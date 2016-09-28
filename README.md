# Concurrent program in the C99 language specification demonstrating how to fork a child process in POSIX.

## *./process_fork.c* explained
The main process, which is also the parent process, calls fork() to create a child process. The parent process then waits for the child process
to finish executing instructions which are to print its process identifier (PID) before the parent does as well.

## A note on the inspiration for this project
A great operating systems professor, class, and class project collaboration in 2016!!!