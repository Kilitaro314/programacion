#include <stdio.h>

typedef struct Nodo{
    int dato;
    struct Nodo *izq;
    struct Nodo *der;
}Nodo;

void pre(Nodo *a){

    if(a==NULL)
        return;

    printf("%d ",a->dato);

    pre(a->izq);
    pre(a->der);
}

void in(Nodo *a){

    if(a==NULL)
        return;

    in(a->izq);

    printf("%d ",a->dato);

    in(a->der);
}

void post(Nodo *a){

    if(a==NULL)
        return;

    post(a->izq);
    post(a->der);

    printf("%d ",a->dato);
}

//Buscar

int buscar(Nodo *a,int x){

    if(a==NULL)
        return 0;

    if(a->dato==x)
        return 1;

    return buscar(a->izq,x)
        || buscar(a->der,x);

}

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