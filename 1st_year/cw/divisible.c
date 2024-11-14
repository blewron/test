#include<stdio.h>
void main(){
    int a;
    printf("Enter your number to check if it is divisible by 5 or not :\n");
    scanf("%d",&a);
    if(a%5==0){
        printf(" %d is divisible by 5",a);
        
    }
   else {
    printf("%d is not divisible by 5",a);
   }

}