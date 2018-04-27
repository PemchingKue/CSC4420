#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>

int x;
int c;

int child(){
	FILE *fd;

	fd = fopen("test", "r+");
	fscanf(fd, "%d", &c);
			
	x = c - 5;

	fseek(fd, 0, SEEK_SET); //temporary set number in file NULL
	fprintf(fd, "%s", "      ");//to avoid numbers being replaced incorrectly
						
	fseek(fd, 0, SEEK_SET);
	fprintf(fd, "%d", x);
	fclose(fd);

	return x;
}

int parent(){
	FILE *fd;

	fd = fopen("test", "r+");
	fscanf(fd, "%d", &c);
			
	x = c / 5;
			
	fseek(fd, 0, SEEK_SET); //temporary set number in file NULL
	fprintf(fd, "%s", "      ");//to avoid numbers not being replaced correctly
						
	fseek(fd, 0, SEEK_SET);
	fprintf(fd, "%d", x);
	fclose(fd);

	return x;
}

void resetTXT(){
	FILE *fd;

	fd = fopen("test", "r+");
	fseek(fd, 0, SEEK_SET);
	fprintf(fd, "%d", 19530);
}

int main(){

printf("x = 19530\n\n");
printf("ITERATION 1\n");
pid_t pID;
pid_t pID2;
pid_t pID3;
pid_t pID4;
pid_t pID5;
pID = fork();

		if (pID == -1) // Failed to fork
		{
			perror("Unable to create child process");
			return 1;
		}
		if (pID == 0) // child
		{
			// Code only executed by child process
			printf("Child: x = %d\n" , child());
			sleep(1);
			exit(EXIT_SUCCESS);
		}
		else if (pID > 0)		// parent
		{
			// Code only executed by parent process
			wait(0);		
			printf("Parent: x = %d\n\n" , parent());
			sleep(1);
		}

printf("ITERATION 2\n");
pID2 = fork();

		if (pID2 == -1) // Failed to fork
		{
			perror("Unable to create child process");
			return 1;
		}
		if (pID2 == 0) // child
		{
			// Code only executed by child process
			printf("Child: x = %d\n" , child());
			sleep(1);
			exit(EXIT_SUCCESS);
		}
		else if (pID2 > 0)		// parent
		{
			// Code only executed by parent process
			wait(0);		
			printf("Parent: x = %d\n\n" , parent());
			sleep(1);
		}

printf("ITERATION 3\n");
pID3 = fork();

		if (pID3 == -1) // Failed to fork
		{
			perror("Unable to create child process");
			return 1;
		}
		if (pID3 == 0) // child
		{
			// Code only executed by child process
			printf("Child: x = %d\n" , child());
			sleep(1);
			exit(EXIT_SUCCESS);
		}
		else if (pID3 > 0)		// parent
		{
			// Code only executed by parent process
			wait(0);		
			printf("Parent: x = %d\n\n" , parent());
			sleep(1);
		}

printf("ITERATION 4\n");
pID4 = fork();

		if (pID4 == -1) // Failed to fork
		{
			perror("Unable to create child process");
			return 1;
		}
		if (pID4 == 0) // child
		{
			// Code only executed by child process
			printf("Child: x = %d\n" , child());
			sleep(1);
			exit(EXIT_SUCCESS);
		}
		else if (pID4 > 0)		// parent
		{
			// Code only executed by parent process
			wait(0);		
			printf("Parent: x = %d\n\n" , parent());
			sleep(1);
		}

printf("ITERATION 5\n");
pID5 = fork();

		if (pID5 == -1) // Failed to fork
		{
			perror("Unable to create child process");
			return 1;
		}
		if (pID5 == 0) // child
		{
			// Code only executed by child process
			printf("Child: x = %d\n" , child());
			sleep(1);
			exit(EXIT_SUCCESS);
		}
		else if (pID5 > 0)		// parent
		{
			// Code only executed by parent process
			wait(0);		
			printf("Parent: x = %d\n\n" , parent());
			sleep(1);
		}

resetTXT();

}//main scope


