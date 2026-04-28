#include <stdio.h>

int main() {
    int edad, i;

    printf("Ingrese su edad: ");
    scanf("%d", &edad);

    for (i = 1; i <= edad; i++) {
        printf("%d\n", i);
    }

    return 0;
}