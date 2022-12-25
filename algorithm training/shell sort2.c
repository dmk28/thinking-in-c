#include <stdio.h>
#include <stdlib.h>



void shell_sort(int array[], int size) {
//define group by gap between array positions
   int gap = size/2;
   int temp;
//outer loop: i equals gap size, i is greater than zero, split i by two each step
   for (int i = gap; i > 0; i /= 2) {
    //first array to be compared is initialized in temp variable;

        for (int i = gap; i < size; i++) {
                    int temp = array[i];
                    int j;
                     //inner loop: j is i (or gap), j is compared to gap size AND array at position j minus gap value must be greater than temporary, j will be subtracted by gap.
                    //this for loop makes j equal to i, j checks if it is greater or equal than gap AND whether array[j minus gap]'s value is greater than temp's, at the end of the iteration, it reduces j by gap;
                        for (j = i; j >= gap && array[j-gap] > temp; j -= gap ) {
                            //the value of array[j-gap] is passed onto array[j]
                             array[j] = array[j-gap];
                        }
                        //outside of the loop, temp's value is now passed onto array[j]
                array[j] = temp;
        }


        if (i == 1) {
            //if gap is 1, it performs insertion sort instead of shell sort since it is no longer necessary
            for (int k = 0; k < size; k++) {
                int next = k;

                while ((next != 0) && (array[next] < array[next-1])) {

                    temp = array[next];

                    array[next] = array[next-1];

                    array[next-1] = temp;
                    next--;

                }
            }
        }
   
   
   }

}


int main() {
    int vector[] = {12,4,16,13,8};
    
    int size = sizeof(vector)/sizeof(vector[0]);
    for (int j = 0; j < size; j++) {
        printf("%d\n", vector[j]);
    }
    printf("\n");
    shell_sort(vector, size);
        printf("\nSorted Array:\n");
    for (int i = 0; i < size; i++) {
        
        printf("%d\n", vector[i]);
    }
}