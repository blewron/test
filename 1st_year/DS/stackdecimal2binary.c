#include<stdio.h>
#include<stdlib.h>
#define MAX 10

int stack[MAX];
int top=-1;


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

void dec2bi(int dec)
{
    while(dec!=0)
    {
        push (dec%2);
        dec=dec/2;
    }
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

void print()
{
    while(top!=-1)
    {
        printf("%d",pop());
    }
}

int main()
{
    int dec;
    printf("Enter decimal number\n");
    scanf("%d", &dec);

    dec2bi(dec);
    print();

    return 0;
}