#include<stdio.h>
int bitcount(unsigned x){
    int b;
    for(b=0;x!=0;x&=(x-1))
    {
        b++;
    }
    return b;
}
int main()
{
    int x;
    printf("Enter a number\n");
    scanf("%d",&x);
    int b=bitcount(x);
    printf("No.of 1's in the given number is:%d",b);
    
}