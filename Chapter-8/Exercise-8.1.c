#include <stdio.h>
#include <fcntl.h>
#include<string.h>
//#include "syscalls.h"
int MAXLINE=10,i=0;
#define PERMS 0666 /* RW for owner, group, others */
void error(char *, ...);
void itoa(int d, char b[])
{
    while (d != 0)
    {
        b[i++] = d % 10 + '0';
        d /= 10;
    }
    strrev(b);
}
void print_file(char *file)
{
    char c;
    int fp=open(file,O_RDONLY,0);
    static int line = 1, page = 0;

    write(1,"\n-----NEW FILE------\n",21);
    write(1,"TITLE:",6);
    write(1,file,strlen(file));
    page++;
    write(1,"\nPage-",6);
    char a[3];
    itoa(page,a);
    i=0;
    write(1,a,strlen(a));
    write(1,"\n",1);
    while(read(fp,&c,1)>0)
    {
        if (c == '\n')
            line++;
        if (line % MAXLINE == 0)
        {
            line++;
            page++;
            write(1, "\nPage-", 6);
            itoa(page, a);
            i=0;
            write(1, a, strlen(a));
            write(1, "\n", 1);
        }
        write(1,&c,1);
    }
}
int main(int argc, char *argv[])
    {
        while (argc-- != 1)
        {
            print_file(*++argv);
        }
    }