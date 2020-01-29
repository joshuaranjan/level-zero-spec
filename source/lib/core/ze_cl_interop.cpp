/*
 *
 * Copyright (C) 2019 Intel Corporation
 *
 * SPDX-License-Identifier: MIT
 *
 * @file ze_cl_interop.cpp
 *
 * @brief C++ static library for Intel 'One API' Level-Zero APIs for OpenCL Interoperability
 *
 * @cond DEV
 * DO NOT EDIT: generated from /scripts/core/cl_interop.yml
 * @endcond
 *
 */
#include "ze_lib.h"

extern "C" {

///////////////////////////////////////////////////////////////////////////////
#if ZE_ENABLE_OCL_INTEROP
/// @brief Registers OpenCL memory with 'One API'
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
zeDeviceRegisterCLMemory(
    ze_device_handle_t hDevice,                     ///< [in] handle to the device
    cl_context context,                             ///< [in] the OpenCL context that created the memory
    cl_mem mem,                                     ///< [in] the OpenCL memory to register
    void** ptr                                      ///< [out] pointer to device allocation
    )
{
    auto pfnRegisterCLMemory = ze_lib::context.ddiTable.Device.pfnRegisterCLMemory;
    if( nullptr == pfnRegisterCLMemory )
        return ZE_RESULT_ERROR_UNSUPPORTED_VERSION;

    return pfnRegisterCLMemory( hDevice, context, mem, ptr );
}
#endif // ZE_ENABLE_OCL_INTEROP

///////////////////////////////////////////////////////////////////////////////
#if ZE_ENABLE_OCL_INTEROP
/// @brief Registers OpenCL program with 'One API'
/// 
/// @returns
///     - ::ZE_RESULT_SUCCESS
///     - ::ZE_RESULT_ERROR_UNINITIALIZED
///     - ::ZE_RESULT_ERROR_DEVICE_LOST
///     - ::ZE_RESULT_ERROR_INVALID_NULL_HANDLE
///         + `nullptr == hDevice`
///     - ::ZE_RESULT_ERROR_INVALID_NULL_POINTER
///         + `nullptr == phModule`
///     - ::ZE_RESULT_ERROR_OUT_OF_HOST_MEMORY
///     - ::ZE_RESULT_ERROR_OUT_OF_DEVICE_MEMORY
ze_result_t __zecall
zeDeviceRegisterCLProgram(
    ze_device_handle_t hDevice,                     ///< [in] handle to the device
    cl_context context,                             ///< [in] the OpenCL context that created the program
    cl_program program,                             ///< [in] the OpenCL program to register
    ze_module_handle_t* phModule                    ///< [out] pointer to handle of module object created
    )
{
    auto pfnRegisterCLProgram = ze_lib::context.ddiTable.Device.pfnRegisterCLProgram;
    if( nullptr == pfnRegisterCLProgram )
        return ZE_RESULT_ERROR_UNSUPPORTED_VERSION;

    return pfnRegisterCLProgram( hDevice, context, program, phModule );
}
#endif // ZE_ENABLE_OCL_INTEROP

///////////////////////////////////////////////////////////////////////////////
#if ZE_ENABLE_OCL_INTEROP
/// @brief Registers OpenCL command queue with 'One API'
/// 
/// @returns
///     - ::ZE_RESULT_SUCCESS
///     - ::ZE_RESULT_ERROR_UNINITIALIZED
///     - ::ZE_RESULT_ERROR_DEVICE_LOST
///     - ::ZE_RESULT_ERROR_INVALID_NULL_HANDLE
///         + `nullptr == hDevice`
///     - ::ZE_RESULT_ERROR_INVALID_NULL_POINTER
///         + `nullptr == phCommandQueue`
///     - ::ZE_RESULT_ERROR_OUT_OF_HOST_MEMORY
///     - ::ZE_RESULT_ERROR_OUT_OF_DEVICE_MEMORY
ze_result_t __zecall
zeDeviceRegisterCLCommandQueue(
    ze_device_handle_t hDevice,                     ///< [in] handle to the device
    cl_context context,                             ///< [in] the OpenCL context that created the command queue
    cl_command_queue command_queue,                 ///< [in] the OpenCL command queue to register
    ze_command_queue_handle_t* phCommandQueue       ///< [out] pointer to handle of command queue object created
    )
{
    auto pfnRegisterCLCommandQueue = ze_lib::context.ddiTable.Device.pfnRegisterCLCommandQueue;
    if( nullptr == pfnRegisterCLCommandQueue )
        return ZE_RESULT_ERROR_UNSUPPORTED_VERSION;

    return pfnRegisterCLCommandQueue( hDevice, context, command_queue, phCommandQueue );
}
#endif // ZE_ENABLE_OCL_INTEROP

} // extern "C"
