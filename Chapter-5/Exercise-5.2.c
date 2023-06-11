#include <ctype.h>
#include <stdio.h>
#define SIZE 100
#define BUFSIZE 100
char buf[BUFSIZE]; /* buffer for ungetch */
int bufp = 0;      /* next free position in buf */
int getch(void)    /* get a (possibly pushed-back) character */
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}
void ungetch(int c) /* push character back on input */
{
    if (bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}
int getfloat(float *pn)
{
    float c;
    int sign;
    while (isspace(c = getch())) /* skip white space */
        ;
    if (!isdigit(c) && c != EOF && c != '+' && c != '-')
    {
        ungetch(c); /* it is not a number */
        return 0;
    }
    sign = (c == '-') ? -1 : 1;
    if (c == '+' || c == '-')
        c = getch();
    if (isdigit(c))
    {
        for (*pn = 0; isdigit(c); c = getch())
        {
            //  printf("Calculating\n");
            *pn = 10 * *pn + (c - '0');
        }
        if (c == '.')
        {
         //   printf("Inside fraction\n");
            c = getch();
            if (isdigit(c))
                for (int i = 1; isdigit(c); c = getch())
                {
                    c -= '0';
                    for (int k = 0; k < i; k++)
                    {
                        c /= 10;
                        //printf("%f\n",c);
                    }
                    *pn += c;
                    i++;
                }
        }
    }
       
   
    else
    {
        if (c != EOF)
            return 0;
    }
    *pn *= sign;
    if (c != EOF)
        ungetch(c);
    return c;
}
int main()
{
    int n, getfloat(float *);
    float array[SIZE];
    for (n = 0; (n < SIZE) && (getfloat(&array[n]) != EOF); n++)
    {
      //  printf("IN for\n");
    }
    for (int i = 0; i < n; i++)
    {
        printf("%f", array[i]);
    }
}