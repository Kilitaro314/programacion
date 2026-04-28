#include <stdio.h>

int main() {
    char nombre[50];
    char sexo;

    printf("Ingrese su nombre: ");
    scanf("%s", nombre);

    printf("Ingrese su sexo (M/F): ");
    scanf(" %c", &sexo);

    if (sexo == 'F' || sexo == 'f') {
        if (nombre[0] < 'M') {
            printf("Grupo A\n");
        } else {
            printf("Grupo B\n");
        }
    } else if (sexo == 'M' || sexo == 'm') {
        if (nombre[0] > 'N') {
            printf("Grupo A\n");
        } else {
            printf("Grupo B\n");
        }
    }

    return 0;
}