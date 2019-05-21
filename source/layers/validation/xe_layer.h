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
* @file xe_layer.h
*
******************************************************************************/
#ifndef _XE_LAYER_H
#define _XE_LAYER_H
#if defined(__cplusplus)
#pragma once
#endif
#include "xe_ddi.h"
#include "xex_ddi.h"
#include "xet_ddi.h"
#include "xe_util.h"

namespace xe_layer
{
    ///////////////////////////////////////////////////////////////////////////////
    class Validation
    {
    public:
        xe_api_version_t version = XE_API_VERSION_1_0;

        bool enableParameterValidation = false;
        bool enableHandleLifetime = false;
        bool enableMemoryTracker = false;
        bool enableThreadingValidation = false;

        xe_dditable_t   xeDdiTable = {};
        xex_dditable_t  xexDdiTable = {};
        xet_dditable_t  xetDdiTable = {};

        Validation();
        ~Validation();
    };

    extern Validation val;

} // namespace xe_layer
#endif // _XE_LAYER_H