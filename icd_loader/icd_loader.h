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
* @file icd_loader.h
*
* @cond DEV
* DO NOT EDIT: generated from /scripts/templates/icd_loader.h.mako
* @endcond
*
******************************************************************************/
#ifndef _XE_LOADER_H
#define _XE_LOADER_H
#if defined(__cplusplus)
#pragma once
#endif
#include "xe_all.h"

typedef struct _cl_mem* cl_mem;
typedef struct _cl_command_queue* cl_command_queue;
typedef struct _cl_context* cl_context;
typedef struct _cl_program* cl_program;

typedef xe_result_t (__xecall *pfn_xeCommandListAppendMemoryRangesBarrier)(
    xe_command_list_handle_t hCommandList,          ///< [in] handle of the command list
    uint32_t numRanges,                             ///< [in] number of memory ranges
    const size_t* pRangeSizes,                      ///< [in] array of sizes of memory range
    const void** pRanges,                           ///< [in] array of memory ranges
    xe_event_handle_t hSignalEvent,                 ///< [in][optional] handle of the event to signal on completion
    uint32_t numWaitEvents,                         ///< [in][optional] number of events to wait on before barrier
    xe_event_handle_t* phWaitEvents                 ///< [in][optional] handle of the events to wait on before barrier
    );
typedef xe_result_t (__xecall *pfn_xeDeviceSystemBarrier)(
    xe_device_handle_t hDevice                      ///< [in] handle of the device
    );
#if XE_ENABLE_OCL_INTEROP
typedef xe_result_t (__xecall *pfn_xeDeviceRegisterCLMemory)(
    xe_device_handle_t hDevice,                     ///< [in] handle to the device
    cl_context context,                             ///< [in] the OpenCL context that created the memory
    cl_mem mem,                                     ///< [in] the OpenCL memory to register
    void** ptr                                      ///< [out] pointer to device allocation
    );
#endif // XE_ENABLE_OCL_INTEROP
#if XE_ENABLE_OCL_INTEROP
typedef xe_result_t (__xecall *pfn_xeDeviceRegisterCLProgram)(
    xe_device_handle_t hDevice,                     ///< [in] handle to the device
    cl_context context,                             ///< [in] the OpenCL context that created the program
    cl_program program,                             ///< [in] the OpenCL program to register
    xe_module_handle_t* phModule                    ///< [out] pointer to handle of module object created
    );
#endif // XE_ENABLE_OCL_INTEROP
#if XE_ENABLE_OCL_INTEROP
typedef xe_result_t (__xecall *pfn_xeDeviceRegisterCLCommandQueue)(
    xe_device_handle_t hDevice,                     ///< [in] handle to the device
    cl_context context,                             ///< [in] the OpenCL context that created the command queue
    cl_command_queue command_queue,                 ///< [in] the OpenCL command queue to register
    xe_command_queue_handle_t* phCommandQueue       ///< [out] pointer to handle of command queue object created
    );
#endif // XE_ENABLE_OCL_INTEROP
typedef xe_result_t (__xecall *pfn_xeCommandListCreate)(
    xe_device_handle_t hDevice,                     ///< [in] handle of the device object
    const xe_command_list_desc_t* desc,             ///< [in] pointer to command list descriptor
    xe_command_list_handle_t* phCommandList         ///< [out] pointer to handle of command list object created
    );
typedef xe_result_t (__xecall *pfn_xeCommandListDestroy)(
    xe_command_list_handle_t hCommandList           ///< [in] handle of command list object to destroy
    );
typedef xe_result_t (__xecall *pfn_xeCommandListClose)(
    xe_command_list_handle_t hCommandList           ///< [in] handle of command list object to close
    );
typedef xe_result_t (__xecall *pfn_xeCommandListReset)(
    xe_command_list_handle_t hCommandList           ///< [in] handle of command list object to reset
    );
typedef xe_result_t (__xecall *pfn_xeCommandListSetParameter)(
    xe_command_list_handle_t hCommandList,          ///< [in] handle of command list
    xe_command_list_parameter_t parameter,          ///< [in] parameter to change
    uint32_t value                                  ///< [in] value of attribute
    );
typedef xe_result_t (__xecall *pfn_xeCommandListGetParameter)(
    xe_command_list_handle_t hCommandList,          ///< [in] handle of command list
    xe_command_list_parameter_t parameter,          ///< [in] parameter to retrieve
    uint32_t* value                                 ///< [out] value of attribute
    );
typedef xe_result_t (__xecall *pfn_xeCommandListResetParameters)(
    xe_command_list_handle_t hCommandList           ///< [in] handle of the command list
    );
typedef xe_result_t (__xecall *pfn_xeCommandListReserveSpace)(
    xe_command_list_handle_t hCommandList,          ///< [in] handle of the command list
    size_t size,                                    ///< [in] size (in bytes) to reserve
    void** ptr                                      ///< [out] pointer to command buffer space reserved
    );
typedef xe_result_t (__xecall *pfn_xeCommandQueueCreate)(
    xe_device_handle_t hDevice,                     ///< [in] handle of the device object
    const xe_command_queue_desc_t* desc,            ///< [in] pointer to command queue descriptor
    xe_command_queue_handle_t* phCommandQueue       ///< [out] pointer to handle of command queue object created
    );
typedef xe_result_t (__xecall *pfn_xeCommandQueueDestroy)(
    xe_command_queue_handle_t hCommandQueue         ///< [in] handle of command queue object to destroy
    );
typedef xe_result_t (__xecall *pfn_xeCommandQueueExecuteCommandLists)(
    xe_command_queue_handle_t hCommandQueue,        ///< [in] handle of the command queue
    uint32_t numCommandLists,                       ///< [in] number of command lists to execute
    xe_command_list_handle_t* phCommandLists,       ///< [in] list of handles of the command lists to execute
    xe_fence_handle_t hFence                        ///< [in][optional] handle of the fence to signal on completion
    );
typedef xe_result_t (__xecall *pfn_xeCommandQueueSynchronize)(
    xe_command_queue_handle_t hCommandQueue,        ///< [in] handle of the command queue
    uint32_t timeout                                ///< [in] if non-zero, then indicates the maximum time to yield before
                                                    ///< returning ::XE_RESULT_SUCCESS or ::XE_RESULT_NOT_READY;
                                                    ///< if zero, then operates exactly like ::xeFenceQueryStatus;
                                                    ///< if MAX_UINT32, then function will not return until complete or device
                                                    ///< is lost.
    );
typedef xe_result_t (__xecall *pfn_xeCommandQueueOpenCommandList)(
    xe_command_queue_handle_t hCommandQueue,        ///< [in] handle of the command queue
    xe_command_list_handle_t* phCommandList         ///< [out] pointer to handle of command list object created
    );
typedef xe_result_t (__xecall *pfn_xeCommandListAppendMemoryCopy)(
    xe_command_list_handle_t hCommandList,          ///< [in] handle of command list
    void* dstptr,                                   ///< [in] pointer to destination memory to copy to
    const void* srcptr,                             ///< [in] pointer to source memory to copy from
    size_t size,                                    ///< [in] size in bytes to copy
    xe_event_handle_t hSignalEvent,                 ///< [in][optional] handle of the event to signal on completion
    uint32_t numWaitEvents,                         ///< [in][optional] number of events to wait on before launching
    xe_event_handle_t* phWaitEvents                 ///< [in][optional] handle of the events to wait on before launching
    );
typedef xe_result_t (__xecall *pfn_xeCommandListAppendMemorySet)(
    xe_command_list_handle_t hCommandList,          ///< [in] handle of command list
    void* ptr,                                      ///< [in] pointer to memory to initialize
    int value,                                      ///< [in] value to initialize memory to
    size_t size,                                    ///< [in] size in bytes to initailize
    xe_event_handle_t hSignalEvent,                 ///< [in][optional] handle of the event to signal on completion
    uint32_t numWaitEvents,                         ///< [in][optional] number of events to wait on before launching
    xe_event_handle_t* phWaitEvents                 ///< [in][optional] handle of the events to wait on before launching
    );
typedef xe_result_t (__xecall *pfn_xeCommandListAppendImageCopy)(
    xe_command_list_handle_t hCommandList,          ///< [in] handle of command list
    xe_image_handle_t hDstImage,                    ///< [in] handle of destination image to copy to
    xe_image_handle_t hSrcImage,                    ///< [in] handle of source image to copy from
    xe_event_handle_t hSignalEvent,                 ///< [in][optional] handle of the event to signal on completion
    uint32_t numWaitEvents,                         ///< [in][optional] number of events to wait on before launching
    xe_event_handle_t* phWaitEvents                 ///< [in][optional] handle of the events to wait on before launching
    );
typedef xe_result_t (__xecall *pfn_xeCommandListAppendImageCopyRegion)(
    xe_command_list_handle_t hCommandList,          ///< [in] handle of command list
    xe_image_handle_t hDstImage,                    ///< [in] handle of destination image to copy to
    xe_image_handle_t hSrcImage,                    ///< [in] handle of source image to copy from
    xe_image_region_t* pDstRegion,                  ///< [in][optional] destination region descriptor
    xe_image_region_t* pSrcRegion,                  ///< [in][optional] source region descriptor
    xe_event_handle_t hSignalEvent,                 ///< [in][optional] handle of the event to signal on completion
    uint32_t numWaitEvents,                         ///< [in][optional] number of events to wait on before launching
    xe_event_handle_t* phWaitEvents                 ///< [in][optional] handle of the events to wait on before launching
    );
typedef xe_result_t (__xecall *pfn_xeCommandListAppendImageCopyToMemory)(
    xe_command_list_handle_t hCommandList,          ///< [in] handle of command list
    void* dstptr,                                   ///< [in] pointer to destination memory to copy to
    xe_image_handle_t hSrcImage,                    ///< [in] handle of source image to copy from
    xe_image_region_t* pSrcRegion,                  ///< [in][optional] source region descriptor
    xe_event_handle_t hSignalEvent,                 ///< [in][optional] handle of the event to signal on completion
    uint32_t numWaitEvents,                         ///< [in][optional] number of events to wait on before launching
    xe_event_handle_t* phWaitEvents                 ///< [in][optional] handle of the events to wait on before launching
    );
typedef xe_result_t (__xecall *pfn_xeCommandListAppendImageCopyFromMemory)(
    xe_command_list_handle_t hCommandList,          ///< [in] handle of command list
    xe_image_handle_t hDstImage,                    ///< [in] handle of destination image to copy to
    const void* srcptr,                             ///< [in] pointer to source memory to copy from
    xe_image_region_t* pDstRegion,                  ///< [in][optional] destination region descriptor
    xe_event_handle_t hSignalEvent,                 ///< [in][optional] handle of the event to signal on completion
    uint32_t numWaitEvents,                         ///< [in][optional] number of events to wait on before launching
    xe_event_handle_t* phWaitEvents                 ///< [in][optional] handle of the events to wait on before launching
    );
typedef xe_result_t (__xecall *pfn_xeCommandListAppendMemoryPrefetch)(
    xe_command_list_handle_t hCommandList,          ///< [in] handle of command list
    const void* ptr,                                ///< [in] pointer to start of the memory range to prefetch
    size_t count                                    ///< [in] size in bytes of the memory range to prefetch
    );
typedef xe_result_t (__xecall *pfn_xeCommandListAppendMemAdvise)(
    xe_command_list_handle_t hCommandList,          ///< [in] handle of command list
    xe_device_handle_t hDevice,                     ///< [in] device associated with the memory advice
    const void* ptr,                                ///< [in] Pointer to the start of the memory range
    size_t size,                                    ///< [in] Size in bytes of the memory range
    xe_memory_advice_t advice                       ///< [in] Memory advice for the memory range
    );
typedef xe_result_t (__xecall *pfn_xeDeviceGetCount)(
    uint32_t* count                                 ///< [out] number of devices available
    );
typedef xe_result_t (__xecall *pfn_xeDeviceGet)(
    uint32_t ordinal,                               ///< [in] The device index in the range of [0, ::xeGetDeviceCount]
    xe_device_handle_t* phDevice                    ///< [out] pointer to handle of device object created
    );
typedef xe_result_t (__xecall *pfn_xeDeviceGetSubDevice)(
    xe_device_handle_t hDevice,                     ///< [in] handle of the device object
    uint32_t ordinal,                               ///< [in] ordinal of sub-device to retrieve
    xe_device_handle_t* phSubDevice                 ///< [out] pointer to handle of sub-device object.
    );
typedef xe_result_t (__xecall *pfn_xeDeviceGetApiVersion)(
    xe_device_handle_t hDevice,                     ///< [in] handle of the device object
    xe_api_version_t* version                       ///< [out] api version
    );
typedef xe_result_t (__xecall *pfn_xeDeviceGetProperties)(
    xe_device_handle_t hDevice,                     ///< [in] handle of the device object
    xe_device_properties_t* pDeviceProperties       ///< [out] query result for device properties
    );
typedef xe_result_t (__xecall *pfn_xeDeviceGetComputeProperties)(
    xe_device_handle_t hDevice,                     ///< [in] handle of the device object
    xe_device_compute_properties_t* pComputeProperties  ///< [out] query result for compute properties
    );
typedef xe_result_t (__xecall *pfn_xeDeviceGetMemoryProperties)(
    xe_device_handle_t hDevice,                     ///< [in] handle of the device object
    xe_device_memory_properties_t* pMemProperties   ///< [out] query result for compute properties
    );
typedef xe_result_t (__xecall *pfn_xeDeviceGetP2PProperties)(
    xe_device_handle_t hDevice,                     ///< [in] handle of the device performing the access
    xe_device_handle_t hPeerDevice,                 ///< [in] handle of the peer device with the allocation
    xe_device_p2p_properties_t* pP2PProperties      ///< [out] Peer-to-Peer properties between source and peer device
    );
typedef xe_result_t (__xecall *pfn_xeDeviceCanAccessPeer)(
    xe_device_handle_t hDevice,                     ///< [in] handle of the device performing the access
    xe_device_handle_t hPeerDevice,                 ///< [in] handle of the peer device with the allocation
    xe_bool_t* value                                ///< [out] returned access capability
    );
typedef xe_result_t (__xecall *pfn_xeDeviceSetIntermediateCacheConfig)(
    xe_device_handle_t hDevice,                     ///< [in] handle of the device 
    xe_cache_config_t CacheConfig                   ///< [in] CacheConfig
    );
typedef xe_result_t (__xecall *pfn_xeDeviceSetLastLevelCacheConfig)(
    xe_device_handle_t hDevice,                     ///< [in] handle of the device 
    xe_cache_config_t CacheConfig                   ///< [in] CacheConfig
    );
typedef xe_result_t (__xecall *pfn_xeInit)(
    xe_init_flag_t flags                            ///< [in] initialization flags
    );
typedef xe_result_t (__xecall *pfn_xeGetDriverVersion)(
    uint32_t* version                               ///< [out] driver version
    );
typedef xe_result_t (__xecall *pfn_xeEventPoolCreate)(
    xe_device_handle_t hDevice,                     ///< [in] handle of the device
    const xe_event_pool_desc_t* desc,               ///< [in] pointer to event pool descriptor
    xe_event_pool_handle_t* phEventPool             ///< [out] pointer handle of event pool object created
    );
typedef xe_result_t (__xecall *pfn_xeEventPoolDestroy)(
    xe_event_pool_handle_t hEventPool               ///< [in] handle of event pool object to destroy
    );
typedef xe_result_t (__xecall *pfn_xeEventCreate)(
    xe_event_pool_handle_t hEventPool,              ///< [in] handle of the event pool
    const xe_event_desc_t* desc,                    ///< [in] pointer to event descriptor
    xe_event_handle_t* phEvent                      ///< [out] pointer to handle of event object created
    );
typedef xe_result_t (__xecall *pfn_xeEventDestroy)(
    xe_event_handle_t hEvent                        ///< [in] handle of event object to destroy
    );
typedef xe_result_t (__xecall *pfn_xeEventPoolGetIpcHandle)(
    xe_event_pool_handle_t hEventPool,              ///< [in] handle of event pool object
    xe_ipc_event_pool_handle_t* phIpc               ///< [out] Returned IPC event handle
    );
typedef xe_result_t (__xecall *pfn_xeEventPoolOpenIpcHandle)(
    xe_device_handle_t hDevice,                     ///< [in] handle of the device to associate with the IPC event pool handle
    xe_ipc_event_pool_handle_t hIpc,                ///< [in] IPC event handle
    xe_event_pool_handle_t* phEventPool             ///< [out] pointer handle of event pool object created
    );
typedef xe_result_t (__xecall *pfn_xeEventPoolCloseIpcHandle)(
    xe_event_pool_handle_t hEventPool               ///< [in] handle of event pool object
    );
typedef xe_result_t (__xecall *pfn_xeCommandListAppendSignalEvent)(
    xe_command_list_handle_t hCommandList,          ///< [in] handle of the command list
    xe_event_handle_t hEvent                        ///< [in] handle of the event
    );
typedef xe_result_t (__xecall *pfn_xeCommandListAppendWaitOnEvent)(
    xe_command_list_handle_t hCommandList,          ///< [in] handle of the command list
    xe_event_handle_t hEvent                        ///< [in] handle of the event
    );
typedef xe_result_t (__xecall *pfn_xeEventHostSignal)(
    xe_event_handle_t hEvent                        ///< [in] handle of the event
    );
typedef xe_result_t (__xecall *pfn_xeEventHostSynchronize)(
    xe_event_handle_t hEvent,                       ///< [in] handle of the event
    uint32_t timeout                                ///< [in] if non-zero, then indicates the maximum time to yield before
                                                    ///< returning ::XE_RESULT_SUCCESS or ::XE_RESULT_NOT_READY;
                                                    ///< if zero, then operates exactly like ::xeEventQueryStatus;
                                                    ///< if MAX_UINT32, then function will not return until complete or device
                                                    ///< is lost.
    );
typedef xe_result_t (__xecall *pfn_xeEventQueryStatus)(
    xe_event_handle_t hEvent                        ///< [in] handle of the event
    );
typedef xe_result_t (__xecall *pfn_xeCommandListAppendEventReset)(
    xe_command_list_handle_t hCommandList,          ///< [in] handle of the command list
    xe_event_handle_t hEvent                        ///< [in] handle of the event
    );
typedef xe_result_t (__xecall *pfn_xeEventReset)(
    xe_event_handle_t hEvent                        ///< [in] handle of the event
    );
typedef xe_result_t (__xecall *pfn_xeFenceCreate)(
    xe_command_queue_handle_t hCommandQueue,        ///< [in] handle of command queue
    const xe_fence_desc_t* desc,                    ///< [in] pointer to fence descriptor
    xe_fence_handle_t* phFence                      ///< [out] pointer to handle of fence object created
    );
typedef xe_result_t (__xecall *pfn_xeFenceDestroy)(
    xe_fence_handle_t hFence                        ///< [in] handle of fence object to destroy
    );
typedef xe_result_t (__xecall *pfn_xeFenceHostSynchronize)(
    xe_fence_handle_t hFence,                       ///< [in] handle of the fence
    uint32_t timeout                                ///< [in] if non-zero, then indicates the maximum time to yield before
                                                    ///< returning ::XE_RESULT_SUCCESS or ::XE_RESULT_NOT_READY;
                                                    ///< if zero, then operates exactly like ::xeFenceQueryStatus;
                                                    ///< if MAX_UINT32, then function will not return until complete or device
                                                    ///< is lost.
    );
typedef xe_result_t (__xecall *pfn_xeFenceQueryStatus)(
    xe_fence_handle_t hFence                        ///< [in] handle of the fence
    );
typedef xe_result_t (__xecall *pfn_xeFenceReset)(
    xe_fence_handle_t hFence                        ///< [in] handle of the fence
    );
typedef xe_result_t (__xecall *pfn_xeImageGetProperties)(
    xe_device_handle_t hDevice,                     ///< [in] handle of the device
    const xe_image_desc_t* desc,                    ///< [in] pointer to image descriptor
    xe_image_properties_t* pImageProperties         ///< [out] pointer to image properties
    );
typedef xe_result_t (__xecall *pfn_xeImageCreate)(
    xe_device_handle_t hDevice,                     ///< [in] handle of the device
    const xe_image_desc_t* desc,                    ///< [in] pointer to image descriptor
    xe_image_handle_t* phImage                      ///< [out] pointer to handle of image object created
    );
typedef xe_result_t (__xecall *pfn_xeImageDestroy)(
    xe_image_handle_t hImage                        ///< [in] handle of image object to destroy
    );
typedef xe_result_t (__xecall *pfn_xeSharedMemAlloc)(
    xe_device_handle_t hDevice,                     ///< [in] handle of the device
    xe_device_mem_alloc_flag_t device_flags,        ///< [in] flags specifying additional device allocation controls
    xe_host_mem_alloc_flag_t host_flags,            ///< [in] flags specifying additional host allocation controls
    size_t size,                                    ///< [in] size in bytes to allocate
    size_t alignment,                               ///< [in] minimum alignment in bytes for the allocation
    void** ptr                                      ///< [out] pointer to shared allocation
    );
typedef xe_result_t (__xecall *pfn_xeMemAlloc)(
    xe_device_handle_t hDevice,                     ///< [in] handle of the device
    xe_device_mem_alloc_flag_t flags,               ///< [in] flags specifying additional allocation controls
    size_t size,                                    ///< [in] size in bytes to allocate
    size_t alignment,                               ///< [in] minimum alignment in bytes for the allocation
    void** ptr                                      ///< [out] pointer to device allocation
    );
typedef xe_result_t (__xecall *pfn_xeHostMemAlloc)(
    xe_host_mem_alloc_flag_t flags,                 ///< [in] flags specifying additional allocation controls
    size_t size,                                    ///< [in] size in bytes to allocate
    size_t alignment,                               ///< [in] minimum alignment in bytes for the allocation
    void** ptr                                      ///< [out] pointer to host allocation
    );
typedef xe_result_t (__xecall *pfn_xeMemFree)(
    const void* ptr                                 ///< [in] pointer to memory to free
    );
typedef xe_result_t (__xecall *pfn_xeMemGetProperties)(
    const void* ptr,                                ///< [in] Pointer to query
    xe_memory_allocation_properties_t* pMemProperties   ///< [out] Query result for memory allocation properties
    );
typedef xe_result_t (__xecall *pfn_xeMemGetAddressRange)(
    const void* ptr,                                ///< [in] Pointer to query
    void** pBase,                                   ///< [in,out][optional] base address of the allocation
    size_t* pSize                                   ///< [in,out][optional] size of the allocation
    );
typedef xe_result_t (__xecall *pfn_xeIpcGetMemHandle)(
    const void* ptr,                                ///< [in] Pointer to the device memory allocation
    xe_ipc_mem_handle_t* pIpcHandle                 ///< [out] Returned IPC memory handle
    );
typedef xe_result_t (__xecall *pfn_xeIpcOpenMemHandle)(
    xe_device_handle_t hDevice,                     ///< [in] handle of the device to associate with the IPC memory handle
    xe_ipc_mem_handle_t handle,                     ///< [in] IPC memory handle
    xe_ipc_memory_flag_t flags,                     ///< [in] flags controlling the operation
    void** ptr                                      ///< [out] pointer to device allocation in this process
    );
typedef xe_result_t (__xecall *pfn_xeIpcCloseMemHandle)(
    const void* ptr                                 ///< [in] pointer to device allocation in this process
    );
typedef xe_result_t (__xecall *pfn_xeModuleCreate)(
    xe_device_handle_t hDevice,                     ///< [in] handle of the device
    const xe_module_desc_t* pDesc,                  ///< [in] pointer to module descriptor
    xe_module_handle_t* phModule,                   ///< [out] pointer to handle of module object created
    xe_module_build_log_handle_t* phBuildLog        ///< [in,out][optional] pointer to handle of module's build log.
    );
typedef xe_result_t (__xecall *pfn_xeModuleDestroy)(
    xe_module_handle_t hModule                      ///< [in] handle of the module
    );
typedef xe_result_t (__xecall *pfn_xeModuleBuildLogDestroy)(
    xe_module_build_log_handle_t hModuleBuildLog    ///< [in] handle of the module build log object.
    );
typedef xe_result_t (__xecall *pfn_xeModuleBuildLogGetString)(
    xe_module_build_log_handle_t hModuleBuildLog,   ///< [in] handle of the module build log object.
    size_t* pSize,                                  ///< [in,out] size of build log string.
    char* pBuildLog                                 ///< [in,out][optional] pointer to null-terminated string of the log.
    );
typedef xe_result_t (__xecall *pfn_xeModuleGetNativeBinary)(
    xe_module_handle_t hModule,                     ///< [in] handle of the device
    size_t* pSize,                                  ///< [in,out] size of native binary in bytes.
    uint8_t* pModuleNativeBinary                    ///< [in,out][optional] byte pointer to native binary
    );
typedef xe_result_t (__xecall *pfn_xeModuleGetGlobalPointer)(
    xe_module_handle_t hModule,                     ///< [in] handle of the device
    const char* pGlobalName,                        ///< [in] name of function in global
    void** pPtr                                     ///< [out] device visible pointer
    );
typedef xe_result_t (__xecall *pfn_xeFunctionCreate)(
    xe_module_handle_t hModule,                     ///< [in] handle of the module
    const xe_function_desc_t* pDesc,                ///< [in] pointer to function descriptor
    xe_function_handle_t* phFunction                ///< [out] handle of the Function object
    );
typedef xe_result_t (__xecall *pfn_xeFunctionDestroy)(
    xe_function_handle_t hFunction                  ///< [in] handle of the function object
    );
typedef xe_result_t (__xecall *pfn_xeModuleGetFunctionPointer)(
    xe_module_handle_t hModule,                     ///< [in] handle of the module
    const char* pFunctionName,                      ///< [in] Name of function to retrieve function pointer for.
    void** pfnFunction                              ///< [out] pointer to function.
    );
typedef xe_result_t (__xecall *pfn_xeFunctionSetGroupSize)(
    xe_function_handle_t hFunction,                 ///< [in] handle of the function object
    uint32_t groupSizeX,                            ///< [in] group size for X dimension to use for this function.
    uint32_t groupSizeY,                            ///< [in] group size for Y dimension to use for this function.
    uint32_t groupSizeZ                             ///< [in] group size for Z dimension to use for this function.
    );
typedef xe_result_t (__xecall *pfn_xeFunctionSuggestGroupSize)(
    xe_function_handle_t hFunction,                 ///< [in] handle of the function object
    uint32_t globalSizeX,                           ///< [in] global width for X dimension.
    uint32_t globalSizeY,                           ///< [in] global width for Y dimension.
    uint32_t globalSizeZ,                           ///< [in] global width for Z dimension.
    uint32_t* groupSizeX,                           ///< [out] recommended size of group for X dimension.
    uint32_t* groupSizeY,                           ///< [out] recommended size of group for Y dimension.
    uint32_t* groupSizeZ                            ///< [out] recommended size of group for Z dimension.
    );
typedef xe_result_t (__xecall *pfn_xeFunctionSetArgumentValue)(
    xe_function_handle_t hFunction,                 ///< [in,out] handle of the function args object.
    uint32_t argIndex,                              ///< [in] argument index in range [0, num args - 1]
    size_t argSize,                                 ///< [in] size of argument type
    const void* pArgValue                           ///< [in][optional] argument value represented as matching arg type. If
                                                    ///< null then argument value is considered null.
    );
typedef xe_result_t (__xecall *pfn_xeFunctionSetAttribute)(
    xe_function_handle_t hFunction,                 ///< [in,out] handle of the function.
    xe_function_set_attribute_t attr,               ///< [in] attribute to set
    uint32_t value                                  ///< [in] attribute value to set
    );
typedef xe_result_t (__xecall *pfn_xeFunctionGetAttribute)(
    xe_function_handle_t hFunction,                 ///< [in] handle of the function object
    xe_function_get_attribute_t attr,               ///< [in] attribute to query
    uint32_t* pValue                                ///< [out] returned attribute value
    );
typedef xe_result_t (__xecall *pfn_xeCommandListAppendLaunchFunction)(
    xe_command_list_handle_t hCommandList,          ///< [in] handle of the command list
    xe_function_handle_t hFunction,                 ///< [in] handle of the function object
    const xe_thread_group_dimensions_t* pLaunchFuncArgs,///< [in] launch function arguments.
    xe_event_handle_t hSignalEvent,                 ///< [in][optional] handle of the event to signal on completion
    uint32_t numWaitEvents,                         ///< [in][optional] number of events to wait on before launching
    xe_event_handle_t* phWaitEvents                 ///< [in][optional] handle of the events to wait on before launching
    );
typedef xe_result_t (__xecall *pfn_xeCommandListAppendLaunchFunctionIndirect)(
    xe_command_list_handle_t hCommandList,          ///< [in] handle of the command list
    xe_function_handle_t hFunction,                 ///< [in] handle of the function object
    const xe_thread_group_dimensions_t* pLaunchArgumentsBuffer, ///< [in] pointer to device buffer that will contain launch arguments
    xe_event_handle_t hSignalEvent,                 ///< [in][optional] handle of the event to signal on completion
    uint32_t numWaitEvents,                         ///< [in][optional] number of events to wait on before launching
    xe_event_handle_t* phWaitEvents                 ///< [in][optional] handle of the events to wait on before launching
    );
typedef xe_result_t (__xecall *pfn_xeCommandListAppendLaunchMultipleFunctionsIndirect)(
    xe_command_list_handle_t hCommandList,          ///< [in] handle of the command list
    uint32_t numFunctions,                          ///< [in] maximum number of functions to launch
    const xe_function_handle_t* phFunctions,        ///< [in] handles of the function objects
    const size_t* pNumLaunchArguments,              ///< [in] pointer to device memory location that will contain the actual
                                                    ///< number of launch arguments; must be less-than or equal-to numFunctions
    const xe_thread_group_dimensions_t* pLaunchArgumentsBuffer, ///< [in] pointer to device buffer that will contain a contiguous array of
                                                    ///< launch arguments
    xe_event_handle_t hSignalEvent,                 ///< [in][optional] handle of the event to signal on completion
    uint32_t numWaitEvents,                         ///< [in][optional] number of events to wait on before launching
    xe_event_handle_t* phWaitEvents                 ///< [in][optional] handle of the events to wait on before launching
    );
typedef xe_result_t (__xecall *pfn_xeCommandListAppendLaunchHostFunction)(
    xe_command_list_handle_t hCommandList,          ///< [in] handle of the command list
    xe_host_pfn_t pfnHostFunc,                      ///< [in] pointer to host function.
    void* pUserData                                 ///< [in] pointer to user data to pass to host function.
    );
typedef xe_result_t (__xecall *pfn_xeDeviceMakeMemoryResident)(
    xe_device_handle_t hDevice,                     ///< [in] handle of the device
    void* ptr,                                      ///< [in] pointer to memory to make resident
    size_t size                                     ///< [in] size in bytes to make resident
    );
typedef xe_result_t (__xecall *pfn_xeDeviceEvictMemory)(
    xe_device_handle_t hDevice,                     ///< [in] handle of the device
    void* ptr,                                      ///< [in] pointer to memory to evict
    size_t size                                     ///< [in] size in bytes to evict
    );
typedef xe_result_t (__xecall *pfn_xeDeviceMakeImageResident)(
    xe_device_handle_t hDevice,                     ///< [in] handle of the device
    xe_image_handle_t hImage                        ///< [in] handle of image to make resident
    );
typedef xe_result_t (__xecall *pfn_xeDeviceEvictImage)(
    xe_device_handle_t hDevice,                     ///< [in] handle of the device
    xe_image_handle_t hImage                        ///< [in] handle of image to make evict
    );
typedef xe_result_t (__xecall *pfn_xeSamplerCreate)(
    xe_device_handle_t hDevice,                     ///< [in] handle of the device
    const xe_sampler_desc_t* pDesc,                 ///< [in] pointer to sampler descriptor
    xe_sampler_handle_t* phSampler                  ///< [out] handle of the sampler
    );
typedef xe_result_t (__xecall *pfn_xeSamplerDestroy)(
    xe_sampler_handle_t hSampler                    ///< [in] handle of the sampler
    );

typedef struct _xe_dispatch_table_t
{
    pfn_xeCommandListAppendMemoryRangesBarrier xeCommandListAppendMemoryRangesBarrier;
    pfn_xeDeviceSystemBarrier xeDeviceSystemBarrier;
#if XE_ENABLE_OCL_INTEROP
    pfn_xeDeviceRegisterCLMemory xeDeviceRegisterCLMemory;
#endif // XE_ENABLE_OCL_INTEROP
#if XE_ENABLE_OCL_INTEROP
    pfn_xeDeviceRegisterCLProgram xeDeviceRegisterCLProgram;
#endif // XE_ENABLE_OCL_INTEROP
#if XE_ENABLE_OCL_INTEROP
    pfn_xeDeviceRegisterCLCommandQueue xeDeviceRegisterCLCommandQueue;
#endif // XE_ENABLE_OCL_INTEROP
    pfn_xeCommandListCreate xeCommandListCreate;
    pfn_xeCommandListDestroy xeCommandListDestroy;
    pfn_xeCommandListClose xeCommandListClose;
    pfn_xeCommandListReset xeCommandListReset;
    pfn_xeCommandListSetParameter xeCommandListSetParameter;
    pfn_xeCommandListGetParameter xeCommandListGetParameter;
    pfn_xeCommandListResetParameters xeCommandListResetParameters;
    pfn_xeCommandListReserveSpace xeCommandListReserveSpace;
    pfn_xeCommandQueueCreate xeCommandQueueCreate;
    pfn_xeCommandQueueDestroy xeCommandQueueDestroy;
    pfn_xeCommandQueueExecuteCommandLists xeCommandQueueExecuteCommandLists;
    pfn_xeCommandQueueSynchronize xeCommandQueueSynchronize;
    pfn_xeCommandQueueOpenCommandList xeCommandQueueOpenCommandList;
    pfn_xeCommandListAppendMemoryCopy xeCommandListAppendMemoryCopy;
    pfn_xeCommandListAppendMemorySet xeCommandListAppendMemorySet;
    pfn_xeCommandListAppendImageCopy xeCommandListAppendImageCopy;
    pfn_xeCommandListAppendImageCopyRegion xeCommandListAppendImageCopyRegion;
    pfn_xeCommandListAppendImageCopyToMemory xeCommandListAppendImageCopyToMemory;
    pfn_xeCommandListAppendImageCopyFromMemory xeCommandListAppendImageCopyFromMemory;
    pfn_xeCommandListAppendMemoryPrefetch xeCommandListAppendMemoryPrefetch;
    pfn_xeCommandListAppendMemAdvise xeCommandListAppendMemAdvise;
    pfn_xeDeviceGetCount xeDeviceGetCount;
    pfn_xeDeviceGet xeDeviceGet;
    pfn_xeDeviceGetSubDevice xeDeviceGetSubDevice;
    pfn_xeDeviceGetApiVersion xeDeviceGetApiVersion;
    pfn_xeDeviceGetProperties xeDeviceGetProperties;
    pfn_xeDeviceGetComputeProperties xeDeviceGetComputeProperties;
    pfn_xeDeviceGetMemoryProperties xeDeviceGetMemoryProperties;
    pfn_xeDeviceGetP2PProperties xeDeviceGetP2PProperties;
    pfn_xeDeviceCanAccessPeer xeDeviceCanAccessPeer;
    pfn_xeDeviceSetIntermediateCacheConfig xeDeviceSetIntermediateCacheConfig;
    pfn_xeDeviceSetLastLevelCacheConfig xeDeviceSetLastLevelCacheConfig;
    pfn_xeInit xeInit;
    pfn_xeGetDriverVersion xeGetDriverVersion;
    pfn_xeEventPoolCreate xeEventPoolCreate;
    pfn_xeEventPoolDestroy xeEventPoolDestroy;
    pfn_xeEventCreate xeEventCreate;
    pfn_xeEventDestroy xeEventDestroy;
    pfn_xeEventPoolGetIpcHandle xeEventPoolGetIpcHandle;
    pfn_xeEventPoolOpenIpcHandle xeEventPoolOpenIpcHandle;
    pfn_xeEventPoolCloseIpcHandle xeEventPoolCloseIpcHandle;
    pfn_xeCommandListAppendSignalEvent xeCommandListAppendSignalEvent;
    pfn_xeCommandListAppendWaitOnEvent xeCommandListAppendWaitOnEvent;
    pfn_xeEventHostSignal xeEventHostSignal;
    pfn_xeEventHostSynchronize xeEventHostSynchronize;
    pfn_xeEventQueryStatus xeEventQueryStatus;
    pfn_xeCommandListAppendEventReset xeCommandListAppendEventReset;
    pfn_xeEventReset xeEventReset;
    pfn_xeFenceCreate xeFenceCreate;
    pfn_xeFenceDestroy xeFenceDestroy;
    pfn_xeFenceHostSynchronize xeFenceHostSynchronize;
    pfn_xeFenceQueryStatus xeFenceQueryStatus;
    pfn_xeFenceReset xeFenceReset;
    pfn_xeImageGetProperties xeImageGetProperties;
    pfn_xeImageCreate xeImageCreate;
    pfn_xeImageDestroy xeImageDestroy;
    pfn_xeSharedMemAlloc xeSharedMemAlloc;
    pfn_xeMemAlloc xeMemAlloc;
    pfn_xeHostMemAlloc xeHostMemAlloc;
    pfn_xeMemFree xeMemFree;
    pfn_xeMemGetProperties xeMemGetProperties;
    pfn_xeMemGetAddressRange xeMemGetAddressRange;
    pfn_xeIpcGetMemHandle xeIpcGetMemHandle;
    pfn_xeIpcOpenMemHandle xeIpcOpenMemHandle;
    pfn_xeIpcCloseMemHandle xeIpcCloseMemHandle;
    pfn_xeModuleCreate xeModuleCreate;
    pfn_xeModuleDestroy xeModuleDestroy;
    pfn_xeModuleBuildLogDestroy xeModuleBuildLogDestroy;
    pfn_xeModuleBuildLogGetString xeModuleBuildLogGetString;
    pfn_xeModuleGetNativeBinary xeModuleGetNativeBinary;
    pfn_xeModuleGetGlobalPointer xeModuleGetGlobalPointer;
    pfn_xeFunctionCreate xeFunctionCreate;
    pfn_xeFunctionDestroy xeFunctionDestroy;
    pfn_xeModuleGetFunctionPointer xeModuleGetFunctionPointer;
    pfn_xeFunctionSetGroupSize xeFunctionSetGroupSize;
    pfn_xeFunctionSuggestGroupSize xeFunctionSuggestGroupSize;
    pfn_xeFunctionSetArgumentValue xeFunctionSetArgumentValue;
    pfn_xeFunctionSetAttribute xeFunctionSetAttribute;
    pfn_xeFunctionGetAttribute xeFunctionGetAttribute;
    pfn_xeCommandListAppendLaunchFunction xeCommandListAppendLaunchFunction;
    pfn_xeCommandListAppendLaunchFunctionIndirect xeCommandListAppendLaunchFunctionIndirect;
    pfn_xeCommandListAppendLaunchMultipleFunctionsIndirect xeCommandListAppendLaunchMultipleFunctionsIndirect;
    pfn_xeCommandListAppendLaunchHostFunction xeCommandListAppendLaunchHostFunction;
    pfn_xeDeviceMakeMemoryResident xeDeviceMakeMemoryResident;
    pfn_xeDeviceEvictMemory xeDeviceEvictMemory;
    pfn_xeDeviceMakeImageResident xeDeviceMakeImageResident;
    pfn_xeDeviceEvictImage xeDeviceEvictImage;
    pfn_xeSamplerCreate xeSamplerCreate;
    pfn_xeSamplerDestroy xeSamplerDestroy;
} xe_dispatch_table_t;

inline bool load_xe(void *handle, void *(*funcAddressGetter)(void *handle, const char *funcName), xe_dispatch_table_t *outTable){
    if((0 == funcAddressGetter) || (0 == outTable)){
        return false;
    }
    outTable->xeCommandListAppendMemoryRangesBarrier = (pfn_xeCommandListAppendMemoryRangesBarrier)funcAddressGetter(handle, "xeCommandListAppendMemoryRangesBarrier");
    outTable->xeDeviceSystemBarrier = (pfn_xeDeviceSystemBarrier)funcAddressGetter(handle, "xeDeviceSystemBarrier");
#if XE_ENABLE_OCL_INTEROP
    outTable->xeDeviceRegisterCLMemory = (pfn_xeDeviceRegisterCLMemory)funcAddressGetter(handle, "xeDeviceRegisterCLMemory");
#endif // XE_ENABLE_OCL_INTEROP
#if XE_ENABLE_OCL_INTEROP
    outTable->xeDeviceRegisterCLProgram = (pfn_xeDeviceRegisterCLProgram)funcAddressGetter(handle, "xeDeviceRegisterCLProgram");
#endif // XE_ENABLE_OCL_INTEROP
#if XE_ENABLE_OCL_INTEROP
    outTable->xeDeviceRegisterCLCommandQueue = (pfn_xeDeviceRegisterCLCommandQueue)funcAddressGetter(handle, "xeDeviceRegisterCLCommandQueue");
#endif // XE_ENABLE_OCL_INTEROP
    outTable->xeCommandListCreate = (pfn_xeCommandListCreate)funcAddressGetter(handle, "xeCommandListCreate");
    outTable->xeCommandListDestroy = (pfn_xeCommandListDestroy)funcAddressGetter(handle, "xeCommandListDestroy");
    outTable->xeCommandListClose = (pfn_xeCommandListClose)funcAddressGetter(handle, "xeCommandListClose");
    outTable->xeCommandListReset = (pfn_xeCommandListReset)funcAddressGetter(handle, "xeCommandListReset");
    outTable->xeCommandListSetParameter = (pfn_xeCommandListSetParameter)funcAddressGetter(handle, "xeCommandListSetParameter");
    outTable->xeCommandListGetParameter = (pfn_xeCommandListGetParameter)funcAddressGetter(handle, "xeCommandListGetParameter");
    outTable->xeCommandListResetParameters = (pfn_xeCommandListResetParameters)funcAddressGetter(handle, "xeCommandListResetParameters");
    outTable->xeCommandListReserveSpace = (pfn_xeCommandListReserveSpace)funcAddressGetter(handle, "xeCommandListReserveSpace");
    outTable->xeCommandQueueCreate = (pfn_xeCommandQueueCreate)funcAddressGetter(handle, "xeCommandQueueCreate");
    outTable->xeCommandQueueDestroy = (pfn_xeCommandQueueDestroy)funcAddressGetter(handle, "xeCommandQueueDestroy");
    outTable->xeCommandQueueExecuteCommandLists = (pfn_xeCommandQueueExecuteCommandLists)funcAddressGetter(handle, "xeCommandQueueExecuteCommandLists");
    outTable->xeCommandQueueSynchronize = (pfn_xeCommandQueueSynchronize)funcAddressGetter(handle, "xeCommandQueueSynchronize");
    outTable->xeCommandQueueOpenCommandList = (pfn_xeCommandQueueOpenCommandList)funcAddressGetter(handle, "xeCommandQueueOpenCommandList");
    outTable->xeCommandListAppendMemoryCopy = (pfn_xeCommandListAppendMemoryCopy)funcAddressGetter(handle, "xeCommandListAppendMemoryCopy");
    outTable->xeCommandListAppendMemorySet = (pfn_xeCommandListAppendMemorySet)funcAddressGetter(handle, "xeCommandListAppendMemorySet");
    outTable->xeCommandListAppendImageCopy = (pfn_xeCommandListAppendImageCopy)funcAddressGetter(handle, "xeCommandListAppendImageCopy");
    outTable->xeCommandListAppendImageCopyRegion = (pfn_xeCommandListAppendImageCopyRegion)funcAddressGetter(handle, "xeCommandListAppendImageCopyRegion");
    outTable->xeCommandListAppendImageCopyToMemory = (pfn_xeCommandListAppendImageCopyToMemory)funcAddressGetter(handle, "xeCommandListAppendImageCopyToMemory");
    outTable->xeCommandListAppendImageCopyFromMemory = (pfn_xeCommandListAppendImageCopyFromMemory)funcAddressGetter(handle, "xeCommandListAppendImageCopyFromMemory");
    outTable->xeCommandListAppendMemoryPrefetch = (pfn_xeCommandListAppendMemoryPrefetch)funcAddressGetter(handle, "xeCommandListAppendMemoryPrefetch");
    outTable->xeCommandListAppendMemAdvise = (pfn_xeCommandListAppendMemAdvise)funcAddressGetter(handle, "xeCommandListAppendMemAdvise");
    outTable->xeDeviceGetCount = (pfn_xeDeviceGetCount)funcAddressGetter(handle, "xeDeviceGetCount");
    outTable->xeDeviceGet = (pfn_xeDeviceGet)funcAddressGetter(handle, "xeDeviceGet");
    outTable->xeDeviceGetSubDevice = (pfn_xeDeviceGetSubDevice)funcAddressGetter(handle, "xeDeviceGetSubDevice");
    outTable->xeDeviceGetApiVersion = (pfn_xeDeviceGetApiVersion)funcAddressGetter(handle, "xeDeviceGetApiVersion");
    outTable->xeDeviceGetProperties = (pfn_xeDeviceGetProperties)funcAddressGetter(handle, "xeDeviceGetProperties");
    outTable->xeDeviceGetComputeProperties = (pfn_xeDeviceGetComputeProperties)funcAddressGetter(handle, "xeDeviceGetComputeProperties");
    outTable->xeDeviceGetMemoryProperties = (pfn_xeDeviceGetMemoryProperties)funcAddressGetter(handle, "xeDeviceGetMemoryProperties");
    outTable->xeDeviceGetP2PProperties = (pfn_xeDeviceGetP2PProperties)funcAddressGetter(handle, "xeDeviceGetP2PProperties");
    outTable->xeDeviceCanAccessPeer = (pfn_xeDeviceCanAccessPeer)funcAddressGetter(handle, "xeDeviceCanAccessPeer");
    outTable->xeDeviceSetIntermediateCacheConfig = (pfn_xeDeviceSetIntermediateCacheConfig)funcAddressGetter(handle, "xeDeviceSetIntermediateCacheConfig");
    outTable->xeDeviceSetLastLevelCacheConfig = (pfn_xeDeviceSetLastLevelCacheConfig)funcAddressGetter(handle, "xeDeviceSetLastLevelCacheConfig");
    outTable->xeInit = (pfn_xeInit)funcAddressGetter(handle, "xeInit");
    outTable->xeGetDriverVersion = (pfn_xeGetDriverVersion)funcAddressGetter(handle, "xeGetDriverVersion");
    outTable->xeEventPoolCreate = (pfn_xeEventPoolCreate)funcAddressGetter(handle, "xeEventPoolCreate");
    outTable->xeEventPoolDestroy = (pfn_xeEventPoolDestroy)funcAddressGetter(handle, "xeEventPoolDestroy");
    outTable->xeEventCreate = (pfn_xeEventCreate)funcAddressGetter(handle, "xeEventCreate");
    outTable->xeEventDestroy = (pfn_xeEventDestroy)funcAddressGetter(handle, "xeEventDestroy");
    outTable->xeEventPoolGetIpcHandle = (pfn_xeEventPoolGetIpcHandle)funcAddressGetter(handle, "xeEventPoolGetIpcHandle");
    outTable->xeEventPoolOpenIpcHandle = (pfn_xeEventPoolOpenIpcHandle)funcAddressGetter(handle, "xeEventPoolOpenIpcHandle");
    outTable->xeEventPoolCloseIpcHandle = (pfn_xeEventPoolCloseIpcHandle)funcAddressGetter(handle, "xeEventPoolCloseIpcHandle");
    outTable->xeCommandListAppendSignalEvent = (pfn_xeCommandListAppendSignalEvent)funcAddressGetter(handle, "xeCommandListAppendSignalEvent");
    outTable->xeCommandListAppendWaitOnEvent = (pfn_xeCommandListAppendWaitOnEvent)funcAddressGetter(handle, "xeCommandListAppendWaitOnEvent");
    outTable->xeEventHostSignal = (pfn_xeEventHostSignal)funcAddressGetter(handle, "xeEventHostSignal");
    outTable->xeEventHostSynchronize = (pfn_xeEventHostSynchronize)funcAddressGetter(handle, "xeEventHostSynchronize");
    outTable->xeEventQueryStatus = (pfn_xeEventQueryStatus)funcAddressGetter(handle, "xeEventQueryStatus");
    outTable->xeCommandListAppendEventReset = (pfn_xeCommandListAppendEventReset)funcAddressGetter(handle, "xeCommandListAppendEventReset");
    outTable->xeEventReset = (pfn_xeEventReset)funcAddressGetter(handle, "xeEventReset");
    outTable->xeFenceCreate = (pfn_xeFenceCreate)funcAddressGetter(handle, "xeFenceCreate");
    outTable->xeFenceDestroy = (pfn_xeFenceDestroy)funcAddressGetter(handle, "xeFenceDestroy");
    outTable->xeFenceHostSynchronize = (pfn_xeFenceHostSynchronize)funcAddressGetter(handle, "xeFenceHostSynchronize");
    outTable->xeFenceQueryStatus = (pfn_xeFenceQueryStatus)funcAddressGetter(handle, "xeFenceQueryStatus");
    outTable->xeFenceReset = (pfn_xeFenceReset)funcAddressGetter(handle, "xeFenceReset");
    outTable->xeImageGetProperties = (pfn_xeImageGetProperties)funcAddressGetter(handle, "xeImageGetProperties");
    outTable->xeImageCreate = (pfn_xeImageCreate)funcAddressGetter(handle, "xeImageCreate");
    outTable->xeImageDestroy = (pfn_xeImageDestroy)funcAddressGetter(handle, "xeImageDestroy");
    outTable->xeSharedMemAlloc = (pfn_xeSharedMemAlloc)funcAddressGetter(handle, "xeSharedMemAlloc");
    outTable->xeMemAlloc = (pfn_xeMemAlloc)funcAddressGetter(handle, "xeMemAlloc");
    outTable->xeHostMemAlloc = (pfn_xeHostMemAlloc)funcAddressGetter(handle, "xeHostMemAlloc");
    outTable->xeMemFree = (pfn_xeMemFree)funcAddressGetter(handle, "xeMemFree");
    outTable->xeMemGetProperties = (pfn_xeMemGetProperties)funcAddressGetter(handle, "xeMemGetProperties");
    outTable->xeMemGetAddressRange = (pfn_xeMemGetAddressRange)funcAddressGetter(handle, "xeMemGetAddressRange");
    outTable->xeIpcGetMemHandle = (pfn_xeIpcGetMemHandle)funcAddressGetter(handle, "xeIpcGetMemHandle");
    outTable->xeIpcOpenMemHandle = (pfn_xeIpcOpenMemHandle)funcAddressGetter(handle, "xeIpcOpenMemHandle");
    outTable->xeIpcCloseMemHandle = (pfn_xeIpcCloseMemHandle)funcAddressGetter(handle, "xeIpcCloseMemHandle");
    outTable->xeModuleCreate = (pfn_xeModuleCreate)funcAddressGetter(handle, "xeModuleCreate");
    outTable->xeModuleDestroy = (pfn_xeModuleDestroy)funcAddressGetter(handle, "xeModuleDestroy");
    outTable->xeModuleBuildLogDestroy = (pfn_xeModuleBuildLogDestroy)funcAddressGetter(handle, "xeModuleBuildLogDestroy");
    outTable->xeModuleBuildLogGetString = (pfn_xeModuleBuildLogGetString)funcAddressGetter(handle, "xeModuleBuildLogGetString");
    outTable->xeModuleGetNativeBinary = (pfn_xeModuleGetNativeBinary)funcAddressGetter(handle, "xeModuleGetNativeBinary");
    outTable->xeModuleGetGlobalPointer = (pfn_xeModuleGetGlobalPointer)funcAddressGetter(handle, "xeModuleGetGlobalPointer");
    outTable->xeFunctionCreate = (pfn_xeFunctionCreate)funcAddressGetter(handle, "xeFunctionCreate");
    outTable->xeFunctionDestroy = (pfn_xeFunctionDestroy)funcAddressGetter(handle, "xeFunctionDestroy");
    outTable->xeModuleGetFunctionPointer = (pfn_xeModuleGetFunctionPointer)funcAddressGetter(handle, "xeModuleGetFunctionPointer");
    outTable->xeFunctionSetGroupSize = (pfn_xeFunctionSetGroupSize)funcAddressGetter(handle, "xeFunctionSetGroupSize");
    outTable->xeFunctionSuggestGroupSize = (pfn_xeFunctionSuggestGroupSize)funcAddressGetter(handle, "xeFunctionSuggestGroupSize");
    outTable->xeFunctionSetArgumentValue = (pfn_xeFunctionSetArgumentValue)funcAddressGetter(handle, "xeFunctionSetArgumentValue");
    outTable->xeFunctionSetAttribute = (pfn_xeFunctionSetAttribute)funcAddressGetter(handle, "xeFunctionSetAttribute");
    outTable->xeFunctionGetAttribute = (pfn_xeFunctionGetAttribute)funcAddressGetter(handle, "xeFunctionGetAttribute");
    outTable->xeCommandListAppendLaunchFunction = (pfn_xeCommandListAppendLaunchFunction)funcAddressGetter(handle, "xeCommandListAppendLaunchFunction");
    outTable->xeCommandListAppendLaunchFunctionIndirect = (pfn_xeCommandListAppendLaunchFunctionIndirect)funcAddressGetter(handle, "xeCommandListAppendLaunchFunctionIndirect");
    outTable->xeCommandListAppendLaunchMultipleFunctionsIndirect = (pfn_xeCommandListAppendLaunchMultipleFunctionsIndirect)funcAddressGetter(handle, "xeCommandListAppendLaunchMultipleFunctionsIndirect");
    outTable->xeCommandListAppendLaunchHostFunction = (pfn_xeCommandListAppendLaunchHostFunction)funcAddressGetter(handle, "xeCommandListAppendLaunchHostFunction");
    outTable->xeDeviceMakeMemoryResident = (pfn_xeDeviceMakeMemoryResident)funcAddressGetter(handle, "xeDeviceMakeMemoryResident");
    outTable->xeDeviceEvictMemory = (pfn_xeDeviceEvictMemory)funcAddressGetter(handle, "xeDeviceEvictMemory");
    outTable->xeDeviceMakeImageResident = (pfn_xeDeviceMakeImageResident)funcAddressGetter(handle, "xeDeviceMakeImageResident");
    outTable->xeDeviceEvictImage = (pfn_xeDeviceEvictImage)funcAddressGetter(handle, "xeDeviceEvictImage");
    outTable->xeSamplerCreate = (pfn_xeSamplerCreate)funcAddressGetter(handle, "xeSamplerCreate");
    outTable->xeSamplerDestroy = (pfn_xeSamplerDestroy)funcAddressGetter(handle, "xeSamplerDestroy");
    if(0 == outTable->xeCommandListAppendMemoryRangesBarrier){
        return false;
    }
    if(0 == outTable->xeDeviceSystemBarrier){
        return false;
    }
#if XE_ENABLE_OCL_INTEROP
    if(0 == outTable->xeDeviceRegisterCLMemory){
        return false;
    }
#endif // XE_ENABLE_OCL_INTEROP
#if XE_ENABLE_OCL_INTEROP
    if(0 == outTable->xeDeviceRegisterCLProgram){
        return false;
    }
#endif // XE_ENABLE_OCL_INTEROP
#if XE_ENABLE_OCL_INTEROP
    if(0 == outTable->xeDeviceRegisterCLCommandQueue){
        return false;
    }
#endif // XE_ENABLE_OCL_INTEROP
    if(0 == outTable->xeCommandListCreate){
        return false;
    }
    if(0 == outTable->xeCommandListDestroy){
        return false;
    }
    if(0 == outTable->xeCommandListClose){
        return false;
    }
    if(0 == outTable->xeCommandListReset){
        return false;
    }
    if(0 == outTable->xeCommandListSetParameter){
        return false;
    }
    if(0 == outTable->xeCommandListGetParameter){
        return false;
    }
    if(0 == outTable->xeCommandListResetParameters){
        return false;
    }
    if(0 == outTable->xeCommandListReserveSpace){
        return false;
    }
    if(0 == outTable->xeCommandQueueCreate){
        return false;
    }
    if(0 == outTable->xeCommandQueueDestroy){
        return false;
    }
    if(0 == outTable->xeCommandQueueExecuteCommandLists){
        return false;
    }
    if(0 == outTable->xeCommandQueueSynchronize){
        return false;
    }
    if(0 == outTable->xeCommandQueueOpenCommandList){
        return false;
    }
    if(0 == outTable->xeCommandListAppendMemoryCopy){
        return false;
    }
    if(0 == outTable->xeCommandListAppendMemorySet){
        return false;
    }
    if(0 == outTable->xeCommandListAppendImageCopy){
        return false;
    }
    if(0 == outTable->xeCommandListAppendImageCopyRegion){
        return false;
    }
    if(0 == outTable->xeCommandListAppendImageCopyToMemory){
        return false;
    }
    if(0 == outTable->xeCommandListAppendImageCopyFromMemory){
        return false;
    }
    if(0 == outTable->xeCommandListAppendMemoryPrefetch){
        return false;
    }
    if(0 == outTable->xeCommandListAppendMemAdvise){
        return false;
    }
    if(0 == outTable->xeDeviceGetCount){
        return false;
    }
    if(0 == outTable->xeDeviceGet){
        return false;
    }
    if(0 == outTable->xeDeviceGetSubDevice){
        return false;
    }
    if(0 == outTable->xeDeviceGetApiVersion){
        return false;
    }
    if(0 == outTable->xeDeviceGetProperties){
        return false;
    }
    if(0 == outTable->xeDeviceGetComputeProperties){
        return false;
    }
    if(0 == outTable->xeDeviceGetMemoryProperties){
        return false;
    }
    if(0 == outTable->xeDeviceGetP2PProperties){
        return false;
    }
    if(0 == outTable->xeDeviceCanAccessPeer){
        return false;
    }
    if(0 == outTable->xeDeviceSetIntermediateCacheConfig){
        return false;
    }
    if(0 == outTable->xeDeviceSetLastLevelCacheConfig){
        return false;
    }
    if(0 == outTable->xeInit){
        return false;
    }
    if(0 == outTable->xeGetDriverVersion){
        return false;
    }
    if(0 == outTable->xeEventPoolCreate){
        return false;
    }
    if(0 == outTable->xeEventPoolDestroy){
        return false;
    }
    if(0 == outTable->xeEventCreate){
        return false;
    }
    if(0 == outTable->xeEventDestroy){
        return false;
    }
    if(0 == outTable->xeEventPoolGetIpcHandle){
        return false;
    }
    if(0 == outTable->xeEventPoolOpenIpcHandle){
        return false;
    }
    if(0 == outTable->xeEventPoolCloseIpcHandle){
        return false;
    }
    if(0 == outTable->xeCommandListAppendSignalEvent){
        return false;
    }
    if(0 == outTable->xeCommandListAppendWaitOnEvent){
        return false;
    }
    if(0 == outTable->xeEventHostSignal){
        return false;
    }
    if(0 == outTable->xeEventHostSynchronize){
        return false;
    }
    if(0 == outTable->xeEventQueryStatus){
        return false;
    }
    if(0 == outTable->xeCommandListAppendEventReset){
        return false;
    }
    if(0 == outTable->xeEventReset){
        return false;
    }
    if(0 == outTable->xeFenceCreate){
        return false;
    }
    if(0 == outTable->xeFenceDestroy){
        return false;
    }
    if(0 == outTable->xeFenceHostSynchronize){
        return false;
    }
    if(0 == outTable->xeFenceQueryStatus){
        return false;
    }
    if(0 == outTable->xeFenceReset){
        return false;
    }
    if(0 == outTable->xeImageGetProperties){
        return false;
    }
    if(0 == outTable->xeImageCreate){
        return false;
    }
    if(0 == outTable->xeImageDestroy){
        return false;
    }
    if(0 == outTable->xeSharedMemAlloc){
        return false;
    }
    if(0 == outTable->xeMemAlloc){
        return false;
    }
    if(0 == outTable->xeHostMemAlloc){
        return false;
    }
    if(0 == outTable->xeMemFree){
        return false;
    }
    if(0 == outTable->xeMemGetProperties){
        return false;
    }
    if(0 == outTable->xeMemGetAddressRange){
        return false;
    }
    if(0 == outTable->xeIpcGetMemHandle){
        return false;
    }
    if(0 == outTable->xeIpcOpenMemHandle){
        return false;
    }
    if(0 == outTable->xeIpcCloseMemHandle){
        return false;
    }
    if(0 == outTable->xeModuleCreate){
        return false;
    }
    if(0 == outTable->xeModuleDestroy){
        return false;
    }
    if(0 == outTable->xeModuleBuildLogDestroy){
        return false;
    }
    if(0 == outTable->xeModuleBuildLogGetString){
        return false;
    }
    if(0 == outTable->xeModuleGetNativeBinary){
        return false;
    }
    if(0 == outTable->xeModuleGetGlobalPointer){
        return false;
    }
    if(0 == outTable->xeFunctionCreate){
        return false;
    }
    if(0 == outTable->xeFunctionDestroy){
        return false;
    }
    if(0 == outTable->xeModuleGetFunctionPointer){
        return false;
    }
    if(0 == outTable->xeFunctionSetGroupSize){
        return false;
    }
    if(0 == outTable->xeFunctionSuggestGroupSize){
        return false;
    }
    if(0 == outTable->xeFunctionSetArgumentValue){
        return false;
    }
    if(0 == outTable->xeFunctionSetAttribute){
        return false;
    }
    if(0 == outTable->xeFunctionGetAttribute){
        return false;
    }
    if(0 == outTable->xeCommandListAppendLaunchFunction){
        return false;
    }
    if(0 == outTable->xeCommandListAppendLaunchFunctionIndirect){
        return false;
    }
    if(0 == outTable->xeCommandListAppendLaunchMultipleFunctionsIndirect){
        return false;
    }
    if(0 == outTable->xeCommandListAppendLaunchHostFunction){
        return false;
    }
    if(0 == outTable->xeDeviceMakeMemoryResident){
        return false;
    }
    if(0 == outTable->xeDeviceEvictMemory){
        return false;
    }
    if(0 == outTable->xeDeviceMakeImageResident){
        return false;
    }
    if(0 == outTable->xeDeviceEvictImage){
        return false;
    }
    if(0 == outTable->xeSamplerCreate){
        return false;
    }
    if(0 == outTable->xeSamplerDestroy){
        return false;
    }
    return true;
}
#endif // _XE_LOADER_H
