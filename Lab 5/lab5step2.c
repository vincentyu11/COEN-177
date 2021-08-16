//Name: Vincent Yu  
//Date: 02/05/2020
//Title: Lab 5 - Step 2 
//Description: This program demonstrates the producer consumer problem using semaphores.


#include <stdio.h>
#include <unistd.h>
#include <pthread.h> 
#include <semaphore.h> 
#include <sys/stat.h>
#include <fcntl.h>

#define n 5

//declare semaphores
sem_t mutex;
sem_t full;
sem_t empty;

typedef int Item;
Item buffer[n];
int in = 0;
int out = 0;

void *producer(void *arg) {
    while (1) {
        //produce next item
        int x = rand()%50 +1;
        sleep(1);

        //lock
        sem_wait(&empty);
        sem_wait(&mutex);

        //add item to buffer
        printf("Added item %d to buffer\n",x);
        buffer[in] = x;
        in = (in+1)%n;

        //unlock
        sem_post(&mutex);
        sem_post(&full);
    }
}


void *consumer(void *arg) {
    while (1) {
        //lock
        sem_wait(&full);
        sem_wait(&mutex);
        
        //remove next item from buffer
        printf("Removed item %d from buffer\n", buffer[out]);
        buffer[out] = 0;
        out = (out+1)%n;

        //unlock
        sem_post(&mutex);
        sem_post(&empty);

        //consume the item
        
    }
}



int main() { 
    //initialize semaphores
    sem_init(&mutex,0,1);
    sem_init(&full,0,0);
    sem_init(&empty,0,n);

    //create threads
    pthread_t p;
    pthread_t c;

    int i;
    for (i=0; i<1; i++) {
        pthread_create(&p, NULL, producer, (void *)(size_t)i);
        pthread_create(&c, NULL, consumer, (void *)(size_t)i);
    }
    for (i=0; i<1; i++) {
        pthread_join(p,NULL);
        pthread_join(c,NULL);
    }

    //destroy semaphores
    sem_destroy(&mutex);
    sem_destroy(&full);
    sem_destroy(&empty);

    return 0;
}


