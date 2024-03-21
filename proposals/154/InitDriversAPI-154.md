# Add a new single API for Level Zero Init and Driver Retrieval

## Metadata

### Component

Core

### Classification

API

### Authors

Neil R. Spruit \<neil.r.spruit@intel.com\>

## Summary

When multiple libraries exist in an application which are initializing L0, the types of drivers reported may not be consistent. We need to have a single API to both initialize level zero and filter the reported drivers.

## Motivation

In a single application, one library may request GPUs and another may request VPUs. This creates a problem where the Init and DriverGet may result in the wrong set of drivers being filtered for the specific library.

To Fix this issue, we should have a single API used by all libraries such that Init and Driver retrieval is done in the same api call.

### Related Bugs:
    https://jira.devtools.intel.com/browse/CVS-128701
    https://jira.devtools.intel.com/browse/GSD-5332

## Description

Add a new API zeInitDrivers with a new init flag type which enables for both the initialization of L0 drivers and the retrieval of L0 Driver handles in a single call.

This enables for a user to init and retrieve the L0 Drivers based on the driver types requested with no dependencies or interference from other calls to L0 Initialization calls.

## Dependencies

None, new API and enums.

## Details

All libraries which need to use NPU & GPUs or only NPUs would be moved to use this new API zeInitDrivers() to perform the Level Zero Initialization and the Driver retrieval such that a given library would be able to retrieve the specified set of drivers based on the init flags such that:
| ZE_INIT_DRIVER_TYPE_FLAG Value  | Resulting Drivers |
| ------------- | ------------- |
| ZE_INIT_DRIVER_TYPE_FLAG_GPU | GPU Drivers are Init and driver handles retrieved.|
| ZE_INIT_DRIVER_TYPE_FLAG_NPU | NPU Drivers are Init and driver handles retrieved.|
| ZE_INIT_DRIVER_TYPE_FLAG_GPU BITWISE_OR ZE_INIT_DRIVER_TYPE_FLAG_NPU   | NPU & GPU Drivers are Init and driver handles retrieved.|
| UINT32_MAX  | All Drivers of any type are Init and driver handles retrieved.|

### Multiple Call Safety
Similar to the usage of zeInit(), multiple calls to zeInitDrivers with the same flags will return the same driver handles in the same order.

Each call to zeInitDrivers will init the driver types associated with the init type flags ie:
zeInitDrivers & ZE_INIT_DRIVER_TYPE_FLAG_GPU will init and retrieve GPU Drivers.
zeInitDrivers & ZE_INIT_DRIVER_TYPE_FLAG_NPU will init and retrieve NPU Drivers.

Subsequent calls to zeInitDrivers() with different sets of init type flags will return different sets of drivers.

Once a given driver has been init by the loader, it will not be reinit by the loader in subsequent calls. The init type will then indicate if that driver handle needs to be returned to the user.

This ensures that the driver is not forced to reinitialize after each call to init and retrieve driver handles and is able to maintain the global singleton object that is the driver and device handles for a L0 Driver.

### zeInit Deprecation Plan
To maintain backwards compatibility and avoid regressions, zeinit() will continue to be supported in v1.x however only with support for initializing with the first "init" flags passed in the program and limited to supporting GPU init.

This means, to support different sets of library initializations with different sets of drivers, the new zeInitDrivers will be pushed as the replacement to use by customers wanting to use both GPU/NPU or want to ensure that NPUs are usable in the application.

The plan will be to officially deprecate the zeInit() API for v2.0 of level zero.

### Application Usage of zeInitDrivers
Applications which are built linking the ze_loader will either need to have a build time check for the symbol zeInitDrivers or continue to use zeInit. This can be done by adding a compile time symbol check in the code to verify the symbol is defined in the headers. For runtime, this would limit this version of these libraries to require this new version of the L0 loader with this symbol defined.

Applications which want a dynamic method of checking to use this new api with dlopen/loadlibrary will be able to check for this symbol's existence during runtime to choose to use the new zeInitDrivers or use zeInit.

### New Object Types

### New Entry Points

#### zeInitDrivers

```cpp
ze_result_t zeInitDrivers(
    uint32_t* pCount,
    ze_driver_handle_t* phDrivers,
    ze_init_driver_type_desc_t *desc,
);
```

| Parameter   | Description |
| :---------- | :----------------------------------------                                 |
| pCount | \[ ${\textsf{\color{orange}in, out}}$ \] *pointer to the number of driver instances. if count is zero, then the loader shall update the value with the total number of drivers* |
| phDrivers | \[ ${\textsf{\color{orange}in, out}}$ \][optional][range(0, *pCount)] *array of driver instance handles. if count is less than the number of drivers available, then the loader shall only retrieve that number of drivers.* |
| desc | \[ ${\textsf{\color{orange}in}}$ \] *descriptor with driver init flags to filter which driver handles are returned.* |

---

### New Enums

#### ze_init_driver_type_flags_t

```cpp
///////////////////////////////////////////////////////////////////////////////
/// @brief Supported driver initialization flags
typedef uint32_t ze_init_driver_type_flags_t;
typedef enum _ze_init_driver_type_flag_t
{
    ZE_INIT_DRIVER_TYPE_FLAG_GPU = ZE_BIT(0),                                     ///< initialize & retrieve GPU drivers
    ZE_INIT_DRIVER_TYPE_FLAG_NPU = ZE_BIT(1),                                     ///< initialize & retrieve NPU drivers
    ZE_INIT_DRIVER_TYPE_FLAG_FORCE_UINT32 = 0x7fffffff

} ze_init_driver_type_flag_t;
```

#### ze_structure_type_t

```cpp
typedef enum _ze_structure_type_t {
    // Previous definitions...
    ZE_STRUCTURE_TYPE_INIT_DRIVER_TYPE_DESC = 0x00020023,
    ZE_STRUCTURE_TYPE_FORCE_UINT32 = 0x7fffffff
} ze_structure_type_t;
```
| Flag                                                                    | Description                                                  |
| :--------------------------------------                                 | :------------------------                                    |
| ZE_STRUCTURE_TYPE_INIT_DRIVER_TYPE_DESC                                 | *enum for the init driver type descriptor structure*         |

---

### New Structures

#### ze_init_driver_type_desc_t

```cpp
typedef struct _ze_init_driver_type_desc_t {
    ze_structure_type_t               stype;
    const void*                       pNext;
    ze_init_driver_type_flags_t       flags;
} ze_init_driver_type_desc_t;
```

| Field       | Description                                                         |
| :---------- | :----------------------------------------                           |
| **stype**   | \[ ${\textsf{\color{orange}in}}$ \] type of this structure          |
| **pNext**   | \[ ${\textsf{\color{orange}in, out}}$ \]\[ ${\textsf{\color{lightblue}optional}}$ \] must be null or a pointer to an extension specific structure (i.e. contains `stype` and `pNext`). |
| **flags**   | \[ ${\textsf{\color{orange}in}}$ \] init driver type flags for driver initialization and retrieval. |

---

### Example Usage

```cpp
uint32_t npu_driver_handle_count = 0;
std::vector<ze_driver_handle_t> npu_driver_handles(npu_driver_handle_count);
ze_init_driver_type_desc_t desc = {ZE_STRUCTURE_TYPE_INIT_DRIVER_TYPE_DESC};
desc.pNext = nullptr;
desc.flags = ZE_INIT_DRIVER_TYPE_NPU;
ze_result_t npu_result = zeInitDrivers(&npu_driver_handle_count, nullptr, &desc);
if (npu_driver_handle_count > 0 && npu_result == ZE_RESULT_SUCCESS) {
      npu_driver_handles.resize(npu_driver_handle_count);
      npu_result = zeInitDrivers(&npu_driver_handle_count, npu_driver_handles.data(), &desc);
}
```
