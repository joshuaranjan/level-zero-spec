/*
 *
 * Copyright (C) 2019 Intel Corporation
 *
 * SPDX-License-Identifier: MIT
 *
 */
#include "xello_init.h"

//////////////////////////////////////////////////////////////////////////
inline xet::MetricGroup* findMetricGroup(
    xet::Device* pDevice,
    const xet::MetricGroup::sampling_type_t type,
    const char* name = "" )
{
    uint32_t groupCount = 0;
    xet::MetricGroup::Get( pDevice, &groupCount );

    std::vector< xet::MetricGroup*> metricGroups( groupCount );
    xet::MetricGroup::Get( pDevice, &groupCount, metricGroups.data() );

    xet::MetricGroup* found = nullptr;

    // for each device group, find the first one matching the type
    for( uint32_t grp = 0; grp < groupCount; ++grp )
    {
        auto pMetricGroup = metricGroups[ grp ];
        xet::MetricGroup::properties_t metric_group_properties;
        pMetricGroup->GetProperties( &metric_group_properties );

        if( 0 != ( static_cast<uint32_t>(type) & static_cast<uint32_t>(metric_group_properties.samplingType) ) )
        {
            if( ( 0 == strlen(name) ) || ( 0 == strcmp( name, metric_group_properties.name ) ) )
            {
                found = pMetricGroup;

                std::cout << "Found " << xet::to_string( type ) << " metric group..." << "\n";
                std::cout << xet::to_string( metric_group_properties ) << "\n";
            }
        }
    }
    if( !found )
    {
        std::cout << "Did NOT find matching " << xet::to_string( type ) << " device group!" << "\n";
    }

    return found;
}

//////////////////////////////////////////////////////////////////////////
inline void calculateResults( xet::MetricGroup* pMetricGroup, xet::MetricQuery* pQuery )
{
    // Read raw data from query
    size_t rawDataSize = 0;
    pQuery->GetData( &rawDataSize, nullptr );
    std::vector<uint8_t> rawData( rawDataSize );
    pQuery->GetData( &rawDataSize, rawData.data() );

    // Calculate results
    uint32_t numMetricValues = 0;
    xet::MetricGroup::CalculateMetricValues( pMetricGroup, rawDataSize, rawData.data(), &numMetricValues );
    std::vector<xet::typed_value_t> metricValues( numMetricValues );
    xet::MetricGroup::CalculateMetricValues( pMetricGroup, rawDataSize, rawData.data(), &numMetricValues, metricValues.data() );

    // get metric info
    uint32_t metricCount = 0;
    xet::Metric::Get( pMetricGroup, &metricCount, nullptr );
    std::vector< xet::Metric* > metrics( metricCount );
    xet::Metric::Get( pMetricGroup, &metricCount, metrics.data() );

    // Report results
    std::cout << "Compute Basic results:\n";
    uint32_t numReports = numMetricValues / metricCount;
    for( uint32_t report = 0; report < numReports; ++report )
    {
        for( uint32_t metric = 0; metric < metricCount; ++metric )
        {
            xet::Metric::properties_t metric_properties;
            metrics[ metric ]->GetProperties( &metric_properties );

            auto& result = metricValues[ report * metricCount + metric ];
            std::cout << metric_properties.name << " (" << metric_properties.resultUnits << ") :\n";
            std::cout << xet::to_string( result ) << "\n";
        }
    }
}
