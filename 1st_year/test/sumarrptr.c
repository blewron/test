#include<stdio.h>
void main(){
    int arr[5],sum;
    int i=0;
    for(i=0;i<5;i++){
        scanf("%d",arr+i);

    sum+= *(arr+i);
}
printf("Sum is %d\n",sum);
}