#include <stdio.h>

int main() {
	
	int dia_nac, mes_nac, anio_nac;
	int dia_act, mes_act, anio_act;
	int edad;
	
	printf("Fecha de nacimiento (dd/mm/aaaa): ");
	scanf ("%d %d %d",&dia_nac, &mes_nac, &anio_nac);
	
	printf("Fecha actual (dd/mm/aaaa): ");
	scanf ("%d %d %d",&dia_act, &mes_act, &anio_act);
	printf("\n");
	edad = anio_act - anio_nac;
	
	if (mes_act < mes_nac || (mes_act == mes_nac && dia_act < dia_nac)) {
		edad = edad -1;
	}
	
	printf("Edad: %d", edad);
	
	
	return 0;
}

