#include  <stdio.h>
#include <stdlib.h>



void bubble_sort(int array[], int size) {
    int next = 0;
    

    for (int i = 0; i < size; i++) {
        //outer for
      for (int j = 0; j < size-1; j++) {
            //inner for:
            if (array[j] > array[j+1]) {
                printf("Condition met. Sorting.\n\n");
                next = array[j];
                array[j] = array[j+1];
                array[j+1]  = next;
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
        printf("\nSorted Array:\n");
    for (int i = 0; i < size; i++) {
        
        printf("%d\n", vector[i]);
    }
}