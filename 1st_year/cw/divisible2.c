#include<stdio.h>
void main(){
    int a;
    printf("check wheter your number is divisible by 5 or 3:\n");
    scanf("%d",&a);
    if(a%5==0 || a%3==0){
        printf(" %d is divisible by 5 or 3.",a);
    }
    else {
        printf(" %d is not divisible by 5 or 3",a);
    }
}