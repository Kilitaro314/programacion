#include <stdio.h>

int main() {
	int nota, cantidad, sumatoria, contador;
	float promedio = 0;
	contador = 1;
	sumatoria = 0;
	printf("Escriba la cantidad\n");
	scanf("%d", &cantidad);
	
	while (contador <= cantidad) 
	{
		printf("Escriba la nota: %d \n",contador);
		scanf("%i", &nota);
		sumatoria += nota;
		printf("Sumatoria: %d \n",sumatoria);
		contador ++;
		
	}
	
	promedio = (float)sumatoria / cantidad;
	printf ("El promedio es: %.2f", promedio);
	
	return 0;
}

