#include<stdio.h>
void main(){
    int i, j, k, n;
    printf("Enter the numbers of terms in the array :\t");
    scanf("\n%d",&n);
    int A[n], B[n];
    printf("\n Enter your numbers:\n");
    for(i=0;i<n;i++){
        scanf("\n%d",&A[i]);
    }

    for(i=0;i<n;i++){
        for(j=i+1;j<n;){
            if(A[j]==A[i]){
                for(k=j;k<n;k++){
                    A[k]=A[k+1];
                }
                n--;
            }
            else{
                j++;
            }
        }
    }

    printf("\nArray after deleting duplicates:");
    for(i=0;i<n;i++){
        printf("\n%d ",A[i]);
    }


}
