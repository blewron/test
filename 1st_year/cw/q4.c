#include<stdio.h>

void main() {
    int  i, j, flag = 1;
    int A[3][3];
    printf("Enter elements of the matrix:\n");
    for(i = 0; i < 3; i++) {
        for(j = 0; j < 3; j++) {
            scanf("%d", &A[i][j]);
        }
    }
    for(i = 0; i < 3; i++) {
        for(j = 0; j < 3; j++) {
            if(i == j && A[i][j] != A[i][j]) {
                flag = 0;
                break;
            }
            if(i != j && A[i][j] != 0) {
                flag = 0;
                break;
            }
        }
    }
    if(flag == 1)
        printf("\nThe given matrix is an identity matrix.\n");
    else
        printf("\nThe given matrix is not an identity matrix.\n");

}
