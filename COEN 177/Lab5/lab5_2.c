// Name: Travis Lee
// Date: 10/21/22 (Friday)
// Title: Lab 5 Step 2
// Description: This program uses mutex locks to provide synchronization to the threads as they
//              print when they enter their critical region and when they return

// Thread Sychronization
//To compile this code:
//If using the SCU Linux lab first add #include<fcntl.h>
//Then you're ready to compile.
//To compile just add -lpthread to your gcc command like:
//gcc threadSync.c -lpthread
//gcc threadSync.c -o test -lpthread


#include <stdio.h>
#include <unistd.h>
#include <pthread.h> 
#include <semaphore.h> 

#define NTHREADS 10

pthread_t threads[NTHREADS];
pthread_mutex_t lock;                           //declare a mutex lock

void* go(void* arg) { 
    pthread_mutex_lock(&lock);                  //acquire mutex lock to enter critical section
    printf("Thread %d Entered Critical Section..\n", (int)arg); //critical section 
        sleep(1); 
    pthread_mutex_unlock(&lock);                //release mutex lock to exit critical section 
    return (NULL);
} 

int main() { 
    pthread_mutex_init(&lock, NULL);            //create a mutex lock
    static int i;
    for (i = 0; i < NTHREADS; i++){
        pthread_create(&threads[i], NULL, go, (void *)(size_t)i);
    }
    for (i = 0; i < NTHREADS; i++) {
        pthread_join(threads[i],NULL);
        printf("\t\t\tThread %d returned \n", i);
    }
    printf("Main thread done.\n");
    pthread_mutex_destroy(&lock);               //delete mutex lock
    return 0; 
} 
