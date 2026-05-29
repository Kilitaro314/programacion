#include <stdio.h>

void mostrarMatriz(int matriz[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
}

void encontrarMayor(int matriz[3][3]){
    int mayor = matriz[0][0];
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (matriz[i][j] > mayor) {
                mayor = matriz[i][j];
            }
        }
    }
    printf("El mayor elemento de la matriz es: %d\n", mayor);
}

void encontrarMenor(int matriz[3][3]){
    int menor = matriz[0][0];
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (matriz[i][j] < menor) {
                menor = matriz[i][j];
            }
        }
    }
    printf("El menor elemento de la matriz es: %d\n", menor);
}

int calcular_mcd(int a, int b) {
    while (b != 0) {
        int temporal = b;
        b = a % b;
        a = temporal;
    }
    return a;
}

int main() {
    
    int m1[3][3] = {{1, 2, 3},
                    {4, 5, 6},
                    {7, 8, 9}};
    int m2[3][3] = {{9, 8, 7},
                    {6, 5, 4},
                    {3, 2, 1}};
    
    int D50[] = {1, 2, 5, 10, 25, 50};
    int tamano = sizeof(D50) / sizeof(D50[0]);

    // 1 Mostrar matrices en orden

    printf("Matriz 1:\n");
    mostrarMatriz(m1);
    printf("Matriz 2:\n");
    mostrarMatriz(m2);

    // 2 Encontrar Mayor y menor

    printf("Matriz 1:\n");
    encontrarMenor(m1);
    encontrarMayor(m1);
    printf("Matriz 2:\n");
    encontrarMenor(m2);
    encontrarMayor(m2);

    //

    printf("m.c.d\t");
    for (int i = 0; i < tamano; i++) {
        printf("%d\t", D50[i]);
    }
    printf("\n-------------------------------------------------\n");

    for (int i = 0; i < tamano; i++) {
        // Imprimir el número de la fila actual
        printf("%d\t", D50[i]);
        
        for (int j = 0; j < tamano; j++) {
            int resultado = calcular_mcd(D50[i], D50[j]);
            printf("%d\t", resultado);
        }
        printf("\n");
    }

    return 0;
}