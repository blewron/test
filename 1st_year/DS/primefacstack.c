#include<stdio.h>
#include<stdlib.h>
#define MAX 50
int top=-1;
int stack[MAX];

int isFULL()
{
    if (top == MAX - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void push(int data)
{
    if (isFULL())
    {
        printf("Stack overflow to add Data:%d\n", data);
        return;
    }
    top++;
    stack[top] = data;
}

int isEMPTY()
{
    if (top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int pop()
{
    int value;

    if (isEMPTY())
    {
        printf("Stack underflow!\n");
        exit(1);
    }
    value = stack[top];
    top--;
    return value;
}

void primefac(int n)
{
    int i=2;
    while(n!=1)
    {
        while(n%i==0)
        {
            push(i);
            n=n/i;
        }
        i++;
    }
    while(top!=-1)
    {
        printf("%d\t",pop());
    }
}

int main()
{   int n;
    printf("Enter number\n");
    scanf("%d", &n);
    printf("The prime factors are:\t");
    primefac(n);

    return 0;
}
    