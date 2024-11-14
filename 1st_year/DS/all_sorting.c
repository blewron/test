a   #include <stdio.h>
#include <stdlib.h>

void bubble_sort(int arr[10], int n) {
    int i, j, temp;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void insertion_sort(int arr[10], int n) {
    int i, j, k;
    for (i = 1; i < n; i++) {
        k = arr[i];
        j = i - 1;
        while ((j >= 0) && (arr[j] > k)) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = k;
    }
}

void selection_sort(int arr[10], int n) {
    int i, j, min_idx;
    for (i = 0; i < n - 1; i++) {
        min_idx = i;
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        if (min_idx != i) {
            int temp = arr[i];
            arr[i] = arr[min_idx];
            arr[min_idx] = temp;
        }
    }
} 





void print_array(int arr[10], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[10] = {56, 23, 78, 49, 12, 34, 65, 21, 98, 45};
    int arr2[10] = {56, 23, 78, 49, 12, 34, 65, 21, 98, 45};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: ");
    print_array(arr, n);

    bubble_sort(arr, n);
    printf("Bubble sort array: ");
    print_array(arr, n);

    for (int i = 0; i < n; i++) {
        arr[i] = arr2[i];
    }

    insertion_sort(arr, n);
    printf("Insertion sort array: ");
    print_array(arr, n);

    for (int i = 0; i < n; i++) {
        arr[i] = arr2[i];
    }

    selection_sort(arr, n);
    printf("Selection sort array: ");
    print_array(arr, n);

    for (int i = 0; i < n; i++) {
        arr[i] = arr2[i];
    }

    
    return 0;
}