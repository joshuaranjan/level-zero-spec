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
* @file xe_tools_driver.cpp
*
* @cond DEV
* DO NOT EDIT: generated from /scripts/templates/nullddi.cpp.mako
* @endcond
*
******************************************************************************/
#include "xe_null.h"

namespace driver
{
    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Intercept function for xetInit
    xe_result_t __xecall
    xetInit(
        xe_init_flag_t flags                            ///< [in] initialization flags
        )
    {
        xe_result_t result = XE_RESULT_SUCCESS;

        return result;
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Intercept function for xetMetricGroupGet
    xe_result_t __xecall
    xetMetricGroupGet(
        xet_device_group_handle_t hDeviceGroup,         ///< [in] handle of the device group
        uint32_t* pCount,                               ///< [in,out] pointer to the number of metric groups.
                                                        ///< if count is zero, then the driver will update the value with the total
                                                        ///< number of metric groups available.
                                                        ///< if count is non-zero, then driver will only retrieve that number of
                                                        ///< metric groups.
        xet_metric_group_handle_t* phMetricGroups       ///< [in,out][optional][range(0, *pCount)] array of handle of metric groups
        )
    {
        xe_result_t result = XE_RESULT_SUCCESS;

        *pCount = 1;
        if( nullptr != phMetricGroups ) *reinterpret_cast<void**>(phMetricGroups) = context.get();

        return result;
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Intercept function for xetMetricGroupGetProperties
    xe_result_t __xecall
    xetMetricGroupGetProperties(
        xet_metric_group_handle_t hMetricGroup,         ///< [in] handle of the metric group
        xet_metric_group_properties_t* pProperties      ///< [out] metric group properties
        )
    {
        xe_result_t result = XE_RESULT_SUCCESS;

        *pProperties = context.metricGroupProperties;

        return result;
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Intercept function for xetMetricGroupCalculateData
    xe_result_t __xecall
    xetMetricGroupCalculateData(
        xet_metric_group_handle_t hMetricGroup,         ///< [in] handle of the metric group
        size_t rawDataSize,                             ///< [in] size in bytes of raw data buffer
        uint8_t* pRawData,                              ///< [in][range(0, rawDataSize)] buffer of raw data to calculate
        uint32_t* pCalculatedDataCount,                 ///< [in] pointer to number of entries in calculated data buffer.
                                                        ///< if count is zero, then the driver will update the value with the total
                                                        ///< number of entires to be calculated.
                                                        ///< if count is non-zero, then driver will only calculate that number of entires.
        xet_typed_value_t* pCalculatedData              ///< [in,out][range(0, *pCalculatedDataSize)] buffer of calculated data
        )
    {
        xe_result_t result = XE_RESULT_SUCCESS;

        *pCalculatedDataCount = 1;
        if( pCalculatedData ) *pCalculatedData = {};

        return result;
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Intercept function for xetMetricGet
    xe_result_t __xecall
    xetMetricGet(
        xet_metric_group_handle_t hMetricGroup,         ///< [in] handle of the metric group
        uint32_t* pCount,                               ///< [in,out] pointer to the number of metrics.
                                                        ///< if count is zero, then the driver will update the value with the total
                                                        ///< number of metrics available.
                                                        ///< if count is non-zero, then driver will only retrieve that number of metrics.
        xet_metric_handle_t* phMetrics                  ///< [in,out][optional][range(0, *pCount)] array of handle of metrics
        )
    {
        xe_result_t result = XE_RESULT_SUCCESS;

        *pCount = 1;
        if( nullptr != phMetrics ) *reinterpret_cast<void**>(phMetrics) = context.get();

        return result;
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Intercept function for xetMetricGetProperties
    xe_result_t __xecall
    xetMetricGetProperties(
        xet_metric_handle_t hMetric,                    ///< [in] handle of the metric
        xet_metric_properties_t* pProperties            ///< [out] metric properties
        )
    {
        xe_result_t result = XE_RESULT_SUCCESS;

        *pProperties = context.metricProperties;

        return result;
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Intercept function for xetDeviceActivateMetricGroups
    xe_result_t __xecall
    xetDeviceActivateMetricGroups(
        xet_device_handle_t hDevice,                    ///< [in] handle of the device
        uint32_t count,                                 ///< [in] metric group count to activate. 0 to deactivate.
        xet_metric_group_handle_t* phMetricGroups       ///< [in][range(0, count)] handles of the metric groups to activate. NULL
                                                        ///< to deactivate.
        )
    {
        xe_result_t result = XE_RESULT_SUCCESS;

        return result;
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Intercept function for xetMetricTracerOpen
    xe_result_t __xecall
    xetMetricTracerOpen(
        xet_device_handle_t hDevice,                    ///< [in] handle of the device
        xet_metric_group_handle_t hMetricGroup,         ///< [in] handle of the metric group
        xet_metric_tracer_desc_t* desc,                 ///< [in,out] metric tracer descriptor
        xe_event_handle_t hNotificationEvent,           ///< [in] event used for report availability notification. Must be device
                                                        ///< to host type.
        xet_metric_tracer_handle_t* phMetricTracer      ///< [out] handle of metric tracer
        )
    {
        xe_result_t result = XE_RESULT_SUCCESS;

        *phMetricTracer = reinterpret_cast<xet_metric_tracer_handle_t>( context.get() );

        return result;
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Intercept function for xetCommandListAppendMetricTracerMarker
    xe_result_t __xecall
    xetCommandListAppendMetricTracerMarker(
        xet_command_list_handle_t hCommandList,         ///< [in] handle of the command list
        xet_metric_tracer_handle_t hMetricTracer,       ///< [in] handle of the metric tracer
        uint32_t value                                  ///< [in] tracer marker value
        )
    {
        xe_result_t result = XE_RESULT_SUCCESS;

        return result;
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Intercept function for xetMetricTracerClose
    xe_result_t __xecall
    xetMetricTracerClose(
        xet_metric_tracer_handle_t hMetricTracer        ///< [in][release] handle of the metric tracer
        )
    {
        xe_result_t result = XE_RESULT_SUCCESS;


        return result;
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Intercept function for xetMetricTracerReadData
    xe_result_t __xecall
    xetMetricTracerReadData(
        xet_metric_tracer_handle_t hMetricTracer,       ///< [in] handle of the metric tracer
        size_t* pRawDataSize,                           ///< [in,out] pointer to size in bytes of raw data requested to read.
                                                        ///< if size is zero, then the driver will update the value with the total
                                                        ///< size in bytes needed for all reports available.
                                                        ///< if size is non-zero, then driver will only retrieve the number of
                                                        ///< reports that fit into the buffer.
        uint8_t* pRawData                               ///< [in,out][optional][range(0, *pRawDataSize)] buffer containing tracer
                                                        ///< reports in raw format
        )
    {
        xe_result_t result = XE_RESULT_SUCCESS;

        *pRawDataSize = 1;
        if( pRawData ) *pRawData = 0;

        return result;
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Intercept function for xetMetricQueryPoolCreate
    xe_result_t __xecall
    xetMetricQueryPoolCreate(
        xet_device_handle_t hDevice,                    ///< [in] handle of the device
        xet_metric_group_handle_t hMetricGroup,         ///< [in] metric group associated with the query object.
        const xet_metric_query_pool_desc_t* desc,       ///< [in] metric query pool descriptor
        xet_metric_query_pool_handle_t* phMetricQueryPool   ///< [out] handle of metric query pool
        )
    {
        xe_result_t result = XE_RESULT_SUCCESS;

        *phMetricQueryPool = reinterpret_cast<xet_metric_query_pool_handle_t>( context.get() );

        return result;
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Intercept function for xetMetricQueryPoolDestroy
    xe_result_t __xecall
    xetMetricQueryPoolDestroy(
        xet_metric_query_pool_handle_t hMetricQueryPool ///< [in][release] handle of the metric query pool
        )
    {
        xe_result_t result = XE_RESULT_SUCCESS;


        return result;
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Intercept function for xetMetricQueryCreate
    xe_result_t __xecall
    xetMetricQueryCreate(
        xet_metric_query_pool_handle_t hMetricQueryPool,///< [in] handle of the metric query pool
        uint32_t index,                                 ///< [in] index of the query within the pool
        xet_metric_query_handle_t* phMetricQuery        ///< [out] handle of metric query
        )
    {
        xe_result_t result = XE_RESULT_SUCCESS;

        *phMetricQuery = reinterpret_cast<xet_metric_query_handle_t>( context.get() );

        return result;
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Intercept function for xetMetricQueryDestroy
    xe_result_t __xecall
    xetMetricQueryDestroy(
        xet_metric_query_handle_t hMetricQuery          ///< [in][release] handle of metric query
        )
    {
        xe_result_t result = XE_RESULT_SUCCESS;


        return result;
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Intercept function for xetMetricQueryReset
    xe_result_t __xecall
    xetMetricQueryReset(
        xet_metric_query_handle_t hMetricQuery          ///< [in] handle of metric query
        )
    {
        xe_result_t result = XE_RESULT_SUCCESS;

        return result;
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Intercept function for xetCommandListAppendMetricQueryBegin
    xe_result_t __xecall
    xetCommandListAppendMetricQueryBegin(
        xet_command_list_handle_t hCommandList,         ///< [in] handle of the command list
        xet_metric_query_handle_t hMetricQuery          ///< [in] handle of the metric query
        )
    {
        xe_result_t result = XE_RESULT_SUCCESS;

        return result;
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Intercept function for xetCommandListAppendMetricQueryEnd
    xe_result_t __xecall
    xetCommandListAppendMetricQueryEnd(
        xet_command_list_handle_t hCommandList,         ///< [in] handle of the command list
        xet_metric_query_handle_t hMetricQuery,         ///< [in] handle of the metric query
        xe_event_handle_t hCompletionEvent              ///< [in] handle of the completion event to signal
        )
    {
        xe_result_t result = XE_RESULT_SUCCESS;

        return result;
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Intercept function for xetCommandListAppendMetricMemoryBarrier
    xe_result_t __xecall
    xetCommandListAppendMetricMemoryBarrier(
        xet_command_list_handle_t hCommandList          ///< [in] handle of the command list
        )
    {
        xe_result_t result = XE_RESULT_SUCCESS;

        return result;
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Intercept function for xetMetricQueryGetData
    xe_result_t __xecall
    xetMetricQueryGetData(
        xet_metric_query_handle_t hMetricQuery,         ///< [in] handle of the metric query
        size_t* pRawDataSize,                           ///< [in,out] pointer to size in bytes of raw data requested to read.
                                                        ///< if size is zero, then the driver will update the value with the total
                                                        ///< size in bytes needed for all reports available.
                                                        ///< if size is non-zero, then driver will only retrieve the number of
                                                        ///< reports that fit into the buffer.
        uint8_t* pRawData                               ///< [in,out][optional][range(0, *pRawDataSize)] buffer containing query
                                                        ///< reports in raw format
        )
    {
        xe_result_t result = XE_RESULT_SUCCESS;

        *pRawDataSize = 1;
        if( pRawData ) *pRawData = 0;

        return result;
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Intercept function for xetModuleGetDebugInfo
    xe_result_t __xecall
    xetModuleGetDebugInfo(
        xet_module_handle_t hModule,                    ///< [in] handle of the module
        xet_module_debug_info_format_t format,          ///< [in] debug info format requested
        size_t* pSize,                                  ///< [in,out] size of debug info in bytes
        uint8_t* pDebugInfo                             ///< [in,out][optional] byte pointer to debug info
        )
    {
        xe_result_t result = XE_RESULT_SUCCESS;

        return result;
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Intercept function for xetModuleAllocateExecutableMemory
    xe_result_t __xecall
    xetModuleAllocateExecutableMemory(
        xet_module_handle_t hModule,                    ///< [in] handle of the module
        size_t size,                                    ///< [in] size (in bytes) to allocate
        void** ptr                                      ///< [out] pointer to allocation
        )
    {
        xe_result_t result = XE_RESULT_SUCCESS;

        *ptr = malloc( size );

        return result;
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Intercept function for xetModuleFreeExecutableMemory
    xe_result_t __xecall
    xetModuleFreeExecutableMemory(
        xet_module_handle_t hModule,                    ///< [in] handle of the module
        void* ptr                                       ///< [in] pointer to allocation to free
        )
    {
        xe_result_t result = XE_RESULT_SUCCESS;

        return result;
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Intercept function for xetModuleGetFunctionNames
    xe_result_t __xecall
    xetModuleGetFunctionNames(
        xet_module_handle_t hModule,                    ///< [in] handle of the device
        uint32_t* pCount,                               ///< [in,out] pointer to the number of names.
                                                        ///< if count is zero, then the driver will update the value with the total
                                                        ///< number of names available.
                                                        ///< if count is non-zero, then driver will only retrieve that number of names.
        const char** pNames                             ///< [in,out][optional][range(0, *pCount)] array of names of functions
        )
    {
        xe_result_t result = XE_RESULT_SUCCESS;

        return result;
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Intercept function for xetFunctionGetProfileInfo
    xe_result_t __xecall
    xetFunctionGetProfileInfo(
        xet_function_handle_t hFunction,                ///< [in] handle to function
        xet_profile_info_t* pInfo                       ///< [out] pointer to profile info
        )
    {
        xe_result_t result = XE_RESULT_SUCCESS;

        return result;
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Intercept function for xetFunctionSetAddress
    xe_result_t __xecall
    xetFunctionSetAddress(
        xet_function_handle_t hFunction,                ///< [in] handle to function
        void* ptr                                       ///< [in] address to use for function; must be allocated using ::xetModuleAllocateExecutableMemory.
                                                        ///< if address is nullptr, then resets function address to default value."
        )
    {
        xe_result_t result = XE_RESULT_SUCCESS;

        return result;
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Intercept function for xetPowerCreate
    xe_result_t __xecall
    xetPowerCreate(
        xet_device_handle_t hDevice,                    ///< [in] handle of the device object
        uint32_t flags,                                 ///< [in] bitfield of ::xet_power_init_flags_t
        xet_power_handle_t* pPowerHandle                ///< [out] handle for accessing power features of the device
        )
    {
        xe_result_t result = XE_RESULT_SUCCESS;

        *pPowerHandle = reinterpret_cast<xet_power_handle_t>( context.get() );

        return result;
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Intercept function for xetPowerDestroy
    xe_result_t __xecall
    xetPowerDestroy(
        xet_power_handle_t hPower                       ///< [in][release] handle of the power object to destroy
        )
    {
        xe_result_t result = XE_RESULT_SUCCESS;


        return result;
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Intercept function for xetPowerGetAveragePowerLimit
    xe_result_t __xecall
    xetPowerGetAveragePowerLimit(
        xet_power_handle_t hPower,                      ///< [in] handle of the power object
        xet_power_average_limit_t* pLimit               ///< [out] information about the average power limit
        )
    {
        xe_result_t result = XE_RESULT_SUCCESS;

        return result;
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Intercept function for xetPowerGetBurstPowerLimit
    xe_result_t __xecall
    xetPowerGetBurstPowerLimit(
        xet_power_handle_t hPower,                      ///< [in] handle of the power object
        xet_power_burst_limit_t* pLimit                 ///< [out] information about the burst power limit
        )
    {
        xe_result_t result = XE_RESULT_SUCCESS;

        return result;
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Intercept function for xetPowerGetPeakPowerLimit
    xe_result_t __xecall
    xetPowerGetPeakPowerLimit(
        xet_power_handle_t hPower,                      ///< [in] handle of the power object
        xet_power_peak_limit_t* pLimit                  ///< [out] information about the peak power limit
        )
    {
        xe_result_t result = XE_RESULT_SUCCESS;

        return result;
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Intercept function for xetPowerGetAllPowerLimits
    xe_result_t __xecall
    xetPowerGetAllPowerLimits(
        xet_power_handle_t hPower,                      ///< [in] handle of the power object
        xet_power_limits_t* pLimits                     ///< [out] information about the average/burst/peak power limits
        )
    {
        xe_result_t result = XE_RESULT_SUCCESS;

        return result;
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Intercept function for xetPowerGetDefaultPowerLimits
    xe_result_t __xecall
    xetPowerGetDefaultPowerLimits(
        xet_power_handle_t hPower,                      ///< [in] handle of the power object
        xet_power_limits_t* pLimits                     ///< [out] information about the default average/burst/peak power limits
        )
    {
        xe_result_t result = XE_RESULT_SUCCESS;

        return result;
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Intercept function for xetPowerSetAveragePowerLimit
    xe_result_t __xecall
    xetPowerSetAveragePowerLimit(
        xet_power_handle_t hPower,                      ///< [in] handle of the power object
        xet_power_average_limit_t* pLimit               ///< [in] information about the average power limit
        )
    {
        xe_result_t result = XE_RESULT_SUCCESS;

        return result;
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Intercept function for xetPowerSetBurstPowerLimit
    xe_result_t __xecall
    xetPowerSetBurstPowerLimit(
        xet_power_handle_t hPower,                      ///< [in] handle of the power object
        xet_power_burst_limit_t* pLimit                 ///< [in] information about the burst power limit
        )
    {
        xe_result_t result = XE_RESULT_SUCCESS;

        return result;
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Intercept function for xetPowerSetPeakPowerLimit
    xe_result_t __xecall
    xetPowerSetPeakPowerLimit(
        xet_power_handle_t hPower,                      ///< [in] handle of the power object
        xet_power_peak_limit_t* pLimit                  ///< [in] information about the peak power limit
        )
    {
        xe_result_t result = XE_RESULT_SUCCESS;

        return result;
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Intercept function for xetPowerSetPowerLimits
    xe_result_t __xecall
    xetPowerSetPowerLimits(
        xet_power_handle_t hPower,                      ///< [in] handle of the power object
        xet_power_limits_t* pLimits                     ///< [in] information about the average/burst/peak power limits
        )
    {
        xe_result_t result = XE_RESULT_SUCCESS;

        return result;
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Intercept function for xetPowerGetEnergyCounter
    xe_result_t __xecall
    xetPowerGetEnergyCounter(
        xet_power_handle_t hPower,                      ///< [in] handle of the power object
        uint64_t* pEnergy                               ///< [out] the energy counter in millijoules
        )
    {
        xe_result_t result = XE_RESULT_SUCCESS;

        return result;
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Intercept function for xetPowerGetTurboMode
    xe_result_t __xecall
    xetPowerGetTurboMode(
        xet_power_handle_t hPower,                      ///< [in] handle of the power object
        xet_turbo_mode_t* pTurboMode                    ///< [out] turbo mode currently in effect
        )
    {
        xe_result_t result = XE_RESULT_SUCCESS;

        return result;
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Intercept function for xetPowerSetTurboMode
    xe_result_t __xecall
    xetPowerSetTurboMode(
        xet_power_handle_t hPower,                      ///< [in] handle of the power object
        xet_turbo_mode_t pTurboMode                     ///< [in] new turbo mode
        )
    {
        xe_result_t result = XE_RESULT_SUCCESS;

        return result;
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Intercept function for xetFreqDomainGet
    xe_result_t __xecall
    xetFreqDomainGet(
        xet_power_handle_t hPower,                      ///< [in] handle of the power object
        uint32_t* pCount,                               ///< [in,out] pointer to the number of frequency domains.
                                                        ///< if count is zero, then the driver will update the value with the total
                                                        ///< number of frequency domains available.
                                                        ///< if count is non-zero, then driver will only retrieve that number of
                                                        ///< frequency domains.
        xet_freq_domain_handle_t* phFreqDomain          ///< [in,out][optional][range(0, *pCount)] array of handle of frequency
                                                        ///< domains
        )
    {
        xe_result_t result = XE_RESULT_SUCCESS;

        for( size_t i = 0; ( nullptr != phFreqDomain ) && ( i < *pCount ); ++i )
            phFreqDomain[ i ] = reinterpret_cast<xet_freq_domain_handle_t>( context.get() );

        return result;
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Intercept function for xetFreqDomainGetProperties
    xe_result_t __xecall
    xetFreqDomainGetProperties(
        xet_freq_domain_handle_t hFreqDomain,           ///< [in] handle of the frequency domain
        xet_freq_domain_properties_t* pFreqDomainProperties ///< [out] pointer to properties for the frequency domain
        )
    {
        xe_result_t result = XE_RESULT_SUCCESS;

        return result;
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Intercept function for xetFreqDomainGetSourceFreqDomain
    xe_result_t __xecall
    xetFreqDomainGetSourceFreqDomain(
        xet_freq_domain_handle_t hFreqDomain,           ///< [in] handle of the frequency domain
        xet_freq_domain_handle_t* phSrcFreqDomain       ///< [out] pointer to a handle where the source frequency domain handle
                                                        ///< will be returned
        )
    {
        xe_result_t result = XE_RESULT_SUCCESS;

        *phSrcFreqDomain = reinterpret_cast<xet_freq_domain_handle_t>( context.get() );

        return result;
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Intercept function for xetFreqDomainGetSupportedClocks
    xe_result_t __xecall
    xetFreqDomainGetSupportedClocks(
        xet_freq_domain_handle_t hFreqDomain,           ///< [in] handle of the frequency domain
        uint32_t numClockPoints,                        ///< [in] number of elements in pClocks
        uint32_t* pClocks                               ///< [out] pointer to array of frequencies
        )
    {
        xe_result_t result = XE_RESULT_SUCCESS;

        return result;
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Intercept function for xetFreqDomainGetSupportedClockDividers
    xe_result_t __xecall
    xetFreqDomainGetSupportedClockDividers(
        xet_freq_domain_handle_t hFreqDomain,           ///< [in] handle of the frequency domain
        uint32_t numClockDividers,                      ///< [in] number of elements in pDividers
        xet_clock_divider_t* pDividers                  ///< [out] pointer to array of dividers
        )
    {
        xe_result_t result = XE_RESULT_SUCCESS;

        return result;
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Intercept function for xetFreqDomainGetClockRange
    xe_result_t __xecall
    xetFreqDomainGetClockRange(
        xet_freq_domain_handle_t hFreqDomain,           ///< [in] handle of the frequency domain
        uint32_t* pMinClock,                            ///< [out] min clock frequency in units of MHz
        uint32_t* pMaxClock                             ///< [out] max clock frequency in units of MHz
        )
    {
        xe_result_t result = XE_RESULT_SUCCESS;

        return result;
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Intercept function for xetFreqDomainSetClockRange
    xe_result_t __xecall
    xetFreqDomainSetClockRange(
        xet_freq_domain_handle_t hFreqDomain,           ///< [in] handle of the frequency domain
        uint32_t minClock,                              ///< [in] min clock frequency in units of MHz
        uint32_t maxClock                               ///< [in] max clock frequency in units of MHz
        )
    {
        xe_result_t result = XE_RESULT_SUCCESS;

        return result;
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Intercept function for xetFreqDomainSetClockDivider
    xe_result_t __xecall
    xetFreqDomainSetClockDivider(
        xet_freq_domain_handle_t hFreqDomain,           ///< [in] handle of the frequency domain
        xet_clock_divider_t* pClockDividerRequest       ///< [out] pointer to frequency divider request
        )
    {
        xe_result_t result = XE_RESULT_SUCCESS;

        return result;
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Intercept function for xetFreqDomainGetCurrentFrequency
    xe_result_t __xecall
    xetFreqDomainGetCurrentFrequency(
        xet_freq_domain_handle_t hFreqDomain,           ///< [in] handle of the frequency domain
        uint32_t* pFreqRequest,                         ///< [out] current frequency in MHz requested by the driver
        uint32_t* pFreqResolved,                        ///< [out] the actual frequency in MHz
        xet_freq_throttle_reasons_t* pFreqThrottleReasons   ///< [out] the reason the resolved frequency is lower than the request
        )
    {
        xe_result_t result = XE_RESULT_SUCCESS;

        return result;
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Intercept function for xetPowerFanCount
    xe_result_t __xecall
    xetPowerFanCount(
        xet_power_handle_t hPower,                      ///< [in] handle of the power object
        uint32_t* pFanCount                             ///< [out] the number of fans on the device
        )
    {
        xe_result_t result = XE_RESULT_SUCCESS;

        return result;
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
        xe_result_t result = XE_RESULT_SUCCESS;

        return result;
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Intercept function for xetPowerFanGetSpeedTable
    xe_result_t __xecall
    xetPowerFanGetSpeedTable(
        xet_power_handle_t hPower,                      ///< [in] handle of the power object
        uint32_t fanIndex,                              ///< [in] fan index [0 .. ::xetPowerFanCount - 1]
        xe_bool_t fanSpeedInRpm,                        ///< [in] true will request fan speeds in RPM, otherwise in percentage
        uint32_t* pNumFanPoints,                        ///< [in,out] input number of elements in pFanSpeedTable array; output
                                                        ///< number of elements returned
        xet_fan_point_t* pFanPoints                     ///< [out] pointer to an array of temperature/fan-speed points
        )
    {
        xe_result_t result = XE_RESULT_SUCCESS;

        return result;
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
        xe_result_t result = XE_RESULT_SUCCESS;

        return result;
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
        xe_result_t result = XE_RESULT_SUCCESS;

        return result;
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
        xe_result_t result = XE_RESULT_SUCCESS;

        return result;
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Intercept function for xetPowerTemperatureSensorCount
    xe_result_t __xecall
    xetPowerTemperatureSensorCount(
        xet_power_handle_t hPower,                      ///< [in] handle of the power object
        uint32_t* pSensorCount                          ///< [out] the number of temperature sensors on the device
        )
    {
        xe_result_t result = XE_RESULT_SUCCESS;

        return result;
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
        xe_result_t result = XE_RESULT_SUCCESS;

        return result;
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
        xe_result_t result = XE_RESULT_SUCCESS;

        return result;
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
        xe_result_t result = XE_RESULT_SUCCESS;

        return result;
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Intercept function for xetPowerActivityCount
    xe_result_t __xecall
    xetPowerActivityCount(
        xet_power_handle_t hPower,                      ///< [in] handle of the power object
        uint32_t* pActivityCount                        ///< [out] the number of activity counters on the device
        )
    {
        xe_result_t result = XE_RESULT_SUCCESS;

        return result;
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
        xe_result_t result = XE_RESULT_SUCCESS;

        return result;
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
        xe_result_t result = XE_RESULT_SUCCESS;

        return result;
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Intercept function for xetDeviceGroupSetTracingPrologue
    xe_result_t __xecall
    xetDeviceGroupSetTracingPrologue(
        xet_device_group_handle_t hDeviceGroup,         ///< [in] handle of the device group
        xet_core_callbacks_t* pCoreCbs,                 ///< [in] pointer to table of 'core' callback function pointers
        xet_extended_callbacks_t* pExtendedCbs          ///< [in][optional] pointer to table of 'extended' callback function
                                                        ///< pointers
        )
    {
        xe_result_t result = XE_RESULT_SUCCESS;

        context.xePrologueCbs = *pCoreCbs;
        if( pExtendedCbs ) context.xexPrologueCbs = *pExtendedCbs;

        return result;
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Intercept function for xetDeviceGroupSetTracingEpilogue
    xe_result_t __xecall
    xetDeviceGroupSetTracingEpilogue(
        xet_device_group_handle_t hDeviceGroup,         ///< [in] handle of the device group
        xet_core_callbacks_t* pCoreCbs,                 ///< [in] pointer to table of 'core' callback function pointers
        xet_extended_callbacks_t* pExtendedCbs          ///< [in][optional] pointer to table of 'extended' callback function
                                                        ///< pointers
        )
    {
        xe_result_t result = XE_RESULT_SUCCESS;

        context.xeEpilogueCbs = *pCoreCbs;
        if( pExtendedCbs ) context.xexEpilogueCbs = *pExtendedCbs;

        return result;
    }

} // namespace driver

#if defined(__cplusplus)
extern "C" {
#endif

///////////////////////////////////////////////////////////////////////////////
/// @brief Exported function for filling application's Global table
///        with current process' addresses
///
/// @returns
///     - ::XE_RESULT_SUCCESS
///     - ::XE_RESULT_ERROR_INVALID_ARGUMENT
///         + invalid value for version
///         + nullptr for pDdiTable
///     - ::XE_RESULT_ERROR_UNSUPPORTED
///         + version not supported
__xedllexport xe_result_t __xecall
xetGetGlobalProcAddrTable(
    xe_api_version_t version,                       ///< [in] API version requested
    xet_global_dditable_t* pDdiTable                ///< [in,out] pointer to table of DDI function pointers
    )
{
    if( nullptr == pDdiTable )
        return XE_RESULT_ERROR_INVALID_ARGUMENT;

    if( driver::context.version < version )
        return XE_RESULT_ERROR_UNSUPPORTED;

    xe_result_t result = XE_RESULT_SUCCESS;

    pDdiTable->pfnInit                                   = driver::xetInit;

    return result;
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Exported function for filling application's DeviceGroup table
///        with current process' addresses
///
/// @returns
///     - ::XE_RESULT_SUCCESS
///     - ::XE_RESULT_ERROR_INVALID_ARGUMENT
///         + invalid value for version
///         + nullptr for pDdiTable
///     - ::XE_RESULT_ERROR_UNSUPPORTED
///         + version not supported
__xedllexport xe_result_t __xecall
xetGetDeviceGroupProcAddrTable(
    xe_api_version_t version,                       ///< [in] API version requested
    xet_device_group_dditable_t* pDdiTable          ///< [in,out] pointer to table of DDI function pointers
    )
{
    if( nullptr == pDdiTable )
        return XE_RESULT_ERROR_INVALID_ARGUMENT;

    if( driver::context.version < version )
        return XE_RESULT_ERROR_UNSUPPORTED;

    xe_result_t result = XE_RESULT_SUCCESS;

    pDdiTable->pfnSetTracingPrologue                     = driver::xetDeviceGroupSetTracingPrologue;

    pDdiTable->pfnSetTracingEpilogue                     = driver::xetDeviceGroupSetTracingEpilogue;

    return result;
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Exported function for filling application's Device table
///        with current process' addresses
///
/// @returns
///     - ::XE_RESULT_SUCCESS
///     - ::XE_RESULT_ERROR_INVALID_ARGUMENT
///         + invalid value for version
///         + nullptr for pDdiTable
///     - ::XE_RESULT_ERROR_UNSUPPORTED
///         + version not supported
__xedllexport xe_result_t __xecall
xetGetDeviceProcAddrTable(
    xe_api_version_t version,                       ///< [in] API version requested
    xet_device_dditable_t* pDdiTable                ///< [in,out] pointer to table of DDI function pointers
    )
{
    if( nullptr == pDdiTable )
        return XE_RESULT_ERROR_INVALID_ARGUMENT;

    if( driver::context.version < version )
        return XE_RESULT_ERROR_UNSUPPORTED;

    xe_result_t result = XE_RESULT_SUCCESS;

    pDdiTable->pfnActivateMetricGroups                   = driver::xetDeviceActivateMetricGroups;

    return result;
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Exported function for filling application's CommandList table
///        with current process' addresses
///
/// @returns
///     - ::XE_RESULT_SUCCESS
///     - ::XE_RESULT_ERROR_INVALID_ARGUMENT
///         + invalid value for version
///         + nullptr for pDdiTable
///     - ::XE_RESULT_ERROR_UNSUPPORTED
///         + version not supported
__xedllexport xe_result_t __xecall
xetGetCommandListProcAddrTable(
    xe_api_version_t version,                       ///< [in] API version requested
    xet_command_list_dditable_t* pDdiTable          ///< [in,out] pointer to table of DDI function pointers
    )
{
    if( nullptr == pDdiTable )
        return XE_RESULT_ERROR_INVALID_ARGUMENT;

    if( driver::context.version < version )
        return XE_RESULT_ERROR_UNSUPPORTED;

    xe_result_t result = XE_RESULT_SUCCESS;

    pDdiTable->pfnAppendMetricTracerMarker               = driver::xetCommandListAppendMetricTracerMarker;

    pDdiTable->pfnAppendMetricQueryBegin                 = driver::xetCommandListAppendMetricQueryBegin;

    pDdiTable->pfnAppendMetricQueryEnd                   = driver::xetCommandListAppendMetricQueryEnd;

    pDdiTable->pfnAppendMetricMemoryBarrier              = driver::xetCommandListAppendMetricMemoryBarrier;

    return result;
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Exported function for filling application's Module table
///        with current process' addresses
///
/// @returns
///     - ::XE_RESULT_SUCCESS
///     - ::XE_RESULT_ERROR_INVALID_ARGUMENT
///         + invalid value for version
///         + nullptr for pDdiTable
///     - ::XE_RESULT_ERROR_UNSUPPORTED
///         + version not supported
__xedllexport xe_result_t __xecall
xetGetModuleProcAddrTable(
    xe_api_version_t version,                       ///< [in] API version requested
    xet_module_dditable_t* pDdiTable                ///< [in,out] pointer to table of DDI function pointers
    )
{
    if( nullptr == pDdiTable )
        return XE_RESULT_ERROR_INVALID_ARGUMENT;

    if( driver::context.version < version )
        return XE_RESULT_ERROR_UNSUPPORTED;

    xe_result_t result = XE_RESULT_SUCCESS;

    pDdiTable->pfnGetDebugInfo                           = driver::xetModuleGetDebugInfo;

    pDdiTable->pfnAllocateExecutableMemory               = driver::xetModuleAllocateExecutableMemory;

    pDdiTable->pfnFreeExecutableMemory                   = driver::xetModuleFreeExecutableMemory;

    pDdiTable->pfnGetFunctionNames                       = driver::xetModuleGetFunctionNames;

    return result;
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Exported function for filling application's Function table
///        with current process' addresses
///
/// @returns
///     - ::XE_RESULT_SUCCESS
///     - ::XE_RESULT_ERROR_INVALID_ARGUMENT
///         + invalid value for version
///         + nullptr for pDdiTable
///     - ::XE_RESULT_ERROR_UNSUPPORTED
///         + version not supported
__xedllexport xe_result_t __xecall
xetGetFunctionProcAddrTable(
    xe_api_version_t version,                       ///< [in] API version requested
    xet_function_dditable_t* pDdiTable              ///< [in,out] pointer to table of DDI function pointers
    )
{
    if( nullptr == pDdiTable )
        return XE_RESULT_ERROR_INVALID_ARGUMENT;

    if( driver::context.version < version )
        return XE_RESULT_ERROR_UNSUPPORTED;

    xe_result_t result = XE_RESULT_SUCCESS;

    pDdiTable->pfnGetProfileInfo                         = driver::xetFunctionGetProfileInfo;

    pDdiTable->pfnSetAddress                             = driver::xetFunctionSetAddress;

    return result;
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Exported function for filling application's MetricGroup table
///        with current process' addresses
///
/// @returns
///     - ::XE_RESULT_SUCCESS
///     - ::XE_RESULT_ERROR_INVALID_ARGUMENT
///         + invalid value for version
///         + nullptr for pDdiTable
///     - ::XE_RESULT_ERROR_UNSUPPORTED
///         + version not supported
__xedllexport xe_result_t __xecall
xetGetMetricGroupProcAddrTable(
    xe_api_version_t version,                       ///< [in] API version requested
    xet_metric_group_dditable_t* pDdiTable          ///< [in,out] pointer to table of DDI function pointers
    )
{
    if( nullptr == pDdiTable )
        return XE_RESULT_ERROR_INVALID_ARGUMENT;

    if( driver::context.version < version )
        return XE_RESULT_ERROR_UNSUPPORTED;

    xe_result_t result = XE_RESULT_SUCCESS;

    pDdiTable->pfnGet                                    = driver::xetMetricGroupGet;

    pDdiTable->pfnGetProperties                          = driver::xetMetricGroupGetProperties;

    pDdiTable->pfnCalculateData                          = driver::xetMetricGroupCalculateData;

    return result;
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Exported function for filling application's Metric table
///        with current process' addresses
///
/// @returns
///     - ::XE_RESULT_SUCCESS
///     - ::XE_RESULT_ERROR_INVALID_ARGUMENT
///         + invalid value for version
///         + nullptr for pDdiTable
///     - ::XE_RESULT_ERROR_UNSUPPORTED
///         + version not supported
__xedllexport xe_result_t __xecall
xetGetMetricProcAddrTable(
    xe_api_version_t version,                       ///< [in] API version requested
    xet_metric_dditable_t* pDdiTable                ///< [in,out] pointer to table of DDI function pointers
    )
{
    if( nullptr == pDdiTable )
        return XE_RESULT_ERROR_INVALID_ARGUMENT;

    if( driver::context.version < version )
        return XE_RESULT_ERROR_UNSUPPORTED;

    xe_result_t result = XE_RESULT_SUCCESS;

    pDdiTable->pfnGet                                    = driver::xetMetricGet;

    pDdiTable->pfnGetProperties                          = driver::xetMetricGetProperties;

    return result;
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Exported function for filling application's MetricTracer table
///        with current process' addresses
///
/// @returns
///     - ::XE_RESULT_SUCCESS
///     - ::XE_RESULT_ERROR_INVALID_ARGUMENT
///         + invalid value for version
///         + nullptr for pDdiTable
///     - ::XE_RESULT_ERROR_UNSUPPORTED
///         + version not supported
__xedllexport xe_result_t __xecall
xetGetMetricTracerProcAddrTable(
    xe_api_version_t version,                       ///< [in] API version requested
    xet_metric_tracer_dditable_t* pDdiTable         ///< [in,out] pointer to table of DDI function pointers
    )
{
    if( nullptr == pDdiTable )
        return XE_RESULT_ERROR_INVALID_ARGUMENT;

    if( driver::context.version < version )
        return XE_RESULT_ERROR_UNSUPPORTED;

    xe_result_t result = XE_RESULT_SUCCESS;

    pDdiTable->pfnOpen                                   = driver::xetMetricTracerOpen;

    pDdiTable->pfnClose                                  = driver::xetMetricTracerClose;

    pDdiTable->pfnReadData                               = driver::xetMetricTracerReadData;

    return result;
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Exported function for filling application's MetricQueryPool table
///        with current process' addresses
///
/// @returns
///     - ::XE_RESULT_SUCCESS
///     - ::XE_RESULT_ERROR_INVALID_ARGUMENT
///         + invalid value for version
///         + nullptr for pDdiTable
///     - ::XE_RESULT_ERROR_UNSUPPORTED
///         + version not supported
__xedllexport xe_result_t __xecall
xetGetMetricQueryPoolProcAddrTable(
    xe_api_version_t version,                       ///< [in] API version requested
    xet_metric_query_pool_dditable_t* pDdiTable     ///< [in,out] pointer to table of DDI function pointers
    )
{
    if( nullptr == pDdiTable )
        return XE_RESULT_ERROR_INVALID_ARGUMENT;

    if( driver::context.version < version )
        return XE_RESULT_ERROR_UNSUPPORTED;

    xe_result_t result = XE_RESULT_SUCCESS;

    pDdiTable->pfnCreate                                 = driver::xetMetricQueryPoolCreate;

    pDdiTable->pfnDestroy                                = driver::xetMetricQueryPoolDestroy;

    return result;
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Exported function for filling application's MetricQuery table
///        with current process' addresses
///
/// @returns
///     - ::XE_RESULT_SUCCESS
///     - ::XE_RESULT_ERROR_INVALID_ARGUMENT
///         + invalid value for version
///         + nullptr for pDdiTable
///     - ::XE_RESULT_ERROR_UNSUPPORTED
///         + version not supported
__xedllexport xe_result_t __xecall
xetGetMetricQueryProcAddrTable(
    xe_api_version_t version,                       ///< [in] API version requested
    xet_metric_query_dditable_t* pDdiTable          ///< [in,out] pointer to table of DDI function pointers
    )
{
    if( nullptr == pDdiTable )
        return XE_RESULT_ERROR_INVALID_ARGUMENT;

    if( driver::context.version < version )
        return XE_RESULT_ERROR_UNSUPPORTED;

    xe_result_t result = XE_RESULT_SUCCESS;

    pDdiTable->pfnCreate                                 = driver::xetMetricQueryCreate;

    pDdiTable->pfnDestroy                                = driver::xetMetricQueryDestroy;

    pDdiTable->pfnReset                                  = driver::xetMetricQueryReset;

    pDdiTable->pfnGetData                                = driver::xetMetricQueryGetData;

    return result;
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Exported function for filling application's Power table
///        with current process' addresses
///
/// @returns
///     - ::XE_RESULT_SUCCESS
///     - ::XE_RESULT_ERROR_INVALID_ARGUMENT
///         + invalid value for version
///         + nullptr for pDdiTable
///     - ::XE_RESULT_ERROR_UNSUPPORTED
///         + version not supported
__xedllexport xe_result_t __xecall
xetGetPowerProcAddrTable(
    xe_api_version_t version,                       ///< [in] API version requested
    xet_power_dditable_t* pDdiTable                 ///< [in,out] pointer to table of DDI function pointers
    )
{
    if( nullptr == pDdiTable )
        return XE_RESULT_ERROR_INVALID_ARGUMENT;

    if( driver::context.version < version )
        return XE_RESULT_ERROR_UNSUPPORTED;

    xe_result_t result = XE_RESULT_SUCCESS;

    pDdiTable->pfnCreate                                 = driver::xetPowerCreate;

    pDdiTable->pfnDestroy                                = driver::xetPowerDestroy;

    pDdiTable->pfnGetAveragePowerLimit                   = driver::xetPowerGetAveragePowerLimit;

    pDdiTable->pfnGetBurstPowerLimit                     = driver::xetPowerGetBurstPowerLimit;

    pDdiTable->pfnGetPeakPowerLimit                      = driver::xetPowerGetPeakPowerLimit;

    pDdiTable->pfnGetAllPowerLimits                      = driver::xetPowerGetAllPowerLimits;

    pDdiTable->pfnGetDefaultPowerLimits                  = driver::xetPowerGetDefaultPowerLimits;

    pDdiTable->pfnSetAveragePowerLimit                   = driver::xetPowerSetAveragePowerLimit;

    pDdiTable->pfnSetBurstPowerLimit                     = driver::xetPowerSetBurstPowerLimit;

    pDdiTable->pfnSetPeakPowerLimit                      = driver::xetPowerSetPeakPowerLimit;

    pDdiTable->pfnSetPowerLimits                         = driver::xetPowerSetPowerLimits;

    pDdiTable->pfnGetEnergyCounter                       = driver::xetPowerGetEnergyCounter;

    pDdiTable->pfnGetTurboMode                           = driver::xetPowerGetTurboMode;

    pDdiTable->pfnSetTurboMode                           = driver::xetPowerSetTurboMode;

    pDdiTable->pfnFanCount                               = driver::xetPowerFanCount;

    pDdiTable->pfnFanGetProperties                       = driver::xetPowerFanGetProperties;

    pDdiTable->pfnFanGetSpeedTable                       = driver::xetPowerFanGetSpeedTable;

    pDdiTable->pfnFanSetSpeedTable                       = driver::xetPowerFanSetSpeedTable;

    pDdiTable->pfnFanGetSpeed                            = driver::xetPowerFanGetSpeed;

    pDdiTable->pfnFanSetSpeed                            = driver::xetPowerFanSetSpeed;

    pDdiTable->pfnTemperatureSensorCount                 = driver::xetPowerTemperatureSensorCount;

    pDdiTable->pfnGetTemperatureProperties               = driver::xetPowerGetTemperatureProperties;

    pDdiTable->pfnGetTemperature                         = driver::xetPowerGetTemperature;

    pDdiTable->pfnSetTemperatureThreshold                = driver::xetPowerSetTemperatureThreshold;

    pDdiTable->pfnActivityCount                          = driver::xetPowerActivityCount;

    pDdiTable->pfnGetActivityProperties                  = driver::xetPowerGetActivityProperties;

    pDdiTable->pfnGetActivityCounters                    = driver::xetPowerGetActivityCounters;

    return result;
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Exported function for filling application's FreqDomain table
///        with current process' addresses
///
/// @returns
///     - ::XE_RESULT_SUCCESS
///     - ::XE_RESULT_ERROR_INVALID_ARGUMENT
///         + invalid value for version
///         + nullptr for pDdiTable
///     - ::XE_RESULT_ERROR_UNSUPPORTED
///         + version not supported
__xedllexport xe_result_t __xecall
xetGetFreqDomainProcAddrTable(
    xe_api_version_t version,                       ///< [in] API version requested
    xet_freq_domain_dditable_t* pDdiTable           ///< [in,out] pointer to table of DDI function pointers
    )
{
    if( nullptr == pDdiTable )
        return XE_RESULT_ERROR_INVALID_ARGUMENT;

    if( driver::context.version < version )
        return XE_RESULT_ERROR_UNSUPPORTED;

    xe_result_t result = XE_RESULT_SUCCESS;

    pDdiTable->pfnGet                                    = driver::xetFreqDomainGet;

    pDdiTable->pfnGetProperties                          = driver::xetFreqDomainGetProperties;

    pDdiTable->pfnGetSourceFreqDomain                    = driver::xetFreqDomainGetSourceFreqDomain;

    pDdiTable->pfnGetSupportedClocks                     = driver::xetFreqDomainGetSupportedClocks;

    pDdiTable->pfnGetSupportedClockDividers              = driver::xetFreqDomainGetSupportedClockDividers;

    pDdiTable->pfnGetClockRange                          = driver::xetFreqDomainGetClockRange;

    pDdiTable->pfnSetClockRange                          = driver::xetFreqDomainSetClockRange;

    pDdiTable->pfnSetClockDivider                        = driver::xetFreqDomainSetClockDivider;

    pDdiTable->pfnGetCurrentFrequency                    = driver::xetFreqDomainGetCurrentFrequency;

    return result;
}

#if defined(__cplusplus)
};
#endif