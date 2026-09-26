#include <stdio.h>

int main()
{
    char marca[50];
    int anio;
    float precio = 0.0;
    const ruedas = 2;

    printf("Ingrese marca de bici en su inicial:");
    scanf("%49s", marca);

    printf("\n");
    
    printf("Ingrese el año de fabricacion: ");
    scanf("%d", &anio);

    printf("\n");

    printf("Ingrese el precio de la bici: ");
    scanf("%f", &precio);

    printf("\n");

    printf("\n-----------Datos de Bici marca %s-----------\n", marca);
    printf("Año: %d |Marca: %s |Precio: %.2f|Ruedas: %d", anio, marca, precio, ruedas);


    return 0;
}