#include <stdio.h>
#include <stdbool.h>
#include <windows.h>

int comparar(const void * a, const void * b){
    return(*(int*)a - *(int*)b);
}

int main() {
    int nota;
    int notas[5];
    int suma = 0;

    for (int i = 0; i < 5; i++){
        printf("Escriba la nota [%d]: ", i+1);
        scanf("%d", &nota);
        if (nota >0 && nota <11){
            notas[i] = nota;
            suma += nota;
        }
        else{
            printf("\nNota invalida");
            i = i -1;
        }
        printf("\n");
    }

    qsort (notas, 5, sizeof(int), comparar);

    printf("Nota media: %d\n", notas[4]/2);
    printf("Nota mas baja: %d\n", notas[0]);
    printf("Nota mas alta: %d", notas[4]);
    printf("Nota promedio: %d", suma/5);

    return 0;
}