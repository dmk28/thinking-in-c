#include <stdio.h>


void merge(int vetor[], int inicio1, int fim1, int inicio2, int fim2){
    int temp[50];

    int i, j, k;

    i = inicio1;
    j = inicio2;
    k = 0;
    while (i <= fim1 && j <= fim2) {
        if (vetor[i] < vetor[j]) {
            temp[k++] = vetor[i++];
        } else {
            temp[k++] = vetor[j++];
        }
    }

    while ( i <= fim1) {
        temp[k++] = vetor[i++];
    }
    while (j <= fim2) {
        temp[k++] = vetor[j++];
    }

    for (i = inicio1, j=0; i<= fim2; i++, j++) {
        vetor[i] = temp[j];
    }

}

void merge_sort(int vetor[], int inicio, int fim) {
    //condição de parada da recursão
    if (inicio < fim) {
        //calcular o meio do vetor
        int meio = (inicio + fim)/2;
    //rec esquerda
        merge_sort(vetor, inicio, meio);
    //rec direita
        merge_sort(vetor, meio+1, fim);
        merge(vetor, inicio, meio, meio+1, fim);
    }

   
}

int main() {
    int array[] = {9, 8, 3, 5, 1, 2, 35, 20};
    
    
    int n = sizeof(array)/sizeof(array[0]);
    for (int i = 0; i < n; i ++) printf("%d ", array[i]); printf("\n");
    merge_sort(array,0, n-1);
    for (int i = 0; i < n; i++) {
    printf("%d ", array[i]);
  }
  printf("\n");
  return 0;
}