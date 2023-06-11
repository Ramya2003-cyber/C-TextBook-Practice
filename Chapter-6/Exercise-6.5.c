#include<stdio.h>
#include <stdlib.h>
#include<string.h>
struct nlist *lookup(char *);
char *strdup(const char *);
#define HASHSIZE 101
static struct nlist *hashtab[HASHSIZE];
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
void undef(char *s)
{
  
    struct nlist *temp,*prev;
    temp = lookup(s);
    prev=hashtab[hash(s)];
    if(temp==prev)
    {
        hashtab[hash(s)]=NULL;
    }
    while (prev->next != temp && prev->next != NULL)
    {
        printf("\nhi");
        prev = prev->next;
        }
    prev->next=temp->next;
    free(temp->defn);
    free(temp->name);
    free(temp);
}
int main()
{
    install("hi","friendly greeting");
    struct nlist *temp;
    temp=lookup("hi");
    if(temp!=NULL)
    printf("%s\n",temp->defn);
    else
    {
        printf("Not found\n");
    }
    undef("hi");
    temp = lookup("hi");
    if (temp != NULL)
        printf("%s", temp->defn);
    else
    {
        printf("Not found\n");
    }
}
