#include <stdio.h>
#include <stdlib.h>



void quick_sort(int array[], int size) {
    int i, j, grouping, temp;

    //For it to be recursive, it has to be greater than a certain size; otherwise, it'll return
    if (size < 2) {
        return;
    } else {
        //my pivot is called grouping, and the position chosen is the one that is size/2 in the array.
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

          //recursive call
        quick_sort(array, i);
        quick_sort(array + i, size -i);
    }
   
  

}

   int main() {
      int vector[99] = {99, 98, 97, 96, 95, 94, 93, 92, 91, 90, 89, 88, 87, 86, 85, 84, 83, 82, 81, 80, 79, 78, 77, 76, 75, 74, 73, 72, 71, 70, 69, 68, 67, 66, 65, 64, 63, 62, 61, 60, 59, 58, 57, 56, 55, 54, 53, 52, 51, 50, 49, 48, 47, 46, 45, 44, 43, 42, 41, 40, 39, 38, 37, 36, 35, 34, 33, 32, 31, 30, 29, 28, 27, 26, 25, 24, 23, 22, 21, 20, 19, 18, 17, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    
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