/*
 *
 * Copyright (C) 2019 Intel Corporation
 *
 * SPDX-License-Identifier: MIT
 *
 * @file ze_null.h
 *
 */
#pragma once
#include <stdlib.h>
#include <vector>
#include "ze_ddi.h"
#include "zet_ddi.h"
#ifdef ZE_EXPERIMENTAL
#include "zex_ddi.h"
#endif
#include "ze_util.h"

namespace driver
{
    ///////////////////////////////////////////////////////////////////////////////
    class __zedlllocal context_t
    {
    public:
        ze_api_version_t version = ZE_API_VERSION_0_91;

        ze_dditable_t   zeDdiTable = {};
        zet_dditable_t  zetDdiTable = {};
#ifdef ZE_EXPERIMENTAL
        zex_dditable_t  zexDdiTable = {};
#endif
        context_t();
        ~context_t() = default;

        void* get( void )
        {
            static uint64_t count = 0x80800000;
            return reinterpret_cast<void*>( ++count );
        }
    };

    extern context_t context;
} // namespace driver

namespace instrumented
{
    //////////////////////////////////////////////////////////////////////////
    struct tracer_data_t
    {
        ze_bool_t enabled = false;

        void* userData = nullptr;

        ze_callbacks_t zePrologueCbs = {};
        ze_callbacks_t zeEpilogueCbs = {};

#ifdef ZE_EXPERIMENTAL
        zex_callbacks_t zexPrologueCbs = {};
        zex_callbacks_t zexEpilogueCbs = {};
#endif
    };

    ///////////////////////////////////////////////////////////////////////////////
    class __zedlllocal context_t
    {
    public:
        ze_bool_t enableTracing = false;
        std::vector< tracer_data_t > tracerData;

        context_t();
        ~context_t() = default;
    };

    extern context_t context;
} // namespace instrumented
