#include <stdio.h>

int main() {
    int idade;
    printf("Qual é a sua idade? ");
    scanf("%d", &idade);

    if (idade < 18) {
        printf("Você é menor de idade.");
    }
    else if (idade > 18 && idade < 32) {
        printf("Você é um jovem adulto.");
    }
    else if (idade > 32 && idade < 65) {
        printf("Você é adulto.");
    }
    else if (idade > 65) {
        printf("Você é um idoso.");
    }

 printf("Sua idade é de: %d", idade);

 return 0;
}