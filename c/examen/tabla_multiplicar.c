#include <stdio.h>

int main() {

    int inicio, fin, limite;

    printf("Inicio: ");
    scanf("%d", &inicio);

    printf("Fin: ");
    scanf("%d", &fin);

    printf("Limite de multiplicacion: ");
    scanf("%d", &limite);

    for (int i = inicio; i <= fin; i++) {
        for (int j = inicio; j <= limite; j++) {
            printf("%d x %d = %d\n", i, j, i * j);
        }
    }

    return 0;
}