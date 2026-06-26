#include <stdio.h>

typedef struct Nodo{
    int dato;
    struct Nodo *izq;
    struct Nodo *der;
}Nodo;

void mostrarArbol(struct Nodo* raiz, int nivel) {
	
	if (raiz == NULL)
		return;
	
	mostrarArbol(raiz->der, nivel + 1);
	
	for(int i = 0; i < nivel; i++)
		printf("     ");
	
	printf("%d\n", raiz->dato);
	
	mostrarArbol(raiz->izq, nivel + 1);
}

//Debug de recorrido
void recorrer(Nodo *a){

    if(a==NULL){

        printf("NULL\n");
        return;

    }

    printf("ENTRO %d\n",a->dato);

    recorrer(a->izq);

    printf("VUELVO A %d\n",a->dato);

    recorrer(a->der);

    printf("SALGO %d\n",a->dato);

}

int main() {
        

}