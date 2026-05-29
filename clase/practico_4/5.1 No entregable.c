#include <stdio.h>
#include <string.h>

#define MAX_CLIENTES 100

// 1. Definición de la estructura para el registro del cliente
typedef struct {
    int nroCliente;
    char tipoCliente; // 'E' o 'P'
    char nombre[50];
    char nroContacto[20];
} Cliente;

// Prototipos de funciones
void cargarArreglo(Cliente arr[], int *n);
void ordenarPorNumero(Cliente arr[], int n);
void mostrarClientes(Cliente arr[], int n);
int busquedaBinaria(Cliente arr[], int n, int numeroBuscado);
void separarPorTipo(Cliente orig[], int n, Cliente arrE[], int *nE, Cliente arrP[], int *nP);

int main() {
    Cliente clientes[MAX_CLIENTES];
    int n = 0;

    // Arreglos para separar por tipo
    Cliente clientesE[MAX_CLIENTES];
    Cliente clientesP[MAX_CLIENTES];
    int nE = 0, nP = 0;

    // Cargar y procesar datos
    printf("--- CARGA DE CLIENTES ---\n");
    cargarArreglo(clientes, &n);

    if (n == 0) {
        printf("No se ingresaron clientes.\n");
        return 0;
    }

    // Ordenar y Mostrar
    ordenarPorNumero(clientes, n);
    mostrarClientes(clientes, n);

    // Búsqueda Binaria
    int numBuscado;
    printf("\nIngrese el Numero de Cliente a buscar: ");
    scanf("%d", &numBuscado);
    
    int pos = busquedaBinaria(clientes, n, numBuscado);
    if (pos != -1) {
        printf("Cliente encontrado! Nombre: %s, Contacto: %s\n", clientes[pos].nombre, clientes[pos].nroContacto);
    } else {
        printf("Cliente no encontrado.\n");
    }

    // Separar por tipo
    separarPorTipo(clientes, n, clientesE, &nE, clientesP, &nP);
    
    printf("\nSe generaron dos nuevos arreglos:");
    printf("\n- Clientes Tipo E (Empresa): %d", nE);
    printf("\n- Clientes Tipo P (Particular): %d\n", nP);

    return 0;
}

// Carga el arreglo pidiendo datos al usuario
void cargarArreglo(Cliente arr[], int *n) {
    int cantidad;
    printf("¿Cuántos clientes desea ingresar? (Máx %d): ", MAX_CLIENTES);
    scanf("%d", &cantidad);
    
    if (cantidad > MAX_CLIENTES) cantidad = MAX_CLIENTES;
    *n = cantidad;

    for (int i = 0; i < *n; i++) {
        printf("\nCliente %d:\n", i + 1);
        printf("Nro. Cliente: ");
        scanf("%d", &arr[i].nroCliente);
        
        do {
            printf("Tipo Cliente (E: Empresa / P: Particular): ");
            scanf(" %c", &arr[i].tipoCliente); // El espacio antes de %c limpia el buffer
        } while (arr[i].tipoCliente != 'E' && arr[i].tipoCliente != 'P');

        printf("Nombre: ");
        scanf(" %[^\n]", arr[i].nombre); // Lee texto con espacios

        printf("Nro. Celular de Contacto: ");
        scanf("%s", arr[i].nroContacto);
    }
}

// Ordenamiento Ascendente por Nro. de Cliente (Método Burbuja)
void ordenarPorNumero(Cliente arr[], int n) {
    Cliente temp;
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

// Muestra el listado formateado y las estadísticas correspondientes
void mostrarClientes(Cliente arr[], int n) {
    int cantE = 0, cantP = 0;
    
    printf("\n\t\tListado de Clientes\n");
    printf("------------------------------------------------------------\n");
    printf("%-12s %-12s %-20s %-15s\n", "Nro.Cliente", "Tipo-Cliente", "Nombre", "Nro. Contacto");
    printf("------------------------------------------------------------\n");

    for (int i = 0; i < n; i++) {
        printf("%-12d %-12c %-20s %-15s\n", 
               arr[i].nroCliente, arr[i].tipoCliente, arr[i].nombre, arr[i].nroContacto);
        
        if (arr[i].tipoCliente == 'E') cantE++;
        else if (arr[i].tipoCliente == 'P') cantP++;
    }
    
    printf("------------------------------------------------------------\n");
    printf("Total de Clientes: %d\n", n);
    printf("Total de Clientes Tipo E: %d\n", cantE);
    printf("Total de Clientes Tipo P: %d\n", cantP);
}

// Búsqueda binaria (Requiere que el arreglo ya esté ordenado)
int busquedaBinaria(Cliente arr[], int n, int numeroBuscado) {
    int izquierda = 0;
    int derecha = n - 1;

    while (izquierda <= derecha) {
        int medio = izquierda + (derecha - izquierda) / 2;

        if (arr[medio].nroCliente == numeroBuscado) {
            return medio; // Retorna el índice donde se encontró
        }
        if (arr[medio].nroCliente < numeroBuscado) {
            izquierda = medio + 1;
        } else {
            derecha = medio - 1;
        }
    }
    return -1; // No encontrado
}

// Divide el arreglo original en dos sub-arreglos según el tipo
void separarPorTipo(Cliente orig[], int n, Cliente arrE[], int *nE, Cliente arrP[], int *nP) {
    *nE = 0;
    *nP = 0;
    for (int i = 0; i < n; i++) {
        if (orig[i].tipoCliente == 'E') {
            arrE[*nE] = orig[i];
            (*nE)++;
        } else if (orig[i].tipoCliente == 'P') {
            arrP[*nP] = orig[i];
            (*nP)++;
        }
    }
}
