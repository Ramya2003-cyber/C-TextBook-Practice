#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#define MAXWORD 100
struct key
{
    char *word;
    int count;
} keytab[] = {
    "auto", 0,
    "break", 0,
    "case", 0,
    "char", 0,
    "const", 0,
    "continue", 0,
    "default", 0,
    "do", 0,
    "double", 0,
    "else", 0,
    "enum", 0,
    "extern", 0,
    "float", 0,
    "for", 0,
    "goto", 0,
    "if", 0,
    "int", 0,
    "long", 0,
    "register", 0,
    "return", 0,
    "short", 0,
    "signed", 0,
    "sizeof", 0,
    "static", 0,
    "struct", 0,
    "switch", 0,
    "typedef", 0,
    "union", 0,
    "unsigned", 0,
    "void", 0,
    "volatile", 0,
    "while", 0};

#define NKEYS (sizeof(keytab) / sizeof(keytab[0]))
int same_chars = 6;
struct tnode{
    int count;
    char *word;
    struct tnode *left;
    struct tnode *right;
};
struct tnode *root;
int getword(char *, int);
int binsearch(char *, struct key *, int);
#define BUFSIZE 100
char buf[BUFSIZE]; /* buffer for ungetch */
int bufp = 0;      /* next free position in buf */
int getch(void)    /* get a (possibly pushed-back) character */
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}
void ungetch(int c) /* push character back on input */
{
    if (bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}
struct tnode *talloc(void)
{
    return (struct tnode *) malloc(sizeof(struct tnode));
}
char *strndup(const char *s,size_t n)
{
    int a=n;
    char *p;
    if(strlen(s)<n)
    {
        a = sizeof(strlen(s));
    }
    p=malloc(a+1);
    if(p!=NULL)
    {
        memcpy(p,s,a);//copies string from s to p of a bytes
        p[a]='\0';
    }
    
    return p;
}
struct tnode *addtree(struct tnode *p,char *word)
{
    int c;
    if(p==NULL)
    {
        p=talloc();
        p->word=strndup(word,same_chars);
        p->left=p->right=NULL;
        p->count=1;
    }

    else if(( c=strncmp(p->word,word,same_chars))==0)
    {
        p->count++;
    }
    else if(c>0)
    {
        p->left=addtree(p->left,word);
    }
    else{
        p->right=addtree(p->right,word);
    }
    return p;
}
void printtree(struct tnode *root)
{
    if(root!=NULL)
    {
        printtree(root->left);
        printf("%d %s\n", root->count, root->word);
        printtree(root->right);
    }
  
}

int main()
{
    int n;
    char word[MAXWORD];
    root=NULL;
    while (getword(word, MAXWORD) != EOF)
        if (isalpha(word[0])||isalpha(word[0])=='_')
            if ((n = binsearch(word, keytab, NKEYS)) != 0)
            {
                root = addtree(root, word);
            }   
    printtree(root);
    return 0;
}

int binsearch(char *word, struct key tab[], int n)
{
    int cond;
    int low, high, mid;
    low = 0;
    high = n - 1;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if ((cond = strcmp(word, tab[mid].word)) < 0)
            high = mid - 1;
        else if (cond > 0)
            low = mid + 1;
        else
            return mid;
    }
    return -1;
}
int getword(char *word, int lim)
{
    int c, getch(void);
    void ungetch(int);
    char *w = word;
    while (isspace(c = getch())) // ignoring spaces
        ;
    if (c != EOF)
        *w++ = c;

    if (c == '\"') // string constants
    {
        for (; --lim > 0; w++)
        {
            if ((*w = getch()) == '\"')
            {
                break;
            }
        }
        *++w = '\0';
    }
    if (c == '#') // preprocessors
    {
        for (; --lim > 0; w++)
        {
            if ((*w = getch()) == '\n')
            {
                break;
            }
        }
        *++w = '\0';
    }
    if (c == '/')
    {
        c = getch();
        if (c == '/')
        {
            *w++ = c;
            for (; --lim > 0; w++)
            {
                if ((*w = getch()) == '\n')
                {
                    break;
                }
            }
            *++w = '\0';
        }
        else if (c == '*')
        {

            *w++ = c;
            for (; --lim > 0; w++)
            {
                if ((*w = getch()) == '/')
                {
                    if (*(w - 1) == '*')
                        break;
                }
            }
            *++w = '\0';
        }
    }
    if (!isalpha(c) && c != '_') // end the word if it doesn't start with alphabet or underscore
    {
        *w = '\0';
        return c;
    }
    for (; --lim > 0; w++)
        if (!isalnum(*w = getch())) // take one input character and ungetch if it is not alphanumeric(doesn't handle comments etc)
        {
            ungetch(*w);
            break;
        }
    *w = '\0';
    return word[0];
}