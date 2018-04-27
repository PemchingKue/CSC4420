#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>

int main(int argc,char* argv[]){
   int fd;
   int m;
   int n;
   int count=1;
   int i;

   char ch;
   char* file;

   if(argc!=4)
       printf("\nIncorrect Parameters, Enter valid set of arguments");
   else{
       m=atoi(argv[1]);
       n=atoi(argv[2]);

       file=(char*)argv[3];
       fd=open(file,O_RDONLY);
       
       if(fd==-1){
           printf("\nCannot open file");
           exit(0);
       }
       while((i=read(fd,&ch,1)>0)){
           
           if((count>=m)&&(count<=n)){
               write(1,&ch,1);
           }
           if(ch=='\n')
               count++;
       }
	close(fd);
   }
return 0;
}
