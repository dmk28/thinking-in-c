#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define N 3

double polynomial(double a[], int n, double x); //declara o polinomio

void derivative(double a[], int n, double d[]);
/* a = vetor de coeficientes, n = grau de polinomio, x= ponto em que se deseja avaliar a função */
int main() {
    double coef[N] = {6, -5, 1};
    int degree = 3;
    printf("%f\n", polynomial(coef, degree, 0));
    double coefDerivate[N-1] = {0};
    derivative(coef, degree, coefDerivate);
    printf("%fx + %f\n", polynomial(coefDerivate, degree, 0));
}

double polynomial(double a[], int n, double x) {
    double sum = 0;
    int i;
    for (i = 0; i < n; i++) {
        sum += a[i]*pow(x,i);
    }
    return sum;
}

void derivative (double a[], int n, double d[]) {
    int i;
    for (i = 1; i <= n; i++) {
        d[i-1] = a[i]*i;
    }
}