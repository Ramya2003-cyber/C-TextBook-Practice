#include<stdio.h>
char lower(char c)
{
    return((c>='A'&&c<='Z')?(c+'a'-'A'):c);
}
int main()
{
    char c;
    printf("Enter a character\n");
    c=getchar();
    printf("%c",lower(c));
}