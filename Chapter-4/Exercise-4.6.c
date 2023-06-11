#include <stdio.h>
#include <math.h>
int i = 0, j = 0;
char s[20];
float arr[20];
float var[26];
void getvar()
{
        
    if (s[i] <= 'Z' && s[i] >= 'A')
    {
        var[s[i] - 'A'] = arr[j - 1];
        printf("%d-%f-%f\n",j-1,arr[j-1],var[s[i]-'A']);
    }
    else if (s[i] <= 'z' && s[i] >= 'a')
    {
        arr[j] = var[s[i] - 'a'];
        j++;
        printf("%f-%d\n",j-1,arr[j-1]);
    }
}
void getnum()
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
   else
   {
       return;
   }
}
int main()
{
    printf("Enter a postfix expression\nEnter capitals to set variable\nEnter smalls to get variable\n");

    gets(s);
    float  res = 0;
   
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
            getnum();
            getvar();
            break;
        }
        i++;
    }

    printf("Answer=%.2f", arr[0]);
}
