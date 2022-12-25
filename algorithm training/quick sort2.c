#include <stdio.h>
#include <stdlib.h>

//quick_sort takes in an array, a variable 'left' as an integer, a variable 'right' as an integer as well
void quick_sort(int array[], int left, int right) {
    int i = left; //left = 0
    int j = right; //right = n-1
//initializing i and j as left and right respectively, left will go UP, right will go DOWN the iteration
    int pivot = array[(left+right)/2];
//chose pivot to be array[(sum of left and right) split by two]

//while i is lower than or equal to j
    while ( i <= j) {
        //while array[i] is lower than pivot, increase by 1 step
        while (array[i] < pivot) i++;
        //while array[j] is greater than pivot, decrease by 1 step
        while (array[j] > pivot) j--;

        if (i <= j) {
            //if i is greater than or equal to j:
            int temp = array[i];
            //declare temp as array[i];
            array[i] = array[j];
            //array[i] gets array[j]'s value passed to it
            array[j] = temp;
            //temp is now in array[j]
            i++; //raise one step (left side)
            j--; //lower one step (right side)
        }
    }
    //recursive call if left is lower than j and right is greater than i
    if (left < j) quick_sort(array, left, j);
    if (i < right) quick_sort(array, i, right);
}

int main() {
    int array[] = {9, 8, 3, 5, 1, 2};

    int n = sizeof(array)/sizeof(array[0]);
    //quick_sort is passed with array, 0 as the left hand position and n-1 as the right hand position
    quick_sort(array, 0, n-1);
    for (int i = 0; i < n; i++) {
    printf("%d ", array[i]);
  }
  printf("\n");
  return 0;
}