#include <stdio.h>
#include <string.h>

void reverse(char a[])
{
    char temp; //kcbksndbghdf
    int n = strlen(a);
    for (int i = n - 1; i >= n / 2; i--)
    {
        temp = a[i];
        a[i] = a[n - i - 1];
        a[n - i - 1] = temp;
    }

    return;
}
int main()
{
    printf("Enter a string\n");
    char s[100];
    gets(s);

    reverse(s);
    printf("The reversed string is:%s", s);
}