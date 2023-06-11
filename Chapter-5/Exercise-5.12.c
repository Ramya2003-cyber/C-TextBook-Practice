#include <stdio.h>

#define MAXLEN 1000
#define N 4

int getLine(char[], int);


int getLine(char s[], int lim)
{
    int c, i;

    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
        s[i] = c;
    if (c == '\n')
    {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}
void detab(char in[], char out[], char *argv[])
{
    int i;       /* index for read line */
    int j;       /* index for modified (written) line */
    int nblanks=0; /* number of blanks to the next tab stop */
    int tb = N;
    int m, n;
    if (*--argv[2] == '-')
    {
        m = *(++argv[2]) - '0';
        printf("%d\n", m);
    }
    if (*--argv[3] == '+')
    {
        n = *(++argv[3]) - '0';
        printf("%d\n", n);
    }
    for (i = j = 0; in[i] != '\0'; ++i)
    {
        if (in[i] == '\t')
        {
            if (i + 1 >= m)
                tb = n - (m - 1 + i) % n;
            //printf("tb=%d,i=%d\n",tb,i);
            if(tb!=0)
            nblanks = tb - (j % tb);

            while (nblanks-- > 0)
                out[j++] = '*';
        }
        else
            out[j++] = in[i];
    }

    out[j] = '\0';
}
void entab(char in[], char out[],char *argv[])
{
    int i;
    int j;
    int nblanks;
    int ntabs;
    int tb=N;
    int m,n;
    if(*argv[2]=='-')
    {
         m=*(++argv[2])-'0';
        printf("%d\n",m);
    }
    if(*argv[3]=='+')
    {
         n=*(++argv[3])-'0';
        printf("%d\n",n);
    }
    for (i = j = 0; in[i] != '\0'; ++i)
    {
        if (in[i] == ' ')
        {
            if(i+1>=m)
            tb=n-(m-1+i)%n;
           // printf("tb=%d,i=%d\n",tb,i);
            for (nblanks = ntabs = 0; in[i] == ' '; ++i)
            {if(tb!=0){
                if ((i + 1) % tb == 0)
                {
                    ++ntabs;
                    nblanks = 0;
                }
                else
                    ++nblanks;
            }
            }
            --i;
            while (ntabs-- > 0)
            {
                out[j++] = '-';
            }

            while (nblanks-- > 0)
                out[j++] = '*';
        }
        else
            out[j++] = in[i];
    }
    out[j] = '\0';
}

int main(int argc,char *argv[])
{
    char in[MAXLEN];
    char out[MAXLEN];
    
        while (getLine(in, MAXLEN) > 0)
        {
            entab(in, out,  argv);
            printf("%s", out);
            detab(in, out,  argv);
            printf("%s", out);
        }
    
    return 0;
}