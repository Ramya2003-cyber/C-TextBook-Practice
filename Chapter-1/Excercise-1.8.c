#include<stdio.h>
#include<ctype.h>
int main()
{
    int c,b=0,t=0,nl=0;
    printf("Enter some text\n");
    while(c!=EOF)
    {
        c=getchar();
       if(c=='\n')
            nl++;
        else if(c==' ')
           {
               b++;
           }

           else if(c=='\t')
           {
               t++;
           }
    }
    printf("blanks:%d tabs:%d new lines:%d",b,t,nl);
}


