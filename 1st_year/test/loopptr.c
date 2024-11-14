#include<stdio.h>
void main(){
    int arr[4]={1,2,3,4};
    int i;
    printf("%lu",sizeof(arr));
    printf("\n%lu",sizeof(arr[0]));
    for (i=0;i<4;i++){
        printf("\nvalue=%d \n address= %p\n",arr[i],arr[i]);
    }

}