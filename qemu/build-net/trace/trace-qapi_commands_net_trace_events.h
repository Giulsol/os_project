/* This file is autogenerated by tracetool, do not edit. */

#ifndef TRACE_QAPI_COMMANDS_NET_TRACE_EVENTS_GENERATED_TRACERS_H
#define TRACE_QAPI_COMMANDS_NET_TRACE_EVENTS_GENERATED_TRACERS_H

#include "trace/control.h"

extern TraceEvent _TRACE_QMP_ENTER_SET_LINK_EVENT;
extern TraceEvent _TRACE_QMP_EXIT_SET_LINK_EVENT;
extern TraceEvent _TRACE_QMP_ENTER_NETDEV_ADD_EVENT;
extern TraceEvent _TRACE_QMP_EXIT_NETDEV_ADD_EVENT;
extern TraceEvent _TRACE_QMP_ENTER_NETDEV_DEL_EVENT;
extern TraceEvent _TRACE_QMP_EXIT_NETDEV_DEL_EVENT;
extern TraceEvent _TRACE_QMP_ENTER_QUERY_RX_FILTER_EVENT;
extern TraceEvent _TRACE_QMP_EXIT_QUERY_RX_FILTER_EVENT;
extern TraceEvent _TRACE_QMP_ENTER_ANNOUNCE_SELF_EVENT;
extern TraceEvent _TRACE_QMP_EXIT_ANNOUNCE_SELF_EVENT;
extern uint16_t _TRACE_QMP_ENTER_SET_LINK_DSTATE;
extern uint16_t _TRACE_QMP_EXIT_SET_LINK_DSTATE;
extern uint16_t _TRACE_QMP_ENTER_NETDEV_ADD_DSTATE;
extern uint16_t _TRACE_QMP_EXIT_NETDEV_ADD_DSTATE;
extern uint16_t _TRACE_QMP_ENTER_NETDEV_DEL_DSTATE;
extern uint16_t _TRACE_QMP_EXIT_NETDEV_DEL_DSTATE;
extern uint16_t _TRACE_QMP_ENTER_QUERY_RX_FILTER_DSTATE;
extern uint16_t _TRACE_QMP_EXIT_QUERY_RX_FILTER_DSTATE;
extern uint16_t _TRACE_QMP_ENTER_ANNOUNCE_SELF_DSTATE;
extern uint16_t _TRACE_QMP_EXIT_ANNOUNCE_SELF_DSTATE;
#define TRACE_QMP_ENTER_SET_LINK_ENABLED 1
#define TRACE_QMP_EXIT_SET_LINK_ENABLED 1
#define TRACE_QMP_ENTER_NETDEV_ADD_ENABLED 1
#define TRACE_QMP_EXIT_NETDEV_ADD_ENABLED 1
#define TRACE_QMP_ENTER_NETDEV_DEL_ENABLED 1
#define TRACE_QMP_EXIT_NETDEV_DEL_ENABLED 1
#define TRACE_QMP_ENTER_QUERY_RX_FILTER_ENABLED 1
#define TRACE_QMP_EXIT_QUERY_RX_FILTER_ENABLED 1
#define TRACE_QMP_ENTER_ANNOUNCE_SELF_ENABLED 1
#define TRACE_QMP_EXIT_ANNOUNCE_SELF_ENABLED 1
#include "qemu/log-for-trace.h"
#include "qemu/error-report.h"


#define TRACE_QMP_ENTER_SET_LINK_BACKEND_DSTATE() ( \
    trace_event_get_state_dynamic_by_id(TRACE_QMP_ENTER_SET_LINK) || \
    false)

static inline void _nocheck__trace_qmp_enter_set_link(const char * json)
{
    if (trace_event_get_state(TRACE_QMP_ENTER_SET_LINK) && qemu_loglevel_mask(LOG_TRACE)) {
        if (message_with_timestamp) {
            struct timeval _now;
            gettimeofday(&_now, NULL);
#line 3 "qapi/qapi-commands-net.trace-events"
            qemu_log("%d@%zu.%06zu:qmp_enter_set_link " "%s" "\n",
                     qemu_get_thread_id(),
                     (size_t)_now.tv_sec, (size_t)_now.tv_usec
                     , json);
#line 58 "trace/trace-qapi_commands_net_trace_events.h"
        } else {
#line 3 "qapi/qapi-commands-net.trace-events"
            qemu_log("qmp_enter_set_link " "%s" "\n", json);
#line 62 "trace/trace-qapi_commands_net_trace_events.h"
        }
    }
}

static inline void trace_qmp_enter_set_link(const char * json)
{
    if (true) {
        _nocheck__trace_qmp_enter_set_link(json);
    }
}

#define TRACE_QMP_EXIT_SET_LINK_BACKEND_DSTATE() ( \
    trace_event_get_state_dynamic_by_id(TRACE_QMP_EXIT_SET_LINK) || \
    false)

static inline void _nocheck__trace_qmp_exit_set_link(const char * result, bool succeeded)
{
    if (trace_event_get_state(TRACE_QMP_EXIT_SET_LINK) && qemu_loglevel_mask(LOG_TRACE)) {
        if (message_with_timestamp) {
            struct timeval _now;
            gettimeofday(&_now, NULL);
#line 4 "qapi/qapi-commands-net.trace-events"
            qemu_log("%d@%zu.%06zu:qmp_exit_set_link " "%s %d" "\n",
                     qemu_get_thread_id(),
                     (size_t)_now.tv_sec, (size_t)_now.tv_usec
                     , result, succeeded);
#line 89 "trace/trace-qapi_commands_net_trace_events.h"
        } else {
#line 4 "qapi/qapi-commands-net.trace-events"
            qemu_log("qmp_exit_set_link " "%s %d" "\n", result, succeeded);
#line 93 "trace/trace-qapi_commands_net_trace_events.h"
        }
    }
}

static inline void trace_qmp_exit_set_link(const char * result, bool succeeded)
{
    if (true) {
        _nocheck__trace_qmp_exit_set_link(result, succeeded);
    }
}

#define TRACE_QMP_ENTER_NETDEV_ADD_BACKEND_DSTATE() ( \
    trace_event_get_state_dynamic_by_id(TRACE_QMP_ENTER_NETDEV_ADD) || \
    false)

static inline void _nocheck__trace_qmp_enter_netdev_add(const char * json)
{
    if (trace_event_get_state(TRACE_QMP_ENTER_NETDEV_ADD) && qemu_loglevel_mask(LOG_TRACE)) {
        if (message_with_timestamp) {
            struct timeval _now;
            gettimeofday(&_now, NULL);
#line 5 "qapi/qapi-commands-net.trace-events"
            qemu_log("%d@%zu.%06zu:qmp_enter_netdev_add " "%s" "\n",
                     qemu_get_thread_id(),
                     (size_t)_now.tv_sec, (size_t)_now.tv_usec
                     , json);
#line 120 "trace/trace-qapi_commands_net_trace_events.h"
        } else {
#line 5 "qapi/qapi-commands-net.trace-events"
            qemu_log("qmp_enter_netdev_add " "%s" "\n", json);
#line 124 "trace/trace-qapi_commands_net_trace_events.h"
        }
    }
}

static inline void trace_qmp_enter_netdev_add(const char * json)
{
    if (true) {
        _nocheck__trace_qmp_enter_netdev_add(json);
    }
}

#define TRACE_QMP_EXIT_NETDEV_ADD_BACKEND_DSTATE() ( \
    trace_event_get_state_dynamic_by_id(TRACE_QMP_EXIT_NETDEV_ADD) || \
    false)

static inline void _nocheck__trace_qmp_exit_netdev_add(const char * result, bool succeeded)
{
    if (trace_event_get_state(TRACE_QMP_EXIT_NETDEV_ADD) && qemu_loglevel_mask(LOG_TRACE)) {
        if (message_with_timestamp) {
            struct timeval _now;
            gettimeofday(&_now, NULL);
#line 6 "qapi/qapi-commands-net.trace-events"
            qemu_log("%d@%zu.%06zu:qmp_exit_netdev_add " "%s %d" "\n",
                     qemu_get_thread_id(),
                     (size_t)_now.tv_sec, (size_t)_now.tv_usec
                     , result, succeeded);
#line 151 "trace/trace-qapi_commands_net_trace_events.h"
        } else {
#line 6 "qapi/qapi-commands-net.trace-events"
            qemu_log("qmp_exit_netdev_add " "%s %d" "\n", result, succeeded);
#line 155 "trace/trace-qapi_commands_net_trace_events.h"
        }
    }
}

static inline void trace_qmp_exit_netdev_add(const char * result, bool succeeded)
{
    if (true) {
        _nocheck__trace_qmp_exit_netdev_add(result, succeeded);
    }
}

#define TRACE_QMP_ENTER_NETDEV_DEL_BACKEND_DSTATE() ( \
    trace_event_get_state_dynamic_by_id(TRACE_QMP_ENTER_NETDEV_DEL) || \
    false)

static inline void _nocheck__trace_qmp_enter_netdev_del(const char * json)
{
    if (trace_event_get_state(TRACE_QMP_ENTER_NETDEV_DEL) && qemu_loglevel_mask(LOG_TRACE)) {
        if (message_with_timestamp) {
            struct timeval _now;
            gettimeofday(&_now, NULL);
#line 7 "qapi/qapi-commands-net.trace-events"
            qemu_log("%d@%zu.%06zu:qmp_enter_netdev_del " "%s" "\n",
                     qemu_get_thread_id(),
                     (size_t)_now.tv_sec, (size_t)_now.tv_usec
                     , json);
#line 182 "trace/trace-qapi_commands_net_trace_events.h"
        } else {
#line 7 "qapi/qapi-commands-net.trace-events"
            qemu_log("qmp_enter_netdev_del " "%s" "\n", json);
#line 186 "trace/trace-qapi_commands_net_trace_events.h"
        }
    }
}

static inline void trace_qmp_enter_netdev_del(const char * json)
{
    if (true) {
        _nocheck__trace_qmp_enter_netdev_del(json);
    }
}

#define TRACE_QMP_EXIT_NETDEV_DEL_BACKEND_DSTATE() ( \
    trace_event_get_state_dynamic_by_id(TRACE_QMP_EXIT_NETDEV_DEL) || \
    false)

static inline void _nocheck__trace_qmp_exit_netdev_del(const char * result, bool succeeded)
{
    if (trace_event_get_state(TRACE_QMP_EXIT_NETDEV_DEL) && qemu_loglevel_mask(LOG_TRACE)) {
        if (message_with_timestamp) {
            struct timeval _now;
            gettimeofday(&_now, NULL);
#line 8 "qapi/qapi-commands-net.trace-events"
            qemu_log("%d@%zu.%06zu:qmp_exit_netdev_del " "%s %d" "\n",
                     qemu_get_thread_id(),
                     (size_t)_now.tv_sec, (size_t)_now.tv_usec
                     , result, succeeded);
#line 213 "trace/trace-qapi_commands_net_trace_events.h"
        } else {
#line 8 "qapi/qapi-commands-net.trace-events"
            qemu_log("qmp_exit_netdev_del " "%s %d" "\n", result, succeeded);
#line 217 "trace/trace-qapi_commands_net_trace_events.h"
        }
    }
}

static inline void trace_qmp_exit_netdev_del(const char * result, bool succeeded)
{
    if (true) {
        _nocheck__trace_qmp_exit_netdev_del(result, succeeded);
    }
}

#define TRACE_QMP_ENTER_QUERY_RX_FILTER_BACKEND_DSTATE() ( \
    trace_event_get_state_dynamic_by_id(TRACE_QMP_ENTER_QUERY_RX_FILTER) || \
    false)

static inline void _nocheck__trace_qmp_enter_query_rx_filter(const char * json)
{
    if (trace_event_get_state(TRACE_QMP_ENTER_QUERY_RX_FILTER) && qemu_loglevel_mask(LOG_TRACE)) {
        if (message_with_timestamp) {
            struct timeval _now;
            gettimeofday(&_now, NULL);
#line 9 "qapi/qapi-commands-net.trace-events"
            qemu_log("%d@%zu.%06zu:qmp_enter_query_rx_filter " "%s" "\n",
                     qemu_get_thread_id(),
                     (size_t)_now.tv_sec, (size_t)_now.tv_usec
                     , json);
#line 244 "trace/trace-qapi_commands_net_trace_events.h"
        } else {
#line 9 "qapi/qapi-commands-net.trace-events"
            qemu_log("qmp_enter_query_rx_filter " "%s" "\n", json);
#line 248 "trace/trace-qapi_commands_net_trace_events.h"
        }
    }
}

static inline void trace_qmp_enter_query_rx_filter(const char * json)
{
    if (true) {
        _nocheck__trace_qmp_enter_query_rx_filter(json);
    }
}

#define TRACE_QMP_EXIT_QUERY_RX_FILTER_BACKEND_DSTATE() ( \
    trace_event_get_state_dynamic_by_id(TRACE_QMP_EXIT_QUERY_RX_FILTER) || \
    false)

static inline void _nocheck__trace_qmp_exit_query_rx_filter(const char * result, bool succeeded)
{
    if (trace_event_get_state(TRACE_QMP_EXIT_QUERY_RX_FILTER) && qemu_loglevel_mask(LOG_TRACE)) {
        if (message_with_timestamp) {
            struct timeval _now;
            gettimeofday(&_now, NULL);
#line 10 "qapi/qapi-commands-net.trace-events"
            qemu_log("%d@%zu.%06zu:qmp_exit_query_rx_filter " "%s %d" "\n",
                     qemu_get_thread_id(),
                     (size_t)_now.tv_sec, (size_t)_now.tv_usec
                     , result, succeeded);
#line 275 "trace/trace-qapi_commands_net_trace_events.h"
        } else {
#line 10 "qapi/qapi-commands-net.trace-events"
            qemu_log("qmp_exit_query_rx_filter " "%s %d" "\n", result, succeeded);
#line 279 "trace/trace-qapi_commands_net_trace_events.h"
        }
    }
}

static inline void trace_qmp_exit_query_rx_filter(const char * result, bool succeeded)
{
    if (true) {
        _nocheck__trace_qmp_exit_query_rx_filter(result, succeeded);
    }
}

#define TRACE_QMP_ENTER_ANNOUNCE_SELF_BACKEND_DSTATE() ( \
    trace_event_get_state_dynamic_by_id(TRACE_QMP_ENTER_ANNOUNCE_SELF) || \
    false)

static inline void _nocheck__trace_qmp_enter_announce_self(const char * json)
{
    if (trace_event_get_state(TRACE_QMP_ENTER_ANNOUNCE_SELF) && qemu_loglevel_mask(LOG_TRACE)) {
        if (message_with_timestamp) {
            struct timeval _now;
            gettimeofday(&_now, NULL);
#line 11 "qapi/qapi-commands-net.trace-events"
            qemu_log("%d@%zu.%06zu:qmp_enter_announce_self " "%s" "\n",
                     qemu_get_thread_id(),
                     (size_t)_now.tv_sec, (size_t)_now.tv_usec
                     , json);
#line 306 "trace/trace-qapi_commands_net_trace_events.h"
        } else {
#line 11 "qapi/qapi-commands-net.trace-events"
            qemu_log("qmp_enter_announce_self " "%s" "\n", json);
#line 310 "trace/trace-qapi_commands_net_trace_events.h"
        }
    }
}

static inline void trace_qmp_enter_announce_self(const char * json)
{
    if (true) {
        _nocheck__trace_qmp_enter_announce_self(json);
    }
}

#define TRACE_QMP_EXIT_ANNOUNCE_SELF_BACKEND_DSTATE() ( \
    trace_event_get_state_dynamic_by_id(TRACE_QMP_EXIT_ANNOUNCE_SELF) || \
    false)

static inline void _nocheck__trace_qmp_exit_announce_self(const char * result, bool succeeded)
{
    if (trace_event_get_state(TRACE_QMP_EXIT_ANNOUNCE_SELF) && qemu_loglevel_mask(LOG_TRACE)) {
        if (message_with_timestamp) {
            struct timeval _now;
            gettimeofday(&_now, NULL);
#line 12 "qapi/qapi-commands-net.trace-events"
            qemu_log("%d@%zu.%06zu:qmp_exit_announce_self " "%s %d" "\n",
                     qemu_get_thread_id(),
                     (size_t)_now.tv_sec, (size_t)_now.tv_usec
                     , result, succeeded);
#line 337 "trace/trace-qapi_commands_net_trace_events.h"
        } else {
#line 12 "qapi/qapi-commands-net.trace-events"
            qemu_log("qmp_exit_announce_self " "%s %d" "\n", result, succeeded);
#line 341 "trace/trace-qapi_commands_net_trace_events.h"
        }
    }
}

static inline void trace_qmp_exit_announce_self(const char * result, bool succeeded)
{
    if (true) {
        _nocheck__trace_qmp_exit_announce_self(result, succeeded);
    }
}
#endif /* TRACE_QAPI_COMMANDS_NET_TRACE_EVENTS_GENERATED_TRACERS_H */
