#include <stdio.h>
#include <string.h>

#define MAX_CLIENTES 400
#define MAX_CHAR 80

struct Cliente
{
    int nroCliente;
    char tipo;
    char nombre[MAX_CHAR];
    char nroDeContacto[20];
};

void cargarClientes(struct Cliente arr[], int *n);
void mostrarClientes(struct Cliente arr[], int n);
void ordenarPorNumero(struct Cliente arr[], int n);
int busquedaBinaria(struct Cliente arr[], int n);
void separarPorTipo(struct Cliente orig[], int n, struct Cliente arrE[], int *nE, struct Cliente arrP[], int *nP);


int main() {

    struct Cliente clientes[MAX_CLIENTES];
    int n = 0;

    struct Cliente clientesP[MAX_CLIENTES];
    struct Cliente clientesE[MAX_CLIENTES];
    int nP = 0, nE = 0;

    cargarClientes(clientes, &n);
    ordenarPorNumero(clientes, n);
    mostrarClientes(clientes, n);
    int pos = busquedaBinaria(clientes,n);

    if (pos > -1){
        printf("Cliente encontrado\n");
        printf("%-12s %-12s %-20s %-15s\n",
           "Nro.Cliente", "Tipo-Cliente", "Nombre", "Nro. Contacto");
        printf("------------------------------------------------------------\n");
        printf("%-12d %-12c %-20s %-15s\n",
        clientes[pos].nroCliente,
        clientes[pos].tipo,
        clientes[pos].nombre,
        clientes[pos].nroDeContacto);
    }
    else {
        printf("Cliente no encontrado\n");
    }

    separarPorTipo(clientes, n, clientesE, &nE, clientesP, &nP);

    printf("\nSe generaron dos nuevos arreglos:");
    printf("\n- Clientes Tipo E (Empresa): %d", nE);
    printf("\n- Clientes Tipo P (Particular): %d\n", nP);

    return 0;
}

void cargarClientes(struct Cliente arr[], int *n){
    int cantidad;

    if (*n >= MAX_CLIENTES){
        printf("Ya no se pueden ingresar mas clientes\n");
        return;
    }

    printf("Ingrese la cantidad: ");
    scanf("%d", &cantidad);

    if (cantidad > MAX_CLIENTES) cantidad = MAX_CLIENTES;
    *n = cantidad;

    for (int i = 0; i < cantidad; i++){

        printf("\nCliente N: %d\n", i + 1);

        printf("Numero de cliente: ");
        scanf("%d", &arr[i].nroCliente);

        do {
            printf("Tipo Cliente (E: Empresa / P: Particular): ");
            scanf(" %c", &arr[i].tipo);
        } while (arr[i].tipo != 'E' && arr[i].tipo != 'P');

        printf("Nombre de Cliente: ");
        scanf(" %[^\n]", arr[i].nombre);

        printf("nro de Contacto: ");
        scanf("%s", arr[i].nroDeContacto);  // 👈 cambio clave
    }
}

void mostrarClientes(struct Cliente arr[], int n) {
   
    if (n == 0){
        printf("No se ingresaron clientes\n");
        return;
    }

    int cantE = 0, cantP = 0;

    printf("\n\t\tListado de Clientes\n");
    printf("------------------------------------------------------------\n");
    printf("%-12s %-12s %-20s %-15s\n",
           "Nro.Cliente", "Tipo-Cliente", "Nombre", "Nro. Contacto");
    printf("------------------------------------------------------------\n");

    for (int i = 0; i < n; i++) {
        printf("%-12d %-12c %-20s %-15s\n",
               arr[i].nroCliente,
               arr[i].tipo,
               arr[i].nombre,
               arr[i].nroDeContacto);

        if (arr[i].tipo == 'E') cantE++;
        else if (arr[i].tipo == 'P') cantP++;
    }

    printf("------------------------------------------------------------\n");
    printf("Total de Clientes: %d\n", n);
    printf("Total de Clientes Tipo E: %d\n", cantE);
    printf("Total de Clientes Tipo P: %d\n", cantP);
}

void ordenarPorNumero(struct Cliente arr[], int n) {
    struct Cliente temp;

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j].nroCliente > arr[j + 1].nroCliente) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int busquedaBinaria(struct Cliente arr[], int n){
    int inicio = 0;
    int fin = n -1;

    int nroBuscado = 0;

    printf("Ingrese numero de cliente a buscar: ");
    scanf("%d", &nroBuscado);

    do
    {
        int medio = inicio + (fin - inicio) / 2;

        if (arr[medio].nroCliente == nroBuscado){
            return medio;
        }

        else if (arr[medio].nroCliente < nroBuscado)
        {
            inicio = medio + 1;
        }
        else {
            fin = medio - 1;
        }
        
    } while (inicio <= fin);

    return -1;
    
}

void separarPorTipo(struct Cliente orig[], int n, struct Cliente arrE[], int *nE, struct Cliente arrP[], int *nP) {
    *nE = 0;
    *nP = 0;
    for (int i = 0; i < n; i++) {
        if (orig[i].tipo == 'E') {
            arrE[*nE] = orig[i];
            (*nE)++;
        } else if (orig[i].tipo == 'P') {
            arrP[*nP] = orig[i];
            (*nP)++;
        }
    }
}