#include<stdio.h>
int main()
{
    float low=0,high=300,step=20;
    float f=low,c;
    f=high;
    for(;f>=low;)
    {
       c=(5*(f-32))/9;
        printf("%3.0f  %6.1f\n",f,c);
       f-=step;
    }
}