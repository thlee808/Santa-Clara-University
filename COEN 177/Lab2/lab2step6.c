// Name: Travis Lee
// Date 9/30/22 (Friday)
// Title: Lab2 - Step 6
// Description: I am rewriting the program from step 1 with two threads instead of processes

/*Sample C program for Lab assignment 1*/
#include <stdio.h>      /* printf, stderr */
#include <sys/types.h>  /* pid_t */
#include <unistd.h>     /* fork */
#include <stdlib.h>     /* atoi */
#include <errno.h>      /* errno */ 
#include <pthread.h>

void* parentFunc(int n);
void* childFunc(int n);

/* main function with command-line arguments to pass */
int main(int argc, char *argv[]) {
    pthread_t  thread_id1, thread_id2;
    int i, n = atoi(argv[1]); // n microseconds to input from keyboard for delay
    printf("\n Before forking.\n");
    
    pthread_create(&thread_id1, NULL, parentFunc, (void *)n);
    pthread_create(&thread_id2, NULL, childFunc, (void *)n);
    
    pthread_join(thread_id1, NULL);
    pthread_join(thread_id2, NULL);

    pthread_exit(NULL);
    return 0;
}

void* parentFunc(int n){
    int i;
    for (i=0;i<100;i++) {
        printf("\t \t \t Parent Process %d \n",i);
        usleep(n);
    }
}

void* childFunc(int n){
    int i;
    for (i=0;i<100;i++) {
        printf("Child process %d\n",i);
        usleep(n);
    }
}