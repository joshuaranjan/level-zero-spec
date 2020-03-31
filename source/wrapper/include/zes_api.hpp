/*
 *
 * Copyright (C) 2019 Intel Corporation
 *
 * SPDX-License-Identifier: MIT
 *
 * @file zes_api.hpp
 * @version v1.0-r0.9.276
 *
 */
#ifndef _ZES_API_HPP
#define _ZES_API_HPP
#if defined(__cplusplus)
#pragma once

// C API headers
#include "zes_api.h"

// 'core' C++ API headers
#include "ze_api.hpp"

#pragma region common
namespace zes
{
    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Handle to a driver instance
    class Driver;
    struct _driver_handle_t;
    using driver_handle_t = _driver_handle_t*;

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Handle of device object
    class Device;
    struct _device_handle_t;
    using device_handle_t = _device_handle_t*;

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Handle for a Sysman device scheduler queue
    class Scheduler;
    struct _sched_handle_t;
    using sched_handle_t = _sched_handle_t*;

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Handle for a Sysman device performance factors
    class PerformanceFactor;
    struct _perf_handle_t;
    using perf_handle_t = _perf_handle_t*;

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Handle for a Sysman device power domain
    class Power;
    struct _pwr_handle_t;
    using pwr_handle_t = _pwr_handle_t*;

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Handle for a Sysman device frequency domain
    class Frequency;
    struct _freq_handle_t;
    using freq_handle_t = _freq_handle_t*;

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Handle for a Sysman device engine group
    class Engine;
    struct _engine_handle_t;
    using engine_handle_t = _engine_handle_t*;

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Handle for a Sysman device standby control
    class Standby;
    struct _standby_handle_t;
    using standby_handle_t = _standby_handle_t*;

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Handle for a Sysman device firmware
    class Firmware;
    struct _firmware_handle_t;
    using firmware_handle_t = _firmware_handle_t*;

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Handle for a Sysman device memory module
    class Memory;
    struct _mem_handle_t;
    using mem_handle_t = _mem_handle_t*;

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Handle for a Sysman fabric port
    class FabricPort;
    struct _fabric_port_handle_t;
    using fabric_port_handle_t = _fabric_port_handle_t*;

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Handle for a Sysman device temperature sensor
    class Temperature;
    struct _temp_handle_t;
    using temp_handle_t = _temp_handle_t*;

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Handle for a Sysman device power supply
    class Psu;
    struct _psu_handle_t;
    using psu_handle_t = _psu_handle_t*;

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Handle for a Sysman device fan
    class Fan;
    struct _fan_handle_t;
    using fan_handle_t = _fan_handle_t*;

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Handle for a Sysman device LED
    class Led;
    struct _led_handle_t;
    using led_handle_t = _led_handle_t*;

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Handle for a Sysman device RAS error set
    class Ras;
    struct _ras_handle_t;
    using ras_handle_t = _ras_handle_t*;

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Handle for a Sysman device diagnostics test suite
    class Diagnostics;
    struct _diag_handle_t;
    using diag_handle_t = _diag_handle_t*;

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Handle for a Sysman device event
    class Event;
    struct _event_handle_t;
    using event_handle_t = _event_handle_t*;

} // namespace zes

namespace zes
{
} // namespace zes

namespace zes
{
    using result_t = ze::result_t;
    using exception_t = ze::exception_t;

} // namespace zes
#pragma endregion
#pragma region device
///////////////////////////////////////////////////////////////////////////////
#ifndef ZES_STRING_PROPERTY_SIZE
/// @brief Maximum number of characters in string properties.
#define ZES_STRING_PROPERTY_SIZE  64
#endif // ZES_STRING_PROPERTY_SIZE

namespace zes
{
    ///////////////////////////////////////////////////////////////////////////////
    /// @brief C++ wrapper for driver instance
    class Driver : public ze::Driver
    {
    public:

    protected:
        ///////////////////////////////////////////////////////////////////////////////

    public:
        ///////////////////////////////////////////////////////////////////////////////
        using ze::Driver::Driver;

        ~Driver( void ) = default;

        Driver( Driver const& other ) = delete;
        void operator=( Driver const& other ) = delete;

        Driver( Driver&& other ) = delete;
        void operator=( Driver&& other ) = delete;

        ///////////////////////////////////////////////////////////////////////////////

    };

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief C++ wrapper for device
    class Device : public ze::Device
    {
    public:
        ///////////////////////////////////////////////////////////////////////////////
        /// @brief API version of Sysman
        enum class version_t
        {
            CURRENT = ZE_MAKE_VERSION( 1, 0 ),              ///< version 1.0

        };

        ///////////////////////////////////////////////////////////////////////////////
        /// @brief Types of accelerator engines
        enum class engine_type_t
        {
            OTHER = 0,                                      ///< Undefined types of accelerators.
            COMPUTE,                                        ///< Engines that process compute kernels.
            _3D,                                            ///< Engines that process 3D content
            MEDIA,                                          ///< Engines that process media workloads
            DMA,                                            ///< Engines that copy blocks of data

        };

        ///////////////////////////////////////////////////////////////////////////////
        /// @brief Device repair status
        enum class repair_status_t
        {
            UNSUPPORTED = 0,                                ///< The device does not support in-field repairs.
            NOT_PERFORMED,                                  ///< The device has never been repaired.
            PERFORMED,                                      ///< The device has been repaired.

        };

        ///////////////////////////////////////////////////////////////////////////////
        /// @brief Device reset reasons
        enum class reset_reasons_t
        {
            NONE = 0,                                       ///< The device does not need to be reset
            WEDGED = ZE_BIT( 0 ),                           ///< The device needs to be reset because one or more parts of the hardware
                                                            ///< is wedged
            REPAIR = ZE_BIT( 1 ),                           ///< The device needs to be reset in order to complete in-field repairs

        };

        ///////////////////////////////////////////////////////////////////////////////
        /// @brief PCI link status
        enum class pci_link_status_t
        {
            GREEN = 0,                                      ///< The link is up and operating as expected
            YELLOW,                                         ///< The link is up but has quality and/or bandwidth degradation
            RED,                                            ///< The link has stability issues and preventing workloads making forward
                                                            ///< progress

        };

        ///////////////////////////////////////////////////////////////////////////////
        /// @brief PCI link quality degradation reasons
        enum class pci_link_qual_issues_t
        {
            NONE = 0,                                       ///< There are no quality issues with the link at this time
            REPLAYS = ZE_BIT( 0 ),                          ///< An significant number of replays are occurring
            SPEED = ZE_BIT( 1 ),                            ///< There is a degradation in the maximum bandwidth of the link

        };

        ///////////////////////////////////////////////////////////////////////////////
        /// @brief PCI link stability issues
        enum class pci_link_stab_issues_t
        {
            NONE = 0,                                       ///< There are no connection stability issues at this time
            RETRAINING = ZE_BIT( 0 ),                       ///< Link retraining has occurred to deal with quality issues

        };

        ///////////////////////////////////////////////////////////////////////////////
        /// @brief PCI bar types
        enum class pci_bar_type_t
        {
            MMIO = 0,                                       ///< MMIO registers
            ROM,                                            ///< ROM aperture
            MEM,                                            ///< Device memory

        };

        ///////////////////////////////////////////////////////////////////////////////
        /// @brief Event types
        enum class event_type_t
        {
            NONE = 0,                                       ///< Specifies no events
            DEVICE_RESET = ZE_BIT( 0 ),                     ///< Event is triggered when the driver is going to reset the device
            DEVICE_SLEEP_STATE_ENTER = ZE_BIT( 1 ),         ///< Event is triggered when the driver is about to put the device into a
                                                            ///< deep sleep state
            DEVICE_SLEEP_STATE_EXIT = ZE_BIT( 2 ),          ///< Event is triggered when the driver is waking the device up from a deep
                                                            ///< sleep state
            FREQ_THROTTLED = ZE_BIT( 3 ),                   ///< Event is triggered when the frequency starts being throttled
            ENERGY_THRESHOLD_CROSSED = ZE_BIT( 4 ),         ///< Event is triggered when the energy consumption threshold is reached
                                                            ///< (use ::zesPowerSetEnergyThreshold() to configure).
            TEMP_CRITICAL = ZE_BIT( 5 ),                    ///< Event is triggered when the critical temperature is reached (use
                                                            ///< ::zesTemperatureSetConfig() to configure - disabled by default).
            TEMP_THRESHOLD1 = ZE_BIT( 6 ),                  ///< Event is triggered when the temperature crosses threshold 1 (use
                                                            ///< ::zesTemperatureSetConfig() to configure - disabled by default).
            TEMP_THRESHOLD2 = ZE_BIT( 7 ),                  ///< Event is triggered when the temperature crosses threshold 2 (use
                                                            ///< ::zesTemperatureSetConfig() to configure - disabled by default).
            MEM_HEALTH = ZE_BIT( 8 ),                       ///< Event is triggered when the health of device memory changes.
            FABRIC_PORT_HEALTH = ZE_BIT( 9 ),               ///< Event is triggered when the health of fabric ports change.
            PCI_LINK_HEALTH = ZE_BIT( 10 ),                 ///< Event is triggered when the health of the PCI link changes.
            RAS_CORRECTABLE_ERRORS = ZE_BIT( 11 ),          ///< Event is triggered when accelerator RAS correctable errors cross
                                                            ///< thresholds (use ::zesRasSetConfig() to configure - disabled by
                                                            ///< default).
            RAS_UNCORRECTABLE_ERRORS = ZE_BIT( 12 ),        ///< Event is triggered when accelerator RAS uncorrectable errors cross
                                                            ///< thresholds (use ::zesRasSetConfig() to configure - disabled by
                                                            ///< default).
            DEVICE_RESET_REQUIRED = ZE_BIT( 14 ),           ///< Event is triggered when the device needs to be reset (use
                                                            ///< ::zesDeviceGetState() to determine the reasons for the reset).
            ALL = 0x0FFF,                                   ///< Specifies all events

        };

        ///////////////////////////////////////////////////////////////////////////////
        /// @brief Frequency domains.
        enum class freq_domain_t
        {
            GPU = 0,                                        ///< GPU Core Domain.
            MEMORY,                                         ///< Local Memory Domain.

        };

        ///////////////////////////////////////////////////////////////////////////////
        /// @brief Scheduler mode
        enum class sched_mode_t
        {
            TIMEOUT = 0,                                    ///< Multiple applications or contexts are submitting work to the hardware.
                                                            ///< When higher priority work arrives, the scheduler attempts to pause the
                                                            ///< current executing work within some timeout interval, then submits the
                                                            ///< other work.
            TIMESLICE,                                      ///< The scheduler attempts to fairly timeslice hardware execution time
                                                            ///< between multiple contexts submitting work to the hardware
                                                            ///< concurrently.
            EXCLUSIVE,                                      ///< Any application or context can run indefinitely on the hardware
                                                            ///< without being preempted or terminated. All pending work for other
                                                            ///< contexts must wait until the running context completes with no further
                                                            ///< submitted work.
            COMPUTE_UNIT_DEBUG,                             ///< Scheduler ensures that submission of workloads to the hardware is
                                                            ///< optimized for compute unit debugging.

        };

        ///////////////////////////////////////////////////////////////////////////////
        /// @brief Device state
        struct state_t
        {
            uint32_t reset;                                 ///< [out] Indicates if the device needs to be reset and for what reasons
                                                            ///< (bitfield of ::zes_reset_reasons_t)
            repair_status_t repaired;                       ///< [out] Indicates if the device has been repaired

        };

        ///////////////////////////////////////////////////////////////////////////////
        /// @brief Device properties
        struct properties_t
        {
            ze::Device::properties_t core;                  ///< [out] Core device properties
            uint32_t numSubdevices;                         ///< [out] Number of sub-devices
            int8_t serialNumber[ZES_STRING_PROPERTY_SIZE];  ///< [out] Manufacturing serial number (NULL terminated string value)
            int8_t boardNumber[ZES_STRING_PROPERTY_SIZE];   ///< [out] Manufacturing board number (NULL terminated string value)
            int8_t brandName[ZES_STRING_PROPERTY_SIZE];     ///< [out] Brand name of the device (NULL terminated string value)
            int8_t modelName[ZES_STRING_PROPERTY_SIZE];     ///< [out] Model name of the device (NULL terminated string value)
            int8_t vendorName[ZES_STRING_PROPERTY_SIZE];    ///< [out] Vendor name of the device (NULL terminated string value)
            int8_t driverVersion[ZES_STRING_PROPERTY_SIZE]; ///< [out] Installed driver version (NULL terminated string value)

        };

        ///////////////////////////////////////////////////////////////////////////////
        /// @brief Contains information about a process that has an open connection with
        ///        this device
        /// 
        /// @details
        ///     - The application can use the process ID to query the OS for the owner
        ///       and the path to the executable.
        struct process_state_t
        {
            uint32_t processId;                             ///< [out] Host OS process ID.
            int64_t memSize;                                ///< [out] Device memory size in bytes allocated by this process (may not
                                                            ///< necessarily be resident on the device at the time of reading).
            uint64_t engines;                               ///< [out] Bitfield of accelerator engines being used by this process (or
                                                            ///< 1<<::zes_engine_type_t together).

        };

        ///////////////////////////////////////////////////////////////////////////////
        /// @brief PCI address
        struct pci_address_t
        {
            uint32_t domain;                                ///< [out] BDF domain
            uint32_t bus;                                   ///< [out] BDF bus
            uint32_t device;                                ///< [out] BDF device
            uint32_t function;                              ///< [out] BDF function

        };

        ///////////////////////////////////////////////////////////////////////////////
        /// @brief PCI speed
        struct pci_speed_t
        {
            uint32_t gen;                                   ///< [out] The link generation
            uint32_t width;                                 ///< [out] The number of lanes
            uint64_t maxBandwidth;                          ///< [out] The maximum bandwidth in bytes/sec

        };

        ///////////////////////////////////////////////////////////////////////////////
        /// @brief Static PCI properties
        struct pci_properties_t
        {
            pci_address_t address;                          ///< [out] The BDF address
            pci_speed_t maxSpeed;                           ///< [out] Fastest port configuration supported by the device.

        };

        ///////////////////////////////////////////////////////////////////////////////
        /// @brief Dynamic PCI state
        struct pci_state_t
        {
            pci_link_status_t status;                       ///< [out] The current status of the port
            pci_link_qual_issues_t qualityIssues;           ///< [out] If status is ::ZES_PCI_LINK_STATUS_YELLOW, this gives a bitfield
                                                            ///< of quality issues that have been detected
            pci_link_stab_issues_t stabilityIssues;         ///< [out] If status is ::ZES_PCI_LINK_STATUS_RED, this gives a bitfield of
                                                            ///< reasons for the connection instability
            pci_speed_t speed;                              ///< [out] The current port configure speed

        };

        ///////////////////////////////////////////////////////////////////////////////
        /// @brief Properties of a pci bar
        struct pci_bar_properties_t
        {
            pci_bar_type_t type;                            ///< [out] The type of bar
            uint32_t index;                                 ///< [out] The index of the bar
            uint64_t base;                                  ///< [out] Base address of the bar.
            uint64_t size;                                  ///< [out] Size of the bar.

        };

        ///////////////////////////////////////////////////////////////////////////////
        /// @brief PCI stats counters
        /// 
        /// @details
        ///     - Percent throughput is calculated by taking two snapshots (s1, s2) and
        ///       using the equation: %bw = 10^6 * ((s2.rxCounter - s1.rxCounter) +
        ///       (s2.txCounter - s1.txCounter)) / (s2.maxBandwidth * (s2.timestamp -
        ///       s1.timestamp))
        ///     - Percent replays is calculated by taking two snapshots (s1, s2) and
        ///       using the equation: %replay = 10^6 * (s2.replayCounter -
        ///       s1.replayCounter) / (s2.maxBandwidth * (s2.timestamp - s1.timestamp))
        struct pci_stats_t
        {
            uint64_t timestamp;                             ///< [out] Monotonic timestamp counter in microseconds when the measurement
                                                            ///< was made.
                                                            ///< No assumption should be made about the absolute value of the timestamp.
                                                            ///< It should only be used to calculate delta time between two snapshots
                                                            ///< of the same structure.
                                                            ///< Never take the delta of this timestamp with the timestamp from a
                                                            ///< different structure.
            uint64_t replayCounter;                         ///< [out] Monotonic counter for the number of replay packets
            uint64_t packetCounter;                         ///< [out] Monotonic counter for the number of packets
            uint64_t rxCounter;                             ///< [out] Monotonic counter for the number of bytes received
            uint64_t txCounter;                             ///< [out] Monotonic counter for the number of bytes transmitted (including
                                                            ///< replays)
            pci_speed_t speed;                              ///< [out] The current speed of the link

        };

        ///////////////////////////////////////////////////////////////////////////////
        /// @brief Configuration for timeout scheduler mode (::ZES_SCHED_MODE_TIMEOUT)
        struct sched_timeout_properties_t
        {
            uint64_t watchdogTimeout;                       ///< [in,out] The maximum time in microseconds that the scheduler will wait
                                                            ///< for a batch of work submitted to a hardware engine to complete or to
                                                            ///< be preempted so as to run another context.
                                                            ///< If this time is exceeded, the hardware engine is reset and the context terminated.
                                                            ///< If set to ::ZES_SCHED_WATCHDOG_DISABLE, a running workload can run as
                                                            ///< long as it wants without being terminated, but preemption attempts to
                                                            ///< run other contexts are permitted but not enforced.

        };

        ///////////////////////////////////////////////////////////////////////////////
        /// @brief Configuration for timeslice scheduler mode
        ///        (::ZES_SCHED_MODE_TIMESLICE)
        struct sched_timeslice_properties_t
        {
            uint64_t interval;                              ///< [in,out] The average interval in microseconds that a submission for a
                                                            ///< context will run on a hardware engine before being preempted out to
                                                            ///< run a pending submission for another context.
            uint64_t yieldTimeout;                          ///< [in,out] The maximum time in microseconds that the scheduler will wait
                                                            ///< to preempt a workload running on an engine before deciding to reset
                                                            ///< the hardware engine and terminating the associated context.

        };


    protected:
        ///////////////////////////////////////////////////////////////////////////////

    public:
        ///////////////////////////////////////////////////////////////////////////////
        using ze::Device::Device;

        ~Device( void ) = default;

        Device( Device const& other ) = delete;
        void operator=( Device const& other ) = delete;

        Device( Device&& other ) = delete;
        void operator=( Device&& other ) = delete;

        ///////////////////////////////////////////////////////////////////////////////

        ///////////////////////////////////////////////////////////////////////////////
        /// @brief Get properties about the device
        /// 
        /// @details
        ///     - The application may call this function from simultaneous threads.
        ///     - The implementation of this function should be lock-free.
        /// @throws result_t
        void __zecall
        GetProperties(
            properties_t* pProperties                       ///< [in,out] Structure that will contain information about the device.
            );

        ///////////////////////////////////////////////////////////////////////////////
        /// @brief Get information about the state of the device - if a reset is
        ///        required, reasons for the reset and if the device has been repaired
        /// 
        /// @details
        ///     - The application may call this function from simultaneous threads.
        ///     - The implementation of this function should be lock-free.
        /// @throws result_t
        void __zecall
        GetState(
            state_t* pState                                 ///< [in,out] Structure that will contain information about the device.
            );

        ///////////////////////////////////////////////////////////////////////////////
        /// @brief Reset device
        /// 
        /// @details
        ///     - Performs a PCI bus reset of the device. This will result in all
        ///       current device state being lost.
        ///     - All applications using the device should be stopped before calling
        ///       this function.
        ///     - If the force argument is specified, all applications using the device
        ///       will be forcibly killed.
        ///     - The function will block until the device has restarted or a timeout
        ///       occurred waiting for the reset to complete.
        /// @throws result_t
        void __zecall
        Reset(
            ze::bool_t force                                ///< [in] If set to true, all applications that are currently using the
                                                            ///< device will be forcibly killed.
            );

        ///////////////////////////////////////////////////////////////////////////////
        /// @brief Get information about host processes using the device
        /// 
        /// @details
        ///     - The number of processes connected to the device is dynamic. This means
        ///       that between a call to determine the correct value of pCount and the
        ///       subsequent call, the number of processes may have increased. It is
        ///       recommended that a large array be passed in so as to avoid receiving
        ///       the error ::ZE_RESULT_ERROR_INVALID_SIZE.
        ///     - The application may call this function from simultaneous threads.
        ///     - The implementation of this function should be lock-free.
        /// @throws result_t
        void __zecall
        ProcessesGetState(
            uint32_t* pCount,                               ///< [in,out] pointer to the number of processes.
                                                            ///< if count is zero, then the driver will update the value with the total
                                                            ///< number of processes currently using the device.
                                                            ///< if count is non-zero but less than the number of processes, the driver
                                                            ///< will set to the number of processes currently using the device and
                                                            ///< return the error ::ZE_RESULT_ERROR_INVALID_SIZE.
                                                            ///< if count is larger than the number of processes, then the driver will
                                                            ///< update the value with the correct number of processes that are returned.
            process_state_t* pProcesses = nullptr           ///< [in,out][optional][range(0, *pCount)] array of process information,
                                                            ///< one for each process currently using the device
            );

        ///////////////////////////////////////////////////////////////////////////////
        /// @brief Get PCI properties - address, max speed
        /// 
        /// @details
        ///     - The application may call this function from simultaneous threads.
        ///     - The implementation of this function should be lock-free.
        /// @throws result_t
        void __zecall
        PciGetProperties(
            pci_properties_t* pProperties                   ///< [in,out] Will contain the PCI properties.
            );

        ///////////////////////////////////////////////////////////////////////////////
        /// @brief Get current PCI state - current speed
        /// 
        /// @details
        ///     - The application may call this function from simultaneous threads.
        ///     - The implementation of this function should be lock-free.
        /// @throws result_t
        void __zecall
        PciGetState(
            pci_state_t* pState                             ///< [in,out] Will contain the PCI properties.
            );

        ///////////////////////////////////////////////////////////////////////////////
        /// @brief Get information about each configured bar
        /// 
        /// @details
        ///     - The application may call this function from simultaneous threads.
        ///     - The implementation of this function should be lock-free.
        /// @throws result_t
        void __zecall
        PciGetBars(
            uint32_t* pCount,                               ///< [in,out] pointer to the number of PCI bars.
                                                            ///< if count is zero, then the driver will update the value with the total
                                                            ///< number of bars.
                                                            ///< if count is non-zero, then driver will only retrieve that number of bars.
                                                            ///< if count is larger than the number of bar, then the driver will update
                                                            ///< the value with the correct number of bars that are returned.
            pci_bar_properties_t* pProperties = nullptr     ///< [in,out][optional][range(0, *pCount)] array of bar properties
            );

        ///////////////////////////////////////////////////////////////////////////////
        /// @brief Get PCI stats - bandwidth, number of packets, number of replays
        /// 
        /// @details
        ///     - The application may call this function from simultaneous threads.
        ///     - The implementation of this function should be lock-free.
        /// @throws result_t
        void __zecall
        PciGetStats(
            pci_stats_t* pStats                             ///< [in,out] Will contain a snapshot of the latest stats.
            );

        ///////////////////////////////////////////////////////////////////////////////
        /// @brief Get handle of diagnostics test suites
        /// 
        /// @details
        ///     - The application may call this function from simultaneous threads.
        ///     - The implementation of this function should be lock-free.
        /// @throws result_t
        void __zecall
        EnumDiagnosticTestSuites(
            uint32_t* pCount,                               ///< [in,out] pointer to the number of components of this type.
                                                            ///< if count is zero, then the driver will update the value with the total
                                                            ///< number of components of this type.
                                                            ///< if count is non-zero, then driver will only retrieve that number of components.
                                                            ///< if count is larger than the number of components available, then the
                                                            ///< driver will update the value with the correct number of components
                                                            ///< that are returned.
            Diagnostics** ppDiagnostics = nullptr           ///< [in,out][optional][range(0, *pCount)] array of pointer to components
                                                            ///< of this type
            );

        ///////////////////////////////////////////////////////////////////////////////
        /// @brief Get handle of engine groups
        /// 
        /// @details
        ///     - The application may call this function from simultaneous threads.
        ///     - The implementation of this function should be lock-free.
        /// @throws result_t
        void __zecall
        EnumEngineGroups(
            uint32_t* pCount,                               ///< [in,out] pointer to the number of components of this type.
                                                            ///< if count is zero, then the driver will update the value with the total
                                                            ///< number of components of this type.
                                                            ///< if count is non-zero, then driver will only retrieve that number of components.
                                                            ///< if count is larger than the number of components available, then the
                                                            ///< driver will update the value with the correct number of components
                                                            ///< that are returned.
            Engine** ppEngine = nullptr                     ///< [in,out][optional][range(0, *pCount)] array of pointer to components
                                                            ///< of this type
            );

        ///////////////////////////////////////////////////////////////////////////////
        /// @brief Get the event handle for the specified device
        /// 
        /// @details
        ///     - The application may call this function from simultaneous threads.
        ///     - The implementation of this function should be lock-free.
        /// @returns
        ///     - Event*: The event handle for the specified device.
        /// 
        /// @throws result_t
        Event* __zecall
        CreateEvents(
            void
            );

        ///////////////////////////////////////////////////////////////////////////////
        /// @brief Get handle of Fabric ports in a device
        /// 
        /// @details
        ///     - The application may call this function from simultaneous threads.
        ///     - The implementation of this function should be lock-free.
        /// @throws result_t
        void __zecall
        EnumFabricPorts(
            uint32_t* pCount,                               ///< [in,out] pointer to the number of components of this type.
                                                            ///< if count is zero, then the driver will update the value with the total
                                                            ///< number of components of this type.
                                                            ///< if count is non-zero, then driver will only retrieve that number of components.
                                                            ///< if count is larger than the number of components available, then the
                                                            ///< driver will update the value with the correct number of components
                                                            ///< that are returned.
            FabricPort** ppPort = nullptr                   ///< [in,out][optional][range(0, *pCount)] array of pointer to components
                                                            ///< of this type
            );

        ///////////////////////////////////////////////////////////////////////////////
        /// @brief Get handle of fans
        /// 
        /// @details
        ///     - The application may call this function from simultaneous threads.
        ///     - The implementation of this function should be lock-free.
        /// @throws result_t
        void __zecall
        EnumFans(
            uint32_t* pCount,                               ///< [in,out] pointer to the number of components of this type.
                                                            ///< if count is zero, then the driver will update the value with the total
                                                            ///< number of components of this type.
                                                            ///< if count is non-zero, then driver will only retrieve that number of components.
                                                            ///< if count is larger than the number of components available, then the
                                                            ///< driver will update the value with the correct number of components
                                                            ///< that are returned.
            Fan** ppFan = nullptr                           ///< [in,out][optional][range(0, *pCount)] array of pointer to components
                                                            ///< of this type
            );

        ///////////////////////////////////////////////////////////////////////////////
        /// @brief Get handle of firmwares
        /// 
        /// @details
        ///     - The application may call this function from simultaneous threads.
        ///     - The implementation of this function should be lock-free.
        /// @throws result_t
        void __zecall
        EnumFirmwares(
            uint32_t* pCount,                               ///< [in,out] pointer to the number of components of this type.
                                                            ///< if count is zero, then the driver will update the value with the total
                                                            ///< number of components of this type.
                                                            ///< if count is non-zero, then driver will only retrieve that number of components.
                                                            ///< if count is larger than the number of components available, then the
                                                            ///< driver will update the value with the correct number of components
                                                            ///< that are returned.
            Firmware** ppFirmware = nullptr                 ///< [in,out][optional][range(0, *pCount)] array of pointer to components
                                                            ///< of this type
            );

        ///////////////////////////////////////////////////////////////////////////////
        /// @brief Get handle of frequency domains
        /// 
        /// @details
        ///     - The application may call this function from simultaneous threads.
        ///     - The implementation of this function should be lock-free.
        /// @throws result_t
        void __zecall
        EnumFrequencyDomains(
            uint32_t* pCount,                               ///< [in,out] pointer to the number of components of this type.
                                                            ///< if count is zero, then the driver will update the value with the total
                                                            ///< number of components of this type.
                                                            ///< if count is non-zero, then driver will only retrieve that number of components.
                                                            ///< if count is larger than the number of components available, then the
                                                            ///< driver will update the value with the correct number of components
                                                            ///< that are returned.
            Frequency** ppFrequency = nullptr               ///< [in,out][optional][range(0, *pCount)] array of pointer to components
                                                            ///< of this type
            );

        ///////////////////////////////////////////////////////////////////////////////
        /// @brief Get handle of LEDs
        /// 
        /// @details
        ///     - The application may call this function from simultaneous threads.
        ///     - The implementation of this function should be lock-free.
        /// @throws result_t
        void __zecall
        EnumLeds(
            uint32_t* pCount,                               ///< [in,out] pointer to the number of components of this type.
                                                            ///< if count is zero, then the driver will update the value with the total
                                                            ///< number of components of this type.
                                                            ///< if count is non-zero, then driver will only retrieve that number of components.
                                                            ///< if count is larger than the number of components available, then the
                                                            ///< driver will update the value with the correct number of components
                                                            ///< that are returned.
            Led** ppLed = nullptr                           ///< [in,out][optional][range(0, *pCount)] array of pointer to components
                                                            ///< of this type
            );

        ///////////////////////////////////////////////////////////////////////////////
        /// @brief Get handle of memory modules
        /// 
        /// @details
        ///     - The application may call this function from simultaneous threads.
        ///     - The implementation of this function should be lock-free.
        /// @throws result_t
        void __zecall
        EnumMemoryModules(
            uint32_t* pCount,                               ///< [in,out] pointer to the number of components of this type.
                                                            ///< if count is zero, then the driver will update the value with the total
                                                            ///< number of components of this type.
                                                            ///< if count is non-zero, then driver will only retrieve that number of components.
                                                            ///< if count is larger than the number of components available, then the
                                                            ///< driver will update the value with the correct number of components
                                                            ///< that are returned.
            Memory** ppMemory = nullptr                     ///< [in,out][optional][range(0, *pCount)] array of pointer to components
                                                            ///< of this type
            );

        ///////////////////////////////////////////////////////////////////////////////
        /// @brief Get handles to accelerator domains whose performance can be optimized
        ///        via a Performance Factor
        /// 
        /// @details
        ///     - A Performance Factor should be tuned for each workload.
        ///     - The application may call this function from simultaneous threads.
        ///     - The implementation of this function should be lock-free.
        /// @throws result_t
        void __zecall
        EnumPerformanceFactorDomains(
            uint32_t* pCount,                               ///< [in,out] pointer to the number of components of this type.
                                                            ///< if count is zero, then the driver will update the value with the total
                                                            ///< number of components of this type.
                                                            ///< if count is non-zero, then driver will only retrieve that number of components.
                                                            ///< if count is larger than the number of components available, then the
                                                            ///< driver will update the value with the correct number of components
                                                            ///< that are returned.
            PerformanceFactor** ppPerf = nullptr            ///< [in,out][optional][range(0, *pCount)] array of pointer to components
                                                            ///< of this type
            );

        ///////////////////////////////////////////////////////////////////////////////
        /// @brief Get handle of power domains
        /// 
        /// @details
        ///     - The application may call this function from simultaneous threads.
        ///     - The implementation of this function should be lock-free.
        /// @throws result_t
        void __zecall
        EnumPowerDomains(
            uint32_t* pCount,                               ///< [in,out] pointer to the number of components of this type.
                                                            ///< if count is zero, then the driver will update the value with the total
                                                            ///< number of components of this type.
                                                            ///< if count is non-zero, then driver will only retrieve that number of components.
                                                            ///< if count is larger than the number of components available, then the
                                                            ///< driver will update the value with the correct number of components
                                                            ///< that are returned.
            Power** ppPower = nullptr                       ///< [in,out][optional][range(0, *pCount)] array of pointer to components
                                                            ///< of this type
            );

        ///////////////////////////////////////////////////////////////////////////////
        /// @brief Get handle of power supplies
        /// 
        /// @details
        ///     - The application may call this function from simultaneous threads.
        ///     - The implementation of this function should be lock-free.
        /// @throws result_t
        void __zecall
        EnumPsus(
            uint32_t* pCount,                               ///< [in,out] pointer to the number of components of this type.
                                                            ///< if count is zero, then the driver will update the value with the total
                                                            ///< number of components of this type.
                                                            ///< if count is non-zero, then driver will only retrieve that number of components.
                                                            ///< if count is larger than the number of components available, then the
                                                            ///< driver will update the value with the correct number of components
                                                            ///< that are returned.
            Psu** ppPsu = nullptr                           ///< [in,out][optional][range(0, *pCount)] array of pointer to components
                                                            ///< of this type
            );

        ///////////////////////////////////////////////////////////////////////////////
        /// @brief Get handle of all RAS error sets on a device
        /// 
        /// @details
        ///     - A RAS error set is a collection of RAS error counters of a given type
        ///       (correctable/uncorrectable) from hardware blocks contained within a
        ///       sub-device or within the device.
        ///     - A device without sub-devices will typically return two handles, one
        ///       for correctable errors sets and one for uncorrectable error sets.
        ///     - A device with sub-devices will return RAS error sets for each
        ///       sub-device and possibly RAS error sets for hardware blocks outside the
        ///       sub-devices.
        ///     - If the function completes successfully but pCount is set to 0, RAS
        ///       features are not available/enabled on this device.
        ///     - The application may call this function from simultaneous threads.
        ///     - The implementation of this function should be lock-free.
        /// @throws result_t
        void __zecall
        EnumRasErrorSets(
            uint32_t* pCount,                               ///< [in,out] pointer to the number of components of this type.
                                                            ///< if count is zero, then the driver will update the value with the total
                                                            ///< number of components of this type.
                                                            ///< if count is non-zero, then driver will only retrieve that number of components.
                                                            ///< if count is larger than the number of components available, then the
                                                            ///< driver will update the value with the correct number of components
                                                            ///< that are returned.
            Ras** ppRas = nullptr                           ///< [in,out][optional][range(0, *pCount)] array of pointer to components
                                                            ///< of this type
            );

        ///////////////////////////////////////////////////////////////////////////////
        /// @brief Get handle to a scheduler component
        /// 
        /// @details
        ///     - The application may call this function from simultaneous threads.
        ///     - The implementation of this function should be lock-free.
        /// @throws result_t
        void __zecall
        EnumSchedulers(
            uint32_t* pCount,                               ///< [in,out] pointer to the number of components of this type.
                                                            ///< if count is zero, then the driver will update the value with the total
                                                            ///< number of components of this type.
                                                            ///< if count is non-zero, then driver will only retrieve that number of components.
                                                            ///< if count is larger than the number of components available, then the
                                                            ///< driver will update the value with the correct number of components
                                                            ///< that are returned.
            Scheduler** ppScheduler = nullptr               ///< [in,out][optional][range(0, *pCount)] array of pointer to components
                                                            ///< of this type
            );

        ///////////////////////////////////////////////////////////////////////////////
        /// @brief Get handle of standby controls
        /// 
        /// @details
        ///     - The application may call this function from simultaneous threads.
        ///     - The implementation of this function should be lock-free.
        /// @throws result_t
        void __zecall
        EnumStandbyDomains(
            uint32_t* pCount,                               ///< [in,out] pointer to the number of components of this type.
                                                            ///< if count is zero, then the driver will update the value with the total
                                                            ///< number of components of this type.
                                                            ///< if count is non-zero, then driver will only retrieve that number of components.
                                                            ///< if count is larger than the number of components available, then the
                                                            ///< driver will update the value with the correct number of components
                                                            ///< that are returned.
            Standby** ppStandby = nullptr                   ///< [in,out][optional][range(0, *pCount)] array of pointer to components
                                                            ///< of this type
            );

        ///////////////////////////////////////////////////////////////////////////////
        /// @brief Get handle of temperature sensors
        /// 
        /// @details
        ///     - The application may call this function from simultaneous threads.
        ///     - The implementation of this function should be lock-free.
        /// @throws result_t
        void __zecall
        EnumTemperatureSensors(
            uint32_t* pCount,                               ///< [in,out] pointer to the number of components of this type.
                                                            ///< if count is zero, then the driver will update the value with the total
                                                            ///< number of components of this type.
                                                            ///< if count is non-zero, then driver will only retrieve that number of components.
                                                            ///< if count is larger than the number of components available, then the
                                                            ///< driver will update the value with the correct number of components
                                                            ///< that are returned.
            Temperature** ppTemperature = nullptr           ///< [in,out][optional][range(0, *pCount)] array of pointer to components
                                                            ///< of this type
            );

    };

} // namespace zes

namespace zes
{
    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Converts Device::version_t to std::string
    std::string to_string( const Device::version_t val );

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Converts Device::engine_type_t to std::string
    std::string to_string( const Device::engine_type_t val );

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Converts Device::repair_status_t to std::string
    std::string to_string( const Device::repair_status_t val );

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Converts Device::reset_reasons_t to std::string
    std::string to_string( const Device::reset_reasons_t val );

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Converts Device::state_t to std::string
    std::string to_string( const Device::state_t val );

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Converts Device::properties_t to std::string
    std::string to_string( const Device::properties_t val );

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Converts Device::process_state_t to std::string
    std::string to_string( const Device::process_state_t val );

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Converts Device::pci_address_t to std::string
    std::string to_string( const Device::pci_address_t val );

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Converts Device::pci_speed_t to std::string
    std::string to_string( const Device::pci_speed_t val );

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Converts Device::pci_properties_t to std::string
    std::string to_string( const Device::pci_properties_t val );

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Converts Device::pci_link_status_t to std::string
    std::string to_string( const Device::pci_link_status_t val );

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Converts Device::pci_link_qual_issues_t to std::string
    std::string to_string( const Device::pci_link_qual_issues_t val );

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Converts Device::pci_link_stab_issues_t to std::string
    std::string to_string( const Device::pci_link_stab_issues_t val );

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Converts Device::pci_state_t to std::string
    std::string to_string( const Device::pci_state_t val );

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Converts Device::pci_bar_type_t to std::string
    std::string to_string( const Device::pci_bar_type_t val );

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Converts Device::pci_bar_properties_t to std::string
    std::string to_string( const Device::pci_bar_properties_t val );

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Converts Device::pci_stats_t to std::string
    std::string to_string( const Device::pci_stats_t val );

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Converts Device::event_type_t to std::string
    std::string to_string( const Device::event_type_t val );

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Converts Device::freq_domain_t to std::string
    std::string to_string( const Device::freq_domain_t val );

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Converts Device::sched_mode_t to std::string
    std::string to_string( const Device::sched_mode_t val );

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Converts Device::sched_timeout_properties_t to std::string
    std::string to_string( const Device::sched_timeout_properties_t val );

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Converts Device::sched_timeslice_properties_t to std::string
    std::string to_string( const Device::sched_timeslice_properties_t val );

} // namespace zes
#pragma endregion
#pragma region diagnostics
///////////////////////////////////////////////////////////////////////////////
#ifndef ZES_DIAG_FIRST_TEST_INDEX
/// @brief Diagnostic test index to use for the very first test.
#define ZES_DIAG_FIRST_TEST_INDEX  0x0
#endif // ZES_DIAG_FIRST_TEST_INDEX

///////////////////////////////////////////////////////////////////////////////
#ifndef ZES_DIAG_LAST_TEST_INDEX
/// @brief Diagnostic test index to use for the very last test.
#define ZES_DIAG_LAST_TEST_INDEX  0xFFFFFFFF
#endif // ZES_DIAG_LAST_TEST_INDEX

namespace zes
{
    ///////////////////////////////////////////////////////////////////////////////
    /// @brief C++ wrapper for a Sysman device diagnostic test suite
    class Diagnostics
    {
    public:
        ///////////////////////////////////////////////////////////////////////////////
        /// @brief Diagnostic test suite type
        enum class diag_type_t
        {
            SCAN = 0,                                       ///< Run SCAN diagnostics
            ARRAY,                                          ///< Run Array diagnostics

        };

        ///////////////////////////////////////////////////////////////////////////////
        /// @brief Diagnostic results
        enum class diag_result_t
        {
            NO_ERRORS = 0,                                  ///< Diagnostic completed without finding errors to repair
            ABORT,                                          ///< Diagnostic had problems running tests
            FAIL_CANT_REPAIR,                               ///< Diagnostic had problems setting up repairs
            REBOOT_FOR_REPAIR,                              ///< Diagnostics found errors, setup for repair and reboot is required to
                                                            ///< complete the process

        };

        ///////////////////////////////////////////////////////////////////////////////
        /// @brief Diagnostic test
        struct diag_test_t
        {
            uint32_t index;                                 ///< [out] Index of the test
            char name[ZES_STRING_PROPERTY_SIZE];            ///< [out] Name of the test

        };

        ///////////////////////////////////////////////////////////////////////////////
        /// @brief Diagnostics test suite properties
        struct diag_properties_t
        {
            diag_type_t type;                               ///< [out] The type of diagnostics test suite
            ze::bool_t onSubdevice;                         ///< [out] True if the resource is located on a sub-device; false means
                                                            ///< that the resource is on the device of the calling Sysman handle
            uint32_t subdeviceId;                           ///< [out] If onSubdevice is true, this gives the ID of the sub-device
            char name[ZES_STRING_PROPERTY_SIZE];            ///< [out] Name of the diagnostics test suite
            ze::bool_t haveTests;                           ///< [out] Indicates if this test suite has individual tests which can be
                                                            ///< run separately (use the function ::zesDiagnosticsGetTests() to get the
                                                            ///< list of these tests)

        };


    protected:
        ///////////////////////////////////////////////////////////////////////////////
        diag_handle_t m_handle = nullptr;               ///< [in] handle of Sysman object
        Device* m_pDevice;                              ///< [in] pointer to owner object

    public:
        ///////////////////////////////////////////////////////////////////////////////
        Diagnostics( void ) = delete;
        Diagnostics( 
            diag_handle_t handle,                           ///< [in] handle of Sysman object
            Device* pDevice                                 ///< [in] pointer to owner object
            );

        ~Diagnostics( void ) = default;

        Diagnostics( Diagnostics const& other ) = delete;
        void operator=( Diagnostics const& other ) = delete;

        Diagnostics( Diagnostics&& other ) = delete;
        void operator=( Diagnostics&& other ) = delete;

        ///////////////////////////////////////////////////////////////////////////////
        auto getHandle( void ) const { return m_handle; }
        auto getDevice( void ) const { return m_pDevice; }

        ///////////////////////////////////////////////////////////////////////////////
        /// @brief Get properties of a diagnostics test suite
        /// 
        /// @details
        ///     - The application may call this function from simultaneous threads.
        ///     - The implementation of this function should be lock-free.
        /// @throws result_t
        void __zecall
        GetProperties(
            diag_properties_t* pProperties                  ///< [in,out] Structure describing the properties of a diagnostics test
                                                            ///< suite
            );

        ///////////////////////////////////////////////////////////////////////////////
        /// @brief Get individual tests that can be run separately. Not all test suites
        ///        permit running individual tests - check
        ///        ::zes_diag_properties_t.haveTests
        /// 
        /// @details
        ///     - The list of available tests is returned in order of increasing test
        ///       index ::zes_diag_test_t.index.
        ///     - The application may call this function from simultaneous threads.
        ///     - The implementation of this function should be lock-free.
        /// @throws result_t
        void __zecall
        GetTests(
            uint32_t* pCount,                               ///< [in,out] pointer to the number of tests.
                                                            ///< If count is zero, then the driver will update the value with the total
                                                            ///< number of tests available.
                                                            ///< If count is non-zero, then driver will only retrieve that number of tests.
                                                            ///< If count is larger than the number of tests available, then the driver
                                                            ///< will update the value with the correct number of tests available.
            diag_test_t* pTests = nullptr                   ///< [in,out][optional][range(0, *pCount)] Array of tests sorted by
                                                            ///< increasing value of ::zes_diag_test_t.index
            );

        ///////////////////////////////////////////////////////////////////////////////
        /// @brief Run a diagnostics test suite, either all tests or a subset of tests.
        /// 
        /// @details
        ///     - WARNING: Performancing diagnostics may destroy current device state
        ///       information. Gracefully close any running workloads before initiating.
        ///     - To run all tests in a test suite, set start =
        ///       ::ZES_DIAG_FIRST_TEST_INDEX and end = ::ZES_DIAG_LAST_TEST_INDEX.
        ///     - If the test suite permits running individual tests,
        ///       ::zes_diag_properties_t.haveTests will be true. In this case, the
        ///       function ::zesDiagnosticsGetTests() can be called to get the list of
        ///       tests and corresponding indices that can be supplied to the arguments
        ///       start and end in this function.
        ///     - This function will block until the diagnostics have completed.
        /// @throws result_t
        void __zecall
        RunTests(
            uint32_t start,                                 ///< [in] The index of the first test to run. Set to
                                                            ///< ::ZES_DIAG_FIRST_TEST_INDEX to start from the beginning.
            uint32_t end,                                   ///< [in] The index of the last test to run. Set to
                                                            ///< ::ZES_DIAG_LAST_TEST_INDEX to complete all tests after the start test.
            diag_result_t* pResult                          ///< [in,out] The result of the diagnostics
            );

    };

} // namespace zes

namespace zes
{
    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Converts Diagnostics::diag_type_t to std::string
    std::string to_string( const Diagnostics::diag_type_t val );

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Converts Diagnostics::diag_result_t to std::string
    std::string to_string( const Diagnostics::diag_result_t val );

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Converts Diagnostics::diag_test_t to std::string
    std::string to_string( const Diagnostics::diag_test_t val );

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Converts Diagnostics::diag_properties_t to std::string
    std::string to_string( const Diagnostics::diag_properties_t val );

} // namespace zes
#pragma endregion
#pragma region engine
namespace zes
{
    ///////////////////////////////////////////////////////////////////////////////
    /// @brief C++ wrapper for a Sysman device engine group
    class Engine
    {
    public:
        ///////////////////////////////////////////////////////////////////////////////
        /// @brief Accelerator engine groups
        enum class group_t
        {
            ALL = 0,                                        ///< Access information about all engines combined.
            COMPUTE_ALL,                                    ///< Access information about all compute engines combined.
            MEDIA_ALL,                                      ///< Access information about all media engines combined.
            COPY_ALL,                                       ///< Access information about all copy (blitter) engines combined.

        };

        ///////////////////////////////////////////////////////////////////////////////
        /// @brief Engine group properties
        struct properties_t
        {
            group_t type;                                   ///< [out] The engine group
            ze::bool_t onSubdevice;                         ///< [out] True if this resource is located on a sub-device; false means
                                                            ///< that the resource is on the device of the calling Sysman handle
            uint32_t subdeviceId;                           ///< [out] If onSubdevice is true, this gives the ID of the sub-device

        };

        ///////////////////////////////////////////////////////////////////////////////
        /// @brief Engine activity counters
        /// 
        /// @details
        ///     - Percent utilization is calculated by taking two snapshots (s1, s2) and
        ///       using the equation: %util = (s2.activeTime - s1.activeTime) /
        ///       (s2.timestamp - s1.timestamp)
        struct stats_t
        {
            uint64_t activeTime;                            ///< [out] Monotonic counter for time in microseconds that this resource is
                                                            ///< actively running workloads.
            uint64_t timestamp;                             ///< [out] Monotonic timestamp counter in microseconds when activeTime
                                                            ///< counter was sampled.
                                                            ///< No assumption should be made about the absolute value of the timestamp.
                                                            ///< It should only be used to calculate delta time between two snapshots
                                                            ///< of the same structure.
                                                            ///< Never take the delta of this timestamp with the timestamp from a
                                                            ///< different structure.

        };


    protected:
        ///////////////////////////////////////////////////////////////////////////////
        engine_handle_t m_handle = nullptr;             ///< [in] handle of Sysman object
        Device* m_pDevice;                              ///< [in] pointer to owner object

    public:
        ///////////////////////////////////////////////////////////////////////////////
        Engine( void ) = delete;
        Engine( 
            engine_handle_t handle,                         ///< [in] handle of Sysman object
            Device* pDevice                                 ///< [in] pointer to owner object
            );

        ~Engine( void ) = default;

        Engine( Engine const& other ) = delete;
        void operator=( Engine const& other ) = delete;

        Engine( Engine&& other ) = delete;
        void operator=( Engine&& other ) = delete;

        ///////////////////////////////////////////////////////////////////////////////
        auto getHandle( void ) const { return m_handle; }
        auto getDevice( void ) const { return m_pDevice; }

        ///////////////////////////////////////////////////////////////////////////////
        /// @brief Get engine group properties
        /// 
        /// @details
        ///     - The application may call this function from simultaneous threads.
        ///     - The implementation of this function should be lock-free.
        /// @throws result_t
        void __zecall
        GetProperties(
            properties_t* pProperties                       ///< [in,out] The properties for the specified engine group.
            );

        ///////////////////////////////////////////////////////////////////////////////
        /// @brief Get the activity stats for an engine group
        /// 
        /// @details
        ///     - The application may call this function from simultaneous threads.
        ///     - The implementation of this function should be lock-free.
        /// @throws result_t
        void __zecall
        GetActivity(
            stats_t* pStats                                 ///< [in,out] Will contain a snapshot of the engine group activity
                                                            ///< counters.
            );

    };

} // namespace zes

namespace zes
{
    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Converts Engine::group_t to std::string
    std::string to_string( const Engine::group_t val );

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Converts Engine::properties_t to std::string
    std::string to_string( const Engine::properties_t val );

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Converts Engine::stats_t to std::string
    std::string to_string( const Engine::stats_t val );

} // namespace zes
#pragma endregion
#pragma region events
///////////////////////////////////////////////////////////////////////////////
#ifndef ZES_EVENT_WAIT_NONE
/// @brief Don't wait - just check if there are any new events
#define ZES_EVENT_WAIT_NONE  0x0
#endif // ZES_EVENT_WAIT_NONE

///////////////////////////////////////////////////////////////////////////////
#ifndef ZES_EVENT_WAIT_INFINITE
/// @brief Wait infinitely for events to arrive.
#define ZES_EVENT_WAIT_INFINITE  0xFFFFFFFF
#endif // ZES_EVENT_WAIT_INFINITE

namespace zes
{
    ///////////////////////////////////////////////////////////////////////////////
    /// @brief C++ wrapper for a Sysman device event
    class Event
    {
    public:
        ///////////////////////////////////////////////////////////////////////////////
        /// @brief Event configuration for a device
        struct config_t
        {
            uint32_t registered;                            ///< [in,out] List of registered events (Bitfield of events
                                                            ///< ::zes_event_type_t). ::ZES_EVENT_TYPE_NONE indicates there are no
                                                            ///< registered events. ::ZES_EVENT_TYPE_ALL indicates that all events are
                                                            ///< registered.

        };


    protected:
        ///////////////////////////////////////////////////////////////////////////////
        event_handle_t m_handle = nullptr;              ///< [in] handle of Sysman object
        Device* m_pDevice;                              ///< [in] pointer to owner object

    public:
        ///////////////////////////////////////////////////////////////////////////////
        Event( void ) = delete;
        Event( 
            event_handle_t handle,                          ///< [in] handle of Sysman object
            Device* pDevice                                 ///< [in] pointer to owner object
            );

        ~Event( void ) = default;

        Event( Event const& other ) = delete;
        void operator=( Event const& other ) = delete;

        Event( Event&& other ) = delete;
        void operator=( Event&& other ) = delete;

        ///////////////////////////////////////////////////////////////////////////////
        auto getHandle( void ) const { return m_handle; }
        auto getDevice( void ) const { return m_pDevice; }

        ///////////////////////////////////////////////////////////////////////////////
        /// @brief Find out which events are currently registered on the specified device
        ///        event handler
        /// 
        /// @details
        ///     - The application may call this function from simultaneous threads.
        ///     - The implementation of this function should be lock-free.
        /// @throws result_t
        void __zecall
        GetConfig(
            config_t* pConfig                               ///< [in,out] Will contain the current event configuration (list of
                                                            ///< registered events).
            );

        ///////////////////////////////////////////////////////////////////////////////
        /// @brief Set a new event configuration (list of registered events) on the
        ///        specified device event handler
        /// 
        /// @details
        ///     - The application may call this function from simultaneous threads.
        ///     - The implementation of this function should be lock-free.
        /// @throws result_t
        void __zecall
        SetConfig(
            const config_t* pConfig                         ///< [in] New event configuration (list of registered events).
            );

        ///////////////////////////////////////////////////////////////////////////////
        /// @brief Get events that have been triggered for a specific device
        /// 
        /// @details
        ///     - If events have occurred on the specified device event handle, they are
        ///       returned and the corresponding event status is cleared if the argument
        ///       clear = true.
        ///     - The application may call this function from simultaneous threads.
        ///     - The implementation of this function should be lock-free.
        /// @throws result_t
        void __zecall
        GetState(
            ze::bool_t clear,                               ///< [in] Indicates if the event list for this device should be cleared.
            uint32_t* pEvents                               ///< [in,out] Bitfield of events ::zes_event_type_t that have been
                                                            ///< triggered by this device.
            );

        ///////////////////////////////////////////////////////////////////////////////
        /// @brief Wait for the specified list of event handles to receive any registered
        ///        events
        /// 
        /// @details
        ///     - If previous events arrived and were not cleared using
        ///       ::zesEventGetState(), this call will return immediately.
        ///     - The application may call this function from simultaneous threads.
        ///     - The implementation of this function should be lock-free.
        /// @throws result_t
        static void __zecall
        Listen(
            ze::Driver* pDriver,                            ///< [in] pointer to the driver instance
            uint32_t timeout,                               ///< [in] How long to wait in milliseconds for events to arrive. Set to
                                                            ///< ::ZES_EVENT_WAIT_NONE will check status and return immediately. Set to
                                                            ///< ::ZES_EVENT_WAIT_INFINITE to block until events arrive.
            uint32_t count,                                 ///< [in] Number of handles in phEvents
            Event** ppEvents,                               ///< [in][range(0, count)] Handle of events that should be listened to
            uint32_t* pEvents                               ///< [in,out] Bitfield of events ::zes_event_type_t that have been
                                                            ///< triggered by any of the supplied event handles. If timeout is not
                                                            ///< ::ZES_EVENT_WAIT_INFINITE and this value is ::ZES_EVENT_TYPE_NONE,
                                                            ///< then a timeout has occurred.
            );

    };

} // namespace zes

namespace zes
{
    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Converts Event::config_t to std::string
    std::string to_string( const Event::config_t val );

} // namespace zes
#pragma endregion
#pragma region fabric
///////////////////////////////////////////////////////////////////////////////
#ifndef ZES_MAX_FABRIC_PORT_MODEL_SIZE
/// @brief Maximum Fabric port model string size
#define ZES_MAX_FABRIC_PORT_MODEL_SIZE  256
#endif // ZES_MAX_FABRIC_PORT_MODEL_SIZE

///////////////////////////////////////////////////////////////////////////////
#ifndef ZES_MAX_FABRIC_LINK_TYPE_SIZE
/// @brief Maximum size of the buffer that will return information about link
///        types
#define ZES_MAX_FABRIC_LINK_TYPE_SIZE  256
#endif // ZES_MAX_FABRIC_LINK_TYPE_SIZE

namespace zes
{
    ///////////////////////////////////////////////////////////////////////////////
    /// @brief C++ wrapper for a Sysman device Fabric port
    class FabricPort
    {
    public:
        ///////////////////////////////////////////////////////////////////////////////
        /// @brief Fabric port status
        enum class status_t
        {
            GREEN = 0,                                      ///< The port is up and operating as expected
            YELLOW,                                         ///< The port is up but has quality and/or speed degradation
            RED,                                            ///< Port connection instabilities are preventing workloads making forward
                                                            ///< progress
            BLACK,                                          ///< The port is configured down

        };

        ///////////////////////////////////////////////////////////////////////////////
        /// @brief Fabric port quality degradation reasons
        enum class qual_issues_t
        {
            NONE = 0,                                       ///< There are no quality issues with the link at this time
            FABRIC_PORT_QUAL_LINK_ERRORS = ZE_BIT( 0 ),     ///< Excessive link errors are occurring
            SPEED = ZE_BIT( 1 ),                            ///< There is a degradation in the bitrate and/or width of the link

        };

        ///////////////////////////////////////////////////////////////////////////////
        /// @brief Fabric port stability issues
        enum class stab_issues_t
        {
            NONE = 0,                                       ///< There are no connection stability issues at this time
            FAILED = ZE_BIT( 0 ),                           ///< A previously operating link has failed. Hardware will automatically
                                                            ///< retrain this port. This state will persist until either the physical
                                                            ///< connection is removed or the link trains successfully.
            TRAINING_TIMEOUT = ZE_BIT( 1 ),                 ///< A connection has not been established within an expected time.
                                                            ///< Hardware will continue to attempt port training. This status will
                                                            ///< persist until either the physical connection is removed or the link
                                                            ///< successfully trains.
            FLAPPING = ZE_BIT( 2 ),                         ///< Port has excessively trained and then transitioned down for some
                                                            ///< period of time. Driver will allow port to continue to train, but will
                                                            ///< not enable the port for use until the port has been disabled and
                                                            ///< subsequently re-enabled using ::zesFabricPortSetConfig().

        };

        ///////////////////////////////////////////////////////////////////////////////
        /// @brief Unique identifier for a fabric port
        /// 
        /// @details
        ///     - This not a universal identifier. The identified is garanteed to be
        ///       unique for the current hardware configuration of the system. Changes
        ///       in the hardware may result in a different identifier for a given port.
        ///     - The main purpose of this identifier to build up an instantaneous
        ///       topology map of system connectivity. An application should enumerate
        ///       all fabric ports and match ::zes_fabric_port_state_t.remotePortId to
        ///       ::zes_fabric_port_properties_t.portId.
        struct id_t
        {
            uint32_t fabricId;                              ///< [out] Unique identifier for the fabric end-point
            uint32_t attachId;                              ///< [out] Unique identifier for the device attachment point
            uint8_t portNumber;                             ///< [out] The logical port number (this is typically marked somewhere on
                                                            ///< the physical device)

        };

        ///////////////////////////////////////////////////////////////////////////////
        /// @brief Fabric port speed in one direction
        struct speed_t
        {
            uint64_t bitRate;                               ///< [out] Bits/sec that the link is operating at
            uint32_t width;                                 ///< [out] The number of lanes

        };

        ///////////////////////////////////////////////////////////////////////////////
        /// @brief Fabric port properties
        struct properties_t
        {
            int8_t model[ZES_MAX_FABRIC_PORT_MODEL_SIZE];   ///< [out] Description of port technology
            ze::bool_t onSubdevice;                         ///< [out] True if the port is located on a sub-device; false means that
                                                            ///< the port is on the device of the calling Sysman handle
            uint32_t subdeviceId;                           ///< [out] If onSubdevice is true, this gives the ID of the sub-device
            id_t portId;                                    ///< [out] The unique port identifier
            speed_t maxRxSpeed;                             ///< [out] Maximum speed supported by the receive side of the port
            speed_t maxTxSpeed;                             ///< [out] Maximum speed supported by the transmit side of the port

        };

        ///////////////////////////////////////////////////////////////////////////////
        /// @brief Provides information about the fabric link attached to a port
        struct fabric_link_type_t
        {
            int8_t desc[ZES_MAX_FABRIC_LINK_TYPE_SIZE];     ///< [out] This provides a static textural description of the physic
                                                            ///< attachment type

        };

        ///////////////////////////////////////////////////////////////////////////////
        /// @brief Fabric port configuration
        struct config_t
        {
            ze::bool_t enabled;                             ///< [in,out] Port is configured up/down
            ze::bool_t beaconing;                           ///< [in,out] Beaconing is configured on/off

        };

        ///////////////////////////////////////////////////////////////////////////////
        /// @brief Fabric port state
        struct state_t
        {
            status_t status;                                ///< [out] The current status of the port
            qual_issues_t qualityIssues;                    ///< [out] If status is ::ZES_FABRIC_PORT_STATUS_YELLOW, this gives a
                                                            ///< bitfield of quality issues that have been detected
            stab_issues_t stabilityIssues;                  ///< [out] If status is ::ZES_FABRIC_PORT_STATUS_RED, this gives a bitfield
                                                            ///< of reasons for the connection instability
            id_t remotePortId;                              ///< [out] The unique port identifier for the remote connection point
            speed_t rxSpeed;                                ///< [out] Current maximum receive speed
            speed_t txSpeed;                                ///< [out] Current maximum transmit speed

        };

        ///////////////////////////////////////////////////////////////////////////////
        /// @brief Fabric port throughput.
        struct throughput_t
        {
            uint64_t timestamp;                             ///< [out] Monotonic timestamp counter in microseconds when the measurement
                                                            ///< was made.
                                                            ///< No assumption should be made about the absolute value of the timestamp.
                                                            ///< It should only be used to calculate delta time between two snapshots
                                                            ///< of the same structure.
                                                            ///< Never take the delta of this timestamp with the timestamp from a
                                                            ///< different structure.
            uint64_t rxCounter;                             ///< [out] Monotonic counter for the number of bytes received. This
                                                            ///< includes all protocol overhead, not only the GPU traffic.
            uint64_t txCounter;                             ///< [out] Monotonic counter for the number of bytes transmitted. This
                                                            ///< includes all protocol overhead, not only the GPU traffic.

        };


    protected:
        ///////////////////////////////////////////////////////////////////////////////
        fabric_port_handle_t m_handle = nullptr;        ///< [in] handle of Sysman object
        Device* m_pDevice;                              ///< [in] pointer to owner object

    public:
        ///////////////////////////////////////////////////////////////////////////////
        FabricPort( void ) = delete;
        FabricPort( 
            fabric_port_handle_t handle,                    ///< [in] handle of Sysman object
            Device* pDevice                                 ///< [in] pointer to owner object
            );

        ~FabricPort( void ) = default;

        FabricPort( FabricPort const& other ) = delete;
        void operator=( FabricPort const& other ) = delete;

        FabricPort( FabricPort&& other ) = delete;
        void operator=( FabricPort&& other ) = delete;

        ///////////////////////////////////////////////////////////////////////////////
        auto getHandle( void ) const { return m_handle; }
        auto getDevice( void ) const { return m_pDevice; }

        ///////////////////////////////////////////////////////////////////////////////
        /// @brief Get Fabric port properties
        /// 
        /// @details
        ///     - The application may call this function from simultaneous threads.
        ///     - The implementation of this function should be lock-free.
        /// @throws result_t
        void __zecall
        GetProperties(
            properties_t* pProperties                       ///< [in,out] Will contain properties of the Fabric Port.
            );

        ///////////////////////////////////////////////////////////////////////////////
        /// @brief Get Fabric port link type
        /// 
        /// @details
        ///     - The application may call this function from simultaneous threads.
        ///     - The implementation of this function should be lock-free.
        /// @throws result_t
        void __zecall
        GetLinkType(
            ze::bool_t verbose,                             ///< [in] Set to true to get a more detailed report.
            fabric_link_type_t* pLinkType                   ///< [in,out] Will contain details about the link attached to the Fabric
                                                            ///< port.
            );

        ///////////////////////////////////////////////////////////////////////////////
        /// @brief Get Fabric port configuration
        /// 
        /// @details
        ///     - The application may call this function from simultaneous threads.
        ///     - The implementation of this function should be lock-free.
        /// @throws result_t
        void __zecall
        GetConfig(
            config_t* pConfig                               ///< [in,out] Will contain configuration of the Fabric Port.
            );

        ///////////////////////////////////////////////////////////////////////////////
        /// @brief Set Fabric port configuration
        /// 
        /// @details
        ///     - The application may call this function from simultaneous threads.
        ///     - The implementation of this function should be lock-free.
        /// @throws result_t
        void __zecall
        SetConfig(
            const config_t* pConfig                         ///< [in] Contains new configuration of the Fabric Port.
            );

        ///////////////////////////////////////////////////////////////////////////////
        /// @brief Get Fabric port state - status (green/yellow/red/black), reasons for
        ///        link degradation or instability, current rx/tx speed
        /// 
        /// @details
        ///     - The application may call this function from simultaneous threads.
        ///     - The implementation of this function should be lock-free.
        /// @throws result_t
        void __zecall
        GetState(
            state_t* pState                                 ///< [in,out] Will contain the current state of the Fabric Port
            );

        ///////////////////////////////////////////////////////////////////////////////
        /// @brief Get Fabric port throughput
        /// 
        /// @details
        ///     - The application may call this function from simultaneous threads.
        ///     - The implementation of this function should be lock-free.
        /// @throws result_t
        void __zecall
        GetThroughput(
            throughput_t* pThroughput                       ///< [in,out] Will contain the Fabric port throughput counters.
            );

    };

} // namespace zes

namespace zes
{
    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Converts FabricPort::status_t to std::string
    std::string to_string( const FabricPort::status_t val );

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Converts FabricPort::qual_issues_t to std::string
    std::string to_string( const FabricPort::qual_issues_t val );

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Converts FabricPort::stab_issues_t to std::string
    std::string to_string( const FabricPort::stab_issues_t val );

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Converts FabricPort::id_t to std::string
    std::string to_string( const FabricPort::id_t val );

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Converts FabricPort::speed_t to std::string
    std::string to_string( const FabricPort::speed_t val );

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Converts FabricPort::properties_t to std::string
    std::string to_string( const FabricPort::properties_t val );

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Converts FabricPort::fabric_link_type_t to std::string
    std::string to_string( const FabricPort::fabric_link_type_t val );

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Converts FabricPort::config_t to std::string
    std::string to_string( const FabricPort::config_t val );

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Converts FabricPort::state_t to std::string
    std::string to_string( const FabricPort::state_t val );

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Converts FabricPort::throughput_t to std::string
    std::string to_string( const FabricPort::throughput_t val );

} // namespace zes
#pragma endregion
#pragma region fan
///////////////////////////////////////////////////////////////////////////////
#ifndef ZES_FAN_TEMP_SPEED_PAIR_COUNT
/// @brief Maximum number of fan temperature/speed pairs in the fan speed table.
#define ZES_FAN_TEMP_SPEED_PAIR_COUNT  32
#endif // ZES_FAN_TEMP_SPEED_PAIR_COUNT

namespace zes
{
    ///////////////////////////////////////////////////////////////////////////////
    /// @brief C++ wrapper for a Sysman device fan
    class Fan
    {
    public:
        ///////////////////////////////////////////////////////////////////////////////
        /// @brief Fan resource speed mode
        enum class speed_mode_t
        {
            DEFAULT = 0,                                    ///< The fan speed is operating using the hardware default settings
            FIXED,                                          ///< The fan speed is currently set to a fixed value
            TABLE,                                          ///< The fan speed is currently controlled dynamically by hardware based on
                                                            ///< a temp/speed table

        };

        ///////////////////////////////////////////////////////////////////////////////
        /// @brief Fan speed units
        enum class speed_units_t
        {
            RPM = 0,                                        ///< The fan speed is in units of revolutions per minute (rpm)
            PERCENT,                                        ///< The fan speed is a percentage of the maximum speed of the fan

        };

        ///////////////////////////////////////////////////////////////////////////////
        /// @brief Fan temperature/speed pair
        struct temp_speed_t
        {
            uint32_t temperature;                           ///< [in,out] Temperature in degrees Celsius.
            uint32_t speed;                                 ///< [in,out] The speed of the fan
            speed_units_t units;                            ///< [in,out] The units of the member speed

        };

        ///////////////////////////////////////////////////////////////////////////////
        /// @brief Fan properties
        struct properties_t
        {
            ze::bool_t onSubdevice;                         ///< [out] True if the resource is located on a sub-device; false means
                                                            ///< that the resource is on the device of the calling Sysman handle
            uint32_t subdeviceId;                           ///< [out] If onSubdevice is true, this gives the ID of the sub-device
            ze::bool_t canControl;                          ///< [out] Indicates if software can control the fan speed assuming the
                                                            ///< user has permissions
            uint32_t maxSpeed;                              ///< [out] The maximum RPM of the fan
            uint32_t maxPoints;                             ///< [out] The maximum number of points in the fan temp/speed table

        };

        ///////////////////////////////////////////////////////////////////////////////
        /// @brief Fan configuration
        struct config_t
        {
            speed_mode_t mode;                              ///< [in,out] The fan speed mode (fixed, temp-speed table)
            uint32_t speed;                                 ///< [in,out] The fixed fan speed setting
            speed_units_t speedUnits;                       ///< [in,out] The units of the fixed fan speed setting
            uint32_t numPoints;                             ///< [in,out] The number of valid points in the fan speed table
            temp_speed_t table[ZES_FAN_TEMP_SPEED_PAIR_COUNT];  ///< [in,out] Array of temperature/fan speed pairs

        };


    protected:
        ///////////////////////////////////////////////////////////////////////////////
        fan_handle_t m_handle = nullptr;                ///< [in] handle of Sysman object
        Device* m_pDevice;                              ///< [in] pointer to owner object

    public:
        ///////////////////////////////////////////////////////////////////////////////
        Fan( void ) = delete;
        Fan( 
            fan_handle_t handle,                            ///< [in] handle of Sysman object
            Device* pDevice                                 ///< [in] pointer to owner object
            );

        ~Fan( void ) = default;

        Fan( Fan const& other ) = delete;
        void operator=( Fan const& other ) = delete;

        Fan( Fan&& other ) = delete;
        void operator=( Fan&& other ) = delete;

        ///////////////////////////////////////////////////////////////////////////////
        auto getHandle( void ) const { return m_handle; }
        auto getDevice( void ) const { return m_pDevice; }

        ///////////////////////////////////////////////////////////////////////////////
        /// @brief Get fan properties
        /// 
        /// @details
        ///     - The application may call this function from simultaneous threads.
        ///     - The implementation of this function should be lock-free.
        /// @throws result_t
        void __zecall
        GetProperties(
            properties_t* pProperties                       ///< [in,out] Will contain the properties of the fan.
            );

        ///////////////////////////////////////////////////////////////////////////////
        /// @brief Get current fan configuration
        /// 
        /// @details
        ///     - The application may call this function from simultaneous threads.
        ///     - The implementation of this function should be lock-free.
        /// @throws result_t
        void __zecall
        GetConfig(
            config_t* pConfig                               ///< [in,out] Will contain the current configuration of the fan.
            );

        ///////////////////////////////////////////////////////////////////////////////
        /// @brief Set fan configuration
        /// 
        /// @details
        ///     - The application may call this function from simultaneous threads.
        ///     - The implementation of this function should be lock-free.
        /// @throws result_t
        void __zecall
        SetConfig(
            const config_t* pConfig                         ///< [in] New fan configuration.
            );

        ///////////////////////////////////////////////////////////////////////////////
        /// @brief Get current state of a fan - current mode and speed
        /// 
        /// @details
        ///     - The application may call this function from simultaneous threads.
        ///     - The implementation of this function should be lock-free.
        /// @throws result_t
        void __zecall
        GetState(
            speed_units_t units,                            ///< [in] The units in which the fan speed should be returned.
            uint32_t* pSpeed                                ///< [in,out] Will contain the current speed of the fan in the units
                                                            ///< requested.
            );

    };

} // namespace zes

namespace zes
{
    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Converts Fan::speed_mode_t to std::string
    std::string to_string( const Fan::speed_mode_t val );

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Converts Fan::speed_units_t to std::string
    std::string to_string( const Fan::speed_units_t val );

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Converts Fan::temp_speed_t to std::string
    std::string to_string( const Fan::temp_speed_t val );

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Converts Fan::properties_t to std::string
    std::string to_string( const Fan::properties_t val );

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Converts Fan::config_t to std::string
    std::string to_string( const Fan::config_t val );

} // namespace zes
#pragma endregion
#pragma region firmware
namespace zes
{
    ///////////////////////////////////////////////////////////////////////////////
    /// @brief C++ wrapper for a Sysman device firmware
    class Firmware
    {
    public:
        ///////////////////////////////////////////////////////////////////////////////
        /// @brief Firmware properties
        struct properties_t
        {
            ze::bool_t onSubdevice;                         ///< [out] True if the resource is located on a sub-device; false means
                                                            ///< that the resource is on the device of the calling Sysman handle
            uint32_t subdeviceId;                           ///< [out] If onSubdevice is true, this gives the ID of the sub-device
            ze::bool_t canControl;                          ///< [out] Indicates if software can flash the firmware assuming the user
                                                            ///< has permissions
            int8_t name[ZES_STRING_PROPERTY_SIZE];          ///< [out] NULL terminated string value
            int8_t version[ZES_STRING_PROPERTY_SIZE];       ///< [out] NULL terminated string value

        };


    protected:
        ///////////////////////////////////////////////////////////////////////////////
        firmware_handle_t m_handle = nullptr;           ///< [in] handle of Sysman object
        Device* m_pDevice;                              ///< [in] pointer to owner object

    public:
        ///////////////////////////////////////////////////////////////////////////////
        Firmware( void ) = delete;
        Firmware( 
            firmware_handle_t handle,                       ///< [in] handle of Sysman object
            Device* pDevice                                 ///< [in] pointer to owner object
            );

        ~Firmware( void ) = default;

        Firmware( Firmware const& other ) = delete;
        void operator=( Firmware const& other ) = delete;

        Firmware( Firmware&& other ) = delete;
        void operator=( Firmware&& other ) = delete;

        ///////////////////////////////////////////////////////////////////////////////
        auto getHandle( void ) const { return m_handle; }
        auto getDevice( void ) const { return m_pDevice; }

        ///////////////////////////////////////////////////////////////////////////////
        /// @brief Get firmware properties
        /// 
        /// @details
        ///     - The application may call this function from simultaneous threads.
        ///     - The implementation of this function should be lock-free.
        /// @throws result_t
        void __zecall
        GetProperties(
            properties_t* pProperties                       ///< [in,out] Pointer to an array that will hold the properties of the
                                                            ///< firmware
            );

        ///////////////////////////////////////////////////////////////////////////////
        /// @brief Get firmware checksum
        /// 
        /// @details
        ///     - The application may call this function from simultaneous threads.
        ///     - The implementation of this function should be lock-free.
        /// @throws result_t
        void __zecall
        GetChecksum(
            uint32_t* pChecksum                             ///< [in,out] Calculated checksum of the installed firmware.
            );

        ///////////////////////////////////////////////////////////////////////////////
        /// @brief Flash a new firmware image
        /// 
        /// @details
        ///     - The application may call this function from simultaneous threads.
        ///     - The implementation of this function should be lock-free.
        /// @throws result_t
        void __zecall
        Flash(
            void* pImage,                                   ///< [in] Image of the new firmware to flash.
            uint32_t size                                   ///< [in] Size of the flash image.
            );

    };

} // namespace zes

namespace zes
{
    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Converts Firmware::properties_t to std::string
    std::string to_string( const Firmware::properties_t val );

} // namespace zes
#pragma endregion
#pragma region frequency
namespace zes
{
    ///////////////////////////////////////////////////////////////////////////////
    /// @brief C++ wrapper for a Sysman device frequency domain
    class Frequency
    {
    public:
        ///////////////////////////////////////////////////////////////////////////////
        /// @brief Frequency throttle reasons
        enum class freq_throttle_reasons_t
        {
            NONE = 0,                                       ///< frequency not throttled
            AVE_PWR_CAP = ZE_BIT( 0 ),                      ///< frequency throttled due to average power excursion (PL1)
            BURST_PWR_CAP = ZE_BIT( 1 ),                    ///< frequency throttled due to burst power excursion (PL2)
            CURRENT_LIMIT = ZE_BIT( 2 ),                    ///< frequency throttled due to current excursion (PL4)
            THERMAL_LIMIT = ZE_BIT( 3 ),                    ///< frequency throttled due to thermal excursion (T > TjMax)
            PSU_ALERT = ZE_BIT( 4 ),                        ///< frequency throttled due to power supply assertion
            SW_RANGE = ZE_BIT( 5 ),                         ///< frequency throttled due to software supplied frequency range
            HW_RANGE = ZE_BIT( 6 ),                         ///< frequency throttled due to a sub block that has a lower frequency
                                                            ///< range when it receives clocks

        };

        ///////////////////////////////////////////////////////////////////////////////
        /// @brief Overclocking modes
        enum class oc_mode_t
        {
            OFF = 0,                                        ///< Overclocking if off - hardware is running using factory default
                                                            ///< voltages/frequencies.
            OVERRIDE,                                       ///< Overclock override mode - In this mode, a fixed user-supplied voltage
                                                            ///< is applied independent of the frequency request. The maximum permitted
                                                            ///< frequency can also be increased.
            INTERPOLATIVE,                                  ///< Overclock interpolative mode - In this mode, the voltage/frequency
                                                            ///< curve can be extended with a new voltage/frequency point that will be
                                                            ///< interpolated. The existing voltage/frequency points can also be offset
                                                            ///< (up or down) by a fixed voltage.

        };

        ///////////////////////////////////////////////////////////////////////////////
        /// @brief Frequency properties
        /// 
        /// @details
        ///     - Indicates if this frequency domain can be overclocked (if true,
        ///       functions such as ::zesFrequencyOcSetConfig() are supported).
        ///     - The min/max hardware frequencies are specified for non-overclock
        ///       configurations. For overclock configurations, use
        ///       ::zesFrequencyOcGetConfig() to determine the maximum frequency that
        ///       can be requested.
        ///     - If step is non-zero, the available frequencies are (min, min + step,
        ///       min + 2xstep, ..., max). Otherwise, call
        ///       ::zesFrequencyGetAvailableClocks() to get the list of frequencies that
        ///       can be requested.
        struct freq_properties_t
        {
            Device::freq_domain_t type;                     ///< [out] The hardware block that this frequency domain controls (GPU,
                                                            ///< memory, ...)
            ze::bool_t onSubdevice;                         ///< [out] True if this resource is located on a sub-device; false means
                                                            ///< that the resource is on the device of the calling Sysman handle
            uint32_t subdeviceId;                           ///< [out] If onSubdevice is true, this gives the ID of the sub-device
            ze::bool_t canControl;                          ///< [out] Indicates if software can control the frequency of this domain
                                                            ///< assuming the user has permissions
            ze::bool_t isThrottleEventSupported;            ///< [out] Indicates if software can register to receive event
                                                            ///< ::ZES_EVENT_TYPE_FREQ_THROTTLED
            double min;                                     ///< [out] The minimum hardware clock frequency in units of MHz
            double max;                                     ///< [out] The maximum non-overclock hardware clock frequency in units of
                                                            ///< MHz.
            double step;                                    ///< [out] The minimum step-size for clock frequencies in units of MHz. The
                                                            ///< hardware will clamp intermediate frequencies to lowest multiplier of
                                                            ///< this number.

        };

        ///////////////////////////////////////////////////////////////////////////////
        /// @brief Frequency range between which the hardware can operate.
        struct freq_range_t
        {
            double min;                                     ///< [in,out] The min frequency in MHz below which hardware frequency
                                                            ///< management will not request frequencies. Setting to 0 will use the
                                                            ///< hardware default value.
            double max;                                     ///< [in,out] The max frequency in MHz above which hardware frequency
                                                            ///< management will not request frequencies. Setting to 0 will use the
                                                            ///< hardware default value.

        };

        ///////////////////////////////////////////////////////////////////////////////
        /// @brief Frequency state
        struct freq_state_t
        {
            double request;                                 ///< [out] The current frequency request in MHz.
            double tdp;                                     ///< [out] The maximum frequency in MHz supported under the current TDP
                                                            ///< conditions
            double efficient;                               ///< [out] The efficient minimum frequency in MHz
            double actual;                                  ///< [out] The resolved frequency in MHz
            uint32_t throttleReasons;                       ///< [out] The reasons that the frequency is being limited by the hardware
                                                            ///< (Bitfield of ::zes_freq_throttle_reasons_t).

        };

        ///////////////////////////////////////////////////////////////////////////////
        /// @brief Frequency throttle time snapshot
        /// 
        /// @details
        ///     - Percent time throttled is calculated by taking two snapshots (s1, s2)
        ///       and using the equation: %throttled = (s2.throttleTime -
        ///       s1.throttleTime) / (s2.timestamp - s1.timestamp)
        struct freq_throttle_time_t
        {
            uint64_t throttleTime;                          ///< [out] The monotonic counter of time in microseconds that the frequency
                                                            ///< has been limited by the hardware.
            uint64_t timestamp;                             ///< [out] Microsecond timestamp when throttleTime was captured.
                                                            ///< No assumption should be made about the absolute value of the timestamp.
                                                            ///< It should only be used to calculate delta time between two snapshots
                                                            ///< of the same structure.
                                                            ///< Never take the delta of this timestamp with the timestamp from a
                                                            ///< different structure.

        };

        ///////////////////////////////////////////////////////////////////////////////
        /// @brief Overclocking properties
        /// 
        /// @details
        ///     - Provides all the overclocking capabilities and properties supported by
        ///       the device for the frequency domain.
        struct oc_capabilities_t
        {
            ze::bool_t isOcSupported;                       ///< [out] Indicates if any overclocking features are supported on this
                                                            ///< frequency domain.
            double maxFactoryDefaultFrequency;              ///< [out] Factory default non-overclock maximum frequency in Mhz.
            double maxFactoryDefaultVoltage;                ///< [out] Factory default voltage used for the non-overclock maximum
                                                            ///< frequency in MHz.
            double maxOcFrequency;                          ///< [out] Maximum hardware overclocking frequency limit in Mhz.
            double minOcVoltageOffset;                      ///< [out] The minimum voltage offset that can be applied to the
                                                            ///< voltage/frequency curve. Note that this number can be negative.
            double maxOcVoltageOffset;                      ///< [out] The maximum voltage offset that can be applied to the
                                                            ///< voltage/frequency curve.
            double maxOcVoltage;                            ///< [out] The maximum overclock voltage that hardware supports.
            ze::bool_t isTjMaxSupported;                    ///< [out] Indicates if the maximum temperature limit (TjMax) can be
                                                            ///< changed for this frequency domain.
            ze::bool_t isIccMaxSupported;                   ///< [out] Indicates if the maximum current (IccMax) can be changed for
                                                            ///< this frequency domain.
            ze::bool_t isHighVoltModeCapable;               ///< [out] Indicates if this frequency domains supports a feature to set
                                                            ///< very high voltages.
            ze::bool_t isHighVoltModeEnabled;               ///< [out] Indicates if very high voltages are permitted on this frequency
                                                            ///< domain.

        };

        ///////////////////////////////////////////////////////////////////////////////
        /// @brief Overclocking configuration
        /// 
        /// @details
        ///     - Overclock settings
        struct oc_config_t
        {
            oc_mode_t mode;                                 ///< [in,out] Overclock Mode ::zes_oc_mode_t.
            double frequency;                               ///< [in,out] Overclocking Frequency in MHz. This cannot be greater than
                                                            ///< ::zes_oc_capabilities_t.maxOcFrequency.
            double voltageTarget;                           ///< [in,out] Overclock voltage in Volts. This cannot be greater than
                                                            ///< ::zes_oc_capabilities_t.maxOcVoltage.
            double voltageOffset;                           ///< [in,out] This voltage offset is applied to all points on the
                                                            ///< voltage/frequency curve, include the new overclock voltageTarget. It
                                                            ///< can be in the range (::zes_oc_capabilities_t.minOcVoltageOffset,
                                                            ///< ::zes_oc_capabilities_t.maxOcVoltageOffset).

        };


    protected:
        ///////////////////////////////////////////////////////////////////////////////
        freq_handle_t m_handle = nullptr;               ///< [in] handle of Sysman object
        Device* m_pDevice;                              ///< [in] pointer to owner object

    public:
        ///////////////////////////////////////////////////////////////////////////////
        Frequency( void ) = delete;
        Frequency( 
            freq_handle_t handle,                           ///< [in] handle of Sysman object
            Device* pDevice                                 ///< [in] pointer to owner object
            );

        ~Frequency( void ) = default;

        Frequency( Frequency const& other ) = delete;
        void operator=( Frequency const& other ) = delete;

        Frequency( Frequency&& other ) = delete;
        void operator=( Frequency&& other ) = delete;

        ///////////////////////////////////////////////////////////////////////////////
        auto getHandle( void ) const { return m_handle; }
        auto getDevice( void ) const { return m_pDevice; }

        ///////////////////////////////////////////////////////////////////////////////
        /// @brief Get frequency properties - available frequencies
        /// 
        /// @details
        ///     - The application may call this function from simultaneous threads.
        ///     - The implementation of this function should be lock-free.
        /// @throws result_t
        void __zecall
        GetProperties(
            freq_properties_t* pProperties                  ///< [in,out] The frequency properties for the specified domain.
            );

        ///////////////////////////////////////////////////////////////////////////////
        /// @brief Get available non-overclocked hardware clock frequencies for the
        ///        frequency domain
        /// 
        /// @details
        ///     - The list of available frequencies is returned in order of slowest to
        ///       fastest.
        ///     - The application may call this function from simultaneous threads.
        ///     - The implementation of this function should be lock-free.
        /// @throws result_t
        void __zecall
        GetAvailableClocks(
            uint32_t* pCount,                               ///< [in,out] pointer to the number of frequencies.
                                                            ///< If count is zero, then the driver will update the value with the total
                                                            ///< number of frequencies available.
                                                            ///< If count is non-zero, then driver will only retrieve that number of frequencies.
                                                            ///< If count is larger than the number of frequencies available, then the
                                                            ///< driver will update the value with the correct number of frequencies available.
            double* phFrequency = nullptr                   ///< [in,out][optional][range(0, *pCount)] array of frequencies in units of
                                                            ///< MHz and sorted from slowest to fastest
            );

        ///////////////////////////////////////////////////////////////////////////////
        /// @brief Get current frequency limits
        /// 
        /// @details
        ///     - The application may call this function from simultaneous threads.
        ///     - The implementation of this function should be lock-free.
        /// @throws result_t
        void __zecall
        GetRange(
            freq_range_t* pLimits                           ///< [in,out] The range between which the hardware can operate for the
                                                            ///< specified domain.
            );

        ///////////////////////////////////////////////////////////////////////////////
        /// @brief Set frequency range between which the hardware can operate.
        /// 
        /// @details
        ///     - The application may call this function from simultaneous threads.
        ///     - The implementation of this function should be lock-free.
        /// @throws result_t
        void __zecall
        SetRange(
            const freq_range_t* pLimits                     ///< [in] The limits between which the hardware can operate for the
                                                            ///< specified domain.
            );

        ///////////////////////////////////////////////////////////////////////////////
        /// @brief Get current frequency state - frequency request, actual frequency, TDP
        ///        limits
        /// 
        /// @details
        ///     - The application may call this function from simultaneous threads.
        ///     - The implementation of this function should be lock-free.
        /// @throws result_t
        void __zecall
        GetState(
            freq_state_t* pState                            ///< [in,out] Frequency state for the specified domain.
            );

        ///////////////////////////////////////////////////////////////////////////////
        /// @brief Get frequency throttle time
        /// 
        /// @details
        ///     - The application may call this function from simultaneous threads.
        ///     - The implementation of this function should be lock-free.
        /// @throws result_t
        void __zecall
        GetThrottleTime(
            freq_throttle_time_t* pThrottleTime             ///< [in,out] Will contain a snapshot of the throttle time counters for the
                                                            ///< specified domain.
            );

        ///////////////////////////////////////////////////////////////////////////////
        /// @brief Get the overclocking capabilities.
        /// 
        /// @details
        ///     - The application may call this function from simultaneous threads.
        ///     - The implementation of this function should be lock-free.
        /// @throws result_t
        void __zecall
        OcGetCapabilities(
            oc_capabilities_t* pOcCapabilities              ///< [in,out] Pointer to the capabilities structure
                                                            ///< ::zes_oc_capabilities_t.
            );

        ///////////////////////////////////////////////////////////////////////////////
        /// @brief Get the current overclocking configuration.
        /// 
        /// @details
        ///     - The application may call this function from simultaneous threads.
        ///     - The implementation of this function should be lock-free.
        /// @throws result_t
        void __zecall
        OcGetConfig(
            oc_config_t* pOcConfiguration                   ///< [in,out] Pointer to the configuration structure ::zes_oc_config_t.
            );

        ///////////////////////////////////////////////////////////////////////////////
        /// @brief Change the overclocking configuration.
        /// 
        /// @details
        ///     - If ::zes_oc_config_t.mode is set to ::ZES_OC_MODE_OFF, overclocking
        ///       will be turned off and the hardware returned to run with factory
        ///       voltages/frequencies. Call ::zesFrequencyOcSetIccMax() and
        ///       ::zesFrequencyOcSetTjMax() separately with 0.0 to return those
        ///       settings to factory defaults.
        ///     - The application may call this function from simultaneous threads.
        ///     - The implementation of this function should be lock-free.
        /// @throws result_t
        void __zecall
        OcSetConfig(
            oc_config_t* pOcConfiguration,                  ///< [in] Pointer to the configuration structure ::zes_oc_config_t.
            ze::bool_t* pDeviceRestart                      ///< [in,out] This will be set to true if the device needs to be restarted
                                                            ///< in order to enable the new overclock settings.
            );

        ///////////////////////////////////////////////////////////////////////////////
        /// @brief Get the maximum current limit setting.
        /// 
        /// @details
        ///     - The application may call this function from simultaneous threads.
        ///     - The implementation of this function should be lock-free.
        /// @throws result_t
        void __zecall
        OcGetIccMax(
            double* pOcIccMax                               ///< [in,out] Will contain the maximum current limit in Amperes on
                                                            ///< successful return.
            );

        ///////////////////////////////////////////////////////////////////////////////
        /// @brief Change the maximum current limit setting.
        /// 
        /// @details
        ///     - Setting ocIccMax to 0.0 will return the value to the factory default.
        ///     - The application may call this function from simultaneous threads.
        ///     - The implementation of this function should be lock-free.
        /// @throws result_t
        void __zecall
        OcSetIccMax(
            double ocIccMax                                 ///< [in] The new maximum current limit in Amperes.
            );

        ///////////////////////////////////////////////////////////////////////////////
        /// @brief Get the maximum temperature limit setting.
        /// 
        /// @details
        ///     - The application may call this function from simultaneous threads.
        ///     - The implementation of this function should be lock-free.
        /// @throws result_t
        void __zecall
        OcGetTjMax(
            double* pOcTjMax                                ///< [in,out] Will contain the maximum temperature limit in degrees Celsius
                                                            ///< on successful return.
            );

        ///////////////////////////////////////////////////////////////////////////////
        /// @brief Change the maximum temperature limit setting.
        /// 
        /// @details
        ///     - Setting ocTjMax to 0.0 will return the value to the factory default.
        ///     - The application may call this function from simultaneous threads.
        ///     - The implementation of this function should be lock-free.
        /// @throws result_t
        void __zecall
        OcSetTjMax(
            double ocTjMax                                  ///< [in] The new maximum temperature limit in degrees Celsius.
            );

    };

} // namespace zes

namespace zes
{
    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Converts Frequency::freq_properties_t to std::string
    std::string to_string( const Frequency::freq_properties_t val );

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Converts Frequency::freq_range_t to std::string
    std::string to_string( const Frequency::freq_range_t val );

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Converts Frequency::freq_throttle_reasons_t to std::string
    std::string to_string( const Frequency::freq_throttle_reasons_t val );

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Converts Frequency::freq_state_t to std::string
    std::string to_string( const Frequency::freq_state_t val );

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Converts Frequency::freq_throttle_time_t to std::string
    std::string to_string( const Frequency::freq_throttle_time_t val );

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Converts Frequency::oc_mode_t to std::string
    std::string to_string( const Frequency::oc_mode_t val );

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Converts Frequency::oc_capabilities_t to std::string
    std::string to_string( const Frequency::oc_capabilities_t val );

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Converts Frequency::oc_config_t to std::string
    std::string to_string( const Frequency::oc_config_t val );

} // namespace zes
#pragma endregion
#pragma region led
namespace zes
{
    ///////////////////////////////////////////////////////////////////////////////
    /// @brief C++ wrapper for a Sysman device LED
    class Led
    {
    public:
        ///////////////////////////////////////////////////////////////////////////////
        /// @brief LED properties
        struct properties_t
        {
            ze::bool_t onSubdevice;                         ///< [out] True if the resource is located on a sub-device; false means
                                                            ///< that the resource is on the device of the calling Sysman handle
            uint32_t subdeviceId;                           ///< [out] If onSubdevice is true, this gives the ID of the sub-device
            ze::bool_t canControl;                          ///< [out] Indicates if software can control the LED assuming the user has
                                                            ///< permissions
            ze::bool_t haveRGB;                             ///< [out] Indicates if the LED is RGB capable

        };

        ///////////////////////////////////////////////////////////////////////////////
        /// @brief LED state
        struct state_t
        {
            ze::bool_t isOn;                                ///< [in,out] Indicates if the LED is on or off
            uint8_t red;                                    ///< [in,out][range(0, 255)] The LED red value
            uint8_t green;                                  ///< [in,out][range(0, 255)] The LED green value
            uint8_t blue;                                   ///< [in,out][range(0, 255)] The LED blue value

        };


    protected:
        ///////////////////////////////////////////////////////////////////////////////
        led_handle_t m_handle = nullptr;                ///< [in] handle of Sysman object
        Device* m_pDevice;                              ///< [in] pointer to owner object

    public:
        ///////////////////////////////////////////////////////////////////////////////
        Led( void ) = delete;
        Led( 
            led_handle_t handle,                            ///< [in] handle of Sysman object
            Device* pDevice                                 ///< [in] pointer to owner object
            );

        ~Led( void ) = default;

        Led( Led const& other ) = delete;
        void operator=( Led const& other ) = delete;

        Led( Led&& other ) = delete;
        void operator=( Led&& other ) = delete;

        ///////////////////////////////////////////////////////////////////////////////
        auto getHandle( void ) const { return m_handle; }
        auto getDevice( void ) const { return m_pDevice; }

        ///////////////////////////////////////////////////////////////////////////////
        /// @brief Get LED properties
        /// 
        /// @details
        ///     - The application may call this function from simultaneous threads.
        ///     - The implementation of this function should be lock-free.
        /// @throws result_t
        void __zecall
        GetProperties(
            properties_t* pProperties                       ///< [in,out] Will contain the properties of the LED.
            );

        ///////////////////////////////////////////////////////////////////////////////
        /// @brief Get current state of a LED - on/off, color
        /// 
        /// @details
        ///     - The application may call this function from simultaneous threads.
        ///     - The implementation of this function should be lock-free.
        /// @throws result_t
        void __zecall
        GetState(
            state_t* pState                                 ///< [in,out] Will contain the current state of the LED.
            );

        ///////////////////////////////////////////////////////////////////////////////
        /// @brief Set state of a LED - on/off, color
        /// 
        /// @details
        ///     - The application may call this function from simultaneous threads.
        ///     - The implementation of this function should be lock-free.
        /// @throws result_t
        void __zecall
        SetState(
            const state_t* pState                           ///< [in] New state of the LED.
            );

    };

} // namespace zes

namespace zes
{
    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Converts Led::properties_t to std::string
    std::string to_string( const Led::properties_t val );

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Converts Led::state_t to std::string
    std::string to_string( const Led::state_t val );

} // namespace zes
#pragma endregion
#pragma region memory
namespace zes
{
    ///////////////////////////////////////////////////////////////////////////////
    /// @brief C++ wrapper for a Sysman device memory module
    class Memory
    {
    public:
        ///////////////////////////////////////////////////////////////////////////////
        /// @brief Memory module types
        enum class mem_type_t
        {
            HBM = 0,                                        ///< HBM memory
            DDR,                                            ///< DDR memory
            SRAM,                                           ///< SRAM memory
            L1,                                             ///< L1 cache
            L3,                                             ///< L3 cache
            GRF,                                            ///< Execution unit register file
            SLM,                                            ///< Execution unit shared local memory

        };

        ///////////////////////////////////////////////////////////////////////////////
        /// @brief Memory health
        enum class mem_health_t
        {
            OK = 0,                                         ///< All memory channels are healthy
            DEGRADED,                                       ///< Excessive correctable errors have been detected on one or more
                                                            ///< channels. Device should be reset.
            CRITICAL,                                       ///< Operating with reduced memory to cover banks with too many
                                                            ///< uncorrectable errors.
            REPLACE,                                        ///< Device should be replaced due to excessive uncorrectable errors.

        };

        ///////////////////////////////////////////////////////////////////////////////
        /// @brief Memory properties
        struct mem_properties_t
        {
            mem_type_t type;                                ///< [out] The memory type
            ze::bool_t onSubdevice;                         ///< [out] True if this resource is located on a sub-device; false means
                                                            ///< that the resource is on the device of the calling Sysman handle
            uint32_t subdeviceId;                           ///< [out] If onSubdevice is true, this gives the ID of the sub-device
            uint64_t physicalSize;                          ///< [out] Physical memory size in bytes

        };

        ///////////////////////////////////////////////////////////////////////////////
        /// @brief Memory state - health, allocated
        /// 
        /// @details
        ///     - Percent allocation is given by 100 * allocatedSize / maxSize.
        ///     - Percent free is given by 100 * (maxSize - allocatedSize) / maxSize.
        struct mem_state_t
        {
            mem_health_t health;                            ///< [out] Indicates the health of the memory
            uint64_t free;                                  ///< [out] The free memory in bytes
            uint64_t size;                                  ///< [out] The total allocatable memory in bytes (can be less than
                                                            ///< ::zes_mem_properties_t.physicalSize)

        };

        ///////////////////////////////////////////////////////////////////////////////
        /// @brief Memory bandwidth
        /// 
        /// @details
        ///     - Percent bandwidth is calculated by taking two snapshots (s1, s2) and
        ///       using the equation: %bw = 10^6 * ((s2.readCounter - s1.readCounter) +
        ///       (s2.writeCounter - s1.writeCounter)) / (s2.maxBandwidth *
        ///       (s2.timestamp - s1.timestamp))
        struct mem_bandwidth_t
        {
            uint64_t readCounter;                           ///< [out] Total bytes read from memory
            uint64_t writeCounter;                          ///< [out] Total bytes written to memory
            uint64_t maxBandwidth;                          ///< [out] Current maximum bandwidth in units of bytes/sec
            uint64_t timestamp;                             ///< [out] The timestamp when these measurements were sampled.
                                                            ///< No assumption should be made about the absolute value of the timestamp.
                                                            ///< It should only be used to calculate delta time between two snapshots
                                                            ///< of the same structure.
                                                            ///< Never take the delta of this timestamp with the timestamp from a
                                                            ///< different structure.

        };


    protected:
        ///////////////////////////////////////////////////////////////////////////////
        mem_handle_t m_handle = nullptr;                ///< [in] handle of Sysman object
        Device* m_pDevice;                              ///< [in] pointer to owner object

    public:
        ///////////////////////////////////////////////////////////////////////////////
        Memory( void ) = delete;
        Memory( 
            mem_handle_t handle,                            ///< [in] handle of Sysman object
            Device* pDevice                                 ///< [in] pointer to owner object
            );

        ~Memory( void ) = default;

        Memory( Memory const& other ) = delete;
        void operator=( Memory const& other ) = delete;

        Memory( Memory&& other ) = delete;
        void operator=( Memory&& other ) = delete;

        ///////////////////////////////////////////////////////////////////////////////
        auto getHandle( void ) const { return m_handle; }
        auto getDevice( void ) const { return m_pDevice; }

        ///////////////////////////////////////////////////////////////////////////////
        /// @brief Get memory properties
        /// 
        /// @details
        ///     - The application may call this function from simultaneous threads.
        ///     - The implementation of this function should be lock-free.
        /// @throws result_t
        void __zecall
        GetProperties(
            mem_properties_t* pProperties                   ///< [in,out] Will contain memory properties.
            );

        ///////////////////////////////////////////////////////////////////////////////
        /// @brief Get memory state - health, allocated
        /// 
        /// @details
        ///     - The application may call this function from simultaneous threads.
        ///     - The implementation of this function should be lock-free.
        /// @throws result_t
        void __zecall
        GetState(
            mem_state_t* pState                             ///< [in,out] Will contain the current health and allocated memory.
            );

        ///////////////////////////////////////////////////////////////////////////////
        /// @brief Get memory bandwidth
        /// 
        /// @details
        ///     - The application may call this function from simultaneous threads.
        ///     - The implementation of this function should be lock-free.
        /// @throws result_t
        void __zecall
        GetBandwidth(
            mem_bandwidth_t* pBandwidth                     ///< [in,out] Will contain the current health, free memory, total memory
                                                            ///< size.
            );

    };

} // namespace zes

namespace zes
{
    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Converts Memory::mem_type_t to std::string
    std::string to_string( const Memory::mem_type_t val );

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Converts Memory::mem_health_t to std::string
    std::string to_string( const Memory::mem_health_t val );

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Converts Memory::mem_properties_t to std::string
    std::string to_string( const Memory::mem_properties_t val );

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Converts Memory::mem_state_t to std::string
    std::string to_string( const Memory::mem_state_t val );

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Converts Memory::mem_bandwidth_t to std::string
    std::string to_string( const Memory::mem_bandwidth_t val );

} // namespace zes
#pragma endregion
#pragma region performance
namespace zes
{
    ///////////////////////////////////////////////////////////////////////////////
    /// @brief C++ wrapper for a Sysman device performance factor
    class PerformanceFactor
    {
    public:
        ///////////////////////////////////////////////////////////////////////////////
        /// @brief Static information about a Performance Factor domain
        struct perf_properties_t
        {
            ze::bool_t onSubdevice;                         ///< [out] True if this Performance Factor affects accelerators located on
                                                            ///< a sub-device
            uint32_t subdeviceId;                           ///< [out] If onSubdevice is true, this gives the ID of the sub-device
            uint64_t engines;                               ///< [out] Bitfield of accelerator engines that are affected by this
                                                            ///< Performance Factor (bitfield of 1<<::zes_engine_type_t).

        };


    protected:
        ///////////////////////////////////////////////////////////////////////////////
        perf_handle_t m_handle = nullptr;               ///< [in] handle of Sysman object
        Device* m_pDevice;                              ///< [in] pointer to owner object

    public:
        ///////////////////////////////////////////////////////////////////////////////
        PerformanceFactor( void ) = delete;
        PerformanceFactor( 
            perf_handle_t handle,                           ///< [in] handle of Sysman object
            Device* pDevice                                 ///< [in] pointer to owner object
            );

        ~PerformanceFactor( void ) = default;

        PerformanceFactor( PerformanceFactor const& other ) = delete;
        void operator=( PerformanceFactor const& other ) = delete;

        PerformanceFactor( PerformanceFactor&& other ) = delete;
        void operator=( PerformanceFactor&& other ) = delete;

        ///////////////////////////////////////////////////////////////////////////////
        auto getHandle( void ) const { return m_handle; }
        auto getDevice( void ) const { return m_pDevice; }

        ///////////////////////////////////////////////////////////////////////////////
        /// @brief Get properties about a Performance Factor domain
        /// 
        /// @details
        ///     - The application may call this function from simultaneous threads.
        ///     - The implementation of this function should be lock-free.
        /// @throws result_t
        void __zecall
        GetProperties(
            perf_properties_t* pProperties                  ///< [in,out] Will contain information about the specified Performance
                                                            ///< Factor domain.
            );

        ///////////////////////////////////////////////////////////////////////////////
        /// @brief Get current Performance Factor for a given domain
        /// 
        /// @details
        ///     - The application may call this function from simultaneous threads.
        ///     - The implementation of this function should be lock-free.
        /// @throws result_t
        void __zecall
        GetConfig(
            double* pFactor                                 ///< [in,out] Will contain the actual Performance Factor being used by the
                                                            ///< hardware (may not be the same as the requested Performance Factor).
            );

        ///////////////////////////////////////////////////////////////////////////////
        /// @brief Change the performance factor for a domain
        /// 
        /// @details
        ///     - The Performance Factor is a number between 0 and 100.
        ///     - A Performance Factor is a hint to the hardware. Depending on the
        ///       hardware, the request may not be granted. Follow up this function with
        ///       a call to ::zesPerformanceFactorGetConfig() to determine the actual
        ///       factor being used by the hardware.
        ///     - The application may call this function from simultaneous threads.
        ///     - The implementation of this function should be lock-free.
        /// @throws result_t
        void __zecall
        SetConfig(
            double factor                                   ///< [in] The new Performance Factor.
            );

    };

} // namespace zes

namespace zes
{
    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Converts PerformanceFactor::perf_properties_t to std::string
    std::string to_string( const PerformanceFactor::perf_properties_t val );

} // namespace zes
#pragma endregion
#pragma region power
namespace zes
{
    ///////////////////////////////////////////////////////////////////////////////
    /// @brief C++ wrapper for a Sysman device power domain
    class Power
    {
    public:
        ///////////////////////////////////////////////////////////////////////////////
        /// @brief Properties related to device power settings
        struct properties_t
        {
            ze::bool_t onSubdevice;                         ///< [out] True if this resource is located on a sub-device; false means
                                                            ///< that the resource is on the device of the calling Sysman handle
            uint32_t subdeviceId;                           ///< [out] If onSubdevice is true, this gives the ID of the sub-device
            ze::bool_t canControl;                          ///< [out] Software can change the power limits of this domain assuming the
                                                            ///< user has permissions.
            ze::bool_t isEnergyThresholdSupported;          ///< [out] Indicates if this power domain supports the energy threshold
                                                            ///< event (::ZES_EVENT_TYPE_ENERGY_THRESHOLD_CROSSED).
            uint32_t defaultLimit;                          ///< [out] The factory default TDP power limit of the part in milliwatts.
            uint32_t minLimit;                              ///< [out] The minimum power limit in milliwatts that can be requested.
            uint32_t maxLimit;                              ///< [out] The maximum power limit in milliwatts that can be requested.

        };

        ///////////////////////////////////////////////////////////////////////////////
        /// @brief Energy counter snapshot
        /// 
        /// @details
        ///     - Average power is calculated by taking two snapshots (s1, s2) and using
        ///       the equation: PowerWatts = (s2.energy - s1.energy) / (s2.timestamp -
        ///       s1.timestamp)
        struct energy_counter_t
        {
            uint64_t energy;                                ///< [out] The monotonic energy counter in microjoules.
            uint64_t timestamp;                             ///< [out] Microsecond timestamp when energy was captured.
                                                            ///< No assumption should be made about the absolute value of the timestamp.
                                                            ///< It should only be used to calculate delta time between two snapshots
                                                            ///< of the same structure.
                                                            ///< Never take the delta of this timestamp with the timestamp from a
                                                            ///< different structure.

        };

        ///////////////////////////////////////////////////////////////////////////////
        /// @brief Sustained power limits
        /// 
        /// @details
        ///     - The power controller (Punit) will throttle the operating frequency if
        ///       the power averaged over a window (typically seconds) exceeds this
        ///       limit.
        struct sustained_limit_t
        {
            ze::bool_t enabled;                             ///< [in,out] indicates if the limit is enabled (true) or ignored (false)
            uint32_t power;                                 ///< [in,out] power limit in milliwatts
            uint32_t interval;                              ///< [in,out] power averaging window (Tau) in milliseconds

        };

        ///////////////////////////////////////////////////////////////////////////////
        /// @brief Burst power limit
        /// 
        /// @details
        ///     - The power controller (Punit) will throttle the operating frequency of
        ///       the device if the power averaged over a few milliseconds exceeds a
        ///       limit known as PL2. Typically PL2 > PL1 so that it permits the
        ///       frequency to burst higher for short periods than would be otherwise
        ///       permitted by PL1.
        struct burst_limit_t
        {
            ze::bool_t enabled;                             ///< [in,out] indicates if the limit is enabled (true) or ignored (false)
            uint32_t power;                                 ///< [in,out] power limit in milliwatts

        };

        ///////////////////////////////////////////////////////////////////////////////
        /// @brief Peak power limit
        /// 
        /// @details
        ///     - The power controller (Punit) will preemptively throttle the operating
        ///       frequency of the device when the instantaneous power exceeds this
        ///       limit. The limit is known as PL4. It expresses the maximum power that
        ///       can be drawn from the power supply.
        ///     - If this power limit is removed or set too high, the power supply will
        ///       generate an interrupt when it detects an overcurrent condition and the
        ///       power controller will throttle the device frequencies down to min. It
        ///       is thus better to tune the PL4 value in order to avoid such
        ///       excursions.
        struct peak_limit_t
        {
            uint32_t powerAC;                               ///< [in,out] power limit in milliwatts for the AC power source.
            uint32_t powerDC;                               ///< [in,out] power limit in milliwatts for the DC power source. This is
                                                            ///< ignored if the product does not have a battery.

        };

        ///////////////////////////////////////////////////////////////////////////////
        /// @brief Energy threshold
        /// 
        /// @details
        ///     - .
        struct energy_threshold_t
        {
            ze::bool_t enable;                              ///< [in,out] Indicates if the energy threshold is enabled.
            double threshold;                               ///< [in,out] The energy threshold in Joules. Will be 0.0 if no threshold
                                                            ///< has been set.
            uint32_t processId;                             ///< [in,out] The host process ID that set the energy threshold. Will be
                                                            ///< 0xFFFFFFFF if no threshold has been set.

        };


    protected:
        ///////////////////////////////////////////////////////////////////////////////
        pwr_handle_t m_handle = nullptr;                ///< [in] handle of Sysman object
        Device* m_pDevice;                              ///< [in] pointer to owner object

    public:
        ///////////////////////////////////////////////////////////////////////////////
        Power( void ) = delete;
        Power( 
            pwr_handle_t handle,                            ///< [in] handle of Sysman object
            Device* pDevice                                 ///< [in] pointer to owner object
            );

        ~Power( void ) = default;

        Power( Power const& other ) = delete;
        void operator=( Power const& other ) = delete;

        Power( Power&& other ) = delete;
        void operator=( Power&& other ) = delete;

        ///////////////////////////////////////////////////////////////////////////////
        auto getHandle( void ) const { return m_handle; }
        auto getDevice( void ) const { return m_pDevice; }

        ///////////////////////////////////////////////////////////////////////////////
        /// @brief Get properties related to a power domain
        /// 
        /// @details
        ///     - The application may call this function from simultaneous threads.
        ///     - The implementation of this function should be lock-free.
        /// @throws result_t
        void __zecall
        GetProperties(
            properties_t* pProperties                       ///< [in,out] Structure that will contain property data.
            );

        ///////////////////////////////////////////////////////////////////////////////
        /// @brief Get energy counter
        /// 
        /// @details
        ///     - The application may call this function from simultaneous threads.
        ///     - The implementation of this function should be lock-free.
        /// @throws result_t
        void __zecall
        GetEnergyCounter(
            energy_counter_t* pEnergy                       ///< [in,out] Will contain the latest snapshot of the energy counter and
                                                            ///< timestamp when the last counter value was measured.
            );

        ///////////////////////////////////////////////////////////////////////////////
        /// @brief Get power limits
        /// 
        /// @details
        ///     - The application may call this function from simultaneous threads.
        ///     - The implementation of this function should be lock-free.
        /// @throws result_t
        void __zecall
        GetLimits(
            sustained_limit_t* pSustained = nullptr,        ///< [in,out][optional] The sustained power limit.
            burst_limit_t* pBurst = nullptr,                ///< [in,out][optional] The burst power limit.
            peak_limit_t* pPeak = nullptr                   ///< [in,out][optional] The peak power limit.
            );

        ///////////////////////////////////////////////////////////////////////////////
        /// @brief Set power limits
        /// 
        /// @details
        ///     - The application may call this function from simultaneous threads.
        ///     - The implementation of this function should be lock-free.
        /// @throws result_t
        void __zecall
        SetLimits(
            const sustained_limit_t* pSustained = nullptr,  ///< [in][optional] The sustained power limit.
            const burst_limit_t* pBurst = nullptr,          ///< [in][optional] The burst power limit.
            const peak_limit_t* pPeak = nullptr             ///< [in][optional] The peak power limit.
            );

        ///////////////////////////////////////////////////////////////////////////////
        /// @brief Get energy threshold
        /// 
        /// @details
        ///     - The application may call this function from simultaneous threads.
        ///     - The implementation of this function should be lock-free.
        /// @throws result_t
        void __zecall
        GetEnergyThreshold(
            energy_threshold_t* pThreshold                  ///< [in,out] Returns information about the energy threshold setting -
                                                            ///< enabled/energy threshold/process ID.
            );

        ///////////////////////////////////////////////////////////////////////////////
        /// @brief Set energy threshold
        /// 
        /// @details
        ///     - An event ::ZES_EVENT_TYPE_ENERGY_THRESHOLD_CROSSED will be generated
        ///       when the delta energy consumed starting from this call exceeds the
        ///       specified threshold. Use the function ::zesEventSetConfig() to start
        ///       receiving the event.
        ///     - Only one running process can control the energy threshold at a given
        ///       time. If another process attempts to change the energy threshold, the
        ///       error ::ZE_RESULT_ERROR_NOT_AVAILABLE will be returned. The function
        ///       ::zesPowerGetEnergyThreshold() to determine the process ID currently
        ///       controlling this setting.
        ///     - Calling this function will remove any pending energy thresholds and
        ///       start counting from the time of this call.
        ///     - Once the energy threshold has been reached and the event generated,
        ///       the threshold is automatically removed. It is up to the application to
        ///       request a new threshold.
        ///     - The application may call this function from simultaneous threads.
        ///     - The implementation of this function should be lock-free.
        /// @throws result_t
        void __zecall
        SetEnergyThreshold(
            double threshold                                ///< [in] The energy threshold to be set in joules.
            );

    };

} // namespace zes

namespace zes
{
    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Converts Power::properties_t to std::string
    std::string to_string( const Power::properties_t val );

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Converts Power::energy_counter_t to std::string
    std::string to_string( const Power::energy_counter_t val );

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Converts Power::sustained_limit_t to std::string
    std::string to_string( const Power::sustained_limit_t val );

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Converts Power::burst_limit_t to std::string
    std::string to_string( const Power::burst_limit_t val );

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Converts Power::peak_limit_t to std::string
    std::string to_string( const Power::peak_limit_t val );

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Converts Power::energy_threshold_t to std::string
    std::string to_string( const Power::energy_threshold_t val );

} // namespace zes
#pragma endregion
#pragma region psu
namespace zes
{
    ///////////////////////////////////////////////////////////////////////////////
    /// @brief C++ wrapper for a Sysman device power supply
    class Psu
    {
    public:
        ///////////////////////////////////////////////////////////////////////////////
        /// @brief PSU voltage status
        enum class voltage_status_t
        {
            NORMAL = 0,                                     ///< No unusual voltages have been detected
            OVER,                                           ///< Over-voltage has occurred
            UNDER,                                          ///< Under-voltage has occurred

        };

        ///////////////////////////////////////////////////////////////////////////////
        /// @brief Static properties of the power supply
        struct properties_t
        {
            ze::bool_t onSubdevice;                         ///< [out] True if the resource is located on a sub-device; false means
                                                            ///< that the resource is on the device of the calling Sysman handle
            uint32_t subdeviceId;                           ///< [out] If onSubdevice is true, this gives the ID of the sub-device
            ze::bool_t haveFan;                             ///< [out] True if the power supply has a fan
            uint32_t ampLimit;                              ///< [out] The maximum electrical current in amperes that can be drawn

        };

        ///////////////////////////////////////////////////////////////////////////////
        /// @brief Dynamic state of the power supply
        struct state_t
        {
            voltage_status_t voltStatus;                    ///< [out] The current PSU voltage status
            ze::bool_t fanFailed;                           ///< [out] Indicates if the fan has failed
            uint32_t temperature;                           ///< [out] Read the current heatsink temperature in degrees Celsius.
            uint32_t current;                               ///< [out] The amps being drawn in amperes

        };


    protected:
        ///////////////////////////////////////////////////////////////////////////////
        psu_handle_t m_handle = nullptr;                ///< [in] handle of Sysman object
        Device* m_pDevice;                              ///< [in] pointer to owner object

    public:
        ///////////////////////////////////////////////////////////////////////////////
        Psu( void ) = delete;
        Psu( 
            psu_handle_t handle,                            ///< [in] handle of Sysman object
            Device* pDevice                                 ///< [in] pointer to owner object
            );

        ~Psu( void ) = default;

        Psu( Psu const& other ) = delete;
        void operator=( Psu const& other ) = delete;

        Psu( Psu&& other ) = delete;
        void operator=( Psu&& other ) = delete;

        ///////////////////////////////////////////////////////////////////////////////
        auto getHandle( void ) const { return m_handle; }
        auto getDevice( void ) const { return m_pDevice; }

        ///////////////////////////////////////////////////////////////////////////////
        /// @brief Get power supply properties
        /// 
        /// @details
        ///     - The application may call this function from simultaneous threads.
        ///     - The implementation of this function should be lock-free.
        /// @throws result_t
        void __zecall
        GetProperties(
            properties_t* pProperties                       ///< [in,out] Will contain the properties of the power supply.
            );

        ///////////////////////////////////////////////////////////////////////////////
        /// @brief Get current power supply state
        /// 
        /// @details
        ///     - The application may call this function from simultaneous threads.
        ///     - The implementation of this function should be lock-free.
        /// @throws result_t
        void __zecall
        GetState(
            state_t* pState                                 ///< [in,out] Will contain the current state of the power supply.
            );

    };

} // namespace zes

namespace zes
{
    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Converts Psu::voltage_status_t to std::string
    std::string to_string( const Psu::voltage_status_t val );

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Converts Psu::properties_t to std::string
    std::string to_string( const Psu::properties_t val );

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Converts Psu::state_t to std::string
    std::string to_string( const Psu::state_t val );

} // namespace zes
#pragma endregion
#pragma region ras
namespace zes
{
    ///////////////////////////////////////////////////////////////////////////////
    /// @brief C++ wrapper for a Sysman device RAS error set
    class Ras
    {
    public:
        ///////////////////////////////////////////////////////////////////////////////
        /// @brief RAS error type
        enum class error_type_t
        {
            CORRECTABLE = 0,                                ///< Errors were corrected by hardware
            UNCORRECTABLE,                                  ///< Error were not corrected

        };

        ///////////////////////////////////////////////////////////////////////////////
        /// @brief RAS error categories
        enum class error_cat_t
        {
            RESET = 0,                                      ///< The number of device resets that have taken place
            PROGRAMMING_ERRORS,                             ///< The number of hardware exceptions generated by the way workloads have
                                                            ///< programmed the hardware
            DRIVER_ERRORS,                                  ///< The number of low level driver communication errors have occurred
            COMPUTE_ERRORS,                                 ///< The number of errors that have occurred in the compute accelerator
                                                            ///< hardware
            NON_COMPUTE_ERRORS,                             ///< The number of errors that have occurred in the fixed-function
                                                            ///< accelerator hardware
            CACHE_ERRORS,                                   ///< The number of errors that have occurred in caches (L1/L3/register
                                                            ///< file/shared local memory/sampler)
            DISPLAY_ERRORS,                                 ///< The number of errors that have occurred in the display
            MAX,                                            ///< The number of categories

        };

        ///////////////////////////////////////////////////////////////////////////////
        /// @brief RAS properties
        struct properties_t
        {
            error_type_t type;                              ///< [out] The type of RAS error
            ze::bool_t onSubdevice;                         ///< [out] True if the resource is located on a sub-device; false means
                                                            ///< that the resource is on the device of the calling Sysman handle
            uint32_t subdeviceId;                           ///< [out] If onSubdevice is true, this gives the ID of the sub-device

        };

        ///////////////////////////////////////////////////////////////////////////////
        /// @brief RAS error details
        struct state_t
        {
            uint64_t category[static_cast<int>(error_cat_t::MAX)];  ///< [in][out] Breakdown of error by category

        };

        ///////////////////////////////////////////////////////////////////////////////
        /// @brief RAS error configuration - thresholds used for triggering RAS events
        ///        (::ZES_EVENT_TYPE_RAS_CORRECTABLE_ERRORS,
        ///        ::ZES_EVENT_TYPE_RAS_UNCORRECTABLE_ERRORS)
        /// 
        /// @details
        ///     - The driver maintains a total counter which is updated every time a
        ///       hardware block covered by the corresponding RAS error set notifies
        ///       that an error has occurred. When this total count goes above the
        ///       totalThreshold specified below, a RAS event is triggered.
        ///     - The driver also maintains a counter for each category of RAS error
        ///       (see ::zes_ras_state_t for a breakdown). Each time a hardware block of
        ///       that category notifies that an error has occurred, that corresponding
        ///       category counter is updated. When it goes above the threshold
        ///       specified in detailedThresholds, a RAS event is triggered.
        struct config_t
        {
            uint64_t totalThreshold;                        ///< [in,out] If the total RAS errors exceeds this threshold, the event
                                                            ///< will be triggered. A value of 0ULL disables triggering the event based
                                                            ///< on the total counter.
            state_t detailedThresholds;                     ///< [in,out] If the RAS errors for each category exceed the threshold for
                                                            ///< that category, the event will be triggered. A value of 0ULL will
                                                            ///< disable an event being triggered for that category.
            uint32_t processId;                             ///< [out] Host processId that set this configuration (ignored when setting
                                                            ///< the configuration).

        };


    protected:
        ///////////////////////////////////////////////////////////////////////////////
        ras_handle_t m_handle = nullptr;                ///< [in] handle of Sysman object
        Device* m_pDevice;                              ///< [in] pointer to owner object

    public:
        ///////////////////////////////////////////////////////////////////////////////
        Ras( void ) = delete;
        Ras( 
            ras_handle_t handle,                            ///< [in] handle of Sysman object
            Device* pDevice                                 ///< [in] pointer to owner object
            );

        ~Ras( void ) = default;

        Ras( Ras const& other ) = delete;
        void operator=( Ras const& other ) = delete;

        Ras( Ras&& other ) = delete;
        void operator=( Ras&& other ) = delete;

        ///////////////////////////////////////////////////////////////////////////////
        auto getHandle( void ) const { return m_handle; }
        auto getDevice( void ) const { return m_pDevice; }

        ///////////////////////////////////////////////////////////////////////////////
        /// @brief Get RAS properties of a given RAS error set - this enables discovery
        ///        of the type of RAS error set (correctable/uncorrectable) and if
        ///        located on a sub-device
        /// 
        /// @details
        ///     - The application may call this function from simultaneous threads.
        ///     - The implementation of this function should be lock-free.
        /// @throws result_t
        void __zecall
        GetProperties(
            properties_t* pProperties                       ///< [in,out] Structure describing RAS properties
            );

        ///////////////////////////////////////////////////////////////////////////////
        /// @brief Get RAS error thresholds that control when RAS events are generated
        /// 
        /// @details
        ///     - The driver maintains counters for all RAS error sets and error
        ///       categories. Events are generated when errors occur. The configuration
        ///       enables setting thresholds to limit when events are sent.
        ///     - When a particular RAS correctable error counter exceeds the configured
        ///       threshold, the event ::ZES_EVENT_TYPE_RAS_CORRECTABLE_ERRORS will be
        ///       triggered.
        ///     - When a particular RAS uncorrectable error counter exceeds the
        ///       configured threshold, the event
        ///       ::ZES_EVENT_TYPE_RAS_UNCORRECTABLE_ERRORS will be triggered.
        ///     - The application may call this function from simultaneous threads.
        ///     - The implementation of this function should be lock-free.
        /// @throws result_t
        void __zecall
        GetConfig(
            config_t* pConfig                               ///< [in,out] Will be populed with the current RAS configuration -
                                                            ///< thresholds used to trigger events
            );

        ///////////////////////////////////////////////////////////////////////////////
        /// @brief Set RAS error thresholds that control when RAS events are generated
        /// 
        /// @details
        ///     - The driver maintains counters for all RAS error sets and error
        ///       categories. Events are generated when errors occur. The configuration
        ///       enables setting thresholds to limit when events are sent.
        ///     - When a particular RAS correctable error counter exceeds the specified
        ///       threshold, the event ::ZES_EVENT_TYPE_RAS_CORRECTABLE_ERRORS will be
        ///       generated.
        ///     - When a particular RAS uncorrectable error counter exceeds the
        ///       specified threshold, the event
        ///       ::ZES_EVENT_TYPE_RAS_UNCORRECTABLE_ERRORS will be generated.
        ///     - Call ::zesRasGetState() and set the clear flag to true to restart
        ///       event generation once counters have exceeded thresholds.
        ///     - The application may call this function from simultaneous threads.
        ///     - The implementation of this function should be lock-free.
        /// @throws result_t
        void __zecall
        SetConfig(
            const config_t* pConfig                         ///< [in] Change the RAS configuration - thresholds used to trigger events
            );

        ///////////////////////////////////////////////////////////////////////////////
        /// @brief Get the current value of RAS error counters for a particular error set
        /// 
        /// @details
        ///     - Clearing errors will affect other threads/applications - the counter
        ///       values will start from zero.
        ///     - Clearing errors requires write permissions.
        ///     - The application may call this function from simultaneous threads.
        ///     - The implementation of this function should be lock-free.
        /// @throws result_t
        void __zecall
        GetState(
            ze::bool_t clear,                               ///< [in] Set to 1 to clear the counters of this type
            state_t* pState                                 ///< [in,out] Breakdown of where errors have occurred
            );

    };

} // namespace zes

namespace zes
{
    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Converts Ras::error_type_t to std::string
    std::string to_string( const Ras::error_type_t val );

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Converts Ras::error_cat_t to std::string
    std::string to_string( const Ras::error_cat_t val );

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Converts Ras::properties_t to std::string
    std::string to_string( const Ras::properties_t val );

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Converts Ras::state_t to std::string
    std::string to_string( const Ras::state_t val );

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Converts Ras::config_t to std::string
    std::string to_string( const Ras::config_t val );

} // namespace zes
#pragma endregion
#pragma region scheduler
///////////////////////////////////////////////////////////////////////////////
#ifndef ZES_SCHED_WATCHDOG_DISABLE
/// @brief Disable forward progress guard timeout.
#define ZES_SCHED_WATCHDOG_DISABLE  (~(0ULL))
#endif // ZES_SCHED_WATCHDOG_DISABLE

namespace zes
{
    ///////////////////////////////////////////////////////////////////////////////
    /// @brief C++ wrapper for a Sysman device scheduler queue
    class Scheduler
    {
    public:
        ///////////////////////////////////////////////////////////////////////////////
        /// @brief Properties related to scheduler component
        struct sched_properties_t
        {
            ze::bool_t onSubdevice;                         ///< [out] True if this resource is located on a sub-device; false means
                                                            ///< that the resource is on the device of the calling Sysman handle
            uint32_t subdeviceId;                           ///< [out] If onSubdevice is true, this gives the ID of the sub-device
            ze::bool_t canControl;                          ///< [out] Software can change the scheduler component configuration
                                                            ///< assuming the user has permissions.
            uint64_t engines;                               ///< [out] Bitfield of accelerator engines that are controlled by this
                                                            ///< scheduler component (bitfield of 1<<::zes_engine_type_t).
            uint32_t supportedModes;                        ///< [out] Bitfield of scheduler modes that can be configured for this
                                                            ///< scheduler component (bitfield of 1<<::zes_sched_mode_t).

        };


    protected:
        ///////////////////////////////////////////////////////////////////////////////
        sched_handle_t m_handle = nullptr;              ///< [in] handle of Sysman object
        Device* m_pDevice;                              ///< [in] pointer to owner object

    public:
        ///////////////////////////////////////////////////////////////////////////////
        Scheduler( void ) = delete;
        Scheduler( 
            sched_handle_t handle,                          ///< [in] handle of Sysman object
            Device* pDevice                                 ///< [in] pointer to owner object
            );

        ~Scheduler( void ) = default;

        Scheduler( Scheduler const& other ) = delete;
        void operator=( Scheduler const& other ) = delete;

        Scheduler( Scheduler&& other ) = delete;
        void operator=( Scheduler&& other ) = delete;

        ///////////////////////////////////////////////////////////////////////////////
        auto getHandle( void ) const { return m_handle; }
        auto getDevice( void ) const { return m_pDevice; }

        ///////////////////////////////////////////////////////////////////////////////
        /// @brief Get properties related to a scheduler component
        /// 
        /// @details
        ///     - The application may call this function from simultaneous threads.
        ///     - The implementation of this function should be lock-free.
        /// @throws result_t
        void __zecall
        GetProperties(
            sched_properties_t* pProperties                 ///< [in,out] Structure that will contain property data.
            );

        ///////////////////////////////////////////////////////////////////////////////
        /// @brief Get current scheduling mode in effect on a scheduler component.
        /// 
        /// @details
        ///     - The application may call this function from simultaneous threads.
        ///     - The implementation of this function should be lock-free.
        /// @throws result_t
        void __zecall
        GetCurrentMode(
            Device::sched_mode_t* pMode                     ///< [in,out] Will contain the current scheduler mode.
            );

        ///////////////////////////////////////////////////////////////////////////////
        /// @brief Get scheduler config for mode ::ZES_SCHED_MODE_TIMEOUT
        /// 
        /// @details
        ///     - The application may call this function from simultaneous threads.
        ///     - The implementation of this function should be lock-free.
        /// @throws result_t
        void __zecall
        GetTimeoutModeProperties(
            ze::bool_t getDefaults,                         ///< [in] If TRUE, the driver will return the system default properties for
                                                            ///< this mode, otherwise it will return the current properties.
            Device::sched_timeout_properties_t* pConfig     ///< [in,out] Will contain the current parameters for this mode.
            );

        ///////////////////////////////////////////////////////////////////////////////
        /// @brief Get scheduler config for mode ::ZES_SCHED_MODE_TIMESLICE
        /// 
        /// @details
        ///     - The application may call this function from simultaneous threads.
        ///     - The implementation of this function should be lock-free.
        /// @throws result_t
        void __zecall
        GetTimesliceModeProperties(
            ze::bool_t getDefaults,                         ///< [in] If TRUE, the driver will return the system default properties for
                                                            ///< this mode, otherwise it will return the current properties.
            Device::sched_timeslice_properties_t* pConfig   ///< [in,out] Will contain the current parameters for this mode.
            );

        ///////////////////////////////////////////////////////////////////////////////
        /// @brief Change scheduler mode to ::ZES_SCHED_MODE_TIMEOUT or update scheduler
        ///        mode parameters if already running in this mode.
        /// 
        /// @details
        ///     - This mode is optimized for multiple applications or contexts
        ///       submitting work to the hardware. When higher priority work arrives,
        ///       the scheduler attempts to pause the current executing work within some
        ///       timeout interval, then submits the other work.
        ///     - The application may call this function from simultaneous threads.
        ///     - The implementation of this function should be lock-free.
        /// @throws result_t
        void __zecall
        SetTimeoutMode(
            Device::sched_timeout_properties_t* pProperties,///< [in] The properties to use when configurating this mode.
            ze::bool_t* pNeedReload                         ///< [in,out] Will be set to TRUE if a device driver reload is needed to
                                                            ///< apply the new scheduler mode.
            );

        ///////////////////////////////////////////////////////////////////////////////
        /// @brief Change scheduler mode to ::ZES_SCHED_MODE_TIMESLICE or update
        ///        scheduler mode parameters if already running in this mode.
        /// 
        /// @details
        ///     - This mode is optimized to provide fair sharing of hardware execution
        ///       time between multiple contexts submitting work to the hardware
        ///       concurrently.
        ///     - The application may call this function from simultaneous threads.
        ///     - The implementation of this function should be lock-free.
        /// @throws result_t
        void __zecall
        SetTimesliceMode(
            Device::sched_timeslice_properties_t* pProperties,  ///< [in] The properties to use when configurating this mode.
            ze::bool_t* pNeedReload                         ///< [in,out] Will be set to TRUE if a device driver reload is needed to
                                                            ///< apply the new scheduler mode.
            );

        ///////////////////////////////////////////////////////////////////////////////
        /// @brief Change scheduler mode to ::ZES_SCHED_MODE_EXCLUSIVE
        /// 
        /// @details
        ///     - This mode is optimized for single application/context use-cases. It
        ///       permits a context to run indefinitely on the hardware without being
        ///       preempted or terminated. All pending work for other contexts must wait
        ///       until the running context completes with no further submitted work.
        ///     - The application may call this function from simultaneous threads.
        ///     - The implementation of this function should be lock-free.
        /// @throws result_t
        void __zecall
        SetExclusiveMode(
            ze::bool_t* pNeedReload                         ///< [in,out] Will be set to TRUE if a device driver reload is needed to
                                                            ///< apply the new scheduler mode.
            );

        ///////////////////////////////////////////////////////////////////////////////
        /// @brief Change scheduler mode to ::ZES_SCHED_MODE_COMPUTE_UNIT_DEBUG
        /// 
        /// @details
        ///     - This mode is optimized for application debug. It ensures that only one
        ///       command queue can execute work on the hardware at a given time. Work
        ///       is permitted to run as long as needed without enforcing any scheduler
        ///       fairness policies.
        ///     - The application may call this function from simultaneous threads.
        ///     - The implementation of this function should be lock-free.
        /// @throws result_t
        void __zecall
        SetComputeUnitDebugMode(
            ze::bool_t* pNeedReload                         ///< [in,out] Will be set to TRUE if a device driver reload is needed to
                                                            ///< apply the new scheduler mode.
            );

    };

} // namespace zes

namespace zes
{
    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Converts Scheduler::sched_properties_t to std::string
    std::string to_string( const Scheduler::sched_properties_t val );

} // namespace zes
#pragma endregion
#pragma region standby
namespace zes
{
    ///////////////////////////////////////////////////////////////////////////////
    /// @brief C++ wrapper for a Sysman standby control
    class Standby
    {
    public:
        ///////////////////////////////////////////////////////////////////////////////
        /// @brief Standby hardware components
        enum class type_t
        {
            GLOBAL = 0,                                     ///< Control the overall standby policy of the device/sub-device

        };

        ///////////////////////////////////////////////////////////////////////////////
        /// @brief Standby promotion modes
        enum class promo_mode_t
        {
            DEFAULT = 0,                                    ///< Best compromise between performance and energy savings.
            NEVER,                                          ///< The device/component will never shutdown. This can improve performance
                                                            ///< but uses more energy.

        };

        ///////////////////////////////////////////////////////////////////////////////
        /// @brief Standby hardware component properties
        struct properties_t
        {
            type_t type;                                    ///< [out] Which standby hardware component this controls
            ze::bool_t onSubdevice;                         ///< [out] True if the resource is located on a sub-device; false means
                                                            ///< that the resource is on the device of the calling Sysman handle
            uint32_t subdeviceId;                           ///< [out] If onSubdevice is true, this gives the ID of the sub-device

        };


    protected:
        ///////////////////////////////////////////////////////////////////////////////
        standby_handle_t m_handle = nullptr;            ///< [in] handle of Sysman object
        Device* m_pDevice;                              ///< [in] pointer to owner object

    public:
        ///////////////////////////////////////////////////////////////////////////////
        Standby( void ) = delete;
        Standby( 
            standby_handle_t handle,                        ///< [in] handle of Sysman object
            Device* pDevice                                 ///< [in] pointer to owner object
            );

        ~Standby( void ) = default;

        Standby( Standby const& other ) = delete;
        void operator=( Standby const& other ) = delete;

        Standby( Standby&& other ) = delete;
        void operator=( Standby&& other ) = delete;

        ///////////////////////////////////////////////////////////////////////////////
        auto getHandle( void ) const { return m_handle; }
        auto getDevice( void ) const { return m_pDevice; }

        ///////////////////////////////////////////////////////////////////////////////
        /// @brief Get standby hardware component properties
        /// 
        /// @details
        ///     - The application may call this function from simultaneous threads.
        ///     - The implementation of this function should be lock-free.
        /// @throws result_t
        void __zecall
        GetProperties(
            properties_t* pProperties                       ///< [in,out] Will contain the standby hardware properties.
            );

        ///////////////////////////////////////////////////////////////////////////////
        /// @brief Get the current standby promotion mode
        /// 
        /// @details
        ///     - The application may call this function from simultaneous threads.
        ///     - The implementation of this function should be lock-free.
        /// @throws result_t
        void __zecall
        GetMode(
            promo_mode_t* pMode                             ///< [in,out] Will contain the current standby mode.
            );

        ///////////////////////////////////////////////////////////////////////////////
        /// @brief Set standby promotion mode
        /// 
        /// @details
        ///     - The application may call this function from simultaneous threads.
        ///     - The implementation of this function should be lock-free.
        /// @throws result_t
        void __zecall
        SetMode(
            promo_mode_t mode                               ///< [in] New standby mode.
            );

    };

} // namespace zes

namespace zes
{
    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Converts Standby::type_t to std::string
    std::string to_string( const Standby::type_t val );

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Converts Standby::properties_t to std::string
    std::string to_string( const Standby::properties_t val );

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Converts Standby::promo_mode_t to std::string
    std::string to_string( const Standby::promo_mode_t val );

} // namespace zes
#pragma endregion
#pragma region temperature
namespace zes
{
    ///////////////////////////////////////////////////////////////////////////////
    /// @brief C++ wrapper for a Sysman device temperature sensor
    class Temperature
    {
    public:
        ///////////////////////////////////////////////////////////////////////////////
        /// @brief Temperature sensors
        enum class temp_sensors_t
        {
            GLOBAL = 0,                                     ///< The maximum temperature across all device sensors
            GPU,                                            ///< The maximum temperature across all sensors in the GPU
            MEMORY,                                         ///< The maximum temperature across all sensors in the local memory

        };

        ///////////////////////////////////////////////////////////////////////////////
        /// @brief Temperature sensor properties
        struct temp_properties_t
        {
            temp_sensors_t type;                            ///< [out] Which part of the device the temperature sensor measures
            ze::bool_t onSubdevice;                         ///< [out] True if the resource is located on a sub-device; false means
                                                            ///< that the resource is on the device of the calling Sysman handle
            uint32_t subdeviceId;                           ///< [out] If onSubdevice is true, this gives the ID of the sub-device
            ze::bool_t isCriticalTempSupported;             ///< [out] Indicates if the critical temperature event
                                                            ///< ::ZES_EVENT_TYPE_TEMP_CRITICAL is supported
            ze::bool_t isThreshold1Supported;               ///< [out] Indicates if the temperature threshold 1 event
                                                            ///< ::ZES_EVENT_TYPE_TEMP_THRESHOLD1 is supported
            ze::bool_t isThreshold2Supported;               ///< [out] Indicates if the temperature threshold 2 event
                                                            ///< ::ZES_EVENT_TYPE_TEMP_THRESHOLD2 is supported

        };

        ///////////////////////////////////////////////////////////////////////////////
        /// @brief Temperature sensor threshold
        struct temp_threshold_t
        {
            ze::bool_t enableLowToHigh;                     ///< [in,out] Trigger an event when the temperature crosses from below the
                                                            ///< threshold to above.
            ze::bool_t enableHighToLow;                     ///< [in,out] Trigger an event when the temperature crosses from above the
                                                            ///< threshold to below.
            double threshold;                               ///< [in,out] The threshold in degrees Celsius.

        };

        ///////////////////////////////////////////////////////////////////////////////
        /// @brief Temperature configuration - which events should be triggered and the
        ///        trigger conditions.
        struct temp_config_t
        {
            ze::bool_t enableCritical;                      ///< [in,out] Indicates if event ::ZES_EVENT_TYPE_TEMP_CRITICAL should be
                                                            ///< triggered by the driver.
            temp_threshold_t threshold1;                    ///< [in,out] Configuration controlling if and when event
                                                            ///< ::ZES_EVENT_TYPE_TEMP_THRESHOLD1 should be triggered by the driver.
            temp_threshold_t threshold2;                    ///< [in,out] Configuration controlling if and when event
                                                            ///< ::ZES_EVENT_TYPE_TEMP_THRESHOLD2 should be triggered by the driver.
            uint32_t processId;                             ///< [out] Host processId that set this configuration (ignored when setting
                                                            ///< the configuration).

        };


    protected:
        ///////////////////////////////////////////////////////////////////////////////
        temp_handle_t m_handle = nullptr;               ///< [in] handle of Sysman object
        Device* m_pDevice;                              ///< [in] pointer to owner object

    public:
        ///////////////////////////////////////////////////////////////////////////////
        Temperature( void ) = delete;
        Temperature( 
            temp_handle_t handle,                           ///< [in] handle of Sysman object
            Device* pDevice                                 ///< [in] pointer to owner object
            );

        ~Temperature( void ) = default;

        Temperature( Temperature const& other ) = delete;
        void operator=( Temperature const& other ) = delete;

        Temperature( Temperature&& other ) = delete;
        void operator=( Temperature&& other ) = delete;

        ///////////////////////////////////////////////////////////////////////////////
        auto getHandle( void ) const { return m_handle; }
        auto getDevice( void ) const { return m_pDevice; }

        ///////////////////////////////////////////////////////////////////////////////
        /// @brief Get temperature sensor properties
        /// 
        /// @details
        ///     - The application may call this function from simultaneous threads.
        ///     - The implementation of this function should be lock-free.
        /// @throws result_t
        void __zecall
        GetProperties(
            temp_properties_t* pProperties                  ///< [in,out] Will contain the temperature sensor properties.
            );

        ///////////////////////////////////////////////////////////////////////////////
        /// @brief Get temperature configuration for this sensor - which events are
        ///        triggered and the trigger conditions
        /// 
        /// @details
        ///     - The application may call this function from simultaneous threads.
        ///     - The implementation of this function should be lock-free.
        /// @throws result_t
        void __zecall
        GetConfig(
            temp_config_t* pConfig                          ///< [in,out] Returns current configuration.
            );

        ///////////////////////////////////////////////////////////////////////////////
        /// @brief Set temperature configuration for this sensor - indicates which events
        ///        are triggered and the trigger conditions
        /// 
        /// @details
        ///     - Events ::ZES_EVENT_TYPE_TEMP_CRITICAL will be triggered when
        ///       temperature reaches the critical range. Use the function
        ///       ::zesEventSetConfig() to start receiving this event.
        ///     - Events ::ZES_EVENT_TYPE_TEMP_THRESHOLD1 and
        ///       ::ZES_EVENT_TYPE_TEMP_THRESHOLD2 will be generated when temperature
        ///       cross the thresholds set using this function. Use the function
        ///       ::zesEventSetConfig() to start receiving these events.
        ///     - Only one running process can set the temperature configuration at a
        ///       time. If another process attempts to change the configuration, the
        ///       error ::ZE_RESULT_ERROR_NOT_AVAILABLE will be returned. The function
        ///       ::zesTemperatureGetConfig() will return the process ID currently
        ///       controlling these settings.
        ///     - The application may call this function from simultaneous threads.
        ///     - The implementation of this function should be lock-free.
        /// @throws result_t
        void __zecall
        SetConfig(
            const temp_config_t* pConfig                    ///< [in] New configuration.
            );

        ///////////////////////////////////////////////////////////////////////////////
        /// @brief Get the temperature from a specified sensor
        /// 
        /// @details
        ///     - The application may call this function from simultaneous threads.
        ///     - The implementation of this function should be lock-free.
        /// @throws result_t
        void __zecall
        GetState(
            double* pTemperature                            ///< [in,out] Will contain the temperature read from the specified sensor
                                                            ///< in degrees Celsius.
            );

    };

} // namespace zes

namespace zes
{
    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Converts Temperature::temp_sensors_t to std::string
    std::string to_string( const Temperature::temp_sensors_t val );

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Converts Temperature::temp_properties_t to std::string
    std::string to_string( const Temperature::temp_properties_t val );

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Converts Temperature::temp_threshold_t to std::string
    std::string to_string( const Temperature::temp_threshold_t val );

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Converts Temperature::temp_config_t to std::string
    std::string to_string( const Temperature::temp_config_t val );

} // namespace zes
#pragma endregion
#endif // defined(__cplusplus)
#endif // _ZES_API_HPP