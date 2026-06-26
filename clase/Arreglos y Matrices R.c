#include <stdio.h>

#define MAX 100

// Prototipos
void cargarMatriz(int m[MAX][MAX], int f, int c);
void mostrarMatriz(int m[MAX][MAX], int f, int c);
void matrizAArray(int m[MAX][MAX], int f, int c, int arr[], int *n);
void ordenarDesc(int arr[], int n);
int esPalindromo(int arr[], int n);
void mostrarArray(int arr[], int n);

int main() {

    int matriz[MAX][MAX];
    int array[MAX * MAX];
    int n = 0;

    int filas, columnas;

    printf("Ingrese filas: ");
    scanf("%d", &filas);

    printf("Ingrese columnas: ");
    scanf("%d", &columnas);

    // 1. Cargar matriz
    cargarMatriz(matriz, filas, columnas);

    printf("\nMatriz original:\n");
    mostrarMatriz(matriz, filas, columnas);

    // 2. Convertir a array
    matrizAArray(matriz, filas, columnas, array, &n);

    printf("\nArray generado:\n");
    mostrarArray(array, n);

    // 3. Ordenar
    ordenarDesc(array, n);

    printf("\nArray ordenado (desc):\n");
    mostrarArray(array, n);

    // 4. Palíndromo
    if (esPalindromo(array, n)) {
        printf("\nEs palindromo\n");
    } else {
        printf("\nNo es palindromo\n");
    }

    return 0;
}

void cargarMatriz(int m[MAX][MAX], int f, int c) {
    for (int i = 0; i < f; i++) {
        for (int j = 0; j < c; j++) {
            printf("Elemento [%d][%d]: ", i, j);
            scanf("%d", &m[i][j]);
        }
    }
}

void mostrarMatriz(int m[MAX][MAX], int f, int c) {
    for (int i = 0; i < f; i++) {
        for (int j = 0; j < c; j++) {
            printf("%d ", m[i][j]);
        }
        printf("\n");
    }
}



void matrizAArray(int m[MAX][MAX], int f, int c, int arr[], int *n) {
    *n = 0;

    for (int i = 0; i < f; i++) {
        for (int j = 0; j < c; j++) {
            arr[*n] = m[i][j];
            (*n)++;
        }
    }
}

void ordenarDesc(int arr[], int n) {
    int aux;

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (arr[j] < arr[j + 1]) {
                aux = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = aux;
            }
        }
    }
}

int esPalindromo(int arr[], int n) {

    int i = 0;
    int j = n - 1;

    while (i < j) {
        if (arr[i] != arr[j]) {
            return 0;
        }
        i++;
        j--;
    }

    return 1;
}