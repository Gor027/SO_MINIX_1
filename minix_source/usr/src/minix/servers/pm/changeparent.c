//
// Created by gor027 on 08.05.2020.
//

#include "pm.h"
#include "mproc.h"
#include "errno.h"

int do_changeparent(void) {
    int parentIndex = mp->mp_parent;

    /* check if it is not init process */
    if (mproc[parentIndex].mp_pid == INIT_PID)
        return EACCES;

    /* check if parent does not wait */
    if (mproc[parentIndex].mp_flags & WAITING)
        return EPERM;

    int grandIndex = mproc[parentIndex].mp_parent;
    mp->mp_parent = grandIndex;

    return 0;
}