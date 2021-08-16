//Name: Vincent Yu
//Date: 01/15/2020  (the day you have lab) 
//Title: Lab2 sample C program
//Description: This is the Lab2 sample C program that was compiled 
//in the terminal wiht 'gcc lab2.c -o ExecutableName'  and ran with 
//'./ExecutableName' , './ExecutableName 3000' , './ExecutableName 500' 
//and './ExecutableName 5000' 
//The program displays the Parent and Child processes from 0-99.


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
    if (pid){
        // Parent process
        for (i=0;i<100;i++) {
            printf("\t \t \t Parent Process %d \n",i);
            usleep(n);
        }
    }
    else{
        // Child process
        for (i=0;i<100;i++) {
            printf("Child process %d\n",i);
            usleep(n);
        }
    }
    return 0;
}
