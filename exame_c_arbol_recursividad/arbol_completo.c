#include <stdio.h>
#include <stdlib.h>


// Estructura para los nodos del árbol binario
struct Nodo {
	int dato;
	struct Nodo* izquierdo;
	struct Nodo* derecho;
};

//Mostrar arbol
void mostrarArbol(struct Nodo* raiz, int nivel) {
	
	if (raiz == NULL)
		return;
	
	mostrarArbol(raiz->derecho, nivel + 1);
	
	for(int i = 0; i < nivel; i++)
		printf("     ");
	
	printf("%d\n", raiz->dato);
	
	mostrarArbol(raiz->izquierdo, nivel + 1);
}

// Procedimiento para crear e insertar elementos por teclado
void crearArbol(struct Nodo** raiz, int valor) {
	if (*raiz == NULL) {
		struct Nodo* nuevoNodo = (struct Nodo*)malloc(sizeof(struct Nodo));
		if (nuevoNodo == NULL) {
			printf("Error: Memoria insuficiente.\n");
			return;
		}
		nuevoNodo->dato = valor;
		nuevoNodo->izquierdo = NULL;
		nuevoNodo->derecho = NULL;
		*raiz = nuevoNodo;
		printf("-> Valor %d insertado correctamente.\n", valor);
		return;
	}
	
	if (valor < (*raiz)->dato) {
		crearArbol(&((*raiz)->izquierdo), valor);
	} else if (valor > (*raiz)->dato) {
		crearArbol(&((*raiz)->derecho), valor);
	} else {
		printf("-> El valor %d ya existe en el arbol.\n", valor);
	}
}

// Recorrido Preorden: Raz -> Izquierdo -> Derecho
void preOrden(struct Nodo* raiz) {
	if (raiz != NULL) {
		printf("%d ", raiz->dato);
		preOrden(raiz->izquierdo);
		preOrden(raiz->derecho);
	}
}

// Recorrido Orden Central (Inorden): Izquierdo -> Raiz -> Derecho
void ordenCentral(struct Nodo* raiz) {
	if (raiz != NULL) {
		ordenCentral(raiz->izquierdo);
		printf("%d ", raiz->dato);
		ordenCentral(raiz->derecho);
	}
}

// Recorrido Postorden: Izquierdo -> Derecho -> Raiz
void postOrden(struct Nodo* raiz) {
	if (raiz != NULL) {
		postOrden(raiz->izquierdo);
		postOrden(raiz->derecho);
		printf("%d ", raiz->dato);
	}
}

struct Nodo* buscar(struct Nodo* raiz, int valor){
	if (raiz == NULL || raiz->dato == valor){
		return raiz;
	}
	if (valor < raiz->dato)
	{
		return buscar(raiz->izquierdo, valor);
	}
	else {
		return buscar(raiz->derecho, valor);
	}
	
}

// Función principal con menú interactivo simplificado
int main() {
	struct Nodo* raiz = NULL;
	int opcion, valor;
	
	do {
		printf("\n=== MENU ARBOL BINARIO ===");
		printf("\n1. Insertar elemento por teclado");
		printf("\n2. Mostrar arbol Preorden");
		printf("\n3. Mostrar arbol Inorden");
		printf("\n4. Mostrar arbol Postorden");
		printf("\n5. Buscar elemento");
		printf("\n6. Mostrar arbol completo");
		printf("\n7. Salir");
		printf("\nSeleccione una opcion: ");
		fflush(stdout);
		
		if (scanf("%d", &opcion) != 1) {
			printf("Error: Ingrese un numero valido.\n");
			while (getchar() != '\n'); // Limpiar buffer
			continue;
		}
		
		switch (opcion) {
		case 1:
			printf("Ingrese el valor entero: ");
			fflush(stdout);
			scanf("%d", &valor);
			crearArbol(&raiz, valor);
			break;
			
		case 2:
			if (raiz == NULL) {
				printf("\nEl arbol esta vacio. Inserte elementos primero.\n");
			} else {
				printf ("\n Recorrido del arbol");
				
				printf("\n> Preorden (Raz-Izq-Der):       ");
				preOrden(raiz);
				
				printf("\n-----------------------------\n");
			}
			fflush(stdout);
			break;
		
		case 3:
			if (raiz == NULL) {
				printf("\nEl arbol esta vacio. Inserte elementos primero.\n");
			} else {
				printf ("\n Recorrido del arbol");
				
				printf("\n> Inorden Central (Izq-Raz-Der):  ");
				ordenCentral(raiz);
				
				printf("\n-----------------------------\n");
			}
			fflush(stdout);
			break;
		
		case 4:
			if (raiz == NULL) {
				printf("\nEl arbol esta vacio. Inserte elementos primero.\n");
			} else {
				printf ("\n Recorrido del arbol");
				
				printf("\n> Postorden (Izq-Der-Raz):      ");
				postOrden(raiz);
				
				printf("\n-----------------------------\n");
			}
			fflush(stdout);
			break;
		
		case 5:
			if (raiz == NULL) {
				printf("\nEl arbol esta vacio. Inserte elementos primero.\n");
			} else {
				printf("Ingrese el valor a buscar: ");
				fflush(stdout);
				scanf("%d", &valor);
				
				struct Nodo* resultado = buscar(raiz, valor);
				if (resultado != NULL) {
					printf("-> Valor %d encontrado en el arbol.\n", valor);
				} else {
					printf("-> Valor %d no encontrado en el arbol.\n", valor);
				}
			}
			fflush(stdout);
			break;
		
		case 6:
			if (raiz == NULL) {
				printf("\nEl arbol esta vacio. Inserte elementos primero.\n");
			} else {
				printf("\nArbol completo:\n");
				mostrarArbol(raiz, 0);
			}
			fflush(stdout);
			break;
		case 7:
			printf("Saliendo del programa...\n");
			break;
		default:
			printf("Opción inválida.\n");
		}
	} while (opcion != 7);

	return 0;
}
