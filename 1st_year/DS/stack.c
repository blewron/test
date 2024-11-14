#include<stdio.h>
int isFULL();
void pop();
int isEmpty();
void push(int data);
int stack[5];
int top=-1;
int main()
{
    push(1);
    push(2);
    push(3);
    push(4);
    push(5);
    push(6);
    pop();
    pop();
    pop();
    pop();


    for(int i=top;i>=0;i--)
    {
        printf("Data:%d\n",stack[i]);
    }
}

int isFULL()
{
    if(top==4)
    {
        return 1;
    }
    else{
        return 0;
    }
}

void push(int data)
{
    if(isFULL())
    { 
        printf("Stack overflow to add Data:%d\n",data);
        return;
    }
    top++;
    stack[top]=data;
}

void pop(){
    if(isEmpty())
    {
        printf("Stack Underflow to remove Data");
        return ;
        }
        else{
            top--;
        }
        return ;


}
int isEmpty(){
    if (top == -1){
        
        return 1;
    }
    else{
        
        return 0;
    }


}
     