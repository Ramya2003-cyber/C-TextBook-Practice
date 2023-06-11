#include<stdio.h>
#include <string.h>
void removeblanks(char a[],char b[])
{
    int j=0;
   // printf("%d\n",strlen(a))  ;
    for(int i=0;i<strlen(a);i++)
    {
      
        if(a[i]==' ')
        {
            b[j++]=a[i];
            while(a[i]==' '||a[i]=='\t')
            {    
                
                  i++;          
            }
            b[j++]=a[i];
        }
        else if(a[i]=='\t')
        {
            b[j++]=' ';
            while(a[i]==' '||a[i]=='\t')
            {    
                   
                  i++;          
            }
            b[j++]=a[i];
        }
        else if(a[i]=='\n')
        {
          b[j++]=a[i];
            while(a[i++]=='\n')
            {               
            }
            printf("%c\n",a[i-1]);
            b[j++]=a[i-1];  
            b[j++]=a[i];
        }
        else{
            b[j++]=a[i];
        }
    }
  
    b[j]='\0';
    return ;
}
int main()
{
    int c,i=0;
    char a[500],b[500];
    printf("Enter some text\n");
    while((c=getchar())!=EOF)
    {
        a[i++]=c;
    }
    a[i]='\0';
    removeblanks(a,b);
    printf("%s",b);
}

