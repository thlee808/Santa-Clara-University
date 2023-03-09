// Name: Travis Lee
// Date: 10/14/22 (Friday)
// Title: Lab4 - Step 3 part 2
// Description: This program uses threads to copy and update a matrix in parallel. The goal is to double the contents
//              of one matrix and copy it to the other, but also to ensure that the doubling takes place before the
//              copying does. (Modified version of code from Step 3 part 1)

#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

#define N 10
#define M 10
#define L 10

//create matrices as global variables
double matrixA[N][M];
double matrixB[M][L];

//create thread ids as global variables
pthread_t thread1;
pthread_t thread2;

//create lock for spinlock
int lock;

//fill matrices
void fillMatrices(double matrixA[N][M], double matrixB[M][L]);

//print out a matrix
void printMatrix(double matrix[N][M]);

//function to copy matrixA to matrixB, doesn't use any arguements b/c it take advantage of the fact the matrices are global
void *copyMatrixAToMatrixB(void *arg);

//function to double matrixA, doesn't use any arguements b/c it take advantage of the fact the matrices are global
void *doubleValueMatrixA(void *);


int main() {

    fillMatrices(matrixA, matrixB);         //fill matrices

    printf("\n Matrix A at start \n");
    printMatrix(matrixA);                   //show matrix A

    printf("\n Matrix B at start \n");
    printMatrix(matrixB);                   //show maatrix B

    printf("\n start threads \n");

    //set lock to 1 already to use spinlock on copy thread, so double thread goes first.
    lock = 1;

    //create two threads
    pthread_create(&thread1, NULL, copyMatrixAToMatrixB, NULL);
    pthread_create(&thread2, NULL, doubleValueMatrixA, NULL);

    //wait for both threads to finish
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    printf("\n threads are done and printing matrix A \n");

    //print matrix A
    printMatrix(matrixA);

    printf("\n checking matrix B\n");

    printMatrix(matrixB);

    return 0;
}

void fillMatrices(double matrixA[N][M], double matrixB[M][L]) {
    int x = 0;
    for (int i = 0; i < N; i++) {       //fill matrix A with numbers incrementing from 0
        for (int j = 0; j < M; j++) {
            matrixA[i][j] = x++;
        }
    }
    for (int i = 0; i < M; i++) {       //fill matrix B with all 0's
        for (int j = 0; j < L; j++) {
            matrixB[i][j] = 0;
        }
    }
}


void printMatrix(double matrix[N][M]) {    //print a matrix
    for (int i = 0; i < N; i++) {           //loop through each row
        for (int j = 0; j < M; j++) {       //loop through each column in that row
            printf("%f  ", matrix[i][j]);
        }
        printf("\n");
    }
}

void *copyMatrixAToMatrixB(void *arg)
{
    //spinlock for copying matrix to ensure that copying happens after doubling is complete
    while(lock == 1) {      //when lock is taken, wait. 
        printf("copy thread is waiting in spinlock \n");
    }

    for (int i = 0; i < N; i++) {       //loop through matrix A and B
        for (int j = 0; j < M; j++) {
            matrixB[i][j] = matrixA[i][j];  //copy corresponding values
        }
    }
    return (NULL);
}

void *doubleValueMatrixA(void *arg)
{       
    //double function doesn't have the while loop and because we want to ensure that it goes first
    lock = 1;                                       //set lock to 1 just to be sure that double function has the lock
    for (int i = 0; i < N; i++) {                   //loop through matrix
        for (int j = 0; j < M; j++) {
            matrixA[i][j] = 2 * matrixA[i][j];      //double each value
        }
    }
    lock = 0;                                       //release the lock
    return (NULL);
}