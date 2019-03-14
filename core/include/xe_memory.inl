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
* @file xe_memory.inl
*
* @brief C++ wrapper of Intel Xe Driver APIs for Memory
*
* @cond DEV
* DO NOT EDIT: generated from /scripts/core/memory.yml
* @endcond
*
******************************************************************************/
#ifndef _XE_MEMORY_INL
#define _XE_MEMORY_INL
#if defined(__cplusplus)
#pragma once
#include "xe_memory.hpp"

namespace xe
{
    ///////////////////////////////////////////////////////////////////////////////
    /// @brief C++ wrapper for ::xeCreateMemAllocator
    /// 
    /// @details
    ///     - Memory allocators store information about allocations.
    ///     - The application may call this function from simultaneous threads.
    ///     - The implementation of this function should be lock-free.
    /// 
    /// @returns
    ///     - mem_allocator_handle_t: Returned memory allocator handle
    /// 
    /// @throws result_t
    inline mem_allocator_handle_t 
    CreateMemAllocator(
        void
        )
    {
        // auto result = ::xeCreateMemAllocator( handle );
        // if( ::XE_RESULT_SUCCESS != result ) throw exception(result, "xe::CreateMemAllocator::CreateMemAllocator");
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief C++ wrapper for ::xeMemAllocatorDestroy
    /// 
    /// @details
    ///     - The application is responsible for making sure the GPU is not
    ///       currently referencing any memory allocations associated with this
    ///       allocator before it is deleted.
    ///     - The implementation of this function will immediately free all memory
    ///       allocations associated with this allocator.
    ///     - The implementation of this function should be lock-free.
    /// 
    /// @throws result_t
    inline void 
    MemAllocatorDestroy(
        mem_allocator_handle_t hMemAllocHandle          ///< [in] handle of memory allocator to destroy
        )
    {
        // auto result = ::xeMemAllocatorDestroy( handle );
        // if( ::XE_RESULT_SUCCESS != result ) throw exception(result, "xe::MemAllocatorDestroy::MemAllocatorDestroy");
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief C++ wrapper for ::xeSharedMemAlloc
    /// 
    /// @details
    ///     - Shared allocations share ownership between the host and one or more
    ///       devices.
    ///     - The application may call this function from simultaneous threads.
    ///     - The implementation of this function should be lock-free.
    /// 
    /// @remarks
    ///   _Analogues_
    ///     - **cudaMallocManaged**
    /// 
    /// @returns
    ///     - void*: pointer to shared allocation
    /// 
    /// @throws result_t
    inline void* 
    SharedMemAlloc(
        mem_allocator_handle_t hMemAllocHandle,         ///< [in] handle of memory allocator for this allocation
        device_handle_t hDevice,                        ///< [in] handle of the device
        device_mem_alloc_flag_t device_flags,           ///< [in] flags specifying additional device allocation controls
        host_mem_alloc_flag_t host_flags,               ///< [in] flags specifying additional host allocation controls
        size_t size,                                    ///< [in] size in bytes to allocate
        size_t alignment                                ///< [in] minimum alignment in bytes for the allocation
        )
    {
        // auto result = ::xeSharedMemAlloc( handle, hDevice->getHandle(), device_flags, host_flags, size, alignment );
        // if( ::XE_RESULT_SUCCESS != result ) throw exception(result, "xe::SharedMemAlloc::SharedMemAlloc");
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief C++ wrapper for ::xeMemAlloc
    /// 
    /// @details
    ///     - A device allocation is owned by a specific device.
    ///     - In general, a device allocation may only be accessed by the device
    ///       that owns it.
    ///     - The application may call this function from simultaneous threads.
    ///     - The implementation of this function should be lock-free.
    /// 
    /// @remarks
    ///   _Analogues_
    ///     - **cudaMalloc**
    /// 
    /// @returns
    ///     - void*: pointer to device allocation
    /// 
    /// @throws result_t
    inline void* 
    MemAlloc(
        mem_allocator_handle_t hMemAllocHandle,         ///< [in] handle of memory allocator for this allocation
        device_handle_t hDevice,                        ///< [in] handle of the device
        device_mem_alloc_flag_t flags,                  ///< [in] flags specifying additional allocation controls
        size_t size,                                    ///< [in] size in bytes to allocate
        size_t alignment                                ///< [in] minimum alignment in bytes for the allocation
        )
    {
        // auto result = ::xeMemAlloc( handle, hDevice->getHandle(), flags, size, alignment );
        // if( ::XE_RESULT_SUCCESS != result ) throw exception(result, "xe::MemAlloc::MemAlloc");
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief C++ wrapper for ::xeHostMemAlloc
    /// 
    /// @details
    ///     - A host allocation is owned by the host process.
    ///     - Host allocations are accessible by the host and all devices.
    ///     - Host allocations are frequently used a staging areas to transfer data
    ///       to or from devices.
    ///     - The application may call this function from simultaneous threads.
    ///     - The implementation of this function should be lock-free.
    /// 
    /// @remarks
    ///   _Analogues_
    ///     - **cudaHostAlloc**
    /// 
    /// @returns
    ///     - void*: pointer to host allocation
    /// 
    /// @throws result_t
    inline void* 
    HostMemAlloc(
        mem_allocator_handle_t hMemAllocHandle,         ///< [in] handle of memory allocator for this allocation
        host_mem_alloc_flag_t flags,                    ///< [in] flags specifying additional allocation controls
        size_t size,                                    ///< [in] size in bytes to allocate
        size_t alignment                                ///< [in] minimum alignment in bytes for the allocation
        )
    {
        // auto result = ::xeHostMemAlloc( handle, flags, size, alignment );
        // if( ::XE_RESULT_SUCCESS != result ) throw exception(result, "xe::HostMemAlloc::HostMemAlloc");
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief C++ wrapper for ::xeMemFree
    /// 
    /// @details
    ///     - The application is responsible for making sure the GPU is not
    ///       currently referencing the memory before it is freed
    ///     - The implementation of this function will immediately free all Host and
    ///       Device allocations associated with this memory
    ///     - The implementation of this function should be lock-free.
    /// 
    /// @remarks
    ///   _Analogues_
    ///     - **cudaFree**
    ///     - **cudaFreeHost**
    /// 
    /// @throws result_t
    inline void 
    MemFree(
        mem_allocator_handle_t hMemAllocHandle,         ///< [in] handle of memory allocator for this allocation
        const void* ptr                                 ///< [in] pointer to memory to free
        )
    {
        // auto result = ::xeMemFree( handle, ptr );
        // if( ::XE_RESULT_SUCCESS != result ) throw exception(result, "xe::MemFree::MemFree");
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief C++ wrapper for ::xeMemGetProperty
    /// 
    /// @details
    ///     - The application may call this function from simultaneous threads.
    ///     - The implementation of this function should be lock-free.
    /// 
    /// @remarks
    ///   _Analogues_
    ///     - **cuPointerGetAttribute**
    /// 
    /// @returns
    ///     - uint32_t: Value of the queried property
    /// 
    /// @throws result_t
    inline uint32_t 
    MemGetProperty(
        mem_allocator_handle_t hMemAllocHandle,         ///< [in] handle of memory allocator for this allocation
        const void* ptr,                                ///< [in] Pointer to query
        memory_property_t property                      ///< [in] Property of the allocation to query
        )
    {
        // auto result = ::xeMemGetProperty( handle, ptr, property );
        // if( ::XE_RESULT_SUCCESS != result ) throw exception(result, "xe::MemGetProperty::MemGetProperty");
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief C++ wrapper for ::xeMemGetAddressRange
    /// 
    /// @details
    ///     - The application may call this function from simultaneous threads.
    ///     - The implementation of this function should be lock-free.
    /// 
    /// @remarks
    ///   _Analogues_
    ///     - **cuMemGetAddressRange**
    /// 
    /// @throws result_t
    inline void 
    MemGetAddressRange(
        mem_allocator_handle_t hMemAllocHandle,         ///< [in] handle of memory allocator for this allocation
        const void* ptr,                                ///< [in] Pointer to query
        void** pBase,                                   ///< [in,out][optional] base address of the allocation
        size_t* pSize                                   ///< [in,out][optional] size of the allocation
        )
    {
        // auto result = ::xeMemGetAddressRange( handle, ptr, pBase, pSize );
        // if( ::XE_RESULT_SUCCESS != result ) throw exception(result, "xe::MemGetAddressRange::MemGetAddressRange");
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief C++ wrapper for ::xeIpcGetMemHandle
    /// 
    /// @details
    ///     - Takes a pointer to the base of a device memory allocation and exports
    ///       it for use in another process.
    ///     - The application may call this function from simultaneous threads.
    ///     - The implementation of this function should be lock-free.
    /// 
    /// @remarks
    ///   _Analogues_
    ///     - **cuIpcGetMemHandle**
    /// 
    /// @returns
    ///     - ipc_mem_handle_t: Returned IPC memory handle
    /// 
    /// @throws result_t
    inline ipc_mem_handle_t 
    IpcGetMemHandle(
        mem_allocator_handle_t hMemAllocHandle,         ///< [in] handle of memory allocator for this allocation
        const void* ptr                                 ///< [in] Pointer to the device memory allocation
        )
    {
        // auto result = ::xeIpcGetMemHandle( handle, ptr );
        // if( ::XE_RESULT_SUCCESS != result ) throw exception(result, "xe::IpcGetMemHandle::IpcGetMemHandle");
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief C++ wrapper for ::xeIpcOpenMemHandle
    /// 
    /// @details
    ///     - Takes an IPC memory handle from a sending process and associates it
    ///       with a device pointer usable in this process.
    ///     - The device pointer in this process should not be freed with ::MemFree,
    ///       but rather with ::IpcCloseMemHandle.
    ///     - The application may call this function from simultaneous threads.
    ///     - The implementation of this function should be lock-free.
    /// 
    /// @remarks
    ///   _Analogues_
    ///     - **cuIpcOpenMemHandle**
    /// 
    /// @returns
    ///     - void*: pointer to device allocation in this process
    /// 
    /// @throws result_t
    inline void* 
    IpcOpenMemHandle(
        mem_allocator_handle_t hMemAllocHandle,         ///< [in] handle of memory allocator for this allocation
        device_handle_t hDevice,                        ///< [in] handle of the device to associate with the IPC memory handle
        ipc_mem_handle_t handle,                        ///< [in] IPC memory handle
        ipc_memory_flag_t flags                         ///< [in] flags controlling the operation
        )
    {
        // auto result = ::xeIpcOpenMemHandle( handle, hDevice->getHandle(), handle->getHandle(), flags );
        // if( ::XE_RESULT_SUCCESS != result ) throw exception(result, "xe::IpcOpenMemHandle::IpcOpenMemHandle");
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief C++ wrapper for ::xeIpcCloseMemHandle
    /// 
    /// @details
    ///     - Closes an IPC memory handle by unmapping memory that was opened in
    ///       this process using ::IpcOpenMemHandle.
    ///     - The application may call this function from simultaneous threads.
    ///     - The implementation of this function should be lock-free.
    /// 
    /// @remarks
    ///   _Analogues_
    ///     - **cuIpcCloseMemHandle**
    /// 
    /// @throws result_t
    inline void 
    IpcCloseMemHandle(
        mem_allocator_handle_t hMemAllocHandle,         ///< [in] handle of memory allocator for this allocation
        const void* ptr                                 ///< [in] pointer to device allocation in this process
        )
    {
        // auto result = ::xeIpcCloseMemHandle( handle, ptr );
        // if( ::XE_RESULT_SUCCESS != result ) throw exception(result, "xe::IpcCloseMemHandle::IpcCloseMemHandle");
    }

} // namespace xe
#endif // defined(__cplusplus)
#endif // _XE_MEMORY_INL
