#include<stdio.h>
#include<string.h>
void squeeze(char s1[],char s2[])
{
    int k=0,j,i;
    for( i=0;i<strlen(s1);i++)
    {
        for( j=0;j<strlen(s2);j++)
        {
            if(s2[j]==s1[i])
            {
                break;
            }
        }
        if(j==strlen(s2))
        {
            s1[k++]=s1[i];
        }
    }
    s1[k]='\0';
}
int main()
{
char s1[100],s2[100];
 printf("ENter string1:");
 gets(s1);
 printf("ENter string2:");
 gets(s2);
 squeeze(s1,s2);
 printf("Final string s1 is :%s",s1);
 
}