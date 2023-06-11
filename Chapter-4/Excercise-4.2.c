
#include <stdio.h> 
#define MAXLINE 100 
#include <ctype.h>
double atof(char s[]) ;
double atof(char s[])
 {
     double val,val1, power;
     int i, sign,sign1;
     for (i = 0; isspace(s[i]); i++) /* skip white space */
         ;
     sign = (s[i] == '-') ? -1 : 1;
     if (s[i] == '+' || s[i] == '-')
         i++;
     for (val = 0.0; isdigit(s[i]); i++)
     {
    
         val = 10.0 * val + (s[i] - '0');
     }
         
     if (s[i] == '.')
         i++;
     for (power = 1.0; isdigit(s[i]); i++)
     {
         val = 10.0 * val + (s[i] - '0');
         power *= 10;
        
     }
     if(s[i]=='e')
     i++;
     sign1 = (s[i] == '-') ? -1 : 1;
     if (s[i] == '+' || s[i] == '-')
         i++;
     for (val1 = 0.0; isdigit(s[i]); i++)
         val1 = 10.0 * val1 + (s[i] - '0');
     if(sign1==1)
     {
         for(int j=0;j<val1;j++)
         {
             power=power/10;
         }
     }
     else
     {
         for(int j=0;j<val1;j++)
         {
             power=power*10;
         }
     }
     return sign * val / power;
 }

 int main() 
 { 
 double sum,atof(char[]); 
 char line[MAXLINE]; 
 gets(line);
 sum = atof(line);
// printf("%d,%d\n", count2);
 printf("%.2e\n",sum ); 
 return 0; 
 }

