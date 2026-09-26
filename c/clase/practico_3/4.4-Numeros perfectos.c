#include <stdio.h>

int main() {
    int num, i, suma = 0;

    printf("Ingrese un numero: ");
    scanf("%d", &num);

    for (i = 1; i < num; i++) {
        if (num % i == 0) {
            suma += i;
        }
    }

    if (suma == num) {
        printf("Es un numero perfecto\n");
    } else {
        printf("No es un numero perfecto\n");
    }

    return 0;
}