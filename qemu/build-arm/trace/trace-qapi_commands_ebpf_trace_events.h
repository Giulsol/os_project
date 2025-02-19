/* This file is autogenerated by tracetool, do not edit. */

#ifndef TRACE_QAPI_COMMANDS_EBPF_TRACE_EVENTS_GENERATED_TRACERS_H
#define TRACE_QAPI_COMMANDS_EBPF_TRACE_EVENTS_GENERATED_TRACERS_H

#include "trace/control.h"

extern TraceEvent _TRACE_QMP_ENTER_REQUEST_EBPF_EVENT;
extern TraceEvent _TRACE_QMP_EXIT_REQUEST_EBPF_EVENT;
extern uint16_t _TRACE_QMP_ENTER_REQUEST_EBPF_DSTATE;
extern uint16_t _TRACE_QMP_EXIT_REQUEST_EBPF_DSTATE;
#define TRACE_QMP_ENTER_REQUEST_EBPF_ENABLED 1
#define TRACE_QMP_EXIT_REQUEST_EBPF_ENABLED 1
#include "qemu/log-for-trace.h"
#include "qemu/error-report.h"


#define TRACE_QMP_ENTER_REQUEST_EBPF_BACKEND_DSTATE() ( \
    trace_event_get_state_dynamic_by_id(TRACE_QMP_ENTER_REQUEST_EBPF) || \
    false)

static inline void _nocheck__trace_qmp_enter_request_ebpf(const char * json)
{
    if (trace_event_get_state(TRACE_QMP_ENTER_REQUEST_EBPF) && qemu_loglevel_mask(LOG_TRACE)) {
        if (message_with_timestamp) {
            struct timeval _now;
            gettimeofday(&_now, NULL);
#line 3 "qapi/qapi-commands-ebpf.trace-events"
            qemu_log("%d@%zu.%06zu:qmp_enter_request_ebpf " "%s" "\n",
                     qemu_get_thread_id(),
                     (size_t)_now.tv_sec, (size_t)_now.tv_usec
                     , json);
#line 34 "trace/trace-qapi_commands_ebpf_trace_events.h"
        } else {
#line 3 "qapi/qapi-commands-ebpf.trace-events"
            qemu_log("qmp_enter_request_ebpf " "%s" "\n", json);
#line 38 "trace/trace-qapi_commands_ebpf_trace_events.h"
        }
    }
}

static inline void trace_qmp_enter_request_ebpf(const char * json)
{
    if (true) {
        _nocheck__trace_qmp_enter_request_ebpf(json);
    }
}

#define TRACE_QMP_EXIT_REQUEST_EBPF_BACKEND_DSTATE() ( \
    trace_event_get_state_dynamic_by_id(TRACE_QMP_EXIT_REQUEST_EBPF) || \
    false)

static inline void _nocheck__trace_qmp_exit_request_ebpf(const char * result, bool succeeded)
{
    if (trace_event_get_state(TRACE_QMP_EXIT_REQUEST_EBPF) && qemu_loglevel_mask(LOG_TRACE)) {
        if (message_with_timestamp) {
            struct timeval _now;
            gettimeofday(&_now, NULL);
#line 4 "qapi/qapi-commands-ebpf.trace-events"
            qemu_log("%d@%zu.%06zu:qmp_exit_request_ebpf " "%s %d" "\n",
                     qemu_get_thread_id(),
                     (size_t)_now.tv_sec, (size_t)_now.tv_usec
                     , result, succeeded);
#line 65 "trace/trace-qapi_commands_ebpf_trace_events.h"
        } else {
#line 4 "qapi/qapi-commands-ebpf.trace-events"
            qemu_log("qmp_exit_request_ebpf " "%s %d" "\n", result, succeeded);
#line 69 "trace/trace-qapi_commands_ebpf_trace_events.h"
        }
    }
}

static inline void trace_qmp_exit_request_ebpf(const char * result, bool succeeded)
{
    if (true) {
        _nocheck__trace_qmp_exit_request_ebpf(result, succeeded);
    }
}
#endif /* TRACE_QAPI_COMMANDS_EBPF_TRACE_EVENTS_GENERATED_TRACERS_H */
