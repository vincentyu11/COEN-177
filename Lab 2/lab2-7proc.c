//Name: Vincent Yu
//Date: 01/15/2020  (the day you have lab) 
//Title: Lab2 sample C program - 2 threads
//Description: This is the Lab2 sample C program that creates 7 processes using fork().



/*Sample C program for Lab assignment 2*/
#include <stdio.h>      /* printf, stderr */
#include <sys/types.h>  /* pid_t */
#include <unistd.h>     /* fork */
#include <stdlib.h>     /* atoi */
#include <errno.h>      /* errno */ 
/* main function with command-line arguments to pass */
int main(int argc, char *argv[]) {
pid_t  pid, pid1, pid2, pid3, pid4, pid5;
    int i, n = atoi(argv[1]); // n microseconds to input from keyboard for delay
    printf("\n Before forking.\n");
    pid = fork();
    if (pid == -1) {
        fprintf(stderr, "can't fork, error %d\n", errno);
    }    
    if (pid == 0){
        printf("Child 1. My pid is %d. My parent's pid is %d. \n", getpid(), getppid());
    }
    else{
        printf("Parent. My pid is %d. \n", getpid());
        pid1 = fork();
        if (pid1 == 0) {
            printf("Child 2. My pid is %d. My parent's pid is %d. \n", getpid(), getppid());
        }
	else {
            pid2 = fork();
            if (pid2 == 0) {
                printf("Child 3. My pid is %d. My Parent's pid is %d. \n", getpid(), getppid());
            }
            else {
                pid3 = fork();
                if (pid3 == 0) {
                    printf("Child 4. My pid is %d. My Parent's pid is %d. \n", getpid(), getppid());
                }
		else {
                    pid4 = fork();
                    if (pid4 == 0){
                        printf("Child 5. My pid is %d. My Parent's pid is %d. \n", getpid(), getppid());
                    }
		    else {
                        pid5 = fork();
                        if (pid5 == 0){
                            printf("Child 6. My pid is %d. My Parent's pid is %d. \n", getpid(), getppid());
                        }
                    }
                }
            }
        }
    }
    return 0;
}
