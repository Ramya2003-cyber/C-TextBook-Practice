#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
int MAXLIM=100;
int main(int argc,char *argv[])
{
    int lim=0;
    int c;
    if(argc==2)
    {
        ++argv;
        int h=strcmp(*argv,"hex");
        int o=strcmp(*argv,"oct");
        while((c=getchar())!=EOF&&lim<MAXLIM)
        {
            if(!isprint(c)&&iscntrl(c))
            {
                if(h==0)
                {
                    printf("%#.2x\n",c);
                  
                }
                else if(o==0)
                {
                    printf("%#.3o\n",c);
                  
                }
                else{
                    exit(0);
                }
                lim += 4;
            }
            else{
                printf("%c",c);
                lim+=1;
            }
        }
    }
}