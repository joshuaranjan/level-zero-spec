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
* @file xet_lib.h
*
******************************************************************************/
#pragma once
#include "xet_api.hpp"
#include "xet_ddi.h"
#include "xe_util.h"
#include "xe_singleton.h"
#include <vector>

namespace xet_lib
{
    using metric_group_factory_t = singleton_factory_t<xet::MetricGroup, xet::metric_group_handle_t>;
    using metric_factory_t = singleton_factory_t<xet::Metric, xet::metric_handle_t>;

    ///////////////////////////////////////////////////////////////////////////////
    class context_t
    {
    public:
        HMODULE loader = nullptr;

        context_t();
        ~context_t();

        xe_result_t Init();

        xet_dditable_t  ddiTable = {};

        metric_group_factory_t  metricGroupFactory;
        metric_factory_t        metricFactory;
    };

    extern context_t context;

} // namespace xet_lib