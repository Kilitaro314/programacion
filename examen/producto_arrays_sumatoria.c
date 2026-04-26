#include <stdio.h>

int main() {

    int numeros_1[3] = {1,2,3};
    int numeros_2[3] = {4,5,6};
    int resultados[3];
    int sumatoria = 0;

    for (int i = 0; i < 3; i++) {
        resultados[i] = numeros_1[i] * numeros_2[i];
        printf("%d x %d = %d\n", numeros_1[i], numeros_2[i], resultados[i]);
        sumatoria += resultados[i];
    }

    printf("Suma final = %d\n", sumatoria);

    return 0;
}