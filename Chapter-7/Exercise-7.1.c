#include<stdio.h>
#include<string.h>
void gettext1(char *a,int lim)
{
    char *temp;
    temp=a;
    int c;
    int i=0;
    while((c=getchar())!=EOF&&i<100)
    {
        *temp=c;
        temp++;
        i++;
    }
    *temp='\0';
}
void utol(char a[])
{
    int l = strlen(a);
    int i = 0;
    while (i < l)
    {
        if (a[i] <= 'Z' && a[i] >= 'A')
        {
            a[i] += 32;
        }
        i++;
    }
}
void ltou(char a[])
{
    int l=strlen(a);
    int i=0;
    while (i<l)
    {
        if(a[i]<='z'&&a[i]>='a')
        {
            a[i]-=32;
        }
        i++;
    }
    

}
void printtext(char *a)
{
    while(*a!='\0')
    {
        putchar(*a);
        a++;
    }
}
int main(int argc,char *argv[])
{
    char a[100];

    if(argc==2)
    {
        gettext1(a, 100);
        ++argv;
        if(strcmp(*argv,"UTOL")==0)
        {
           utol(a);
        }
        else if (strcmp(*argv, "LTOU")==0)
        {

            ltou(a);
        }
        printtext(a);
    }
}