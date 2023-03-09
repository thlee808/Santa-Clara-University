// Name: Travis Lee
// Date: 10/21/22 (Friday)
// Title: Lab 5 step 3
// Description: This program solves the producer - consumer problem using semaphores
//              

//Shared data: semaphore full, empty, mutex;
//pool of n buffers, each can hold one item
//mutex provides mutual exclusion to the buffer pool
//empty and full count the number of empty and full buffers
//Initially: full = 0, empty = n, mutex = 1

#include <stdio.h>
#include <unistd.h>
#include <pthread.h> 
#include <semaphore.h>

//#define NTHREADS 2
#define N 10

struct Item {                           //define what an Item is, using an integer so I can print out something unique
    int myData;
};

//pthread_t threads[NTHREADS];
pthread_t prod_tid, cons_tid;
struct Item buffer[N];
sem_t *full, *empty, *mutex;
int endThreads;                         //use this for the while loops to stop the threads from running forever.

//Producer thread
void* producer(void* arg) {

    int itemCounter = 0;                //will increment to assign different values to items
    int in = 0;
    struct Item pItem;

    do { 
        //produce next item
        pItem.myData = itemCounter;     //assigns a value to Item
        
        //wait for semaphores
        sem_wait(empty);                //if empty is 0, then producer sleeps as there is no empty spaces
        sem_wait(mutex);
        
        //add the item to buffer
        buffer[in] = pItem;
        
        in = (in + 1) % N;              //update in value
        itemCounter++;                  //update itemCounter

        //release semaphores
        sem_post(mutex);
        sem_post(full);                 //signal() or up() increments full

    } while (endThreads == 1);          //use endThreads to stop the function instead of while(1) for the sake of demo

    return (NULL);
}

//Consumer thread
void* consumer(void* arg) {
    int out = 0;
    struct Item cItem;                  //item used to consume the stored items
    do { 
        //get semaphores
        sem_wait(full);                 //if full = 0, then consumer sleeps because there are 0 full spots in buffer
        sem_wait(mutex);
        
        //remove next item from buffer
        cItem = buffer[out];

        out = (out + 1) % N;            //increment out, but also have out wrap around;
        
        //release semaphores
        sem_post(mutex);
        sem_post(empty);
        
        //consume the item by printing the data inside
        printf("The item data, %d, was consumed at index %d \n", cItem.myData, (((out - 1) + N) % N));
        
    } while (endThreads == 1);          //use endThreads to stop the function instead of while(1) for the sake of demo

    return (NULL);
}


int main() {
    //Initially: full = 0, empty = n, mutex = 1
    full = sem_open("full", O_CREAT, 0644, 0);          //initialize full to be 0
    empty = sem_open("empty", O_CREAT, 0644, N);        //initialize empty to be N
    mutex = sem_open("mutex", O_CREAT, 0644, 1);        //initializes mutex as 1

    endThreads = 1;                                     //allows threads to run

    pthread_create(&prod_tid, NULL, producer, NULL);    //create producer thread
    pthread_create(&cons_tid, NULL, consumer, NULL);    //create consumer thread

    usleep(100);                                        //wait 100 microseconds, to have a managable output for demo
    endThreads = 0;                                     //stop the do while loop in the threads

    pthread_join(prod_tid, NULL);
    pthread_join(cons_tid, NULL);

    //delete the semaphores
    sem_unlink("full");                                 //delete full semaphore
    sem_unlink("empty");                                //delete empty semaphore
    sem_unlink("mutex");                                //delete mutex semaphore

    return 0;
}