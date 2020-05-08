# SO_MINIX_1
Adding system calls to Minix 3 Process Manager (PM) server.

## Main Task 
The task is to add two new system calls:

`PM_CHANGE_PARENT` with library function `int changeparent()`

and

`PM_GETOPPID` with library function `pid_t getoppid(pid_t pid)`.

Library functions should be declared in a file unistd.h.

## Change of parent
The function `PM_CHANGE_PARENT` changes the parent of the process that called the function to his "grandfather", i.e. the parent of the existing parent, provided that

the current parent is not the process `init` and
the parent does not wait for the child to finish, i.e. does not perform the function wait().
If these conditions are not met, then the parent remains unchanged.

The function `changeparent()` passes 0 if the parent has changed and -1 if it fails. If the parent of the process is `init`, then the function sets errnoto `EACCES`, and if the parent is waiting for the child to finish, then to `EPERM`.

## The original parent
`PM_GETOPPID` As a result, the function passes the ID of the original parent for the given process.

If the process did not change the parent, then the original parent is the current parent. Even if the process changed the parent many times, the original parent remains unchanged.

`getoppid(pid_t pid)` As a result, the function passes the ID of the original parent of the process with the ID pid, if the parent is still running, otherwise it passes 0.

If the process specified pid does not exist, the function passes −1 in the result and sets it errnoto EINVAL.
