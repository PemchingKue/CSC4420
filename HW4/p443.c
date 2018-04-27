#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>

int main()
{

    char arr[200], var;
    int var1, var2;
    int temp = 0;

	FILE *value, *outfile;

    value = fopen("test.txt","r");

    if(value == NULL)
	{
        printf("Error opening input file");
    	return 1;
	}
 
    outfile = fopen("Reverse.txt","w");
    if(outfile == NULL)
	{
    	printf("Error opening the output file");
    	return 1;
	}

    while(temp == 0)
	{
    		for(var1=0; var1 < 200; var1++)
		{
        		if((var = fgetc(value)) != EOF)
        		{
			arr[var1] = var;
			var2 = var1;
			}
        		else
        		temp = 1;
		}
	}
for(var1 = var2; var1 >=0; var1--)
{
    fputc(arr[var1],outfile);
}

printf("Done Reversing bytes of a file.\n");
return 0;
}



