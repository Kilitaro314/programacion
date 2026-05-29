#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX_BESTIAS 40

struct Bestia
{
    char nombre[50];
    int vida;
    int fuerza;
    int magia;
    int rareza;
    char descripcion[4000];
    int id;

};

//Ordenar bestiario por rareza
void ordenarBestiarioRareza(struct Bestia arr[], int num){
   
    struct Bestia temp;
    

    for (int i = 0; i < num - 1; i++){
        for (int j = 0; j < num -1 - i; j++){
            
            if (arr[j].rareza > arr[j + 1].rareza){
            
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;

            }
        }
    }
}

//Ordenar por alfabeto
void ordenarBestiarioNombre(struct Bestia arr[], int num)
{
    struct Bestia temp;

    for (int i = 0; i < num - 1; i++)
    {
        for (int j = 0; j < num - 1 - i; j++)
        {
            if (strcmp(arr[j].nombre, arr[j + 1].nombre) > 0)
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

//Listar Bestiario normalmente
void listarBestiario(struct Bestia arr[], int num){
    printf("\n------------------Bestiario de Between Eyes------------------\n");
    printf("%-20s %-8s %-8s %-8s %-8s %-20s\n",
       "Nombre",
       "Vida",
       "Fuerza",
       "Magia",
       "Rareza",
       "ID");
    for (int i = 0; i < num; i++){
        printf("%-20s %-8d %-8d %-8d %-8d %-20d\n",
        arr[i].nombre,
        arr[i].vida,
        arr[i].fuerza,
        arr[i].magia,
        arr[i].rareza,
        arr[i].id);
    }
    
}

//Buscar bestia
struct Bestia buscarBestia(struct Bestia arr[], int num){
    char nombre[80];
    int inicio = 0;
    int fin = num - 1;

    printf("Ingrese el nombre de la bestia a buscar: ");
    scanf(" %79[^\n]", nombre);

    while (inicio <= fin)
    {
        int medio = inicio + (fin - inicio) /2;

        int comparacion = (strcmp(arr[medio].nombre, nombre));

        if (comparacion == 0){
            return arr[medio];
        }

        if (comparacion < 0){
            inicio = medio + 1;
        }
        else {
            fin = medio - 1;
        }
    }

    struct Bestia vacia = {"", 0, 0, 0, 0, ""};
    return vacia;
}

//Añadir besia
void agregarBestia(struct Bestia arr[], int *num){
    if (*num >= MAX_BESTIAS){
        printf("No se pueden listar mas bestias, Bestiario sin hojas\n");
        return;
    }

    struct Bestia nuevaBestia;

    printf("Ingresar nombre de la bestia: ");
    scanf(" %49[^\n]", nuevaBestia.nombre);
    printf("Ingresar vida de la bestia: ");
    scanf("%d", &nuevaBestia.vida);
    printf("Ingresar fuerza fisica de la bestia: ");
    scanf("%d", &nuevaBestia.fuerza);
    printf("Ingresar capacidad magica la bestia: ");
    scanf("%d", &nuevaBestia.magia);
    printf("Ingresar rareza de la bestia: ");
    scanf("%d", &nuevaBestia.rareza);
    printf("Ingresar descripcion de la bestia: ");
    scanf(" %3999[^\n]", nuevaBestia.descripcion);
    printf("Ingresar ID de la bestia: ");
    scanf("%d", &nuevaBestia.id);

    arr[*num] = nuevaBestia;
    (*num)++;

    ordenarBestiarioNombre(arr, *num);

    printf("Bestia añadida a la lista correctamente\n");
    return;

}

//Eliminar bestia
void eliminarBestia(struct Bestia arr[], int *num){
    char nombre[80];
    printf("Ingrese el nombre de la bestia a eliminar: ");
    scanf(" %79[^\n]", nombre);

    int i, j;
    bool encontrado = false;

    for (i = 0; i < *num; i++){
        if (strcmp(arr[i].nombre, nombre) == 0){
            encontrado = true;
            break;
        }
    }

    if (!encontrado){
        printf("No se encontro la bestia a eliminar\n");
    }
    else{
        for (j = i; j < *num - 1; j++){
            arr[j] = arr[j + 1];
        }
        (*num)--;
        printf("Bestia eliminada correctamente\n");
    }
}

//Modificar bestia
void modificarBestia(struct Bestia arr[], int num){
    char nombre[80];
    printf("Ingrese el nombre de la bestia a modificar: ");
    scanf(" %79[^\n]", nombre);

    int i;
    bool encontrado = false;

    for (i = 0; i < num; i++){
        if (strcmp(arr[i].nombre, nombre) == 0){
            encontrado = true;
            break;
        }
    }

    if (!encontrado){
        printf("No se encontro la bestia a modificar\n");
    }
    else{
        printf("Ingresar nuevo nombre de la bestia: ");
        scanf(" %49[^\n]", arr[i].nombre);
        printf("Ingresar nueva vida de la bestia: ");
        scanf("%d", &arr[i].vida);
        printf("Ingresar nueva fuerza fisica de la bestia: ");
        scanf("%d", &arr[i].fuerza);
        printf("Ingresar nueva capacidad magica la bestia: ");
        scanf("%d", &arr[i].magia);
        printf("Ingresar nueva rareza de la bestia: ");
        scanf("%d", &arr[i].rareza);
    }
}

int main() {

    struct Bestia Bestiario[MAX_BESTIAS] =
    {
        {"Caballero Globo", 100,4,0,1,
        "Su armadura no es su cuerpo, solamente lo compone una cabeza de globo.\n"
        "Poco se sabe de ellos, salvo sus nombres, donde viven, su sueldo (muy bajo), su autoestima (Tambien baja)\n"
        "Y su comida favorita", 1001},
        
        {"Grulla de cristal", 50,2,6,1,
        "Una grulla hecha de un vidrio especialmente quebradizo, se dedica a ser el hombre bala del circo.\n"
        "Es rarito, pero es especialmente valiente...aunque a veces se arrepiente, tarde, pero lo hace", 1002},

        {"Heladito Magico", 80, 1,10,2,
        "Un hombre magico el cual es un helado con cuerpo, se dedica a los trucos de magian aunque su personalidad\n"
        "aunque su personalidad no es precisamente magica, parece desilucionado", 1003},

    };

    int n = 3;
    int opcion = 0;

    ordenarBestiarioNombre(Bestiario,n);

    printf("\n-----------Bienvenido al bestiario de Between Eyes-----------\n");

    do
    {
        printf("\n-----------Menu de Opciones-----------\n");
        printf("1. Listar bestias\n");
        printf("2. Buscar bestia\n");
        printf("3. Añadir bestia\n");
        printf("4. Eliminar bestia\n");
        printf("5. Modificar bestia\n");
        printf("6. Salir\n");

        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);

        switch (opcion)
        {
        //Listar

        case 1:
        {
            int opcion2 = 0;
            printf("1. Alfabetico\n");
            printf("2. Rareza\n");
            scanf ("%d", &opcion2);

            if (opcion2 == 1){
                ordenarBestiarioNombre(Bestiario,n);
                listarBestiario(Bestiario,n);
            }
            else if (opcion2 == 2)
            {
                struct Bestia BestiarioTemp[MAX_BESTIAS];

                for (int i = 0; i < n; i++){
                    BestiarioTemp[i] = Bestiario[i];
                }
                ordenarBestiarioRareza(BestiarioTemp,n);
                listarBestiario(BestiarioTemp,n);
            }
            else {
                printf("Opcion no valida, regresando a menu...\n");
            }
            
            break;

        }
        //Buscar
        case 2:
        {
            ordenarBestiarioNombre(Bestiario,n);

            struct Bestia encontrada = buscarBestia(Bestiario, n);
            if (strcmp(encontrada.nombre, "") != 0)
            {
                printf("\nBestia encontrada:\n");
                printf("Nombre: %s\n", encontrada.nombre);
                printf("Vida: %d\n", encontrada.vida);
                printf("Fuerza: %d\n", encontrada.fuerza);
                printf("Magia: %d\n", encontrada.magia);
                printf("Rareza: %d\n", encontrada.rareza);
                printf("Descripcion: %s\n", encontrada.descripcion);
            }
            else
            {
                printf("\nNo se encontro la bestia.\n");
            }
        }
            break;
        case 3:
            agregarBestia(Bestiario, &n);
        break;

        case 4:
            eliminarBestia(Bestiario, &n);  
        break;
        case 5:
            modificarBestia(Bestiario, n);
        break;
        default:
            break;
        }
    } while (opcion != 6);
    
    

    
    return 0;

}