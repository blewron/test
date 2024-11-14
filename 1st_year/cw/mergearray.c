#include<stdio.h>
void main(){
    int i,j,k,n,m=0;
    printf("Enter the number of element in both the arrays:\n");
    scanf("%d",&n);
    printf("Enter the elements of the first array to merge:\n");
    int A[n];
    int B[n];
    for(i=0;i<n;i++){
        scanf("%d",&A[i]);
    }
    printf("Enter the elements of the second array to merge:\n");
    for(j=0;j<n;j++){
        scanf("%d",&B[j]);
    }
    int C[2*n];
    for ( i = 0; i < n; i++)
    { 
        C[i]=A[i];
        m++;

    }
    for ( j = 0; j< n; j++)
    {
        C[m]=B[j];
        m++;
    }
    printf("Ther merged array is :\n");
    for ( i = 0; i<2*n; i++)
    {
        printf("%d",C[i]);
    }
    

        


}