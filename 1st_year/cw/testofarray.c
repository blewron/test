// Include the standard input/output library
#include <stdio.h>

// Define a function to reverse an array
void main()
{
    int arr[5],n;
  // Initialize left and right pointers
  int a = 0;
  int z= n - 1;

  // Loop until left is greater than or equal to right
  while (a < z) {
    // Swap the elements at left and right indices
    int temp = arr[a];
    arr[a] = arr[z];
    arr[z] = temp;

    // Increment left and decrement right
    a++;
    z++;
// Loop through the array elements
  for (int i = 0; i < n; i++) {
    // Print the element with a space
    printf("%d ", arr[i]);
  }
  // Print a new line
  printf("\n");


// Test the function with some examples
  // Declare and initialize an array of size 5

  // Prompt the user to enter the array elements
  printf("Enter the array elements: ");

  // Loop through the array indices
  for (int i = 0; i < 5; i++) {
    // Scan the element from the user input
    scanf("%d", &arr[i]);
  }

  // Print the original array
  printf("Original array:\n %d",arr[5]);




  // Print the reversed array
  printf("Reversed array:\n %d");

  }
