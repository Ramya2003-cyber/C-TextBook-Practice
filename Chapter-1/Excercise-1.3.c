#include<stdio.h>
int main()
{
    float low=0,high=300,step=20;
    float f=low,c;
    printf("Fahrenheit  Celcius\n");
    while(f<=high)
    {
       c=(5*(f-32))/9;
        printf("%3.0f  %13.1f\n",f,c);
        f+=step;
    }
}