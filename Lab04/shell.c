#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <string.h>
#include <errno.h>

int makeargv(const char *string, const char *delim, char ***argvp) {

int error;
int tokens;
const char *stringNew;
char *temp;

if ((string == NULL) || (delim == NULL) || (argvp == NULL)) {
errno = EINVAL;
return -1;
}

*argvp = NULL;   
stringNew = string + strspn(string, delim);

if ((temp = malloc(strlen(stringNew) + 1)) == NULL)
{
return -1;
}

strcpy(temp, stringNew);   
tokens = 0;

if (strtok(temp, delim) != NULL)
{
for (tokens = 1; strtok(NULL, delim) != NULL; tokens++);
}

if ((*argvp = malloc((tokens + 1)*sizeof(char *))) == NULL) {
error = errno;
free(temp);
errno = error;
return -1;
}

if (tokens == 0)
{
free(temp);
}
else {
strcpy(temp, stringNew);
**argvp = strtok(temp, delim);
for (int i = 1; i < tokens; i++)
*((*argvp) + i) = strtok(NULL, delim);
}

*((*argvp) + tokens) = NULL;

return tokens;

}

int main ()
{
int PID;
char lineGot[256];
char *cmd;
char **argu;

while(1) {

printf("cmd: ");
fgets(lineGot, 256, stdin); // Get a string from user (includes \n)
cmd = strtok(lineGot, "\n"); // Get the string without the \n

if (strcmp(cmd, "e") == 0 )// loop terminates when "e" is typed
exit (0);

// creates a new process. Parent gets the child’s process ID. Child gets 0.
if ((PID=fork()) > 0)
{
wait(NULL);
}

else if (PID == 0) /*child process*/
{
makeargv(lineGot, " ", &argu);
execvp (argu[0], argu);
/*exec cannot return. If so do the following*/
fprintf (stderr, "Cannot execute %s \n", cmd);
exit(1);
/*exec failed*/
}

else if(PID == -1)
{
fprintf(stderr, "Cannot create a new process \n" );
exit(2);
}
}
}
