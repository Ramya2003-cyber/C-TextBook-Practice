#include<stdio.h>
int main()
{
    int c=1,i=0;
    printf("Enter some text\n");
    while(c=getchar()!=EOF && c!=0){
       
       printf("%d\n",c);
      
    }
    printf("last:%d\n",c);
}