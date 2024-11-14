#include<stdio.h>
#include<stdlib.h>
int create_array(int n);
void display(int *arr, int n);
void bubbleSort( int *arr,int n);
void incertionsort(int *arr,int n) ; 
void selectionSort(int *arr, int n);

int main(){
    int n,arr,ch;
    printf("Enter the number of elements you want in array: ");
    scanf("%d",&n);
    arr=create_array(n);
    display_elements(arr,n);
    printf("\n1. Bubble sort.\n2.Incertion sort.\n3.Selection sort\n4.Exit.");
    printf("\nEnter your choice ->\n");
    scanf(" %d", &ch);
    switch (ch) {
        case 1 :
        bubbleSort(&arr,n);
        break;
        case 2 :
        incertionsort(&arr,n);
        break;
        case 3 :
        selectionSort(&arr,n);
        break;
        default : exit(0);
    
    
    }


}

int create_array(int n){
    int arr[n];

    int i;
    printf("Enter %d integers: \n", n);
    for(i=0; i<n; i++){
        scanf("%d", &arr[i]);
        }
        return arr;
    }

    void display_array(int n,int *arr){
        for(int i;i<n;i++){
            printf("%d ", arr[i]);
            }printf("\n");
    }

    void bubblesort(int *arr, int n){
        int i, j;
        for(i; i<n;i++){
            for(j; j<n-i;j++){
                if(arr[j]>arr[j+1]){
                    int temp=arr[j];
                    arr[j]=arr[j+1];
                    arr[j+1]=temp;
                }
            }
        }

    }
