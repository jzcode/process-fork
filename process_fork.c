/*
Jason Zadwick, Winter 2016.

SUMMARY:
A program in which the main (parent) process calls fork() to create a child process.

CONFIGURATION:
Tested with gcc version 4.8.5 on Red Hat Linux

Example Compilation: gcc -o forkprog fork_prog.c
Example Usage: ./forkprog

REFERENCES:
TANENBAUM, A.S., BOS, H.: "Modern Operating Systems," 4th ed., Upper Saddle River, NJ: Prentice Hall, 2015.
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int main(void){
	pid_t pid, ppid;                               // Variables to store the child (pid) and parent (ppid) process identifiers.
	int status;                                    // Will store the child process' exit status.	

	if((pid=fork()) != 0){                         // The call to fork() from within the body of main().
		if(pid<0) exit(EXIT_FAILURE);          // Check if call to fork() fails to create a child process.
		waitpid(pid, &status, 0);              // Parent process blocked until the child process terminates.
		printf("Within parent; child process ID:\t%ld\n", (long)pid);
	}
	else{
		printf("Within child; parent process ID:\t%ld\n", (long)getppid());
		_Exit(0);                              // Terminate the child process, so the parent process can finish executing.
	}
	printf("Exiting program...\n");
	exit(EXIT_SUCCESS);
}
