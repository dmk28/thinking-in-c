#include <stdio.h>
#include <stdlib.h>


void quick_sort(int array[], int left, int right) {
    int i = left;
    int j = right;

    int pivot = array[(left+right)/2];

    while ( i <= j) {
        while (array[i] < pivot) i++;
        while (array[j] > pivot) j--;

        if (i <= j) {
            int temp = array[i];
            array[i] = array[j];
            array[j] = temp;
            i++;
            j--;
        }
    }

    if (left < j) quick_sort(array, left, j);
    if (i < right) quick_sort(array, i, right);
}

int main() {
    int array[] = {9, 8, 3, 5, 1, 2};

    int n = sizeof(array)/sizeof(array[0]);
    quick_sort(array, 0, n-1);
    for (int i = 0; i < n; i++) {
    printf("%d ", array[i]);
  }
  printf("\n");
  return 0;
}