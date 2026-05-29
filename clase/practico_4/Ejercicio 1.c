#include <stdio.h>
#include <stdlib.h>

#define TAM 10
#define TAM_D 20

// Comparador para Q Sort

int comparar(const void *a, const void *b) {
    return (*(int*)b - *(int*)a);
}

// Cargar arreglos

void cargarArreglo(int arr[], int tam, char nombre[]) {

    for (int i = 0; i < tam; i++) {
        printf("Ingrese %s[%d]: ", nombre, i);
        scanf("%d", &arr[i]);
    }
}

// Mostrar arreglos

void mostrarArreglo(int arr[], int tam, char nombre[]) {

    printf("\nArreglo %s:\n", nombre);

    for (int i = 0; i < tam; i++) {
        printf("%d ", arr[i]);
    }

    printf("\n");
}

// Sumar arreglos

void sumarArreglos(int a[], int b[], int c[], int tam) {

    for (int i = 0; i < tam; i++) {
        c[i] = a[i] + b[i];
    }

}

// Ordenar arreglos

void ordenarArreglo(int arr[], int tam) {

    int aux;

    for(int i = 0; i < tam - 1; i++){
        for (int j = 0; j < tam - i -1; j++){

            if (arr[j] < arr[j + 1]) {
                aux = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = aux;
            }
        }
    }
}

// Generar arreglo D sin repetidos

int generarArregloD(int a[], int b[], int d[]) {

    int aux[TAM_D];
    int j = 0;

    // Copiar A
    for (int i = 0; i < TAM; i++) {
        aux[i] = a[i];
    }

    // Copiar B
    for (int i = 0; i < TAM; i++) {
        aux[i + TAM] = b[i];
    }

    // Ordenar auxiliar
    ordenarArreglo(aux, TAM_D);

    // Eliminar repetidos
    d[j++] = aux[0];

    for (int i = 1; i < TAM_D; i++) {

        if (aux[i] != aux[i - 1]) {
            d[j] = aux[i];
            j++;
        }
    }

    return j; // cantidad real de elementos
}

// Busqueda binaria

int busquedaBinaria(int arr[], int tam, int objetivo) {

    int izquierda = 0;
    int derecha = tam - 1;

    while (izquierda <= derecha) {

        int medio = (izquierda + derecha) / 2;

        if (arr[medio] == objetivo) {
            return 1; // encontrado
        }
 

        if (arr[medio] < objetivo) {
            derecha = medio - 1;
        }
        else {
            izquierda = medio + 1;
        }
    }

    return -1; // no encontrado
}

// Contar apariciones de un valor en un arreglo

int contarApariciones(int arr[], int tam, int valor) {

    int contador = 0;

    for (int i = 0; i < tam; i++) {

        if (arr[i] == valor) {
            contador++;
        }
    }

    return contador;
}

int main() {

    // 1) Cargar A en declaración
    int a[TAM] = {0,1,2,3,4,5,6,7,8,9};

    // Arreglos restantes
    int b[TAM];
    int c[TAM];
    int d[TAM_D];

    int numero;
    int tamD;

    // 2) Cargar B por teclado
    cargarArreglo(b, TAM, "B");

    // 3) Generar C con suma de A y B
    sumarArreglos(a, b, c, TAM);

    // 4) Ordenar A y B de mayor a menor
    ordenarArreglo(a, TAM);
    ordenarArreglo(b, TAM);

    // 5) Generar D sin repetidos
    tamD = generarArregloD(a, b, d);

    // 6) Busqueda binaria en B
    printf("\nIngrese numero a buscar en B: ");
    scanf("%d", &numero);

    int resultado = busquedaBinaria(b, TAM, numero);

    if (resultado == -1) {
        printf("Elemento NO encontrado\n");
    }
    else {
        printf("Elemento encontrado en posicion %d\n", resultado);
    }

    // 7) Mostrar arreglos
    mostrarArreglo(a, TAM, "A");
    mostrarArreglo(b, TAM, "B");
    mostrarArreglo(c, TAM, "C");
    mostrarArreglo(d, tamD, "D");

    // 8) Contar apariciones de un valor en C (Ejercicio 2.1)

    printf("\nIngrese numero a buscar en C: ");
    scanf("%d", &numero);

    int apariciones = contarApariciones(c, TAM, numero);

    printf("El numero aparece %d veces en C\n", apariciones);

    return 0;
}