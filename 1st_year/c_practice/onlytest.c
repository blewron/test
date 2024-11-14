// #include<stdio.h>
//  void main(){
//     int n, i , arr[10];
//     printf("Enter the  elements are  in array : \n");
//     for (int i=0; i<10; i++){
//       scanf("%d",&arr[i]);
//     }
//     printf(" Enter your number for checking : \n");
//     scanf("%d", &n);
//     for (int i=0; i<10;i++){
//       if (n==arr[i]){
//          printf("\n %d is present at index %d ",n,i);
//       }
//     }
//  } 
#include <stdio.h>

int factorial(int n) {
    if (n == 0) {
        return 1;
    } else {
        return n * factorial(n - 1);
    }
}

int main() {
    int a, b;

    printf("Enter the number you want to know the factorial of : \n");
    scanf("%d", &a);

    b = factorial(a);
    printf("The factorial of %d is %d.\n", a, b);

    return 0;
}