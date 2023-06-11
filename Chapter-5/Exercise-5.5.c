// Write versions of the library functions strncpy, strncat, and strncmp, which operate on at most the first n characters of their argument strings.For example,
//     strncpy(s, t, n) copies at most n characters of t to s.
#include<stdio.h>
int strncmp1(char *s,char *t,int n)
{
    for(int i=0;i<n;i++)
    {
        if(*s==*t)
        {
            s++;
            t++;
        }
        else
        {
            return *s-*t;
        }
    }
    return 0;
}
void strncat1(char *s,char *t,int n)
{
    while (*s!='\0')
    {
       s++;
    }
    int i=0;

    while (*t!='\0'&&i<n)
    {
        *s=*t;
        t++;
        s++;
        i++;
    }
    *s='\0';    
}
void strncpy1(char *s,char *t,int n)
{
    while(n>0)
    {
        *s=*t;
        s++;
        t++;
        n--;
    }
    *s='\0';
    
}
int main()
{
    char s[20],t[20];
    int n;
    int c,i=0;
    while ((c=getchar())!='\n')
    {
        s[i]=c;
        i++;
    }
    i=0;
    while ((c=getchar())!='\n')
    {
        t[i]=c;
        i++;
    }
    
    scanf("%d", &n);
    int a=strncmp1(s,t,n);
    printf("%d\n",a);
    strncat1(s,t,n);
    printf("s=%s\n",s);
    strncpy1(s,t,n);
    printf("s=%s",s);
}