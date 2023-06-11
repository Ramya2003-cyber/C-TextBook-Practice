#include<stdio.h>
unsigned rightrot(unsigned x,int n)
{
    unsigned  a= x & ~(~0<<n);
    x=x&~0<<n;
    x=x>>n;
    a=a<<32-n;
    x=x|a;
    return x;
}
int main()
{
    unsigned x;
    int n;
    printf("ENter a decimal number\n");
    scanf("%d",&x);
    printf("ENter no.of bits to be rotated right\n");
    scanf("%d",&n);
    x=rightrot(x,n);
    printf("Decimal after right rotation is:%d",x);
    
}