#include<stdio.h>
#include<string.h>
int isvalid(char a,char b)
{
return (a<b&&((isdigit(a)&&isdigit(b))||(isalpha(a)&&isalpha(b)&&((islower(a)&&islower(b))||(isupper(a)&&isupper(b))))));
}
void expand(char a[],char b[])
{
    int i=0,k=0;
  while(a[i]!='\0')
  {
      if(a[i]=='-'&&isvalid(a[i-1],a[i+1]))
      {
          for(int j=1;j<=a[i+1]-a[i-1];j++)
          {
              b[k++]=a[i-1]+j;
          }
          i++;
      }
      else
    {
        b[k++]=a[i];
    }
    
      i++;
  }
}

int main()
{
    int c,i=0;
    char a[100],b[100];
    printf("Enter some text\n");
    while((c=getchar())!=EOF)
    {
        a[i++]=c;
    }
    a[i]='\0';
    expand(a,b);
    printf("%s",b);
}
