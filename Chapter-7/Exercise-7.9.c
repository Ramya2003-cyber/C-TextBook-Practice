#include<stdio.h>
#define isupper_macro(c) ( (c<='Z')&&(c>='A')?1:0)//more space ,less time
int isupper_function(char c)//less code but more time due to function call overhead
{
    return c <= 'Z' && c >= 'A';
}
int main()
{
    char b='B';
    printf("%d\n",isupper_macro(b));
    printf("%d",isupper_function(b));

}