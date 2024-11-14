#include<stdio.h>
void main(){
    int a;
    printf("Enter your year :\n");
    scanf("%d",&a);
    
    if(a%4==0){
        printf(" %d is a leap year. ",a);
    }
    else{
        printf(" %d is not a leap year. ",a);
    }

}