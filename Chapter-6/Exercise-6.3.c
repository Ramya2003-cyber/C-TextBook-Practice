#include<stdio.h>
#include<ctype.h>
#include <stdlib.h>
#include<string.h>
struct word *addnode(struct word *a,char *b);
int getword(FILE *c,char *w);
char *string_duplicate(char *d);
void printnode(struct word *e);
int binsearch(char *b,int c);
struct word* talloc(void);
struct word{
    char *word;
    int *start;
    int *end;
    int count;
    struct word *next;
} ;
char *s[]={
    "a","and","be","or","that","the","this"
};
int line = 1;
int endword=0,endfile=0;
struct word *fn = NULL;
int main()
{
    FILE *fp;
    fp=fopen("text.txt","r");
    char word[20];
    while((getword(fp,word))!=EOF)
    {
        if (word[0] != '\0')
        {
            //printf("%s\n", word);
            if(binsearch(word,sizeof(s)/8)==-1)
            {
                fn = addnode(fn, word);
            }
           
        }
            
    }
    printnode(fn);
}
int getword(FILE *fp,char *word)
{
    int c;
    char *w=word;
    while ((c = fgetc(fp)) != EOF && c != ' ' && c != '\t' && c != '\n' && isalpha(c))
    {
            *w=c;
            w++;
    }
    if (endfile)
    {
            return -1;
    }
    if(c==EOF)
    {
        endfile=1;
    }
    
    if (endword)
    {
        line++;
        endword = 0;
    }
    if(c=='\n')
    {
      endword=1;
    }
    *w='\0';
   
    return word[0];
}
struct word *addnode(struct word *p,char *word)
{
   if(p==NULL)
   {
    p=talloc();
    p->word=strdup(word);
   // printf("%s\n",p->word);
    p->start=(int *)malloc(sizeof(int));
    *(p->start)=line;
    p->count=1;
    p->next=NULL;
    p->end=p->start;
   }
   else if(strcmp(p->word,word)==0)
   {
    if(*(p->end)!=line)
    {
        p->count++;
        p->end++;
        *(p->end)=line;
    }
   }
   else
   {
    p->next=addnode(p->next,word);
   }
   return p;
}
char *strdup(const char *b)
{
    char *c;
    int a =strlen(b);
    c=(char *)malloc(a*sizeof(char));
    if(c!=NULL)
    {
        strcpy(c,b);
    }
    return c;
}
void printnode(struct word *fn)
{
    if(fn!=NULL)
    {
        printf("%s ",fn->word);
        int *a;
        a=fn->start;
        while(a!=fn->end)
        {
            printf("%d ",*a);
            a++;
        }
        printf("%d\n",*a);
        printnode(fn->next);
    }
}
struct word* talloc()
{
    return (struct word *)malloc(sizeof(struct word *));
}
int binsearch( char *word, int n)
{
    int cond;
    int low, high, mid;
    low = 0;
    high = n - 1;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if ((cond = strcmp(word, *(s+mid))) < 0)
            high = mid - 1;
        else if (cond > 0)
            low = mid + 1;
        else
            return mid;
    }
    return -1;
}