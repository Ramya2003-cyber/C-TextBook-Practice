#include <stdio.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#define MAXLEN 1000 /* max #lines to be sorted */
char *lineptr[MAXLEN];
char *temp[MAXLEN]; /* pointers to text lines */
int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines);
void qsort_(void *lineptr[], int left, int right,
            int (*comp)(void *, void *), int, void *temp[]);
int numcmp(char *, char *);
void swap(void *v[], int, int);
void tolower_(char *lineptr[], int, char *temp[]);
int start=1,end=4;
int fold = 0;
int directory = 0;
int numeric = 0;
/* sort input lines */
int dcmp(char *a, char *b)
{
    for (; ((isalnum(*a) || *a == '_') && (isalnum(*b) || *b == '_')); a++, b++)
    {
        if (*a != *b)
            break;
    }
    if (!((isalnum(*a) || *a == '_') && (isalnum(*b) || *b == '_')))
    {

        return 0;
    }

    return *a - *b;
}
int dfcmp(char *a, char *b)
{
    char x[start - end + 1], y[start - end + 1];
    int i = 0;
    int cmp = 0;
    int j=0;
    printf("a=%s\nb=%s\n",a,b);
    
    j=0;
  
    int n = strlen(b);
    if (n < end)
    {
        for (i = start; i <n; i++)
        {
            y[j++] = *(b + i);
        }
    }
    else
    {
        for (i = start; i < end; i++)
        {
            y[j++] = *(b + i);
        }
    }
    j=0;
    for (i = start; i < end; i++)
    {
        x[j++] = *(a + i);
    }
    x[j] = '\0';
    printf("x=%s\n", x);
    printf("y=%s\n", y);
    if (numeric)
    {
        cmp = numcmp(x, y);
    }
    else if (directory)
    {
        cmp = dcmp(x, y);
    }
    else
    {
        cmp = strcmp(x, y);
        printf("%s %s %d",x,y,cmp);
    }
    return cmp;
}

int main(int argc, char *argv[])
{
    int nlines; /* number of input lines read */
    
    int reverse = 0; /* 1 if numeric sort */
    int i = 1;
    
    int df=1;
    if (argc > 1 && strcmp(argv[i], "-n") == 0)
    {
        numeric = 1;
        i++;
        argc--;
    }
    if (argc > 1 && strcmp(argv[i], "-r") == 0)
    {
        reverse = 1;
        i++;
        argc--;
    }
    if (argc > 1 && strcmp(argv[i], "-f") == 0)
    {
        fold = 1;
        i++;
        argc--;
    }
    if (argc > 1 && strcmp(argv[i], "-d") == 0 && fold == 1)
    {
        directory = 1;
        i++;
        argc--;
    }
    if(argc>1&&isdigit(argv[i][0]))
    {
        start=atoi(argv[i]);
        i++;
        argc--;

    }
    if(argc>1&&isdigit(argv[i][0]))
    {
        end=atoi(argv[i]);
        i++;
        argc--;
        df=1;
    }
 
    if ((nlines = readlines(lineptr, MAXLEN)) >= 0)
    {

        for (int i = 0; i < nlines; i++)
        {
            temp[i] = (char *)malloc(MAXLEN * sizeof(char));
            strcpy(temp[i], lineptr[i]);
        }
        // printf("%u %u\n",temp,lineptr);
        if (fold)
        {

            tolower_(lineptr, nlines, temp);
        }
        if(df)
        {
            printf("df\n");
            qsort_((void **)lineptr, 0, nlines - 1,
                   (int (*)(void *, void *))dfcmp, reverse, (void **)temp);
        }
        else if (directory)
        {
            qsort_((void **)lineptr, 0, nlines - 1,
                   (int (*)(void *, void *))dcmp, reverse, (void **)temp);
        }
        else
            qsort_((void **)lineptr, 0, nlines - 1,
                   (int (*)(void *, void *))(numeric ? numcmp : strcmp), reverse, (void **)temp);
        writelines(lineptr, nlines);
        return 0;
    }
    else
    {
        printf("input too big to sort\n");
        return 1;
    }
}
/* qsort: sort v[left]...v[right] into increasing order */
void qsort_(void *v[], int left, int right,
            int (*comp)(void *, void *), int reverse, void *temp[])
{
    int i, last;

    if (left >= right) /* do nothing if array contains */
        return;        /* fewer than two elements */
    swap(v, left, (left + right) / 2);
    swap(temp, left, (left + right) / 2);
    last = left;
    for (i = left + 1; i <= right; i++)
        if (reverse)
        {
            if ((*comp)(temp[i], temp[left]) > 0)
                swap(v, ++last, i);
        }
        else
        {
            if ((*comp)(temp[i], temp[left]) < 0)
                swap(v, ++last, i);
        }

    swap(v, left, last);
    qsort_(v, left, last - 1, comp, reverse, temp);
    qsort_(v, last + 1, right, comp, reverse, temp);
}

/* numcmp: compare s1 and s2 numerically */
int numcmp(char *s1, char *s2)
{
    double v1, v2;
    v1 = atof(s1);
    v2 = atof(s2);
    if (v1 < v2)
        return -1;
    else if (v1 > v2)
        return 1;
    else
        return 0;
}
void swap(void *v[], int i, int j)
{
    void *temp;
    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}
void writelines(char *lineptr[], int nlines)
{
    int i;
    for (i = 0; i < nlines; i++)
    {
        printf("%s\n", lineptr[i]);
    }
}
int getline(char s[], int lim)
{
    int c;
    int i = 0;
    while (--lim > 0 && (c = getchar()) != EOF && c != '\n')
        s[i++] = c;
    if (c == '\n')
        s[i++] = c;
    s[i] = '\0';
    if (c == EOF)
    {
        return 0;
    }
    return i;
}
int readlines(char *lineptr[], int maxlines)
{
    int len, nlines;
    char *p, line[MAXLEN];
    nlines = 0;
    while ((len = getline(line, MAXLEN)) > 0)
        if (nlines >= maxlines || (p = malloc(len * sizeof(char))) == NULL)
            return -1;
        else
        {
            line[len - 1] = '\0'; /* delete newline */
            strcpy(p, line);
            lineptr[nlines++] = p;
        }
    return nlines;
}
void tolower_(char *v[], int nlines, char *temp[])
{

    char *temp1[nlines];

    int n = nlines;
    while (nlines > 0)
    {
        temp1[n - nlines] = temp[n - nlines];
        while (*(temp1[n - nlines]) != '\0')
        {

            if (isupper(*(temp1[n - nlines])))
            {
                *(temp1[n - nlines]) += 'a' - 'A';
            }

            temp1[n - nlines]++;
        }

        nlines--;
    }
}