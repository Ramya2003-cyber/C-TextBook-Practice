#include<stdio.h>
#include <stdarg.h>
#include<ctype.h>
char *getnum(char *p,int *a,int *b)
{
    int neg=0;
    *a=0;*b=0;
   if(*p=='-')
   {
        neg=1;
        ++p;
   }
   if(isdigit(*p))
   {
      *a=*p-'0';
      while(isdigit(*++p))
      {
        *a=10*(*a)+*p-'0';
      }
   }
   if(*p=='.')
   {
      if (isdigit(*++p))
      {
        *b = *p-'0';
        while (isdigit(*++p))
        {
            *b = 10 *(*b)  + *p-'0';
        }
      }
   }
   if(neg)
   {
    *a=-(*a);
   }
   if(*a==0&&*b==0)
   {
    return NULL;
   }
   return p;
}
int minprintf(char *fmt, ...)
{
    va_list ap; /* points to each unnamed arg in turn */
    char *p, *sval,*temp,*temp1;
    int ival;
    double dval;
    int a, b;
    int count=0;
    va_start(ap, fmt); /* make ap point to 1st unnamed arg */
    for (p = fmt; *p; p++)
    {
        if (*p != '%')
        {
            putchar(*p);
            count++;
            continue;
        }
        switch (*++p)
        {
        case 'd':
            ival = va_arg(ap, int);
            count+=printf("%d", ival);
            break;
        case 'f':
            dval = va_arg(ap, double);
            count+=printf("%f", dval);
            break;
        case 's':
            for (sval = va_arg(ap, char *); *sval; sval++,count++)
                putchar(*sval);
            count++;
            break;
        default:
        
            if ((temp1=getnum(p, &a, &b))!=0)
            {
                p=temp1;
                switch (*p)
                {
                case 'd':
                    ival = va_arg(ap, int);
                    count+=printf("%*.*d", a,b,ival);
                    break;
                case 'f':
                    dval = va_arg(ap, double);
                    count+=printf("%*.*f",a,b ,dval);
                    break;
                case 's':
                    for (sval = va_arg(ap, char *),temp=sval; *sval; sval++)
                      ;
                    count+=printf("%*.*s",a,b,temp);
                    break;
                default:
                    putchar(*p);
                    count++;
                    break;
                }
           }
           else
           {
                putchar(*p);
                count++;
           }
              
           break;
        }
    }
    va_end(ap); /* clean up when done */
    return count;
}
int main()
{
    int x=1;
    float y=2.3;
    int c=minprintf("x=%10d y=%f",x,y);
    printf("\n%d",c);
}