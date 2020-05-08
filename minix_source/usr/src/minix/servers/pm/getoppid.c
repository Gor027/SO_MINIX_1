//
// Created by gor027 on 08.05.2020.
//

#include "pm.h"
#include "mproc.h"

int do_getoppid(void) {
    pid_t inPid = (pid_t) m_in.m1_i1;
    int found = 0;
    pid_t originalParent = 0;

    for (int i = 0; i < NR_PROCS; i++) {
        if (mproc[i].mp_pid == inPid) {
            found = 1;
            originalParent = mproc[i].original_parent;
            break;
        }
    }

    if (found == 0) {
        return EINVAL;
    }

    mp->mp_reply.m2_i1 = originalParent;

    return 0;
}