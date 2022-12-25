#include <stdio.h>
#include <stdlib.h>


void merge_sort(int array[], int size) {

    if (size <= 1) {
        return;
    }
    //defining split point as size/2
     // Divide the array into two halves
    int split = size/2;
    //declare pointer variable left as pointing to the start of the array
    int *left = array;
    //declare pointer variable right as pointing to the middle of the array onwards
    int *right = array + split;
  // Call merge sort recursively on each half
    merge_sort(left, split);
    merge_sort(right, size - split);
     // Create a temporary array to hold the sorted elements
    int *temporary = (int *) malloc(size * sizeof(int));
// Initialize variables to keep track of the current position in each half of the array
    int i = 0, j = 0, k = 0;

    // Compare the elements at the current positions in each half of the array,
    // and add the smaller element to the temporary array
    while (i < split && j < size - split) {
        if (left[i] < right[j]) {
            temporary[k++] = left[i++];
        } else {
            temporary[k++] = right[j++];
        }
    }
 // Add the remaining elements from the other half to the temporary array
    while (i < split) {
        temporary[k++] = left[i++];
    }
    while (j < size - split) {
        temporary[k++] = right[j++];
    }


    // Copy the elements from the temporary array back into the original array
    for (i = 0; i < size; i++) {
        array[i] = temporary[i];
    }
    free(temporary);
}



int main() {
    int array[] = {9, 8, 3, 5, 1, 2, 35, 20};
    
    
    int n = sizeof(array)/sizeof(array[0]);
    for (int i = 0; i < n; i ++) printf("%d ", array[i]); printf("\n");
    merge_sort(array, n);
    for (int i = 0; i < n; i++) {
    printf("%d ", array[i]);
  }
  printf("\n");
  return 0;
}