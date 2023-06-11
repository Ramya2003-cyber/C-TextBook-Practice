#include<stdio.h>
#include <stdarg.h>
void minscanf(char *fmt, ...)
{
    va_list ap;
    char *p;
    int *ival;
    double *dval;
    char *sval,*temp;
    int c;
    va_start(ap, fmt);
    for (p = fmt; *p; p++)
    {
        if(*p=='%')
        {
            switch(*++p)
            {
            case 'd':
                ival = va_arg(ap, int *);
                scanf("%d",ival);
                break;
            case 'f':
                dval = va_arg(ap, double *);
                scanf("%f",dval);
                break;
            case 's':
                temp=va_arg(ap,char *);
                sval=temp;
                while((c=getchar())!=EOF)
                {
                    *sval=c;
                    sval++;
                }
                *sval='\0';
                break;
            default:
                break;
            }

        }
    }
    va_end(ap);
}
int main()
{
    int a;
    float b;
    char d[10];
    minscanf("%d %f %s",&a,&b,d);
    printf("a=%d b=%f d=%s",a,b,d);
}