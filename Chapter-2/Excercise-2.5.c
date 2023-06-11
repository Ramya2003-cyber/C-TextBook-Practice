#include<stdio.h>
#include<string.h>
int any(char s1[],char s2[])
{
int c;
    for(int i=0;i<strlen(s1);i++){
        for(int  j=0;j<strlen(s2);j++)
        {
            if(s1[i]==s2[j])
            {
                return i;
            }
        }
    }
return -1;
}
int main()
{
 char s1[100],s2[100];
 printf("ENter string1:");
 gets(s1);
 printf("ENter string2:");
 gets(s2);
 int p=any(s1,s2);
 printf("The first occurence is at %d",p+1);
}