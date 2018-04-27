#include <iostream>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
using namespace std;

int main(){

int pid;
pid=getpid();
cout<<"Parent Process ID of Process before termination: " << pid <<endl;
pid=fork();

	if(pid > 0){
	sleep(3);
	cout<<"Parent Process ID of Process after Termination: "<< getppid() <<endl;
	}
	else if(pid < 0)
	{
	cout<<"Process Creation Failed."<<endl;
	exit(0);
	}
	else if(pid==0)
	{
	cout<<"Child Process is Running."<<endl;
	}
	return 0;
}
