#include <stdio.h>
int main()
{
    int c = 0;
    int count[100]={0,0},j=0;
    printf("Enter some text\n");
    int max=0;
    while ((c = getchar()) != EOF)
    {

        if (c != ' ' && c != '\t' && c != '\n')
        {
            count[j]++;
        }
        else
        {
            j++;
        }
    }
   
    for(int i=0;i<j;i++)
    {
       if(count[i]>max)
       {
           max=count[i];
       }
    }
    for(int i=max;i>0;i--)
    {
        for(int k=0;k<j;k++)
        {
            if(count[k]>=i)
            {
                printf("|   ");
            }
            else
            {
                printf("    ");
            }
        }
        printf("\n");
    }
    
}