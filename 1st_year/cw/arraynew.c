#include<stdio.h>
int main()
{
    int a[100],n,i,b,c=0;
    printf("enter the number to be checked");
    scanf("%d",&b);
    printf("enter the size of the array");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("enter the number");
        scanf("%d",&a[i]);
    }
    for(i=0;i<n;i++)
    {
        if(a[i]==b)
        {
        c=c+1;
        }
    }
    if(c==0)
    {
        printf("the %d is not present in array",b);
    }
    else
    {
        printf("the %d occurs %d times",b,c); 
    }
}