<%!
import re
from templates import helper as th

def declare_obj(obj, tags):
    if re.match(r"class", obj['type']):
        return True
    if 'class' not in obj or obj['class'] in tags:
        return re.match(r"function", obj['type'])
    return False

%><%
    n=namespace
    N=n.upper()

    x=tags['$x']
    X=x.upper()
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
* @file ${n}_${name}.cpp
*
* @brief C++ wrapper of ${th.subt(n, tags, header['desc'])}
*
* @cond DEV
* DO NOT EDIT: generated from /scripts/${section}/${name}.yml
* @endcond
*
******************************************************************************/
#include "${n}_api.hpp"

namespace ${n}
{
%for obj in objects:
%if declare_obj(obj, tags):
%if re.match(r"function", obj['type']):
    ## FUNCTION ###################################################################
    ///////////////////////////////////////////////////////////////////////////////
%if 'condition' in obj:
#if ${th.subt(n, tags, obj['condition'])}
%endif
    /// @brief C++ wrapper for ::${th.make_func_name(n, tags, obj)}
    %for line in th.make_details_lines(n, tags, obj, cpp=True):
    /// ${line}
    %endfor
    /// 
    %for line in th.make_returns_lines(n, tags, obj, cpp=True, meta=meta):
    /// ${line}
    %endfor
    inline ${th.make_return_value(n, tags, obj, cpp=True, meta=meta)} 
    ${th.make_func_name(n, tags, obj, cpp=True)}(
        %for line in th.make_param_lines(n, tags, obj, cpp=True, meta=meta):
        ${line}
        %endfor
        )
    {
        // auto result = ::${th.make_func_name(n, tags, obj)}( ${th.make_param_call_str(n, tags, "handle", obj, True)} );
        // if( ::${X}_RESULT_SUCCESS != result ) throw exception(result, "${th.subt(n, tags, obj['name'], cpp=True)}");
    }
%if 'condition' in obj:
#endif // ${th.subt(n, tags, obj['condition'])}
%endif

%elif re.match(r"class", obj['type']):
    ## CTORS/DTORS ################################################################
    %if 'base' not in obj:
    ///////////////////////////////////////////////////////////////////////////////
    ${th.make_class_name(n, tags, obj)}::${th.make_class_name(n, tags, obj)}( 
    %for line in th.make_ctor_param_lines(n, tags, obj, meta=meta):
        ${line}
    %endfor
        ) :
    %for line in th.make_ctor_param_init_lines(n, tags, obj, "m_"):
        ${line}
    %endfor
    {
    }

    %endif
    ## CLASS FUNCTION #############################################################
    %for f in th.filter_items(th.extract_objs(specs, r"function"), 'class', obj['name']):
    ///////////////////////////////////////////////////////////////////////////////
%if 'condition' in f:
#if ${th.subt(n, tags, f['condition'])}
%endif
    /// @brief C++ wrapper for ::${th.make_func_name(n, tags, f)}
    %for line in th.make_details_lines(n, tags, f, cpp=True):
    /// ${line}
    %endfor
    /// 
    %for line in th.make_returns_lines(n, tags, f, cpp=True, meta=meta):
    /// ${line}
    %endfor
    %if 'tparams' in f:
    template<${th.make_tparams_line(n, tags, f)}>
    %endif
    inline ${th.make_return_value(n, tags, f, cpp=True, meta=meta)} 
    ${th.subt(n, tags, obj['name'], cpp=True)}::${th.make_func_name(n, tags, f, cpp=True)}(
        %for line in th.make_param_lines(n, tags, f, cpp=True, meta=meta):
        ${line}
        %endfor
        )
    {
        // auto result = ::${th.make_func_name(n, tags, f)}( ${th.make_param_call_str(n, tags, "handle", f, True)} );
        // if( ::${X}_RESULT_SUCCESS != result ) throw exception(result, "${n}::${th.subt(n, tags, obj['name'], cpp=True)}::${th.subt(n, tags, f['name'], cpp=True)}");
    }
%if 'condition' in f:
#endif // ${th.subt(n, tags, f['condition'])}
%endif

    %endfor
%endif
%endif  # declare_obj
%endfor # obj in objects
} // namespace ${n}