// Write the function strend(s, t), which returns 1 if the string t occurs at the end of the
// string s, and zero otherwise.
#include<stdio.h>
int strend(char *s,char *t)
{
    int i=0;
    while(*s!='\0')
    s++;
    while(*t!='\0')
    {
    t++;
    i++;
    }
    s--;
    t--;
    while(*s==*t)
    {
       // printf("hi\n");
        s--;
        t--;
        i--;
    }
    if(i==0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
    
}
int main()
{
    char s[]="auction";
    char t[]="tion";
    if(strend(s,t)==1)
    {
        printf("%s ends with %s",s,t);
    }
    else
    {
        printf("%s doesn't end with %s",s,t);
    }
}