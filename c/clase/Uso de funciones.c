#include <stdio.h>
#include <stdbool.h>
#include <windows.h>

#define MAX 10
// Mostrar elementos de array

void mostrar(int a[]){

    for (int i = 0; i<MAX; i++){

        printf("Elemento %d: %d \n", i+1, a[i]);

    }
}
// Buscar pares en array

int pares (int a[]) {
        int cant = 0;
        for (int i = 0; i<MAX; i++){
            if (a[i]% 2 == 0){
                cant++;
            }
        }

        return cant;
    }
// Saber si un numero es primo

int esPrimo (int n){
    if (n <= 1) return 0;

    for (int i = 2; i < n; i++){
        if (n % i == 0) {
            return 0;
        }
    }

    return 1;
}
//Contar primos en la array

int contarPrimos(int a[]){
    int cant = 0;

    for (int i = 0; i < MAX; i++){
        if (esPrimo(a[i])){
            cant++;
        }
    }

    return cant;
}
// Contar la cantidad de veces que se repite

int seRepite(int a[],int n){
    int cant = 0;
    for (int i = 0; i < MAX; i++){
        if (a[i] == n){
            cant++;
        }
    }
    return cant;
}

// Mostrar array al reves

void mostrarReves(int a[]){
    for (int i = MAX - 1; i >= 0; i--){
        printf("Elemento %d: %d \n", i+1, a[i]);
    }
}

int main() {

    int lista[MAX];
    int i = 0;
    int num = 0;
    int opcion = 0;

    while (i < MAX)
    {
        printf("Ingrese el Elemento %d: ", i);
        scanf("%d", &lista[i]);
        i++;
    }

    mostrar(lista);
    printf("Cantidad de numeros primos: %d", contarPrimos(lista));

    printf("\nEliga un numero para buscar si se repite: ");
    scanf("%d", &num);
    printf("%d se repite: %d veces\n", num, seRepite(lista, num));

    printf("Motrar array al reves? 1. Si, 0. No: ");
    scanf("%d", &opcion);

    if (opcion == 1){
        mostrarReves(lista);
    }
    else {
        printf("Siguiente\n");
    }


    return 0;
   
}