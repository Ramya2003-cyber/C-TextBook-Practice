#include<stdio.h>

#define swap(t,x,y) { t temp;temp=x;x=y;y=temp;}
    
   

int main()
{
    int a = 2, b = 3;
    printf("%d %d\n", a, b);
    swap(int,a,b);
    printf("%d %d\n", a, b);
    float a1 = 2.3, b1 = 3.2;
    printf("%f %f\n", a1, b1);
    swap(float,a1,b1);
    printf("%f %f\n", a1, b1);
}