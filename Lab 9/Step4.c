//Name: Vincent Yu  
//Date: 03/04/2020
//Title: Lab 9 - Step 4
//Description: This program reads a file from beginning to end and makes a copy depending on the number of threads. 
//The number of threads and buffer size are from command line input

//gcc Step4.c -o Step4 -lpthread

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>


struct file {   //struct to pass as parameter into thread
    int bufsize;
    int threadnum;
    char* filename;
};

void *go(void *arg) {
    int go_buffersize = ((struct file*)arg)->bufsize;
    int go_threadnum = ((struct file*)arg)->threadnum;
    char *go_filename = ((struct file*)arg)->filename;

    char *fnamenew = malloc(strlen(go_filename)+1);
    strcpy(fnamenew,go_filename);
    strcat(fnamenew,".t");  //new name for copy of files
    char k[1];
    sprintf(k,"%d",go_threadnum+1);
    strcat(fnamenew,k);
    
    size_t n;
    char buffer[go_buffersize];
    FILE *in, *out;
    in = fopen(go_filename,"rb");
    out = fopen(fnamenew, "wb");
    while ((n=fread(buffer,1,go_buffersize,in)) != 0) { //read file
        fwrite(buffer,1,n,out); //write file
    }
    fclose(in);
    fclose(out);
    return NULL;
}


int main(int argc, char* argv[]) {
    
    int NTHREADS = atoi(argv[3]);   //number of threads from command line input
    int buffersize = atoi(argv[2]); //buffer size from command line input
    char *fname = argv[1];  //file name from command line input
    pthread_t threads[NTHREADS];
    int i;

    for (i = 0; i < NTHREADS; i++) {
        struct file *input = (struct file *)malloc(sizeof(struct file));   //make a struct for each file to be read and copied
        input->bufsize = buffersize;    
        input->threadnum = i;
        input->filename = fname;
        pthread_create(&threads[i], NULL, go, (void *)input);   //create thread
    }
    for (i = 0; i < NTHREADS; i++) {
        pthread_join(threads[i],NULL);  //join threads
    }

    return 0;
}