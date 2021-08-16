//Name: Vincent Yu  
//Date: 03/04/2020
//Title: Lab 9 - Step 2 
//Description: This program reads a file from beginning to end with a command line argument buffer size.



#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]){
    int buffersize = atoi(argv[2]); //set buffer size to command line input
    FILE *in;
    char buffer[buffersize];
    in = fopen(argv[1],"rb");
    fread(buffer,sizeof(buffer),1,in);  //read file
    fclose(in);
    return 0;
}