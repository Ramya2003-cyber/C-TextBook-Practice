#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
struct word *addnode(struct word *a, char *b);
int getword(FILE *c, char *w);
char *string_duplicate(char *d);
void printnode(struct word *e);
struct word *bubblesort(struct word *fn);
struct word *talloc(void);
struct word
{
    char *word;
    int count;
    struct word *next;
};
int line = 1;
int endword = 0;
struct word *fn = NULL;
int main()
{
    FILE *fp;
    fp = fopen("text.txt", "r");
    char word[20];
    while ((getword(fp, word)) != EOF)
    {
        if (word[0] != '\0')
        {

            fn = addnode(fn, word);
        }
    }
    fn=bubblesort(fn);
    printnode(fn);
}
int getword(FILE *fp, char *word)
{
    int c;
    char *w = word;
    while ((c = fgetc(fp)) != EOF && c != ' ' && c != '\t' && c != '\n' && isalpha(c))
    {
        *w = c;
        w++;
    }
    if (c == EOF)
    {
        return c;
    }
    if (endword)
    {
        line++;
        endword = 0;
    }
    if (c == '\n')
    {
        endword = 1;
    }
    *w = '\0';

    return word[0];
}
struct word *addnode(struct word *p, char *word)
{
    if (p == NULL)
    {
        p = talloc();
        p->word = strdup(word);
        p->count = 1;
        p->next = NULL;
    }
    else if (strcmp(p->word, word) == 0)
    {
            p->count++;
    }
    else
    {
        p->next = addnode(p->next, word);
    }
    return p;
}
char *strdup(const char *b)
{
    char *c;
    int a = strlen(b);
    c = (char *)malloc(a * sizeof(char));
    if (c != NULL)
    {
        strcpy(c, b);
    }
    return c;
}
void printnode(struct word *fn)
{
    if (fn != NULL)
    {
        printf("%d  %s\n", fn->count,fn->word);
        printnode(fn->next);
    }
}
struct word *talloc()
{
    return (struct word *)malloc(sizeof(struct word *));
}
struct word *bubblesort(struct word *fn)
{
    struct word *i, *j, *temp, *prev;
    i = fn;
    j = fn;

    while (i->next != NULL)
    {
        while (j->next != 0)
        {
            if (j->count < j->next->count)
            {
                if (i == j)
                {
                    i = i->next;
                }
                else if (j->next == i)
                {
                    i = j;
                }
                if (j == fn)
                {
                    fn = fn->next;

                    temp = j->next;
                    j->next = j->next->next;
                    temp->next = j;
                }
                else
                {
                    prev = fn;
                    while (prev->next != j)
                    {
                        prev = prev->next;
                    }
                    prev->next = j->next;
                    temp = j->next->next;
                    j->next->next = j;
                    j->next = temp;
                }
            }
            else
            {
                j = j->next;
            }
        }
        i = i->next;
        j = fn;
    }
    i = fn;
    return i;
}