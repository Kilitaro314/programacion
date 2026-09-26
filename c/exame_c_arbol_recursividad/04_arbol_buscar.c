#include <stdio.h>

typedef struct Nodo{
    int dato;
    struct Nodo *izq;
    struct Nodo *der;
}Nodo;

//Buscar

int buscar(Nodo *a,int x){

    if(a==NULL)
        return 0;

    if(a->dato==x)
        return 1;

    return buscar(a->izq,x)
        || buscar(a->der,x);

}

int main() {
        

}