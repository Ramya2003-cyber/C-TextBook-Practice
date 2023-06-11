#include<stdio.h>
#include <limits.h>
#include <string.h>
void reverse(char a[])
{
    char temp;
    for(int i=0;i<strlen(a)/2;i++)
    {
       // printf("hi");
        temp=a[i];
        a[i]=a[strlen(a)-i-1];
        a[strlen(a)-i-1]=temp;
    }
   // printf("%s\n",a);

}
void itoa(int n, char s[],int min) 
 { 
 int i, sign,c=0; 
 if(n==INT_MIN)
 {
    c++;
    n++;
 }
 if ((sign = n) < 0) /* record sign */ 
 n = -n; /* make n positive */ 
 i = 0; 
 do { /* generate digits in reverse order */ 
 
 if(c){
s[i++] = n % 10 + '1';
c--;}
else
s[i++] = n % 10 + '0';  
 
 }
 
  while ((n /= 10) > 0); /* delete it */ 
 if (sign < 0) 
 s[i++] = '-'; 
 s[i] = '\0';
 //printf("%s",s);
 for(int k=strlen(s);k<min;k++)
 {
    // printf("%d %d\n",k,min);
     s[i++]=' ';
 }
  s[i] = '\0';
 reverse(s); 
 }
 int main()
 {
     printf("Enter an integer\n");
     char a[10];
     int b,min;
     scanf("%d",&b);
     printf("Enter a min width\n");
     scanf("%d",&min);
     itoa(b,a,min);
     printf("%s",a);
 }