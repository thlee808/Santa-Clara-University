// Name: Travis Lee
// Date 9/30/22 (Friday)
// Title: Lab2 - Step 5
// Description: This code creates 7 processes including the initial program. These processes may either have
//              two children or no children at all

#include <stdio.h>      /* printf, stderr */
#include <sys/types.h>  /* pid_t */
#include <unistd.h>     /* fork */
#include <errno.h>      /* errno */ 

//Initial program will have two child processes, which one child will have two child processes (grandchild processes) and the other child
//process will have no children. One of the granchild processes will have two child processes (great granchild processes).
//in all there will be 1 parent process, 2 children processes, 2 grandchildren processes, and 2 great grandchildren processes

int main(void) {
    pid_t pid1, pid2;
    int wait = 0;       //use this to keep the child from getting ahead of the parent process, when parent process creates second child process


    pid1 = fork( );       //create first child process
    if (pid1 == -1) {    //check if first child process was created
        fprintf(stderr, "can't fork, error %d\n", errno);
    }

    pid2 = fork( );      //create second child process from the initial program and grandchild process from first child process
    if (pid2 == -1) {    //check if second fork was successful
        fprintf(stderr, "can't fork, error %d\n", errno);
    }


    if (pid1 == 0 && pid2 > 0) {     //identifying the first child process, child of initial program
        pid1 = fork( );       //create second grandchild process
        if (pid1 == -1) {    //check if second grandchild process was created
            fprintf(stderr, "can't fork, error %d\n", errno);
        }
    }

    if (pid1 == 0 && (!pid2)) {    //identifying the second grandchild process, child of first child process
        pid2 = fork( );          //create a great grand child process
        if (pid2 == -1) {       //check if fork was successful
            fprintf(stderr, "can't fork, error %d\n", errno);
        }

        if(pid2 > 0) {          //assuming that the grandchild who just got a child process has a pid2 value greater than 0 now
            pid1 = fork( );          //create a great grand child process
            if (pid2 == -1) {       //check if fork was successful
                fprintf(stderr, "can't fork, error %d\n", errno);
            }
        }
    }

    printf("Hello \n");     //each process will print a hello, so expecting 7 hello's

}