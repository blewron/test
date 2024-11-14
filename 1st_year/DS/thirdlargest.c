#include <stdio.h>

void main(){
    int n, arr[100];
    int largest,secondlargest,thirdlargest;
    printf("Enter the number of elements you want in array:\n ");
    scanf("%d", &n);
    for(int i=0;i<n;i++){
        printf("\n Enter element %d : ", i+1);
        scanf("%d", &arr[i]);
        }
        for(int i = 0; i < n-1; i++) {
            for (int j = i + 1; j < n; j++) {
                if(arr[i] > arr[j]){
                    int temp = arr[i];
                    arr[i] = arr[j];
                    arr[j] = temp;
                    }
                    }
        }
        largest=arr[n-1];
        secondlargest=arr[n-2];
        thirdlargest=arr[n-3];
        printf("\n the largest number is :\n%d",largest);
        printf("\n The Second Largest Number is : \n%d",secondlargest);
        printf("\n The Third Largest Number is : \n%d",thirdlargest);
        


}