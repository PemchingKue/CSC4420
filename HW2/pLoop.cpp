#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
using namespace std;

int main ()
{
	int processID;
	
	processID = getpid();
	cout<< "New Process ID = " << processID <<endl;
	
	while(1)
	{
	cout<< "Forking \t Process ID = " << processID <<endl;
		
	cout<< "Process ID = " << getpid() << " got Fork " << fork() <<endl;
	}

	return 0;

}

