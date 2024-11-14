#include<stdio.h>
void main(){
    int a,n;
    int b=-1;
    printf("Enter your number :\n");
    scanf("%d",&a);

    if(a<0){
        n=a*b;
        printf("absolute value of %d is:\n%d",a,n);
    }
        else{
            printf("absolute value of %d is:\n%d",a,a);
        }
}