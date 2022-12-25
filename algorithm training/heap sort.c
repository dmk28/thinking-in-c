#include <stdio.h>
#include <stdlib.h>

void create_heap(int array[], int start, int end) {
    int parent = array[start];
    int child = start * 2 + 1;
    //checks if parent has two children, and if it does, which is bigger
    while (child <= end) {
        if (child < end) {
            if (array[child] < array[child+1]) {
                child = child+1;
            }
        }
        //Checks if the child is bigger than the parent element
        //if yes, they become the parent
        //The process repeats itself
        if (parent < array[child]) {
            array[start] = array[child];
            start = child;
            child = 2*start+1;
        } else {
            child = end+1;
        }
    }
    //The old parent occupies the place of the last evaluted child element
    array[start] = parent;
}

void heap_sort(int array[], int size) {
    int temp;
    int middle = ((size-1)/2);

    for (int i = middle; i >= 0; i--) {
        create_heap(array, i, size-1);
    }

    for (int i = size - 1; i >= 1; i--) {
        temp = array[0];
        array[0] = array[i];
        array[i] = temp;


        create_heap(array, 0, i-1);
    }
}


int main() {
   
   int array[] = {10, 12, 1, 2, 3, 4};
   
   int size = (sizeof(array)/sizeof(int));
   heap_sort(array, size);

   for (int i = 0; i < size; i++) {
    printf("%d\n", array[i]);
   }
    
    return 0;

}