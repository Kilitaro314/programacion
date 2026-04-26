#include <stdio.h>

int main()
{
    
    int a, b;
    
    printf("Ingrese valor A: ");
    scanf("%d", &a);

    printf("Ingrese valor B: ");
    scanf("%d", &b);

    //Operaciones matematicas
    printf("%d + %d = %d", a, b, a + b);
    printf("\n%d - %d = %d", a, b, a - b);
    printf("\n%d x %d = %d", a, b, a * b);
    printf("\n%d / %d = %d", a, b, a / b);
    printf("\n%d resto %d = %d", a, b, a % b);

    //Operadores racionales
    printf("\nA == B = %d", a == b);
    printf("\nA != B = %d", a != b);
    printf("\nA > B = %d", a > b);
    printf("\nA < B = %d", a < b);
    printf("\nA >= B %d", a >= b);
    printf("\nA <= B %d", a <= b);

    //Operadores logicos
    printf("\n(a > b) && (b != 0): %d", (a > b) && (b != 0));
    printf("\n(a > b) || (b != 0): %d", (a > b) || (b != 0));

    a += b;
    printf("\nNuevo valor de A (A += B): %d", a);

    b *= 2;
    printf("\nNuevo valor de B (B *= 2): %d", b);

    return 0;
}
