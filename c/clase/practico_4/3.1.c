#include <stdio.h>


int main() {
    int a[10] = {5, 3, 6, 2, 5, 4, 4, 6, 9, 0};
    int b[10] = {10, 20, 15, 5, 25, 30, 12, 18, 22, 28};
    int d[20];
    int tamD;

    //Ordenar y listar a y b

    ordenarArreglo(a, 10, 2);
    ordenarArreglo(b, 10, 2);
    
    listarArreglo(a, 10);
    listarArreglo(b, 10);

    unirArreglos(a,b,d);
    listarArreglo(d,20);

    // Generar D sin repeticiones

    tamD = deshacerRepeticiones(a,b,d);
    listarArreglo(d,tamD);

    // Buscar en binario

    printf("%d", busquedaBinaria(d, tamD));

    return 0;
}

//Metodo de Selection Sort
void ordenarArreglo(int arr[], int n, int opcion){

    int pos;
    int aux;

    for (int i = 0; i < n - 1; i++){

        pos = i;

        for (int j = i + 1; j < n; j++){

            // Mayor a menor
            if (opcion == 1){

                if (arr[j] > arr[pos]){
                    pos = j;
                }
            }

            // Menor a mayor
            else if (opcion == 2){

                if (arr[j] < arr[pos]){
                    pos = j;
                }
            }
        }

        aux = arr[i];
        arr[i] = arr[pos];
        arr[pos] = aux;
    }
}

void listarArreglo(int arr[], int n){
    
    for (int i = 0; i < n; i++){
        printf("%d ", arr[i]);
        printf("\n");
    }
}

void unirArreglos(int a[], int b[], int c[]){
    int a_can;
    int b_can;
    int c_can;
    printf("Ingrese cantidad de elementos de A: ");
    scanf("%d", &a_can);
    printf("Ingrese cantidad de elementos de B: ");
    scanf("%d", &b_can);

    c_can = a_can + b_can;

    //Cargar A en C
    for (int i = 0; i < a_can; i++){
        c[i] = a[i];
    }

    for (int i = 0; i < b_can; i++){
        c[i + a_can] = b[i];
    }
}

int deshacerRepeticiones(int a[], int b[], int c[]){
    int j = 0;
    
    int a_can;
    int b_can;
    int c_can;
    printf("Ingrese cantidad de elementos de A: ");
    scanf("%d", &a_can);
    printf("Ingrese cantidad de elementos de B: ");
    scanf("%d", &b_can);

    c_can = a_can + b_can;
    int aux[c_can];

    //Cargar A en AUX
    for (int i = 0; i < a_can; i++){
        aux[i] = a[i];
    }
    //Cargar B en AUX
    for (int i = 0; i < b_can; i++){
        aux[i + a_can] = b[i];
    }
    ordenarArreglo(aux, c_can, 2);

    //Eliminar repetidos
    c[j++] = aux[0];

    for (int i = 1; i < c_can; i++){

        if (aux[i] != aux[i-1]){
            c[j] = aux[i];
            j++;
        }
    }

    return j;
}

int busquedaBinaria(int a[], int n){
    int objetivo;
    printf("Ingrese el valor a buscar: ");
    scanf("%d", &objetivo);

    int inicio = 0;
    int fin = n - 1;

    while (inicio <= fin)
    {
        int medio = (inicio + fin) / 2;

        if (a[medio] == objetivo){
            return 1;
        }

       else if (a[medio] < objetivo)
        {
            inicio = medio + 1;
        }
        else
        {
            fin = medio - 1;
        }
        
    }

    return -1;
    
}




