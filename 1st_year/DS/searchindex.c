#include<stdio.h>
void main(){
    int a,n,i,arr[100];
    printf("Enter the number of elements you want in array:\n");
    scanf("%d",&n);
    printf("\nEnter the elements of the array" );
    for(i=0;i<n;i++){
        printf("\n Enter element %d : ", i+1);
        scanf("%d", &arr[i]);
        }
        printf("Enter your number for searching\n");
        scanf("%d",&a);
        for(i=0;i<n;i++){
            if (a==arr[i]) {
                printf("\n%d is present at index = %d\n",a, i);
        }


    }
}
