#include<stdio.h>
#include<conio.h>

void fun();

int a=10,b=20;

void main()
{
    printf("a value inside main():%d",a);
    fun();
}

void fun()
{
    printf("\nb value inside fun():%d",b);
    


}