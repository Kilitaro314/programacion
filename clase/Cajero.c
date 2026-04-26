#include <stdio.h>

int main()
{
    
    float saldo = 0;
    int pin = 0;
    int contrasena = 1234;
    int opcion;
    int accedido = 0;
    int intentos = 0;
    float monto;

    printf("-----Bienvenido al cajero aujtomatico------\n");
    
    while (accedido == 0)
    {
        printf("Ingrese PIN: ");
        scanf("%d", &pin);

        if (pin != contrasena){
            printf("Contraseña incorrecta\n");
            intentos += 1;
        }
        else {
            accedido = 1;
            printf("Contraseña valida\n");
        }
        
        if (intentos >= 3){
            printf("Cantidad intentos excedidos");
            return 1;
        }
        
    }

    while (accedido == 1)
    {
        /* code */
        printf("\n-----Menu-----\n");
        printf("1 - Consultar saldo\n");
        printf("2 - Depositar dinero\n");
        printf("3 - Extraer dinero\n");
        printf("4 - Cambiar PIN\n");
        printf("5 - Salir\n");
        
        scanf("%d", &opcion);
    
        switch (opcion)
        {
        case 1:
            printf("Su saldo es de: %.2f", saldo);
            break;
        
        case 2:
    
        printf("Ingresar el monto a depositar: ");
        scanf("%f", &monto);
    
        if (monto > 0) {
    
            saldo = saldo + monto;
            printf("Tu nuevo saldo es de: %.2f", saldo);
    
        }
        else {
    
            printf("Monto invalido");
    
        }
    
        break;
    
        case 3:

        printf("Ingresar el monto a retirar: ");
        scanf("%f", &monto);

        if (monto > 0){

            if (monto <= saldo){

                saldo = saldo - monto;
                printf("Tu nuevo saldo es de: %.2f\n", saldo);

            }
            else
            {
                printf("Fondos insuficientes\n");
            }
            
        }
        else {
            printf("Monto invalido\n");
        }
    
        break;
    
        case 4:
        printf("Ingresar PIN actual: ");
        scanf("%d", &pin);

        if (pin != contrasena){
            printf("Contraseña incorrecta\n");
            break;
        }

        if (pin == contrasena){
            printf("Ingrese su nueva contraseña: ");
            scanf("%d", &pin);

            if (pin <= 0 || pin < 1000 || pin > 9999){
                printf("Contraseña invalida, no superar 4 digitos");
            }
            else {

                contrasena = pin;
                printf("Tu nueva contraseña es: %d", contrasena);
                
            }

        }

    
        break;
    
        default:
        accedido = 0;
            break;
        }
        
    }
    
    printf("Gracias por ser cliente\n");

    return 0;
}
