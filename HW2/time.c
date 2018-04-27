#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <time.h>
#include <sys/times.h>

time_t currTime;
clock_t time1;
clock_t time2;
int PID;
double timec = 0;

void test(){

    PID = fork();

    if(PID != 0){
	time1 = clock();
	}
	printf("Testing\n");
}

int main () {

     time(&currTime);
     printf("Parent process started at %s", ctime(&currTime));
     test();

     if (PID != 0) {
         time2 = clock();
         timec = (time2 - time1);
     	}

     if (PID != 0){
         printf("The time taken by program is %f sec\n", timec / CLOCKS_PER_SEC);
	}

 }
