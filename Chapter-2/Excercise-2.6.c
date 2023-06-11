#include<stdio.h>
unsigned setbits(unsigned x,int p,int n,unsigned y)
{
    unsigned  a= x & ~(~0<<p+1-n);
    printf("a=%d\n",a);
    x= x>>(p+1-n);
    printf("x=%d\n",x);
    x=x & (~0<<n);
    printf("x=%d\n",x);
    y=y&~(~0<<n);
    printf("y=%d\n",y);
    x=x | y;
    printf("x=%d\n",x);
    x=x<<(p+1-n);
    printf("x=%d\n",x);
    x=x | a;
    printf("x=%d\n",x);
    return x; 
}
int main()
{
    int x,y,p,n;
    printf("Enter x in decimal\n");
    scanf("%d",&x);
    printf("Enter y in decimal\n");
    scanf("%d",&y);
    printf("Enter the starting position in x\n");
    scanf("%d",&p);
    printf("ENter the no.of bits to be manipulated\n");
    scanf("%d",&n);
    if(p+1-n<0)
    {
        printf("Invalid input");
        return -1;
    }
    x=setbits(x,p,n,y);
    printf("%d",x);
}