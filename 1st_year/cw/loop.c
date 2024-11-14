#include<stdio.h>
void main(){
    int n,arr[n], i,j;
    printf("Enter your number of array you want :\n");
    scanf("%d",&n);
    printf("Enter the elements of array you want to arrange:\n");

    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            scanf("%d",&arr[i]);
            if(arr[i]<0){
            printf("\n%d",arr[i]);
            }
            else{
                for(j=i+1;j<n;j++){
                    printf("\n%d",arr[i]);
                }

            }
        }
    }
    
}