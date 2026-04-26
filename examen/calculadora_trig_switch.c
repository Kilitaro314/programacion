#include <stdio.h>
#include <math.h>

#define PI 3.14159265

int main() {

    double angulo, resultado;
    char funcion;

    printf("Angulo en grados: ");
    scanf("%lf", &angulo);

    printf("Funcion (s=sin, c=cos, t=tan): ");
    scanf(" %c", &funcion);

    double rad = angulo * (PI / 180.0);

    switch (funcion) {
        case 's':
        case 'S':
            resultado = sin(rad);
            printf("sin = %.4lf\n", resultado);
            break;

        case 'c':
        case 'C':
            resultado = cos(rad);
            printf("cos = %.4lf\n", resultado);
            break;

        case 't':
        case 'T':
            resultado = tan(rad);
            printf("tan = %.4lf\n", resultado);
            break;

        default:
            printf("Funcion no valida\n");
    }

    return 0;
}