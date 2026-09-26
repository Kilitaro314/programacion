#include <stdio.h>

int main() {

    int dn, mn, an;
    int da, ma, aa;
    int edad;

    printf("Fecha nacimiento (dd mm aaaa): ");
    scanf("%d %d %d", &dn, &mn, &an);

    printf("Fecha actual (dd mm aaaa): ");
    scanf("%d %d %d", &da, &ma, &aa);

    edad = aa - an;

    if (ma < mn || (ma == mn && da < dn)) {
        edad--;
    }

    printf("Edad: %d\n", edad);

    return 0;
}