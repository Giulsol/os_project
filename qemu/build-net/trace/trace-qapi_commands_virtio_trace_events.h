/* This file is autogenerated by tracetool, do not edit. */

#ifndef TRACE_QAPI_COMMANDS_VIRTIO_TRACE_EVENTS_GENERATED_TRACERS_H
#define TRACE_QAPI_COMMANDS_VIRTIO_TRACE_EVENTS_GENERATED_TRACERS_H

#include "trace/control.h"

extern TraceEvent _TRACE_QMP_ENTER_X_QUERY_VIRTIO_EVENT;
extern TraceEvent _TRACE_QMP_EXIT_X_QUERY_VIRTIO_EVENT;
extern TraceEvent _TRACE_QMP_ENTER_X_QUERY_VIRTIO_STATUS_EVENT;
extern TraceEvent _TRACE_QMP_EXIT_X_QUERY_VIRTIO_STATUS_EVENT;
extern TraceEvent _TRACE_QMP_ENTER_X_QUERY_VIRTIO_QUEUE_STATUS_EVENT;
extern TraceEvent _TRACE_QMP_EXIT_X_QUERY_VIRTIO_QUEUE_STATUS_EVENT;
extern TraceEvent _TRACE_QMP_ENTER_X_QUERY_VIRTIO_VHOST_QUEUE_STATUS_EVENT;
extern TraceEvent _TRACE_QMP_EXIT_X_QUERY_VIRTIO_VHOST_QUEUE_STATUS_EVENT;
extern TraceEvent _TRACE_QMP_ENTER_X_QUERY_VIRTIO_QUEUE_ELEMENT_EVENT;
extern TraceEvent _TRACE_QMP_EXIT_X_QUERY_VIRTIO_QUEUE_ELEMENT_EVENT;
extern uint16_t _TRACE_QMP_ENTER_X_QUERY_VIRTIO_DSTATE;
extern uint16_t _TRACE_QMP_EXIT_X_QUERY_VIRTIO_DSTATE;
extern uint16_t _TRACE_QMP_ENTER_X_QUERY_VIRTIO_STATUS_DSTATE;
extern uint16_t _TRACE_QMP_EXIT_X_QUERY_VIRTIO_STATUS_DSTATE;
extern uint16_t _TRACE_QMP_ENTER_X_QUERY_VIRTIO_QUEUE_STATUS_DSTATE;
extern uint16_t _TRACE_QMP_EXIT_X_QUERY_VIRTIO_QUEUE_STATUS_DSTATE;
extern uint16_t _TRACE_QMP_ENTER_X_QUERY_VIRTIO_VHOST_QUEUE_STATUS_DSTATE;
extern uint16_t _TRACE_QMP_EXIT_X_QUERY_VIRTIO_VHOST_QUEUE_STATUS_DSTATE;
extern uint16_t _TRACE_QMP_ENTER_X_QUERY_VIRTIO_QUEUE_ELEMENT_DSTATE;
extern uint16_t _TRACE_QMP_EXIT_X_QUERY_VIRTIO_QUEUE_ELEMENT_DSTATE;
#define TRACE_QMP_ENTER_X_QUERY_VIRTIO_ENABLED 1
#define TRACE_QMP_EXIT_X_QUERY_VIRTIO_ENABLED 1
#define TRACE_QMP_ENTER_X_QUERY_VIRTIO_STATUS_ENABLED 1
#define TRACE_QMP_EXIT_X_QUERY_VIRTIO_STATUS_ENABLED 1
#define TRACE_QMP_ENTER_X_QUERY_VIRTIO_QUEUE_STATUS_ENABLED 1
#define TRACE_QMP_EXIT_X_QUERY_VIRTIO_QUEUE_STATUS_ENABLED 1
#define TRACE_QMP_ENTER_X_QUERY_VIRTIO_VHOST_QUEUE_STATUS_ENABLED 1
#define TRACE_QMP_EXIT_X_QUERY_VIRTIO_VHOST_QUEUE_STATUS_ENABLED 1
#define TRACE_QMP_ENTER_X_QUERY_VIRTIO_QUEUE_ELEMENT_ENABLED 1
#define TRACE_QMP_EXIT_X_QUERY_VIRTIO_QUEUE_ELEMENT_ENABLED 1
#include "qemu/log-for-trace.h"
#include "qemu/error-report.h"


#define TRACE_QMP_ENTER_X_QUERY_VIRTIO_BACKEND_DSTATE() ( \
    trace_event_get_state_dynamic_by_id(TRACE_QMP_ENTER_X_QUERY_VIRTIO) || \
    false)

static inline void _nocheck__trace_qmp_enter_x_query_virtio(const char * json)
{
    if (trace_event_get_state(TRACE_QMP_ENTER_X_QUERY_VIRTIO) && qemu_loglevel_mask(LOG_TRACE)) {
        if (message_with_timestamp) {
            struct timeval _now;
            gettimeofday(&_now, NULL);
#line 3 "qapi/qapi-commands-virtio.trace-events"
            qemu_log("%d@%zu.%06zu:qmp_enter_x_query_virtio " "%s" "\n",
                     qemu_get_thread_id(),
                     (size_t)_now.tv_sec, (size_t)_now.tv_usec
                     , json);
#line 58 "trace/trace-qapi_commands_virtio_trace_events.h"
        } else {
#line 3 "qapi/qapi-commands-virtio.trace-events"
            qemu_log("qmp_enter_x_query_virtio " "%s" "\n", json);
#line 62 "trace/trace-qapi_commands_virtio_trace_events.h"
        }
    }
}

static inline void trace_qmp_enter_x_query_virtio(const char * json)
{
    if (true) {
        _nocheck__trace_qmp_enter_x_query_virtio(json);
    }
}

#define TRACE_QMP_EXIT_X_QUERY_VIRTIO_BACKEND_DSTATE() ( \
    trace_event_get_state_dynamic_by_id(TRACE_QMP_EXIT_X_QUERY_VIRTIO) || \
    false)

static inline void _nocheck__trace_qmp_exit_x_query_virtio(const char * result, bool succeeded)
{
    if (trace_event_get_state(TRACE_QMP_EXIT_X_QUERY_VIRTIO) && qemu_loglevel_mask(LOG_TRACE)) {
        if (message_with_timestamp) {
            struct timeval _now;
            gettimeofday(&_now, NULL);
#line 4 "qapi/qapi-commands-virtio.trace-events"
            qemu_log("%d@%zu.%06zu:qmp_exit_x_query_virtio " "%s %d" "\n",
                     qemu_get_thread_id(),
                     (size_t)_now.tv_sec, (size_t)_now.tv_usec
                     , result, succeeded);
#line 89 "trace/trace-qapi_commands_virtio_trace_events.h"
        } else {
#line 4 "qapi/qapi-commands-virtio.trace-events"
            qemu_log("qmp_exit_x_query_virtio " "%s %d" "\n", result, succeeded);
#line 93 "trace/trace-qapi_commands_virtio_trace_events.h"
        }
    }
}

static inline void trace_qmp_exit_x_query_virtio(const char * result, bool succeeded)
{
    if (true) {
        _nocheck__trace_qmp_exit_x_query_virtio(result, succeeded);
    }
}

#define TRACE_QMP_ENTER_X_QUERY_VIRTIO_STATUS_BACKEND_DSTATE() ( \
    trace_event_get_state_dynamic_by_id(TRACE_QMP_ENTER_X_QUERY_VIRTIO_STATUS) || \
    false)

static inline void _nocheck__trace_qmp_enter_x_query_virtio_status(const char * json)
{
    if (trace_event_get_state(TRACE_QMP_ENTER_X_QUERY_VIRTIO_STATUS) && qemu_loglevel_mask(LOG_TRACE)) {
        if (message_with_timestamp) {
            struct timeval _now;
            gettimeofday(&_now, NULL);
#line 5 "qapi/qapi-commands-virtio.trace-events"
            qemu_log("%d@%zu.%06zu:qmp_enter_x_query_virtio_status " "%s" "\n",
                     qemu_get_thread_id(),
                     (size_t)_now.tv_sec, (size_t)_now.tv_usec
                     , json);
#line 120 "trace/trace-qapi_commands_virtio_trace_events.h"
        } else {
#line 5 "qapi/qapi-commands-virtio.trace-events"
            qemu_log("qmp_enter_x_query_virtio_status " "%s" "\n", json);
#line 124 "trace/trace-qapi_commands_virtio_trace_events.h"
        }
    }
}

static inline void trace_qmp_enter_x_query_virtio_status(const char * json)
{
    if (true) {
        _nocheck__trace_qmp_enter_x_query_virtio_status(json);
    }
}

#define TRACE_QMP_EXIT_X_QUERY_VIRTIO_STATUS_BACKEND_DSTATE() ( \
    trace_event_get_state_dynamic_by_id(TRACE_QMP_EXIT_X_QUERY_VIRTIO_STATUS) || \
    false)

static inline void _nocheck__trace_qmp_exit_x_query_virtio_status(const char * result, bool succeeded)
{
    if (trace_event_get_state(TRACE_QMP_EXIT_X_QUERY_VIRTIO_STATUS) && qemu_loglevel_mask(LOG_TRACE)) {
        if (message_with_timestamp) {
            struct timeval _now;
            gettimeofday(&_now, NULL);
#line 6 "qapi/qapi-commands-virtio.trace-events"
            qemu_log("%d@%zu.%06zu:qmp_exit_x_query_virtio_status " "%s %d" "\n",
                     qemu_get_thread_id(),
                     (size_t)_now.tv_sec, (size_t)_now.tv_usec
                     , result, succeeded);
#line 151 "trace/trace-qapi_commands_virtio_trace_events.h"
        } else {
#line 6 "qapi/qapi-commands-virtio.trace-events"
            qemu_log("qmp_exit_x_query_virtio_status " "%s %d" "\n", result, succeeded);
#line 155 "trace/trace-qapi_commands_virtio_trace_events.h"
        }
    }
}

static inline void trace_qmp_exit_x_query_virtio_status(const char * result, bool succeeded)
{
    if (true) {
        _nocheck__trace_qmp_exit_x_query_virtio_status(result, succeeded);
    }
}

#define TRACE_QMP_ENTER_X_QUERY_VIRTIO_QUEUE_STATUS_BACKEND_DSTATE() ( \
    trace_event_get_state_dynamic_by_id(TRACE_QMP_ENTER_X_QUERY_VIRTIO_QUEUE_STATUS) || \
    false)

static inline void _nocheck__trace_qmp_enter_x_query_virtio_queue_status(const char * json)
{
    if (trace_event_get_state(TRACE_QMP_ENTER_X_QUERY_VIRTIO_QUEUE_STATUS) && qemu_loglevel_mask(LOG_TRACE)) {
        if (message_with_timestamp) {
            struct timeval _now;
            gettimeofday(&_now, NULL);
#line 7 "qapi/qapi-commands-virtio.trace-events"
            qemu_log("%d@%zu.%06zu:qmp_enter_x_query_virtio_queue_status " "%s" "\n",
                     qemu_get_thread_id(),
                     (size_t)_now.tv_sec, (size_t)_now.tv_usec
                     , json);
#line 182 "trace/trace-qapi_commands_virtio_trace_events.h"
        } else {
#line 7 "qapi/qapi-commands-virtio.trace-events"
            qemu_log("qmp_enter_x_query_virtio_queue_status " "%s" "\n", json);
#line 186 "trace/trace-qapi_commands_virtio_trace_events.h"
        }
    }
}

static inline void trace_qmp_enter_x_query_virtio_queue_status(const char * json)
{
    if (true) {
        _nocheck__trace_qmp_enter_x_query_virtio_queue_status(json);
    }
}

#define TRACE_QMP_EXIT_X_QUERY_VIRTIO_QUEUE_STATUS_BACKEND_DSTATE() ( \
    trace_event_get_state_dynamic_by_id(TRACE_QMP_EXIT_X_QUERY_VIRTIO_QUEUE_STATUS) || \
    false)

static inline void _nocheck__trace_qmp_exit_x_query_virtio_queue_status(const char * result, bool succeeded)
{
    if (trace_event_get_state(TRACE_QMP_EXIT_X_QUERY_VIRTIO_QUEUE_STATUS) && qemu_loglevel_mask(LOG_TRACE)) {
        if (message_with_timestamp) {
            struct timeval _now;
            gettimeofday(&_now, NULL);
#line 8 "qapi/qapi-commands-virtio.trace-events"
            qemu_log("%d@%zu.%06zu:qmp_exit_x_query_virtio_queue_status " "%s %d" "\n",
                     qemu_get_thread_id(),
                     (size_t)_now.tv_sec, (size_t)_now.tv_usec
                     , result, succeeded);
#line 213 "trace/trace-qapi_commands_virtio_trace_events.h"
        } else {
#line 8 "qapi/qapi-commands-virtio.trace-events"
            qemu_log("qmp_exit_x_query_virtio_queue_status " "%s %d" "\n", result, succeeded);
#line 217 "trace/trace-qapi_commands_virtio_trace_events.h"
        }
    }
}

static inline void trace_qmp_exit_x_query_virtio_queue_status(const char * result, bool succeeded)
{
    if (true) {
        _nocheck__trace_qmp_exit_x_query_virtio_queue_status(result, succeeded);
    }
}

#define TRACE_QMP_ENTER_X_QUERY_VIRTIO_VHOST_QUEUE_STATUS_BACKEND_DSTATE() ( \
    trace_event_get_state_dynamic_by_id(TRACE_QMP_ENTER_X_QUERY_VIRTIO_VHOST_QUEUE_STATUS) || \
    false)

static inline void _nocheck__trace_qmp_enter_x_query_virtio_vhost_queue_status(const char * json)
{
    if (trace_event_get_state(TRACE_QMP_ENTER_X_QUERY_VIRTIO_VHOST_QUEUE_STATUS) && qemu_loglevel_mask(LOG_TRACE)) {
        if (message_with_timestamp) {
            struct timeval _now;
            gettimeofday(&_now, NULL);
#line 9 "qapi/qapi-commands-virtio.trace-events"
            qemu_log("%d@%zu.%06zu:qmp_enter_x_query_virtio_vhost_queue_status " "%s" "\n",
                     qemu_get_thread_id(),
                     (size_t)_now.tv_sec, (size_t)_now.tv_usec
                     , json);
#line 244 "trace/trace-qapi_commands_virtio_trace_events.h"
        } else {
#line 9 "qapi/qapi-commands-virtio.trace-events"
            qemu_log("qmp_enter_x_query_virtio_vhost_queue_status " "%s" "\n", json);
#line 248 "trace/trace-qapi_commands_virtio_trace_events.h"
        }
    }
}

static inline void trace_qmp_enter_x_query_virtio_vhost_queue_status(const char * json)
{
    if (true) {
        _nocheck__trace_qmp_enter_x_query_virtio_vhost_queue_status(json);
    }
}

#define TRACE_QMP_EXIT_X_QUERY_VIRTIO_VHOST_QUEUE_STATUS_BACKEND_DSTATE() ( \
    trace_event_get_state_dynamic_by_id(TRACE_QMP_EXIT_X_QUERY_VIRTIO_VHOST_QUEUE_STATUS) || \
    false)

static inline void _nocheck__trace_qmp_exit_x_query_virtio_vhost_queue_status(const char * result, bool succeeded)
{
    if (trace_event_get_state(TRACE_QMP_EXIT_X_QUERY_VIRTIO_VHOST_QUEUE_STATUS) && qemu_loglevel_mask(LOG_TRACE)) {
        if (message_with_timestamp) {
            struct timeval _now;
            gettimeofday(&_now, NULL);
#line 10 "qapi/qapi-commands-virtio.trace-events"
            qemu_log("%d@%zu.%06zu:qmp_exit_x_query_virtio_vhost_queue_status " "%s %d" "\n",
                     qemu_get_thread_id(),
                     (size_t)_now.tv_sec, (size_t)_now.tv_usec
                     , result, succeeded);
#line 275 "trace/trace-qapi_commands_virtio_trace_events.h"
        } else {
#line 10 "qapi/qapi-commands-virtio.trace-events"
            qemu_log("qmp_exit_x_query_virtio_vhost_queue_status " "%s %d" "\n", result, succeeded);
#line 279 "trace/trace-qapi_commands_virtio_trace_events.h"
        }
    }
}

static inline void trace_qmp_exit_x_query_virtio_vhost_queue_status(const char * result, bool succeeded)
{
    if (true) {
        _nocheck__trace_qmp_exit_x_query_virtio_vhost_queue_status(result, succeeded);
    }
}

#define TRACE_QMP_ENTER_X_QUERY_VIRTIO_QUEUE_ELEMENT_BACKEND_DSTATE() ( \
    trace_event_get_state_dynamic_by_id(TRACE_QMP_ENTER_X_QUERY_VIRTIO_QUEUE_ELEMENT) || \
    false)

static inline void _nocheck__trace_qmp_enter_x_query_virtio_queue_element(const char * json)
{
    if (trace_event_get_state(TRACE_QMP_ENTER_X_QUERY_VIRTIO_QUEUE_ELEMENT) && qemu_loglevel_mask(LOG_TRACE)) {
        if (message_with_timestamp) {
            struct timeval _now;
            gettimeofday(&_now, NULL);
#line 11 "qapi/qapi-commands-virtio.trace-events"
            qemu_log("%d@%zu.%06zu:qmp_enter_x_query_virtio_queue_element " "%s" "\n",
                     qemu_get_thread_id(),
                     (size_t)_now.tv_sec, (size_t)_now.tv_usec
                     , json);
#line 306 "trace/trace-qapi_commands_virtio_trace_events.h"
        } else {
#line 11 "qapi/qapi-commands-virtio.trace-events"
            qemu_log("qmp_enter_x_query_virtio_queue_element " "%s" "\n", json);
#line 310 "trace/trace-qapi_commands_virtio_trace_events.h"
        }
    }
}

static inline void trace_qmp_enter_x_query_virtio_queue_element(const char * json)
{
    if (true) {
        _nocheck__trace_qmp_enter_x_query_virtio_queue_element(json);
    }
}

#define TRACE_QMP_EXIT_X_QUERY_VIRTIO_QUEUE_ELEMENT_BACKEND_DSTATE() ( \
    trace_event_get_state_dynamic_by_id(TRACE_QMP_EXIT_X_QUERY_VIRTIO_QUEUE_ELEMENT) || \
    false)

static inline void _nocheck__trace_qmp_exit_x_query_virtio_queue_element(const char * result, bool succeeded)
{
    if (trace_event_get_state(TRACE_QMP_EXIT_X_QUERY_VIRTIO_QUEUE_ELEMENT) && qemu_loglevel_mask(LOG_TRACE)) {
        if (message_with_timestamp) {
            struct timeval _now;
            gettimeofday(&_now, NULL);
#line 12 "qapi/qapi-commands-virtio.trace-events"
            qemu_log("%d@%zu.%06zu:qmp_exit_x_query_virtio_queue_element " "%s %d" "\n",
                     qemu_get_thread_id(),
                     (size_t)_now.tv_sec, (size_t)_now.tv_usec
                     , result, succeeded);
#line 337 "trace/trace-qapi_commands_virtio_trace_events.h"
        } else {
#line 12 "qapi/qapi-commands-virtio.trace-events"
            qemu_log("qmp_exit_x_query_virtio_queue_element " "%s %d" "\n", result, succeeded);
#line 341 "trace/trace-qapi_commands_virtio_trace_events.h"
        }
    }
}

static inline void trace_qmp_exit_x_query_virtio_queue_element(const char * result, bool succeeded)
{
    if (true) {
        _nocheck__trace_qmp_exit_x_query_virtio_queue_element(result, succeeded);
    }
}
#endif /* TRACE_QAPI_COMMANDS_VIRTIO_TRACE_EVENTS_GENERATED_TRACERS_H */
