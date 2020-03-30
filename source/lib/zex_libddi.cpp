/*
 *
 * Copyright (C) 2019 Intel Corporation
 *
 * SPDX-License-Identifier: MIT
 *
 * @file zex_libddi.cpp
 * @version v0.91-275
 *
 */
#include "ze_lib.h"

namespace ze_lib
{
    ///////////////////////////////////////////////////////////////////////////////
    __zedlllocal ze_result_t context_t::zexInit()
    {
        ze_result_t result = ZE_RESULT_SUCCESS;

        if( ZE_RESULT_SUCCESS == result )
        {
            auto getTable = reinterpret_cast<zex_pfnGetCommandListProcAddrTable_t>(
                GET_FUNCTION_PTR(loader, "zexGetCommandListProcAddrTable") );
            result = getTable( ZE_API_VERSION_0_91, &zexDdiTable.CommandList );
        }

        if( ZE_RESULT_SUCCESS == result )
        {
            auto getTable = reinterpret_cast<zex_pfnGetCommandGraphProcAddrTable_t>(
                GET_FUNCTION_PTR(loader, "zexGetCommandGraphProcAddrTable") );
            result = getTable( ZE_API_VERSION_0_91, &zexDdiTable.CommandGraph );
        }

        return result;
    }
} // namespace ze_lib
