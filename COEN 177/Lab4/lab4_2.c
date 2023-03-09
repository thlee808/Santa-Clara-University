// Name: Travis Lee
// Date: 10/14/22 (Friday)
// Title: Lab4 - Step 2
// Description: This is a modified version of the given code for step 1, threadHello.c. The second for
//              loop has been deleted, which had the pthread_join code. Now, this program will output
//              an unknown number of hello statements because the main thread can now terminate whenever.

/**************************************************************
*	threadHello.c - simple multi-threaded program.            *
*   compile with: >gcc -lp threadHello.c -o threadHello       *                                              *
**************************************************************/
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

#define NTHREADS 20

void *go(void *);
pthread_t threads[NTHREADS];

int main() {
    static int i;
    for (i = 0; i < NTHREADS; i++)  
        pthread_create(&threads[i], NULL, go, &i);
    printf("Main thread done.\n");
}
void *go(void *arg) {
    printf("Hello from thread %d with thread ID %d \n", *(int *)arg, (int)pthread_self());
    return (NULL);
}

