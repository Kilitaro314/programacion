#include <stdio.h>

typedef struct Nodo{
    int dato;
    struct Nodo *sig;
}Nodo;

int contar(Nodo *p){
    if(p==NULL) return 0;

    return 1+contar(p->sig);
}

int suma(Nodo *p){
    if(p==NULL) return 0;

    return p->dato+suma(p->sig);
}

int buscar(Nodo *p,int x){
    if(p==NULL) return 0;

    if(p->dato==x)
        return 1;

    return buscar(p->sig,x);
}

int main() {
        
    

}