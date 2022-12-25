#include <stdio.h>
#include <stdlib.h>


//Shell sort uses Insert Sort but instead of iterating through the entire array, it splits the array into smaller groups
//then it combines them

void shell_sort(int vector[], int size) {
    //temp variable
   

    int cluster = 1;

    while (cluster < size) {
        //naturally the cluster has to be lower in size than the actual array;
        cluster = 3 * cluster + 1;
    }

    while (cluster > 1) {
        cluster /= 3;
        //sweep
        for (int i = cluster; i < size; i++) {
            int chng = vector[i];
            int j = i - cluster;
            while (j >= 0 && chng < vector[j]) {
                printf("Sorting\n");
                vector[j + cluster] = vector[j];
                j-=cluster;
            }

            vector[j+cluster] = chng;
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
    shell_sort(vector, size);
        printf("\nSorted Array:\n");
    for (int i = 0; i < size; i++) {
        
        printf("%d\n", vector[i]);
    }
}