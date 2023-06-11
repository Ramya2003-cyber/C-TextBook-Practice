#include<stdio.h>
#include<string.h>
void swap(char a[],int b,int c)
{
    char temp=a[b];
    a[b]=a[c];
    a[c]=temp;
}
void reverse(char s[],int begin,int end)
{
    swap(s,begin,end);
    begin++;
    end--;
    if(begin<end)
    reverse(s,begin,end);
}
int main()
{
    char s[]="hi ramya";
    reverse(s,0,strlen(s)-1);
    printf("%s",s);
}