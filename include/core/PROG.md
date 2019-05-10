# Programming Guide (Core)

[DO NOT EDIT]: # (generated from /scripts/core/PROG.md)

The following documents the high-level programming models and guidelines.  

NOTE: This is a **PRELIMINARY** specification, provided for review and feedback.

## Table of Contents
* [Driver and Device](#dnd)
* [Memory and Image Management](#mim)
    + [Memory](#mem)
    + [Images](#img)
* [Command Queues and Command Lists](#cnc)
    + [Command Queue](#cq)
    + [Command List](#cl)
* [Synchronization Primitives](#sp)
    + [Fences](#fnc)
    + [Events](#evnt)
* [Barriers](#brr)
* [Modules and Functions](#mnf)
    + [Modules](#mod)
    + [Functions](#func)
    + [Execution](#exe)
    + [Sampler](#smp)
* [Advanced](#adv)
    + [Sub-Device Support](#sd)
    + [Device Residency](#res)
    + [OpenCL Interoperability](#oi)
    + [Inter-Process Communication](#ipc)
* [Experimental](#exp)

# <a name="dnd">Driver and Device</a>
## Driver
A driver represents an instance of a Xe driver being loaded and initialized into the current process.
- Only one instance of a driver per process can be loaded.
- Multiple calls to ::xeInit are silently ignored.
- A driver has minimal global state associated; only that which is sufficient for querying devices recognized by the driver.
- There is no explicit unload or shutdown of the driver.
- Any global resources acquired during ::xeInit will be released during process detach.

## Device
A device represents a physical device in the system that can support Xe.
- More than one device may be available in the system.
- The driver will only report devices that are recognized by the driver.
- The application is responsible for sharing memory and explicit submission and synchronization across multiple devices.
- Device can expose sub-devices that allow finer-grained control of multi-tile devices.

## Initialization
The driver must be initizalized by calling ::xeInit before any other function.
This function will query the available physical adapters in the system and make this information available to all threads in the current process.

The following sample code demonstrates a basic initialization sequence:
```c
    // NOTE: Sample code in this document contains little or no error checking for brevity and clarity.
    //       However, proper error checking is highly recommended and necessary in many cases.

    // Initialize the driver
    xeInit(XE_INIT_FLAG_NONE);

    // Get number of devices supporting Xe
    uint32_t deviceCount = 0;
    xeDeviceGetCount(&deviceCount);
    if(0 == deviceCount)
    {
        printf("There is no device supporting Xe!\n");
        return;
    }

    // Get the handle for device that supports required API version
    xe_device_handle_t hDevice;
    for(uint32_t i = 0; i < deviceCount; ++i)
    {
        xeDeviceGet(i, &hDevice);
        
        xe_api_version_t version;
        xeDeviceGetApiVersion(hDevice, &version);
        if(XE_API_VERSION_1_0 <= version)
            break;

        if(i == deviceCount)
        {
            printf("There is no device that supporting Xe version required!\n");
            return;
        }
    }
    ...

```

# <a name="mim">Memory and Image Management</a>
There are two types of allocations:
1. [**Memory**](#mem) - linear, unformatted allocations for direct access from both the host and device.
2. [**Images**](#img) - non-linear, formatted allocations for direct access from the device.

## <a name="mem">Memory</a>
Linear, unformatted memory allocations are represented as pointers in the host application.
A pointer on the host has the same size as a pointer on the device.

### Types
Three types of allocations are supported.
The type of allocation describes the _ownership_ of the allocation:
1. **Host** allocations are owned by the host and are intended to be allocated out of system memory.
  Host allocations are accessible by the host and one or more devices.
  The same pointer to a host allocation may be used on the host and all supported devices; they have _address equivalence_.
  Host allocations are not expected to migrate between system memory and device local memory.
  Host allocations trade off wide accessibility and transfer benefits for potentially higher per-access costs, such as over PCI express.
2. **Device** allocations are owned by a specific device and are intended to be allocated out of device local memory, if present.
  Device allocations generally trade off access limitations for higher performance.
  With very few exceptions, device allocations may only be accessed by the specific device that they are allocated on, or copied to a host or another device allocation.
  The same pointer to a device allocation may be used on any supported device.
3. **Shared** allocations share ownership and are intended to migrate between the host and one or more devices.
  Shared allocations are accessible by at least the host and an associated device.
  Shared allocations may be accessed by other devices in some cases.
  Shared allocations trade off transfer costs for per-access benefits.
  The same pointer to a shared allocation may be used on the host and all supported devices.

A **Shared System** allocation is a sub-class of a **Shared** allocation, where the memory is allocated by a _system allocator_ - such as `malloc` or `new` - rather than by a driver allocation API.
Shared system allocations have no associated device - they are inherently cross-device.
Like other shared allocations, shared system allocations are intended to migrate between the host and supported devices, and the same pointer to a shared system allocation may be used on the host and all supported devices.

In summary:
| Name              | Initial Location                      | Accessible By     |                               | Migratable To     |           |
| :--:              | :--:                                  | :--:              | :--:                          | :--:              | :--:      |
| **Host**          | Host                                  | Host              | Yes                           | Host              | N/A       |
| ^                 | ^                                     | Any Device        | Yes (perhaps over PCIe)       | Device            | No        |
| **Device**        | Specific Device                       | Host              | No                            | Host              | No        |
| ^                 | ^                                     | Specific Device   | Yes                           | Device            | N/A       |
| ^                 | ^                                     | Another Device    | Optional (may require p2p)    | Another Device    | No        |
| **Shared**        | Host, Specific Device, Or Unspecified | Host              | Yes                           | Host              | Yes       |
| ^                 | ^                                     | Specific Device   | Yes                           | Device            | Yes       |
| ^                 | ^                                     | Another Device    | Optional (may require p2p)    | Another Device    | Optional  |
| **Shared System** | Host                                  | Host              | Yes                           | Host              | Yes       |
| ^                 | ^                                     | Device            | Yes                           | Device            | Yes       |

Devices may support different capabilities for each type of allocation.
Supported capabilities are:
* ::XE_MEMORY_ACCESS - if a device supports access (read or write) to allocations of the specified type.
* ::XE_MEMORY_ATOMIC_ACCESS - if a device support atomic access to allocations of the specified type.
* ::XE_MEMORY_CONCURRENT_ACCESS - if a device supports concurrent access to allocations of the specified type, or another device's allocation of the specified type.
* ::XE_MEMORY_CONCURRENT_ATOMIC_ACCESS - if a device supports concurrent atomic access to allocations of the specified type, or another device's allocations of the specified type.

Some devices may _oversubscribe_ some **shared** allocations.
When and how such oversubscription occurs, including which allocations are evicted when the working set changes, are considered implementation details.

The required matrix of capabilities are:
| Allocation Type                  | Access   | Atomic Access | Concurrent Access | Concurrent Atomic Access |
| :--:                             | :--:     | :--:          | :--:              | :--:                     |
| **Host**                         | Required | Optional      | Optional          | Optional                 |
| **Device**                       | Required | Optional      | Optional          | Optional                 |
| **Shared**                       | Required | Optional      | Optional          | Optional                 |
| **Shared** (Cross-Device)        | Optional | Optional      | Optional          | Optional                 |
| **Shared System** (Cross-Device) | Optional | Optional      | Optional          | Optional                 |

### Cache Hints, Prefetch, and Memory Advice
Cacheability hints may be provided via separate host and device allocation flags when memory is allocated.

**Shared** allocations may be prefetched to a supporting device via the ::xeCommandListAppendMemoryPrefetch API.
Prefetching may allow memory transfers to be scheduled concurrently with other computations and may improve performance.

Additionally, an application may provide memory advice for a **shared** allocation via the ::xeCommandListAppendMemAdvise API, to override driver heuristics or migration policies.
Memory advice may avoid unnecessary or unprofitable memory transfers and may improve performance.

Both prefetch and memory advice are asynchronous operations that are appended into command lists.

## <a name="img">Images</a>
An image is used to store multi-dimensional and format-defined memory for optimal device access.
An image's contents can be copied to and from other images, as well as host-accessable memory allocations.
This is the only method for host access to the contents of an image.
This methodology allows for device-specific encoding of image contents (e.g., tile swizzle patterns, loseless compression, etc.) 
and avoids exposing these details in the API in a backwards compatible fashion.

```c
    // Specify single component FLOAT32 format
    xe_image_format_desc_t formatDesc = {
        XE_IMAGE_FORMAT_LAYOUT_32, XE_IMAGE_FORMAT_TYPE_FLOAT,
        XE_IMAGE_FORMAT_SWIZZLE_R, XE_IMAGE_FORMAT_SWIZZLE_0, XE_IMAGE_FORMAT_SWIZZLE_0, XE_IMAGE_FORMAT_SWIZZLE_1
    };

    xe_image_desc_t imageDesc = {
        XE_IMAGE_DESC_VERSION_CURRENT,
        XE_IMAGE_FLAG_PROGRAM_READ,
        XE_IMAGE_TYPE_2D,
        formatDesc,
        128, 128, 0, 0, 0
    };
    xe_image_handle_t hImage;
    xeImageCreate(hDevice, &imageDesc, &hImage);

    // upload contents from host pointer
    xeCommandListAppendImageCopyFromMemory(hCommandList, hImage, nullptr, pImageData, nullptr, 0, nullptr);
    ...
```

## Device Cache Settings
For device support cache control and config, there are two methods for cache control:
1. Cache Size Configuration: Ability to configure larger size for SLM vs Data globally for Device
2. Runtime Hint/prefrence for application to allow access to be Cached or not in Device Caches. For GPU device this is provided via two ways  
      -  During Image creation via Flag
      -  Kernel instruction 

The following sample code demonstrates a basic sequence for Cache size configuration:
```c
    // Large SLM for Intermediate and Last Level cache
    xeDeviceSetIntermediateCacheConfig(hDevice, XE_CACHE_CONFIG_LARGE_SLM);
    xeDeviceSetLastLevelCacheConfig(hDevice, XE_CACHE_CONFIG_LARGE_SLM);
    ...
```
The following sample code demonstrates a basic sequence for Runtime Hint/Prefrence for Cache:

# <a name="cnc">Command Queues and Command Lists</a>
The following are the motivations for seperating a command queue from a command list:
- Command queues are mostly associated with physical device properties,
  such as the number of input streams.
- Command queues provide (near) zero-latency access to the device.
- Command lists are mostly associated with Host threads for simultaneous construction.
- Command list appending can occur independently of command queue submission.
- Command list submission can occur to more than one command queue.

The following diagram illustrates the hierarchy of command lists and command queues to the device:  
![Queue](../images/core_queue.png?raw=true)  
@image latex core_queue.png

## <a name="cq">Command Queues</a>
A command queue represents a logical input stream to the device, tied to a physical input
stream via an ordinal at creation time.

### Creation
- The application may explicitly bind the command queue to a physical input stream, or
  allow the driver to choose dynamically, based on usage.
- Multiple command queues may be created that use the same physical input stream. For example,
  an application may create a command queue per Host thread with different scheduling priorities.
- However, because each command queue allocates a logical hardware context, an application 
  should avoid creating multiple command queues for the same physical input stream with the
  same priority due to possible performance penalties with hardware context switching.
- The maximum number of command queues an application can create is limited by device-specific
  resources; e.g., the maximum number of logical hardware contexts supported by the device. 
  This can be queried from ::xe_device_properties_t.maxCommandQueues.
- The maximum number of simultaneous compute command queues per device is queried from 
  ::xe_device_properties_t.numAsyncComputeEngines.
- The maximum number of simultaneous copy command queues per device is queried from 
  ::xe_device_properties_t.numAsyncCopyEngines.
- All command lists executed on a command queue are gaurenteed to only execute on its 
  single, physical input stream; e.g., copy commands in a compute command list / queue will
  execute via the compute engine, not the copy engine.

The following sample code demonstrates a basic sequence for creation of command queues:
```c
    // Create a command queue
    xe_command_queue_desc_t commandQueueDesc = {
        XE_COMMAND_QUEUE_DESC_VERSION_CURRENT,
        XE_COMMAND_QUEUE_FLAG_NONE,
        XE_COMMAND_QUEUE_MODE_DEFAULT,
        XE_COMMAND_QUEUE_PRIORITY_NORMAL,
        0
    };
    xe_command_queue_handle_t hCommandQueue;
    xeCommandQueueCreate(hDevice, &commandQueueDesc, &hCommandQueue);
    ...
```

### Execution
- Command lists submitted to a command queue are **immediately** executed in a fifo manner.
- Command queue submission is free-treaded, allowing multiple Host threads to
  share the same command queue.
- If multiple Host threads enter the same command queue simultaneously, then execution order
  is undefined.
- Command lists created with ::XE_COMMAND_LIST_FLAG_COPY_ONLY may only be submitted to
  command queues created with ::XE_COMMAND_QUEUE_FLAG_COPY_ONLY.

### Destruction
- The application is responsible for making sure the device is not currently
  executing from a command queue before it is deleted.  This is 
  typically done by tracking command queue fences, but may also be
  handled by calling ::xeCommandQueueSynchronize.

## <a name="cl">Command Lists</a>
A command list represents a sequence of commands for execution on a command queue.

### Creation
- A command list is created for a device to allow device-specific appending of commands.
- A command list can be copied to create another command list. The application may use this
  to copy a command list for use on a different device.

### Appending
- There is no implicit binding of command lists to Host threads. Therefore, an 
  application may share a command list handle across multiple Host threads. However,
  the application is responsible for ensuring that multiple Host threads do not access
  the same command list simultaneously.
- By default, commands are executed in the same order in which they are appended.
  However, an application may allow the driver to optimize the ordering by using
  ::XE_COMMAND_LIST_FLAG_RELAXED_ORDERING.  Reordering is guarenteed to be only occur
  between barriers and synchronization primitives.
- The command list maintains some machine state, which is inherited by subsequent
  commands. See ::xe_command_list_parameter_t for details.
- A command list can be called from another command list (nested). In this case, state
  may be inherited and leaked by the nested command list.

The following sample code demonstrates a basic sequence for creation of command lists:
```c
    // Create a command list
    xe_command_list_desc_t commandListDesc = {
        XE_COMMAND_LIST_DESC_VERSION_CURRENT,
        XE_COMMAND_LIST_FLAG_NONE
    };
    xe_command_list_handle_t hCommandList;
    xeCommandListCreate(hDevice, &commandListDesc, &hCommandList);
    ...
```

### Submission
- There is no implicit association between a command list and a command queue. 
  Therefore, a command list may be submitted to any, or multiple command queues.
  However, if a command list is meant to be submitted to a copy-only command queue
  then the ::XE_COMMAND_LIST_FLAG_COPY_ONLY must be set at creation.
- The application is responsible for calling close before submission to a command queue.
- Command lists do not inherit state from other command lists executed on the same
  command queue.  i.e. each command list begins execution in its own default state.

The following sample code demonstrates submission of commands to a command queue, via a command list:
```c
    ...
    // finished appending commands (typically done on another thread)
    xeCommandListClose(hCommandList);

    // Execute command list in command queue
    xeCommandQueueExecuteCommandLists(hCommandQueue, 1, &hCommandList, nullptr);

    // synchronize host and device
    xeCommandQueueSynchronize(hCommandQueue, MAX_UINT32);

    // Reset (recycle) command list for new commands
    xeCommandListReset(hCommandList);
    ...
```

### Recycling
- A command list may be recycled to avoid the overhead of frequent creation and destruction.
- The application is responsible for making sure the device is not currently
  executing from a command list before it is reset.  This should be
  handled by tracking a completion event associated with the command list.
- The application is responsible for making sure the device is not currently
  executing from a command list before it is deleted.  This should be
  handled by tracking a completion event associated with the command list.

### Low-Latency Immediate Command Lists
A special type of command list can be used for very low-latency submission usage-models.
- An immediate command list is both a command list and an implicit command queue.
- An immediate command list is created using a command queue descriptor.
- Commands submitted to an immediate command list are immediately executed on the device.
- An immediate command list is not required to be closed or reset.  However, usage will be honored and expected behaviors will be followed.

The following sample code demonstrates a basic sequence for creation and usage of immediate command lists:
```c
    // Create an immediate command list
    xe_command_queue_desc_t commandQueueDesc = {
        XE_COMMAND_QUEUE_DESC_VERSION_CURRENT,
        XE_COMMAND_QUEUE_FLAG_NONE,
        XE_COMMAND_QUEUE_MODE_DEFAULT,
        XE_COMMAND_QUEUE_PRIORITY_NORMAL,
        0
    };
    xe_command_list_handle_t hCommandList;
    xeCommandListCreateImmediate(hDevice, &commandQueueDesc, &hCommandList);

    // Immediately submit a function to the device
    xeCommandListAppendLaunchFunction(hCommandList, hFunction, &launchArgs, nullptr, 0, nullptr);
    ...
```

# <a name="sp">Synchronization Primitives</a>
There are two types of synchronization primitives:
1. [**Fences**](#fnc) - used to communicate to the host that command queue execution has completed.
2. [**Events**](#evnt) - used as fine-grain host-to-device, device-to-host or device-to-device execution and memory dependencies.

The following diagram illustrats the relationship of capabilities of these types of synchronization primitives:  
![Graph](../images/core_sync.png?raw=true)  
@image latex core_sync.png

The following are the motivations for seperating the different types of synchronization primitives:
- Allows device-specific optimizations for certain types of primitives:
    + fences may share device memory with all other fences within the same command queue.
    + events may be implemented using pipelined operations as part of the program execution.
    + fences are implicit, coarse-grain execution and memory barriers.
    + events optionally cause fine-grain execution and memory barriers.
- Allows distinction on which type of primitive may be shared across devices.

Generally. Events are generic synchronization primitives that can be used across many different usage-models, including those of fences.
However, this generality comes with some cost in memory overhead and efficiency.

## <a name="fnc">Fences</a>
A fence is a heavyweight synchronization primitive used to communicate to the host that command list execution within a command queue has completed.
- A fence is associated with a single command queue.
- A fence can only be signaled from a device's command queue (e.g. between execution of command lists)
  and can only be waited upon from the host.
- A fence gaurentees both execution completion and memory coherency, across the device and host, prior to being signalled.
- A fence only has two states: not signaled and signaled.
- A fence can only be reset from the Host.
- A fence cannot be shared across processes.

The following sample code demonstrates a sequence for creation, submission and querying of a fence:
```c
    // Create fence
    xe_fence_desc_t fenceDesc = {
        XE_FENCE_DESC_VERSION_CURRENT,
        XE_FENCE_FLAG_NONE
    };
    xe_fence_handle_t hFence;
    xeFenceCreate(hCommandQueue, &fenceDesc, &hFence);

    // Execute a command list with a signal of the fence
    xeCommandQueueExecuteCommandLists(hCommandQueue, 1, &hCommandList, hFence);

    // Wait for fence to be signaled
    xeFenceHostSynchronize(hFence, MAX_UINT32);
    xeFenceReset(hFence);
    ...
```

The primary usage model(s) for fences are to notify the Host when a command list has finished execution to allow:
- Recycling of memory and images
- Recycling of command lists
- Recycling of other synchronization primitives
- Explicit memory residency.

The following diagram illustrates fences signalled after command lists on execution:  
![Fence](../images/core_fence.png?raw=true)  
@image latex core_fence.png

## <a name="evnt">Events</a>
An event is used to communicate fine-grain host-to-device, device-to-host or device-to-device dependencies from within a command list.
- An event can be:
  + signaled from within a device's command list and waited upon within the same command list
  + signaled from within a device's command list and waited upon from the host, another command queue or another device
  + signaled from the host, and waited upon from within a device's command list.
- An event only has two states: not signaled and signaled.
- An event can be reset from the Host or device.
- An event can be appended into multiple command lists simultaneously.
- An event can be shared across devices and processes.
- An event can invoke an execution and/or memory barrier; which should be used sparingly to avoid device underutilization.
- There are no protections against events causing deadlocks, such as circular waits scenarios. 
  + These problems are left to the application to avoid.
- An event intended to be signaled by the host, another command queue or another device after command list submission to a command queue may prevent 
  subsequent forward progress within the command queue itself.
  + This can create create bubbles in the pipeline or deadlock situations if not correctly scheduled.

An event pool is used for creation of individual events:
- An event pool reduces the cost of creating multiple events by allowing underlying device allocations to be shared by events with the same properties
- An event pool can be shared via IPC; allowing sharing blocks of events rather than sharing each individual event

The following sample code demonstrates a sequence for creation and submission of an event:
```c
    // Create event pool
    xe_event_pool_desc_t eventPoolDesc = {
        XE_EVENT_POOL_DESC_VERSION_CURRENT,
        XE_EVENT_POOL_FLAG_HOST_VISIBLE, // all events in pool are visible to Host
        1
    };
    xe_event_pool_handle_t hEventPool;
    xeEventPoolCreate(hDevice, &eventPoolDesc, &hEventPool);

    xe_event_desc_t eventDesc = {
        XE_EVENT_DESC_VERSION_CURRENT,
        0,
        XE_EVENT_SCOPE_FLAG_NONE,
        XE_EVENT_SCOPE_FLAG_HOST  // ensure memory coherency across device and Host after event completes
    };
    xe_event_handle_t hEvent;
    xeEventCreate(hEventPool, &eventDesc, &hEvent);

    // Append a signal of an event into the command list after the function executes
    xeCommandListAppendLaunchFunction(hCommandList, hFunction1, &launchArgs, hEvent, 0, nullptr);

    // Execute the command list with the signal
    xeCommandQueueExecuteCommandLists(hCommandQueue, 1, &hCommandList, nullptr);
    ...
```

The following diagram illustrates an event being signalled between functions within a command list:  
![Event](../images/core_event.png?raw=true)  
@image latex core_event.png

# <a name="brr">Barriers</a>
There are two types of barriers:
1. **Execution Barriers** - used to communicate execution dependencies between commands within a command list or across command queues, devices and/or Host.
2. **Memory Barriers** - used to communicate memory coherency dependencies between commands within a command list or across command queues, devices and/or Host.

The following sample code demonstrates a sequence for submission of a brute-force execution and global memory barrier:
```c
    xeCommandListAppendLaunchFunction(hCommandList, hFunction, &launchArgs, nullptr, 0, nullptr);

    // Append a barrier into a command list to ensure hFunction1 completes before hFunction2 begins
    xeCommandListAppendBarrier(hCommandList, nullptr, 0, nullptr);

    xeCommandListAppendLaunchFunction(hCommandList, hFunction, &launchArgs, nullptr, 0, nullptr);
    ...
```

## Execution Barriers
Commands executed on a command list are only guarenteed to start in the same order in which they are submitted;
i.e. there is no implicit definition of the order of completion.
- Fences provide implicit, coarse-grain control to indicate that all previous commands must complete prior to the fence being signalled.
- Events provide explicit, fine-grain control over execution dependencies between commands; allowing more opportunities for concurrent execution and higher device utilization.

The following sample code demonstrates a sequence for submission of a fine-grain execution-only dependency using events:
```c
    xe_event_desc_t event1Desc = {
        XE_EVENT_DESC_VERSION_CURRENT,
        0,
        XE_EVENT_SCOPE_FLAG_NONE, // no memory/cache coherency required on signal
        XE_EVENT_SCOPE_FLAG_NONE  // no memory/cache coherency required on wait
    };
    xe_event_handle_t hEvent1;
    xeEventCreate(hEventPool, &event1Desc, &hEvent1);

    // Ensure hFunction1 completes before signaling hEvent1
    xeCommandListAppendLaunchFunction(hCommandList, hFunction1, &launchArgs, hEvent1, 0, nullptr);

    // Ensure hEvent1 is signalled before starting hFunction2
    xeCommandListAppendLaunchFunction(hCommandList, hFunction2, &launchArgs, nullptr, 1, &hEvent1);
    ...
```

## Memory Barriers
Commands executed on a command list are *not* guarenteed to maintain memory coherency with other commands; 
i.e. there is no implicit memory or cache coherency.
- Fences provide implicit, coarse-grain control to indicate that all caches and memory are coherent across the device and Host prior to the fence being signalled.
- Events provide explicit, fine-grain control over cache and memory coherency dependencies between commands; allowing more opportunities for concurrent execution and higher device utilization.

The following sample code demonstrates a sequence for submission of a fine-grain memory dependency using events:
```c
    xe_event_desc_t event1Desc = {
        XE_EVENT_DESC_VERSION_CURRENT,
        0,
        XE_EVENT_SCOPE_FLAG_DEVICE, // ensure memory coherency across device before event signalled
        XE_EVENT_SCOPE_FLAG_NONE
    };
    xe_event_handle_t hEvent1;
    xeEventCreate(hEventPool, &event1Desc, &hEvent1);

    // Ensure hFunction1 memory writes are fully coherent across the device before signaling hEvent1
    xeCommandListAppendLaunchFunction(hCommandList, hFunction1, &launchArgs, hEvent1, 0, nullptr);

    // Ensure hEvent1 is signalled before starting hFunction2
    xeCommandListAppendLaunchFunction(hCommandList, hFunction2, &launchArgs, nullptr, 1, &hEvent1);
    ...
```

## Range-based Memory Barriers
Range-based memory barriers provide explicit control of which cachelines require coherency.

The following sample code demonstrates a sequence for submission of a range-based memory barrier:
```c
    xeCommandListAppendLaunchFunction(hCommandList, hFunction1, &launchArgs, nullptr, 0, nullptr);

    // Ensure memory range is fully coherent across the device after hFunction1 and before hFunction2
    xeCommandListAppendMemoryRangesBarrier(hCommandList, 1, &size, &ptr, nullptr, 0, nullptr);

    xeCommandListAppendLaunchFunction(hCommandList, hFunction2, &launchArgs, nullptr, 0, nullptr);
    ...
```

# <a name="mnf">Modules and Functions</a>
There are multiple levels of constructs needed for executing functions on the device:
1. A [**Module**](#mod) represents a single translation unit that consists of functions that have been compiled together.
2. A [**Function**](#func) represents the function within the module that will be launched directly from a command list.

The following diagram provides a high level overview of the major parts of the system.

![Driver](../images/core_module.png?raw=true)  
@image latex core_module.png

## <a name="mod">Modules</a>
Modules can be created from an IL or directly from native format using ::xeModuleCreate.
- ::xeModuleCreate takes a format argument that specifies the input format.
- ::xeModuleCreate performs a compilation step when format is IL.

The following sample code demonstrates a sequence for creating a module from an OpenCL function:
```c
    __kernel void image_scaling( __read_only  image2d_t src_img,
                                 __write_only image2d_t dest_img,
                                              uint WIDTH,     // resized width
                                              uint HEIGHT )   // resized height
    {
        int2       coor = (int2)( get_global_id(0), get_global_id(1) );
        float2 normCoor = convert_float2(coor) / (float2)( WIDTH, HEIGHT );

        float4    color = read_imagef( src_img, SMPL_PREF, normCoor );

        write_imagef( dest_img, coor, color );
    }
    ...
```

```c
    // OpenCL C function has been compiled to SPIRV IL (pImageScalingIL)
    xe_module_desc_t moduleDesc = {
        XE_MODULE_DESC_VERSION_CURRENT,
        XE_MODULE_FORMAT_IL_SPIRV,
        ilSize,
        pImageScalingIL,
        nullptr
    };
    xe_module_handle_t hModule;
    xeModuleCreate(hDevice, &moduleDesc, &hModule, nullptr);
    ...
```

### Module Build Options
Build options can be passed with ::xe_module_desc_t as a string.
| Build Option                                  | Description                                           | Default  |
| :--                                           | :--                                                   | :--      |
| -xe-opt-disable                             | Disable optimizations.                                | Disabled |
| -xe-opt-greater-than-4GB-buffer-required    | Use 64-bit offset calculations for buffers.           | Disabled |
| -xe-opt-large-register-file                 | Increase number of registers available to threads.    | Disabled |

### Module Build Log
The ::xeModuleCreate function can optionally generate a build log object ::xe_module_build_log_handle_t.

```c
    ...
    xe_module_build_log_handle_t buildlog;
    xe_result_t result = xeModuleCreate(hDevice, &desc, &module, &buildlog);

    // Only save build logs for module creation errors.
    if (result != XE_RESULT_SUCCESS)
    {
        size_t szLog = 0;
        xeModuleBuildLogGetString(buildlog, &szLog, nullptr);
        
        char_t* strLog = (char_t*)malloc(szLog);
        xeModuleBuildLogGetString(buildlog, &szLog, strLog);

        // Save log to disk.
        ...

        free(strLog);
    }

    xeModuleBuildLogDestroy(buildlog);
```

### Module Caching with Native Binaries
Disk caching of modules is not supported by the driver. If a disk cache for modules is desired then it is the
responsibility of the application to implement this using ::xeModuleGetNativeBinary.

```c
    ...
    // compute hash for pIL and check cache.
    ...

    if (cacheUpdateNeeded)
    {
        size_t szBinary = 0;
        xeModuleGetNativeBinary(hModule, &szBinary, nullptr);

        uint8_t* pBinary = malloc(szBinary);
        xeModuleGetNativeBinary(hModule, &szBinary, pBinary);

        // cache pBinary for corresponding IL
        ...

        free(pBinary);
    }
```
Also, note that the native binary will retain all debug information that is associated with the module. This allows debug
capabilities for modules that are created from native binaries.

### Built-in Functions
Built-in functions are not supported but can be implemented by an upper level runtime or library using the native binary
interface.

## <a name="func">Functions</a>
A Function is a reference to a function within a module. The Function object supports both explicit and implicit function
arguments along with data needed for launch.

The following sample code demonstrates a sequence for creating a function from a module:
```c
    xe_function_desc_t functionDesc = {
        XE_FUNCTION_DESC_VERSION_CURRENT,
        XE_FUNCTION_FLAG_NONE,
        "image_scaling"
    };
    xe_function_handle_t hFunction;
    xeFunctionCreate(hModule, &functionDesc, &hFunction);
    ...
```

### Function Attributes
Use ::xeFunctionGetAttribute to query attributes from a function object.

```c
    ...
    uint32_t numRegisters;

    // Number of program registers used by function.
    xeFunctionGetAttribute(hFunction, XE_FUNCTION_GET_ATTR_MAX_REGS_USED, &numRegisters);
    ...
```
See ::xe_function_get_attribute_t for more information on the "get" attributes.

Use ::xeFunctionSetAttribute to set attributes from a function object.

```c
    // Function performs indirect device access.
    xeFunctionSetAttribute(hFunction, XE_FUNCTION_SET_ATTR_INDIRECT_DEVICE_ACCESS, true);
    ...
```

See ::xe_function_set_attribute_t for more information on the "set" attributes.

## <a name="exe">Execution</a>

### Function Group Size
The group size for a function can be set using ::xeFunctionSetGroupSize. If a group size is not
set prior to appending a function into a command list then a default will be chosen.
The group size can updated over a series of append operations. The driver will copy the
group size information when appending the function into the command list.

```c
    xeFunctionSetGroupSize(function, groupSizeX, groupSizeY, 1);

    ...
```

The API supports a query for suggested group size when providing the global size. This function ignores the
group size that was set on the function using ::xeFunctionSetGroupSize.

```c
    // Find suggested group size for processing image.
    uint32_t groupSizeX;
    uint32_t groupSizeY;
    xeFunctionSuggestGroupSize(function, imageWidth, imageHeight, 1, &groupSizeX, &groupSizeY, nullptr);

    xeFunctionSetGroupSize(function, groupSizeX, groupSizeY, 1);

    ...
```

### Function Arguments
Function arguments represent only the explicit function arguments that are within "brackets" e.g. func(arg1, arg2, ...).
- Use ::xeFunctionSetArgumentValue to setup arguments for a function launch.
- The AppendLaunchFunction command will make a copy the function arguments to send to the device.
- Function arguments can be updated at anytime and used across multiple append calls.

The following sample code demonstrates a sequence for creating function args and launching the function:
```c
    // Bind arguments
    xeFunctionSetArgumentValue(hFunction, 0, sizeof(xe_image_handle_t), &src_image);
    xeFunctionSetArgumentValue(hFunction, 1, sizeof(xe_image_handle_t), &dest_image);
    xeFunctionSetArgumentValue(hFunction, 2, sizeof(uint32_t), &width);
    xeFunctionSetArgumentValue(hFunction, 3, sizeof(uint32_t), &height);

    xe_thread_group_dimensions_t launchArgs = { numGroupsX, numGroupsY, 1 };

    // Append function
    xeCommandListAppendLaunchFunction(hCommandList, hFunction, &launchArgs, nullptr, 0, nullptr);

    // Update image pointers to copy and scale next image.
    xeFunctionSetArgumentValue(hFunction, 0, sizeof(xe_image_handle_t), &src2_image);
    xeFunctionSetArgumentValue(hFunction, 1, sizeof(xe_image_handle_t), &dest2_image);

    // Append function
    xeCommandListAppendLaunchFunction(hCommandList, hFunction, &launchArgs, nullptr, 0, nullptr);

    ...
```

### Function Launch
In order to invoke a function on the device you must call one of the CommandListAppendLaunch* functions for
a command list. The most basic version of these is ::xeCommandListAppendLaunchFunction which takes a
command list, function, launch arguments, and an optional synchronization event used to signal completion.
The launch arguments contain thread group dimensions.

```c
    // compute number of groups to launch based on image size and function group size.
    uint32_t numGroupsX = imageWidth / groupSizeX;
    uint32_t numGroupsY = imageHeight / groupSizeY;

    xe_thread_group_dimensions_t launchArgs = { numGroupsX, numGroupsY, 1 };

    // Append function
    xeCommandListAppendLaunchFunction(hCommandList, hFunction, &launchArgs, nullptr, 0, nullptr);
```

::xeCommandListAppendLaunchFunctionIndirect allows the launch parameters to be supplied indirectly in a
buffer that the device reads instead of the command itself. This allows for the previous operations on the
device to generate the parameters.

```c
    xe_thread_group_dimensions_t* pIndirectArgs;
    
    ...
    xeDeviceMemAlloc(hDevice, flags, sizeof(xe_thread_group_dimensions_t), sizeof(uint32_t), &pIndirectArgs);

    // Append function
    xeCommandListAppendLaunchFunctionIndirect(hCommandList, hFunction, &pIndirectArgs, nullptr, 0, nullptr);
```

## <a name="smp">Sampler</a>
The API supports Sampler objects that represent state needed for sampling images from within
Module functions.  The ::xeSamplerCreate function takes a sampler descriptor (::xe_sampler_desc_t):

| Sampler Field    | Description                                           |
| :--              | :--                                                   |
| Address Mode     | Determines how out-of-bounds accessse are handled. See ::xe_sampler_address_mode_t. |
| Filter Mode      | Specifies which filtering mode to use. See ::xe_sampler_filter_mode_t               |
| Normalized       | Specifies whether coordinates for addressing image are normalized [0,1] or not.       |

The following is sample for code creating a sampler object and passing it as a Function argument.

```c
    // Setup sampler for linear filtering and clamp out of bounds accesses to edge.
    xe_sampler_desc_t desc = {
        XE_SAMPLER_DESC_VERSION_CURRENT,
        XE_SAMPLER_ADDRESS_MODE_CLAMP,
        XE_SAMPLER_FILTER_MODE_LINEAR,
        false
        };
    xe_sampler_handle_t sampler;
    xeSamplerCreate(hDevice, &desc, &sampler);
    ...
    
    // The sampler can be passed as a function argument.
    xeFunctionSetArgumentValue(hFunction, 0, sizeof(xe_sampler_handle_t), &sampler);

    // Append function
    xeCommandListAppendLaunchFunction(hCommandList, hFunction, &launchArgs, nullptr, 0, nullptr);
```

# <a name="adv">Advanced</a>
## <a name="sd">Sub-Device Support</a>
A multi-tile device consists of tiles that are tied together by high-speed interconnects. Each tile
has local memory that is shared to other tiles through these interconnects. The API represents tiles
as sub-devices and there are functions to query and obtain a sub-device. Outside of these functions
there are no distinction between sub-devices and devices. 

![Subdevice](../images/core_subdevice.png?raw=true)  
@image latex core_subdevice.png

Query device properties using ::xeDeviceGetProperties to confirm subdevices are supported with
::xe_device_properties_t.numSubDevices. Use ::xeDeviceGetSubDevice to obtain a sub-device handle.
There are additional device properties in ::xe_device_properties_t for sub-devices to confirm a
device is a sub-device and to query the id. This is useful when needing to pass a sub-device
handle to another library.

To allocate memory and dispatch tasks to a particular sub-device then obtain the sub-device
handle and use this with memory and command queue/lists APIs. Local memory allocation will be placed
in the local memory that is attached to the sub-device. An out-of-memory error indicates
that there is not enough local sub-device memory for the allocation. The driver will not try and spill
sub-device allocations over to another sub-device's local memory. However, the application can retry using the
parent device and the driver will decide where to place the allocation.

One thing to note is that the ordinal
that is used when creating a command queue is relative to the sub-device. This ordinal specifies which
physical compute queue on the device or sub-device to map the logical queue to. You need to query
::xe_device_properties_t.numAsyncComputeEngines from the sub-device to determine how to set this ordinal.
See ::xe_command_queue_desc_t for more details.

A 16-byte unique device identifier (uuid) can be obtained for a device or sub-device using ::xeDeviceGetProperties.

```c
    ...
    xeDeviceGetProperties(device, &deviceProps);
    ...

    // Code assumes a specific device configuration.
    assert(deviceProps.numSubDevices == 4);

    // Desire is to allocate and dispatch work to sub-device 2.
    uint32_t subdeviceId = 2;
    xeDeviceGetSubDevice(device, subdeviceId, &subdevice);

    // Query sub-device properties.
    xe_device_properties_t subdeviceProps;
    xeDeviceGetProperties(subdevice, &subdeviceProps);

    assert(subdeviceProps.isSubdevice == true); // Ensure that we have a handle to a sub-device.
    assert(subdeviceProps.subdeviceId == 2);    // Ensure that we have a handle to the sub-device we asked for.

    void* pMemForSubDevice2;
    xeDeviceMemAlloc(subDevice, XE_DEVICE_MEM_ALLOC_FLAG_DEFAULT, memSize, sizeof(uint32_t), &pMemForSubDevice2);
    ...

    ...
    // Check that cmd queue ordinal that was chosen is valid.
    assert(desc.ordinal < subdeviceProps.numAsyncComputeEngines);

    xe_command_queue_handle_t commandQueueForSubDevice2;
    xeCommandQueueCreate(subdevice, desc, &commandQueueForSubDevice2);
    ...
```

## <a name="res">Device Residency</a>
For devices that do not support page-faults, the driver must ensure that all pages that will be accessed by the kernel are resident before program execution.
This can be determined by checking ::xe_device_memory_properties_t.onDemandPageFaults.

In most cases, the driver implicitly handles residency of allocations for device access.
This can be done by inspecting API parameters, including function arguments.
However, in cases where the devices does **not** support page-faulting _and_ the driver is incapable of determining whether an allocation will be accessed by the device,
such as multiple levels of indirection, there are two methods available:
1. the application may set the ::XE_FUNCTION_FLAG_FORCE_RESIDENCY flag during program creation to force all device allocations to be resident during execution.
 + in addition, the application should indicate the type of allocations that will be indirectly accessed using ::xe_function_set_attribute_t
 + if the driver is unable to make all allocations resident, then the call to ::xeCommandQueueExecuteCommandLists will return XE_RESULT_ERROR_OUT_OF_DEVICE_MEMORY
2. explcit ::xeDeviceMakeMemoryResident APIs are included for the application to dynamically change residency as needed. (Windows-only)
 + if the application over-commits device memory, then a call to ::xeDeviceMakeMemoryResident will return XE_RESULT_ERROR_OUT_OF_DEVICE_MEMORY

If the application does not properly manage residency for these cases then the device may experience unrecoverable page-faults.

The following sample code demonstrate a sequence for using coarse-grain residency control for indirect arguments:
```c
    struct node {
        node* next;
    };
    node* begin = nullptr;
    xeHostMemAlloc(XE_HOST_MEM_ALLOC_FLAG_DEFAULT, sizeof(node), 1, &begin);
    xeHostMemAlloc(XE_HOST_MEM_ALLOC_FLAG_DEFAULT, sizeof(node), 1, &begin->next);
    xeHostMemAlloc(XE_HOST_MEM_ALLOC_FLAG_DEFAULT, sizeof(node), 1, &begin->next->next);

    // 'begin' is passed as function argument and appended into command list
    xeFunctionSetAttribute(hFuncArgs, XE_FUNCTION_SET_ATTR_INDIRECT_HOST_ACCESS, TRUE);
    xeFunctionSetArgumentValue(hFunction, 0, sizeof(node*), &begin);
    xeCommandListAppendLaunchFunction(hCommandList, hFunction, &launchArgs, nullptr, 0, nullptr);
    ...

    xeCommandQueueExecuteCommandLists(hCommandQueue, 1, &hCommandList, nullptr);
    ...
```

The following sample code demonstrate a sequence for using fine-grain residency control for indirect arguments:
```c
    struct node {
        node* next;
    };
    node* begin = nullptr;
    xeHostMemAlloc(XE_HOST_MEM_ALLOC_FLAG_DEFAULT, sizeof(node), 1, &begin);
    xeHostMemAlloc(XE_HOST_MEM_ALLOC_FLAG_DEFAULT, sizeof(node), 1, &begin->next);
    xeHostMemAlloc(XE_HOST_MEM_ALLOC_FLAG_DEFAULT, sizeof(node), 1, &begin->next->next);

    // 'begin' is passed as function argument and appended into command list
    xeFunctionSetArgumentValue(hFunction, 0, sizeof(node*), &begin);
    xeCommandListAppendLaunchFunction(hCommandList, hFunction, &launchArgs, nullptr, 0, nullptr);
    ...

    // Make indirect allocations resident before enqueuing
    xeDeviceMakeMemoryResident(hDevice, begin->next, sizeof(node));
    xeDeviceMakeMemoryResident(hDevice, begin->next->next, sizeof(node));

    xeCommandQueueExecuteCommandLists(hCommandQueue, 1, &hCommandList, hFence);

    // wait until complete
    xeFenceHostSynchronize(hFence, MAX_UINT32);

    // Finally, evict to free device resources
    xeDeviceEvictMemory(hDevice, begin->next, sizeof(node));
    xeDeviceEvictMemory(hDevice, begin->next->next, sizeof(node));
    ...
```

## <a name="oi">OpenCL Interoperability</a>
Interoperability with OpenCL is currently only supported _from_ OpenCL _to_ Xe for a subset of types.
The APIs are designed to be OS agnostics and allow implementations to optimize for unified device drivers;
while allowing less-optimal interopability across different device types and/or vendors.

There are three OpenCL types that can be shared for interoperability:
1. **cl_mem** - an OpenCL buffer object
2. **cl_program** - an OpenCL program object
3. **cl_command_queue** - an OpenCL command queue object

### cl_mem
OpenCL buffer objects may be registered for use as an Xe device memory allocation.
Registering an OpenCL buffer object with Xe merely obtains a pointer to the underlying device memory
allocation and does not alter the lifetime of the device memory underlying the OpenCL buffer object.
Freeing the Xe device memory allocation effectively "un-registers" the allocation from Xe, 
and should be performed before the OpenCL buffer object is destroyed.
Using the Xe device memory allocation after destroying its associated OpenCL buffer object will
result in undefined behavior.

Applications are responsible for enforcing memory consistency for shared buffer objects using existing OpenCL and/or Xe APIs.

### cl_program
Xe modules are always in a compiled state and therefore prior to retrieving an ::xe_module_handle_t from
a cl_program the caller must ensure the cl_program is compiled and linked.

### cl_command_queue
Sharing OpenCL command queues provide opportunities to minimize transition costs when submitting work from
an OpenCL queue followed by submitting work to Xe command queue and vice-versa.  Enqueuing Xe command lists
to Xe command queues are immediately submitted to the device.  OpenCL implementations, however, may not
necessarily submit tasks to the device unless forced by explicit OpenCL API such as clFlush or clFinish.
To minimize overhead between sharing command queues, applications must explicitly submit OpenCL command 
queues using clFlush, clFinish or similar operations prior to enqueuing an Xe command list.
Failing to explicitly submit device work may result in undefined behavior.  

Sharing an OpenCL command queue doesn't alter the lifetime of the API object.  It provides knowledge for the
driver to potentially reuse some internal resources which may have noticeable overhead when switching the resources.

Memory contents as reflected by any caching schemes will be consistent such that, for example, a memory write
in an OpenCL command queue can be read by a subsequent Xe command list without any special application action. 
The cost to ensure memory consistency may be implementation dependent.  The performance of sharing command queues
will be no worse than an application submitting work to OpenCL, calling clFinish followed by submitting an
Xe command list.  In most cases, command queue sharing may be much more efficient. 

## <a name="ipc">Inter-Process Communication</a>
There are two types of Inter-Process Communication (IPC) APIs for using Xe allocations across processes:
1. Memory
2. Events 

### Memory
The following code examples demonstrate how to use the memory IPC APIs:

1. First, the allocation is made, packaged, and sent on the sending process:
```c
    void* dptr = nullptr;
    xeDeviceMemAlloc(hDevice, flags, size, alignment, &dptr);

    xe_ipc_mem_handle_t hIPC;
    xeIpcGetMemHandle(dptr, &hIPC);

    // Method of sending to receiving process is not defined by Xe:
    send_to_receiving_process(hIPC);
```

2. Next, the allocation is received and un-packaged on the receiving process:
```c
    // Method of receiving from sending process is not defined by Xe:
    xe_ipc_mem_handle_t hIPC;
    hIPC = receive_from_sending_process();

    void* dptr = nullptr;
    xeIpcOpenMemHandle(hDevice, hIPC, XE_IPC_MEMORY_FLAG_NONE, &dptr);
```

3. Each process may now refer to the same device memory allocation via its `dptr`.
Note, there is no guaranteed address equivalence for the values of `dptr` in each process.

4. To cleanup, first close the handle in the receiving process:
```c
    xeIpcCloseMemHandle(dptr);
```

5. Finally, free the device pointer in the sending process:
```c
    xeMemFree(dptr);
```

### Events
The following code examples demonstrate how to use the event IPC APIs:

1. First, the event pool is create, packaged, and sent on the sending process:
```c
    // create event pool
    xe_event_pool_desc_t eventPoolDesc = {
        XE_EVENT_POOL_DESC_VERSION_CURRENT,
        XE_EVENT_POOL_FLAG_IPC | XE_EVENT_POOL_FLAG_HOST_VISIBLE,
        10
    };
    xe_event_pool_handle_t hEventPool;
    xeEventPoolCreate(hDevice, &eventPoolDesc, &hEventPool);
 
    // get IPC handle and send to another process
    xe_ipc_event_pool_handle_t hIpcEvent;
    xeEventPoolGetIpcHandle(hEventPool, &hIpcEventPool);
    send_to_receiving_process(hIpcEventPool);
```

2. Next, the event pool is received and un-packaged on the receiving process:
```c
    // get IPC handle from other process
    xe_ipc_event_pool_handle_t hIpcEventPool;
    receive_from_sending_process(&hIpcEventPool);
 
    // open event pool
    xe_event_pool_handle_t hEventPool;
    xeEventPoolOpenIpcHandle(hDevice, hIpcEvent, &hEventPool);
```

3. Each process may now refer to the same device event allocation via its handle.
    a. receiving process creates event at location 
```c
    xe_event_handle_t hEvent;
    xeEventCreate(hEventPool, 5, &hEvent);

    // submit function and signal event when complete
    xeCommandListAppendLaunchFunction(hCommandList, hFunction, &args, hEvent, 0, nullptr);
    xeCommandListClose(hCommandList);
    xeCommandQueueExecuteCommandLists(hCommandQueue, 1, &hCommandList, nullptr);
```
    b. sending process creates event at same location
```c
    xe_event_handle_t hEvent;
    xeEventCreate(hEventPool, 5, &hEvent);

    xeEventHostSynchronize(hEvent, MAX_UINT32);
```
    Note, there is no guaranteed address equivalence for the values of `hEvent` in each process.

4. To cleanup, first close the pool handle in the receiving process:
```c
    xeEventDestroy(hEvent);
    xeEventPoolCloseIpcHandle(&hEventPool);
```

5. Finally, free the event pool handle in the sending process:
```c
    xeEventDestroy(hEvent);
    xeEventPoolDestroy(hEventPool);
```

# <a name="exp">Experimental</a>
The following experimental features are provided only for the development and refinement of future APIs.
These APIs are **not** supported by production drivers without explicit end-user opt-in.

## Device-Specific Commands
::xeCommandListReserveSpace provides direct access to the command list's command buffers in order to allow unrestricted access the device's capabilities.
The application is solely responsible for ensuring the commands are valid and correct for the specific device.

```c
    void* ptr = nullptr;
    xeCommandListReserveSpace(hCommandList, sizeof(blob), &ptr);
    ::memcpy(ptr, blob, sizeof(blob));
```