#include<stdio.h>
 void table();
 void main(){
   
    printf("Enter the number for which you want its table:\n");
    table();
 }
 void table(){
    int n,i;
    scanf("%d",&n);
    if(n>=0){printf("Table of %d is:",n);
        for( int i=1;i<=10;i++){
            printf("\n%d * %d = %d",n,i,n*i);
        }
    }
    else{printf("\nPlease enter a positive number :");
    table();
    }

 } 
