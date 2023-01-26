#include <stdio.h>

int main() {
    int i, n;
    int firstNumber;

    int progNumber;
    printf("Enter the number of steps in the arithmetic progression:");
    scanf("%d", &n);
    printf("Enter the number after 1 that each step will multiply by:");
    scanf("%d", &progNumber);
   
    for (i  = 0; i <= n; i++ ) {
        
        firstNumber = 1 +  (progNumber - 1) * i;

        printf("%d\n", firstNumber);
    }

}