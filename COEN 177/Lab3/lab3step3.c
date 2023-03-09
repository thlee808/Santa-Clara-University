// Name: Travis Lee
// Date: 10/8/22 (Friday)
// Title: Lab3 - Step 3
// Description: Modified version of the program from step 2. The writer process now executes the ls command
//				and passes the output to the upstream end of the pipe. 

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
   int count;
   int i;
   pipe(fds);
   
   if (fork()==0){
       dup2(fds[1],1);          //redirects the output of ls from stdout to upstream end of pipe
       close(fds[0]);           //close downstream end
       execlp("ls", "ls", 0);   //run the ls command
       exit(0);
   }
   else if(fork()==0){
       printf("\nReader on the downstream end of the pipe \n");
       close(fds[1]);           //close upstream end
       while((count=read(fds[0],buff,60))>0){
           for(i=0;i<count;i++){
               write(1,buff+i,1);
               write(1," ",1);
           }
           printf("\n");
       }
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
