#include<stdio.h>
static int i = 0;
void iota(int a,char *b)
{
 
    if(a<0)
    {
        b[i++]='-';
        a=-a;
    }
    if(a/10)
    {
        iota(a/10,b);
    }
    b[i++]=a%10+'0';
}
int main()
{
    int a=34;
    char b[20];
    iota(a,b);
    b[i]='\0';
    printf("%s",b);
}