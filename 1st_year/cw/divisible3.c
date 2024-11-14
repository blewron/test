#include<stdio.h>
void main(){
    int a;
    printf("check the number is divisible by 3 or 5 but not divisible by 15:\n");
    scanf("%d",&a);
    if (a%5==0 || a%3==0){
        if (a%15!=0){
            printf(" %d is divisible by 3 or 5 but not by 15.",a);
        }
        else {
            printf(" %d is divisible by 15.",a);
        }
    }
    else{
        printf(" %d is not divisible by 3 or 5. ",a);
    }
}