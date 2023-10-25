#include <stdio.h>

int i, j, k;
int n3;
int coefmul[20], expomul[20];

void display(int n, int coef[], int expo[]) {
    for (i = 0; i < n; i++) {
        if (expo[i] == 0) {
            printf("%d", coef[i]);
        } else {
            printf("%dx^%d", coef[i], expo[i]);
        }
        if (i != n - 1) {
            printf(" + ");
        }
    }
    printf("\n");
}

void multiply(int coef1[], int expo1[], int coef2[], int expo2[], int n1, int n2) {
    k = 0;
    for (i = 0; i < n1; i++) {
        for (j = 0; j < n2; j++) {
            coefmul[k] = coef1[i] * coef2[j];
            expomul[k] = expo1[i] + expo2[j];
            k++;
        }
    }
    n3 = k;
    display(n3, coefmul, expomul);
}

void read(int coef1[], int expo1[], int coef2[], int expo2[], int n1, int n2) {
    printf("Enter the first polynomial for multiplication\n");
    for (i = 0; i < n1; i++) {
        printf("Enter the coefficient and exponent: ");
        scanf("%d %d", &coef1[i], &expo1[i]);
    }
    printf("Enter the second polynomial for multiplication\n");
    for (i = 0; i < n2; i++) {
        printf("Enter the coefficient and exponent: ");
        scanf("%d %d", &coef2[i], &expo2[i]);
    }
    printf("\n1st polynomial: ");
    display(n1, coef1, expo1);
    printf("\n2nd polynomial: ");
    display(n2, coef2, expo2);
}

int main() {
    int coef1[10], expo1[10], coef2[10], expo2[10];
    int n1, n2;

    printf("Enter the number of terms in the first polynomial: ");
    scanf("%d", &n1);
    printf("Enter the number of terms in the second polynomial: ");
    scanf("%d", &n2);

    read(coef1, expo1, coef2, expo2, n1, n2);
    printf("\nResult of polynomial multiplication:\n");
    multiply(coef1, expo1, coef2, expo2, n1, n2);

    return 0;
}

