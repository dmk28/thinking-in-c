#include <stdio.h>
#include <stdlib.h>



void quick_sort(int array[], int size) {
    int i, j, grouping, temp;

    //For it to be recursive, it has to be greater than a certain size; otherwise, it'll return
    if (size < 2) {
        return;
    } else {
        grouping = array[size/2];
        
        //This loop will behave as if it was two
          for (i = 0, j = size -1;;i++, j--) {
        //Moving elements in the array
            //left hand
        while(array[i] < grouping) {
            i++;
        }
            //right hand
        while(array[j]  > grouping) {
            j--;
        }

        //When will loop stop?
        if (i >= j) {
            break;
        } else {
            temp = array[i];
            array[i] = array[j];
            array[j] = temp;
        }

       
        
          } 
        quick_sort(array, i);
        quick_sort(array + i, size -i);
    }
   
  

}

   int main() {
    int vector[] = {20, 14, 13, 8, 18, 21, 22, 24, 27, 30, 32};
    
    int size = sizeof(vector)/sizeof(vector[0]);
    for (int j = 0; j < size; j++) {
        printf("%d\n", vector[j]);
    }
    printf("\n");
    quick_sort(vector, size);
        printf("\nSorted Array:\n");
    for (int i = 0; i < size; i++) {
        
        printf("%d\n", vector[i]);
    }

}