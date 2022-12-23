#include <stdio.h>

void select_sort(int vector[], int size) {
    int lesser, temp;

    for (int i = 0; i < size-1; i++) {
        lesser = i;
        for (int j = i+1; j < size; j++) {
            if (vector[j] < vector[lesser]) {
                lesser = j;
            }
        }
        if (lesser != i) {
            temp = vector[i];
            vector[i] = vector[lesser];
            vector[lesser] = temp;
        }
    }
}

int main() {
    int vetor[] = {8, 3, 6, 4, 2, 5};
    int size = sizeof(vetor) / sizeof(int);
    printf("Before sorting:\n");
    for (int i = 0; i < size; i++) {
        printf("%d\n", vetor[i]);
    }

    select_sort(vetor, size);
    printf("\nAfter sorting:\n");
    for (int i = 0; i < size; i++) {
        printf("%d \n", vetor[i]);
    }

    return 0;
}
