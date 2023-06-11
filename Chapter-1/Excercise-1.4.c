#include<stdio.h>
int main()
{
    float low=-20,high=150,step=2;
    float f=0,c=low;
    while(f<=high)
    {
       
       f=(c*9)/5+32;
        printf("%3.2f  %7.2f\n",c,f);
        c+=step;
    }
}