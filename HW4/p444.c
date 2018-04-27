#include <dirent.h>
#include <sys/stat.h>
#include <stdio.h>

long int findSize(const char *file_name)
{
    struct stat st;
    if(stat(file_name,&st)==0)
    {
        return (st.st_size);
    }
    else
    {
        return -1;
    }

}



int main()
{

    DIR *d;
    int i=0;
    long int arr[10000];

    struct dirent *dir;
    d = opendir(".");

    if (d)
    {
        while ((dir = readdir(d)) != NULL)
        {
            printf("%s \t %ld\n",dir->d_name,findSize(dir->d_name));
        }
        closedir(d);
    }

    return(0);

}
