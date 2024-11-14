#include<stdio.h>

void main(){
    int i, n,arr[100];
    int frq=1;
    printf("Enter the number of elements you want in array:\n ");
    scanf("%d",&n);
    printf("Enter the element of the array:\n");
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
        }
    for(int i=0;i<n;i++){
        for(int j =0;j<n;j++){
            if(arr[j] == arr[i] ){
                frq++;
                i++;
            }
            else{
                continue;
            }
            printf("frequency of %d is :%d\n",arr[i],frq);


            frq=1;
        }
    }

}