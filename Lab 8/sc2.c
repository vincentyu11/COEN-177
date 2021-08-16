//Name: Vincent Yu
//Date: 02/26/2020
//Title: Lab 8 Second Change page algorithm
//Description: This C program implements the Second Chance page algorithm. It takes
//  a text file of page numbers from the command line and runs the SC algorithm with the 
// command line input sized page table. Then it outputs the number of hits, misses (page faults)
//  and the hit rate and miss rate. 

// terminal input: gcc sc.c -o sc
//                 cat accesses.txt | ./sc (10-500)

#include <stdio.h>
#include <stdlib.h>

#define PAGESIZE 10000  //number of values in accesses.txt file

typedef struct {
    int pageno;
    int scbit;
} ref_page;


int main(int argc, char *argv[]) {
    int pagetablesize = atoi(argv[1]);  //command line input for page table size
    ref_page pagetable[pagetablesize];  //creating page table
    char pageCache[PAGESIZE];   //cache to hold test file input
    
    int i;
    int match = 0;  //boolean for if a page number is matched / hit
    int hit = 0;    //total hits
    int totalFaults = 0;    //total page faults
    int index = 0;     //index for second chance bit

    for (i=0; i<pagetablesize; i++) {   //initialize values of page table to -1
        pagetable[i].pageno = -1;
        pagetable[i].scbit = 0;
    }

    while (fgets(pageCache, PAGESIZE, stdin)) {
        int page_num = atoi(pageCache);
        printf("%d: ", page_num);

        match = 0;
        for (i=0; i<pagetablesize; i++) {   //loop to find matches and find hits
            if (pagetable[i].pageno == page_num && match == 0) { 
                hit += 1;
                match = 1;
                pagetable[i].scbit = 1;
                break;
            }   
        }

        if (match == 0) {   //insert page numbers
            for (i=0; i<pagetablesize; i++) {
                if (pagetable[index].scbit == 0) {
                    break;
                }
                else {
                    pagetable[index].scbit = 0;
                    index +=1;
                    if (index == pagetablesize) {
                        index = 0;
                    }
                }  
            }
            pagetable[index].pageno = page_num;
            index += 1;
            if (index == pagetablesize) {
                index = 0;
            }
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
