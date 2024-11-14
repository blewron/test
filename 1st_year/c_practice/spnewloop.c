#include<stdio.h>
void check();
void main(){
    int flag;
    printf("Enter your number to check for prime number:\n");
    check();
}
void check(){
    int n,i;
    int flag=0;
    scanf("%d",&n);
    for(int i=2;i<n;i++){
        if(n%i==0) {
            flag=1;
            break;
            }
        
        }
           

        
        if(flag==0){
        printf("Your number %d is a prime number :",n);}
        else{
        printf("Your number %d is not a prime number :",n);
    }
}
    

    