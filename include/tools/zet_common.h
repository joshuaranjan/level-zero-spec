/*
 *
 * Copyright (C) 2019 Intel Corporation
 *
 * SPDX-License-Identifier: MIT
 *
 * @file zet_common.h
 *
 * @brief Intel 'One API' Level-Zero Tool API common types
 *
 * @cond DEV
 * DO NOT EDIT: generated from /scripts/tools/common.yml
 * @endcond
 *
 */
#ifndef _ZET_COMMON_H
#define _ZET_COMMON_H
#if defined(__cplusplus)
#pragma once
#endif
#if !defined(_ZET_API_H)
#pragma message("warning: this file is not intended to be included directly")
#endif

#if defined(__cplusplus)
extern "C" {
#endif

///////////////////////////////////////////////////////////////////////////////
/// @brief Handle to a driver instance
typedef ze_driver_handle_t zet_driver_handle_t;

///////////////////////////////////////////////////////////////////////////////
/// @brief Handle of device object
typedef ze_device_handle_t zet_device_handle_t;

///////////////////////////////////////////////////////////////////////////////
/// @brief Handle of command list object
typedef ze_command_list_handle_t zet_command_list_handle_t;

///////////////////////////////////////////////////////////////////////////////
/// @brief Handle of module object
typedef ze_module_handle_t zet_module_handle_t;

///////////////////////////////////////////////////////////////////////////////
/// @brief Handle of function object
typedef ze_kernel_handle_t zet_kernel_handle_t;

///////////////////////////////////////////////////////////////////////////////
/// @brief Handle of metric group's object
typedef struct _zet_metric_group_handle_t *zet_metric_group_handle_t;

///////////////////////////////////////////////////////////////////////////////
/// @brief Handle of metric's object
typedef struct _zet_metric_handle_t *zet_metric_handle_t;

///////////////////////////////////////////////////////////////////////////////
/// @brief Handle of metric tracer's object
typedef struct _zet_metric_tracer_handle_t *zet_metric_tracer_handle_t;

///////////////////////////////////////////////////////////////////////////////
/// @brief Handle of metric query pool's object
typedef struct _zet_metric_query_pool_handle_t *zet_metric_query_pool_handle_t;

///////////////////////////////////////////////////////////////////////////////
/// @brief Handle of metric query's object
typedef struct _zet_metric_query_handle_t *zet_metric_query_handle_t;

///////////////////////////////////////////////////////////////////////////////
/// @brief Handle of tracer object
typedef struct _zet_tracer_handle_t *zet_tracer_handle_t;

///////////////////////////////////////////////////////////////////////////////
/// @brief Handle for accessing System Resource Management features of a device
typedef struct _zet_sysman_handle_t *zet_sysman_handle_t;

///////////////////////////////////////////////////////////////////////////////
/// @brief Handle for a Sysman device power domain
typedef struct _zet_sysman_pwr_handle_t *zet_sysman_pwr_handle_t;

///////////////////////////////////////////////////////////////////////////////
/// @brief Handle for a Sysman device frequency domain
typedef struct _zet_sysman_freq_handle_t *zet_sysman_freq_handle_t;

///////////////////////////////////////////////////////////////////////////////
/// @brief Handle for a Sysman device engine group
typedef struct _zet_sysman_engine_handle_t *zet_sysman_engine_handle_t;

///////////////////////////////////////////////////////////////////////////////
/// @brief Handle for a Sysman device standby control
typedef struct _zet_sysman_standby_handle_t *zet_sysman_standby_handle_t;

///////////////////////////////////////////////////////////////////////////////
/// @brief Handle for a Sysman device firmware
typedef struct _zet_sysman_firmware_handle_t *zet_sysman_firmware_handle_t;

///////////////////////////////////////////////////////////////////////////////
/// @brief Handle for a Sysman device memory module
typedef struct _zet_sysman_mem_handle_t *zet_sysman_mem_handle_t;

///////////////////////////////////////////////////////////////////////////////
/// @brief Handle for a Sysman fabric port
typedef struct _zet_sysman_fabric_port_handle_t *zet_sysman_fabric_port_handle_t;

///////////////////////////////////////////////////////////////////////////////
/// @brief Handle for a Sysman device temperature sensor
typedef struct _zet_sysman_temp_handle_t *zet_sysman_temp_handle_t;

///////////////////////////////////////////////////////////////////////////////
/// @brief Handle for a Sysman device power supply
typedef struct _zet_sysman_psu_handle_t *zet_sysman_psu_handle_t;

///////////////////////////////////////////////////////////////////////////////
/// @brief Handle for a Sysman device fan
typedef struct _zet_sysman_fan_handle_t *zet_sysman_fan_handle_t;

///////////////////////////////////////////////////////////////////////////////
/// @brief Handle for a Sysman device LED
typedef struct _zet_sysman_led_handle_t *zet_sysman_led_handle_t;

///////////////////////////////////////////////////////////////////////////////
/// @brief Handle for a Sysman device RAS error set
typedef struct _zet_sysman_ras_handle_t *zet_sysman_ras_handle_t;

///////////////////////////////////////////////////////////////////////////////
/// @brief Handle for a Sysman device diagnostics test suite
typedef struct _zet_sysman_diag_handle_t *zet_sysman_diag_handle_t;

///////////////////////////////////////////////////////////////////////////////
/// @brief Handle for a Sysman device event
typedef struct _zet_sysman_event_handle_t *zet_sysman_event_handle_t;

///////////////////////////////////////////////////////////////////////////////
/// @brief Forward-declare zet_metric_group_properties_t
typedef struct _zet_metric_group_properties_t zet_metric_group_properties_t;

///////////////////////////////////////////////////////////////////////////////
/// @brief Forward-declare zet_typed_value_t
typedef struct _zet_typed_value_t zet_typed_value_t;

///////////////////////////////////////////////////////////////////////////////
/// @brief Forward-declare zet_metric_properties_t
typedef struct _zet_metric_properties_t zet_metric_properties_t;

///////////////////////////////////////////////////////////////////////////////
/// @brief Forward-declare zet_metric_tracer_desc_t
typedef struct _zet_metric_tracer_desc_t zet_metric_tracer_desc_t;

///////////////////////////////////////////////////////////////////////////////
/// @brief Forward-declare zet_metric_query_pool_desc_t
typedef struct _zet_metric_query_pool_desc_t zet_metric_query_pool_desc_t;

///////////////////////////////////////////////////////////////////////////////
/// @brief Forward-declare zet_sysman_properties_t
typedef struct _zet_sysman_properties_t zet_sysman_properties_t;

///////////////////////////////////////////////////////////////////////////////
/// @brief Forward-declare zet_sched_timeout_properties_t
typedef struct _zet_sched_timeout_properties_t zet_sched_timeout_properties_t;

///////////////////////////////////////////////////////////////////////////////
/// @brief Forward-declare zet_sched_timeslice_properties_t
typedef struct _zet_sched_timeslice_properties_t zet_sched_timeslice_properties_t;

///////////////////////////////////////////////////////////////////////////////
/// @brief Forward-declare zet_process_state_t
typedef struct _zet_process_state_t zet_process_state_t;

///////////////////////////////////////////////////////////////////////////////
/// @brief Forward-declare zet_pci_address_t
typedef struct _zet_pci_address_t zet_pci_address_t;

///////////////////////////////////////////////////////////////////////////////
/// @brief Forward-declare zet_pci_speed_t
typedef struct _zet_pci_speed_t zet_pci_speed_t;

///////////////////////////////////////////////////////////////////////////////
/// @brief Forward-declare zet_pci_properties_t
typedef struct _zet_pci_properties_t zet_pci_properties_t;

///////////////////////////////////////////////////////////////////////////////
/// @brief Forward-declare zet_pci_state_t
typedef struct _zet_pci_state_t zet_pci_state_t;

///////////////////////////////////////////////////////////////////////////////
/// @brief Forward-declare zet_pci_bar_properties_t
typedef struct _zet_pci_bar_properties_t zet_pci_bar_properties_t;

///////////////////////////////////////////////////////////////////////////////
/// @brief Forward-declare zet_pci_stats_t
typedef struct _zet_pci_stats_t zet_pci_stats_t;

///////////////////////////////////////////////////////////////////////////////
/// @brief Forward-declare zet_power_properties_t
typedef struct _zet_power_properties_t zet_power_properties_t;

///////////////////////////////////////////////////////////////////////////////
/// @brief Forward-declare zet_power_energy_counter_t
typedef struct _zet_power_energy_counter_t zet_power_energy_counter_t;

///////////////////////////////////////////////////////////////////////////////
/// @brief Forward-declare zet_power_sustained_limit_t
typedef struct _zet_power_sustained_limit_t zet_power_sustained_limit_t;

///////////////////////////////////////////////////////////////////////////////
/// @brief Forward-declare zet_power_burst_limit_t
typedef struct _zet_power_burst_limit_t zet_power_burst_limit_t;

///////////////////////////////////////////////////////////////////////////////
/// @brief Forward-declare zet_power_peak_limit_t
typedef struct _zet_power_peak_limit_t zet_power_peak_limit_t;

///////////////////////////////////////////////////////////////////////////////
/// @brief Forward-declare zet_energy_threshold_t
typedef struct _zet_energy_threshold_t zet_energy_threshold_t;

///////////////////////////////////////////////////////////////////////////////
/// @brief Forward-declare zet_freq_properties_t
typedef struct _zet_freq_properties_t zet_freq_properties_t;

///////////////////////////////////////////////////////////////////////////////
/// @brief Forward-declare zet_freq_range_t
typedef struct _zet_freq_range_t zet_freq_range_t;

///////////////////////////////////////////////////////////////////////////////
/// @brief Forward-declare zet_freq_state_t
typedef struct _zet_freq_state_t zet_freq_state_t;

///////////////////////////////////////////////////////////////////////////////
/// @brief Forward-declare zet_freq_throttle_time_t
typedef struct _zet_freq_throttle_time_t zet_freq_throttle_time_t;

///////////////////////////////////////////////////////////////////////////////
/// @brief Forward-declare zet_oc_capabilities_t
typedef struct _zet_oc_capabilities_t zet_oc_capabilities_t;

///////////////////////////////////////////////////////////////////////////////
/// @brief Forward-declare zet_oc_config_t
typedef struct _zet_oc_config_t zet_oc_config_t;

///////////////////////////////////////////////////////////////////////////////
/// @brief Forward-declare zet_engine_properties_t
typedef struct _zet_engine_properties_t zet_engine_properties_t;

///////////////////////////////////////////////////////////////////////////////
/// @brief Forward-declare zet_engine_stats_t
typedef struct _zet_engine_stats_t zet_engine_stats_t;

///////////////////////////////////////////////////////////////////////////////
/// @brief Forward-declare zet_standby_properties_t
typedef struct _zet_standby_properties_t zet_standby_properties_t;

///////////////////////////////////////////////////////////////////////////////
/// @brief Forward-declare zet_firmware_properties_t
typedef struct _zet_firmware_properties_t zet_firmware_properties_t;

///////////////////////////////////////////////////////////////////////////////
/// @brief Forward-declare zet_mem_properties_t
typedef struct _zet_mem_properties_t zet_mem_properties_t;

///////////////////////////////////////////////////////////////////////////////
/// @brief Forward-declare zet_mem_state_t
typedef struct _zet_mem_state_t zet_mem_state_t;

///////////////////////////////////////////////////////////////////////////////
/// @brief Forward-declare zet_mem_bandwidth_t
typedef struct _zet_mem_bandwidth_t zet_mem_bandwidth_t;

///////////////////////////////////////////////////////////////////////////////
/// @brief Forward-declare zet_fabric_port_uuid_t
typedef struct _zet_fabric_port_uuid_t zet_fabric_port_uuid_t;

///////////////////////////////////////////////////////////////////////////////
/// @brief Forward-declare zet_fabric_port_speed_t
typedef struct _zet_fabric_port_speed_t zet_fabric_port_speed_t;

///////////////////////////////////////////////////////////////////////////////
/// @brief Forward-declare zet_fabric_port_properties_t
typedef struct _zet_fabric_port_properties_t zet_fabric_port_properties_t;

///////////////////////////////////////////////////////////////////////////////
/// @brief Forward-declare zet_fabric_link_type_t
typedef struct _zet_fabric_link_type_t zet_fabric_link_type_t;

///////////////////////////////////////////////////////////////////////////////
/// @brief Forward-declare zet_fabric_port_config_t
typedef struct _zet_fabric_port_config_t zet_fabric_port_config_t;

///////////////////////////////////////////////////////////////////////////////
/// @brief Forward-declare zet_fabric_port_state_t
typedef struct _zet_fabric_port_state_t zet_fabric_port_state_t;

///////////////////////////////////////////////////////////////////////////////
/// @brief Forward-declare zet_fabric_port_throughput_t
typedef struct _zet_fabric_port_throughput_t zet_fabric_port_throughput_t;

///////////////////////////////////////////////////////////////////////////////
/// @brief Forward-declare zet_temp_properties_t
typedef struct _zet_temp_properties_t zet_temp_properties_t;

///////////////////////////////////////////////////////////////////////////////
/// @brief Forward-declare zet_temp_threshold_t
typedef struct _zet_temp_threshold_t zet_temp_threshold_t;

///////////////////////////////////////////////////////////////////////////////
/// @brief Forward-declare zet_temp_config_t
typedef struct _zet_temp_config_t zet_temp_config_t;

///////////////////////////////////////////////////////////////////////////////
/// @brief Forward-declare zet_psu_properties_t
typedef struct _zet_psu_properties_t zet_psu_properties_t;

///////////////////////////////////////////////////////////////////////////////
/// @brief Forward-declare zet_psu_state_t
typedef struct _zet_psu_state_t zet_psu_state_t;

///////////////////////////////////////////////////////////////////////////////
/// @brief Forward-declare zet_fan_temp_speed_t
typedef struct _zet_fan_temp_speed_t zet_fan_temp_speed_t;

///////////////////////////////////////////////////////////////////////////////
/// @brief Forward-declare zet_fan_properties_t
typedef struct _zet_fan_properties_t zet_fan_properties_t;

///////////////////////////////////////////////////////////////////////////////
/// @brief Forward-declare zet_fan_config_t
typedef struct _zet_fan_config_t zet_fan_config_t;

///////////////////////////////////////////////////////////////////////////////
/// @brief Forward-declare zet_led_properties_t
typedef struct _zet_led_properties_t zet_led_properties_t;

///////////////////////////////////////////////////////////////////////////////
/// @brief Forward-declare zet_led_state_t
typedef struct _zet_led_state_t zet_led_state_t;

///////////////////////////////////////////////////////////////////////////////
/// @brief Forward-declare zet_ras_properties_t
typedef struct _zet_ras_properties_t zet_ras_properties_t;

///////////////////////////////////////////////////////////////////////////////
/// @brief Forward-declare zet_ras_details_t
typedef struct _zet_ras_details_t zet_ras_details_t;

///////////////////////////////////////////////////////////////////////////////
/// @brief Forward-declare zet_ras_config_t
typedef struct _zet_ras_config_t zet_ras_config_t;

///////////////////////////////////////////////////////////////////////////////
/// @brief Forward-declare zet_event_config_t
typedef struct _zet_event_config_t zet_event_config_t;

///////////////////////////////////////////////////////////////////////////////
/// @brief Forward-declare zet_diag_test_t
typedef struct _zet_diag_test_t zet_diag_test_t;

///////////////////////////////////////////////////////////////////////////////
/// @brief Forward-declare zet_diag_properties_t
typedef struct _zet_diag_properties_t zet_diag_properties_t;

///////////////////////////////////////////////////////////////////////////////
/// @brief Forward-declare zet_profile_info_t
typedef struct _zet_profile_info_t zet_profile_info_t;

///////////////////////////////////////////////////////////////////////////////
/// @brief Forward-declare zet_profile_free_register_token_t
typedef struct _zet_profile_free_register_token_t zet_profile_free_register_token_t;

///////////////////////////////////////////////////////////////////////////////
/// @brief Forward-declare zet_profile_register_sequence_t
typedef struct _zet_profile_register_sequence_t zet_profile_register_sequence_t;

///////////////////////////////////////////////////////////////////////////////
/// @brief Forward-declare zet_tracer_desc_t
typedef struct _zet_tracer_desc_t zet_tracer_desc_t;

///////////////////////////////////////////////////////////////////////////////
/// @brief Forward-declare zet_debug_event_info_detached_t
typedef struct _zet_debug_event_info_detached_t zet_debug_event_info_detached_t;

///////////////////////////////////////////////////////////////////////////////
/// @brief Forward-declare zet_debug_event_info_module_t
typedef struct _zet_debug_event_info_module_t zet_debug_event_info_module_t;

///////////////////////////////////////////////////////////////////////////////
/// @brief Forward-declare zet_debug_event_info_exception_t
typedef struct _zet_debug_event_info_exception_t zet_debug_event_info_exception_t;

///////////////////////////////////////////////////////////////////////////////
/// @brief Forward-declare zet_debug_event_t
typedef struct _zet_debug_event_t zet_debug_event_t;

#if defined(__cplusplus)
} // extern "C"
#endif

#endif // _ZET_COMMON_H
