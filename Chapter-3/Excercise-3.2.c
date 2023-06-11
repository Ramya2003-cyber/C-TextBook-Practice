#include<stdio.h>
#include<string.h>
int main()
{
    int c,i=0;
    char a[100];
    printf("Enter some text\n");
    while((c=getchar())!=EOF)
    {
        a[i++]=c;
    }
    //a[i]='\0';
    i=0;
    while(i<strlen(a)){
    switch(a[i]){
            case '\t':
                putchar('\\');
                putchar('t');
                break;
            case '\n':
                putchar('\\');
                putchar('n');
                break;
            default:
                putchar(a[i]);
                break;

        }
        i++;
    }
}