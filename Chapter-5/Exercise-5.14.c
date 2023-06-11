#include<stdio.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#define MAXLEN 1000    /* max #lines to be sorted */
char *lineptr[MAXLEN];

int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines);
void qsort_(void *lineptr[], int left, int right,
           int (*comp)(void *, void *),int );
int numcmp(char *, char *);
void swap(void *v[], int, int);

/* sort input lines */
int main(int argc, char *argv[])
{
    int nlines;      /* number of input lines read */
    int numeric = 0; 
    int reverse=0;/* 1 if numeric sort */
    int i=1;
    int fold=0;
    

    if (argc > 1 && strcmp(argv[i], "-n") == 0)
    {
        numeric = 1;
        i++;
    } 
    if (argc > 1 && strcmp(argv[i], "-r") == 0)
    {
        reverse = 1;
        i++;
    }

    
        
    
    if ((nlines = readlines(lineptr, MAXLEN)) >= 0)
    {
        
       
        qsort_((void **)lineptr, 0, nlines - 1,
              (int (*)(void *, void *))(numeric ? numcmp : strcmp),reverse);
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
           int (*comp)(void *, void *),int reverse)
{
    int i, last;

    if (left >= right) /* do nothing if array contains */
        return;        /* fewer than two elements */
    swap(v, left, (left + right) / 2);
    last = left;
    for (i = left + 1; i <= right; i++)
        if(reverse)
        {
            if ((*comp)(v[i], v[left]) > 0)
                swap(v, ++last, i);
        }
        else
        {
            if ((*comp)(v[i], v[left]) < 0)
                swap(v, ++last, i);
        }
        
    swap(v, left, last);
    qsort_(v, left, last - 1, comp,reverse);
    qsort_(v, last + 1, right, comp,reverse);
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
        if (nlines >= maxlines || (p = malloc(len*sizeof(char)) )== NULL)
            return -1;
        else
        {
            line[len - 1] = '\0'; /* delete newline */
            strcpy(p, line);
            lineptr[nlines++] = p;
        }
    return nlines;
}
