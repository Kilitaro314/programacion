#include <stdio.h>

int main() {
    int anioNacimiento, anioActual = 2026, edad;

    printf("Ingrese su anio de nacimiento: ");
    scanf("%d", &anioNacimiento);

    edad = anioActual - anioNacimiento;

    printf("La edad es: %d\n", edad);

    return 0;
}