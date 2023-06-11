#include<stdio.h>
#include<ctype.h>
#include<string.h>
int main()
{
    int c;

    printf("Enter some text\n");
    int i=0;
    while(c!=EOF)
    {
        c=getchar();
       // in[i++]=c;
       if(c!=' ')
       {
           putchar(c);
           i=0;
       }       
       else if(c==' ' && i==0)
       {
              putchar(c);
              i++;
       }

    }
    printf("END\n");
    
}

