<%!
import re
from templates import helper as th

def declare_type(obj, cls, cli):
    if re.match(r"none", cls) and \
        not re.match(r"macro", obj['type']) and \
        not re.match(r"function", obj['type']):
        return True
    return re.match(r"handle", obj['type'])

%>/**************************************************************************//**
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
* @file ${x}_${name}.hpp
*
* @brief C++ wrapper of ${th.subx(x, header['desc'])}
*
* @cond DEV
* DO NOT EDIT: generated from /scripts/${type}/${name}.yml
* @endcond
*
******************************************************************************/
#ifndef _${X}_${name.upper()}_HPP
#define _${X}_${name.upper()}_HPP
#if defined(__cplusplus)
#pragma once
%if re.match(r"common", name):
#include "${x}_all.h"
%else:
#include "${x}_common.hpp"
%endif

namespace ${x}
{
%for obj in objects:
%for cli, cls in enumerate(obj['class']):
%if declare_type(obj, cls, cli):
    ///////////////////////////////////////////////////////////////////////////////
    %if 'condition' in obj:
    #if ${th.subx(x,obj['condition'])}
    %endif
    %for line in th.make_desc_lines(None, obj):
    /// ${line}
    %endfor
    %for line in th.make_details_lines(None, obj):
    /// ${line}
    %endfor
    ## TYPEDEF ####################################################################
    %if re.match(r"typedef", obj['type']):
    using ${th.subx(None, obj['name'])} = ::${th.subx(x, obj['name'])};
    ## ENUM #######################################################################
    %elif re.match(r"enum", obj['type']):
    enum class ${th.subx(None, obj['name'])}
    {
        %for line in th.make_etor_lines(None, obj, True, x, meta):
        ${line}
        %endfor

    };
    ## STRUCT #####################################################################
    %elif re.match(r"struct", obj['type']):
    struct ${th.subx(None, obj['name'])}
    {
        %for line in th.make_member_lines(None, obj, True, x, meta):
        ${line}
        %endfor

    };
    ## CLASS ###################################################################
    %elif re.match(r"class", obj['type']):
    class ${th.subx(None, obj['name'])}
    {
    protected:
        %for line in th.make_member_lines(x, obj):
        ::${line}
        %endfor

    public:
        %for t in th.filter_items(th.extract_objs(specs, "typedef"), 'class', obj['name']):
        ///////////////////////////////////////////////////////////////////////////////
        /// @brief C++ version for ::${th.subx(x, t['name'])}
        using ${th.subx(None, t['name'])} = ::${th.subx(x, t['name'])};

        %endfor
        %for e in th.filter_items(th.extract_objs(specs, "enum"), 'class', obj['name']):
        ///////////////////////////////////////////////////////////////////////////////
        /// @brief C++ version for ::${th.subx(x, e['name'])}
        enum class ${th.subx(None, e['name'])}
        {
            %for line in th.make_etor_lines(None, e, True, x, meta):
            ${line}
            %endfor

        };

        %endfor
        %for s in th.filter_items(th.extract_objs(specs, "struct"), 'class', obj['name']):
        ///////////////////////////////////////////////////////////////////////////////
        /// @brief C++ version for ::${th.subx(x, s['name'])}
        struct ${th.subx(None, s['name'])}
        {
            %for line in th.make_member_lines(None, s, True, x, meta):
            ${line}
            %endfor

        };

        %endfor
        %for f in th.filter_items(th.extract_objs(specs, "function"), 'class', obj['name']):
        ///////////////////////////////////////////////////////////////////////////////
        /// @brief C++ wrapper for ::${th.make_func_name(x, f, obj['name'])}
        inline void ${th.subx(None, f['name'])}(
            %for line in th.make_param_lines(None, f, 'this'):
            ${line}
            %endfor
            )
        {
            return ::${th.make_func_name(x, f, obj['name'])}( ${th.make_param_call_str("handle", None, f, 'this')} );
        }

        %endfor
    };
    ## HANDLE #####################################################################
    %elif re.match(r"handle", obj['type']):
    %if 'none' != cls:
    class ${th.subx(None, cls)};
    using ${th.subx(None, obj['name'])} = ${th.subx(None, cls)}*;
    %else:
    using ${th.subx(None, obj['name'])} = ::${th.subx(x, obj['name'])};
    %endif
    %endif
    %if 'condition' in obj:
    #endif // ${th.subx(x,obj['condition'])}
    %endif

%endif
%endfor
%endfor
} // namespace ${x}
#endif // defined(__cplusplus)
#endif // _${X}_${name.upper()}_HPP
