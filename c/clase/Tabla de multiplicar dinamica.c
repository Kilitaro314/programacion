#include <stdio.h>

int main() {
	
	int inicio, fin, inter;
	
	printf("Desde que numero empieza a multiplicar\n");
	scanf("%d", &inicio);
	printf("En que numero termina de multiplicar\n");
	scanf("%d", &fin);
	printf("Cual es el limite a multiplicar\n");
	scanf("%d", &inter);
	printf("\n");
	
	for (int i = inicio; i <= fin; i++) {
		for (int j = i; j <= inter; j++){
			int total = i * j;
			printf("%d x %d = %d\n", i, j, total);
		}
		
	}
	
	return 0;
}

