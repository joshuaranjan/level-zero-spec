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
* @file tools_layer.cpp
*
* @cond DEV
* DO NOT EDIT: generated from /scripts/templates/validation.cpp.mako
* @endcond
*
******************************************************************************/
#include "layer.h"

extern xe_layer context;

#if defined(__cplusplus)
extern "C" {
#endif

///////////////////////////////////////////////////////////////////////////////
/// @brief Exported function for filling application's Device table
///        with current process' addresses
///
/// @returns
///     - ::XE_RESULT_SUCCESS
///     - ::XE_RESULT_ERROR_INVALID_PARAMETER
///         + invalid value for version
///         + nullptr for ptable
///     - ::XE_RESULT_ERROR_UNSUPPORTED
///         + version not supported
__xedllexport xe_result_t __xecall
xetGetDeviceProcAddrTable(
    uint32_t version,           ///< [in] ::XE_API_HEADER_VERSION
    xet_device_apitable_t* ptable      ///< [in,out] pointer to table of API function pointers
    )
{
    if( nullptr == ptable )
        return XE_RESULT_ERROR_INVALID_PARAMETER;

    if( XE_API_HEADER_VERSION < version )
        return XE_RESULT_ERROR_UNSUPPORTED;

    xe_result_t result = XE_RESULT_SUCCESS;

    context.xetDevice.pfnActivateMetricGroups                                 = ptable->pfnActivateMetricGroups;
    ptable->pfnActivateMetricGroups                                           = xetDeviceActivateMetricGroups;

    context.xetDevice.pfnPowerInit                                            = ptable->pfnPowerInit;
    ptable->pfnPowerInit                                                      = xetDevicePowerInit;

    return result;
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Exported function for filling application's CommandList table
///        with current process' addresses
///
/// @returns
///     - ::XE_RESULT_SUCCESS
///     - ::XE_RESULT_ERROR_INVALID_PARAMETER
///         + invalid value for version
///         + nullptr for ptable
///     - ::XE_RESULT_ERROR_UNSUPPORTED
///         + version not supported
__xedllexport xe_result_t __xecall
xetGetCommandListProcAddrTable(
    uint32_t version,           ///< [in] ::XE_API_HEADER_VERSION
    xet_command_list_apitable_t* ptable      ///< [in,out] pointer to table of API function pointers
    )
{
    if( nullptr == ptable )
        return XE_RESULT_ERROR_INVALID_PARAMETER;

    if( XE_API_HEADER_VERSION < version )
        return XE_RESULT_ERROR_UNSUPPORTED;

    xe_result_t result = XE_RESULT_SUCCESS;

    context.xetCommandList.pfnAppendMetricTracerMarker                             = ptable->pfnAppendMetricTracerMarker;
    ptable->pfnAppendMetricTracerMarker                                            = xetCommandListAppendMetricTracerMarker;

    context.xetCommandList.pfnAppendMetricQueryBegin                               = ptable->pfnAppendMetricQueryBegin;
    ptable->pfnAppendMetricQueryBegin                                              = xetCommandListAppendMetricQueryBegin;

    context.xetCommandList.pfnAppendMetricQueryEnd                                 = ptable->pfnAppendMetricQueryEnd;
    ptable->pfnAppendMetricQueryEnd                                                = xetCommandListAppendMetricQueryEnd;

    context.xetCommandList.pfnAppendMetricMemoryBarrier                            = ptable->pfnAppendMetricMemoryBarrier;
    ptable->pfnAppendMetricMemoryBarrier                                           = xetCommandListAppendMetricMemoryBarrier;

    return result;
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Exported function for filling application's MetricGroup table
///        with current process' addresses
///
/// @returns
///     - ::XE_RESULT_SUCCESS
///     - ::XE_RESULT_ERROR_INVALID_PARAMETER
///         + invalid value for version
///         + nullptr for ptable
///     - ::XE_RESULT_ERROR_UNSUPPORTED
///         + version not supported
__xedllexport xe_result_t __xecall
xetGetMetricGroupProcAddrTable(
    uint32_t version,           ///< [in] ::XE_API_HEADER_VERSION
    xet_metric_group_apitable_t* ptable      ///< [in,out] pointer to table of API function pointers
    )
{
    if( nullptr == ptable )
        return XE_RESULT_ERROR_INVALID_PARAMETER;

    if( XE_API_HEADER_VERSION < version )
        return XE_RESULT_ERROR_UNSUPPORTED;

    xe_result_t result = XE_RESULT_SUCCESS;

    context.xetMetricGroup.pfnGetCount                                             = ptable->pfnGetCount;
    ptable->pfnGetCount                                                            = xetMetricGroupGetCount;

    context.xetMetricGroup.pfnGet                                                  = ptable->pfnGet;
    ptable->pfnGet                                                                 = xetMetricGroupGet;

    context.xetMetricGroup.pfnGetProperties                                        = ptable->pfnGetProperties;
    ptable->pfnGetProperties                                                       = xetMetricGroupGetProperties;

    context.xetMetricGroup.pfnCalculateData                                        = ptable->pfnCalculateData;
    ptable->pfnCalculateData                                                       = xetMetricGroupCalculateData;

    return result;
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Exported function for filling application's Metric table
///        with current process' addresses
///
/// @returns
///     - ::XE_RESULT_SUCCESS
///     - ::XE_RESULT_ERROR_INVALID_PARAMETER
///         + invalid value for version
///         + nullptr for ptable
///     - ::XE_RESULT_ERROR_UNSUPPORTED
///         + version not supported
__xedllexport xe_result_t __xecall
xetGetMetricProcAddrTable(
    uint32_t version,           ///< [in] ::XE_API_HEADER_VERSION
    xet_metric_apitable_t* ptable      ///< [in,out] pointer to table of API function pointers
    )
{
    if( nullptr == ptable )
        return XE_RESULT_ERROR_INVALID_PARAMETER;

    if( XE_API_HEADER_VERSION < version )
        return XE_RESULT_ERROR_UNSUPPORTED;

    xe_result_t result = XE_RESULT_SUCCESS;

    context.xetMetric.pfnGet                                                  = ptable->pfnGet;
    ptable->pfnGet                                                            = xetMetricGet;

    context.xetMetric.pfnGetProperties                                        = ptable->pfnGetProperties;
    ptable->pfnGetProperties                                                  = xetMetricGetProperties;

    return result;
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Exported function for filling application's MetricTracer table
///        with current process' addresses
///
/// @returns
///     - ::XE_RESULT_SUCCESS
///     - ::XE_RESULT_ERROR_INVALID_PARAMETER
///         + invalid value for version
///         + nullptr for ptable
///     - ::XE_RESULT_ERROR_UNSUPPORTED
///         + version not supported
__xedllexport xe_result_t __xecall
xetGetMetricTracerProcAddrTable(
    uint32_t version,           ///< [in] ::XE_API_HEADER_VERSION
    xet_metric_tracer_apitable_t* ptable      ///< [in,out] pointer to table of API function pointers
    )
{
    if( nullptr == ptable )
        return XE_RESULT_ERROR_INVALID_PARAMETER;

    if( XE_API_HEADER_VERSION < version )
        return XE_RESULT_ERROR_UNSUPPORTED;

    xe_result_t result = XE_RESULT_SUCCESS;

    context.xetMetricTracer.pfnOpen                                                 = ptable->pfnOpen;
    ptable->pfnOpen                                                                 = xetMetricTracerOpen;

    context.xetMetricTracer.pfnClose                                                = ptable->pfnClose;
    ptable->pfnClose                                                                = xetMetricTracerClose;

    context.xetMetricTracer.pfnReadData                                             = ptable->pfnReadData;
    ptable->pfnReadData                                                             = xetMetricTracerReadData;

    return result;
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Exported function for filling application's MetricQueryPool table
///        with current process' addresses
///
/// @returns
///     - ::XE_RESULT_SUCCESS
///     - ::XE_RESULT_ERROR_INVALID_PARAMETER
///         + invalid value for version
///         + nullptr for ptable
///     - ::XE_RESULT_ERROR_UNSUPPORTED
///         + version not supported
__xedllexport xe_result_t __xecall
xetGetMetricQueryPoolProcAddrTable(
    uint32_t version,           ///< [in] ::XE_API_HEADER_VERSION
    xet_metric_query_pool_apitable_t* ptable      ///< [in,out] pointer to table of API function pointers
    )
{
    if( nullptr == ptable )
        return XE_RESULT_ERROR_INVALID_PARAMETER;

    if( XE_API_HEADER_VERSION < version )
        return XE_RESULT_ERROR_UNSUPPORTED;

    xe_result_t result = XE_RESULT_SUCCESS;

    context.xetMetricQueryPool.pfnCreate                                               = ptable->pfnCreate;
    ptable->pfnCreate                                                                  = xetMetricQueryPoolCreate;

    context.xetMetricQueryPool.pfnDestroy                                              = ptable->pfnDestroy;
    ptable->pfnDestroy                                                                 = xetMetricQueryPoolDestroy;

    context.xetMetricQueryPool.pfnGetMetricQuery                                       = ptable->pfnGetMetricQuery;
    ptable->pfnGetMetricQuery                                                          = xetMetricQueryPoolGetMetricQuery;

    return result;
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Exported function for filling application's MetricQuery table
///        with current process' addresses
///
/// @returns
///     - ::XE_RESULT_SUCCESS
///     - ::XE_RESULT_ERROR_INVALID_PARAMETER
///         + invalid value for version
///         + nullptr for ptable
///     - ::XE_RESULT_ERROR_UNSUPPORTED
///         + version not supported
__xedllexport xe_result_t __xecall
xetGetMetricQueryProcAddrTable(
    uint32_t version,           ///< [in] ::XE_API_HEADER_VERSION
    xet_metric_query_apitable_t* ptable      ///< [in,out] pointer to table of API function pointers
    )
{
    if( nullptr == ptable )
        return XE_RESULT_ERROR_INVALID_PARAMETER;

    if( XE_API_HEADER_VERSION < version )
        return XE_RESULT_ERROR_UNSUPPORTED;

    xe_result_t result = XE_RESULT_SUCCESS;

    context.xetMetricQuery.pfnGetData                                              = ptable->pfnGetData;
    ptable->pfnGetData                                                             = xetMetricQueryGetData;

    return result;
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Exported function for filling application's Power table
///        with current process' addresses
///
/// @returns
///     - ::XE_RESULT_SUCCESS
///     - ::XE_RESULT_ERROR_INVALID_PARAMETER
///         + invalid value for version
///         + nullptr for ptable
///     - ::XE_RESULT_ERROR_UNSUPPORTED
///         + version not supported
__xedllexport xe_result_t __xecall
xetGetPowerProcAddrTable(
    uint32_t version,           ///< [in] ::XE_API_HEADER_VERSION
    xet_power_apitable_t* ptable      ///< [in,out] pointer to table of API function pointers
    )
{
    if( nullptr == ptable )
        return XE_RESULT_ERROR_INVALID_PARAMETER;

    if( XE_API_HEADER_VERSION < version )
        return XE_RESULT_ERROR_UNSUPPORTED;

    xe_result_t result = XE_RESULT_SUCCESS;

    context.xetPower.pfnShutdown                                             = ptable->pfnShutdown;
    ptable->pfnShutdown                                                      = xetPowerShutdown;

    context.xetPower.pfnGetAveragePowerLimit                                 = ptable->pfnGetAveragePowerLimit;
    ptable->pfnGetAveragePowerLimit                                          = xetPowerGetAveragePowerLimit;

    context.xetPower.pfnGetBurstPowerLimit                                   = ptable->pfnGetBurstPowerLimit;
    ptable->pfnGetBurstPowerLimit                                            = xetPowerGetBurstPowerLimit;

    context.xetPower.pfnGetPeakPowerLimit                                    = ptable->pfnGetPeakPowerLimit;
    ptable->pfnGetPeakPowerLimit                                             = xetPowerGetPeakPowerLimit;

    context.xetPower.pfnGetAllPowerLimits                                    = ptable->pfnGetAllPowerLimits;
    ptable->pfnGetAllPowerLimits                                             = xetPowerGetAllPowerLimits;

    context.xetPower.pfnGetDefaultPowerLimits                                = ptable->pfnGetDefaultPowerLimits;
    ptable->pfnGetDefaultPowerLimits                                         = xetPowerGetDefaultPowerLimits;

    context.xetPower.pfnSetAveragePowerLimit                                 = ptable->pfnSetAveragePowerLimit;
    ptable->pfnSetAveragePowerLimit                                          = xetPowerSetAveragePowerLimit;

    context.xetPower.pfnSetBurstPowerLimit                                   = ptable->pfnSetBurstPowerLimit;
    ptable->pfnSetBurstPowerLimit                                            = xetPowerSetBurstPowerLimit;

    context.xetPower.pfnSetPeakPowerLimit                                    = ptable->pfnSetPeakPowerLimit;
    ptable->pfnSetPeakPowerLimit                                             = xetPowerSetPeakPowerLimit;

    context.xetPower.pfnSetPowerLimits                                       = ptable->pfnSetPowerLimits;
    ptable->pfnSetPowerLimits                                                = xetPowerSetPowerLimits;

    context.xetPower.pfnGetEnergyCounter                                     = ptable->pfnGetEnergyCounter;
    ptable->pfnGetEnergyCounter                                              = xetPowerGetEnergyCounter;

    context.xetPower.pfnGetTurboMode                                         = ptable->pfnGetTurboMode;
    ptable->pfnGetTurboMode                                                  = xetPowerGetTurboMode;

    context.xetPower.pfnSetTurboMode                                         = ptable->pfnSetTurboMode;
    ptable->pfnSetTurboMode                                                  = xetPowerSetTurboMode;

    context.xetPower.pfnFreqDomainCount                                      = ptable->pfnFreqDomainCount;
    ptable->pfnFreqDomainCount                                               = xetPowerFreqDomainCount;

    context.xetPower.pfnFreqDomainGetHandle                                  = ptable->pfnFreqDomainGetHandle;
    ptable->pfnFreqDomainGetHandle                                           = xetPowerFreqDomainGetHandle;

    context.xetPower.pfnFreqDomainGetProperties                              = ptable->pfnFreqDomainGetProperties;
    ptable->pfnFreqDomainGetProperties                                       = xetPowerFreqDomainGetProperties;

    context.xetPower.pfnFreqDomainGetSupportedClocks                         = ptable->pfnFreqDomainGetSupportedClocks;
    ptable->pfnFreqDomainGetSupportedClocks                                  = xetPowerFreqDomainGetSupportedClocks;

    context.xetPower.pfnFreqDomainGetSupportedClockDividers                  = ptable->pfnFreqDomainGetSupportedClockDividers;
    ptable->pfnFreqDomainGetSupportedClockDividers                           = xetPowerFreqDomainGetSupportedClockDividers;

    context.xetPower.pfnxetPowerFreqDomainGetClockRange                      = ptable->pfnxetPowerFreqDomainGetClockRange;
    ptable->pfnxetPowerFreqDomainGetClockRange                               = xetPowerxetPowerFreqDomainGetClockRange;

    context.xetPower.pfnxetPowerFreqDomainSetClockRange                      = ptable->pfnxetPowerFreqDomainSetClockRange;
    ptable->pfnxetPowerFreqDomainSetClockRange                               = xetPowerxetPowerFreqDomainSetClockRange;

    context.xetPower.pfnFreqDomainSetClockDivider                            = ptable->pfnFreqDomainSetClockDivider;
    ptable->pfnFreqDomainSetClockDivider                                     = xetPowerFreqDomainSetClockDivider;

    context.xetPower.pfnGetCurrentFrequency                                  = ptable->pfnGetCurrentFrequency;
    ptable->pfnGetCurrentFrequency                                           = xetPowerGetCurrentFrequency;

    context.xetPower.pfnFanCount                                             = ptable->pfnFanCount;
    ptable->pfnFanCount                                                      = xetPowerFanCount;

    context.xetPower.pfnFanGetProperties                                     = ptable->pfnFanGetProperties;
    ptable->pfnFanGetProperties                                              = xetPowerFanGetProperties;

    context.xetPower.pfnFanGetSpeedTable                                     = ptable->pfnFanGetSpeedTable;
    ptable->pfnFanGetSpeedTable                                              = xetPowerFanGetSpeedTable;

    context.xetPower.pfnFanSetSpeedTable                                     = ptable->pfnFanSetSpeedTable;
    ptable->pfnFanSetSpeedTable                                              = xetPowerFanSetSpeedTable;

    context.xetPower.pfnFanGetSpeed                                          = ptable->pfnFanGetSpeed;
    ptable->pfnFanGetSpeed                                                   = xetPowerFanGetSpeed;

    context.xetPower.pfnFanSetSpeed                                          = ptable->pfnFanSetSpeed;
    ptable->pfnFanSetSpeed                                                   = xetPowerFanSetSpeed;

    context.xetPower.pfnTemperatureSensorCount                               = ptable->pfnTemperatureSensorCount;
    ptable->pfnTemperatureSensorCount                                        = xetPowerTemperatureSensorCount;

    context.xetPower.pfnGetTemperatureProperties                             = ptable->pfnGetTemperatureProperties;
    ptable->pfnGetTemperatureProperties                                      = xetPowerGetTemperatureProperties;

    context.xetPower.pfnGetTemperature                                       = ptable->pfnGetTemperature;
    ptable->pfnGetTemperature                                                = xetPowerGetTemperature;

    context.xetPower.pfnSetTemperatureThreshold                              = ptable->pfnSetTemperatureThreshold;
    ptable->pfnSetTemperatureThreshold                                       = xetPowerSetTemperatureThreshold;

    context.xetPower.pfnActivityCount                                        = ptable->pfnActivityCount;
    ptable->pfnActivityCount                                                 = xetPowerActivityCount;

    context.xetPower.pfnGetActivityProperties                                = ptable->pfnGetActivityProperties;
    ptable->pfnGetActivityProperties                                         = xetPowerGetActivityProperties;

    context.xetPower.pfnGetActivityCounters                                  = ptable->pfnGetActivityCounters;
    ptable->pfnGetActivityCounters                                           = xetPowerGetActivityCounters;

    return result;
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Intercept function for xetMetricGroupGetCount
xe_result_t __xecall
xetMetricGroupGetCount(
    xe_device_handle_t hDevice,                     ///< [in] handle of the device object
    uint32_t* pCount                                ///< [out] number of metric groups supported by the device
    )
{
    if( context.enableParameterValidation )
    {
        if( nullptr == hDevice )
            return XE_RESULT_ERROR_INVALID_PARAMETER;

        if( nullptr == pCount )
            return XE_RESULT_ERROR_INVALID_PARAMETER;

    }

    return context.xetMetricGroup.pfnGetCount( hDevice, pCount );
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Intercept function for xetMetricGroupGet
xe_result_t __xecall
xetMetricGroupGet(
    xe_device_handle_t hDevice,                     ///< [in] handle of the device
    uint32_t ordinal,                               ///< [in] metric group index
    xet_metric_group_handle_t* phMetricGroup        ///< [out] metric group handle
    )
{
    if( context.enableParameterValidation )
    {
        if( nullptr == hDevice )
            return XE_RESULT_ERROR_INVALID_PARAMETER;

        if( nullptr == phMetricGroup )
            return XE_RESULT_ERROR_INVALID_PARAMETER;

    }

    return context.xetMetricGroup.pfnGet( hDevice, ordinal, phMetricGroup );
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Intercept function for xetMetricGroupGetProperties
xe_result_t __xecall
xetMetricGroupGetProperties(
    xet_metric_group_handle_t hMetricGroup,         ///< [in] handle of the metric group
    xet_metric_group_properties_t* pProperties      ///< [out] metric group properties
    )
{
    if( context.enableParameterValidation )
    {
        if( nullptr == hMetricGroup )
            return XE_RESULT_ERROR_INVALID_PARAMETER;

        if( nullptr == pProperties )
            return XE_RESULT_ERROR_INVALID_PARAMETER;

    }

    return context.xetMetricGroup.pfnGetProperties( hMetricGroup, pProperties );
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Intercept function for xetMetricGet
xe_result_t __xecall
xetMetricGet(
    xet_metric_group_handle_t hMetricGroup,         ///< [in] handle of the metric group
    uint32_t ordinal,                               ///< [in] metric index
    xet_metric_handle_t* phMetric                   ///< [out] handle of metric
    )
{
    if( context.enableParameterValidation )
    {
        if( nullptr == hMetricGroup )
            return XE_RESULT_ERROR_INVALID_PARAMETER;

        if( nullptr == phMetric )
            return XE_RESULT_ERROR_INVALID_PARAMETER;

    }

    return context.xetMetric.pfnGet( hMetricGroup, ordinal, phMetric );
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Intercept function for xetMetricGetProperties
xe_result_t __xecall
xetMetricGetProperties(
    xet_metric_handle_t hMetric,                    ///< [in] handle of the metric
    xet_metric_properties_t* pProperties            ///< [out] metric properties
    )
{
    if( context.enableParameterValidation )
    {
        if( nullptr == hMetric )
            return XE_RESULT_ERROR_INVALID_PARAMETER;

        if( nullptr == pProperties )
            return XE_RESULT_ERROR_INVALID_PARAMETER;

    }

    return context.xetMetric.pfnGetProperties( hMetric, pProperties );
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Intercept function for xetMetricGroupCalculateData
xe_result_t __xecall
xetMetricGroupCalculateData(
    xet_metric_group_handle_t hMetricGroup,         ///< [in] handle of the metric group
    uint32_t* pReportCount,                         ///< [in,out] report count to calculate
    uint32_t rawDataSize,                           ///< [in] raw data size
    uint8_t* pRawData,                              ///< [in] raw data to calculate
    uint32_t calculatedDataSize,                    ///< [in] calculated data size
    xet_typed_value_t* pCalculatedData              ///< [in,out] calculated metrics
    )
{
    if( context.enableParameterValidation )
    {
        if( nullptr == hMetricGroup )
            return XE_RESULT_ERROR_INVALID_PARAMETER;

        if( nullptr == pReportCount )
            return XE_RESULT_ERROR_INVALID_PARAMETER;

        if( nullptr == pRawData )
            return XE_RESULT_ERROR_INVALID_PARAMETER;

        if( nullptr == pCalculatedData )
            return XE_RESULT_ERROR_INVALID_PARAMETER;

    }

    return context.xetMetricGroup.pfnCalculateData( hMetricGroup, pReportCount, rawDataSize, pRawData, calculatedDataSize, pCalculatedData );
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Intercept function for xetDeviceActivateMetricGroups
xe_result_t __xecall
xetDeviceActivateMetricGroups(
    xe_device_handle_t hDevice,                     ///< [in] handle of the device
    uint32_t count,                                 ///< [in] metric group count to activate. 0 to deactivate.
    xet_metric_group_handle_t* phMetricGroups       ///< [in] handles of the metric groups to activate. NULL to deactivate.
    )
{
    if( context.enableParameterValidation )
    {
        if( nullptr == hDevice )
            return XE_RESULT_ERROR_INVALID_PARAMETER;

        if( nullptr == phMetricGroups )
            return XE_RESULT_ERROR_INVALID_PARAMETER;

    }

    return context.xetDevice.pfnActivateMetricGroups( hDevice, count, phMetricGroups );
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Intercept function for xetMetricTracerOpen
xe_result_t __xecall
xetMetricTracerOpen(
    xe_device_handle_t hDevice,                     ///< [in] handle of the device
    xet_metric_tracer_desc_t* pDesc,                ///< [in,out] metric tracer descriptor
    xe_event_handle_t hNotificationEvent,           ///< [in] event used for report availability notification. Must be device
                                                    ///< to host type.
    xet_metric_tracer_handle_t* phMetricTracer      ///< [out] handle of metric tracer
    )
{
    if( context.enableParameterValidation )
    {
        if( nullptr == hDevice )
            return XE_RESULT_ERROR_INVALID_PARAMETER;

        if( nullptr == pDesc )
            return XE_RESULT_ERROR_INVALID_PARAMETER;

        if( nullptr == hNotificationEvent )
            return XE_RESULT_ERROR_INVALID_PARAMETER;

        if( nullptr == phMetricTracer )
            return XE_RESULT_ERROR_INVALID_PARAMETER;

        if( XET_METRIC_TRACER_DESC_VERSION_CURRENT < pDesc->version )
            return XE_RESULT_ERROR_UNSUPPORTED;

    }

    return context.xetMetricTracer.pfnOpen( hDevice, pDesc, hNotificationEvent, phMetricTracer );
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Intercept function for xetCommandListAppendMetricTracerMarker
xe_result_t __xecall
xetCommandListAppendMetricTracerMarker(
    xe_command_list_handle_t hCommandList,          ///< [in] handle of the command list
    xet_metric_tracer_handle_t hMetricTracer,       ///< [in] handle of the metric tracer
    uint32_t value                                  ///< [in] tracer marker value
    )
{
    if( context.enableParameterValidation )
    {
        if( nullptr == hCommandList )
            return XE_RESULT_ERROR_INVALID_PARAMETER;

        if( nullptr == hMetricTracer )
            return XE_RESULT_ERROR_INVALID_PARAMETER;

    }

    return context.xetCommandList.pfnAppendMetricTracerMarker( hCommandList, hMetricTracer, value );
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Intercept function for xetMetricTracerClose
xe_result_t __xecall
xetMetricTracerClose(
    xet_metric_tracer_handle_t hMetricTracer        ///< [in] handle of the metric tracer
    )
{
    if( context.enableParameterValidation )
    {
        if( nullptr == hMetricTracer )
            return XE_RESULT_ERROR_INVALID_PARAMETER;

    }

    return context.xetMetricTracer.pfnClose( hMetricTracer );
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Intercept function for xetMetricTracerReadData
xe_result_t __xecall
xetMetricTracerReadData(
    xet_metric_tracer_handle_t hMetricTracer,       ///< [in] handle of the metric tracer
    uint32_t* pReportCount,                         ///< [in,out] report count to read/returned
    uint32_t rawDataSize,                           ///< [in] raw data buffer size
    uint8_t* pRawData                               ///< [in,out] raw data buffer for reports
    )
{
    if( context.enableParameterValidation )
    {
        if( nullptr == hMetricTracer )
            return XE_RESULT_ERROR_INVALID_PARAMETER;

        if( nullptr == pReportCount )
            return XE_RESULT_ERROR_INVALID_PARAMETER;

        if( nullptr == pRawData )
            return XE_RESULT_ERROR_INVALID_PARAMETER;

    }

    return context.xetMetricTracer.pfnReadData( hMetricTracer, pReportCount, rawDataSize, pRawData );
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Intercept function for xetMetricQueryPoolCreate
xe_result_t __xecall
xetMetricQueryPoolCreate(
    xe_device_handle_t hDevice,                     ///< [in] handle of the device
    xet_metric_query_pool_desc_t* pDesc,            ///< [in] metric query pool creation data
    xet_metric_query_pool_handle_t* phMetricQueryPool   ///< [out] handle of metric query pool
    )
{
    if( context.enableParameterValidation )
    {
        if( nullptr == hDevice )
            return XE_RESULT_ERROR_INVALID_PARAMETER;

        if( nullptr == pDesc )
            return XE_RESULT_ERROR_INVALID_PARAMETER;

        if( nullptr == phMetricQueryPool )
            return XE_RESULT_ERROR_INVALID_PARAMETER;

        if( XET_METRIC_QUERY_POOL_DESC_VERSION_CURRENT < pDesc->version )
            return XE_RESULT_ERROR_UNSUPPORTED;

    }

    return context.xetMetricQueryPool.pfnCreate( hDevice, pDesc, phMetricQueryPool );
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Intercept function for xetMetricQueryPoolDestroy
xe_result_t __xecall
xetMetricQueryPoolDestroy(
    xet_metric_query_pool_handle_t hMetricQueryPool ///< [in] handle of the metric query pool
    )
{
    if( context.enableParameterValidation )
    {
        if( nullptr == hMetricQueryPool )
            return XE_RESULT_ERROR_INVALID_PARAMETER;

    }

    return context.xetMetricQueryPool.pfnDestroy( hMetricQueryPool );
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Intercept function for xetMetricQueryPoolGetMetricQuery
xe_result_t __xecall
xetMetricQueryPoolGetMetricQuery(
    xet_metric_query_pool_handle_t hMetricQueryPool,///< [in] handle of the metric query pool
    uint32_t ordinal,                               ///< [in] index of the query within the pool
    xet_metric_query_handle_t* phMetricQuery        ///< [out] handle of metric query
    )
{
    if( context.enableParameterValidation )
    {
        if( nullptr == hMetricQueryPool )
            return XE_RESULT_ERROR_INVALID_PARAMETER;

        if( nullptr == phMetricQuery )
            return XE_RESULT_ERROR_INVALID_PARAMETER;

    }

    return context.xetMetricQueryPool.pfnGetMetricQuery( hMetricQueryPool, ordinal, phMetricQuery );
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Intercept function for xetCommandListAppendMetricQueryBegin
xe_result_t __xecall
xetCommandListAppendMetricQueryBegin(
    xe_command_list_handle_t hCommandList,          ///< [in] handle of the command list
    xet_metric_query_handle_t hMetricQuery          ///< [in] handle of the metric query
    )
{
    if( context.enableParameterValidation )
    {
        if( nullptr == hCommandList )
            return XE_RESULT_ERROR_INVALID_PARAMETER;

        if( nullptr == hMetricQuery )
            return XE_RESULT_ERROR_INVALID_PARAMETER;

    }

    return context.xetCommandList.pfnAppendMetricQueryBegin( hCommandList, hMetricQuery );
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Intercept function for xetCommandListAppendMetricQueryEnd
xe_result_t __xecall
xetCommandListAppendMetricQueryEnd(
    xe_command_list_handle_t hCommandList,          ///< [in] handle of the command list
    xet_metric_query_handle_t hMetricQuery,         ///< [in] handle of the metric query
    xe_event_handle_t hCompletionEvent              ///< [in] handle of the completion event to signal
    )
{
    if( context.enableParameterValidation )
    {
        if( nullptr == hCommandList )
            return XE_RESULT_ERROR_INVALID_PARAMETER;

        if( nullptr == hMetricQuery )
            return XE_RESULT_ERROR_INVALID_PARAMETER;

        if( nullptr == hCompletionEvent )
            return XE_RESULT_ERROR_INVALID_PARAMETER;

    }

    return context.xetCommandList.pfnAppendMetricQueryEnd( hCommandList, hMetricQuery, hCompletionEvent );
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Intercept function for xetCommandListAppendMetricMemoryBarrier
xe_result_t __xecall
xetCommandListAppendMetricMemoryBarrier(
    xe_command_list_handle_t hCommandList           ///< [in] handle of the command list
    )
{
    if( context.enableParameterValidation )
    {
        if( nullptr == hCommandList )
            return XE_RESULT_ERROR_INVALID_PARAMETER;

    }

    return context.xetCommandList.pfnAppendMetricMemoryBarrier( hCommandList );
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Intercept function for xetMetricQueryGetData
xe_result_t __xecall
xetMetricQueryGetData(
    xet_metric_query_handle_t hMetricQuery,         ///< [in] handle of the metric query
    uint32_t* pReportCount,                         ///< [in,out] report count to read/returned
    uint32_t rawDataSize,                           ///< [in] raw data size passed by the user
    uint8_t* pRawData                               ///< [in,out] query result data in raw format
    )
{
    if( context.enableParameterValidation )
    {
        if( nullptr == hMetricQuery )
            return XE_RESULT_ERROR_INVALID_PARAMETER;

        if( nullptr == pReportCount )
            return XE_RESULT_ERROR_INVALID_PARAMETER;

        if( nullptr == pRawData )
            return XE_RESULT_ERROR_INVALID_PARAMETER;

    }

    return context.xetMetricQuery.pfnGetData( hMetricQuery, pReportCount, rawDataSize, pRawData );
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Intercept function for xetDevicePowerInit
xe_result_t __xecall
xetDevicePowerInit(
    xe_device_handle_t hDevice,                     ///< [in] handle of the device object
    uint32_t flags,                                 ///< [in] bitfield of ::xet_power_init_flags_t
    xet_power_handle_t* pPowerHandle                ///< [out] handle for accessing power features of the device
    )
{
    if( context.enableParameterValidation )
    {
        if( nullptr == hDevice )
            return XE_RESULT_ERROR_INVALID_PARAMETER;

        if( nullptr == pPowerHandle )
            return XE_RESULT_ERROR_INVALID_PARAMETER;

    }

    return context.xetDevice.pfnPowerInit( hDevice, flags, pPowerHandle );
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Intercept function for xetPowerShutdown
xe_result_t __xecall
xetPowerShutdown(
    xet_power_handle_t hPower                       ///< [in] handle of the power object
    )
{
    if( context.enableParameterValidation )
    {
        if( nullptr == hPower )
            return XE_RESULT_ERROR_INVALID_PARAMETER;

    }

    return context.xetPower.pfnShutdown( hPower );
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Intercept function for xetPowerGetAveragePowerLimit
xe_result_t __xecall
xetPowerGetAveragePowerLimit(
    xet_power_handle_t hPower,                      ///< [in] handle of the power object
    xet_power_average_limit_t* pLimit               ///< [out] information about the average power limit
    )
{
    if( context.enableParameterValidation )
    {
        if( nullptr == hPower )
            return XE_RESULT_ERROR_INVALID_PARAMETER;

        if( nullptr == pLimit )
            return XE_RESULT_ERROR_INVALID_PARAMETER;

    }

    return context.xetPower.pfnGetAveragePowerLimit( hPower, pLimit );
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Intercept function for xetPowerGetBurstPowerLimit
xe_result_t __xecall
xetPowerGetBurstPowerLimit(
    xet_power_handle_t hPower,                      ///< [in] handle of the power object
    xet_power_burst_limit_t* pLimit                 ///< [out] information about the burst power limit
    )
{
    if( context.enableParameterValidation )
    {
        if( nullptr == hPower )
            return XE_RESULT_ERROR_INVALID_PARAMETER;

        if( nullptr == pLimit )
            return XE_RESULT_ERROR_INVALID_PARAMETER;

    }

    return context.xetPower.pfnGetBurstPowerLimit( hPower, pLimit );
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Intercept function for xetPowerGetPeakPowerLimit
xe_result_t __xecall
xetPowerGetPeakPowerLimit(
    xet_power_handle_t hPower,                      ///< [in] handle of the power object
    xet_power_peak_limit_t* pLimit                  ///< [out] information about the peak power limit
    )
{
    if( context.enableParameterValidation )
    {
        if( nullptr == hPower )
            return XE_RESULT_ERROR_INVALID_PARAMETER;

        if( nullptr == pLimit )
            return XE_RESULT_ERROR_INVALID_PARAMETER;

    }

    return context.xetPower.pfnGetPeakPowerLimit( hPower, pLimit );
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Intercept function for xetPowerGetAllPowerLimits
xe_result_t __xecall
xetPowerGetAllPowerLimits(
    xet_power_handle_t hPower,                      ///< [in] handle of the power object
    xet_power_limits_t* pLimits                     ///< [out] information about the average/burst/peak power limits
    )
{
    if( context.enableParameterValidation )
    {
        if( nullptr == hPower )
            return XE_RESULT_ERROR_INVALID_PARAMETER;

        if( nullptr == pLimits )
            return XE_RESULT_ERROR_INVALID_PARAMETER;

    }

    return context.xetPower.pfnGetAllPowerLimits( hPower, pLimits );
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Intercept function for xetPowerGetDefaultPowerLimits
xe_result_t __xecall
xetPowerGetDefaultPowerLimits(
    xet_power_handle_t hPower,                      ///< [in] handle of the power object
    xet_power_limits_t* pLimits                     ///< [out] information about the default average/burst/peak power limits
    )
{
    if( context.enableParameterValidation )
    {
        if( nullptr == hPower )
            return XE_RESULT_ERROR_INVALID_PARAMETER;

        if( nullptr == pLimits )
            return XE_RESULT_ERROR_INVALID_PARAMETER;

    }

    return context.xetPower.pfnGetDefaultPowerLimits( hPower, pLimits );
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Intercept function for xetPowerSetAveragePowerLimit
xe_result_t __xecall
xetPowerSetAveragePowerLimit(
    xet_power_handle_t hPower,                      ///< [in] handle of the power object
    xet_power_average_limit_t* pLimit               ///< [in] information about the average power limit
    )
{
    if( context.enableParameterValidation )
    {
        if( nullptr == hPower )
            return XE_RESULT_ERROR_INVALID_PARAMETER;

        if( nullptr == pLimit )
            return XE_RESULT_ERROR_INVALID_PARAMETER;

    }

    return context.xetPower.pfnSetAveragePowerLimit( hPower, pLimit );
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Intercept function for xetPowerSetBurstPowerLimit
xe_result_t __xecall
xetPowerSetBurstPowerLimit(
    xet_power_handle_t hPower,                      ///< [in] handle of the power object
    xet_power_burst_limit_t* pLimit                 ///< [in] information about the burst power limit
    )
{
    if( context.enableParameterValidation )
    {
        if( nullptr == hPower )
            return XE_RESULT_ERROR_INVALID_PARAMETER;

        if( nullptr == pLimit )
            return XE_RESULT_ERROR_INVALID_PARAMETER;

    }

    return context.xetPower.pfnSetBurstPowerLimit( hPower, pLimit );
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Intercept function for xetPowerSetPeakPowerLimit
xe_result_t __xecall
xetPowerSetPeakPowerLimit(
    xet_power_handle_t hPower,                      ///< [in] handle of the power object
    xet_power_peak_limit_t* pLimit                  ///< [in] information about the peak power limit
    )
{
    if( context.enableParameterValidation )
    {
        if( nullptr == hPower )
            return XE_RESULT_ERROR_INVALID_PARAMETER;

        if( nullptr == pLimit )
            return XE_RESULT_ERROR_INVALID_PARAMETER;

    }

    return context.xetPower.pfnSetPeakPowerLimit( hPower, pLimit );
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Intercept function for xetPowerSetPowerLimits
xe_result_t __xecall
xetPowerSetPowerLimits(
    xet_power_handle_t hPower,                      ///< [in] handle of the power object
    xet_power_limits_t* pLimits                     ///< [in] information about the average/burst/peak power limits
    )
{
    if( context.enableParameterValidation )
    {
        if( nullptr == hPower )
            return XE_RESULT_ERROR_INVALID_PARAMETER;

        if( nullptr == pLimits )
            return XE_RESULT_ERROR_INVALID_PARAMETER;

    }

    return context.xetPower.pfnSetPowerLimits( hPower, pLimits );
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Intercept function for xetPowerGetEnergyCounter
xe_result_t __xecall
xetPowerGetEnergyCounter(
    xet_power_handle_t hPower,                      ///< [in] handle of the power object
    uint64_t* pEnergyMillijoules                    ///< [out] the energy counter in millijoules
    )
{
    if( context.enableParameterValidation )
    {
        if( nullptr == hPower )
            return XE_RESULT_ERROR_INVALID_PARAMETER;

        if( nullptr == pEnergyMillijoules )
            return XE_RESULT_ERROR_INVALID_PARAMETER;

    }

    return context.xetPower.pfnGetEnergyCounter( hPower, pEnergyMillijoules );
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Intercept function for xetPowerGetTurboMode
xe_result_t __xecall
xetPowerGetTurboMode(
    xet_power_handle_t hPower,                      ///< [in] handle of the power object
    xet_turbo_mode_t* pTurboMode                    ///< [out] turbo mode currently in effect
    )
{
    if( context.enableParameterValidation )
    {
        if( nullptr == hPower )
            return XE_RESULT_ERROR_INVALID_PARAMETER;

        if( nullptr == pTurboMode )
            return XE_RESULT_ERROR_INVALID_PARAMETER;

    }

    return context.xetPower.pfnGetTurboMode( hPower, pTurboMode );
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Intercept function for xetPowerSetTurboMode
xe_result_t __xecall
xetPowerSetTurboMode(
    xet_power_handle_t hPower,                      ///< [in] handle of the power object
    xet_turbo_mode_t pTurboMode                     ///< [in] new turbo mode
    )
{
    if( context.enableParameterValidation )
    {
        if( nullptr == hPower )
            return XE_RESULT_ERROR_INVALID_PARAMETER;

    }

    return context.xetPower.pfnSetTurboMode( hPower, pTurboMode );
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Intercept function for xetPowerFreqDomainCount
xe_result_t __xecall
xetPowerFreqDomainCount(
    xet_power_handle_t hPower,                      ///< [in] handle of the power object
    uint32_t* pNumFreqDomains                       ///< [out] the number of frequency domains
    )
{
    if( context.enableParameterValidation )
    {
        if( nullptr == hPower )
            return XE_RESULT_ERROR_INVALID_PARAMETER;

        if( nullptr == pNumFreqDomains )
            return XE_RESULT_ERROR_INVALID_PARAMETER;

    }

    return context.xetPower.pfnFreqDomainCount( hPower, pNumFreqDomains );
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Intercept function for xetPowerFreqDomainGetHandle
xe_result_t __xecall
xetPowerFreqDomainGetHandle(
    xet_power_handle_t hPower,                      ///< [in] handle of the power object
    uint32_t ordinal,                               ///< [in] frequency domain index [0 .. ::xetPowerFreqDomainCount - 1]
    xet_freq_domain_handle_t* phFreqDomain          ///< [out] pointer to handle of frequency domain object
    )
{
    if( context.enableParameterValidation )
    {
        if( nullptr == hPower )
            return XE_RESULT_ERROR_INVALID_PARAMETER;

        if( nullptr == phFreqDomain )
            return XE_RESULT_ERROR_INVALID_PARAMETER;

    }

    return context.xetPower.pfnFreqDomainGetHandle( hPower, ordinal, phFreqDomain );
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Intercept function for xetPowerFreqDomainGetProperties
xe_result_t __xecall
xetPowerFreqDomainGetProperties(
    xet_freq_domain_handle_t hFreqDomain,           ///< [in] handle of the frequency domain
    xet_freq_domain_properties_t* pFreqDomainProperties ///< [out] pointer to properties for the frequency domain
    )
{
    if( context.enableParameterValidation )
    {
        if( nullptr == hFreqDomain )
            return XE_RESULT_ERROR_INVALID_PARAMETER;

        if( nullptr == pFreqDomainProperties )
            return XE_RESULT_ERROR_INVALID_PARAMETER;

    }

    return context.xetPower.pfnFreqDomainGetProperties( hFreqDomain, pFreqDomainProperties );
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Intercept function for xetPowerFreqDomainGetSupportedClocks
xe_result_t __xecall
xetPowerFreqDomainGetSupportedClocks(
    xet_freq_domain_handle_t hFreqDomain,           ///< [in] handle of the frequency domain
    uint32_t numClockPoints,                        ///< [in] number of elements in pClocksMHz
    uint32_t* pClocksMHz                            ///< [out] pointer to array of frequencies
    )
{
    if( context.enableParameterValidation )
    {
        if( nullptr == hFreqDomain )
            return XE_RESULT_ERROR_INVALID_PARAMETER;

        if( nullptr == pClocksMHz )
            return XE_RESULT_ERROR_INVALID_PARAMETER;

    }

    return context.xetPower.pfnFreqDomainGetSupportedClocks( hFreqDomain, numClockPoints, pClocksMHz );
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Intercept function for xetPowerFreqDomainGetSupportedClockDividers
xe_result_t __xecall
xetPowerFreqDomainGetSupportedClockDividers(
    xet_freq_domain_handle_t hFreqDomain,           ///< [in] handle of the frequency domain
    uint32_t numClockDividers,                      ///< [in] number of elements in pDividers
    xet_clock_divider_t* pDividers                  ///< [out] pointer to array of dividers
    )
{
    if( context.enableParameterValidation )
    {
        if( nullptr == hFreqDomain )
            return XE_RESULT_ERROR_INVALID_PARAMETER;

        if( nullptr == pDividers )
            return XE_RESULT_ERROR_INVALID_PARAMETER;

    }

    return context.xetPower.pfnFreqDomainGetSupportedClockDividers( hFreqDomain, numClockDividers, pDividers );
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Intercept function for xetPowerxetPowerFreqDomainGetClockRange
xe_result_t __xecall
xetPowerxetPowerFreqDomainGetClockRange(
    xet_freq_domain_handle_t hFreqDomain,           ///< [in] handle of the frequency domain
    uint32_t* pMinClockMHz,                         ///< [out] min clock frequency in units of MHz
    uint32_t* pMaxClockMHz                          ///< [out] max clock frequency in units of MHz
    )
{
    if( context.enableParameterValidation )
    {
        if( nullptr == hFreqDomain )
            return XE_RESULT_ERROR_INVALID_PARAMETER;

        if( nullptr == pMinClockMHz )
            return XE_RESULT_ERROR_INVALID_PARAMETER;

        if( nullptr == pMaxClockMHz )
            return XE_RESULT_ERROR_INVALID_PARAMETER;

    }

    return context.xetPower.pfnxetPowerFreqDomainGetClockRange( hFreqDomain, pMinClockMHz, pMaxClockMHz );
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Intercept function for xetPowerxetPowerFreqDomainSetClockRange
xe_result_t __xecall
xetPowerxetPowerFreqDomainSetClockRange(
    xet_freq_domain_handle_t hFreqDomain,           ///< [in] handle of the frequency domain
    uint32_t minClockMHz,                           ///< [in] min clock frequency in units of MHz
    uint32_t maxClockMHz                            ///< [in] max clock frequency in units of MHz
    )
{
    if( context.enableParameterValidation )
    {
        if( nullptr == hFreqDomain )
            return XE_RESULT_ERROR_INVALID_PARAMETER;

    }

    return context.xetPower.pfnxetPowerFreqDomainSetClockRange( hFreqDomain, minClockMHz, maxClockMHz );
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Intercept function for xetPowerFreqDomainSetClockDivider
xe_result_t __xecall
xetPowerFreqDomainSetClockDivider(
    xet_freq_domain_handle_t hFreqDomain,           ///< [in] handle of the frequency domain
    xet_clock_divider_t* pClockDividerRequest       ///< [out] pointer to frequency divider request
    )
{
    if( context.enableParameterValidation )
    {
        if( nullptr == hFreqDomain )
            return XE_RESULT_ERROR_INVALID_PARAMETER;

        if( nullptr == pClockDividerRequest )
            return XE_RESULT_ERROR_INVALID_PARAMETER;

    }

    return context.xetPower.pfnFreqDomainSetClockDivider( hFreqDomain, pClockDividerRequest );
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Intercept function for xetPowerGetCurrentFrequency
xe_result_t __xecall
xetPowerGetCurrentFrequency(
    xet_freq_domain_handle_t hFreqDomain,           ///< [in] handle of the frequency domain
    uint32_t* pFreqRequestMHz,                      ///< [out] current frequency in MHz requested by the driver
    uint32_t* pFreqResolvedMHz,                     ///< [out] the actual frequency in MHz
    xet_freq_throttle_reasons_t* pFreqThrottleReasons   ///< [out] the reason the resolved frequency is lower than the request
    )
{
    if( context.enableParameterValidation )
    {
        if( nullptr == hFreqDomain )
            return XE_RESULT_ERROR_INVALID_PARAMETER;

        if( nullptr == pFreqRequestMHz )
            return XE_RESULT_ERROR_INVALID_PARAMETER;

        if( nullptr == pFreqResolvedMHz )
            return XE_RESULT_ERROR_INVALID_PARAMETER;

        if( nullptr == pFreqThrottleReasons )
            return XE_RESULT_ERROR_INVALID_PARAMETER;

    }

    return context.xetPower.pfnGetCurrentFrequency( hFreqDomain, pFreqRequestMHz, pFreqResolvedMHz, pFreqThrottleReasons );
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Intercept function for xetPowerFanCount
xe_result_t __xecall
xetPowerFanCount(
    xet_power_handle_t hPower,                      ///< [in] handle of the power object
    uint32_t* pFanCount                             ///< [out] the number of fans on the device
    )
{
    if( context.enableParameterValidation )
    {
        if( nullptr == hPower )
            return XE_RESULT_ERROR_INVALID_PARAMETER;

        if( nullptr == pFanCount )
            return XE_RESULT_ERROR_INVALID_PARAMETER;

    }

    return context.xetPower.pfnFanCount( hPower, pFanCount );
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Intercept function for xetPowerFanGetProperties
xe_result_t __xecall
xetPowerFanGetProperties(
    xet_power_handle_t hPower,                      ///< [in] handle of the power object
    uint32_t fanIndex,                              ///< [in] fan index [0 .. ::xetPowerFanCount - 1]
    xet_fan_properties_t* pFanProperties            ///< [out] pointer to storage for fan properties
    )
{
    if( context.enableParameterValidation )
    {
        if( nullptr == hPower )
            return XE_RESULT_ERROR_INVALID_PARAMETER;

        if( nullptr == pFanProperties )
            return XE_RESULT_ERROR_INVALID_PARAMETER;

    }

    return context.xetPower.pfnFanGetProperties( hPower, fanIndex, pFanProperties );
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Intercept function for xetPowerFanGetSpeedTable
xe_result_t __xecall
xetPowerFanGetSpeedTable(
    xet_power_handle_t hPower,                      ///< [in] handle of the power object
    uint32_t fanIndex,                              ///< [in] fan index [0 .. ::xetPowerFanCount - 1]
    xe_bool_t fanSpeedInRpm,                        ///< [in] true will request fan speeds in RPM, otherwise in percentage
    uint32_t* pNumFanPoints,                        ///< [in/out] input number of elements in pFanSpeedTable array; output
                                                    ///< number of elements returned
    xet_fan_point_t* pFanPoints                     ///< [out] pointer to an array of temperature/fan-speed points
    )
{
    if( context.enableParameterValidation )
    {
        if( nullptr == hPower )
            return XE_RESULT_ERROR_INVALID_PARAMETER;

        if( nullptr == pNumFanPoints )
            return XE_RESULT_ERROR_INVALID_PARAMETER;

        if( nullptr == pFanPoints )
            return XE_RESULT_ERROR_INVALID_PARAMETER;

    }

    return context.xetPower.pfnFanGetSpeedTable( hPower, fanIndex, fanSpeedInRpm, pNumFanPoints, pFanPoints );
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Intercept function for xetPowerFanSetSpeedTable
xe_result_t __xecall
xetPowerFanSetSpeedTable(
    xet_power_handle_t hPower,                      ///< [in] handle of the power object
    uint32_t fanIndex,                              ///< [in] fan index [0 .. ::xetPowerFanCount - 1]
    uint32_t numFanPoints,                          ///< [in] number of points in pFanSpeedTable array
    xet_fan_point_t* pFanPoints                     ///< [in] pointer to an array of temperature/fan-speed points
    )
{
    if( context.enableParameterValidation )
    {
        if( nullptr == hPower )
            return XE_RESULT_ERROR_INVALID_PARAMETER;

        if( nullptr == pFanPoints )
            return XE_RESULT_ERROR_INVALID_PARAMETER;

    }

    return context.xetPower.pfnFanSetSpeedTable( hPower, fanIndex, numFanPoints, pFanPoints );
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Intercept function for xetPowerFanGetSpeed
xe_result_t __xecall
xetPowerFanGetSpeed(
    xet_power_handle_t hPower,                      ///< [in] handle of the power object
    uint32_t startFanIndex,                         ///< [in] fan index [0 .. ::xetPowerFanCount - 1]
    uint32_t numFans,                               ///< [in] pFanSpeed will contain results for fan index
                                                    ///< (startFanIndex)..(startFanIndex + numFans - 1)
    xe_bool_t fanSpeedInRpm,                        ///< [in] true will request fan speeds in RPM, otherwise in percentage
    xet_fan_speed_info_t* pFanSpeed                 ///< [out] pointer to an array of current fan speeds
    )
{
    if( context.enableParameterValidation )
    {
        if( nullptr == hPower )
            return XE_RESULT_ERROR_INVALID_PARAMETER;

        if( nullptr == pFanSpeed )
            return XE_RESULT_ERROR_INVALID_PARAMETER;

    }

    return context.xetPower.pfnFanGetSpeed( hPower, startFanIndex, numFans, fanSpeedInRpm, pFanSpeed );
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Intercept function for xetPowerFanSetSpeed
xe_result_t __xecall
xetPowerFanSetSpeed(
    xet_power_handle_t hPower,                      ///< [in] handle of the power object
    uint32_t startFanIndex,                         ///< [in] fan index [0 .. ::xetPowerFanCount - 1]
    uint32_t numFans,                               ///< [in] pFanSpeed will contain results for fan index
                                                    ///< (startFanIndex)..(startFanIndex + numFans - 1)
    xet_fan_speed_info_t* pFanSpeed                 ///< [in] pointer to an array of current fan speeds
    )
{
    if( context.enableParameterValidation )
    {
        if( nullptr == hPower )
            return XE_RESULT_ERROR_INVALID_PARAMETER;

        if( nullptr == pFanSpeed )
            return XE_RESULT_ERROR_INVALID_PARAMETER;

    }

    return context.xetPower.pfnFanSetSpeed( hPower, startFanIndex, numFans, pFanSpeed );
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Intercept function for xetPowerTemperatureSensorCount
xe_result_t __xecall
xetPowerTemperatureSensorCount(
    xet_power_handle_t hPower,                      ///< [in] handle of the power object
    uint32_t* pSensorCount                          ///< [out] the number of temperature sensors on the device
    )
{
    if( context.enableParameterValidation )
    {
        if( nullptr == hPower )
            return XE_RESULT_ERROR_INVALID_PARAMETER;

        if( nullptr == pSensorCount )
            return XE_RESULT_ERROR_INVALID_PARAMETER;

    }

    return context.xetPower.pfnTemperatureSensorCount( hPower, pSensorCount );
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Intercept function for xetPowerGetTemperatureProperties
xe_result_t __xecall
xetPowerGetTemperatureProperties(
    xet_power_handle_t hPower,                      ///< [in] handle of the power object
    uint32_t sensorIndex,                           ///< [in] sensor index [0 .. ::xetPowerTemperatureSensorCount]
    xet_temperature_properties_t* pProperties       ///< [out] pointer to properties for this sensor
    )
{
    if( context.enableParameterValidation )
    {
        if( nullptr == hPower )
            return XE_RESULT_ERROR_INVALID_PARAMETER;

        if( nullptr == pProperties )
            return XE_RESULT_ERROR_INVALID_PARAMETER;

    }

    return context.xetPower.pfnGetTemperatureProperties( hPower, sensorIndex, pProperties );
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Intercept function for xetPowerGetTemperature
xe_result_t __xecall
xetPowerGetTemperature(
    xet_power_handle_t hPower,                      ///< [in] handle of the power object
    uint32_t startSensorIndex,                      ///< [in] sensor index [0 .. ::xetPowerTemperatureSensorCount]
    uint32_t numSensors,                            ///< [in] pTemperatures will contain results for sensors index
                                                    ///< (startSensorIndex)..(startSensorIndex + numSensors - 1)
    uint16_t* pTemperatures                         ///< [out] pointer to an array of temperatures in units of degrees celsius
    )
{
    if( context.enableParameterValidation )
    {
        if( nullptr == hPower )
            return XE_RESULT_ERROR_INVALID_PARAMETER;

        if( nullptr == pTemperatures )
            return XE_RESULT_ERROR_INVALID_PARAMETER;

    }

    return context.xetPower.pfnGetTemperature( hPower, startSensorIndex, numSensors, pTemperatures );
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Intercept function for xetPowerSetTemperatureThreshold
xe_result_t __xecall
xetPowerSetTemperatureThreshold(
    xet_power_handle_t hPower,                      ///< [in] handle of the power object
    uint32_t sensorIndex,                           ///< [in] sensor index [0 .. ::xetPowerTemperatureSensorCount]
    uint16_t maxTemperature                         ///< [in] temperature threshold in degrees celsius beyond which frequency
                                                    ///< will be throttled
    )
{
    if( context.enableParameterValidation )
    {
        if( nullptr == hPower )
            return XE_RESULT_ERROR_INVALID_PARAMETER;

    }

    return context.xetPower.pfnSetTemperatureThreshold( hPower, sensorIndex, maxTemperature );
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Intercept function for xetPowerActivityCount
xe_result_t __xecall
xetPowerActivityCount(
    xet_power_handle_t hPower,                      ///< [in] handle of the power object
    uint32_t* pActivityCount                        ///< [out] the number of activity counters on the device
    )
{
    if( context.enableParameterValidation )
    {
        if( nullptr == hPower )
            return XE_RESULT_ERROR_INVALID_PARAMETER;

        if( nullptr == pActivityCount )
            return XE_RESULT_ERROR_INVALID_PARAMETER;

    }

    return context.xetPower.pfnActivityCount( hPower, pActivityCount );
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Intercept function for xetPowerGetActivityProperties
xe_result_t __xecall
xetPowerGetActivityProperties(
    xet_power_handle_t hPower,                      ///< [in] handle of the power object
    uint32_t activityIndex,                         ///< [in] activity counter index [0 .. ::xetPowerActivityCount]
    xet_activity_properties_t* pProperties          ///< [out] pointer to properties for this activity counter
    )
{
    if( context.enableParameterValidation )
    {
        if( nullptr == hPower )
            return XE_RESULT_ERROR_INVALID_PARAMETER;

        if( nullptr == pProperties )
            return XE_RESULT_ERROR_INVALID_PARAMETER;

    }

    return context.xetPower.pfnGetActivityProperties( hPower, activityIndex, pProperties );
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Intercept function for xetPowerGetActivityCounters
xe_result_t __xecall
xetPowerGetActivityCounters(
    xet_power_handle_t hPower,                      ///< [in] handle of the power object
    uint32_t startCounterIndex,                     ///< [in] sensor index [0 .. ::xetPowerActivityCount]
    uint32_t numCounters,                           ///< [in] pCounters will contain results for activity counter index
                                                    ///< (startCounterIndex)..(startCounterIndex + numCounters - 1)
    xet_activity_counters_t* pCounters              ///< [out] pointer to an array of activity counter data
    )
{
    if( context.enableParameterValidation )
    {
        if( nullptr == hPower )
            return XE_RESULT_ERROR_INVALID_PARAMETER;

        if( nullptr == pCounters )
            return XE_RESULT_ERROR_INVALID_PARAMETER;

    }

    return context.xetPower.pfnGetActivityCounters( hPower, startCounterIndex, numCounters, pCounters );
}

#if defined(__cplusplus)
};
#endif
