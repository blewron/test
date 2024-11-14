#include<stdio.h>
void main(){
    float p,r,t,si;
    printf("Enter your values respectivly p,r,t:\n");
    scanf("%f\n%f\n%f",&p,&r,&t);
    si= (p*r*t)/100.0;
    printf("your simple intrest is :\n%f",si);
}