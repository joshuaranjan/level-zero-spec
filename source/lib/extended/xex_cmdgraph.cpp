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
* @file xex_cmdgraph.cpp
*
* @brief C++ wrapper of Intel Xe Level-Zero Extended APIs for CommandGraph
*
* @cond DEV
* DO NOT EDIT: generated from /scripts/extended/cmdgraph.yml
* @endcond
*
******************************************************************************/
#include "xex_api.hpp"

namespace xex
{
    ///////////////////////////////////////////////////////////////////////////////
    CommandGraph::CommandGraph( 
        Device* pDevice,                                ///< [in] pointer to parent object
        desc_t desc                                     ///< [in] descriptor of the command graph object
        ) :
        m_pDevice( pDevice ),
        m_desc( desc )
    {
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief C++ wrapper for ::xexCommandGraphCreate
    /// 
    /// @details
    ///     - The application may call this function from simultaneous threads.
    ///     - The implementation of this function should be lock-free.
    /// 
    /// @returns
    ///     - CommandGraph: pointer to handle of command graph object created
    /// 
    /// @throws result_t
    inline CommandGraph* 
    CommandGraph::Create(
        xe::Device* hDevice,                            ///< [in] handle of the device object
        const desc_t* desc                              ///< [in] pointer to command graph descriptor
        )
    {
        // auto result = ::xexCommandGraphCreate( handle, hDevice, desc );
        // if( ::XE_RESULT_SUCCESS != result ) throw exception(result, "xex::CommandGraph::Create");
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief C++ wrapper for ::xexCommandGraphDestroy
    /// 
    /// @details
    ///     - The implementation of this function will immediately free all Host
    ///       allocations associated with this command graph.
    ///     - The application may **not** call this function from simultaneous
    ///       threads with the same command graph handle.
    ///     - The implementation of this function should be lock-free.
    /// 
    /// @throws result_t
    inline void 
    CommandGraph::Destroy(
        CommandGraph* hCommandGraph                     ///< [in] handle of command graph object to destroy
        )
    {
        // auto result = ::xexCommandGraphDestroy( handle, hCommandGraph );
        // if( ::XE_RESULT_SUCCESS != result ) throw exception(result, "xex::CommandGraph::Destroy");
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief C++ wrapper for ::xexCommandGraphClose
    /// 
    /// @details
    ///     - The command graph will optimize the execution order of the command
    ///       lists.
    ///     - A command list may **not** be reset after the command graph is closed.
    ///     - The application may **not** call this function from simultaneous
    ///       threads with the same command graph handle.
    ///     - The implementation of this function should be lock-free.
    /// 
    /// @throws result_t
    inline void 
    CommandGraph::Close(
        void
        )
    {
        // auto result = ::xexCommandGraphClose( handle );
        // if( ::XE_RESULT_SUCCESS != result ) throw exception(result, "xex::CommandGraph::Close");
    }

} // namespace xex