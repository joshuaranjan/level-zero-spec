<%
import re
from templates import helper as th
%><%
    n=namespace
    N=n.upper()

    x=tags['$x']
%>/**************************************************************************//**
*
* INTEL CONFIDENTIAL
* Copyright 2019
* Intel Corporation All Rights Reserved.
*
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
*
* @file ${n}_ddi.h
*
* @cond DEV
* DO NOT EDIT: generated from /scripts/${section}
* @endcond
*
******************************************************************************/
#ifndef _${N}_DDI_H
#define _${N}_DDI_H
#if defined(__cplusplus)
#pragma once
#endif
#include "${n}_api.h"

%for obj in th.extract_objs(specs, r"function"):
///////////////////////////////////////////////////////////////////////////////
%if 'condition' in obj:
#if ${th.subt(n, tags, obj['condition'])}
%endif
/// @brief ${th.make_func_name(n, tags, obj)} function-pointer
typedef ${x}_result_t (__${x}call *${th.make_pfn_type(n, tags, obj)})(
    %for line in th.make_param_lines(n, tags, obj, format=["type", "delim"]):
    ${line}
    %endfor
    );
%if 'condition' in obj:
#endif // ${th.subt(n, tags, obj['condition'])}
%endif

%endfor

///////////////////////////////////////////////////////////////////////////////
typedef struct _${n}_apitable_t
{
    %for obj in th.extract_objs(specs, r"function"):
    %if 'condition' in obj:
    #if ${th.subt(n, tags, obj['condition'])}
    %endif
    ${th.append_ws(th.make_pfn_type(n, tags, obj), 47)} ${th.make_pfn_name(n, tags, obj)};
    %if 'condition' in obj:
    #endif // ${th.subt(n, tags, obj['condition'])}
    %endif
    %endfor
} ${n}_apitable_t;

#endif // _${N}_DDI_H