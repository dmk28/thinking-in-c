//BUBBLE SORT
//it's a simple ordination algorithm
//the idea is to iterate over the array and 'float over' the largest element in the sequence
//despite being considered efficient, it iterates many times over the array in the same positions
//so it is not recommended for programs that require computing speed.
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
void bubble_sort(int vector[], int range) {
//algorithm goes to the RIGHT
int temp;
//declare temporary variable

bool sorted = false;
//this is a way to use booleans for bubble sort
    while (!sorted) {
        //while sorted is false
        sorted = true;
        //declare sorted to true
        for (int i = 0; i < range - 1; i++) {
            //run from i = 0 up to range-1, aka 5 in this example;
            if (vector[i] > vector[i+1]) {
                //if vector at position i is greater than vector at the next position
                    printf("%d is greater than %d\n", vector[i], vector[i+1]);

                    printf("\n\nSorting\n");
                    temp = vector[i+1];
                    //temporary variable will get the next position's value
                    vector[i+1] = vector[i];
                    //next position will get current position's value
                    vector[i] = temp;
                    //current position will be shifted left with previous value
                    sorted = false;
                    //sorted is back to false until all the elements are sorted
            }
        }
    }
}



int main() {
    int vector[] = {12,4,16,13,8};
    
    int size = sizeof(vector)/sizeof(int);
    for (int j = 0; j < size; j++) {
        printf("%d\n", vector[j]);
    }
    printf("\n");
    bubble_sort(vector, size);
    
    for (int i = 0; i < size; i++) {
        printf("%d\n", vector[i]);
    }
}