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
* @file xe_cmdgraph.h
*
* @brief Intel Xe Driver APIs for CommandGraph
*
* @cond DEV
* DO NOT EDIT: generated from /scripts/<type>/cmdgraph.yml
* @endcond
*
******************************************************************************/
#ifndef _XE_CMDGRAPH_H
#define _XE_CMDGRAPH_H
#if defined(__cplusplus)
#pragma once
#endif
#include "xe_common.h"

#if defined(__cplusplus)
extern "C" {
#endif

///////////////////////////////////////////////////////////////////////////////
/// @brief API version of ::xe_command_graph_desc_t
#define XE_COMMAND_GRAPH_DESC_VERSION  XE_MAKE_VERSION( 1, 0 )

///////////////////////////////////////////////////////////////////////////////
/// @brief Supported command graph creation flags
typedef enum _xe_command_graph_flag_t
{
    XE_COMMAND_GRAPH_FLAG_NONE = 0,                 ///< default behavior

} xe_command_graph_flag_t;

///////////////////////////////////////////////////////////////////////////////
/// @brief CommandGraph descriptor
typedef struct _xe_command_graph_desc_t
{
    uint32_t version;                               ///< [in] ::XE_COMMAND_GRAPH_DESC_VERSION
    xe_command_graph_flag_t flags;                  ///< [in] creation flags

} xe_command_graph_desc_t;

///////////////////////////////////////////////////////////////////////////////
/// @brief Creates a command graph on the device for submitting commands to any
///        command queue.
/// 
/// @details
///     - This function may be called from simultaneous threads.
///     - The implementation of this function should be lock-free.
/// 
/// @returns
///     - ::XE_RESULT_SUCCESS
///     - ::XE_RESULT_ERROR_UNINITIALIZED
///     - ::XE_RESULT_ERROR_DEVICE_LOST
///     - ::XE_RESULT_ERROR_INVALID_PARAMETER
///         + nullptr == hDevice
///         + nullptr == desc
///         + nullptr == phCommandGraph
///     - ::XE_RESULT_ERROR_UNSUPPORTED
///         + ::XE_COMMAND_GRAPH_DESC_VERSION <= desc->version
///     - ::XE_RESULT_ERROR_OUT_OF_HOST_MEMORY
///     - ::XE_RESULT_ERROR_OUT_OF_DEVICE_MEMORY
__xedllport xe_result_t __xecall
  xeDeviceCreateCommandGraph(
    xe_device_handle_t hDevice,                     ///< [in] handle of the device object
    const xe_command_graph_desc_t* desc,            ///< [in] pointer to command graph descriptor
    xe_command_graph_handle_t* phCommandGraph       ///< [out] pointer to handle of command graph object created
    );

///////////////////////////////////////////////////////////////////////////////
/// @brief Destroys a command graph.
/// 
/// @details
///     - The implementation of this function will immediately free all Host
///       allocations associated with this command graph.
///     - The implementation of this function should be lock-free.
/// 
/// @returns
///     - ::XE_RESULT_SUCCESS
///     - ::XE_RESULT_ERROR_UNINITIALIZED
///     - ::XE_RESULT_ERROR_DEVICE_LOST
///     - ::XE_RESULT_ERROR_INVALID_PARAMETER
///         + nullptr == hCommandGraph
///     - ::XE_RESULT_ERROR_UNSUPPORTED
__xedllport xe_result_t __xecall
  xeCommandGraphDestroy(
    xe_command_graph_handle_t hCommandGraph         ///< [in] handle of command graph object to destroy
    );

///////////////////////////////////////////////////////////////////////////////
/// @brief Closes a command graph; ready to be enqueued into a command queue.
/// 
/// @details
///     - The command graph will optimize the execution order of the command
///       lists.
///     - A command list may **not** be reset after the command graph is closed.
///     - The application may **not** call this function from simultaneous
///       threads with the same command graph handle.
///     - The implementation of this function should be lock-free.
/// 
/// @returns
///     - ::XE_RESULT_SUCCESS
///     - ::XE_RESULT_ERROR_UNINITIALIZED
///     - ::XE_RESULT_ERROR_DEVICE_LOST
///     - ::XE_RESULT_ERROR_INVALID_PARAMETER
///         + nullptr == hCommandGraph
///     - ::XE_RESULT_ERROR_UNSUPPORTED
__xedllport xe_result_t __xecall
  xeCommandGraphClose(
    xe_command_graph_handle_t hCommandGraph         ///< [in] handle of command graph object to close
    );

///////////////////////////////////////////////////////////////////////////////
/// @brief Reset a command graph to initial (empty) state; ready for adding
///        command lists.
/// 
/// @details
///     - The application may **not** call this function from simultaneous
///       threads with the same command graph handle.
///     - The implementation of this function should be lock-free.
/// 
/// @returns
///     - ::XE_RESULT_SUCCESS
///     - ::XE_RESULT_ERROR_UNINITIALIZED
///     - ::XE_RESULT_ERROR_DEVICE_LOST
///     - ::XE_RESULT_ERROR_INVALID_PARAMETER
///         + nullptr == hCommandGraph
///     - ::XE_RESULT_ERROR_UNSUPPORTED
__xedllport xe_result_t __xecall
  xeCommandGraphReset(
    xe_command_graph_handle_t hCommandGraph         ///< [in] handle of command graph object to reset
    );

#if defined(__cplusplus)
} // extern "C"
#endif

#endif // _XE_CMDGRAPH_H
