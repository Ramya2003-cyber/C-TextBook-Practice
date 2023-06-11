#include <stdio.h>
#include <math.h>
#include<stdlib.h>
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

    else if (s[i] <= '9' && s[i] >= '0')
    {
        arr[j] = s[i] - '0';

        i++;
        while (s[i] <= '9' && s[i] >= '0')
        {
            //printf("while\n");
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
    else
    {
        exit(0);
    }
}
int main()
{
    printf("Enter a postfix expression\n");
  
    char s[20];
    gets(s);
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
        
        case 's':
            if(s[++i]=='i'&&s[++i]=='n')
            {
                res=sin(arr[j-1]);
                arr[j-1]=res;
                break;
            }
            else{
                exit(0);
            }
            
        case 'e':
            if(s[++i]=='x'&&s[++i]=='p')
            {
                res=exp(arr[j-1]);
                arr[j-1]=res;
            
                break;
            }
            else
            {
                exit(0);
            }
        case 'p':
            if(s[++i]=='o'&&s[++i]=='w')
            {
                res=pow(arr[j-1],arr[j-1]);
                arr[j-2]=res;
                j--;
                break;
            }
            else
            {
                exit(0);
            }
        case ' ':
            break;

        default:
            getnum(s, arr);
            break;
        }
        i++;
    }

    printf("Answer=%.2f", arr[0]);
}