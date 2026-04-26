#include <stdio.h>

/*
    GUIA BASICA DE TIPOS Y ENTRADA EN C
    (para usar como referencia en examen)
*/

int main() {

    // =========================
    // 🧠 TIPOS DE VARIABLES
    // =========================

    int entero = 10;              // números enteros
    float decimal = 3.14f;        // decimales simples
    double precision = 3.141592;  // decimales más precisos
    char letra = 'A';             // un solo carácter

    // =========================
    // 📌 STRINGS (PALABRAS)
    // =========================

    char palabra[50];  // string básico (array de char)
    
    printf("Ingrese una palabra: ");
    scanf("%s", palabra); // NO lleva &

    // ⚠️ Solo lee hasta espacio

    // =========================
    // 📌 FRASES COMPLETAS
    // =========================

    char frase[100];

    printf("Ingrese una frase: ");
    fgets(frase, 100, stdin); // incluye espacios

    // =========================
    // 📌 ARREGLOS (ARRAYS)
    // =========================

    int numeros[5] = {1, 2, 3, 4, 5};

    for (int i = 0; i < 5; i++) {
        printf("Elemento %d: %d\n", i, numeros[i]);
    }

    // =========================
    // 📌 MATRICES (BASE)
    // =========================

    int matriz[2][2] = {
        {1, 2},
        {3, 4}
    };

    for (int i = 0; i < 2; i++) {        // filas
        for (int j = 0; j < 2; j++) {    // columnas
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }

    // =========================
    // 📌 INPUT BÁSICO
    // =========================

    int a, b;

    printf("Ingrese dos numeros: ");
    scanf("%d %d", &a, &b);

    printf("Suma: %d\n", a + b);

    // =========================
    // 🧠 RECORDATORIOS CLAVE
    // =========================

    /*
        - char = 1 letra
        - char[] = palabra/frase
        - scanf("%s") no lee espacios
        - fgets SI lee espacios
        - arrays empiezan en 0
        - matriz[i][j] = fila, columna
    */

    return 0;
}