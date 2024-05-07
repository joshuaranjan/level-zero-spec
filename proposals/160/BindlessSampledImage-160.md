# \<Bindless sampled images\>

### Component

\<Core\>

### Classification

\<Experimental Extension\>

### Authors

- \[Mateusz\] \[Hoppe\] \<mateusz.hoppe@intel.com\>

## Summary

This proposal extends ZE_experimental_bindless_image extension with bindless sampled images.

> ```text
> level-zero-spec
>  |
>  |-> proposals
>  |      |
>  |      |-> 160
>  |      |    |
>  |      |    |-> BindlessSampledImage-160.md
>  |      |    |---
>  |      |---
>  ---
> ```

## Motivation

SYCL requires sampled images to be able to achieve compatibility with Cuda. Experimental SYCL type definitions and usage examples are defined in https://github.com/intel/llvm/blob/sycl/sycl/doc/extensions/experimental/sycl_ext_oneapi_bindless_images.asciidoc#obtaining-a-handle-to-the-image and https://github.com/intel/llvm/blob/sycl/sycl/doc/extensions/experimental/sycl_ext_oneapi_bindless_images.asciidoc#reading-a-1d-mipmap-with-anisotropic-filtering-and-levels.

## Description

Bindless sampled image is a combination of a sampler and an image that can be referenced with single handle.
Level Zero defines ze_image_handle_t to reference images on a host. To reference bindless image on a device, users need to use ZE_experimental_bindless_image API `zeImageGetDeviceOffsetExp()` and access image with returned offset.
Contrary to regular, non-sampled images, reading sampled image does not require sampler object to be created on a host and passed to a kernel.

In this proposal, ZE_experimental_bindless_image is extended with bindless sampled images that use single handle to access image with a sampler.
A new flag is introduced to `ze_image_bindless_exp_flags_t` to allow allocating sampled image with `zeImageCreate()` API.
The flag is set in `ze_image_bindless_exp_desc_t`. pNext member of this struct should point to `ze_sampler_desc_t` when creating sampled images.

Please refer to the programming example below on how to cascade pNext members.

## Dependencies

ZE_experimental_bindless_image

## Details

In file "EXT_EXP_BindlessImages.rst" extend "Bindless Images" section with:

list of additions:
```
 * Create Bindless sampled images
```

description:

```
It is not allowed to create an image view from bindless image without ZE_IMAGE_BINDLESS_EXP_FLAG_BINDLESS.
```

```
A "Bindless sampled image" can be created by passing ze_image_bindless_exp_desc_t to pNext member of
ze_image_desc_t and setting the flags to a combination of ZE_IMAGE_BINDLESS_EXP_FLAG_BINDLESS and ZE_IMAGE_BINDLESS_EXP_FLAG_SAMPLED_IMAGE.
```

```
When image view is created from bindless sampled image, sampling modes can be redefined by passing sampler descriptor in pNext field of ze_image_bindless_exp_desc_t struct.
Image view created from bindless sampled image without setting ZE_IMAGE_BINDLESS_EXP_FLAG_SAMPLED_IMAGE is an unsampled image.
Sampled image view can be created from bindless unsampled image by setting ZE_IMAGE_BINDLESS_EXP_FLAG_SAMPLED_IMAGE and passing sampler descriptor in pNext field of ze_image_bindless_exp_desc_t struct.
```

In file "bindlessimages.yml" extend description of flags member of ze_image_bindless_exp_desc_t:

```
When ZE_IMAGE_BINDLESS_EXP_FLAG_SAMPLED_IMAGE flag is passed, ze_sampler_desc_t must be attached via pNext member of ze_image_bindless_exp_desc_t.
```

Please refer to the programming example below.

### New Object Types

No new types

---

### New Entry Points

No new entry points

---

### New Enums

#### ze_image_bindless_exp_flags_t

New flag added to ze_image_bindless_exp_flags_t:

```cpp
typedef uint32_t ze_image_bindless_exp_flags_t;
typedef enum _ze_image_bindless_exp_flags_t {
    ZE_IMAGE_BINDLESS_EXP_FLAG_BINDLESS = ZE_BIT(0),
    ZE_IMAGE_BINDLESS_EXP_FLAG_SAMPLED_IMAGE = ZE_BIT(1),

    ZE_IMAGE_BINDLESS_EXP_FLAG_FORCE_UINT32 = 0x7fffffff

} ze_image_bindless_exp_flags_t;
```

| Flag        | Description                               |
| :---------- | :---------------------------------------- |
| SAMPLED_IMAGE   | *indicates sampled image is allocated.*             |

---

### New Structures

#### ze_example_structure_exp_properties_t

No new structures

---

### Example Usage

```cpp
    // 2D image dimensions
    size_t imageWidth = 1024;
    size_t imageHeight = 1024;

    // Single-precision float image format with one channel
    ze_image_format_t imageFormat = {
        ZE_IMAGE_FORMAT_LAYOUT_32, ZE_IMAGE_FORMAT_TYPE_FLOAT,
        ZE_IMAGE_FORMAT_SWIZZLE_R, ZE_IMAGE_FORMAT_SWIZZLE_X,
        ZE_IMAGE_FORMAT_SWIZZLE_R, ZE_IMAGE_FORMAT_SWIZZLE_X
    }

    // Define sampler descriptor
    ze_sampler_desc_t samplerDesc = {
        ZE_STRUCTURE_TYPE_SAMPLER_DESC,
        nullptr,
        ZE_SAMPLER_ADDRESS_MODE_CLAMP,
        ZE_SAMPLER_FILTER_MODE_LINEAR,
        true
    };

    // Create an image descriptor for bindless image
    ze_image_desc_t imageDesc = {
        ZE_STRUCTURE_TYPE_IMAGE_DESC,
        nullptr,
        0,
        ZE_IMAGE_TYPE_2D,
        imageFormat,
        imageWidth, imageHeight, 0, 0, 0
    };

    ze_image_bindless_exp_desc_t bindlessImageDesc = {ZE_STRUCTURE_TYPE_BINDLESS_IMAGE_EXP_DESC};
    bindlessImageDesc.flags = ZE_IMAGE_BINDLESS_EXP_FLAG_BINDLESS | ZE_IMAGE_BINDLESS_EXP_FLAG_SAMPLED_IMAGE;
    imageDesc.pNext = &bindlessImageDesc;

    bindlessImageDesc.pNext = &samplerDesc;

    // Create bindless sampled image
    // pass ZE_IMAGE_BINDLESS_EXP_FLAG_BINDLESS and ZE_IMAGE_BINDLESS_EXP_FLAG_SAMPLED_IMAGE to zeImageCreate(),
    ze_image_handle_t hImage;
    zeImageCreate(hContext, hDevice, &imageDesc, &hImage);

    // Create an image view from bindless sampled image
    // define sampler descriptor for view
    ze_sampler_desc_t samplerDescForView = {
        ZE_STRUCTURE_TYPE_SAMPLER_DESC,
        nullptr,
        ZE_SAMPLER_ADDRESS_MODE_CLAMP,
        ZE_SAMPLER_FILTER_MODE_NEAREST,
        true
    };

    ze_image_format_t imageViewFormat = {
        ZE_IMAGE_FORMAT_LAYOUT_32, ZE_IMAGE_FORMAT_TYPE_UINT,
        ZE_IMAGE_FORMAT_SWIZZLE_R, ZE_IMAGE_FORMAT_SWIZZLE_X,
        ZE_IMAGE_FORMAT_SWIZZLE_R, ZE_IMAGE_FORMAT_SWIZZLE_X
    }

    // image descriptor for bindless image view
    ze_image_desc_t imageViewDesc = {
        ZE_STRUCTURE_TYPE_IMAGE_DESC,
        nullptr,
        0,
        ZE_IMAGE_TYPE_2D,
        imageViewFormat,
        128, 128, 0, 0, 0
    };
    imageViewDesc.pNext = &bindlessImageDesc;
    bindlessImageDesc.pNext = &samplerDescForView;
    ze_image_handle_t hImageView;

    zeImageViewCreateExt(hContext, hDevice, &imageViewDesc, hImage, &hImageView);

    // If ZE_IMAGE_BINDLESS_EXP_FLAG_SAMPLED_IMAGE is not set, unsampled image is created
    ze_image_handle_t hUnsampledImageView;
    bindlessImageDesc.flags = ZE_IMAGE_BINDLESS_EXP_FLAG_BINDLESS;
    bindlessImageDesc.pNext = nullptr;
    zeImageViewCreateExt(hContext, hDevice, &imageViewDesc, hImage, &hUnsampledImageView);

    // Create an image view from bindless unsampled image
    ze_image_handle_t hUnsampledImage;
    ze_image_handle_t hSampledImageView;
    bindlessImageDesc.flags = ZE_IMAGE_BINDLESS_EXP_FLAG_BINDLESS;
    bindlessImageDesc.pNext = nullptr;
    imageDesc.pNext = &bindlessImageDesc;

    // create unsampled image
    zeImageCreate(hContext, hDevice, &imageDesc, &hUnsampledImage);

    bindlessImageDesc.flags = ZE_IMAGE_BINDLESS_EXP_FLAG_BINDLESS | ZE_IMAGE_BINDLESS_EXP_FLAG_SAMPLED_IMAGE;
    bindlessImageDesc.pNext = &samplerDescForView;
    zeImageViewCreateExt(hContext, hDevice, &imageDesc, hUnsampledImage, &hSampledImageView);

```
