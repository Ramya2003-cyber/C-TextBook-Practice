#include<stdio.h>
#include<ctype.h>
#include<string.h>
static int v;
int flag=0;
int NUMBER=1;
char getch()
{
   if(flag)
   {
    flag=0;
    return v;
}
else{
    return getchar();
}
}
int getop(char s[])
{
    int i,c;
    while ((s[0] = c = getch()) == ' ' || c == '\t')
        ;
    s[1] = '\0';
    if (!isdigit(c) && c != '.')
        return c; /* not a number */
    i = 0;
    if (isdigit(c)) /* collect integer part */
        while (isdigit(s[++i] = c = getch()))
            ;
    if (c == '.') /* collect fraction part */
        while (isdigit(s[++i] = c = getch()))
            ;
    s[i] = '\0';
    if (c != EOF)
    {
        flag=1;
        v = c;
    }

    return NUMBER;
}
int main()
{
    char s[20];
    while(getop(s)==1)
    printf("%s\n",s);
}
