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
* @file loader.cpp
*
******************************************************************************/
#include <mutex>
#include <stdlib.h>

#include "loader.h"
#include "core_loader.h"
#include "extended_loader.h"
#include "tools_loader.h"

namespace xe_loader
{
    ///////////////////////////////////////////////////////////////////////////////
    xeapi_pfntable_t  xeapi_pfntable = {};
    xexapi_pfntable_t xexapi_pfntable = {};
    xetapi_pfntable_t xetapi_pfntable = {};

    ///////////////////////////////////////////////////////////////////////////////
    context_t context = {
        &xeapi_pfntable,    // xeapi
        &xexapi_pfntable,   // xexapi
        &xetapi_pfntable,   // xetapi

        false   // initialized
    };

} // namespace xe_loader

///////////////////////////////////////////////////////////////////////////////
typedef xe_result_t( __xecall *pfn_xeInitLayer_t )(
    xeapi_pfntable_ptr_t,
    xexapi_pfntable_ptr_t,
    xetapi_pfntable_ptr_t
    );


#if defined(__cplusplus)
extern "C" {
#endif

///////////////////////////////////////////////////////////////////////////////
__xedllexport xe_result_t __xecall
xeInit(
    xe_init_flag_t flags ){

    static std::mutex crit;
    std::lock_guard<std::mutex> lockGuard{crit};
        
    if(xe_loader::context.initialized)
        return XE_RESULT_SUCCESS;
        
    auto driverLibrary = LOAD_DRIVER_LIBRARY("xe_common"); // persistent handle

    xe_loader::context.initialized =
        xe_loader::xeLoadExports(driverLibrary) &&
        xe_loader::xexLoadExports(driverLibrary) &&
        xe_loader::xetLoadExports(driverLibrary);
            
    if(false == xe_loader::context.initialized)
        return XE_RESULT_ERROR_UNINITIALIZED;

    const char* env_var = getenv( "XE_ENABLE_VALIDATION_LAYER" );
    if((nullptr != env_var) && (0 != atoi(env_var))){
        auto validationLayer = LOAD_DRIVER_LIBRARY("xe_validation_layer");
        auto xeInitLayer = (pfn_xeInitLayer_t)LOAD_FUNCTION_PTR(validationLayer, "xeInitLayer");
        xeInitLayer(xe_loader::context.xeapi, xe_loader::context.xexapi, xe_loader::context.xetapi);
    }

    return xe_loader::context.xeapi->xeInit(flags);
}

#if defined(__cplusplus)
};
#endif
