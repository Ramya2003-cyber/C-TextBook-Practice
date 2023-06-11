#include<stdio.h>
int main()
{
    FILE *fp1,*fp2;
    fp1=fopen("file1.txt","r");
    fp2=fopen("file2.txt","r");
    int line=1,c;
    while((c=fgetc(fp1))==fgetc(fp2))
    {
        if(c=='\n')
        line++;
    }
    printf("%d",line);
}