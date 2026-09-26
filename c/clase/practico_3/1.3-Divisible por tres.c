#include <stdio.h>

int main() {
    int num;

    printf("Ingrese un numero: ");
    scanf("%d", &num);

    if (num % 3 == 0) {
        printf("Es divisible por 3\n");
    } else {
        printf("No es divisible por 3\n");
    }

    return 0;
}