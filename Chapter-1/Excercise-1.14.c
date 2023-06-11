#include<stdio.h>
int main()
{
    printf("Enter some text\n");
    int c=0;
    int a[127]={0,0};
    while ((c=getchar())!=EOF)
    {
        a[c]++;
    }
    for(int i=0;i<127;i++)
    {
        
        if(a[i]!=0){
            printf("%c:",i);
            for(int j=0;j<a[i];j++)
        {
            printf("-");
        }
         printf("\n");
        }
       
        
    }
    
}