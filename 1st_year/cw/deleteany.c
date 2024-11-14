#include<stdio.h>

int main(){
    int i, j=0, n, k;
    printf("Enter the number of array elements you want:\n");
    scanf("%d",&n);

    int A[n];
    printf("Enter the elements of the array:\n");
    for(i=0; i<n; i++){
        scanf("%d",&A[i]);
    }

    printf("Enter the location of element to delete it:\n ");
    scanf("%d",&k);

    for(i=k; i<n-1; i++){
        A[i] = A[i+1];
    }
    
    n--;

    printf("\nThe modified array is:\n");
    for(i=0; i<n; i++){
        printf("%d ", A[i]);
    }
    
    return 0;
}
