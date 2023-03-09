// Name: Travis Lee
// Date: 10/21/22 (Friday)
// Title: Lab 5 Step 4
// Description: This program uses conditional variables to solve the producer - consumer problem
//              

#include <stdio.h>
#include <unistd.h>
#include <pthread.h> 
#include <semaphore.h>

#define N 10

struct Item {       //define what an Item is, using an integer so I can print out something unique
    int myData;
};

pthread_t prod_tid, cons_tid;           //create pthread ids for producer and consumer threads
struct Item buffer[N];
pthread_mutex_t mutex;                  //create mutex locks
pthread_cond_t full, empty;
int endThreads;                         //use this for the while loops to stop the threads from running forever.
int buffCount;                          //use this to keep track of the number of spaces filled in buffer

//Producer thread
void* producer(void* arg) {

    int itemCounter = 0;                            //will increment to assign different values to items
    int in = 0;
    struct Item pItem;
    do { 
        //produce next item
        pItem.myData = itemCounter;
        
        pthread_mutex_lock(&mutex);

        //while buffer is full
        while (buffCount == N) {                    //when buffCount == N then the buffer is full
            pthread_cond_wait(&empty, &mutex);
        }
        
        //add the item to buffer
        buffer[in] = pItem;
        buffCount++;                                //increment buffCount
        
        in = (in + 1) % N;                          //update in value
        itemCounter++;                              //update itemCounter
        
        pthread_cond_signal(&full);
        pthread_mutex_unlock(&mutex);

    } while (endThreads == 1);                      //use endThreads to stop the function instead of while(1) for the sake of demo

    return (NULL);
}

//Consumer thread
void* consumer(void* arg) {
    int out = 0;
    struct Item cItem;

    do { 
        pthread_mutex_lock(&mutex);

        //while buffer is empty
        while (buffCount == 0) {                    //when buffCount == 0 the buffer is empty
            pthread_cond_wait(&full, &mutex);
        }
        
        //remove next item from buffer
        cItem = buffer[out];
        buffCount--;                                //decrement buffCount

        out = (out + 1) % N;                        //increment out, but also have out wrap around;
        
        pthread_cond_signal(&empty);
        pthread_mutex_unlock(&mutex);
        
        //consume the item
        printf("The item data, %d, was consumed at index %d \n", cItem.myData, (((out - 1) + N) % N));

    } while (endThreads == 1);                      //use endThreads to stop the function instead of while(1) for the sake of demo

    return (NULL);
}

int main() {
    pthread_cond_init(&full, NULL);                     //initialize full conditional variable
    pthread_cond_init(&empty, NULL);                    //initialize empty conditional variable
    pthread_mutex_init(&mutex, NULL);                   //initializes mutex lock

    endThreads = 1;                                     //allows threads to run

    pthread_create(&prod_tid, NULL, producer, NULL);    //create producer thread
    pthread_create(&cons_tid, NULL, consumer, NULL);    //create consumer thread

    usleep(100);                                        //wait 100 microseconds, to have a managable output for demo
    endThreads = 0;                                     //stop the do while loop in the threads

    pthread_join(prod_tid, NULL);
    pthread_join(cons_tid, NULL);

    //delete the mutex lock
    pthread_mutex_destroy(&full);                       //delete full mutex lock
    pthread_mutex_destroy(&empty);                      //delete empty mutex lock
    pthread_mutex_destroy(&mutex);                      //delete mutex mutex lock

    return 0;
}