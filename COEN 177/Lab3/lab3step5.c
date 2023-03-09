// Name: Travis Lee
// Date: 10/8/22 (Friday)
// Title: Lab3 - Step 5
// Description: This program implements the producer-consumer message communication
//              using pipes

/**************************
*   Lab3 - pipe()
**************************/
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h> 
#include <string.h>
#include <sys/wait.h> 

// main
int main(int argc,char *argv[]){
    int  fds[2];
    char buff[60];
    char printBuff[60];
    char sharedBuff[60];
    pipe(fds);
    
    printf("Message for producer: ");
    fgets(buff, sizeof(buff), stdin);                       //takes in message from user and stores in buffer
    if (fork()==0){                         //producer
        close(fds[0]);                                      //close downstream end
        write(fds[1], buff, sizeof(buff));                  //takes message from buffer into upstream end of pipe
        exit(0);   
    }
    if (fork()==0){                         //consumer
        close(fds[1]);                                      //close upstream end
        read(fds[0], printBuff, sizeof(printBuff));         //takes message from downstream end of pipe into another buffer
        printf("Message consumed    : %s", printBuff);      //print out message
        exit(0);
    }
    else{     
        close(fds[0]);
        close(fds[1]);
        wait(0);
        wait(0);
    }
return 0;
}