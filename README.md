# Concurrent program demonstrating how to create a new process in POSIX.

The main (parent) process calls fork() to create a child process. The parent process then waits for the child process to finish executing and this is shown by the fact
that the child process prints its process identifier (PID) first.