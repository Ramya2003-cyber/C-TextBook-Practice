#include<stdio.h>
unsigned invert(unsigned x,int p,int n)
{
    unsigned y,z;
    y=~0<<p+1-n;
    printf("y=%d\n",y);
    z=~(~0<<p+1);
    printf("z=%d\n",z);
    z=z&y;
    printf("z=%d\n",z);
    y=z&x;
    printf("y=%d\n",y);
    y=y>>p+1-n;
    printf("y=%d\n",y);
    y=~y;
    printf("y=%d\n",y);
    z=~(~0<<n);
    printf("z=%d\n",z);
    y=y&z;
    printf("y=%d\n",y);
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
    unsigned x;
    int p,n;
    printf("ENter a decimal number");
    scanf("%d",&x);
    printf("ENter the position\n");
    scanf("%d",&p);
    printf("ENter the no.of characters to be flipped\n");
    scanf("%d",&n);
    x= invert(x,p,n);
    printf("%d",x);


}