//Name: Vincent Yu
//Date: 01/22/2020
//Title: Lab1 - Step 5
//Description: This program simulates the producer and consumer problem using pipes.


/**************************
*	pipe()
**************************/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h> 
#include <sys/wait.h> 

int buffersize = 10;

void producer(int fds) {
    int i;
    for (i=0; i<buffersize; i++) {
        write(fds, &i, sizeof i);
        printf("Produced %d\n",i);
    }
    exit(0);
}

void consumer(int fds) {
    int i;
    int var;
    while((var = read(fds, &i, sizeof i)) >0) {
        printf("Consumed %d\n",i);
    }
    exit(0);
}

//main
int main() {
 	int fds[2];
 	pipe(fds);
	if (fork()== 0) {
		close(fds[1]);
        consumer(fds[0]);
	}
	else if (fork() == 0) {
		close(fds[0]);
        producer(fds[1]);
	}
	else {
		close(fds[0]);
		close(fds[1]);
		wait(0);
		wait(0); 
	}
} 
