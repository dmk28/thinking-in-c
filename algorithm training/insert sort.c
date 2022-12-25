#include <stdio.h>
#include <stdlib.h>

//insert sort
//aka insertion sort, simple more efficient algorith in smaller vectors
//runs a vector from left to right and as it advances, aligns
//values to its left


void insertion_sort(int vector[], int range) {
    //initialize variable to switch the vector[position]
int switched;
//for i equals 0, i is lower than range of the array, i gains one every iteration/
for (int i = 0; i < range; i++) {
    //initialize 'next', which is the number that will be originally iterated
    int next = i;   
    //if i = 0, next = 0
    while ((next != 0) && (vector[next] < vector[next-1])) {
        printf("%d is less than %d!\n\n", vector[next], vector[next-1]);
        //while next is different than zero AND vector[next] is LESSER THAN its previous iteration:
        switched = vector[next];
        //this will only start working at i = 1
        //switched is now declared to be vector[1], minimally
        vector[next] = vector[next-1];
        //vector[next] now has the value of its previous iteration if that iteration is greater than the current iteration

        vector[next-1] = switched;
        //previous vector iteration is switched with the temporary variable since it is lower than the current
        next--; //walk back one step (so now next is 0 if it was 1, 1 if it was 2, and so on; this will map the next comparison)
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
    insertion_sort(vector, size);
    
    for (int i = 0; i < size; i++) {
        printf("%d\n", vector[i]);
    }
}