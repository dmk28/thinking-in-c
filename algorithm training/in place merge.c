#include <stdio.h>
#include <stdlib.h>

void merge_sort_inplace(int *array, int size) {
    //Alocate temporary array
    int *temp = malloc(size * sizeof(int));


    for (int block_size = 1; block_size < size; block_size *= 2) {
         //iterate over blocks of increasing size
        for (int start = 0; start < size; start += 2 * block_size ) { 
            int i = start, j = start+block_size, k=0;
            //Merge blocks of the current size
            while (i < start + block_size && j < start + 2 * block_size && j < size) {
                if (array[i] < array[j]) {
                    temp[k++] = array[i++];
                } else {
                    temp[k++] = array[j++];
                }
            }
            //Copy elements of the first block;
            while (i < start + block_size) {
                temp[k++] = array[i++];
            }
            //Copy elements of the second block;
            while (j < start + 2 * block_size && j < size) {
                temp[k++] = array[j++];
            }
    //Copy sorted elements back into original array;
            for (int l = 0; l < k; l++) {
                array[start+l] = temp[l];
            }
        }
    }
    free(temp);
}

int main() {
    int array[] = {9, 8, 3, 5, 1, 2, 35, 20};
    
    
    int n = sizeof(array)/sizeof(array[0]);
    for (int i = 0; i < n; i ++) printf("%d ", array[i]); printf("\n");
    merge_sort_inplace(array, n-1);
    for (int i = 0; i < n; i++) {
    printf("%d ", array[i]);
  }
  printf("\n");
  return 0;
}