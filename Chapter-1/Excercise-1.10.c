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
       if(c=='\t')
       {
           printf("\\t");
           
       }       
       else if(c=='\\')
       {
            printf("\\\\");
       }
       else if(c=='\b')
       {
           printf("\\b");
       }
       else{
           putchar(c);
       }

    }
    
}
