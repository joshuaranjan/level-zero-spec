/*
 *
 * Copyright (C) 2019 Intel Corporation
 *
 * SPDX-License-Identifier: MIT
 *
 * @file ze_residency.cpp
 *
 * @brief C++ wrapper of Intel 'One API' Level-Zero APIs for Memory Residency
 *
 * @cond DEV
 * DO NOT EDIT: generated from /scripts/core/residency.yml
 * @endcond
 *
 */
#include "ze_lib.h"

extern "C" {

///////////////////////////////////////////////////////////////////////////////
/// @brief Makes memory resident for the device.
/// 
/// @details
///     - If the application does not properly manage residency then the device
///       may experience unrecoverable page-faults.
///     - The application may call this function from simultaneous threads.
///     - The implementation of this function should be lock-free.
/// 
/// @returns
///     - ::ZE_RESULT_SUCCESS
///     - ::ZE_RESULT_ERROR_UNINITIALIZED
///     - ::ZE_RESULT_ERROR_DEVICE_LOST
///     - ::ZE_RESULT_ERROR_INVALID_NULL_HANDLE
///         + `nullptr == hDevice`
///     - ::ZE_RESULT_ERROR_INVALID_NULL_POINTER
///         + `nullptr == ptr`
///     - ::ZE_RESULT_ERROR_OUT_OF_HOST_MEMORY
///     - ::ZE_RESULT_ERROR_OUT_OF_DEVICE_MEMORY
ze_result_t __zecall
zeDeviceMakeMemoryResident(
    ze_device_handle_t hDevice,                     ///< [in] handle of the device
    void* ptr,                                      ///< [in] pointer to memory to make resident
    size_t size                                     ///< [in] size in bytes to make resident
    )
{
    auto pfnMakeMemoryResident = ze_lib::context.ddiTable.Device.pfnMakeMemoryResident;
    if( nullptr == pfnMakeMemoryResident )
        return ZE_RESULT_ERROR_UNSUPPORTED_VERSION;

    return pfnMakeMemoryResident( hDevice, ptr, size );
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Allows memory to be evicted from the device.
/// 
/// @details
///     - The application is responsible for making sure the device is not
///       currently referencing the memory before it is evicted
///     - Memory is always implicitly evicted if it is resident when freed.
///     - The application may call this function from simultaneous threads.
///     - The implementation of this function should be lock-free.
/// 
/// @returns
///     - ::ZE_RESULT_SUCCESS
///     - ::ZE_RESULT_ERROR_UNINITIALIZED
///     - ::ZE_RESULT_ERROR_DEVICE_LOST
///     - ::ZE_RESULT_ERROR_INVALID_NULL_HANDLE
///         + `nullptr == hDevice`
///     - ::ZE_RESULT_ERROR_INVALID_NULL_POINTER
///         + `nullptr == ptr`
///     - ::ZE_RESULT_ERROR_OUT_OF_HOST_MEMORY
///     - ::ZE_RESULT_ERROR_OUT_OF_DEVICE_MEMORY
ze_result_t __zecall
zeDeviceEvictMemory(
    ze_device_handle_t hDevice,                     ///< [in] handle of the device
    void* ptr,                                      ///< [in] pointer to memory to evict
    size_t size                                     ///< [in] size in bytes to evict
    )
{
    auto pfnEvictMemory = ze_lib::context.ddiTable.Device.pfnEvictMemory;
    if( nullptr == pfnEvictMemory )
        return ZE_RESULT_ERROR_UNSUPPORTED_VERSION;

    return pfnEvictMemory( hDevice, ptr, size );
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Makes image resident for the device.
/// 
/// @details
///     - If the application does not properly manage residency then the device
///       may experience unrecoverable page-faults.
///     - The application may call this function from simultaneous threads.
///     - The implementation of this function should be lock-free.
/// 
/// @returns
///     - ::ZE_RESULT_SUCCESS
///     - ::ZE_RESULT_ERROR_UNINITIALIZED
///     - ::ZE_RESULT_ERROR_DEVICE_LOST
///     - ::ZE_RESULT_ERROR_INVALID_NULL_HANDLE
///         + `nullptr == hDevice`
///         + `nullptr == hImage`
///     - ::ZE_RESULT_ERROR_OUT_OF_HOST_MEMORY
///     - ::ZE_RESULT_ERROR_OUT_OF_DEVICE_MEMORY
ze_result_t __zecall
zeDeviceMakeImageResident(
    ze_device_handle_t hDevice,                     ///< [in] handle of the device
    ze_image_handle_t hImage                        ///< [in] handle of image to make resident
    )
{
    auto pfnMakeImageResident = ze_lib::context.ddiTable.Device.pfnMakeImageResident;
    if( nullptr == pfnMakeImageResident )
        return ZE_RESULT_ERROR_UNSUPPORTED_VERSION;

    return pfnMakeImageResident( hDevice, hImage );
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Allows image to be evicted from the device.
/// 
/// @details
///     - The application is responsible for making sure the device is not
///       currently referencing the memory before it is evicted
///     - An image is always implicitly evicted if it is resident when
///       destroyed.
///     - The application may call this function from simultaneous threads.
///     - The implementation of this function should be lock-free.
/// 
/// @returns
///     - ::ZE_RESULT_SUCCESS
///     - ::ZE_RESULT_ERROR_UNINITIALIZED
///     - ::ZE_RESULT_ERROR_DEVICE_LOST
///     - ::ZE_RESULT_ERROR_INVALID_NULL_HANDLE
///         + `nullptr == hDevice`
///         + `nullptr == hImage`
///     - ::ZE_RESULT_ERROR_OUT_OF_HOST_MEMORY
///     - ::ZE_RESULT_ERROR_OUT_OF_DEVICE_MEMORY
ze_result_t __zecall
zeDeviceEvictImage(
    ze_device_handle_t hDevice,                     ///< [in] handle of the device
    ze_image_handle_t hImage                        ///< [in] handle of image to make evict
    )
{
    auto pfnEvictImage = ze_lib::context.ddiTable.Device.pfnEvictImage;
    if( nullptr == pfnEvictImage )
        return ZE_RESULT_ERROR_UNSUPPORTED_VERSION;

    return pfnEvictImage( hDevice, hImage );
}

} // extern "C"

namespace ze
{
    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Makes memory resident for the device.
    /// 
    /// @details
    ///     - If the application does not properly manage residency then the device
    ///       may experience unrecoverable page-faults.
    ///     - The application may call this function from simultaneous threads.
    ///     - The implementation of this function should be lock-free.
    /// 
    /// @throws result_t
    void __zecall
    Device::MakeMemoryResident(
        void* ptr,                                      ///< [in] pointer to memory to make resident
        size_t size                                     ///< [in] size in bytes to make resident
        )
    {
        auto result = static_cast<result_t>( ::zeDeviceMakeMemoryResident(
            reinterpret_cast<ze_device_handle_t>( getHandle() ),
            ptr,
            size ) );

        if( result_t::SUCCESS != result )
            throw exception_t( result, __FILE__, STRING(__LINE__), "ze::Device::MakeMemoryResident" );
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Allows memory to be evicted from the device.
    /// 
    /// @details
    ///     - The application is responsible for making sure the device is not
    ///       currently referencing the memory before it is evicted
    ///     - Memory is always implicitly evicted if it is resident when freed.
    ///     - The application may call this function from simultaneous threads.
    ///     - The implementation of this function should be lock-free.
    /// 
    /// @throws result_t
    void __zecall
    Device::EvictMemory(
        void* ptr,                                      ///< [in] pointer to memory to evict
        size_t size                                     ///< [in] size in bytes to evict
        )
    {
        auto result = static_cast<result_t>( ::zeDeviceEvictMemory(
            reinterpret_cast<ze_device_handle_t>( getHandle() ),
            ptr,
            size ) );

        if( result_t::SUCCESS != result )
            throw exception_t( result, __FILE__, STRING(__LINE__), "ze::Device::EvictMemory" );
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Makes image resident for the device.
    /// 
    /// @details
    ///     - If the application does not properly manage residency then the device
    ///       may experience unrecoverable page-faults.
    ///     - The application may call this function from simultaneous threads.
    ///     - The implementation of this function should be lock-free.
    /// 
    /// @throws result_t
    void __zecall
    Device::MakeImageResident(
        Image* pImage                                   ///< [in] pointer to image to make resident
        )
    {
        auto result = static_cast<result_t>( ::zeDeviceMakeImageResident(
            reinterpret_cast<ze_device_handle_t>( getHandle() ),
            reinterpret_cast<ze_image_handle_t>( pImage->getHandle() ) ) );

        if( result_t::SUCCESS != result )
            throw exception_t( result, __FILE__, STRING(__LINE__), "ze::Device::MakeImageResident" );
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Allows image to be evicted from the device.
    /// 
    /// @details
    ///     - The application is responsible for making sure the device is not
    ///       currently referencing the memory before it is evicted
    ///     - An image is always implicitly evicted if it is resident when
    ///       destroyed.
    ///     - The application may call this function from simultaneous threads.
    ///     - The implementation of this function should be lock-free.
    /// 
    /// @throws result_t
    void __zecall
    Device::EvictImage(
        Image* pImage                                   ///< [in] pointer to image to make evict
        )
    {
        auto result = static_cast<result_t>( ::zeDeviceEvictImage(
            reinterpret_cast<ze_device_handle_t>( getHandle() ),
            reinterpret_cast<ze_image_handle_t>( pImage->getHandle() ) ) );

        if( result_t::SUCCESS != result )
            throw exception_t( result, __FILE__, STRING(__LINE__), "ze::Device::EvictImage" );
    }

} // namespace ze

namespace ze
{
} // namespace ze
