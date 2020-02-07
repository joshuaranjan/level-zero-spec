/*
 *
 * Copyright (C) 2019 Intel Corporation
 *
 * SPDX-License-Identifier: MIT
 *
 * @file zex_driver.cpp
 *
 * @brief C++ wrapper of Intel 'One API' Level-Zero APIs
 *
 * @cond DEV
 * DO NOT EDIT: generated from /scripts/experimental/driver.yml
 * @endcond
 *
 */
#include "zex_api.hpp"
#include "ze_singleton.h"

#define _STRING(s) #s
#define STRING(s) _STRING(s)

namespace zex
{
    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Initialize the 'One API' driver and must be called before any other
    ///        API function.
    /// 
    /// @details
    ///     - If this function is not called then all other functions will return
    ///       ::ZE_RESULT_ERROR_UNINITIALIZED.
    ///     - Only one instance of a driver per process will be initialized.
    ///     - This function is thread-safe for scenarios where multiple libraries
    ///       may initialize the driver simultaneously.
    /// 
    /// @remarks
    ///   _Analogues_
    ///     - **cuInit**
    /// 
    /// @throws result_t
    void __zecall
    Init(
        ze::init_flag_t flags                           ///< [in] initialization flags
        )
    {
        auto result = static_cast<result_t>( ::zexInit(
            static_cast<ze_init_flag_t>( flags ) ) );

        if( result_t::SUCCESS != result )
            throw exception_t( result, __FILE__, STRING(__LINE__), "zex::::Init" );
    }

} // namespace zex

namespace zex
{
} // namespace zex