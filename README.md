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

## Further Notices

The CMakeLists.txt is added in order to open the project in and IDE, e.g. CLion, which will index the files and make easier to add or modify code. 

There are big and small tests, where big tests should be used according to the instruction in README.md, but the small test cases need to be copied to virtual machine running Minix and do the following:
`make example` if the name of the file containing the test is example.c, then

`./example` to run the test case and see the output.

The big tests are copied and modified version of Antoni's tests:
 https://github.com/azewierzejew/SO_3_testy
 
The CMakeLists.txt is made with the help of "fake" executable and adding all the headers and executables.

` SOURCES=$(find . | grep -E ".*\.(h|hh|cc|c)$" | sed '$!s/$/ /') && echo "add_executable(arbabik $SOURCES)" `

Run the above code in the source directory and append to a standard CMakeLists.txt to add executable.

### Some staff in tests may be in Polish as this is a project from Operating Systems course in Warsaw Univeristy MIM Faculty.
