#include<stdio.h>
void search(int mat[4][4], int target){
    int i=0, j=3;
    while(i<4&&j >=0){
        if (mat[i][j]==target){
            printf("Element found at (%d,%d)\n",i,j);
            return;
        }
        if (mat[i][j]> target)
        j--;
        else
        i++;
    }
    printf("Element not found\n");
}
void main(){
    int mat[4][4];
    int target;
    printf("Enter the elements of the 4x4 matrix:\n");
    for(int i=0;i<4;i++)
      for(int j=0;j<4;j++)
      scanf("%d",&mat[i][j]);
      printf("Enter the target number:");
      scanf("%d",&target);
      search(mat,target);
}