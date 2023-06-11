#include<stdio.h>
#include<string.h>
#define N 10

int main()
{
    int c,i=0,t=0,j,k=0,n;
    char a[100]; 
    while((c=getchar())!=EOF)
    {
        a[i++]=c;
    }
    a[i]='\0';
    i=0;
    n=strlen(a);
    while(i<n)
    {
            k=i+N;
            while(a[k]==' ')
            k--;
            for(int j=0;j<k;j++)
            {
                putchar(a[k+j]);
            }
        
    }

}