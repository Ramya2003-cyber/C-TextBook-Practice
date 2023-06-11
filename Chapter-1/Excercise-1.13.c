
#include<stdio.h>
int main()
{
    int c=0,i=2;
    printf("Enter some text\n");
    
    while((c = getchar()) != EOF)
    {
        
        if(c!=' '&&c!='\t'&&c!='\n')
        {
            printf("-");
        }
        else{
            printf("\n");
        }
        
    }
}