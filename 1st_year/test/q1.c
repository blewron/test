#include<stdio.h>
int sum(int n){
if(n==0)
return 0;
int s,r;
while(n==0){r=n%10;
n=n/10;
s=sum(n)+r;}
}
int main(){
int n;
printf("Enter the positive integer :");
scanf("%d",&n);
int ans= sum(n);
printf("The reg sum of digits -%d",ans);
return 0;}

