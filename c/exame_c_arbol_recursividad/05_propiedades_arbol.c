#include <stdio.h>

typedef struct Nodo{
    int dato;
    struct Nodo *izq;
    struct Nodo *der;
}Nodo;

//Contar

int contar(Nodo *a){

    if(a==NULL)
        return 0;

    return 1+
        contar(a->izq)+
        contar(a->der);

}

//Sumar

int suma(Nodo *a){

    if(a==NULL)
        return 0;

    return a->dato+
        suma(a->izq)+
        suma(a->der);

}

//Altura

int max(int a,int b){

    return a>b?a:b;

}

int altura(Nodo *a){

    if(a==NULL)
        return 0;

    return 1+max(
        altura(a->izq),
        altura(a->der)
    );

}

int main() {
        

}