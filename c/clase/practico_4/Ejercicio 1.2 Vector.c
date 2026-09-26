#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int main() {
    
    int vector_numeros[10];

    for (int i = 0; i < 10; i++){
        vector_numeros[i] = rand() % 10 + 1;
    }

    for (int i = 0; i < 10; i++){
       int v_cuadrado = pow(vector_numeros[i], 2);
       int v_cubo = pow(vector_numeros[i], 3);

       printf("Numero: %d | Cuadrado: %d | Cubo: %d\n", vector_numeros[i], v_cuadrado, v_cubo);
    }

    return 0;
}