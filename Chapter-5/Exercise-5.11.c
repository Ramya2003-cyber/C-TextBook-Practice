#include <stdio.h>
#include<string.h>
#define MAXLEN 1000
int N=5;

/* functions */
int getLine(char[], int);

/* getLine function: read a line into s, return length */
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

/* detab function: replaces tabs with the proper number of blanks */
void detab(char in[], char out[],int argc,char *argv[])
{
    int i;       /* index for read line */
    int j;       /* index for modified (written) line */
    int nblanks; /* number of blanks to the next tab stop */
    int tb=N;
    int p=argc;
    argc--;
    for (i = j = 0; in[i] != '\0'; ++i)
    {
        if (in[i] == '\t')
        {

            if (argc > 0)
            {
                tb = *argv[p - argc] - '0';
                argc--;
            }
            
            nblanks = tb - (j % tb);
            
            while (nblanks-- > 0)
                out[j++] = '*';
         
        }
        else
            out[j++] = in[i];
    }
        
    out[j] = '\0';
}
void entab(char in[], char out[],int argc,char *argv[])
{
    int i;
    int j;
    int nblanks;
    int ntabs;
    int tb = N;
    int p = argc;
    argc--;
    for (i = j = 0; in[i] != '\0'; ++i)
    {
        if (in[i] == ' ')
        {
            if (argc > 0)
            {
                tb = *argv[p - argc] - '0';
                argc--;
            }
            for (nblanks = ntabs = 0; in[i] == ' '; ++i)
            {
                if ((i + 1) % tb == 0)
                {
                    ++ntabs;
                    nblanks = 0;
                    // printf("tab\n");
                }
                else
                    ++nblanks;
            }
            --i;
            while (ntabs-- > 0)
            {
                out[j++] = '\t';
            }

            while (nblanks-- > 0)
                out[j++] = ' ';
        }
        else
            out[j++] = in[i];
    }
    out[j] = '\0';
}
int main(int argc,char *argv[])
{
    char in[MAXLEN];  /* currently read line */
    char out[MAXLEN]; /* modified line */

    while (getLine(in, MAXLEN) > 0)
    {
        detab(in, out,argc,argv);
        printf("%s\n", in);

        printf("%s", out);
        entab(in, out,argc,argv);
        printf("%s\n", in);

        printf("%s", out);
    }
    return 0;
}