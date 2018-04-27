#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>

int main(int argc,char* argv[]){
   int fd;
   int count=1;
   int i;

   char ch;
   char* file;

   if(argc!=2)
       printf("\n Incorrect parameters, Enter valid set of arguments");
   else{
       file=(char*)argv[1];
       fd=open(file,O_RDONLY);

       if(fd==-1){
           printf("\nCannot open file");
           exit(0);
       }

       while((i=read(fd,&ch,1) > 0)){
           write(1,&ch,1);
           if(ch=='\n')
               count++;
       }
	close(fd);
   }
return 0;
}
