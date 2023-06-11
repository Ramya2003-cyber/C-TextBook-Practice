#include<stdio.h>
int main()
{
    int c=0;
    printf("Enter some text\n");
    while((c = getchar()) != EOF)
    {
       
        if(c!= ' '  && c!='\t'&&c!='\n')
        {
            putchar(c);
        }
        else{
            printf("\n");
        }
        
    }
}