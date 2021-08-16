//Name: Vincent Yu
//Date: 01/29/2020
//Title: Lab4- Step 3 - 1024x1024 matrix
//Description: This program demonstrates using threads to parallel matrix multiply.
//  This is shown using a 1024x1024 matrix.


#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <stdlib.h>
#include <time.h>

//Matrix sizes
#define SIZE 1024
#define N 1024
#define M 1024
#define L 1024

//Matrices
double matrixA[N][M];
double matrixB[M][L];
double matrixC[N][L];

pthread_t threads[SIZE];

//Function to print matrices
void printMatrix(double matrix[SIZE][SIZE]) {
    int i;
    int j;
    for (i=0; i<SIZE; i++) {
        for (j=0; j<SIZE; j++) {
            printf("%0.1f\t", matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

//Function to fill Matrix A
void fillMatrixA(double matrix[SIZE][SIZE]) {
    int i;
    int j;
    srand(time(NULL));
    for (i=0; i<SIZE; i++) {
        for (j=0; j<SIZE; j++) {
            matrix[i][j] = rand() %10;
        }
    }
}

//Function to fill Matrix B
void fillMatrixB(double matrix[SIZE][SIZE]) {
    int i;
    int j;
    srand(time(NULL));
    for (i=0; i<SIZE; i++) {
        for (j=0; j<SIZE; j++) {
            matrix[i][j] = rand() %5;
        }
    }
}

//Multiplication function
void *go(void* arg) {
    //cast size_t to int
    int i = (int)(size_t)arg;
    int j;
    int k;
    for (j=0; j<L; j++) {
        double temp = 0;
        for (k=0; k<M; k++) {
            //matrix multiplication (row A * column B)
            temp += matrixA[i][k] * matrixB[k][j];
        }
        matrixC[i][j] = temp;
    }
    return (NULL);
}


int main() {
    //fill and display Matrix A and B
    fillMatrixA(matrixA);
    fillMatrixA(matrixB);
    printf("Matrix A: \n");
    printMatrix(matrixA);
    printf("Matrix B: \n");
    printMatrix(matrixB);

    //create a thread for each row of Matrix A to do multiplication
    int i;
    for (i=0; i<SIZE; i++) {
        pthread_create(&threads[i], NULL, go, (void *)(size_t)i);
    }
    //pthread_join to wait for completion of other threads
    for (i=0; i<SIZE; i++) {
        pthread_join(threads[i], NULL);
    }

    //output answer Matrix C
    printf("Matrix C: \n"); 
    printMatrix(matrixC);

    return 0;
}