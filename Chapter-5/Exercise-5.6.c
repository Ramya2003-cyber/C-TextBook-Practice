#include<stdio.h>
#include <math.h>
#include<ctype.h>
#include<string.h>
#define NUMBER '0'
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
int getLine(char *s, int lim)
{
    int c, i;

    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; s++,i++)
        *s = c;
    // if (c == '\n')
    // {
    //     *s = c;
    //     ++i;
    //     s++;
    // }
    *s= '\0';
    return i;
}
int atoi(char *s)
{
    int a=0,i=0;
    
    while(*s!='\0'&&isdigit(*s))
    {
        a=10*a+(*s-'0');
        s++;
       i++;
    }
    
    return a;
}
void itoa(int num,char *s)
{
    int revnum=0;
    while(num!=0)
    {
        int c=num%10;
        revnum=10*revnum+c;
        num/=10;
    }
    while(revnum!=0)
    {
        int c=revnum%10;
        *s=c+'0';
        s++;
        revnum/=10;
    }
}
void reverse(char *t)
{
    char *a,*b;
    int i=0,temp;
    int l=strlen(t);
    a=t;
    b=t+l-2;//newline,'\0'

    for( i=0;i<(l-1)/2;i++)
    {
        //printf("%c %c",*a,*b);
        temp=*a;
        *a=*b;
        *b=temp;
        //printf("%c %c %c\n",*a,*b, temp);
        a++;
        b--;

    }
    a--;
    b++;
    
}
int strindex(char *s,char *t)
{
    int i=0;
    char *temp;
    temp=t;
    while (*s!='\0')
    {
        if(*s==*t)
        {
            while(*s!='\0'&&*t!='\0')
            {
                if(*s==*t)
                {
                    s++;
                    t++;
                }
                else{
                    t=temp;
                    break;
                }
            }
            if(*t=='\0')
            {
                return i;
            }
        }
        i++;
        s++;
    }
    return -1;  
}
int getop(char *s)
{
    int c;
    while((*s=c=getch())==' '||c=='\t')
    ;
    s++;
    *s='\0';
    if(!isdigit(c)&&c!='.')
       return c;
    if(isdigit(c))
       while(isdigit(*(++s)=c=getch()))
       ;
    if(c=='.')
       while (isdigit(*(++s) = c = getch()))
       ;
    *s='\0';
    if(c!=EOF)
    {
        ungetch(c);
    }
    return NUMBER;
}
int main()
{
    char s[20],t[20],u[20],v[20],w[20],waste[2];
    int num;
    printf("Enter a number\n");
    getLine(s,20);
    printf("atoi=%d\n",atoi(s));   
    printf("Enter a string\n");
    getLine(t, 20);
    reverse(t);
    printf("%s\n",t);
    printf("Enter a number\n");
    scanf("%d", &num);
    getLine(waste,2);
    itoa(num, u);
    printf("itoa=%s\n", u);
    printf("Enter two strings\n");
    getLine(v,20);
    getLine(w,20);
    int index=strindex(v,w);
    if(index!=-1)
    {
        printf("%s is found at %d\n",w,index);
    }
    else{
        printf("%s is not found\n",w);
    }
    char a[10];
    printf("Enter an operand or an operator\n");
    int res=getop(a);
    if(NUMBER==res)
    {
        printf("The number is %s\n",a);
    }
    else{
        printf("The operator is %c\n",res);
    }

}