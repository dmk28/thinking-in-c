#include <stdio.h>
#include <stdlib.h>


void maxHeapify (int *array, int index, int heapSize) {
    //declares leftChild. To find the left child of any node in a binary tree, calculate twice its parent's index and add 1.
    //So the leftChild of the parent node would be 2 * 0 + 1 or array[1]
    //The rightChild, thus, would be 2 * 0 + 2 or array[2].
    int leftChild = 2 * index + 1;
    int rightChild = 2 * index + 2;
    //for now, the largest is the index;
    int largest = index;

    //IF leftChild isn't as tall as the HeapSize (the sizing integer determining the size of the tree) and
    //the array at the leftChild's position is larger than the one declared in the largest address
    //the largest will now take the value of the leftChild
    if (leftChild < heapSize && array[leftChild] > array[largest]) {
        largest = leftChild;
    }
    //same thing here, except for the rightChild

    if (rightChild < heapSize && array[rightChild] > array[largest]) {
        largest = rightChild;
    }
    //if the largest IS NOT the index, a new root must be found

    if (largest != index) {
        //initializes temp to take array at the address 'index' and its value
        int temp = array[index];
        //array 'index' now gets passed the address of the largest number of the array, so if it was the leftChild's leftChild, that would be array[4] for example

        array[index] = array[largest];
        //now the array at the address of the largest takes instead the temporary value we saved, the numbers are switched
        array[largest] = temp;
        //repeat this again, with these parameters, until the largest is indeed the parent node
        maxHeapify(array, largest, heapSize);
    }
}

void buildMaxHeap(int *array, int size) {
    for (int i = size / 2 - 1; i >= 0; i--) {
        maxHeapify(array, i, size);
    }
}

void heapSort(int *array, int size) {
    buildMaxHeap(array, size);

    for (int i = size-1; i >= 1; i--) {
        int temp = array[0];
        array[0] = array[i];
        array[i] = temp;

        maxHeapify(array, 0, i);

    }
}



int main()
{
    int array[] = {4, 1, 3, 2, 16, 9, 10, 14, 8, 7};
    int size = sizeof(array) / sizeof(array[0]);

    heapSort(array, size);

    for (int i = 0; i < size; i++)
    {
        printf("%d ", array[i]);
    }

    return 0;
}