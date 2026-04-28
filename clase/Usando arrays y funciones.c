#include <stdio.h>
#include <stdbool.h>
#include <windows.h>

#define MAX 5

void mostrar(int a[]){

    for (int i = 0; i<MAX; i++){

        printf("Elemento %d: %d \n", i+1, a[i]);

    }
}

int pares (int a[]) {
        int cant = 0;
        for (int i = 0; i<MAX; i++){
            if (a[i]% 2 == 0){
                cant++;
            }
        }

        return cant;
    }

int main() {

    bool usar_m = false;
    bool usar_a1 = false;
    bool usar_a2 = false;
    bool usar_a3 = false;

    int lista[9] = {0,4,78,5,32,9,77,1,23};
    int aum;

    if (usar_m == true){

        int m[4][4] = {
        {1,2,3,4},
        {5,6,7,8},
        {9,10,11,12},
        {13,14,15,16}
       };
    
       for(int i = 0; i < 4; i++){
        for (int j = 0; j < 4; j++){
            printf("%d ", m[i][j]);
        }
        printf("\n");
    
       }
    }

    if (usar_a1 == true){
        printf("Todos los numeros\n");
        for (int i = 0; i <9; i++){
            printf("Digito %d: %d\n ",i, lista[i]);
        }
    }

    if (usar_a2 == true){
        printf("Numeros par\n");
        for (int i = 0; i <9; i++){
            if (lista[i] % 2 == 0){
                printf("Digito par %d: %d\n ",i, lista[i]);
                aum = aum + lista[i];
            }
        }
        printf("Suma de numeros pares: %d\n", aum);
        printf("Promedio: %d", aum/9);

    }

    if (usar_a3 == true){

        printf("Todos los numeros\n");
        for (int i = 0; i <9; i++){
            printf("Ingrese el elemento %d:\n", i);
            scanf("%d", &lista[i]);
        }
    
        printf("%d", lista[9]);
        Sleep(5);
    
    
        for (int i = 0; i <9; i++){
            printf("Elemento %d: %d\n", i+1, lista[i]);
    
            if (lista[i]%2 == 0) {
                printf("%d\n", lista[i]);
            }
        }
    }
    
    mostrar(lista);
    printf("Cantidad de pares: %d", pares(lista));


    return 0;
   
}