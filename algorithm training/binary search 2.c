#include <stdio.h>
#include <stdlib.h>

void quick_sort(int *array, int left, int right) {
    int i = left;
    int j = right;

    int pivot = array[(left+right)/2];


    while (i <= j) {
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

void print_array(int *array, int size) {

    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
}

int binary_search(int *array, int key, int size) {
    int start = 0;
    int finish = size - 1;

    while (start <= finish) {
        int pivot = start + (finish - start)/2;

        if (key == array[pivot]) {
            return pivot;
        }

        if (key < array[pivot]) {
            finish = pivot-1;
        } else {
            start = pivot +1;
        }

    }

    return -1;
}


int main() {
    int array[] = {14, 10, 2, 3, 8, 4, 25, 545, 30, 130, 444};
    int size = sizeof(array)/sizeof(int);
    quick_sort(array, 0, size-1);
    int key = 25;
    print_array(array, size);
    int ret= binary_search(array, key, size);
    printf("\nElement %d is in position %d", key, ret);

    return 0;
}