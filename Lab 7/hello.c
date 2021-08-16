#include <stdio.h>
#include <unistd.h>

int main(void) {  
    int i; 
    for (i=0;i<1000000;i++){
        printf("abc123");
    }
    return 0; 
} 
