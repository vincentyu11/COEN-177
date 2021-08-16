//Name: Vincent Yu
//Date: 01/15/2020  (the day you have lab) 
//Title: Lab2 sample C program
//Description: This is the Lab2 sample C program that is edited to use 2 threads instead of 2 processes.


/*Sample C program for Lab assignment 2*/
#include <stdio.h>      /* printf, stderr */
#include <sys/types.h>  /* pid_t */
#include <unistd.h>     /* fork */
#include <stdlib.h>     /* atoi */
#include <errno.h>      /* errno */
#include <pthread.h> 
/* main function with command-line arguments to pass */

void *threadPrint(void *threadid) {
    int i;
    for (i=0; i<100; i++) {
      printf("Thread %d \n", i);
    }
    pthread_exit(NULL);
}


int main(int argc, char *argv[]) {
    
    pthread_t threads[2];
    int thread;
    int i;
    for (i=0; i<2; i++) {
      pthread_create(&threads[i], NULL, threadPrint, NULL);
    }
    for (i=0; i<2; i++) {
      pthread_join(threads[i],NULL);
    }

    pthread_exit(NULL);

    return 0;
}
