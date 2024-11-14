#include <stdio.h>
void main (){
    int a ,b ,n, arr[100];

    printf("Enter the size of arrray :\n");
    scanf("%d",&n);
    printf("\n Enter elements of array : \n");
    for(int i = 0;i<n;i++){
        printf("Element %d: ",i+1);
        scanf("%d", &arr[i]);
        }
        a=arr[0];
        for(int j = 1;j<n;j++) {
            if(arr[j] > a)   
            a = arr[j];      
            }
            b = arr[0];
            for(int k = 1;k<n;k++) {
                if(arr[k] < b)
                b = arr[k];
                }
    printf("The largest element of the  array is :\n");
    printf("%d",a);
    printf("\nThe smallest element of the array is :\n");
    printf("%d",b);

}