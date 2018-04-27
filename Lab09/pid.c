#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
#include<time.h>

pid_t pid;

void alarm_handler(int sig)
{
        printf("%s" , "Time limit exceeded\n");
        kill(pid, 9);
}

    void main(int argc, char *argv[])
    {

       int status = 0;
       int count;

       pid=fork();

       if (pid == -1){
          printf("Forking fail....\n");
       }

       if (pid == 0)
       {
           count = 0;
           while (1) {
             printf("hello %d\n",count);
             count++;
             sleep(1);
           }
       }
       else{
         signal(SIGALRM, alarm_handler);   
         alarm(5);
         while( wait(NULL) > 0 );
       }
    }
