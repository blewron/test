#include <stdio.h>

int factorial(int a){
    int b;
    if (a==0){
        return 1;
        }
    while (a>0){
        b=a*factorial(a-1);

    }
    return b;

}

void main(){
    int a, b  ;
    printf("Enter the number you want to know the factorial of : \n "  );
    scanf("%d",&a);

    b=factorial(a);
    printf("\n The Factorial of %d is = %d ",a,b);
    


    
}