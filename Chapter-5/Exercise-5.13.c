#include<stdio.h>
int MAXLIM=1000;

int tail=10;
int getline(char s[], int lim)
{
    int c;
    int i = 0;
    while (--lim > 0 && (c = getchar()) != EOF && c != '\n')
        s[i++] = c;
    if (c == '\n')
        s[i++] = c;
    s[i] = '\0';
    if(c==EOF)
    {
        return 0;
    }
    return i;
}
int main(int argc,char *argv[])
{
    char d[100][MAXLIM];
    int line=0;
    while(getline(d[line],MAXLIM)>0)
    {
         line++;
    }
     if(argc==3)
     {
        if(strcmp(*argv[1],tail)==0)
        tail=*argv[2]-'0';
     }
     int f=line-10;
     while(f!=line)
     {
        printf("%s",d[f++]);
     }


}