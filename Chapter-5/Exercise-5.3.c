#include<stdio.h>

void strcat1(char *s, char *t)
{
    while (*s != '\0') /* find end of s */
        {
         
            s++;
        }
   
    while (*t != '\0') /* copy t */
    {
        *s=*t;
        s++;
        t++;
    }
    *s='\0';
}
int main()
{
    char s[10]="hi ";
    char t[]="ramya";
    strcat1(s,t);
    int i=0;
    while (s[i]!='\0')
    {
        printf("%c",s[i]);
        i++;
    }
    
}