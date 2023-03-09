// Name: Travis Lee
// Date 9/30/22 (Friday)
// Title: Lab2 - Step 7
// Description: Rewriting the program from step 1, but the child process runs the ls command and the
//              parent process will wait until the child process terminates before it exits.

/*Sample C program for Lab assignment 1*/
#include <stdio.h>      /* printf, stderr */
#include <sys/types.h>  /* pid_t */
#include <unistd.h>     /* fork */
#include <stdlib.h>     /* atoi */
#include <errno.h>      /* errno */ 
/* main function with command-line arguments to pass */
int main(int argc, char *argv[]) {
    pid_t  pid;
    int i, n = atoi(argv[1]); // n microseconds to input from keyboard for delay
    printf("\n Before forking.\n");
    pid = fork();
    if (pid == -1) {
        fprintf(stderr, "can't fork, error %d\n", errno);
    }    
    else if (pid == 0){
        //Child process runs ls command
        execlp("/bin/ls", "ls", NULL);
    }
    else{
        wait(NULL);
        printf("Child Complete");
        exit(0);
    }
    return 0;
}