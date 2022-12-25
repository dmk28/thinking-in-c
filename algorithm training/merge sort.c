#include <stdio.h>
#include <stdlib.h>
void merge_sort(int array[], int size) {
    //if array is less than or equal to 1, return
    if (size <= 1) {
        return;
    } 
    //define midpoint of the array (where it will split)
    int middle = size/2;
    //left is pointing to the first address of the array right now, aka array[0]
    int *left = array;
    //right points to the address at the middle of the array and onwards, so array[3] in array[5]
    int *right = array + middle;
//use of merge sort, making it run left pointer with the size of middle, so from 0 to 3 in an array of six elements
    merge_sort(left, middle);
//use of merge sort with right pointer, making it traverse from 3 to 6 in an array of six elements
    merge_sort(right, size - middle);
//both are recursive
//dynamic allocation for the temporary array
    int *temp = (int *)malloc(size * sizeof(int));
//variables for while are declared here
    int i =0, j = 0, k = 0;
//while i is lower than the middle (aka array/2) and j is lower than size minus middle (aka the elements from 3 and onwards)
    while (i < middle && j < size - middle) {
        if (left[i] < right[j]) {
            temp[k++] = left[i++];
        } else {
            temp[k++] = right[j++];
        }
    }


    while (i < middle) temp[k++] = left[i++];
    while (j < size-middle) temp[k++] = right[j++];

    for (int i = 0; i < size; i++) {
        array[i] = temp[i];
    }


    free(temp);

}

int main() {
    int array[] = {9, 8, 3, 5, 1, 2};
    
    
    int n = sizeof(array)/sizeof(array[0]);
    for (int i = 0; i < n; i ++) printf("%d ", array[i]); printf("\n");
    merge_sort(array, n);
    for (int i = 0; i < n; i++) {
    printf("%d ", array[i]);
  }
  printf("\n");
  return 0;
}