#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
int htoi(char s[]){
int i=0,sum=0;
for(int i=strlen(s)-1;i>=0;i--)
{
    if(s[i]>='0' && s[i]<='9'){
    sum+=(s[i]-'0')*pow(16,strlen(s)-1-i);
    }
    else{
        sum+=(s[i]-65+11)*pow(16,strlen(s)-1-i);
    }
}
return sum;
}
int main()
{
    char hex[100],s[100];
    printf("Enter the hexadecimal number\n");
    scanf("%s",hex);
   
    int index=0;
    if((hex[1]=='x'||hex[1]=='X')&&(hex[0]=='0'||hex[0]=='o'))
    {
        index=2;
    }
    int j=0;
    for(int i=index;i<strlen(hex);i++)
    {
        if(!((hex[i]>='0'&&hex[i]<='9')||(hex[i]>='a'&&hex[i]<='f')||(hex[i]>='A'&&hex[i]<='F')))
        {
            printf("Invalid input")
            return;
        }
        s[j++]=hex[i];
    }
    s[j]='\0';
    int sum=htoi(s);
    printf("The decimal value is :%d",sum);
}