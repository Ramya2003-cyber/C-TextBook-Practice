#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
struct nlist *lookup(char *);
char *strdup(const char *);
#define HASHSIZE 101
static struct nlist *hashtab[HASHSIZE];
int endword = 0, endfile = 0;
struct nlist
{                       /* table entry: */
    struct nlist *next; /* next entry in chain */
    char *name;         /* defined name */
    char *defn;         /* replacement text */
};
unsigned hash(char *s)
{
    unsigned hashval;
    for (hashval = 0; *s != '\0'; s++)
        hashval = *s + 31 * hashval;
    return hashval % HASHSIZE;
}
struct nlist *lookup(char *s)
{
    struct nlist *np;
    for (np = hashtab[hash(s)]; np != NULL; np = np->next)
        if (strcmp(s, np->name) == 0)
            return np; /* found */
    return NULL;       /* not found */
}
struct nlist *install(char *name, char *defn)
{
    struct nlist *np;
    unsigned hashval;
    if ((np = lookup(name)) == NULL)
    { /* not found */
        np = (struct nlist *)malloc(sizeof(*np));
        if (np == NULL || (np->name = strdup(name)) == NULL)
            return NULL;
        hashval = hash(name);
        np->next = hashtab[hashval];
        hashtab[hashval] = np;
    }
    else                        /* already there */
        free((void *)np->defn); /*free previous defn */
    if ((np->defn = strdup(defn)) == NULL)
        return NULL;
    return np;
}
int getword(FILE *fp, char *word)
{
    int c;
    char *w = word;
    while ((c = fgetc(fp)) != EOF && c != ' ' && c != '\t' && c != '\n' && (isalnum(c)||c=='#'))
    {
        *w = c;
        w++;
    }
    if (endfile)
    {
        return -1;
    }
    if (c == EOF)
    {
        endfile = 1;
    }
    *w = '\0';
    if(word[0]!='\0')
    return word[0];
    else
    {
        getword(fp,word);
    }
}
int main()
{
    FILE *fp;
    fp = fopen("define.txt", "r");
    char word[20];
    char var[20],val[20];
    while ((getword(fp, word)) != EOF)
    {
        if (word[0] != '\0')
        {
            if (strcmp(word,"#define")==0)
            {

                if ((getword(fp, word)) != EOF)
                {
                   strcpy(var,word);
                   if ((getword(fp, word)) != EOF)
                   {
                      strcpy(val,word);
                      install(var,val);
                   }

                }
            }
        }
    }
    int c;
    char *s,*temp;
    s=(char *)malloc(sizeof(char));
    temp=s;
    struct nlist *t;
    while((c=getchar())!=EOF)
    {
        if(isalpha(c))
        {
            *s = c;
            ++s;
        }
        if(c=='\n')
        {
            *s='\0';
            t=lookup(temp);
            if(t!=NULL)
            {
                printf("%s\n",t->defn);
            }
            s=temp;
        }
    }
 
}