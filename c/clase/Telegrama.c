#include <stdio.h>

int main() {

    char texto[1000];
    char telegrama[1000];

    int n  = 0;

    printf("Escriba su texto: ");
    fgets(texto, 1000, stdin);

    generarTelegrama(texto,telegrama);

    printf("Su telegrama:\n");
    printf("%s", telegrama);

    cobrarTelegrama(telegrama);
}

void generarTelegrama(char texto[1000], char telegrama[1000]){
    int j = 0;

    for (int i = 0; texto[i] != '\0'; i++){

        if (texto[i] == ' '){
            telegrama[j] = '*';
        }
        else if (texto[i] == '\n')
        {
            telegrama[j] = '.';
        }
        else {
            telegrama[j] = texto[i];
        }
        j++;
    }
    telegrama[j] = '\0';
}

void cobrarTelegrama(char telegrama[1000]){
    int caracteres = 0;
    int palabras = 0;
    int oraciones = 0;

    int precio = 100;

    for (int i = 0; telegrama[i] != '\0'; i++){
        caracteres++;
        
        if (telegrama[i] == '*'){
            palabras++;
        }

        else if (telegrama[i] == '.')
        {
            oraciones++;
        }
    }

    palabras = palabras+1;

    if (oraciones == 1 && palabras == 5) {
        precio = 100;
    }
    else if (oraciones >= 2 && oraciones <= 3 && palabras <= 15) {
        precio = 500;
    }
    else {
        precio = 1000;
    }

    printf("\nPrecio por caracter: %d\n", precio);
    printf("Precio total de telegrama es %d", caracteres*precio);

}