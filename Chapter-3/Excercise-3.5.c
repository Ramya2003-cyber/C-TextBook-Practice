#include<stdio.h>
#include <string.h>
void reverse(char a[])
{
    char temp;
    for(int i=0;i<strlen(a)/2;i++)
    {
       // printf("hi");
        temp=a[i];
        a[i]=a[strlen(a)-i-1];
        a[strlen(a)-i-1]=temp;
    }
 }  // printf("%s\n",a);

void itob(int n,char s[],int b)
{
    int r,i=0;
    char d[]={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
    while (n>0)
    {
        r=n%b;
        s[i++]=d[r];
        n=n/b;
    }
    s[i]='\0';
   // printf("%s",s);
    reverse(s);
   
}
int main()
{
 printf("ENter a decimal\n");
 int b,n;
 char a[100];
 scanf("%d",&n);
 printf("ENter a base to convert");
 scanf("%d",&b);
 itob(n,a,b);
 printf("%s",a);
}