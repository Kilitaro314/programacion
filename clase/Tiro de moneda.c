#include <stdio.h>

int main() {
	
	int cantidad, caras = 0, secas = 0, contador = 1, tiro;
	float probC, probS;
	
	
	printf ("Cuantas tiradas hara?\n");
	scanf ("%d",&cantidad);
	while (contador <= cantidad) {
		printf ("Tirada %d (Cara = 1, Seca = 2)\n", contador);
		scanf ("%d", &tiro);
		if (tiro == 1) {
			caras ++;
		}
		else if (tiro == 2) {
			secas ++;
		}
		else {
			printf("Numero no admisible\n");
			continue;
		}
		contador ++;
		
	}
	
	
	printf ("Caras: %d ", caras);
	printf ("Secas: %d\n", secas);
	
	probC = ((float)caras / cantidad) * 100;
	probS = ((float)secas / cantidad) * 100;
	
	printf ("Probabilidad de Cara: %.2f%\n", probC);
	printf ("Probabilidad de Secas: %.2f%\n", probS);
	
	return 0;
}

