//Name: Vincent Yu
//Date: 02/26/2020
//Title: Lab 8 LRU page algorithm
//Description: This C program implements the Least Recently Used page algorithm. It takes
//  a text file of page numbers from the command line and runs the LRU algorithm with the
// command line input sized page table. Then it outputs the number of hits, misses (page faults)
//  and the hit rate and miss rate. 

// terminal input: gcc lru.c -o lru
//                 cat accesses.txt | ./lru (10-500)

#include <stdio.h>
#include <stdlib.h>

#define PAGESIZE 10000

typedef struct {
    int pageno;
    int lru;
} ref_page;


//copy pagetable array with LRU indexes. then add one (+=1) for each addition for pagetable
//find leas/greatest number in new array to find LRU


int main(int argc, char *argv[]) {
    int pagetablesize = atoi(argv[1]);  //command line input for page table size
    ref_page pagetable[pagetablesize];  //creating page table
    char pageCache[PAGESIZE];   //cache to hold test file input

    
    int i;
    int match = 0;  //boolean for if a page number is matched / hit
    int hit = 0;    //total hits
    int totalFaults = 0;    //total page faults

    for (i=0; i<pagetablesize; i++) {   //initialize values of page table to -1
        pagetable[i].pageno = -1;
        pagetable[i].lru = pagetablesize - i;
    }
    

    while (fgets(pageCache, PAGESIZE, stdin)) {
        int page_num = atoi(pageCache);
        printf("%d: ", page_num);

        match = 0;
        for (i=0; i<pagetablesize; i++) {   //loop to find matches and find hits 
            if (pagetable[i].pageno == page_num && match == 0) {
                hit += 1;
                match = 1;
                pagetable[i].lru = 0;   //set lru to 0 if match is found
                int j;
                for (j=0; j<pagetablesize; j++) {
                    if (pagetable[j].lru != -1) {   //shift all lru in preparation for next page number
                        pagetable[j].lru += 1;
                    }
                }
            }   
        }
        
        int largest = pagetable[0].lru;
        int index_largest = 0;
        if (match == 0) {
            for (i=0; i<pagetablesize; i++) {   //find largest lru value
                if (largest < pagetable[i].lru) {
                    largest = pagetable[i].lru;
                    index_largest = i;  //get the index for largest lru value
                }
            }
            pagetable[index_largest].pageno = page_num; //use index for largest lru to place page number
            pagetable[index_largest].lru = 0;
            int j;
            for (j=0; j<pagetablesize; j++) {   //shift all lru in preparation for next page number
                pagetable[j].lru += 1;
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
