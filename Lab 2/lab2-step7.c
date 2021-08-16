//Name: Vincent Yu
//Date: 01/15/2020  (the day you have lab) 
//Title: Lab2 sample C program
//Description: This is the Lab2 sample C program with step 7, which is rewriting the program so that the child process runs the ls command, and the parent process will wait until the child process finishing before it exits.


/*Sample C program for Lab assignment 2*/
#include <stdio.h>      /* printf, stderr */
#include <sys/types.h>  /* pid_t */
#include <unistd.h>     /* fork */
#include <stdlib.h>     /* atoi */
#include <errno.h>      /* errno */ 
/* main function with command-line arguments to pass */
int main(int argc, char *argv[]) {
    pid_t  pid;
    int i, n = atoi(argv[1]); // n microseconds to input from keyboard for delay
    printf("\n Before forking.\n");
    pid = fork();
    if (pid == -1) {
        fprintf(stderr, "can't fork, error %d\n", errno);
    }    
    else if (pid == 0) {
        execlp("/bin/ls", "ls", NULL);

    }
    else {
        wait(NULL);
	    printf("Child Complete \n");
        exit(0);
    }
    return 0;
}
