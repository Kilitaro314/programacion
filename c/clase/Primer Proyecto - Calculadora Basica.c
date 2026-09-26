
#include <stdio.h>

int main()
{
	int num1, num2, opcion;
	float resultado;
	
	printf("Ingrese la operacion que desea realizar:\n");
	printf("1. Suma\n2. Resta\n3. Multiplicacion\n4. Division\n" );
	printf("Opcion: ");
	scanf("%d", &opcion);
	
	if (opcion <1 || opcion >4){
		printf("Opcion no registrada");
		return 0;
	}
	
	printf("Ingrese el primer numero: ");
	scanf("%d", &num1);
	printf("Ingrese el segundo numero: ");
	scanf("%d", &num2);
	
	switch(opcion){
	case 1:
		resultado = num1 + num2;
		printf("%d + %d = %.2f\n", num1, num2, resultado);
		break;
	case 2:
		
		resultado = num1 - num2;
		printf("%d - %d = %.2f\n", num1, num2, resultado);
		break;

		
	case 3:
		resultado = num1 * num2;
		printf("%d * %d = %.2f\n", num1, num2, resultado);
		break;
	
	case 4:
			if(num2 > 0){
				resultado = (float)num1 / num2;
				printf("%d / %d = %.2f\n", num1, num2, resultado);
			}
			else {
				printf("No se puede dividir por 0");
			}
		break;
	}
	
	return 0;
}
