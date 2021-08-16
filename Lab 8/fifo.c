//Name: Vincent Yu
//Date: 02/26/2020
//Title: Lab 8 FIFO page algorithm
//Description: This C program implements the First in First out page algorithm. It takes
//  a text file of page numbers from the command line and runs the FIFO algorithm with the 
// command line input sized page table. Then it outputs the number of hits, misses (page faults)
//  and the hit rate and miss rate. 

// terminal input: gcc fifo.c -o fifo
//                 cat accesses.txt | ./fifo (10-500)

#include <stdio.h>
#include <stdlib.h>

#define PAGESIZE 10000  //number of values in accesses.txt file

typedef struct {
    int pageno; 
} ref_page;


int main(int argc, char *argv[]) {
    int pagetablesize = atoi(argv[1]);  //command line input for page table size
    ref_page pagetable[pagetablesize];  //creating page table
    char pageCache[PAGESIZE];   //cache to hold test file input
    
    int i;
    int firstin = 0;    //index for page number that was first in
    int match = 0;  //boolean for if a page number is matched / hit
    int hit = 0;    //total hits
    int totalFaults = 0;    //total page faults

    for (i=0; i<pagetablesize; i++) {   //initialize values of page table to -1
        pagetable[i].pageno = -1;
    }

    while (fgets(pageCache, PAGESIZE, stdin)) {
        int page_num = atoi(pageCache);
        printf("%d: ", page_num);

        match = 0;
        for (i=0; i<pagetablesize; i++) {   //loop to find matches and find hits
            if (pagetable[i].pageno == page_num && match == 0) { 
                hit += 1;
                match = 1;
            }   
        }
        if (match == 0) {   //insert page numbers
            pagetable[firstin].pageno = page_num;
            firstin += 1;
        }
        if (firstin > pagetablesize-1) {    //reset firstin to index 0 when reaching end of page table
            firstin = 0;
        }


        //print pagetable
        for (i=0; i<pagetablesize; i++) {
            printf("%d ",pagetable[i].pageno);
        }
        printf("\n");
    }
    
    //print results
    printf("Number of hits: %d \n", hit);
    printf("Number of page faults: %d \n", PAGESIZE-hit);
    printf("Hit rate: %f \n", (double)hit/PAGESIZE);
    printf("Miss rate: %f \n", (double)(PAGESIZE-hit)/PAGESIZE);

    return 0;
}
