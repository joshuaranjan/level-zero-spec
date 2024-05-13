# Add new image format layout for Vulkan interop

## Metadata

### Component

- Core

### Classification

- New enumerator

### Authors

- Aravind Gopalakrishnan \<aravind.gopalakrishnan@intel.com\>

## Summary

SYCL-Vulkan interop for memory and image formats is a commited oneAPI feature, and for the feature to work well, we need to add these image formats that are supported on the target platform and also supported by other vendors.

## Motivation

ZE_IMAGE_FORMAT_LAYOUT_32_32_32 is needed for VK_FORMAT_R32G32B32_SFLOAT, which is a very important format, and the usefulness of VK-L0 interop would be quite limited without this. ZE_IMAGE_FORMAT_LAYOUT_16_16_16 and ZE_IMAGE_FORMAT_LAYOUT_8_8_8 (the equivalent 8/16-bit Vulkan formats are also reported to be supported by DG2 for images) so would be good to add to L0.

## Description

Currently L0 allows users to export/import memory as `OPAQUE_WIN32` or `DMA_BUF` handles and then attach the request to import in the image descriptor prior to allocating image. 

Request is to add new image format layouts to https://spec.oneapi.io/level-zero/latest/core/api.html#ze-image-format-layout-t

for users to use these before creating images. These new image formats are supported on the platform and by other vendors so it's critical to support for parity and completness of feature.

## Dependencies

No dependencies.

## Details

Proposal is to add new enums as follows to `ze_image_format_layout_t`

### New Object Types

### New Enums

#### ze_image_format_layout_t

```cpp
typedef uint32_t ze_image_format_layout_t;
typedef enum _ze_image_format_layout_t {
    ...
    ZE_IMAGE_FORMAT_LAYOUT_BRGP = 42,                                       ///< Media Format: BRGP. Format type and swizzle is ignored for this
    ZE_IMAGE_FORMAT_LAYOUT_8_8_8 = 43,                                         ///< 3-component 8-bit layout
    ZE_IMAGE_FORMAT_LAYOUT_16_16_16 = 44,                                         ///< 3-component 16-bit layout
    ZE_IMAGE_FORMAT_LAYOUT_32_32_32 = 45,                                         ///< 3-component 32-bit layout
    ZE_EXAMPLE_ENUM_EXP_FLAG_FORCE_UINT32 = 0x7fffffff

} ze_image_format_layout_t;
```

| Flag        | Description                               |
| :---------- | :---------------------------------------- |
| ZE_IMAGE_FORMAT_LAYOUT_8_8_8| *3-component 8-bit layout*             |
| ZE_IMAGE_FORMAT_LAYOUT_16_16_16| *3-component 16-bit layout*             |
| ZE_IMAGE_FORMAT_LAYOUT_32_32_32| *3-component 32-bit layout*             |


### Example Usage

```cpp
// Set up the request to import the external memory handle
ze_external_memory_import_win32_handle_t importHandle = {
    ZE_STRUCTURE_TYPE_EXTERNAL_MEMORY_IMPORT_WIN32,
    nullptr, // pNext
    ZE_EXTERNAL_MEMORY_TYPE_FLAG_OPAQUE_WIN32,
    win32Handle,
    nullptr 
};

ze_image_format_t format = {
    ZE_IMAGE_FORMAT_LAYOUT_32_32_32, ZE_IMAGE_FORMAT_TYPE_FLOAT,
    ZE_IMAGE_FORMAT_SWIZZLE_R, ZE_IMAGE_FORMAT_SWIZZLE_0, ZE_IMAGE_FORMAT_SWIZZLE_0, ZE_IMAGE_FORMAT_SWIZZLE_1
};

ze_image_desc_t imageDesc = {
    ZE_STRUCTURE_TYPE_IMAGE_DESC,
    &importHandle, //pNext: link the request into allocation descriptor
    0, // read-only
    ZE_IMAGE_TYPE_2D,
    format,
    128, 128, 0, 0, 0
};

ze_image_handle_t hImage;
zeImageCreate(hContext, hDevice, &imageDesc, &hImage);
```
