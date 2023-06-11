#include <stdio.h>
int b = 0;
int main()
{
    int c;
    printf("Enter one ctrl-z\n");
    c = getch();
    printf("Unreading the character\n");
    ungetch(c);
    printf("Reading again %d\n", getch());
}
int getch()
{
    if (b == 0)
        return getchar();
    else
    {
        int c = b;
        b = 0;
        return c;
    }
}
void ungetch(int c)
{
    if (b != 0)
    {
        printf("Too many characters!");
    }
    else
    {
        b = c;
    }
}