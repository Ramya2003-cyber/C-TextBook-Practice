#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
int lim=20;
int getline(char p[],int lim)
{
    int c, i;
    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
        p[i] = c;

    p[++i] = '\0';
    return i;
}
int main()
{
    printf("Enter a postfix expression\n");
    char a[20],b[20];
    int i=0,j=0,c=0;
    if(getline(a,lim)<=0)
    {
       exit(0);
    }
    char *s;
    s=a;
    float arr[20] = {0, 0}, res = 0;

    while (*s != '\0')
    {
        switch (*s)
        {
        case '+':
            res = arr[j - 2] + arr[j - 1];
            arr[j - 2] = res;
            j--;

            break;
        case '-':
            if (*++s != ' ' && *s != '\0')
            {
               
                strcpy(b, s);
                sscanf(b,"%f",&arr[j++]);
                ++s;
                while (*s != ' ')
                {

                    ++s;
                }
                arr[j - 1] -= 2 * arr[j - 1];
                // printf("%f\n",arr[j-1]);
                break;
            }
            i--;
            res = arr[j - 2] - arr[j - 1];
            arr[j - 2] = res;
            j--;

            break;
        case '*':
            res = arr[j - 2] * arr[j - 1];
            arr[j - 2] = res;
            j--;
            break;
        case '/':
            res = arr[j - 2] / arr[j - 1];
            arr[j - 2] = res;
            j--;
            break;
        case '%':
            res = fmod(arr[j - 2], arr[j - 1]);
            arr[j - 2] = res;
            j--;
            break;
        case ' ':
            break;

        default:
            strcpy(b,s);
            sscanf(b, "%f", &arr[j++]);
            ++s;
            while(*s!=' ')
            {
               
                ++s;
            }
            break;
        }
        ++s;
    }

    printf("Answer=%.2f", arr[0]);
}