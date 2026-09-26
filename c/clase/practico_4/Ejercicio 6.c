#include <stdio.h>

void ingresarFrase(char frase[80]);
int encontrarLetras(char arr[80], char letras);
void invertirFrase(char frase[80]);

int main() {
    char letra;
    char frase[80];

    //Escribir frase
    ingresarFrase(frase);

    //Buscar letras
    printf("Letra a buscar: ");
    scanf(" %c", &letra);  // espacio antes de %c para ignorar \n

    printf("La letra %c aparece %d veces\n", letra, encontrarLetras(frase, letra));

    //Invertir frase
    invertirFrase(frase);
    
    return 0;
}

//Ingresar la frase
void ingresarFrase(char frase[80]){
    printf("Escriba su frase: ");
    scanf(" %79[^\n]", frase);  // permite espacios hasta enter
}

//Buscar letras
int encontrarLetras(char arr[80], char letras){
    int cont = 0;

    for (int i = 0; arr[i] != '\0'; i++){
        if (arr[i] == letras){
            cont++;
        }
    }

    return cont;
}

//Invertir frase
void invertirFrase(char frase[80]){

    int len = 0;

    //Calcular longitud real
    while (frase[len] != '\0')
    {
        len++;
    }

    // imprimir al reves
    for (int i = len - 1; i >= 0; i--){
        printf("%c", frase[i]);
    }

    printf("\n");
    
}