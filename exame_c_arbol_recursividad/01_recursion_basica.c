#include <stdio.h>

int potencia (int a, int b){
    if (b == 0){
        return 1;
    }

    return a * potencia(a, b -1);
}

#include <stdio.h>

void pre(int n){
    if(n==0) return;

    printf("%d ",n);
    pre(n-1);
}

void post(int n){
    if(n==0) return;

    post(n-1);
    printf("%d ",n);
}

void espejo(int n){
    if(n==0) return;

    printf("%d ",n);
    espejo(n-1);
    printf("%d ",n);
}

int main() {
    
    printf("Potencia: %d\n", potencia(2, 3));

    printf("Preorden: ");
    pre(5);
    printf("\n");

    printf("Postorden: ");
    post(5);
    printf("\n");

    printf("Espejo: ");
    espejo(5);
    printf("\n");

}