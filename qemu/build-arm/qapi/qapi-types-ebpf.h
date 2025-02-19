/* AUTOMATICALLY GENERATED by qapi-gen.py DO NOT MODIFY */

/*
 * Schema-defined QAPI types
 *
 * Copyright IBM, Corp. 2011
 * Copyright (c) 2013-2018 Red Hat Inc.
 *
 * This work is licensed under the terms of the GNU LGPL, version 2.1 or later.
 * See the COPYING.LIB file in the top-level directory.
 */

#ifndef QAPI_TYPES_EBPF_H
#define QAPI_TYPES_EBPF_H

#include "qapi/qapi-builtin-types.h"

#if defined(CONFIG_EBPF)
typedef struct EbpfObject EbpfObject;
#endif /* defined(CONFIG_EBPF) */

#if defined(CONFIG_EBPF)
typedef enum EbpfProgramID {
    EBPF_PROGRAMID_RSS,
    EBPF_PROGRAMID__MAX,
} EbpfProgramID;

#define EbpfProgramID_str(val) \
    qapi_enum_lookup(&EbpfProgramID_lookup, (val))

extern const QEnumLookup EbpfProgramID_lookup;
#endif /* defined(CONFIG_EBPF) */

#if defined(CONFIG_EBPF)
typedef struct q_obj_request_ebpf_arg q_obj_request_ebpf_arg;
#endif /* defined(CONFIG_EBPF) */

#if defined(CONFIG_EBPF)
struct EbpfObject {
    char *object;
};
#endif /* defined(CONFIG_EBPF) */

#if defined(CONFIG_EBPF)
void qapi_free_EbpfObject(EbpfObject *obj);
G_DEFINE_AUTOPTR_CLEANUP_FUNC(EbpfObject, qapi_free_EbpfObject)
#endif /* defined(CONFIG_EBPF) */

#if defined(CONFIG_EBPF)
struct q_obj_request_ebpf_arg {
    EbpfProgramID id;
};
#endif /* defined(CONFIG_EBPF) */

#endif /* QAPI_TYPES_EBPF_H */
