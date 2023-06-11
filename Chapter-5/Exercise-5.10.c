#include<stdio.h>
#include<stdlib.h>
#include <math.h>
int i = 0, j = 0;
void getnum(char s[], float arr[])
{
    int pos = 0;
    float temp;
    if (s[i] == '.')
    {

        i++;
        while (s[i] <= '9' && s[i] >= '0')
        {

            pos++;
            temp = s[i] - '0';
            for (int k = 0; k < pos; k++)
            {
                temp /= 10;
            }
            arr[j] += temp;
            i++;
        }
        j++;
    }

    if (s[i] <= '9' && s[i] >= '0')
    {
        arr[j] = s[i] - '0';

        i++;
        while (s[i] <= '9' && s[i] >= '0')
        {
            printf("while\n");
            arr[j] *= 10;
            arr[j] += s[i] - '0';
            i++;
        }

        if (s[i] == '.')
        {

            i++;
            while (s[i] <= '9' && s[i] >= '0')
            {

                pos++;
                temp = s[i] - '0';
                for (int k = 0; k < pos; k++)
                {
                    temp /= 10;
                }
                arr[j] += temp;
                i++;
            }
        }

        j++;
    }
}
    int main(int argc, char *argv[])
    {
        char s[100];
        int p = 0;
        ++argv;
       // printf("%d", argc);
        while (!(*argv[0] == 'e' && *++argv[0] == 'x' && *++argv[0] == 'p' && *++argv[0] == 'r'))
        {
            printf("Usage:expr <expression> %d ",
                   argc);
            exit(0);
        }
        ++argv;
        argc -= 2;
        while (argc-- > 0)
        {
            do
            {
                s[p++] = *argv[0];
                // printf("\nc==%c",*argv[0]);
            } while (*++argv[0] != '\0');
            s[p++] = ' ';
            ++argv;
        }
        s[p] = '\0';
        //printf("\n%s", s);
        float arr[20] = {0, 0}, res = 0;

        while (s[i] != '\0')
        {
            switch (s[i])
            {
            case '+':
                res = arr[j - 2] + arr[j - 1];
                arr[j - 2] = res;
                j--;

                break;
            case '-':
                if (s[++i] != ' ' && s[i] != '\0')
                {
                    getnum(s, arr);
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
                getnum(s, arr);
                break;
            }
            i++;
        }

        printf("\nAnswer=%.2f", arr[0]);
    }