// Write the function strindex(s, t)
// which returns the position of the rightmost
//     occurrence of t in s,
//     or -1 if there is none.

#include<stdio.h>
#include <string.h>
int strindex(char[], char);
int strindex(char s[],char t)
{
    int index=1,temp,count=0;
    int n=strlen(s);
    for(int i=0;i<=(n-1)/2;i++)
    {
        temp=s[i];
        s[i]=s[n-1-i];
        s[n-1-i]=temp;
    }
    
    while(s[index]!=t&&index<n)
    {
        index++;
    }
    for (int i = 0; i <= (n - 1) / 2; i++)
    {
        temp = s[i];
        s[i] = s[n - 1 - i];
        s[n - 1 - i] = temp;
    }
    if(index==n)
    {
        return -1;
    }

    return n-index-1;
}
int main()
{
    printf("Enter a string\n");
    char s[100];
    gets(s);
    printf("Enter the character you want to find\n");
    char t;
    scanf("%c",&t);
    int index=strindex(s,t);
    if(index!=-1)
    {
        printf("The index of rightmost position of %c in %s is %d",t,s,index);
    }
    else
    {
        printf("Character not found");
    }
}