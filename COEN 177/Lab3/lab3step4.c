// Name: Travis Lee
// Date: 10/8/22 (Friday)
// Title: Lab3 - Step 4
// Description: This program implements the shell command "cat /etc/paswd | grep root"

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
   int fds[2];
   pipe(fds);
   
   if (fork()==0){
       dup2(fds[0], 0);                             //send downstream data to stdin
       close(fds[1]);                               //close upstream end
       execlp("grep", "grep", "root", 0);           //run the command "grep root"
       exit(0);
   }
   else if (fork()==0){
       dup2(fds[1], 1);                             //send
       close(fds[0]);
       execlp("cat", "cat", "/etc/passwd", 0);      //run the command "cat /etc/passwd"
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