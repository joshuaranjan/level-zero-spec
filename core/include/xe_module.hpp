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
* @file xe_module.hpp
*
* @brief C++ wrapper of Intel Xe Driver APIs for Module
*
* @cond DEV
* DO NOT EDIT: generated from /scripts/core/module.yml
* @endcond
*
******************************************************************************/
#ifndef _XE_MODULE_HPP
#define _XE_MODULE_HPP
#if defined(__cplusplus)
#pragma once
#include "xe_common.hpp"

namespace xe
{
    ///////////////////////////////////////////////////////////////////////////////
    /// @brief C++ wrapper for module
    class Module
    {
    protected:
        ::xe_module_handle_t handle;                      ///< handle of module object
        ::xe_module_desc_t desc;                          ///< descriptor of the module object

    public:
        auto getHandle( void ) const { return handle; }
        auto getDesc( void ) const { return desc; }

        ///////////////////////////////////////////////////////////////////////////////
        /// @brief C++ version for ::xe_function_flag_t
        enum class function_flag_t
        {
            NONE = 0,                                       ///< default driver behavior
            FORCE_RESIDENCY,                                ///< force all device allocations to be resident during execution

        };

        ///////////////////////////////////////////////////////////////////////////////
        /// @brief C++ version for ::xe_function_desc_t
        struct function_desc_t
        {
            uint32_t version = XE_FUNCTION_DESC_VERSION;    ///< [in] ::FUNCTION_DESC_VERSION
            function_flag_t flags = function_flag_t::NONE;  ///< [in] creation flags
            const char* pFunctionName = nullptr;            ///< [in] null-terminated name of function in Module

        };

        ///////////////////////////////////////////////////////////////////////////////
        /// @brief C++ wrapper for ::xeModuleDestroy
        inline void Destroy(
            );

        ///////////////////////////////////////////////////////////////////////////////
        /// @brief C++ wrapper for ::xeModuleGetNativeBinary
        inline void GetNativeBinary(
            uint32_t* pSize,                                ///< [out] size of native binary.
            char** pModuleNativeBinary                      ///< [out] pointer to native binary
            );

        ///////////////////////////////////////////////////////////////////////////////
        /// @brief C++ wrapper for ::xeModuleCreateFunction
        inline void CreateFunction(
            const function_desc_t* pDesc,                   ///< [in] pointer to function descriptor
            function_handle_t* phFunction                   ///< [out] handle of the Function object
            );

        ///////////////////////////////////////////////////////////////////////////////
        /// @brief C++ wrapper for ::xeModuleGetFunctionPointer
        inline void GetFunctionPointer(
            const char* pFunctionName,                      ///< [in] Name of function to retrieve function pointer for.
            void** pfnFunction                              ///< [out] pointer to function.
            );

    };

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief C++ wrapper for function
    class Function
    {
    protected:
        ::xe_function_handle_t handle;                    ///< handle of function object
        ::xe_function_desc_t desc;                        ///< descriptor of the function object

    public:
        auto getHandle( void ) const { return handle; }
        auto getDesc( void ) const { return desc; }

        ///////////////////////////////////////////////////////////////////////////////
        /// @brief C++ version for ::xe_function_set_attribute_t
        enum class function_set_attribute_t
        {
            FUNCTION_SET_ATTR_INDIRECT_HOST_ACCESS = 0,     ///< Indicates that the function accesses host allocations indirectly
                                                            ///< (default: false)
            FUNCTION_SET_ATTR_INDIRECT_DEVICE_ACCESS,       ///< Indicates that the function accesses device allocations indirectly
                                                            ///< (default: false)
            FUNCTION_SET_ATTR_INDIRECT_SHARED_ACCESS,       ///< Indicates that the function accesses shared allocations indirectly
                                                            ///< (default: false)

        };

        ///////////////////////////////////////////////////////////////////////////////
        /// @brief C++ version for ::xe_function_get_attribute_t
        enum class function_get_attribute_t
        {
            FUNCTION_GET_ATTR_MAX_REGS_USED = 0,            ///< Maximum device registers used for this function
            FUNCTION_GET_ATTR_NUM_THREAD_DIMENSIONS,        ///< Maximum dimensions for group for this function
            FUNCTION_GET_ATTR_MAX_SHARED_MEM_SIZE,          ///< Maximum shared memory required for this function
            FUNCTION_GET_ATTR_HAS_SPILL_FILL,               ///< Function required spill/fills.
            FUNCTION_GET_ATTR_HAS_BARRIERS,                 ///< Function contains barriers.
            FUNCTION_GET_ATTR_HAS_DPAS,                     ///< Function contains DPAs.

        };

        ///////////////////////////////////////////////////////////////////////////////
        /// @brief C++ wrapper for ::xeFunctionDestroy
        inline void Destroy(
            );

        ///////////////////////////////////////////////////////////////////////////////
        /// @brief C++ wrapper for ::xeFunctionSetGroupSize
        inline void SetGroupSize(
            uint32_t groupSizeX,                            ///< [in] group size for X dimension to use for this function.
            uint32_t groupSizeY,                            ///< [in] group size for Y dimension to use for this function.
            uint32_t groupSizeZ                             ///< [in] group size for Z dimension to use for this function.
            );

        ///////////////////////////////////////////////////////////////////////////////
        /// @brief C++ wrapper for ::xeFunctionSuggestGroupSize
        inline void SuggestGroupSize(
            uint32_t globalSizeX,                           ///< [in] global width for X dimension.
            uint32_t globalSizeY,                           ///< [in] global width for Y dimension.
            uint32_t globalSizeZ,                           ///< [in] global width for Z dimension.
            uint32_t* groupSizeX,                           ///< [out] recommended size of group for X dimension.
            uint32_t* groupSizeY,                           ///< [out] recommended size of group for Y dimension.
            uint32_t* groupSizeZ                            ///< [out] recommended size of group for Z dimension.
            );

        ///////////////////////////////////////////////////////////////////////////////
        /// @brief C++ wrapper for ::xeFunctionSetArgumentValue
        inline void SetArgumentValue(
            uint32_t argIndex,                              ///< [in] argument index in range [0, num args - 1]
            size_t argSize,                                 ///< [in] size of argument type
            const void* pArgValue                           ///< [in] argument value represented as matching arg type
            );

        ///////////////////////////////////////////////////////////////////////////////
        /// @brief C++ wrapper for ::xeFunctionSetAttribute
        inline void SetAttribute(
            function_set_attribute_t attr,                  ///< [in] attribute to set
            uint32_t value                                  ///< [in] attribute value to set
            );

        ///////////////////////////////////////////////////////////////////////////////
        /// @brief C++ wrapper for ::xeFunctionGetAttribute
        inline void GetAttribute(
            function_get_attribute_t attr,                  ///< [in] attribute to query
            uint32_t* pValue                                ///< [out] returned attribute value
            );

    };

} // namespace xe
#endif // defined(__cplusplus)
#endif // _XE_MODULE_HPP