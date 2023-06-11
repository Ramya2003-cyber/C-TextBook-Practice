#include<stdio.h>
int main()
{
    char s[100];
    int lim=10,c;
    int i;
    for( i=0;i<lim-1;)
    {
       if((c=getchar())!='\n')
       {
           if(c!=EOF)
           {
               s[i]=c;
               i++;
           }
            else{
           break;
       }
       }
       else{
           break;
       }
    }
    s[i]='\0';
    printf("%s",s);
}