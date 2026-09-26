#include <stdio.h>

float sumar(int a, int b) {
    return a + b;
}

float restar(int a, int b) {
    return a - b;
}

float multiplicar(int a, int b) {
    return a * b;
}

float dividir(int a, int b) {
    return (float)a / b;
}

int main() {
    int num1, num2, opcion;

    printf("Ingrese la operacion:\n");
    printf("1. Suma\n2. Resta\n3. Multiplicacion\n4. Division\n");
    printf("Opcion: ");
    scanf("%d", &opcion);

    if (opcion < 1 || opcion > 4) {
        printf("Opcion invalida\n");
        return 0;
    }

    printf("Ingrese el primer numero: ");
    scanf("%d", &num1);

    printf("Ingrese el segundo numero: ");
    scanf("%d", &num2);

    if (opcion == 4 && num2 == 0) {
        printf("No se puede dividir por 0\n");
        return 0;
    }

    float resultado;

    switch (opcion) {
        case 1:
            resultado = sumar(num1, num2);
            break;
        case 2:
            resultado = restar(num1, num2);
            break;
        case 3:
            resultado = multiplicar(num1, num2);
            break;
        case 4:
            resultado = dividir(num1, num2);
            break;
    }

    printf("Resultado: %.2f\n", resultado);

    return 0;
}