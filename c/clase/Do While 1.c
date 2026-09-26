#include <stdio.h>

int main() {
	int a, b, c;
	
	do {
		printf("Ingrese tres numeros consecutivos: ");
		scanf("%d %d %d", &a, &b, &c);
		
		if (!((b == a + 1) && (c == b + 1))) {
			printf("No son consecutivos. Intente nuevamente.\n");
		}
	} while (!((b == a + 1) && (c == b + 1)));
	
	printf("Gracias\n");
	return 0;
}

