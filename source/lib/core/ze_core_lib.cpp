/*
 *
 * Copyright (C) 2019 Intel Corporation
 *
 * SPDX-License-Identifier: MIT
 *
 * @file ze_core_lib.cpp
 *
 * @cond DEV
 * DO NOT EDIT: generated from /scripts/templates/libddi.cpp.mako
 * @endcond
 *
 */
#include "ze_lib.h"

namespace ze_lib
{
    ///////////////////////////////////////////////////////////////////////////////
    __zedlllocal ze_result_t context_t::Init()
    {
        loader = LOAD_DRIVER_LIBRARY( MAKE_DRIVER_NAME( "ze_loader" ) );

        if( NULL == loader )
            return ZE_RESULT_ERROR_UNINITIALIZED;

        ze_result_t result = ZE_RESULT_SUCCESS;

        if( ZE_RESULT_SUCCESS == result )
        {
            auto getTable = reinterpret_cast<ze_pfnGetDriverProcAddrTable_t>(
                GET_FUNCTION_PTR(loader, "zeGetDriverProcAddrTable") );
            result = getTable( ZE_API_VERSION_0_91, &ddiTable.Driver );
        }

        if( ZE_RESULT_SUCCESS == result )
        {
            auto getTable = reinterpret_cast<ze_pfnGetGlobalProcAddrTable_t>(
                GET_FUNCTION_PTR(loader, "zeGetGlobalProcAddrTable") );
            result = getTable( ZE_API_VERSION_0_91, &ddiTable.Global );
        }

        if( ZE_RESULT_SUCCESS == result )
        {
            auto getTable = reinterpret_cast<ze_pfnGetDeviceProcAddrTable_t>(
                GET_FUNCTION_PTR(loader, "zeGetDeviceProcAddrTable") );
            result = getTable( ZE_API_VERSION_0_91, &ddiTable.Device );
        }

        if( ZE_RESULT_SUCCESS == result )
        {
            auto getTable = reinterpret_cast<ze_pfnGetCommandQueueProcAddrTable_t>(
                GET_FUNCTION_PTR(loader, "zeGetCommandQueueProcAddrTable") );
            result = getTable( ZE_API_VERSION_0_91, &ddiTable.CommandQueue );
        }

        if( ZE_RESULT_SUCCESS == result )
        {
            auto getTable = reinterpret_cast<ze_pfnGetCommandListProcAddrTable_t>(
                GET_FUNCTION_PTR(loader, "zeGetCommandListProcAddrTable") );
            result = getTable( ZE_API_VERSION_0_91, &ddiTable.CommandList );
        }

        if( ZE_RESULT_SUCCESS == result )
        {
            auto getTable = reinterpret_cast<ze_pfnGetFenceProcAddrTable_t>(
                GET_FUNCTION_PTR(loader, "zeGetFenceProcAddrTable") );
            result = getTable( ZE_API_VERSION_0_91, &ddiTable.Fence );
        }

        if( ZE_RESULT_SUCCESS == result )
        {
            auto getTable = reinterpret_cast<ze_pfnGetEventPoolProcAddrTable_t>(
                GET_FUNCTION_PTR(loader, "zeGetEventPoolProcAddrTable") );
            result = getTable( ZE_API_VERSION_0_91, &ddiTable.EventPool );
        }

        if( ZE_RESULT_SUCCESS == result )
        {
            auto getTable = reinterpret_cast<ze_pfnGetEventProcAddrTable_t>(
                GET_FUNCTION_PTR(loader, "zeGetEventProcAddrTable") );
            result = getTable( ZE_API_VERSION_0_91, &ddiTable.Event );
        }

        if( ZE_RESULT_SUCCESS == result )
        {
            auto getTable = reinterpret_cast<ze_pfnGetImageProcAddrTable_t>(
                GET_FUNCTION_PTR(loader, "zeGetImageProcAddrTable") );
            result = getTable( ZE_API_VERSION_0_91, &ddiTable.Image );
        }

        if( ZE_RESULT_SUCCESS == result )
        {
            auto getTable = reinterpret_cast<ze_pfnGetModuleProcAddrTable_t>(
                GET_FUNCTION_PTR(loader, "zeGetModuleProcAddrTable") );
            result = getTable( ZE_API_VERSION_0_91, &ddiTable.Module );
        }

        if( ZE_RESULT_SUCCESS == result )
        {
            auto getTable = reinterpret_cast<ze_pfnGetModuleBuildLogProcAddrTable_t>(
                GET_FUNCTION_PTR(loader, "zeGetModuleBuildLogProcAddrTable") );
            result = getTable( ZE_API_VERSION_0_91, &ddiTable.ModuleBuildLog );
        }

        if( ZE_RESULT_SUCCESS == result )
        {
            auto getTable = reinterpret_cast<ze_pfnGetKernelProcAddrTable_t>(
                GET_FUNCTION_PTR(loader, "zeGetKernelProcAddrTable") );
            result = getTable( ZE_API_VERSION_0_91, &ddiTable.Kernel );
        }

        if( ZE_RESULT_SUCCESS == result )
        {
            auto getTable = reinterpret_cast<ze_pfnGetSamplerProcAddrTable_t>(
                GET_FUNCTION_PTR(loader, "zeGetSamplerProcAddrTable") );
            result = getTable( ZE_API_VERSION_0_91, &ddiTable.Sampler );
        }

        return result;
    }
} // namespace ze_lib
