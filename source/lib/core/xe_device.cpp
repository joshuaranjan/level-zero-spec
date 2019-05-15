/**************************************************************************//**
* INTEL CONFIDENTIAL  
* Copyright 2019  
* Intel Corporation All Rights Reserved.  
*
* @cond DEV
* The source code contained or described herein and all documents related to the  
* source code ("Material") are owned by Intel Corporation or its suppliers or  
* licensors. Title to the Material remains with Intel Corporation or its suppliers  
* and licensors. The Material contains trade secrets and proprietary and confidential  
* information of Intel or its suppliers and licensors. The Material is protected by  
* worldwide copyright and trade secret laws and treaty provisions. No part of the  
* Material may be used, copied, reproduced, modified, published, uploaded, posted  
* transmitted, distributed, or disclosed in any way without Intel's prior express  
* written permission.  
*
* No license under any patent, copyright, trade secret or other intellectual  
* property right is granted to or conferred upon you by disclosure or delivery  
* of the Materials, either expressly, by implication, inducement, estoppel  
* or otherwise. Any license under such intellectual property rights must be  
* express and approved by Intel in writing.  
* @endcond
*
* @file xe_device.cpp
*
* @brief C++ wrapper of Intel Xe Level-Zero APIs for Device
*
* @cond DEV
* DO NOT EDIT: generated from /scripts/core/device.yml
* @endcond
*
******************************************************************************/
#include "xe_api.hpp"
#include "xe_ddi.h"
#include "xe_lib.h"

extern "C" {

///////////////////////////////////////////////////////////////////////////////
/// @brief Retrieves device groups
/// 
/// @details
///     - A device group represents a collection of physical, homogeneous
///       devices.
///     - The application may pass nullptr for pDeviceGroups when only querying
///       the number of device groups.
///     - The application may call this function from simultaneous threads.
///     - The implementation of this function should be lock-free.
/// 
/// @remarks
///   _Analogues_
///     - clGetDeviceIDs
/// 
/// @returns
///     - ::XE_RESULT_SUCCESS
///     - ::XE_RESULT_ERROR_UNINITIALIZED
///     - ::XE_RESULT_ERROR_DEVICE_LOST
///     - ::XE_RESULT_ERROR_INVALID_PARAMETER
///         + nullptr == pCount
///     - ::XE_RESULT_ERROR_UNSUPPORTED
xe_result_t __xecall
xeGetDeviceGroups(
    size_t* pCount,                                 ///< [in,out] pointer to the number of device groups.
                                                    ///< if count is zero, then the driver will update the value with the total
                                                    ///< number of device groups available.
                                                    ///< if count is non-zero, then driver will only retrieve that number of
                                                    ///< device groups.
    xe_device_group_handle_t* pDeviceGroups         ///< [in,out][optional] array of handle of device groups
    )
{
    return XE_RESULT_SUCCESS;
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Retrieves devices within a device group
/// 
/// @details
///     - The application may call this function from simultaneous threads.
///     - The implementation of this function should be lock-free.
/// 
/// @remarks
///   _Analogues_
///     - **cuDeviceGet**
/// 
/// @returns
///     - ::XE_RESULT_SUCCESS
///     - ::XE_RESULT_ERROR_UNINITIALIZED
///     - ::XE_RESULT_ERROR_DEVICE_LOST
///     - ::XE_RESULT_ERROR_INVALID_PARAMETER
///         + nullptr == hDeviceGroup
///         + nullptr == pCount
///         + count is out of range reported by ::xeDeviceGroupGetDevices
///     - ::XE_RESULT_ERROR_UNSUPPORTED
xe_result_t __xecall
xeDeviceGroupGetDevices(
    xe_device_group_handle_t hDeviceGroup,          ///< [in] handle of the device group object
    size_t* pCount,                                 ///< [in,out] pointer to the number of device groups.
                                                    ///< if count is zero, then the driver will update the value with the total
                                                    ///< number of device groups available.
                                                    ///< if count is non-zero, then driver will only retrieve that number of
                                                    ///< device groups.
    xe_device_group_handle_t* pDeviceGroups         ///< [in,out][optional] array of handle of device groups
    )
{
    return XE_RESULT_SUCCESS;
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Retrieves a sub-device from a device
/// 
/// @details
///     - The application may call this function from simultaneous threads.
///     - The implementation of this function should be lock-free.
/// 
/// @remarks
///   _Analogues_
///     - clCreateSubDevices
/// 
/// @returns
///     - ::XE_RESULT_SUCCESS
///     - ::XE_RESULT_ERROR_UNINITIALIZED
///     - ::XE_RESULT_ERROR_DEVICE_LOST
///     - ::XE_RESULT_ERROR_INVALID_PARAMETER
///         + nullptr == hDevice
///         + nullptr == phSubDevice
///         + ordinal is out of range reported by device properties.
///     - ::XE_RESULT_ERROR_UNSUPPORTED
xe_result_t __xecall
xeDeviceGetSubDevice(
    xe_device_handle_t hDevice,                     ///< [in] handle of the device object
    uint32_t ordinal,                               ///< [in] ordinal of sub-device to retrieve
    xe_device_handle_t* phSubDevice                 ///< [out] pointer to handle of sub-device object.
    )
{
    return XE_RESULT_SUCCESS;
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Returns the API version supported by the device group
/// 
/// @details
///     - The application may call this function from simultaneous threads.
///     - The implementation of this function should be lock-free.
/// 
/// @remarks
///   _Analogues_
///     - **cuCtxGetApiVersion**
/// 
/// @returns
///     - ::XE_RESULT_SUCCESS
///     - ::XE_RESULT_ERROR_UNINITIALIZED
///     - ::XE_RESULT_ERROR_DEVICE_LOST
///     - ::XE_RESULT_ERROR_INVALID_PARAMETER
///         + nullptr == hDeviceGroup
///         + nullptr == version
///     - ::XE_RESULT_ERROR_UNSUPPORTED
xe_result_t __xecall
xeDeviceGroupGetApiVersion(
    xe_device_group_handle_t hDeviceGroup,          ///< [in] handle of the device group object
    xe_api_version_t* version                       ///< [out] api version
    )
{
    return XE_RESULT_SUCCESS;
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Retrieves attributes of the device
/// 
/// @details
///     - The application may call this function from simultaneous threads.
///     - The implementation of this function should be lock-free.
/// 
/// @remarks
///   _Analogues_
///     - **cuDeviceGetAttribute**
///     - cuDeviceGetName
///     - clGetDeviceInfo
/// 
/// @returns
///     - ::XE_RESULT_SUCCESS
///     - ::XE_RESULT_ERROR_UNINITIALIZED
///     - ::XE_RESULT_ERROR_DEVICE_LOST
///     - ::XE_RESULT_ERROR_INVALID_PARAMETER
///         + nullptr == hDeviceGroup
///         + nullptr == pDeviceProperties
///     - ::XE_RESULT_ERROR_UNSUPPORTED
xe_result_t __xecall
xeDeviceGroupGetProperties(
    xe_device_group_handle_t hDeviceGroup,          ///< [in] handle of the device group object
    xe_device_properties_t* pDeviceProperties       ///< [out] query result for device properties
    )
{
    return XE_RESULT_SUCCESS;
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Retrieves compute attributes of the device group
/// 
/// @details
///     - The application may call this function from simultaneous threads.
///     - The implementation of this function should be lock-free.
/// 
/// @remarks
///   _Analogues_
///     - **cuDeviceGetAttribute**
///     - clGetDeviceInfo
/// 
/// @returns
///     - ::XE_RESULT_SUCCESS
///     - ::XE_RESULT_ERROR_UNINITIALIZED
///     - ::XE_RESULT_ERROR_DEVICE_LOST
///     - ::XE_RESULT_ERROR_INVALID_PARAMETER
///         + nullptr == hDeviceGroup
///         + nullptr == pComputeProperties
///     - ::XE_RESULT_ERROR_UNSUPPORTED
xe_result_t __xecall
xeDeviceGroupGetComputeProperties(
    xe_device_group_handle_t hDeviceGroup,          ///< [in] handle of the device group object
    xe_device_compute_properties_t* pComputeProperties  ///< [out] query result for compute properties
    )
{
    return XE_RESULT_SUCCESS;
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Retrieves memory attributes of the device
/// 
/// @details
///     - The application may call this function from simultaneous threads.
///     - The implementation of this function should be lock-free.
/// 
/// @remarks
///   _Analogues_
///     - **cuDeviceGetAttribute**
///     - cuDeviceTotalMem
///     - clGetDeviceInfo
/// 
/// @returns
///     - ::XE_RESULT_SUCCESS
///     - ::XE_RESULT_ERROR_UNINITIALIZED
///     - ::XE_RESULT_ERROR_DEVICE_LOST
///     - ::XE_RESULT_ERROR_INVALID_PARAMETER
///         + nullptr == hDeviceGroup
///         + nullptr == pMemProperties
///     - ::XE_RESULT_ERROR_UNSUPPORTED
xe_result_t __xecall
xeDeviceGroupGetMemoryProperties(
    xe_device_group_handle_t hDeviceGroup,          ///< [in] handle of the device group object
    xe_device_memory_properties_t* pMemProperties   ///< [out] query result for compute properties
    )
{
    return XE_RESULT_SUCCESS;
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Retrieves Peer-to-Peer properties between one device and a peer
///        devices
/// 
/// @details
///     - The application may call this function from simultaneous threads.
///     - The implementation of this function should be lock-free.
/// 
/// @remarks
///   _Analogues_
///     - **cudaDeviceGetP2PAttribute**
/// 
/// @returns
///     - ::XE_RESULT_SUCCESS
///     - ::XE_RESULT_ERROR_UNINITIALIZED
///     - ::XE_RESULT_ERROR_DEVICE_LOST
///     - ::XE_RESULT_ERROR_INVALID_PARAMETER
///         + nullptr == hDevice
///         + nullptr == hPeerDevice
///         + nullptr == pP2PProperties
///     - ::XE_RESULT_ERROR_UNSUPPORTED
xe_result_t __xecall
xeDeviceGetP2PProperties(
    xe_device_handle_t hDevice,                     ///< [in] handle of the device performing the access
    xe_device_handle_t hPeerDevice,                 ///< [in] handle of the peer device with the allocation
    xe_device_p2p_properties_t* pP2PProperties      ///< [out] Peer-to-Peer properties between source and peer device
    )
{
    return XE_RESULT_SUCCESS;
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Queries if one device can directly access peer device allocations
/// 
/// @details
///     - The application may call this function from simultaneous threads.
///     - The implementation of this function should be lock-free.
/// 
/// @remarks
///   _Analogues_
///     - **cudaDeviceCanAccessPeer**
/// 
/// @returns
///     - ::XE_RESULT_SUCCESS
///     - ::XE_RESULT_ERROR_UNINITIALIZED
///     - ::XE_RESULT_ERROR_DEVICE_LOST
///     - ::XE_RESULT_ERROR_INVALID_PARAMETER
///         + nullptr == hDevice
///         + nullptr == hPeerDevice
///         + nullptr == value
///     - ::XE_RESULT_ERROR_UNSUPPORTED
xe_result_t __xecall
xeDeviceCanAccessPeer(
    xe_device_handle_t hDevice,                     ///< [in] handle of the device performing the access
    xe_device_handle_t hPeerDevice,                 ///< [in] handle of the peer device with the allocation
    xe_bool_t* value                                ///< [out] returned access capability
    )
{
    return XE_RESULT_SUCCESS;
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Sets the preferred Intermediate cache configuration for a device.
/// 
/// @details
///     - The application may **not** call this function from simultaneous
///       threads with the same device handle.
/// 
/// @remarks
///   _Analogues_
///     - **cudaFuncSetCacheConfig **
/// 
/// @returns
///     - ::XE_RESULT_SUCCESS
///     - ::XE_RESULT_ERROR_UNINITIALIZED
///     - ::XE_RESULT_ERROR_DEVICE_LOST
///     - ::XE_RESULT_ERROR_INVALID_PARAMETER
///         + nullptr == hDevice
///         + devices do not support CacheConfig
///     - ::XE_RESULT_ERROR_UNSUPPORTED
xe_result_t __xecall
xeDeviceSetIntermediateCacheConfig(
    xe_device_handle_t hDevice,                     ///< [in] handle of the device 
    xe_cache_config_t CacheConfig                   ///< [in] CacheConfig
    )
{
    return XE_RESULT_SUCCESS;
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Sets the preferred Last Level cache configuration for a device.
/// 
/// @details
///     - The application may **not** call this function from simultaneous
///       threads with the same device handle.
/// 
/// @remarks
///   _Analogues_
///     - **cudaFuncSetCacheConfig **
/// 
/// @returns
///     - ::XE_RESULT_SUCCESS
///     - ::XE_RESULT_ERROR_UNINITIALIZED
///     - ::XE_RESULT_ERROR_DEVICE_LOST
///     - ::XE_RESULT_ERROR_INVALID_PARAMETER
///         + nullptr == hDevice
///         + devices do not support CacheConfig
///     - ::XE_RESULT_ERROR_UNSUPPORTED
xe_result_t __xecall
xeDeviceSetLastLevelCacheConfig(
    xe_device_handle_t hDevice,                     ///< [in] handle of the device 
    xe_cache_config_t CacheConfig                   ///< [in] CacheConfig
    )
{
    return XE_RESULT_SUCCESS;
}

} // extern "C"

namespace xe
{
    ///////////////////////////////////////////////////////////////////////////////
    DeviceGroup::DeviceGroup( 
        void
        )
    {
    }

    ///////////////////////////////////////////////////////////////////////////////
    Device::Device( 
        DeviceGroup* pDeviceGroup                       ///< [in] pointer to parent object
        ) :
        m_pDeviceGroup( pDeviceGroup )
    {
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Retrieves device groups
    /// 
    /// @details
    ///     - A device group represents a collection of physical, homogeneous
    ///       devices.
    ///     - The application may pass nullptr for pDeviceGroups when only querying
    ///       the number of device groups.
    ///     - The application may call this function from simultaneous threads.
    ///     - The implementation of this function should be lock-free.
    /// 
    /// @remarks
    ///   _Analogues_
    ///     - clGetDeviceIDs
    /// 
    /// @throws result_t
    void __xecall
    GetDeviceGroups(
        size_t* pCount,                                 ///< [in,out] pointer to the number of device groups.
                                                        ///< if count is zero, then the driver will update the value with the total
                                                        ///< number of device groups available.
                                                        ///< if count is non-zero, then driver will only retrieve that number of
                                                        ///< device groups.
        DeviceGroup* pDeviceGroups                      ///< [in,out][optional] array of pointer to device groups
        )
    {
        // auto result = ::xeGetDeviceGroups( handle, pCount, pDeviceGroups );
        // if( ::XE_RESULT_SUCCESS != result ) throw exception(result, "GetDeviceGroups");
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Retrieves devices within a device group
    /// 
    /// @details
    ///     - The application may call this function from simultaneous threads.
    ///     - The implementation of this function should be lock-free.
    /// 
    /// @remarks
    ///   _Analogues_
    ///     - **cuDeviceGet**
    /// 
    /// @throws result_t
    void __xecall
    DeviceGroup::GetDevices(
        size_t* pCount,                                 ///< [in,out] pointer to the number of device groups.
                                                        ///< if count is zero, then the driver will update the value with the total
                                                        ///< number of device groups available.
                                                        ///< if count is non-zero, then driver will only retrieve that number of
                                                        ///< device groups.
        DeviceGroup* pDeviceGroups                      ///< [in,out][optional] array of pointer to device groups
        )
    {
        // auto result = ::xeDeviceGroupGetDevices( handle, pCount, pDeviceGroups );
        // if( ::XE_RESULT_SUCCESS != result ) throw exception(result, "xe::DeviceGroup::GetDevices");
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Retrieves a sub-device from a device
    /// 
    /// @details
    ///     - The application may call this function from simultaneous threads.
    ///     - The implementation of this function should be lock-free.
    /// 
    /// @remarks
    ///   _Analogues_
    ///     - clCreateSubDevices
    /// 
    /// @returns
    ///     - Device: pointer to handle of sub-device object.
    /// 
    /// @throws result_t
    Device* __xecall
    Device::GetSubDevice(
        uint32_t ordinal                                ///< [in] ordinal of sub-device to retrieve
        )
    {
        // auto result = ::xeDeviceGetSubDevice( handle, ordinal );
        // if( ::XE_RESULT_SUCCESS != result ) throw exception(result, "xe::Device::GetSubDevice");

        return (Device*)0;
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Returns the API version supported by the device group
    /// 
    /// @details
    ///     - The application may call this function from simultaneous threads.
    ///     - The implementation of this function should be lock-free.
    /// 
    /// @remarks
    ///   _Analogues_
    ///     - **cuCtxGetApiVersion**
    /// 
    /// @returns
    ///     - api_version_t: api version
    /// 
    /// @throws result_t
    DeviceGroup::api_version_t __xecall
    DeviceGroup::GetApiVersion(
        void
        )
    {
        // auto result = ::xeDeviceGroupGetApiVersion( handle );
        // if( ::XE_RESULT_SUCCESS != result ) throw exception(result, "xe::DeviceGroup::GetApiVersion");

        return api_version_t{};
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Retrieves attributes of the device
    /// 
    /// @details
    ///     - The application may call this function from simultaneous threads.
    ///     - The implementation of this function should be lock-free.
    /// 
    /// @remarks
    ///   _Analogues_
    ///     - **cuDeviceGetAttribute**
    ///     - cuDeviceGetName
    ///     - clGetDeviceInfo
    /// 
    /// @returns
    ///     - device_properties_t: query result for device properties
    /// 
    /// @throws result_t
    DeviceGroup::device_properties_t __xecall
    DeviceGroup::GetProperties(
        void
        )
    {
        // auto result = ::xeDeviceGroupGetProperties( handle );
        // if( ::XE_RESULT_SUCCESS != result ) throw exception(result, "xe::DeviceGroup::GetProperties");

        return device_properties_t{};
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Retrieves compute attributes of the device group
    /// 
    /// @details
    ///     - The application may call this function from simultaneous threads.
    ///     - The implementation of this function should be lock-free.
    /// 
    /// @remarks
    ///   _Analogues_
    ///     - **cuDeviceGetAttribute**
    ///     - clGetDeviceInfo
    /// 
    /// @returns
    ///     - device_compute_properties_t: query result for compute properties
    /// 
    /// @throws result_t
    DeviceGroup::device_compute_properties_t __xecall
    DeviceGroup::GetComputeProperties(
        void
        )
    {
        // auto result = ::xeDeviceGroupGetComputeProperties( handle );
        // if( ::XE_RESULT_SUCCESS != result ) throw exception(result, "xe::DeviceGroup::GetComputeProperties");

        return device_compute_properties_t{};
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Retrieves memory attributes of the device
    /// 
    /// @details
    ///     - The application may call this function from simultaneous threads.
    ///     - The implementation of this function should be lock-free.
    /// 
    /// @remarks
    ///   _Analogues_
    ///     - **cuDeviceGetAttribute**
    ///     - cuDeviceTotalMem
    ///     - clGetDeviceInfo
    /// 
    /// @returns
    ///     - device_memory_properties_t: query result for compute properties
    /// 
    /// @throws result_t
    DeviceGroup::device_memory_properties_t __xecall
    DeviceGroup::GetMemoryProperties(
        void
        )
    {
        // auto result = ::xeDeviceGroupGetMemoryProperties( handle );
        // if( ::XE_RESULT_SUCCESS != result ) throw exception(result, "xe::DeviceGroup::GetMemoryProperties");

        return device_memory_properties_t{};
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Retrieves Peer-to-Peer properties between one device and a peer
    ///        devices
    /// 
    /// @details
    ///     - The application may call this function from simultaneous threads.
    ///     - The implementation of this function should be lock-free.
    /// 
    /// @remarks
    ///   _Analogues_
    ///     - **cudaDeviceGetP2PAttribute**
    /// 
    /// @returns
    ///     - p2p_properties_t: Peer-to-Peer properties between source and peer device
    /// 
    /// @throws result_t
    Device::p2p_properties_t __xecall
    Device::GetP2PProperties(
        Device* pPeerDevice                             ///< [in] pointer to the peer device with the allocation
        )
    {
        // auto result = ::xeDeviceGetP2PProperties( handle, pPeerDevice );
        // if( ::XE_RESULT_SUCCESS != result ) throw exception(result, "xe::Device::GetP2PProperties");

        return p2p_properties_t{};
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Queries if one device can directly access peer device allocations
    /// 
    /// @details
    ///     - The application may call this function from simultaneous threads.
    ///     - The implementation of this function should be lock-free.
    /// 
    /// @remarks
    ///   _Analogues_
    ///     - **cudaDeviceCanAccessPeer**
    /// 
    /// @returns
    ///     - bool_t: returned access capability
    /// 
    /// @throws result_t
    bool_t __xecall
    Device::CanAccessPeer(
        Device* pPeerDevice                             ///< [in] pointer to the peer device with the allocation
        )
    {
        // auto result = ::xeDeviceCanAccessPeer( handle, pPeerDevice );
        // if( ::XE_RESULT_SUCCESS != result ) throw exception(result, "xe::Device::CanAccessPeer");

        return bool_t{};
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Sets the preferred Intermediate cache configuration for a device.
    /// 
    /// @details
    ///     - The application may **not** call this function from simultaneous
    ///       threads with the same device handle.
    /// 
    /// @remarks
    ///   _Analogues_
    ///     - **cudaFuncSetCacheConfig **
    /// 
    /// @throws result_t
    void __xecall
    Device::SetIntermediateCacheConfig(
        cache_config_t CacheConfig                      ///< [in] CacheConfig
        )
    {
        // auto result = ::xeDeviceSetIntermediateCacheConfig( handle, CacheConfig );
        // if( ::XE_RESULT_SUCCESS != result ) throw exception(result, "xe::Device::SetIntermediateCacheConfig");
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Sets the preferred Last Level cache configuration for a device.
    /// 
    /// @details
    ///     - The application may **not** call this function from simultaneous
    ///       threads with the same device handle.
    /// 
    /// @remarks
    ///   _Analogues_
    ///     - **cudaFuncSetCacheConfig **
    /// 
    /// @throws result_t
    void __xecall
    Device::SetLastLevelCacheConfig(
        cache_config_t CacheConfig                      ///< [in] CacheConfig
        )
    {
        // auto result = ::xeDeviceSetLastLevelCacheConfig( handle, CacheConfig );
        // if( ::XE_RESULT_SUCCESS != result ) throw exception(result, "xe::Device::SetLastLevelCacheConfig");
    }

} // namespace xe

#ifdef _DEBUG
    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Converts DeviceGroup::api_version_t to std::string
    std::string to_string( xe::DeviceGroup::api_version_t val )
    {
        switch( val )
        {
        case xe::DeviceGroup::api_version_t::_1_0:
            return std::string("xe::DeviceGroup::api_version_t::_1_0");
        };
        return std::string("xe::DeviceGroup::api_version_t::?");
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Converts DeviceGroup::device_properties_version_t to std::string
    std::string to_string( xe::DeviceGroup::device_properties_version_t val )
    {
        switch( val )
        {
        case xe::DeviceGroup::device_properties_version_t::CURRENT:
            return std::string("xe::DeviceGroup::device_properties_version_t::CURRENT");
        };
        return std::string("xe::DeviceGroup::device_properties_version_t::?");
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Converts DeviceGroup::device_compute_properties_version_t to std::string
    std::string to_string( xe::DeviceGroup::device_compute_properties_version_t val )
    {
        switch( val )
        {
        case xe::DeviceGroup::device_compute_properties_version_t::CURRENT:
            return std::string("xe::DeviceGroup::device_compute_properties_version_t::CURRENT");
        };
        return std::string("xe::DeviceGroup::device_compute_properties_version_t::?");
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Converts DeviceGroup::device_memory_properties_version_t to std::string
    std::string to_string( xe::DeviceGroup::device_memory_properties_version_t val )
    {
        switch( val )
        {
        case xe::DeviceGroup::device_memory_properties_version_t::CURRENT:
            return std::string("xe::DeviceGroup::device_memory_properties_version_t::CURRENT");
        };
        return std::string("xe::DeviceGroup::device_memory_properties_version_t::?");
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Converts DeviceGroup::memory_access_capabilities_t to std::string
    std::string to_string( xe::DeviceGroup::memory_access_capabilities_t val )
    {
        const auto bits = static_cast<uint32_t>( val );
        if( 0 == bits ) return std::string("{}");
        std::string str;
        if( static_cast<uint32_t>(xe::DeviceGroup::memory_access_capabilities_t::MEMORY_ACCESS) & bits )
            str += "xe::DeviceGroup::memory_access_capabilities_t::MEMORY_ACCESS | ";
        if( static_cast<uint32_t>(xe::DeviceGroup::memory_access_capabilities_t::MEMORY_ATOMIC_ACCESS) & bits )
            str += "xe::DeviceGroup::memory_access_capabilities_t::MEMORY_ATOMIC_ACCESS | ";
        if( static_cast<uint32_t>(xe::DeviceGroup::memory_access_capabilities_t::MEMORY_CONCURRENT_ACCESS) & bits )
            str += "xe::DeviceGroup::memory_access_capabilities_t::MEMORY_CONCURRENT_ACCESS | ";
        if( static_cast<uint32_t>(xe::DeviceGroup::memory_access_capabilities_t::MEMORY_CONCURRENT_ATOMIC_ACCESS) & bits )
            str += "xe::DeviceGroup::memory_access_capabilities_t::MEMORY_CONCURRENT_ATOMIC_ACCESS | ";
        return "{ " + str.substr(0, str.size() - 3) + " }";
    }


    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Converts Device::p2p_properties_version_t to std::string
    std::string to_string( xe::Device::p2p_properties_version_t val )
    {
        switch( val )
        {
        case xe::Device::p2p_properties_version_t::CURRENT:
            return std::string("xe::Device::p2p_properties_version_t::CURRENT");
        };
        return std::string("xe::Device::p2p_properties_version_t::?");
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Converts Device::cache_config_t to std::string
    std::string to_string( xe::Device::cache_config_t val )
    {
        const auto bits = static_cast<uint32_t>( val );
        if( 0 == bits ) return std::string("{}");
        std::string str;
        if( static_cast<uint32_t>(xe::Device::cache_config_t::DEFAULT) & bits )
            str += "xe::Device::cache_config_t::DEFAULT | ";
        if( static_cast<uint32_t>(xe::Device::cache_config_t::LARGE_SLM) & bits )
            str += "xe::Device::cache_config_t::LARGE_SLM | ";
        if( static_cast<uint32_t>(xe::Device::cache_config_t::LARGE_DATA) & bits )
            str += "xe::Device::cache_config_t::LARGE_DATA | ";
        return "{ " + str.substr(0, str.size() - 3) + " }";
    }


#endif // _DEBUG
