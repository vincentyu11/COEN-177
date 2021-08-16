//Name: Vincent Yu  
//Date: 03/04/2020
//Title: Lab 9 - Step 1
//Description: This program reads a file from beginning to end with a buffer size of 10000 bytes.


#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]){
    FILE *in;
    char buffer[10000]; //set buffer size to 10000
    in = fopen(argv[1],"rb");
    fread(buffer,sizeof(buffer),1,in);  //read file
    fclose(in);
    return 0;
}