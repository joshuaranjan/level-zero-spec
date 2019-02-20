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
* @file xe_cmdlist.cpp
*
* @brief Intel Xe Driver APIs for Command List
*
* DO NOT EDIT: generated from /scripts/<type>/cmdlist.yml
*
******************************************************************************/
#include "../include/xe_cmdlist.h"

#include <exception>    // @todo: move to common and/or precompiled header

///////////////////////////////////////////////////////////////////////////////
/// @brief Creates a command list on the device for submitting commands to any
///        command queue.
/// 
/// @details
///     - The command list is created in the 'open' state.
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
///         + nullptr == phCommandList
///     - ::XE_RESULT_ERROR_UNSUPPORTED
///         + ::XE_COMMAND_LIST_DESC_VERSION <= desc->version
///     - ::XE_RESULT_ERROR_OUT_OF_HOST_MEMORY
///     - ::XE_RESULT_ERROR_OUT_OF_DEVICE_MEMORY
///
/// @hash {30179944405dd754aa51afa884ab3ef58a0b94bbdda27c2776a05c23c12678dc}
///
__xedllexport xe_result_t __xecall
  xeDeviceCreateCommandList(
    xe_device_handle_t hDevice,                     ///< [in] handle of the device object
    const xe_command_list_desc_t* desc,             ///< [in] pointer to command list descriptor
    xe_command_list_handle_t* phCommandList         ///< [out] pointer to handle of command list object created
    )
{
    try
    {
        //if( XE_DRIVER_PARAMETER_VALIDATION_LEVEL >= 0 )
        {
            // if( nullptr == driver ) return XE_RESULT_ERROR_UNINITIALIZED;

            // Check parameters
            if( nullptr == hDevice ) return XE_RESULT_ERROR_INVALID_PARAMETER;
            if( nullptr == desc ) return XE_RESULT_ERROR_INVALID_PARAMETER;
            if( nullptr == phCommandList ) return XE_RESULT_ERROR_INVALID_PARAMETER;
            if( XE_COMMAND_LIST_DESC_VERSION <= desc->version ) return XE_RESULT_ERROR_UNSUPPORTED;
        }
        /// @begin

        // @todo: insert <code> here

        /// @end
        return XE_RESULT_SUCCESS;
    }
    catch(xe_result_t& result)
    {
        return result;
    }
    catch(std::bad_alloc&)
    {
        return XE_RESULT_ERROR_OUT_OF_HOST_MEMORY;
    }
    catch(std::exception&)
    {
        // @todo: pfnOnException(e.what());
        return XE_RESULT_ERROR_UNKNOWN;
    }
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Copies a command list on the device for submitting commands to any
///        command queue.
/// 
/// @details
///     - The command list to be copied must be closed.
///     - The command list created will be in the 'open' state.
///     - If the device is a different than the one used to create the source
///       command list, then it must have been created using the
///       ::XE_COMMAND_LIST_FLAG_CROSS_DEVICE flag.
///     - This function may be called from simultaneous threads.
///     - The implementation of this function should be lock-free.
/// 
/// @returns
///     - ::XE_RESULT_SUCCESS
///     - ::XE_RESULT_ERROR_UNINITIALIZED
///     - ::XE_RESULT_ERROR_DEVICE_LOST
///     - ::XE_RESULT_ERROR_INVALID_PARAMETER
///         + nullptr == hDevice
///         + nullptr == hCommandList
///         + nullptr == phCommandList
///     - ::XE_RESULT_ERROR_UNSUPPORTED
///     - ::XE_RESULT_ERROR_OUT_OF_HOST_MEMORY
///     - ::XE_RESULT_ERROR_OUT_OF_DEVICE_MEMORY
///
/// @hash {cb04dd0733e58a851c0572d742124358b24254aa21c3320c9473cb8aa20a5a7f}
///
__xedllexport xe_result_t __xecall
  xeDeviceCopyCommandList(
    xe_device_handle_t hDevice,                     ///< [in] handle of the device object
    xe_command_list_handle_t hCommandList,          ///< [in] handle to command list to copy
    xe_command_list_handle_t* phCommandList         ///< [out] pointer to handle of command list object created
    )
{
    try
    {
        //if( XE_DRIVER_PARAMETER_VALIDATION_LEVEL >= 0 )
        {
            // if( nullptr == driver ) return XE_RESULT_ERROR_UNINITIALIZED;

            // Check parameters
            if( nullptr == hDevice ) return XE_RESULT_ERROR_INVALID_PARAMETER;
            if( nullptr == hCommandList ) return XE_RESULT_ERROR_INVALID_PARAMETER;
            if( nullptr == phCommandList ) return XE_RESULT_ERROR_INVALID_PARAMETER;
        }
        /// @begin

        // @todo: insert <code> here

        /// @end
        return XE_RESULT_SUCCESS;
    }
    catch(xe_result_t& result)
    {
        return result;
    }
    catch(std::bad_alloc&)
    {
        return XE_RESULT_ERROR_OUT_OF_HOST_MEMORY;
    }
    catch(std::exception&)
    {
        // @todo: pfnOnException(e.what());
        return XE_RESULT_ERROR_UNKNOWN;
    }
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Destroys a command list.
/// 
/// @details
///     - The application is responsible for making sure the GPU is not
///       currently referencing the command list before it is deleted
///     - The implementation of this function will immediately free all Host and
///       Device allocations associated with this command list.
///     - The implementation of this function should be lock-free.
/// 
/// @returns
///     - ::XE_RESULT_SUCCESS
///     - ::XE_RESULT_ERROR_UNINITIALIZED
///     - ::XE_RESULT_ERROR_DEVICE_LOST
///     - ::XE_RESULT_ERROR_INVALID_PARAMETER
///         + nullptr == hCommandList
///     - ::XE_RESULT_ERROR_UNSUPPORTED
///
/// @hash {bda478b6a2926bea888c8c1b4c9a333a3a13205d3fc16d3ae0972b97335fc4ff}
///
__xedllexport xe_result_t __xecall
  xeCommandListDestroy(
    xe_command_list_handle_t hCommandList           ///< [in] handle of command list object to destroy
    )
{
    try
    {
        //if( XE_DRIVER_PARAMETER_VALIDATION_LEVEL >= 0 )
        {
            // if( nullptr == driver ) return XE_RESULT_ERROR_UNINITIALIZED;

            // Check parameters
            if( nullptr == hCommandList ) return XE_RESULT_ERROR_INVALID_PARAMETER;
        }
        /// @begin

        // @todo: insert <code> here

        /// @end
        return XE_RESULT_SUCCESS;
    }
    catch(xe_result_t& result)
    {
        return result;
    }
    catch(std::bad_alloc&)
    {
        return XE_RESULT_ERROR_OUT_OF_HOST_MEMORY;
    }
    catch(std::exception&)
    {
        // @todo: pfnOnException(e.what());
        return XE_RESULT_ERROR_UNKNOWN;
    }
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Closes a command list; ready to be enqueued into a command queue.
/// 
/// @details
///     - The application may **not** call this function from simultaneous
///       threads with the same command list handle.
///     - The implementation of this function should be lock-free.
/// 
/// @returns
///     - ::XE_RESULT_SUCCESS
///     - ::XE_RESULT_ERROR_UNINITIALIZED
///     - ::XE_RESULT_ERROR_DEVICE_LOST
///     - ::XE_RESULT_ERROR_INVALID_PARAMETER
///         + nullptr == hCommandList
///     - ::XE_RESULT_ERROR_UNSUPPORTED
///
/// @hash {90afb0f4260abf7f09ed295975efc80087058f86a66e73983dd9c9b30f8b2a48}
///
__xedllexport xe_result_t __xecall
  xeCommandListClose(
    xe_command_list_handle_t hCommandList           ///< [in] handle of command list object to close
    )
{
    try
    {
        //if( XE_DRIVER_PARAMETER_VALIDATION_LEVEL >= 0 )
        {
            // if( nullptr == driver ) return XE_RESULT_ERROR_UNINITIALIZED;

            // Check parameters
            if( nullptr == hCommandList ) return XE_RESULT_ERROR_INVALID_PARAMETER;
        }
        /// @begin

        // @todo: insert <code> here

        /// @end
        return XE_RESULT_SUCCESS;
    }
    catch(xe_result_t& result)
    {
        return result;
    }
    catch(std::bad_alloc&)
    {
        return XE_RESULT_ERROR_OUT_OF_HOST_MEMORY;
    }
    catch(std::exception&)
    {
        // @todo: pfnOnException(e.what());
        return XE_RESULT_ERROR_UNKNOWN;
    }
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Reset a command list to initial (empty) state; ready for encoding
///        commands.
/// 
/// @details
///     - The application is responsible for making sure the GPU is not
///       currently referencing the command list before it is reset
///     - The application may **not** call this function from simultaneous
///       threads with the same command list handle.
///     - The implementation of this function should be lock-free.
/// 
/// @returns
///     - ::XE_RESULT_SUCCESS
///     - ::XE_RESULT_ERROR_UNINITIALIZED
///     - ::XE_RESULT_ERROR_DEVICE_LOST
///     - ::XE_RESULT_ERROR_INVALID_PARAMETER
///         + nullptr == hCommandList
///     - ::XE_RESULT_ERROR_UNSUPPORTED
///
/// @hash {66bc9e2b7766eb06b0315ded3a6c40ea09ad7181fb12b2ad53d2c3d801085382}
///
__xedllexport xe_result_t __xecall
  xeCommandListReset(
    xe_command_list_handle_t hCommandList           ///< [in] handle of command list object to reset
    )
{
    try
    {
        //if( XE_DRIVER_PARAMETER_VALIDATION_LEVEL >= 0 )
        {
            // if( nullptr == driver ) return XE_RESULT_ERROR_UNINITIALIZED;

            // Check parameters
            if( nullptr == hCommandList ) return XE_RESULT_ERROR_INVALID_PARAMETER;
        }
        /// @begin

        // @todo: insert <code> here

        /// @end
        return XE_RESULT_SUCCESS;
    }
    catch(xe_result_t& result)
    {
        return result;
    }
    catch(std::bad_alloc&)
    {
        return XE_RESULT_ERROR_OUT_OF_HOST_MEMORY;
    }
    catch(std::exception&)
    {
        // @todo: pfnOnException(e.what());
        return XE_RESULT_ERROR_UNKNOWN;
    }
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Sets a command list's parameter.
/// 
/// @details
///     - The application may **not** call this function from simultaneous
///       threads with the same command list handle.
///     - The implementation of this function should be lock-free.
/// 
/// @remarks
///   _Analogues_
///     - cuCtxSetCacheConfig
///     - cuCtxSetLimit
///     - cuCtxSetSharedMemConfig
/// 
/// @returns
///     - ::XE_RESULT_SUCCESS
///     - ::XE_RESULT_ERROR_UNINITIALIZED
///     - ::XE_RESULT_ERROR_DEVICE_LOST
///     - ::XE_RESULT_ERROR_INVALID_PARAMETER
///         + nullptr == hCommandList
///         + invalid value for attribute
///         + invalid value for value
///     - ::XE_RESULT_ERROR_UNSUPPORTED
///
/// @hash {d9caf889451be1ea8e3cc168591fd03c2dca3f8b5650b0bc13252abbcd50c3f3}
///
__xedllexport xe_result_t __xecall
  xeCommandListSetParameter(
    xe_command_list_handle_t hCommandList,          ///< [in] handle of command list
    xe_command_list_parameter_t parameter,          ///< [in] parameter to change
    uint32_t value                                  ///< [in] value of attribute
    )
{
    try
    {
        //if( XE_DRIVER_PARAMETER_VALIDATION_LEVEL >= 0 )
        {
            // if( nullptr == driver ) return XE_RESULT_ERROR_UNINITIALIZED;

            // Check parameters
            if( nullptr == hCommandList ) return XE_RESULT_ERROR_INVALID_PARAMETER;
        }
        /// @begin

        // @todo: insert <code> here

        /// @end
        return XE_RESULT_SUCCESS;
    }
    catch(xe_result_t& result)
    {
        return result;
    }
    catch(std::bad_alloc&)
    {
        return XE_RESULT_ERROR_OUT_OF_HOST_MEMORY;
    }
    catch(std::exception&)
    {
        // @todo: pfnOnException(e.what());
        return XE_RESULT_ERROR_UNKNOWN;
    }
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Retrieves a command list's parameter.
/// 
/// @details
///     - The application may **not** call this function from simultaneous
///       threads with the same command list handle.
///     - The implementation of this function should be lock-free.
/// 
/// @remarks
///   _Analogues_
///     - cuCtxGetCacheConfig
///     - cuCtxGetLimit
///     - cuCtxGetSharedMemConfig
///     - cuCtxGetStreamPriorityRange
/// 
/// @returns
///     - ::XE_RESULT_SUCCESS
///     - ::XE_RESULT_ERROR_UNINITIALIZED
///     - ::XE_RESULT_ERROR_DEVICE_LOST
///     - ::XE_RESULT_ERROR_INVALID_PARAMETER
///         + nullptr == hCommandList
///         + nullptr == value
///         + invalid value for attribute
///     - ::XE_RESULT_ERROR_UNSUPPORTED
///
/// @hash {777661badc06e83cb81081081ac71fb368cdd3cc235e1d188eeeaae409158e59}
///
__xedllexport xe_result_t __xecall
  xeCommandListGetParameter(
    xe_command_list_handle_t hCommandList,          ///< [in] handle of command list
    xe_command_list_parameter_t parameter,          ///< [in] parameter to retrieve
    uint32_t* value                                 ///< [out] value of attribute
    )
{
    try
    {
        //if( XE_DRIVER_PARAMETER_VALIDATION_LEVEL >= 0 )
        {
            // if( nullptr == driver ) return XE_RESULT_ERROR_UNINITIALIZED;

            // Check parameters
            if( nullptr == hCommandList ) return XE_RESULT_ERROR_INVALID_PARAMETER;
            if( nullptr == value ) return XE_RESULT_ERROR_INVALID_PARAMETER;
        }
        /// @begin

        // @todo: insert <code> here

        /// @end
        return XE_RESULT_SUCCESS;
    }
    catch(xe_result_t& result)
    {
        return result;
    }
    catch(std::bad_alloc&)
    {
        return XE_RESULT_ERROR_OUT_OF_HOST_MEMORY;
    }
    catch(std::exception&)
    {
        // @todo: pfnOnException(e.what());
        return XE_RESULT_ERROR_UNKNOWN;
    }
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Resets all command list parameters to default state.
/// 
/// @details
///     - The application may **not** call this function from simultaneous
///       threads with the same command list handle.
///     - The implementation of this function should be lock-free.
/// 
/// @returns
///     - ::XE_RESULT_SUCCESS
///     - ::XE_RESULT_ERROR_UNINITIALIZED
///     - ::XE_RESULT_ERROR_DEVICE_LOST
///     - ::XE_RESULT_ERROR_INVALID_PARAMETER
///         + nullptr == hCommandList
///     - ::XE_RESULT_ERROR_UNSUPPORTED
///
/// @hash {395c8a05f90f7eeaba849d437320a99b66722039d7cb081a256ed4c16d408edf}
///
__xedllexport xe_result_t __xecall
  xeCommandListResetParameters(
    xe_command_list_handle_t hCommandList           ///< [in] handle of the command list
    )
{
    try
    {
        //if( XE_DRIVER_PARAMETER_VALIDATION_LEVEL >= 0 )
        {
            // if( nullptr == driver ) return XE_RESULT_ERROR_UNINITIALIZED;

            // Check parameters
            if( nullptr == hCommandList ) return XE_RESULT_ERROR_INVALID_PARAMETER;
        }
        /// @begin

        // @todo: insert <code> here

        /// @end
        return XE_RESULT_SUCCESS;
    }
    catch(xe_result_t& result)
    {
        return result;
    }
    catch(std::bad_alloc&)
    {
        return XE_RESULT_ERROR_OUT_OF_HOST_MEMORY;
    }
    catch(std::exception&)
    {
        // @todo: pfnOnException(e.what());
        return XE_RESULT_ERROR_UNKNOWN;
    }
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Encode a command list into another command list.
/// 
/// @details
///     - The application may **not** call this function from simultaneous
///       threads with the same command list handle.
///     - The implementation of this function should be lock-free.
/// 
/// @returns
///     - ::XE_RESULT_SUCCESS
///     - ::XE_RESULT_ERROR_UNINITIALIZED
///     - ::XE_RESULT_ERROR_DEVICE_LOST
///     - ::XE_RESULT_ERROR_INVALID_PARAMETER
///         + nullptr == hCommandList
///         + nullptr == phCommandLists
///         + 0 for numCommandLists
///     - ::XE_RESULT_ERROR_UNSUPPORTED
///
/// @hash {596df05be8f869f5f8e50121263d6be6d062370e8ebddec124125948e8b8f644}
///
__xedllexport xe_result_t __xecall
  xeCommandListEncodeCommandLists(
    xe_command_list_handle_t hCommandList,          ///< [in] handle of the command list
    uint32_t numCommandLists,                       ///< [in] number of command lists to encode
    xe_command_list_handle_t* phCommandLists        ///< [in] list of handles of the command lists to encode for execution
    )
{
    try
    {
        //if( XE_DRIVER_PARAMETER_VALIDATION_LEVEL >= 0 )
        {
            // if( nullptr == driver ) return XE_RESULT_ERROR_UNINITIALIZED;

            // Check parameters
            if( nullptr == hCommandList ) return XE_RESULT_ERROR_INVALID_PARAMETER;
            if( nullptr == phCommandLists ) return XE_RESULT_ERROR_INVALID_PARAMETER;
        }
        /// @begin

        // @todo: insert <code> here

        /// @end
        return XE_RESULT_SUCCESS;
    }
    catch(xe_result_t& result)
    {
        return result;
    }
    catch(std::bad_alloc&)
    {
        return XE_RESULT_ERROR_OUT_OF_HOST_MEMORY;
    }
    catch(std::exception&)
    {
        // @todo: pfnOnException(e.what());
        return XE_RESULT_ERROR_UNKNOWN;
    }
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Encode a pre-formatted blob of commands into the comamnd list.
/// 
/// @details
///     - The commands are gaurenteed to be contiguous in the command buffer
///     - The application may **not** call this function from simultaneous
///       threads with the same command list handle.
///     - The implementation of this function should be lock-free.
/// 
/// @returns
///     - ::XE_RESULT_SUCCESS
///     - ::XE_RESULT_ERROR_UNINITIALIZED
///     - ::XE_RESULT_ERROR_DEVICE_LOST
///     - ::XE_RESULT_ERROR_INVALID_PARAMETER
///         + nullptr == hCommandList
///         + nullptr == pBlob
///         + invalid value for format
///         + 0 for size
///     - ::XE_RESULT_ERROR_UNSUPPORTED
///
/// @hash {4ee4c7f667ccfeddde2cf709cea446468d2e5a3703c9233d89defae89ed61118}
///
__xedllexport xe_result_t __xecall
  xeCommandListEncodeCommands(
    xe_command_list_handle_t hCommandList,          ///< [in] handle of the command list
    xe_command_format_t format,                     ///< [in] format of the command blob
    size_t size,                                    ///< [in] size (in bytes) of the command blob
    void* pBlob                                     ///< [in] pointer to blob of commands to encode into the command list
    )
{
    try
    {
        //if( XE_DRIVER_PARAMETER_VALIDATION_LEVEL >= 0 )
        {
            // if( nullptr == driver ) return XE_RESULT_ERROR_UNINITIALIZED;

            // Check parameters
            if( nullptr == hCommandList ) return XE_RESULT_ERROR_INVALID_PARAMETER;
            if( nullptr == pBlob ) return XE_RESULT_ERROR_INVALID_PARAMETER;
        }
        /// @begin

        // @todo: insert <code> here

        /// @end
        return XE_RESULT_SUCCESS;
    }
    catch(xe_result_t& result)
    {
        return result;
    }
    catch(std::bad_alloc&)
    {
        return XE_RESULT_ERROR_OUT_OF_HOST_MEMORY;
    }
    catch(std::exception&)
    {
        // @todo: pfnOnException(e.what());
        return XE_RESULT_ERROR_UNKNOWN;
    }
}

