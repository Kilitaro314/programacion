#include <stdio.h>

int main() {
    int i, j;

    // El bucle externo comienza en 10 y disminuye hasta 1
    for (i = 10; i >= 1; i--) {
        
        // El bucle interno imprime números desde 1 hasta el valor actual de i
        for (j = 1; j <= i; j++) {
            printf("%d ", j);
        }
        
        // Salto de línea al terminar cada fila
        printf("\n");
    }

    return 0;
}
