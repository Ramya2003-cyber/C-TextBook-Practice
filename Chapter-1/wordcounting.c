#include<stdio.h>
#include<ctype.h>
int main()
{
    int c,l=0,w=0,li=0;
    printf("Enter some text\n");
    while(c!=EOF)
    {
        c=getchar();
       if(c=='\n')
            li++;
        else if(c==' '||c=='\n'||c=='\t')
            w++;
        else 
            l++;
    }
    printf("letters:%d words:%d lines:%d",l,w,li);
}


