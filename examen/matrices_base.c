#include <stdio.h>

int main() {
    int matriz1[3][3], matriz2[3][3], resultado[3][3];


    //“El primer for mueve la fila, el segundo mueve la columna”
    
    // Cargar matriz 1
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            scanf("%d", &matriz1[i][j]);
        }
    }

    // Cargar matriz 2
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            scanf("%d", &matriz2[i][j]);
        }
    }

    // Sumar matrices
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            resultado[i][j] = matriz1[i][j] + matriz2[i][j];
        }
    }

    // Mostrar resultado
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", resultado[i][j]);
        }
        printf("\n");
    }

    return 0;
}