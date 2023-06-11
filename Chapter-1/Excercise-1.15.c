
#include<stdio.h>
int convert(int);
int main()
{
    float low=0,high=300,step=20;
    float f=low,c;
    while(f<=high)
    {
       c=convert(f);
        printf("%3.0f  %6.1f\n",f,c);
        f+=step;
    }
}
int convert(int f)
{
    return (5*(f-32))/9;
}