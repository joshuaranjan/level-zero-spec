/*
 *
 * Copyright (C) 2019 Intel Corporation
 *
 * SPDX-License-Identifier: MIT
 *
 * @file zet_ldrddi.cpp
 * @version v0.91-275
 *
 */
#include "ze_loader.h"

namespace loader
{
    ///////////////////////////////////////////////////////////////////////////////
    zet_driver_factory_t                zet_driver_factory;
    zet_device_factory_t                zet_device_factory;
    zet_command_list_factory_t          zet_command_list_factory;
    zet_module_factory_t                zet_module_factory;
    zet_kernel_factory_t                zet_kernel_factory;
    zet_metric_group_factory_t          zet_metric_group_factory;
    zet_metric_factory_t                zet_metric_factory;
    zet_metric_tracer_factory_t         zet_metric_tracer_factory;
    zet_metric_query_pool_factory_t     zet_metric_query_pool_factory;
    zet_metric_query_factory_t          zet_metric_query_factory;
    zet_tracer_factory_t                zet_tracer_factory;
    zet_debug_session_factory_t         zet_debug_session_factory;

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Intercept function for zetDebugAttach
    __zedlllocal ze_result_t __zecall
    zetDebugAttach(
        zet_device_handle_t hDevice,                    ///< [in] device handle
        const zet_debug_config_t* config,               ///< [in] the debug configuration
        zet_debug_session_handle_t* hDebug              ///< [out] debug session handle
        )
    {
        ze_result_t result = ZE_RESULT_SUCCESS;

        // extract driver's function pointer table
        auto dditable = reinterpret_cast<zet_device_object_t*>( hDevice )->dditable;
        auto pfnAttach = dditable->zet.Debug.pfnAttach;
        if( nullptr == pfnAttach )
            return ZE_RESULT_ERROR_UNSUPPORTED_VERSION;

        // convert loader handle to driver handle
        hDevice = reinterpret_cast<zet_device_object_t*>( hDevice )->handle;

        // forward to device-driver
        result = pfnAttach( hDevice, config, hDebug );

        try
        {
            // convert driver handle to loader handle
            *hDebug = reinterpret_cast<zet_debug_session_handle_t>(
                zet_debug_session_factory.getInstance( *hDebug, dditable ) );
        }
        catch( std::bad_alloc& )
        {
            result = ZE_RESULT_ERROR_OUT_OF_HOST_MEMORY;
        }

        return result;
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Intercept function for zetDebugDetach
    __zedlllocal ze_result_t __zecall
    zetDebugDetach(
        zet_debug_session_handle_t hDebug               ///< [in][release] debug session handle
        )
    {
        ze_result_t result = ZE_RESULT_SUCCESS;

        // extract driver's function pointer table
        auto dditable = reinterpret_cast<zet_debug_session_object_t*>( hDebug )->dditable;
        auto pfnDetach = dditable->zet.Debug.pfnDetach;
        if( nullptr == pfnDetach )
            return ZE_RESULT_ERROR_UNSUPPORTED_VERSION;

        // convert loader handle to driver handle
        hDebug = reinterpret_cast<zet_debug_session_object_t*>( hDebug )->handle;

        // forward to device-driver
        result = pfnDetach( hDebug );

        // release loader handle
        zet_debug_session_factory.release( hDebug );

        return result;
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Intercept function for zetDebugGetNumThreads
    __zedlllocal ze_result_t __zecall
    zetDebugGetNumThreads(
        zet_debug_session_handle_t hDebug,              ///< [in] debug session handle
        uint64_t* pNumThreads                           ///< [out] the maximal number of threads
        )
    {
        ze_result_t result = ZE_RESULT_SUCCESS;

        // extract driver's function pointer table
        auto dditable = reinterpret_cast<zet_debug_session_object_t*>( hDebug )->dditable;
        auto pfnGetNumThreads = dditable->zet.Debug.pfnGetNumThreads;
        if( nullptr == pfnGetNumThreads )
            return ZE_RESULT_ERROR_UNSUPPORTED_VERSION;

        // convert loader handle to driver handle
        hDebug = reinterpret_cast<zet_debug_session_object_t*>( hDebug )->handle;

        // forward to device-driver
        result = pfnGetNumThreads( hDebug, pNumThreads );

        return result;
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Intercept function for zetDebugReadEvent
    __zedlllocal ze_result_t __zecall
    zetDebugReadEvent(
        zet_debug_session_handle_t hDebug,              ///< [in] debug session handle
        uint64_t timeout,                               ///< [in] timeout in milliseconds (or ::ZET_DEBUG_TIMEOUT_INFINITE)
        size_t size,                                    ///< [in] the size of the buffer in bytes
        void* buffer                                    ///< [in,out] a buffer to hold the event data
        )
    {
        ze_result_t result = ZE_RESULT_SUCCESS;

        // extract driver's function pointer table
        auto dditable = reinterpret_cast<zet_debug_session_object_t*>( hDebug )->dditable;
        auto pfnReadEvent = dditable->zet.Debug.pfnReadEvent;
        if( nullptr == pfnReadEvent )
            return ZE_RESULT_ERROR_UNSUPPORTED_VERSION;

        // convert loader handle to driver handle
        hDebug = reinterpret_cast<zet_debug_session_object_t*>( hDebug )->handle;

        // forward to device-driver
        result = pfnReadEvent( hDebug, timeout, size, buffer );

        return result;
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Intercept function for zetDebugInterrupt
    __zedlllocal ze_result_t __zecall
    zetDebugInterrupt(
        zet_debug_session_handle_t hDebug,              ///< [in] debug session handle
        uint64_t threadid                               ///< [in] the thread to inerrupt or ::ZET_DEBUG_THREAD_ALL
        )
    {
        ze_result_t result = ZE_RESULT_SUCCESS;

        // extract driver's function pointer table
        auto dditable = reinterpret_cast<zet_debug_session_object_t*>( hDebug )->dditable;
        auto pfnInterrupt = dditable->zet.Debug.pfnInterrupt;
        if( nullptr == pfnInterrupt )
            return ZE_RESULT_ERROR_UNSUPPORTED_VERSION;

        // convert loader handle to driver handle
        hDebug = reinterpret_cast<zet_debug_session_object_t*>( hDebug )->handle;

        // forward to device-driver
        result = pfnInterrupt( hDebug, threadid );

        return result;
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Intercept function for zetDebugResume
    __zedlllocal ze_result_t __zecall
    zetDebugResume(
        zet_debug_session_handle_t hDebug,              ///< [in] debug session handle
        uint64_t threadid                               ///< [in] the thread to resume or ::ZET_DEBUG_THREAD_ALL
        )
    {
        ze_result_t result = ZE_RESULT_SUCCESS;

        // extract driver's function pointer table
        auto dditable = reinterpret_cast<zet_debug_session_object_t*>( hDebug )->dditable;
        auto pfnResume = dditable->zet.Debug.pfnResume;
        if( nullptr == pfnResume )
            return ZE_RESULT_ERROR_UNSUPPORTED_VERSION;

        // convert loader handle to driver handle
        hDebug = reinterpret_cast<zet_debug_session_object_t*>( hDebug )->handle;

        // forward to device-driver
        result = pfnResume( hDebug, threadid );

        return result;
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Intercept function for zetDebugReadMemory
    __zedlllocal ze_result_t __zecall
    zetDebugReadMemory(
        zet_debug_session_handle_t hDebug,              ///< [in] debug session handle
        uint64_t threadid,                              ///< [in] the thread context or ::ZET_DEBUG_THREAD_NONE
        int memSpace,                                   ///< [in] the (device-specific) memory space
        uint64_t address,                               ///< [in] the virtual address of the memory to read from
        size_t size,                                    ///< [in] the number of bytes to read
        void* buffer                                    ///< [in,out] a buffer to hold a copy of the memory
        )
    {
        ze_result_t result = ZE_RESULT_SUCCESS;

        // extract driver's function pointer table
        auto dditable = reinterpret_cast<zet_debug_session_object_t*>( hDebug )->dditable;
        auto pfnReadMemory = dditable->zet.Debug.pfnReadMemory;
        if( nullptr == pfnReadMemory )
            return ZE_RESULT_ERROR_UNSUPPORTED_VERSION;

        // convert loader handle to driver handle
        hDebug = reinterpret_cast<zet_debug_session_object_t*>( hDebug )->handle;

        // forward to device-driver
        result = pfnReadMemory( hDebug, threadid, memSpace, address, size, buffer );

        return result;
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Intercept function for zetDebugWriteMemory
    __zedlllocal ze_result_t __zecall
    zetDebugWriteMemory(
        zet_debug_session_handle_t hDebug,              ///< [in] debug session handle
        uint64_t threadid,                              ///< [in] the thread context or ::ZET_DEBUG_THREAD_NONE
        int memSpace,                                   ///< [in] the (device-specific) memory space
        uint64_t address,                               ///< [in] the virtual address of the memory to write to
        size_t size,                                    ///< [in] the number of bytes to write
        const void* buffer                              ///< [in] a buffer holding the pattern to write
        )
    {
        ze_result_t result = ZE_RESULT_SUCCESS;

        // extract driver's function pointer table
        auto dditable = reinterpret_cast<zet_debug_session_object_t*>( hDebug )->dditable;
        auto pfnWriteMemory = dditable->zet.Debug.pfnWriteMemory;
        if( nullptr == pfnWriteMemory )
            return ZE_RESULT_ERROR_UNSUPPORTED_VERSION;

        // convert loader handle to driver handle
        hDebug = reinterpret_cast<zet_debug_session_object_t*>( hDebug )->handle;

        // forward to device-driver
        result = pfnWriteMemory( hDebug, threadid, memSpace, address, size, buffer );

        return result;
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Intercept function for zetDebugReadState
    __zedlllocal ze_result_t __zecall
    zetDebugReadState(
        zet_debug_session_handle_t hDebug,              ///< [in] debug session handle
        uint64_t threadid,                              ///< [in] the thread context
        uint64_t offset,                                ///< [in] the offset into the register state area
        size_t size,                                    ///< [in] the number of bytes to read
        void* buffer                                    ///< [in,out] a buffer to hold a copy of the register state
        )
    {
        ze_result_t result = ZE_RESULT_SUCCESS;

        // extract driver's function pointer table
        auto dditable = reinterpret_cast<zet_debug_session_object_t*>( hDebug )->dditable;
        auto pfnReadState = dditable->zet.Debug.pfnReadState;
        if( nullptr == pfnReadState )
            return ZE_RESULT_ERROR_UNSUPPORTED_VERSION;

        // convert loader handle to driver handle
        hDebug = reinterpret_cast<zet_debug_session_object_t*>( hDebug )->handle;

        // forward to device-driver
        result = pfnReadState( hDebug, threadid, offset, size, buffer );

        return result;
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Intercept function for zetDebugWriteState
    __zedlllocal ze_result_t __zecall
    zetDebugWriteState(
        zet_debug_session_handle_t hDebug,              ///< [in] debug session handle
        uint64_t threadid,                              ///< [in] the thread context
        uint64_t offset,                                ///< [in] the offset into the register state area
        size_t size,                                    ///< [in] the number of bytes to write
        const void* buffer                              ///< [in] a buffer holding the pattern to write
        )
    {
        ze_result_t result = ZE_RESULT_SUCCESS;

        // extract driver's function pointer table
        auto dditable = reinterpret_cast<zet_debug_session_object_t*>( hDebug )->dditable;
        auto pfnWriteState = dditable->zet.Debug.pfnWriteState;
        if( nullptr == pfnWriteState )
            return ZE_RESULT_ERROR_UNSUPPORTED_VERSION;

        // convert loader handle to driver handle
        hDebug = reinterpret_cast<zet_debug_session_object_t*>( hDebug )->handle;

        // forward to device-driver
        result = pfnWriteState( hDebug, threadid, offset, size, buffer );

        return result;
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Intercept function for zetMetricGroupGet
    __zedlllocal ze_result_t __zecall
    zetMetricGroupGet(
        zet_device_handle_t hDevice,                    ///< [in] handle of the device
        uint32_t* pCount,                               ///< [in,out] pointer to the number of metric groups.
                                                        ///< if count is zero, then the driver will update the value with the total
                                                        ///< number of metric groups available.
                                                        ///< if count is non-zero, then driver will only retrieve that number of
                                                        ///< metric groups.
                                                        ///< if count is larger than the number of metric groups available, then
                                                        ///< the driver will update the value with the correct number of metric
                                                        ///< groups available.
        zet_metric_group_handle_t* phMetricGroups       ///< [in,out][optional][range(0, *pCount)] array of handle of metric groups
        )
    {
        ze_result_t result = ZE_RESULT_SUCCESS;

        // extract driver's function pointer table
        auto dditable = reinterpret_cast<zet_device_object_t*>( hDevice )->dditable;
        auto pfnGet = dditable->zet.MetricGroup.pfnGet;
        if( nullptr == pfnGet )
            return ZE_RESULT_ERROR_UNSUPPORTED_VERSION;

        // convert loader handle to driver handle
        hDevice = reinterpret_cast<zet_device_object_t*>( hDevice )->handle;

        // forward to device-driver
        result = pfnGet( hDevice, pCount, phMetricGroups );

        try
        {
            // convert driver handles to loader handles
            for( size_t i = 0; ( nullptr != phMetricGroups ) && ( i < *pCount ); ++i )
                phMetricGroups[ i ] = reinterpret_cast<zet_metric_group_handle_t>(
                    zet_metric_group_factory.getInstance( phMetricGroups[ i ], dditable ) );
        }
        catch( std::bad_alloc& )
        {
            result = ZE_RESULT_ERROR_OUT_OF_HOST_MEMORY;
        }

        return result;
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Intercept function for zetMetricGroupGetProperties
    __zedlllocal ze_result_t __zecall
    zetMetricGroupGetProperties(
        zet_metric_group_handle_t hMetricGroup,         ///< [in] handle of the metric group
        zet_metric_group_properties_t* pProperties      ///< [in,out] metric group properties
        )
    {
        ze_result_t result = ZE_RESULT_SUCCESS;

        // extract driver's function pointer table
        auto dditable = reinterpret_cast<zet_metric_group_object_t*>( hMetricGroup )->dditable;
        auto pfnGetProperties = dditable->zet.MetricGroup.pfnGetProperties;
        if( nullptr == pfnGetProperties )
            return ZE_RESULT_ERROR_UNSUPPORTED_VERSION;

        // convert loader handle to driver handle
        hMetricGroup = reinterpret_cast<zet_metric_group_object_t*>( hMetricGroup )->handle;

        // forward to device-driver
        result = pfnGetProperties( hMetricGroup, pProperties );

        return result;
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Intercept function for zetMetricGroupCalculateMetricValues
    __zedlllocal ze_result_t __zecall
    zetMetricGroupCalculateMetricValues(
        zet_metric_group_handle_t hMetricGroup,         ///< [in] handle of the metric group
        size_t rawDataSize,                             ///< [in] size in bytes of raw data buffer
        const uint8_t* pRawData,                        ///< [in][range(0, rawDataSize)] buffer of raw data to calculate
        uint32_t* pMetricValueCount,                    ///< [in,out] pointer to number of metric values calculated.
                                                        ///< if count is zero, then the driver will update the value with the total
                                                        ///< number of metric values to be calculated.
                                                        ///< if count is non-zero, then driver will only calculate that number of
                                                        ///< metric values.
                                                        ///< if count is larger than the number available in the raw data buffer,
                                                        ///< then the driver will update the value with the actual number of metric
                                                        ///< values to be calculated.
        zet_typed_value_t* pMetricValues                ///< [in,out][optional][range(0, *pMetricValueCount)] buffer of calculated
                                                        ///< metrics
        )
    {
        ze_result_t result = ZE_RESULT_SUCCESS;

        // extract driver's function pointer table
        auto dditable = reinterpret_cast<zet_metric_group_object_t*>( hMetricGroup )->dditable;
        auto pfnCalculateMetricValues = dditable->zet.MetricGroup.pfnCalculateMetricValues;
        if( nullptr == pfnCalculateMetricValues )
            return ZE_RESULT_ERROR_UNSUPPORTED_VERSION;

        // convert loader handle to driver handle
        hMetricGroup = reinterpret_cast<zet_metric_group_object_t*>( hMetricGroup )->handle;

        // forward to device-driver
        result = pfnCalculateMetricValues( hMetricGroup, rawDataSize, pRawData, pMetricValueCount, pMetricValues );

        return result;
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Intercept function for zetMetricGet
    __zedlllocal ze_result_t __zecall
    zetMetricGet(
        zet_metric_group_handle_t hMetricGroup,         ///< [in] handle of the metric group
        uint32_t* pCount,                               ///< [in,out] pointer to the number of metrics.
                                                        ///< if count is zero, then the driver will update the value with the total
                                                        ///< number of metrics available.
                                                        ///< if count is non-zero, then driver will only retrieve that number of metrics.
                                                        ///< if count is larger than the number of metrics available, then the
                                                        ///< driver will update the value with the correct number of metrics available.
        zet_metric_handle_t* phMetrics                  ///< [in,out][optional][range(0, *pCount)] array of handle of metrics
        )
    {
        ze_result_t result = ZE_RESULT_SUCCESS;

        // extract driver's function pointer table
        auto dditable = reinterpret_cast<zet_metric_group_object_t*>( hMetricGroup )->dditable;
        auto pfnGet = dditable->zet.Metric.pfnGet;
        if( nullptr == pfnGet )
            return ZE_RESULT_ERROR_UNSUPPORTED_VERSION;

        // convert loader handle to driver handle
        hMetricGroup = reinterpret_cast<zet_metric_group_object_t*>( hMetricGroup )->handle;

        // forward to device-driver
        result = pfnGet( hMetricGroup, pCount, phMetrics );

        try
        {
            // convert driver handles to loader handles
            for( size_t i = 0; ( nullptr != phMetrics ) && ( i < *pCount ); ++i )
                phMetrics[ i ] = reinterpret_cast<zet_metric_handle_t>(
                    zet_metric_factory.getInstance( phMetrics[ i ], dditable ) );
        }
        catch( std::bad_alloc& )
        {
            result = ZE_RESULT_ERROR_OUT_OF_HOST_MEMORY;
        }

        return result;
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Intercept function for zetMetricGetProperties
    __zedlllocal ze_result_t __zecall
    zetMetricGetProperties(
        zet_metric_handle_t hMetric,                    ///< [in] handle of the metric
        zet_metric_properties_t* pProperties            ///< [in,out] metric properties
        )
    {
        ze_result_t result = ZE_RESULT_SUCCESS;

        // extract driver's function pointer table
        auto dditable = reinterpret_cast<zet_metric_object_t*>( hMetric )->dditable;
        auto pfnGetProperties = dditable->zet.Metric.pfnGetProperties;
        if( nullptr == pfnGetProperties )
            return ZE_RESULT_ERROR_UNSUPPORTED_VERSION;

        // convert loader handle to driver handle
        hMetric = reinterpret_cast<zet_metric_object_t*>( hMetric )->handle;

        // forward to device-driver
        result = pfnGetProperties( hMetric, pProperties );

        return result;
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Intercept function for zetDeviceActivateMetricGroups
    __zedlllocal ze_result_t __zecall
    zetDeviceActivateMetricGroups(
        zet_device_handle_t hDevice,                    ///< [in] handle of the device
        uint32_t count,                                 ///< [in] metric group count to activate. 0 to deactivate.
        zet_metric_group_handle_t* phMetricGroups       ///< [in][optional][range(0, count)] handles of the metric groups to
                                                        ///< activate. NULL to deactivate.
        )
    {
        ze_result_t result = ZE_RESULT_SUCCESS;

        // extract driver's function pointer table
        auto dditable = reinterpret_cast<zet_device_object_t*>( hDevice )->dditable;
        auto pfnActivateMetricGroups = dditable->zet.Device.pfnActivateMetricGroups;
        if( nullptr == pfnActivateMetricGroups )
            return ZE_RESULT_ERROR_UNSUPPORTED_VERSION;

        // convert loader handle to driver handle
        hDevice = reinterpret_cast<zet_device_object_t*>( hDevice )->handle;

        // convert loader handles to driver handles
        for( size_t i = 0; ( nullptr != phMetricGroups ) && ( i < count ); ++i )
            phMetricGroups[ i ] = reinterpret_cast<zet_metric_group_object_t*>( phMetricGroups[ i ] )->handle;

        // forward to device-driver
        result = pfnActivateMetricGroups( hDevice, count, phMetricGroups );

        return result;
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Intercept function for zetMetricTracerOpen
    __zedlllocal ze_result_t __zecall
    zetMetricTracerOpen(
        zet_device_handle_t hDevice,                    ///< [in] handle of the device
        zet_metric_group_handle_t hMetricGroup,         ///< [in] handle of the metric group
        zet_metric_tracer_desc_t* desc,                 ///< [in,out] metric tracer descriptor
        ze_event_handle_t hNotificationEvent,           ///< [in][optional] event used for report availability notification. Must
                                                        ///< be device to host type.
        zet_metric_tracer_handle_t* phMetricTracer      ///< [out] handle of metric tracer
        )
    {
        ze_result_t result = ZE_RESULT_SUCCESS;

        // extract driver's function pointer table
        auto dditable = reinterpret_cast<zet_device_object_t*>( hDevice )->dditable;
        auto pfnOpen = dditable->zet.MetricTracer.pfnOpen;
        if( nullptr == pfnOpen )
            return ZE_RESULT_ERROR_UNSUPPORTED_VERSION;

        // convert loader handle to driver handle
        hDevice = reinterpret_cast<zet_device_object_t*>( hDevice )->handle;

        // convert loader handle to driver handle
        hMetricGroup = reinterpret_cast<zet_metric_group_object_t*>( hMetricGroup )->handle;

        // convert loader handle to driver handle
        hNotificationEvent = ( hNotificationEvent ) ? reinterpret_cast<ze_event_object_t*>( hNotificationEvent )->handle : nullptr;

        // forward to device-driver
        result = pfnOpen( hDevice, hMetricGroup, desc, hNotificationEvent, phMetricTracer );

        try
        {
            // convert driver handle to loader handle
            *phMetricTracer = reinterpret_cast<zet_metric_tracer_handle_t>(
                zet_metric_tracer_factory.getInstance( *phMetricTracer, dditable ) );
        }
        catch( std::bad_alloc& )
        {
            result = ZE_RESULT_ERROR_OUT_OF_HOST_MEMORY;
        }

        return result;
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Intercept function for zetCommandListAppendMetricTracerMarker
    __zedlllocal ze_result_t __zecall
    zetCommandListAppendMetricTracerMarker(
        zet_command_list_handle_t hCommandList,         ///< [in] handle of the command list
        zet_metric_tracer_handle_t hMetricTracer,       ///< [in] handle of the metric tracer
        uint32_t value                                  ///< [in] tracer marker value
        )
    {
        ze_result_t result = ZE_RESULT_SUCCESS;

        // extract driver's function pointer table
        auto dditable = reinterpret_cast<zet_command_list_object_t*>( hCommandList )->dditable;
        auto pfnAppendMetricTracerMarker = dditable->zet.CommandList.pfnAppendMetricTracerMarker;
        if( nullptr == pfnAppendMetricTracerMarker )
            return ZE_RESULT_ERROR_UNSUPPORTED_VERSION;

        // convert loader handle to driver handle
        hCommandList = reinterpret_cast<zet_command_list_object_t*>( hCommandList )->handle;

        // convert loader handle to driver handle
        hMetricTracer = reinterpret_cast<zet_metric_tracer_object_t*>( hMetricTracer )->handle;

        // forward to device-driver
        result = pfnAppendMetricTracerMarker( hCommandList, hMetricTracer, value );

        return result;
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Intercept function for zetMetricTracerClose
    __zedlllocal ze_result_t __zecall
    zetMetricTracerClose(
        zet_metric_tracer_handle_t hMetricTracer        ///< [in][release] handle of the metric tracer
        )
    {
        ze_result_t result = ZE_RESULT_SUCCESS;

        // extract driver's function pointer table
        auto dditable = reinterpret_cast<zet_metric_tracer_object_t*>( hMetricTracer )->dditable;
        auto pfnClose = dditable->zet.MetricTracer.pfnClose;
        if( nullptr == pfnClose )
            return ZE_RESULT_ERROR_UNSUPPORTED_VERSION;

        // convert loader handle to driver handle
        hMetricTracer = reinterpret_cast<zet_metric_tracer_object_t*>( hMetricTracer )->handle;

        // forward to device-driver
        result = pfnClose( hMetricTracer );

        // release loader handle
        zet_metric_tracer_factory.release( hMetricTracer );

        return result;
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Intercept function for zetMetricTracerReadData
    __zedlllocal ze_result_t __zecall
    zetMetricTracerReadData(
        zet_metric_tracer_handle_t hMetricTracer,       ///< [in] handle of the metric tracer
        uint32_t maxReportCount,                        ///< [in] the maximum number of reports the application wants to receive.
                                                        ///< if UINT32_MAX, then function will retrieve all reports available
        size_t* pRawDataSize,                           ///< [in,out] pointer to size in bytes of raw data requested to read.
                                                        ///< if size is zero, then the driver will update the value with the total
                                                        ///< size in bytes needed for all reports available.
                                                        ///< if size is non-zero, then driver will only retrieve the number of
                                                        ///< reports that fit into the buffer.
                                                        ///< if size is larger than size needed for all reports, then driver will
                                                        ///< update the value with the actual size needed.
        uint8_t* pRawData                               ///< [in,out][optional][range(0, *pRawDataSize)] buffer containing tracer
                                                        ///< reports in raw format
        )
    {
        ze_result_t result = ZE_RESULT_SUCCESS;

        // extract driver's function pointer table
        auto dditable = reinterpret_cast<zet_metric_tracer_object_t*>( hMetricTracer )->dditable;
        auto pfnReadData = dditable->zet.MetricTracer.pfnReadData;
        if( nullptr == pfnReadData )
            return ZE_RESULT_ERROR_UNSUPPORTED_VERSION;

        // convert loader handle to driver handle
        hMetricTracer = reinterpret_cast<zet_metric_tracer_object_t*>( hMetricTracer )->handle;

        // forward to device-driver
        result = pfnReadData( hMetricTracer, maxReportCount, pRawDataSize, pRawData );

        return result;
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Intercept function for zetMetricQueryPoolCreate
    __zedlllocal ze_result_t __zecall
    zetMetricQueryPoolCreate(
        zet_device_handle_t hDevice,                    ///< [in] handle of the device
        zet_metric_group_handle_t hMetricGroup,         ///< [in] metric group associated with the query object.
        const zet_metric_query_pool_desc_t* desc,       ///< [in] metric query pool descriptor
        zet_metric_query_pool_handle_t* phMetricQueryPool   ///< [out] handle of metric query pool
        )
    {
        ze_result_t result = ZE_RESULT_SUCCESS;

        // extract driver's function pointer table
        auto dditable = reinterpret_cast<zet_device_object_t*>( hDevice )->dditable;
        auto pfnCreate = dditable->zet.MetricQueryPool.pfnCreate;
        if( nullptr == pfnCreate )
            return ZE_RESULT_ERROR_UNSUPPORTED_VERSION;

        // convert loader handle to driver handle
        hDevice = reinterpret_cast<zet_device_object_t*>( hDevice )->handle;

        // convert loader handle to driver handle
        hMetricGroup = reinterpret_cast<zet_metric_group_object_t*>( hMetricGroup )->handle;

        // forward to device-driver
        result = pfnCreate( hDevice, hMetricGroup, desc, phMetricQueryPool );

        try
        {
            // convert driver handle to loader handle
            *phMetricQueryPool = reinterpret_cast<zet_metric_query_pool_handle_t>(
                zet_metric_query_pool_factory.getInstance( *phMetricQueryPool, dditable ) );
        }
        catch( std::bad_alloc& )
        {
            result = ZE_RESULT_ERROR_OUT_OF_HOST_MEMORY;
        }

        return result;
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Intercept function for zetMetricQueryPoolDestroy
    __zedlllocal ze_result_t __zecall
    zetMetricQueryPoolDestroy(
        zet_metric_query_pool_handle_t hMetricQueryPool ///< [in][release] handle of the metric query pool
        )
    {
        ze_result_t result = ZE_RESULT_SUCCESS;

        // extract driver's function pointer table
        auto dditable = reinterpret_cast<zet_metric_query_pool_object_t*>( hMetricQueryPool )->dditable;
        auto pfnDestroy = dditable->zet.MetricQueryPool.pfnDestroy;
        if( nullptr == pfnDestroy )
            return ZE_RESULT_ERROR_UNSUPPORTED_VERSION;

        // convert loader handle to driver handle
        hMetricQueryPool = reinterpret_cast<zet_metric_query_pool_object_t*>( hMetricQueryPool )->handle;

        // forward to device-driver
        result = pfnDestroy( hMetricQueryPool );

        // release loader handle
        zet_metric_query_pool_factory.release( hMetricQueryPool );

        return result;
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Intercept function for zetMetricQueryCreate
    __zedlllocal ze_result_t __zecall
    zetMetricQueryCreate(
        zet_metric_query_pool_handle_t hMetricQueryPool,///< [in] handle of the metric query pool
        uint32_t index,                                 ///< [in] index of the query within the pool
        zet_metric_query_handle_t* phMetricQuery        ///< [out] handle of metric query
        )
    {
        ze_result_t result = ZE_RESULT_SUCCESS;

        // extract driver's function pointer table
        auto dditable = reinterpret_cast<zet_metric_query_pool_object_t*>( hMetricQueryPool )->dditable;
        auto pfnCreate = dditable->zet.MetricQuery.pfnCreate;
        if( nullptr == pfnCreate )
            return ZE_RESULT_ERROR_UNSUPPORTED_VERSION;

        // convert loader handle to driver handle
        hMetricQueryPool = reinterpret_cast<zet_metric_query_pool_object_t*>( hMetricQueryPool )->handle;

        // forward to device-driver
        result = pfnCreate( hMetricQueryPool, index, phMetricQuery );

        try
        {
            // convert driver handle to loader handle
            *phMetricQuery = reinterpret_cast<zet_metric_query_handle_t>(
                zet_metric_query_factory.getInstance( *phMetricQuery, dditable ) );
        }
        catch( std::bad_alloc& )
        {
            result = ZE_RESULT_ERROR_OUT_OF_HOST_MEMORY;
        }

        return result;
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Intercept function for zetMetricQueryDestroy
    __zedlllocal ze_result_t __zecall
    zetMetricQueryDestroy(
        zet_metric_query_handle_t hMetricQuery          ///< [in][release] handle of metric query
        )
    {
        ze_result_t result = ZE_RESULT_SUCCESS;

        // extract driver's function pointer table
        auto dditable = reinterpret_cast<zet_metric_query_object_t*>( hMetricQuery )->dditable;
        auto pfnDestroy = dditable->zet.MetricQuery.pfnDestroy;
        if( nullptr == pfnDestroy )
            return ZE_RESULT_ERROR_UNSUPPORTED_VERSION;

        // convert loader handle to driver handle
        hMetricQuery = reinterpret_cast<zet_metric_query_object_t*>( hMetricQuery )->handle;

        // forward to device-driver
        result = pfnDestroy( hMetricQuery );

        // release loader handle
        zet_metric_query_factory.release( hMetricQuery );

        return result;
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Intercept function for zetMetricQueryReset
    __zedlllocal ze_result_t __zecall
    zetMetricQueryReset(
        zet_metric_query_handle_t hMetricQuery          ///< [in] handle of metric query
        )
    {
        ze_result_t result = ZE_RESULT_SUCCESS;

        // extract driver's function pointer table
        auto dditable = reinterpret_cast<zet_metric_query_object_t*>( hMetricQuery )->dditable;
        auto pfnReset = dditable->zet.MetricQuery.pfnReset;
        if( nullptr == pfnReset )
            return ZE_RESULT_ERROR_UNSUPPORTED_VERSION;

        // convert loader handle to driver handle
        hMetricQuery = reinterpret_cast<zet_metric_query_object_t*>( hMetricQuery )->handle;

        // forward to device-driver
        result = pfnReset( hMetricQuery );

        return result;
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Intercept function for zetCommandListAppendMetricQueryBegin
    __zedlllocal ze_result_t __zecall
    zetCommandListAppendMetricQueryBegin(
        zet_command_list_handle_t hCommandList,         ///< [in] handle of the command list
        zet_metric_query_handle_t hMetricQuery          ///< [in] handle of the metric query
        )
    {
        ze_result_t result = ZE_RESULT_SUCCESS;

        // extract driver's function pointer table
        auto dditable = reinterpret_cast<zet_command_list_object_t*>( hCommandList )->dditable;
        auto pfnAppendMetricQueryBegin = dditable->zet.CommandList.pfnAppendMetricQueryBegin;
        if( nullptr == pfnAppendMetricQueryBegin )
            return ZE_RESULT_ERROR_UNSUPPORTED_VERSION;

        // convert loader handle to driver handle
        hCommandList = reinterpret_cast<zet_command_list_object_t*>( hCommandList )->handle;

        // convert loader handle to driver handle
        hMetricQuery = reinterpret_cast<zet_metric_query_object_t*>( hMetricQuery )->handle;

        // forward to device-driver
        result = pfnAppendMetricQueryBegin( hCommandList, hMetricQuery );

        return result;
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Intercept function for zetCommandListAppendMetricQueryEnd
    __zedlllocal ze_result_t __zecall
    zetCommandListAppendMetricQueryEnd(
        zet_command_list_handle_t hCommandList,         ///< [in] handle of the command list
        zet_metric_query_handle_t hMetricQuery,         ///< [in] handle of the metric query
        ze_event_handle_t hCompletionEvent              ///< [in][optional] handle of the completion event to signal
        )
    {
        ze_result_t result = ZE_RESULT_SUCCESS;

        // extract driver's function pointer table
        auto dditable = reinterpret_cast<zet_command_list_object_t*>( hCommandList )->dditable;
        auto pfnAppendMetricQueryEnd = dditable->zet.CommandList.pfnAppendMetricQueryEnd;
        if( nullptr == pfnAppendMetricQueryEnd )
            return ZE_RESULT_ERROR_UNSUPPORTED_VERSION;

        // convert loader handle to driver handle
        hCommandList = reinterpret_cast<zet_command_list_object_t*>( hCommandList )->handle;

        // convert loader handle to driver handle
        hMetricQuery = reinterpret_cast<zet_metric_query_object_t*>( hMetricQuery )->handle;

        // convert loader handle to driver handle
        hCompletionEvent = ( hCompletionEvent ) ? reinterpret_cast<ze_event_object_t*>( hCompletionEvent )->handle : nullptr;

        // forward to device-driver
        result = pfnAppendMetricQueryEnd( hCommandList, hMetricQuery, hCompletionEvent );

        return result;
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Intercept function for zetCommandListAppendMetricMemoryBarrier
    __zedlllocal ze_result_t __zecall
    zetCommandListAppendMetricMemoryBarrier(
        zet_command_list_handle_t hCommandList          ///< [in] handle of the command list
        )
    {
        ze_result_t result = ZE_RESULT_SUCCESS;

        // extract driver's function pointer table
        auto dditable = reinterpret_cast<zet_command_list_object_t*>( hCommandList )->dditable;
        auto pfnAppendMetricMemoryBarrier = dditable->zet.CommandList.pfnAppendMetricMemoryBarrier;
        if( nullptr == pfnAppendMetricMemoryBarrier )
            return ZE_RESULT_ERROR_UNSUPPORTED_VERSION;

        // convert loader handle to driver handle
        hCommandList = reinterpret_cast<zet_command_list_object_t*>( hCommandList )->handle;

        // forward to device-driver
        result = pfnAppendMetricMemoryBarrier( hCommandList );

        return result;
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Intercept function for zetMetricQueryGetData
    __zedlllocal ze_result_t __zecall
    zetMetricQueryGetData(
        zet_metric_query_handle_t hMetricQuery,         ///< [in] handle of the metric query
        size_t* pRawDataSize,                           ///< [in,out] pointer to size in bytes of raw data requested to read.
                                                        ///< if size is zero, then the driver will update the value with the total
                                                        ///< size in bytes needed for all reports available.
                                                        ///< if size is non-zero, then driver will only retrieve the number of
                                                        ///< reports that fit into the buffer.
                                                        ///< if size is larger than size needed for all reports, then driver will
                                                        ///< update the value with the actual size needed.
        uint8_t* pRawData                               ///< [in,out][optional][range(0, *pRawDataSize)] buffer containing query
                                                        ///< reports in raw format
        )
    {
        ze_result_t result = ZE_RESULT_SUCCESS;

        // extract driver's function pointer table
        auto dditable = reinterpret_cast<zet_metric_query_object_t*>( hMetricQuery )->dditable;
        auto pfnGetData = dditable->zet.MetricQuery.pfnGetData;
        if( nullptr == pfnGetData )
            return ZE_RESULT_ERROR_UNSUPPORTED_VERSION;

        // convert loader handle to driver handle
        hMetricQuery = reinterpret_cast<zet_metric_query_object_t*>( hMetricQuery )->handle;

        // forward to device-driver
        result = pfnGetData( hMetricQuery, pRawDataSize, pRawData );

        return result;
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Intercept function for zetModuleGetDebugInfo
    __zedlllocal ze_result_t __zecall
    zetModuleGetDebugInfo(
        zet_module_handle_t hModule,                    ///< [in] handle of the module
        zet_module_debug_info_format_t format,          ///< [in] debug info format requested
        size_t* pSize,                                  ///< [in,out] size of debug info in bytes
        uint8_t* pDebugInfo                             ///< [in,out][optional] byte pointer to debug info
        )
    {
        ze_result_t result = ZE_RESULT_SUCCESS;

        // extract driver's function pointer table
        auto dditable = reinterpret_cast<zet_module_object_t*>( hModule )->dditable;
        auto pfnGetDebugInfo = dditable->zet.Module.pfnGetDebugInfo;
        if( nullptr == pfnGetDebugInfo )
            return ZE_RESULT_ERROR_UNSUPPORTED_VERSION;

        // convert loader handle to driver handle
        hModule = reinterpret_cast<zet_module_object_t*>( hModule )->handle;

        // forward to device-driver
        result = pfnGetDebugInfo( hModule, format, pSize, pDebugInfo );

        return result;
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Intercept function for zetKernelGetProfileInfo
    __zedlllocal ze_result_t __zecall
    zetKernelGetProfileInfo(
        zet_kernel_handle_t hKernel,                    ///< [in] handle to kernel
        zet_profile_info_t* pInfo                       ///< [out] pointer to profile info
        )
    {
        ze_result_t result = ZE_RESULT_SUCCESS;

        // extract driver's function pointer table
        auto dditable = reinterpret_cast<zet_kernel_object_t*>( hKernel )->dditable;
        auto pfnGetProfileInfo = dditable->zet.Kernel.pfnGetProfileInfo;
        if( nullptr == pfnGetProfileInfo )
            return ZE_RESULT_ERROR_UNSUPPORTED_VERSION;

        // convert loader handle to driver handle
        hKernel = reinterpret_cast<zet_kernel_object_t*>( hKernel )->handle;

        // forward to device-driver
        result = pfnGetProfileInfo( hKernel, pInfo );

        return result;
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Intercept function for zetTracerCreate
    __zedlllocal ze_result_t __zecall
    zetTracerCreate(
        zet_driver_handle_t hDriver,                    ///< [in] handle of the driver
        const zet_tracer_desc_t* desc,                  ///< [in] pointer to tracer descriptor
        zet_tracer_handle_t* phTracer                   ///< [out] pointer to handle of tracer object created
        )
    {
        ze_result_t result = ZE_RESULT_SUCCESS;

        // extract driver's function pointer table
        auto dditable = reinterpret_cast<zet_driver_object_t*>( hDriver )->dditable;
        auto pfnCreate = dditable->zet.Tracer.pfnCreate;
        if( nullptr == pfnCreate )
            return ZE_RESULT_ERROR_UNSUPPORTED_VERSION;

        // convert loader handle to driver handle
        hDriver = reinterpret_cast<zet_driver_object_t*>( hDriver )->handle;

        // forward to device-driver
        result = pfnCreate( hDriver, desc, phTracer );

        try
        {
            // convert driver handle to loader handle
            *phTracer = reinterpret_cast<zet_tracer_handle_t>(
                zet_tracer_factory.getInstance( *phTracer, dditable ) );
        }
        catch( std::bad_alloc& )
        {
            result = ZE_RESULT_ERROR_OUT_OF_HOST_MEMORY;
        }

        return result;
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Intercept function for zetTracerDestroy
    __zedlllocal ze_result_t __zecall
    zetTracerDestroy(
        zet_tracer_handle_t hTracer                     ///< [in][release] handle of tracer object to destroy
        )
    {
        ze_result_t result = ZE_RESULT_SUCCESS;

        // extract driver's function pointer table
        auto dditable = reinterpret_cast<zet_tracer_object_t*>( hTracer )->dditable;
        auto pfnDestroy = dditable->zet.Tracer.pfnDestroy;
        if( nullptr == pfnDestroy )
            return ZE_RESULT_ERROR_UNSUPPORTED_VERSION;

        // convert loader handle to driver handle
        hTracer = reinterpret_cast<zet_tracer_object_t*>( hTracer )->handle;

        // forward to device-driver
        result = pfnDestroy( hTracer );

        // release loader handle
        zet_tracer_factory.release( hTracer );

        return result;
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Intercept function for zetTracerSetPrologues
    __zedlllocal ze_result_t __zecall
    zetTracerSetPrologues(
        zet_tracer_handle_t hTracer,                    ///< [in] handle of the tracer
        zet_core_callbacks_t* pCoreCbs                  ///< [in] pointer to table of 'core' callback function pointers
        )
    {
        ze_result_t result = ZE_RESULT_SUCCESS;

        // extract driver's function pointer table
        auto dditable = reinterpret_cast<zet_tracer_object_t*>( hTracer )->dditable;
        auto pfnSetPrologues = dditable->zet.Tracer.pfnSetPrologues;
        if( nullptr == pfnSetPrologues )
            return ZE_RESULT_ERROR_UNSUPPORTED_VERSION;

        // convert loader handle to driver handle
        hTracer = reinterpret_cast<zet_tracer_object_t*>( hTracer )->handle;

        // forward to device-driver
        result = pfnSetPrologues( hTracer, pCoreCbs );

        return result;
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Intercept function for zetTracerSetEpilogues
    __zedlllocal ze_result_t __zecall
    zetTracerSetEpilogues(
        zet_tracer_handle_t hTracer,                    ///< [in] handle of the tracer
        zet_core_callbacks_t* pCoreCbs                  ///< [in] pointer to table of 'core' callback function pointers
        )
    {
        ze_result_t result = ZE_RESULT_SUCCESS;

        // extract driver's function pointer table
        auto dditable = reinterpret_cast<zet_tracer_object_t*>( hTracer )->dditable;
        auto pfnSetEpilogues = dditable->zet.Tracer.pfnSetEpilogues;
        if( nullptr == pfnSetEpilogues )
            return ZE_RESULT_ERROR_UNSUPPORTED_VERSION;

        // convert loader handle to driver handle
        hTracer = reinterpret_cast<zet_tracer_object_t*>( hTracer )->handle;

        // forward to device-driver
        result = pfnSetEpilogues( hTracer, pCoreCbs );

        return result;
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Intercept function for zetTracerSetEnabled
    __zedlllocal ze_result_t __zecall
    zetTracerSetEnabled(
        zet_tracer_handle_t hTracer,                    ///< [in] handle of the tracer
        ze_bool_t enable                                ///< [in] enable the tracer if true; disable if false
        )
    {
        ze_result_t result = ZE_RESULT_SUCCESS;

        // extract driver's function pointer table
        auto dditable = reinterpret_cast<zet_tracer_object_t*>( hTracer )->dditable;
        auto pfnSetEnabled = dditable->zet.Tracer.pfnSetEnabled;
        if( nullptr == pfnSetEnabled )
            return ZE_RESULT_ERROR_UNSUPPORTED_VERSION;

        // convert loader handle to driver handle
        hTracer = reinterpret_cast<zet_tracer_object_t*>( hTracer )->handle;

        // forward to device-driver
        result = pfnSetEnabled( hTracer, enable );

        return result;
    }

} // namespace loader

#if defined(__cplusplus)
extern "C" {
#endif

///////////////////////////////////////////////////////////////////////////////
/// @brief Exported function for filling application's Device table
///        with current process' addresses
///
/// @returns
///     - ::ZE_RESULT_SUCCESS
///     - ::ZE_RESULT_ERROR_UNINITIALIZED
///     - ::ZE_RESULT_ERROR_INVALID_NULL_POINTER
///     - ::ZE_RESULT_ERROR_UNSUPPORTED_VERSION
__zedllexport ze_result_t __zecall
zetGetDeviceProcAddrTable(
    ze_api_version_t version,                       ///< [in] API version requested
    zet_device_dditable_t* pDdiTable                ///< [in,out] pointer to table of DDI function pointers
    )
{
    if( loader::context.drivers.size() < 1 )
        return ZE_RESULT_ERROR_UNINITIALIZED;

    if( nullptr == pDdiTable )
        return ZE_RESULT_ERROR_INVALID_NULL_POINTER;

    if( loader::context.version < version )
        return ZE_RESULT_ERROR_UNSUPPORTED_VERSION;

    ze_result_t result = ZE_RESULT_SUCCESS;

    // Load the device-driver DDI tables
    for( auto& drv : loader::context.drivers )
    {
        if( ZE_RESULT_SUCCESS == result )
        {
            auto getTable = reinterpret_cast<zet_pfnGetDeviceProcAddrTable_t>(
                GET_FUNCTION_PTR( drv.handle, "zetGetDeviceProcAddrTable") );
            result = getTable( version, &drv.dditable.zet.Device );
        }
    }

    if( ZE_RESULT_SUCCESS == result )
    {
        if( ( loader::context.drivers.size() > 1 ) || loader::context.forceIntercept )
        {
            // return pointers to loader's DDIs
            pDdiTable->pfnActivateMetricGroups                     = loader::zetDeviceActivateMetricGroups;
        }
        else
        {
            // return pointers directly to driver's DDIs
            *pDdiTable = loader::context.drivers.front().dditable.zet.Device;
        }
    }

    // If the validation layer is enabled, then intercept the loader's DDIs
    if(( ZE_RESULT_SUCCESS == result ) && ( nullptr != loader::context.validationLayer ))
    {
        auto getTable = reinterpret_cast<zet_pfnGetDeviceProcAddrTable_t>(
            GET_FUNCTION_PTR(loader::context.validationLayer, "zetGetDeviceProcAddrTable") );
        result = getTable( version, pDdiTable );
    }

    return result;
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Exported function for filling application's CommandList table
///        with current process' addresses
///
/// @returns
///     - ::ZE_RESULT_SUCCESS
///     - ::ZE_RESULT_ERROR_UNINITIALIZED
///     - ::ZE_RESULT_ERROR_INVALID_NULL_POINTER
///     - ::ZE_RESULT_ERROR_UNSUPPORTED_VERSION
__zedllexport ze_result_t __zecall
zetGetCommandListProcAddrTable(
    ze_api_version_t version,                       ///< [in] API version requested
    zet_command_list_dditable_t* pDdiTable          ///< [in,out] pointer to table of DDI function pointers
    )
{
    if( loader::context.drivers.size() < 1 )
        return ZE_RESULT_ERROR_UNINITIALIZED;

    if( nullptr == pDdiTable )
        return ZE_RESULT_ERROR_INVALID_NULL_POINTER;

    if( loader::context.version < version )
        return ZE_RESULT_ERROR_UNSUPPORTED_VERSION;

    ze_result_t result = ZE_RESULT_SUCCESS;

    // Load the device-driver DDI tables
    for( auto& drv : loader::context.drivers )
    {
        if( ZE_RESULT_SUCCESS == result )
        {
            auto getTable = reinterpret_cast<zet_pfnGetCommandListProcAddrTable_t>(
                GET_FUNCTION_PTR( drv.handle, "zetGetCommandListProcAddrTable") );
            result = getTable( version, &drv.dditable.zet.CommandList );
        }
    }

    if( ZE_RESULT_SUCCESS == result )
    {
        if( ( loader::context.drivers.size() > 1 ) || loader::context.forceIntercept )
        {
            // return pointers to loader's DDIs
            pDdiTable->pfnAppendMetricTracerMarker                 = loader::zetCommandListAppendMetricTracerMarker;
            pDdiTable->pfnAppendMetricQueryBegin                   = loader::zetCommandListAppendMetricQueryBegin;
            pDdiTable->pfnAppendMetricQueryEnd                     = loader::zetCommandListAppendMetricQueryEnd;
            pDdiTable->pfnAppendMetricMemoryBarrier                = loader::zetCommandListAppendMetricMemoryBarrier;
        }
        else
        {
            // return pointers directly to driver's DDIs
            *pDdiTable = loader::context.drivers.front().dditable.zet.CommandList;
        }
    }

    // If the validation layer is enabled, then intercept the loader's DDIs
    if(( ZE_RESULT_SUCCESS == result ) && ( nullptr != loader::context.validationLayer ))
    {
        auto getTable = reinterpret_cast<zet_pfnGetCommandListProcAddrTable_t>(
            GET_FUNCTION_PTR(loader::context.validationLayer, "zetGetCommandListProcAddrTable") );
        result = getTable( version, pDdiTable );
    }

    return result;
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Exported function for filling application's Module table
///        with current process' addresses
///
/// @returns
///     - ::ZE_RESULT_SUCCESS
///     - ::ZE_RESULT_ERROR_UNINITIALIZED
///     - ::ZE_RESULT_ERROR_INVALID_NULL_POINTER
///     - ::ZE_RESULT_ERROR_UNSUPPORTED_VERSION
__zedllexport ze_result_t __zecall
zetGetModuleProcAddrTable(
    ze_api_version_t version,                       ///< [in] API version requested
    zet_module_dditable_t* pDdiTable                ///< [in,out] pointer to table of DDI function pointers
    )
{
    if( loader::context.drivers.size() < 1 )
        return ZE_RESULT_ERROR_UNINITIALIZED;

    if( nullptr == pDdiTable )
        return ZE_RESULT_ERROR_INVALID_NULL_POINTER;

    if( loader::context.version < version )
        return ZE_RESULT_ERROR_UNSUPPORTED_VERSION;

    ze_result_t result = ZE_RESULT_SUCCESS;

    // Load the device-driver DDI tables
    for( auto& drv : loader::context.drivers )
    {
        if( ZE_RESULT_SUCCESS == result )
        {
            auto getTable = reinterpret_cast<zet_pfnGetModuleProcAddrTable_t>(
                GET_FUNCTION_PTR( drv.handle, "zetGetModuleProcAddrTable") );
            result = getTable( version, &drv.dditable.zet.Module );
        }
    }

    if( ZE_RESULT_SUCCESS == result )
    {
        if( ( loader::context.drivers.size() > 1 ) || loader::context.forceIntercept )
        {
            // return pointers to loader's DDIs
            pDdiTable->pfnGetDebugInfo                             = loader::zetModuleGetDebugInfo;
        }
        else
        {
            // return pointers directly to driver's DDIs
            *pDdiTable = loader::context.drivers.front().dditable.zet.Module;
        }
    }

    // If the validation layer is enabled, then intercept the loader's DDIs
    if(( ZE_RESULT_SUCCESS == result ) && ( nullptr != loader::context.validationLayer ))
    {
        auto getTable = reinterpret_cast<zet_pfnGetModuleProcAddrTable_t>(
            GET_FUNCTION_PTR(loader::context.validationLayer, "zetGetModuleProcAddrTable") );
        result = getTable( version, pDdiTable );
    }

    return result;
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Exported function for filling application's Kernel table
///        with current process' addresses
///
/// @returns
///     - ::ZE_RESULT_SUCCESS
///     - ::ZE_RESULT_ERROR_UNINITIALIZED
///     - ::ZE_RESULT_ERROR_INVALID_NULL_POINTER
///     - ::ZE_RESULT_ERROR_UNSUPPORTED_VERSION
__zedllexport ze_result_t __zecall
zetGetKernelProcAddrTable(
    ze_api_version_t version,                       ///< [in] API version requested
    zet_kernel_dditable_t* pDdiTable                ///< [in,out] pointer to table of DDI function pointers
    )
{
    if( loader::context.drivers.size() < 1 )
        return ZE_RESULT_ERROR_UNINITIALIZED;

    if( nullptr == pDdiTable )
        return ZE_RESULT_ERROR_INVALID_NULL_POINTER;

    if( loader::context.version < version )
        return ZE_RESULT_ERROR_UNSUPPORTED_VERSION;

    ze_result_t result = ZE_RESULT_SUCCESS;

    // Load the device-driver DDI tables
    for( auto& drv : loader::context.drivers )
    {
        if( ZE_RESULT_SUCCESS == result )
        {
            auto getTable = reinterpret_cast<zet_pfnGetKernelProcAddrTable_t>(
                GET_FUNCTION_PTR( drv.handle, "zetGetKernelProcAddrTable") );
            result = getTable( version, &drv.dditable.zet.Kernel );
        }
    }

    if( ZE_RESULT_SUCCESS == result )
    {
        if( ( loader::context.drivers.size() > 1 ) || loader::context.forceIntercept )
        {
            // return pointers to loader's DDIs
            pDdiTable->pfnGetProfileInfo                           = loader::zetKernelGetProfileInfo;
        }
        else
        {
            // return pointers directly to driver's DDIs
            *pDdiTable = loader::context.drivers.front().dditable.zet.Kernel;
        }
    }

    // If the validation layer is enabled, then intercept the loader's DDIs
    if(( ZE_RESULT_SUCCESS == result ) && ( nullptr != loader::context.validationLayer ))
    {
        auto getTable = reinterpret_cast<zet_pfnGetKernelProcAddrTable_t>(
            GET_FUNCTION_PTR(loader::context.validationLayer, "zetGetKernelProcAddrTable") );
        result = getTable( version, pDdiTable );
    }

    return result;
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Exported function for filling application's MetricGroup table
///        with current process' addresses
///
/// @returns
///     - ::ZE_RESULT_SUCCESS
///     - ::ZE_RESULT_ERROR_UNINITIALIZED
///     - ::ZE_RESULT_ERROR_INVALID_NULL_POINTER
///     - ::ZE_RESULT_ERROR_UNSUPPORTED_VERSION
__zedllexport ze_result_t __zecall
zetGetMetricGroupProcAddrTable(
    ze_api_version_t version,                       ///< [in] API version requested
    zet_metric_group_dditable_t* pDdiTable          ///< [in,out] pointer to table of DDI function pointers
    )
{
    if( loader::context.drivers.size() < 1 )
        return ZE_RESULT_ERROR_UNINITIALIZED;

    if( nullptr == pDdiTable )
        return ZE_RESULT_ERROR_INVALID_NULL_POINTER;

    if( loader::context.version < version )
        return ZE_RESULT_ERROR_UNSUPPORTED_VERSION;

    ze_result_t result = ZE_RESULT_SUCCESS;

    // Load the device-driver DDI tables
    for( auto& drv : loader::context.drivers )
    {
        if( ZE_RESULT_SUCCESS == result )
        {
            auto getTable = reinterpret_cast<zet_pfnGetMetricGroupProcAddrTable_t>(
                GET_FUNCTION_PTR( drv.handle, "zetGetMetricGroupProcAddrTable") );
            result = getTable( version, &drv.dditable.zet.MetricGroup );
        }
    }

    if( ZE_RESULT_SUCCESS == result )
    {
        if( ( loader::context.drivers.size() > 1 ) || loader::context.forceIntercept )
        {
            // return pointers to loader's DDIs
            pDdiTable->pfnGet                                      = loader::zetMetricGroupGet;
            pDdiTable->pfnGetProperties                            = loader::zetMetricGroupGetProperties;
            pDdiTable->pfnCalculateMetricValues                    = loader::zetMetricGroupCalculateMetricValues;
        }
        else
        {
            // return pointers directly to driver's DDIs
            *pDdiTable = loader::context.drivers.front().dditable.zet.MetricGroup;
        }
    }

    // If the validation layer is enabled, then intercept the loader's DDIs
    if(( ZE_RESULT_SUCCESS == result ) && ( nullptr != loader::context.validationLayer ))
    {
        auto getTable = reinterpret_cast<zet_pfnGetMetricGroupProcAddrTable_t>(
            GET_FUNCTION_PTR(loader::context.validationLayer, "zetGetMetricGroupProcAddrTable") );
        result = getTable( version, pDdiTable );
    }

    return result;
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Exported function for filling application's Metric table
///        with current process' addresses
///
/// @returns
///     - ::ZE_RESULT_SUCCESS
///     - ::ZE_RESULT_ERROR_UNINITIALIZED
///     - ::ZE_RESULT_ERROR_INVALID_NULL_POINTER
///     - ::ZE_RESULT_ERROR_UNSUPPORTED_VERSION
__zedllexport ze_result_t __zecall
zetGetMetricProcAddrTable(
    ze_api_version_t version,                       ///< [in] API version requested
    zet_metric_dditable_t* pDdiTable                ///< [in,out] pointer to table of DDI function pointers
    )
{
    if( loader::context.drivers.size() < 1 )
        return ZE_RESULT_ERROR_UNINITIALIZED;

    if( nullptr == pDdiTable )
        return ZE_RESULT_ERROR_INVALID_NULL_POINTER;

    if( loader::context.version < version )
        return ZE_RESULT_ERROR_UNSUPPORTED_VERSION;

    ze_result_t result = ZE_RESULT_SUCCESS;

    // Load the device-driver DDI tables
    for( auto& drv : loader::context.drivers )
    {
        if( ZE_RESULT_SUCCESS == result )
        {
            auto getTable = reinterpret_cast<zet_pfnGetMetricProcAddrTable_t>(
                GET_FUNCTION_PTR( drv.handle, "zetGetMetricProcAddrTable") );
            result = getTable( version, &drv.dditable.zet.Metric );
        }
    }

    if( ZE_RESULT_SUCCESS == result )
    {
        if( ( loader::context.drivers.size() > 1 ) || loader::context.forceIntercept )
        {
            // return pointers to loader's DDIs
            pDdiTable->pfnGet                                      = loader::zetMetricGet;
            pDdiTable->pfnGetProperties                            = loader::zetMetricGetProperties;
        }
        else
        {
            // return pointers directly to driver's DDIs
            *pDdiTable = loader::context.drivers.front().dditable.zet.Metric;
        }
    }

    // If the validation layer is enabled, then intercept the loader's DDIs
    if(( ZE_RESULT_SUCCESS == result ) && ( nullptr != loader::context.validationLayer ))
    {
        auto getTable = reinterpret_cast<zet_pfnGetMetricProcAddrTable_t>(
            GET_FUNCTION_PTR(loader::context.validationLayer, "zetGetMetricProcAddrTable") );
        result = getTable( version, pDdiTable );
    }

    return result;
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Exported function for filling application's MetricTracer table
///        with current process' addresses
///
/// @returns
///     - ::ZE_RESULT_SUCCESS
///     - ::ZE_RESULT_ERROR_UNINITIALIZED
///     - ::ZE_RESULT_ERROR_INVALID_NULL_POINTER
///     - ::ZE_RESULT_ERROR_UNSUPPORTED_VERSION
__zedllexport ze_result_t __zecall
zetGetMetricTracerProcAddrTable(
    ze_api_version_t version,                       ///< [in] API version requested
    zet_metric_tracer_dditable_t* pDdiTable         ///< [in,out] pointer to table of DDI function pointers
    )
{
    if( loader::context.drivers.size() < 1 )
        return ZE_RESULT_ERROR_UNINITIALIZED;

    if( nullptr == pDdiTable )
        return ZE_RESULT_ERROR_INVALID_NULL_POINTER;

    if( loader::context.version < version )
        return ZE_RESULT_ERROR_UNSUPPORTED_VERSION;

    ze_result_t result = ZE_RESULT_SUCCESS;

    // Load the device-driver DDI tables
    for( auto& drv : loader::context.drivers )
    {
        if( ZE_RESULT_SUCCESS == result )
        {
            auto getTable = reinterpret_cast<zet_pfnGetMetricTracerProcAddrTable_t>(
                GET_FUNCTION_PTR( drv.handle, "zetGetMetricTracerProcAddrTable") );
            result = getTable( version, &drv.dditable.zet.MetricTracer );
        }
    }

    if( ZE_RESULT_SUCCESS == result )
    {
        if( ( loader::context.drivers.size() > 1 ) || loader::context.forceIntercept )
        {
            // return pointers to loader's DDIs
            pDdiTable->pfnOpen                                     = loader::zetMetricTracerOpen;
            pDdiTable->pfnClose                                    = loader::zetMetricTracerClose;
            pDdiTable->pfnReadData                                 = loader::zetMetricTracerReadData;
        }
        else
        {
            // return pointers directly to driver's DDIs
            *pDdiTable = loader::context.drivers.front().dditable.zet.MetricTracer;
        }
    }

    // If the validation layer is enabled, then intercept the loader's DDIs
    if(( ZE_RESULT_SUCCESS == result ) && ( nullptr != loader::context.validationLayer ))
    {
        auto getTable = reinterpret_cast<zet_pfnGetMetricTracerProcAddrTable_t>(
            GET_FUNCTION_PTR(loader::context.validationLayer, "zetGetMetricTracerProcAddrTable") );
        result = getTable( version, pDdiTable );
    }

    return result;
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Exported function for filling application's MetricQueryPool table
///        with current process' addresses
///
/// @returns
///     - ::ZE_RESULT_SUCCESS
///     - ::ZE_RESULT_ERROR_UNINITIALIZED
///     - ::ZE_RESULT_ERROR_INVALID_NULL_POINTER
///     - ::ZE_RESULT_ERROR_UNSUPPORTED_VERSION
__zedllexport ze_result_t __zecall
zetGetMetricQueryPoolProcAddrTable(
    ze_api_version_t version,                       ///< [in] API version requested
    zet_metric_query_pool_dditable_t* pDdiTable     ///< [in,out] pointer to table of DDI function pointers
    )
{
    if( loader::context.drivers.size() < 1 )
        return ZE_RESULT_ERROR_UNINITIALIZED;

    if( nullptr == pDdiTable )
        return ZE_RESULT_ERROR_INVALID_NULL_POINTER;

    if( loader::context.version < version )
        return ZE_RESULT_ERROR_UNSUPPORTED_VERSION;

    ze_result_t result = ZE_RESULT_SUCCESS;

    // Load the device-driver DDI tables
    for( auto& drv : loader::context.drivers )
    {
        if( ZE_RESULT_SUCCESS == result )
        {
            auto getTable = reinterpret_cast<zet_pfnGetMetricQueryPoolProcAddrTable_t>(
                GET_FUNCTION_PTR( drv.handle, "zetGetMetricQueryPoolProcAddrTable") );
            result = getTable( version, &drv.dditable.zet.MetricQueryPool );
        }
    }

    if( ZE_RESULT_SUCCESS == result )
    {
        if( ( loader::context.drivers.size() > 1 ) || loader::context.forceIntercept )
        {
            // return pointers to loader's DDIs
            pDdiTable->pfnCreate                                   = loader::zetMetricQueryPoolCreate;
            pDdiTable->pfnDestroy                                  = loader::zetMetricQueryPoolDestroy;
        }
        else
        {
            // return pointers directly to driver's DDIs
            *pDdiTable = loader::context.drivers.front().dditable.zet.MetricQueryPool;
        }
    }

    // If the validation layer is enabled, then intercept the loader's DDIs
    if(( ZE_RESULT_SUCCESS == result ) && ( nullptr != loader::context.validationLayer ))
    {
        auto getTable = reinterpret_cast<zet_pfnGetMetricQueryPoolProcAddrTable_t>(
            GET_FUNCTION_PTR(loader::context.validationLayer, "zetGetMetricQueryPoolProcAddrTable") );
        result = getTable( version, pDdiTable );
    }

    return result;
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Exported function for filling application's MetricQuery table
///        with current process' addresses
///
/// @returns
///     - ::ZE_RESULT_SUCCESS
///     - ::ZE_RESULT_ERROR_UNINITIALIZED
///     - ::ZE_RESULT_ERROR_INVALID_NULL_POINTER
///     - ::ZE_RESULT_ERROR_UNSUPPORTED_VERSION
__zedllexport ze_result_t __zecall
zetGetMetricQueryProcAddrTable(
    ze_api_version_t version,                       ///< [in] API version requested
    zet_metric_query_dditable_t* pDdiTable          ///< [in,out] pointer to table of DDI function pointers
    )
{
    if( loader::context.drivers.size() < 1 )
        return ZE_RESULT_ERROR_UNINITIALIZED;

    if( nullptr == pDdiTable )
        return ZE_RESULT_ERROR_INVALID_NULL_POINTER;

    if( loader::context.version < version )
        return ZE_RESULT_ERROR_UNSUPPORTED_VERSION;

    ze_result_t result = ZE_RESULT_SUCCESS;

    // Load the device-driver DDI tables
    for( auto& drv : loader::context.drivers )
    {
        if( ZE_RESULT_SUCCESS == result )
        {
            auto getTable = reinterpret_cast<zet_pfnGetMetricQueryProcAddrTable_t>(
                GET_FUNCTION_PTR( drv.handle, "zetGetMetricQueryProcAddrTable") );
            result = getTable( version, &drv.dditable.zet.MetricQuery );
        }
    }

    if( ZE_RESULT_SUCCESS == result )
    {
        if( ( loader::context.drivers.size() > 1 ) || loader::context.forceIntercept )
        {
            // return pointers to loader's DDIs
            pDdiTable->pfnCreate                                   = loader::zetMetricQueryCreate;
            pDdiTable->pfnDestroy                                  = loader::zetMetricQueryDestroy;
            pDdiTable->pfnReset                                    = loader::zetMetricQueryReset;
            pDdiTable->pfnGetData                                  = loader::zetMetricQueryGetData;
        }
        else
        {
            // return pointers directly to driver's DDIs
            *pDdiTable = loader::context.drivers.front().dditable.zet.MetricQuery;
        }
    }

    // If the validation layer is enabled, then intercept the loader's DDIs
    if(( ZE_RESULT_SUCCESS == result ) && ( nullptr != loader::context.validationLayer ))
    {
        auto getTable = reinterpret_cast<zet_pfnGetMetricQueryProcAddrTable_t>(
            GET_FUNCTION_PTR(loader::context.validationLayer, "zetGetMetricQueryProcAddrTable") );
        result = getTable( version, pDdiTable );
    }

    return result;
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Exported function for filling application's Tracer table
///        with current process' addresses
///
/// @returns
///     - ::ZE_RESULT_SUCCESS
///     - ::ZE_RESULT_ERROR_UNINITIALIZED
///     - ::ZE_RESULT_ERROR_INVALID_NULL_POINTER
///     - ::ZE_RESULT_ERROR_UNSUPPORTED_VERSION
__zedllexport ze_result_t __zecall
zetGetTracerProcAddrTable(
    ze_api_version_t version,                       ///< [in] API version requested
    zet_tracer_dditable_t* pDdiTable                ///< [in,out] pointer to table of DDI function pointers
    )
{
    if( loader::context.drivers.size() < 1 )
        return ZE_RESULT_ERROR_UNINITIALIZED;

    if( nullptr == pDdiTable )
        return ZE_RESULT_ERROR_INVALID_NULL_POINTER;

    if( loader::context.version < version )
        return ZE_RESULT_ERROR_UNSUPPORTED_VERSION;

    ze_result_t result = ZE_RESULT_SUCCESS;

    // Load the device-driver DDI tables
    for( auto& drv : loader::context.drivers )
    {
        if( ZE_RESULT_SUCCESS == result )
        {
            auto getTable = reinterpret_cast<zet_pfnGetTracerProcAddrTable_t>(
                GET_FUNCTION_PTR( drv.handle, "zetGetTracerProcAddrTable") );
            result = getTable( version, &drv.dditable.zet.Tracer );
        }
    }

    if( ZE_RESULT_SUCCESS == result )
    {
        if( ( loader::context.drivers.size() > 1 ) || loader::context.forceIntercept )
        {
            // return pointers to loader's DDIs
            pDdiTable->pfnCreate                                   = loader::zetTracerCreate;
            pDdiTable->pfnDestroy                                  = loader::zetTracerDestroy;
            pDdiTable->pfnSetPrologues                             = loader::zetTracerSetPrologues;
            pDdiTable->pfnSetEpilogues                             = loader::zetTracerSetEpilogues;
            pDdiTable->pfnSetEnabled                               = loader::zetTracerSetEnabled;
        }
        else
        {
            // return pointers directly to driver's DDIs
            *pDdiTable = loader::context.drivers.front().dditable.zet.Tracer;
        }
    }

    // If the validation layer is enabled, then intercept the loader's DDIs
    if(( ZE_RESULT_SUCCESS == result ) && ( nullptr != loader::context.validationLayer ))
    {
        auto getTable = reinterpret_cast<zet_pfnGetTracerProcAddrTable_t>(
            GET_FUNCTION_PTR(loader::context.validationLayer, "zetGetTracerProcAddrTable") );
        result = getTable( version, pDdiTable );
    }

    return result;
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Exported function for filling application's Debug table
///        with current process' addresses
///
/// @returns
///     - ::ZE_RESULT_SUCCESS
///     - ::ZE_RESULT_ERROR_UNINITIALIZED
///     - ::ZE_RESULT_ERROR_INVALID_NULL_POINTER
///     - ::ZE_RESULT_ERROR_UNSUPPORTED_VERSION
__zedllexport ze_result_t __zecall
zetGetDebugProcAddrTable(
    ze_api_version_t version,                       ///< [in] API version requested
    zet_debug_dditable_t* pDdiTable                 ///< [in,out] pointer to table of DDI function pointers
    )
{
    if( loader::context.drivers.size() < 1 )
        return ZE_RESULT_ERROR_UNINITIALIZED;

    if( nullptr == pDdiTable )
        return ZE_RESULT_ERROR_INVALID_NULL_POINTER;

    if( loader::context.version < version )
        return ZE_RESULT_ERROR_UNSUPPORTED_VERSION;

    ze_result_t result = ZE_RESULT_SUCCESS;

    // Load the device-driver DDI tables
    for( auto& drv : loader::context.drivers )
    {
        if( ZE_RESULT_SUCCESS == result )
        {
            auto getTable = reinterpret_cast<zet_pfnGetDebugProcAddrTable_t>(
                GET_FUNCTION_PTR( drv.handle, "zetGetDebugProcAddrTable") );
            result = getTable( version, &drv.dditable.zet.Debug );
        }
    }

    if( ZE_RESULT_SUCCESS == result )
    {
        if( ( loader::context.drivers.size() > 1 ) || loader::context.forceIntercept )
        {
            // return pointers to loader's DDIs
            pDdiTable->pfnAttach                                   = loader::zetDebugAttach;
            pDdiTable->pfnDetach                                   = loader::zetDebugDetach;
            pDdiTable->pfnGetNumThreads                            = loader::zetDebugGetNumThreads;
            pDdiTable->pfnReadEvent                                = loader::zetDebugReadEvent;
            pDdiTable->pfnInterrupt                                = loader::zetDebugInterrupt;
            pDdiTable->pfnResume                                   = loader::zetDebugResume;
            pDdiTable->pfnReadMemory                               = loader::zetDebugReadMemory;
            pDdiTable->pfnWriteMemory                              = loader::zetDebugWriteMemory;
            pDdiTable->pfnReadState                                = loader::zetDebugReadState;
            pDdiTable->pfnWriteState                               = loader::zetDebugWriteState;
        }
        else
        {
            // return pointers directly to driver's DDIs
            *pDdiTable = loader::context.drivers.front().dditable.zet.Debug;
        }
    }

    // If the validation layer is enabled, then intercept the loader's DDIs
    if(( ZE_RESULT_SUCCESS == result ) && ( nullptr != loader::context.validationLayer ))
    {
        auto getTable = reinterpret_cast<zet_pfnGetDebugProcAddrTable_t>(
            GET_FUNCTION_PTR(loader::context.validationLayer, "zetGetDebugProcAddrTable") );
        result = getTable( version, pDdiTable );
    }

    return result;
}


#if defined(__cplusplus)
};
#endif
