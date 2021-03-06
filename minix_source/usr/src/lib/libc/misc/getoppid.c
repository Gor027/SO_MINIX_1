//
// Created by gor027 on 08.05.2020.
//

#include <lib.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <minix/rs.h>

int get_pm_endpt(endpoint_t * );

pid_t getoppid(pid_t pid) {
    endpoint_t pm_pt;
    message m;
    if (get_pm_endpt(&pm_pt) != 0)
    {
        errno = ENOSYS;
        return -1;
    }

    m.m1_i1 = pid;
    int result = (_syscall(pm_pt, PM_GETOPPID, &m));

    if (result != 0)
        return -1;
    else
        return m.m2_i1;
}