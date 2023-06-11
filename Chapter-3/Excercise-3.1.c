#include<stdio.h>
int binsearch(int x,int v[],int n)
{
 int low, high, mid; 
 low = 0; 
 high = n - 1; 
 while (low <high) { 
 mid = (low+high)/2; 
 
 if(v[mid]<x)
 low=mid+1;
 else 
 high=mid;
 } 
 if(x==v[low])
     return low; 
 return -1; /* no match */
}
int main()
{
    int a[]={1,2,3,4,5,6,7,8,9};
    int n=3;
    int pos=binsearch(n,a,9);
    printf("%d",pos);
}