#include<stdio.h>
int sum(int n){
    if(n==0)
    return 0;
    else 
    return (n%10+sum(n/10));
}
void main(){
    int num;
    printf("Enter a positive integer:\n");
    scanf("%d", &num);
    printf("sum of the number:\n%d",sum(num));
    

}