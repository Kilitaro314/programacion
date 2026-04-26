#include <stdio.h>

int main() {
    int cantidad, caras = 0, secas = 0, tiro;

    printf("Cuantas tiradas hara?\n");
    scanf("%d", &cantidad);

    int realizadas = 0;

    while (realizadas < cantidad) {

        printf("Tirada %d (Cara = 1, Seca = 2)\n", realizadas + 1);
        scanf("%d", &tiro);

        if (tiro == 1) {
            caras++;
            realizadas++;
        }
        else if (tiro == 2) {
            secas++;
            realizadas++;
        }
        else {
            printf("Numero no valido, intente de nuevo\n");
        }
    }

    printf("Caras: %d\n", caras);
    printf("Secas: %d\n", secas);

    float probC = (float)caras / cantidad * 100;
    float probS = (float)secas / cantidad * 100;

    printf("Probabilidad Cara: %.2f%%\n", probC);
    printf("Probabilidad Seca: %.2f%%\n", probS);

    return 0;
}