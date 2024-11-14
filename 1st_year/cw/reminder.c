#include<stdio.h>
void main()
{
    int a,b,q,reminder;
    printf("Enter your numbers for reminder:\n");
    scanf("%d\n%d",&a,&b);
    q = a/b;
    reminder= a-(b*q);
    printf("the reminder of %d and %d is :\n%d",a,b,reminder);
}

