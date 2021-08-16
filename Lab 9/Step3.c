//Name: Vincent Yu  
//Date: 03/04/2020
//Title: Lab 9 - Step 3
//Description: This program reads a file from beginning to end and makes a copy of it with a command line argument.


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[]) {
    int buffersize = atoi(argv[2]); //set buffer size to command line input
    size_t n;
    char buffer[buffersize];
    FILE *in, *out;
    in = fopen(argv[1],"rb");
    char *newname = argv[1];
    strcat(newname,".copy");    //create new name for copy of file
    out = fopen(newname, "wb");
    while ((n=fread(buffer,1,buffersize,in)) != 0) {    //read file
        fwrite(buffer,1,n,out); //write file
    }
    fclose(in);
    fclose(out);
    return 0;
}