/*
 *
 * Copyright (C) 2019 Intel Corporation
 *
 * SPDX-License-Identifier: MIT
 *
 * @file zet_debug.hpp
 *
 * @brief C++ wrapper of Intel 'One API' Level-Zero Tool APIs for Program Debug
 *
 * @cond DEV
 * DO NOT EDIT: generated from /scripts/tools/debug.yml
 * @endcond
 *
 */
#ifndef _ZET_DEBUG_HPP
#define _ZET_DEBUG_HPP
#if defined(__cplusplus)
#pragma once
#if !defined(_ZET_API_HPP)
#pragma message("warning: this file is not intended to be included directly")
#endif

///////////////////////////////////////////////////////////////////////////////
#ifndef ZET_DEBUG_TIMEOUT_INFINITE
/// @brief An infinite timeout.
#define ZET_DEBUG_TIMEOUT_INFINITE  0xffffffffffffffffull
#endif // ZET_DEBUG_TIMEOUT_INFINITE

///////////////////////////////////////////////////////////////////////////////
#ifndef ZET_DEBUG_THREAD_NONE
/// @brief No thread on the device.
#define ZET_DEBUG_THREAD_NONE  0xffffffffffffffffull
#endif // ZET_DEBUG_THREAD_NONE

///////////////////////////////////////////////////////////////////////////////
#ifndef ZET_DEBUG_THREAD_ALL
/// @brief All threads on the device.
#define ZET_DEBUG_THREAD_ALL  0xfffffffffffffffeull
#endif // ZET_DEBUG_THREAD_ALL

namespace zet
{
    ///////////////////////////////////////////////////////////////////////////////
    /// @brief C++ wrapper for Debug API
    class Debug
    {
    public:
        ///////////////////////////////////////////////////////////////////////////////
        /// @brief Debug attach flags.
        enum class attach_flags_t
        {
            DEBUG_ATTACH_NONE = 0,                          ///< No attach flags

        };

        ///////////////////////////////////////////////////////////////////////////////
        /// @brief Debug wait flags.
        enum class wait_flags_t
        {
            DEBUG_WAIT_NONE = 0,                            ///< No wait flags

        };

        ///////////////////////////////////////////////////////////////////////////////
        /// @brief Debug event flags.
        enum class event_flags_t
        {
            DEBUG_EVENT_FLAG_NONE = 0,                      ///< No event flags
            DEBUG_EVENT_FLAG_STOPPED = (1 << 0),            ///< The reporting thread stopped

        };

        ///////////////////////////////////////////////////////////////////////////////
        /// @brief Debug event types.
        enum class event_type_t
        {
            DEBUG_EVENT_INVALID = 0,                        ///< The event is invalid
            DEBUG_EVENT_DETACHED,                           ///< The tool was detached
            DEBUG_EVENT_PROCESS_ENTRY,                      ///< The debuggee process created command queues on the device
            DEBUG_EVENT_PROCESS_EXIT,                       ///< The debuggee process destroyed all command queues on the device
            DEBUG_EVENT_MODULE_LOAD,                        ///< An in-memory module was loaded onto the device
            DEBUG_EVENT_EXCEPTION,                          ///< The thread stopped due to a device exception

        };

        ///////////////////////////////////////////////////////////////////////////////
        /// @brief Debug detach reason.
        enum class detach_reason_t
        {
            DEBUG_DETACH_INVALID = 0,                       ///< The detach reason is not valid
            DEBUG_DETACH_HOST_EXIT,                         ///< The host process exited

        };

        ///////////////////////////////////////////////////////////////////////////////
        /// @brief Event information for ::ZET_DEBUG_EVENT_DETACHED
        struct event_info_detached_t
        {
            uint8_t reason;                                 ///< The detach reason

        };

        ///////////////////////////////////////////////////////////////////////////////
        /// @brief Event information for ::ZET_DEBUG_EVENT_MODULE_LOAD
        struct event_info_module_t
        {
            uint64_t moduleBegin;                           ///< The begin address of the in-memory module
            uint64_t moduleEnd;                             ///< The end address of the in-memory module
            uint64_t loadBegin;                             ///< The begin address of the loaded module on the device
            uint64_t loadEnd;                               ///< The end address of the loaded module on the device

        };

        ///////////////////////////////////////////////////////////////////////////////
        /// @brief Event information for ::ZET_DEBUG_EVENT_EXCEPTION
        struct event_info_exception_t
        {
            uint64_t code;                                  ///< The device-specific exception code
            uint64_t ip;                                    ///< The instruction pointer
            uint64_t sp;                                    ///< The stack pointer

        };

        ///////////////////////////////////////////////////////////////////////////////
        /// @brief Event type specific information
        union event_info_t
        {
            event_info_detached_t detached;                 ///< type == ::ZET_DEBUG_EVENT_DETACHED
            event_info_module_t module;                     ///< type == ::ZET_DEBUG_EVENT_MODULE_LOAD
            event_info_exception_t exception;               ///< type == ::ZET_DEBUG_EVENT_EXCEPTION

        };

        ///////////////////////////////////////////////////////////////////////////////
        /// @brief A debug event on the device.
        struct event_t
        {
            uint16_t size;                                  ///< The size of the event object in bytes
            uint8_t type;                                   ///< The event type
            uint64_t flags;                                 ///< A bit-vector of ::zet_debug_event_flags_t
            uint64_t thread;                                ///< The thread reporting the event
            event_info_t info;                              ///< Event type specific information

        };


    protected:
        ///////////////////////////////////////////////////////////////////////////////
        debug_session_handle_t* m_hDebug;               ///< [in] debug session handle

    public:
        ///////////////////////////////////////////////////////////////////////////////
        Debug( void ) = delete;
        Debug( 
            debug_session_handle_t* hDebug                  ///< [in] debug session handle
            );

        ~Debug( void ) = default;

        Debug( Debug const& other ) = delete;
        void operator=( Debug const& other ) = delete;

        Debug( Debug&& other ) = delete;
        void operator=( Debug&& other ) = delete;

        ///////////////////////////////////////////////////////////////////////////////
        auto getHdebug( void ) const { return m_hDebug; }

        ///////////////////////////////////////////////////////////////////////////////
        /// @brief Attach to a device.
        /// @returns
        ///     - debug_session_handle_t: debug session handle
        /// 
        /// @throws result_t
        static debug_session_handle_t __zecall
        Attach(
            Device* pDevice,                                ///< [in] device handle
            int pid,                                        ///< [in] host process identifier
            uint64_t flags                                  ///< [in] a bit-vector of ::zet_debug_attach_flags_t
            );

        ///////////////////////////////////////////////////////////////////////////////
        /// @brief Close a debug session.
        /// @throws result_t
        void __zecall
        Detach(
            void
            );

        ///////////////////////////////////////////////////////////////////////////////
        /// @brief Query the number of device threads for a debug session.
        /// @returns
        ///     - uint64_t: the maximal number of threads
        /// 
        /// @throws result_t
        uint64_t __zecall
        GetNumThreads(
            void
            );

        ///////////////////////////////////////////////////////////////////////////////
        /// @brief Wait for a debug event on the device.
        /// @returns
        ///     - size_t: size of the topmost event in bytes
        /// 
        /// @throws result_t
        size_t __zecall
        WaitForEvent(
            uint64_t timeout,                               ///< [in] timeout in milliseconds (UINT64_MAX for infinite)
            uint64_t flags                                  ///< [in] a bit-vector of ::zet_debug_wait_flags_t
            );

        ///////////////////////////////////////////////////////////////////////////////
        /// @brief Read the topmost debug event.
        /// @returns
        ///     - ze::bool_t:'0' when ZE::RESULT_NOT_READY
        /// @throws result_t
        ze::bool_t __zecall
        ReadEvent(
            size_t size,                                    ///< [in] the size of the buffer in bytes
            void* buffer                                    ///< [in,out] a buffer to hold the event data
            );

    };

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Debug session handle
    struct _debug_session_handle_t;
    using debug_session_handle_t = _debug_session_handle_t*;

} // namespace zet

namespace zet
{
    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Converts Debug::attach_flags_t to std::string
    std::string to_string( const Debug::attach_flags_t val );

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Converts Debug::wait_flags_t to std::string
    std::string to_string( const Debug::wait_flags_t val );

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Converts Debug::event_flags_t to std::string
    std::string to_string( const Debug::event_flags_t val );

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Converts Debug::event_type_t to std::string
    std::string to_string( const Debug::event_type_t val );

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Converts Debug::detach_reason_t to std::string
    std::string to_string( const Debug::detach_reason_t val );

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Converts Debug::event_info_detached_t to std::string
    std::string to_string( const Debug::event_info_detached_t val );

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Converts Debug::event_info_module_t to std::string
    std::string to_string( const Debug::event_info_module_t val );

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Converts Debug::event_info_exception_t to std::string
    std::string to_string( const Debug::event_info_exception_t val );

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Converts Debug::event_info_t to std::string
    std::string to_string( const Debug::event_info_t val );

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Converts Debug::event_t to std::string
    std::string to_string( const Debug::event_t val );

} // namespace zet
#endif // defined(__cplusplus)
#endif // _ZET_DEBUG_HPP
