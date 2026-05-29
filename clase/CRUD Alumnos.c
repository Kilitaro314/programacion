#include <stdio.h>

#define MAX_LETRAS 80
#define MAX_PERSONAS 100


struct Persona
{

    int DNI;
    char nombre[MAX_LETRAS];
    char apellido[MAX_LETRAS];
    int nota;

};

//Prototipos
void ordenarAlumnos(struct Persona arr[], int n, int opcion);
void listarAlumnos(struct Persona arr[], int n);
int buscarAlumno(struct Persona arr[], int n);
void mostrarAlumno(struct Persona arr[], int n);


int main() {

    struct Persona estudiantes[MAX_PERSONAS] = {
        {47042254, "Elias","Lopez", 1},
        {47041243, "Frederick","Matosgaut", 4},
        {47043445, "Isaac","Doyle", 6},
        {47043227, "Zara","Arsene", 3},
        {47045243, "Noah","Chevalier",11},
    };

    int n = 5;
    int opcion = 0;

    ordenarAlumnos(estudiantes, n, 2);

    printf("\n-----------Bienvenido a la planilla de alumnos (no sea cruel)-----------\n");

    do
    {
        printf("\n-----------Menu de Opciones-----------\n");
        printf("1. Listar alumnos\n");
        printf("2. Buscar alumno\n");
        printf("3. Añadir alumno\n");
        printf("4. Eliminar alumno\n");
        printf("5. Modificar bestia\n");
        printf("6. Salir\n");

        printf("Ingrese su accion: ");
        scanf("%d", &opcion);

        switch (opcion)
        {
        case 1:
            listarAlumnos(estudiantes, n);
            break;
        
        case 2:
            ordenarAlumnos(estudiantes, n, 2);
            mostrarAlumno(estudiantes, buscarAlumno(estudiantes,n));
            break;
        
        case 3:
            agregarAlumno(estudiantes, &n);
            ordenarAlumnos(estudiantes, n, 2);

            break;
        case 4:
            eliminarAlumno(estudiantes, &n);
            ordenarAlumnos(estudiantes, n, 2);

          break;
        
        case 5:
            printf("Funcion sin añadir\n");
            break;
        
        case 6:
            printf("Saliendo...");
            break;
        default:
            break;
        }


    } while (opcion != 6);
    
    return 0;
}

void ordenarAlumnos(struct Persona arr[], int n, int opcion){
    
    if (opcion < 1 || opcion > 2){
        printf("Opcion no valida\n");
        return;
    }
    struct Persona temp;

    //Ordenar por nota si es 1
    if (opcion == 1){
        for (int i = 0; i < n -1; i++){
            for (int j = 0; j < n - 1 - i; j++){
                if (arr[j].nota > arr[j+1].nota){
                    temp = arr[j];
                    arr[j] = arr[j+1];
                    arr[j+1] = temp;
                }
            }
        }
    }
    //Ordenar por DNI si es 2
    else if (opcion == 2){

        for (int i = 0; i < n -1; i++){
            for (int j = 0; j < n - 1 - i; j++){
                if (arr[j].DNI > arr[j+1].DNI){
                    temp = arr[j];
                    arr[j] = arr[j+1];
                    arr[j+1] = temp;
                }
            }
        }
    }

    return;
}

void listarAlumnos(struct Persona arr[], int n){
    printf("\n------------------Planilla de alumnos------------------\n");
    printf("%-15s %-15s %-10s %-8s\n",
       "Nombre",
       "Apellido",
       "DNI",
       "Nota");
    for (int i = 0; i < n; i++){
        printf("%-15s %-15s %-10d %-8d\n",
        arr[i].nombre,
        arr[i].apellido,
        arr[i].DNI,
        arr[i].nota);
    }

    return;

}  

int buscarAlumno(struct Persona arr[], int n){
    int dni_temp;
    printf("Ingrese DNI del alumno a buscar: ");
    scanf("%d",&dni_temp);

    int inicio = 0;
    int fin = n - 1;

    while (inicio <= fin)
    {
        int medio = inicio + (fin - inicio) /2;

        if (arr[medio].DNI == dni_temp){
            return medio;
        }

        else if (arr[medio].DNI < dni_temp)
        {
            inicio = medio + 1;
        }
        else {
            fin = medio - 1;
        }
        
    }

    return -1;
    
}

void mostrarAlumno(struct Persona arr[], int n){
    if (n < 0) {
        printf("Alumno no encontrado\n");
        return;
    }

    printf("\nAlumno encontrado:\n");
    printf("%-15s %-15s %-10s %-8s\n",
       "Nombre",
       "Apellido",
       "DNI",
       "Nota");
    
    printf("%-15s %-15s %-10d %-8d\n",
    arr[n].nombre,
    arr[n].apellido,
    arr[n].DNI,
    arr[n].nota);

    return;

}

void agregarAlumno(struct Persona arr[], int *n){
    
    if (*n >= MAX_PERSONAS){
        printf("No es posible añadir mas alumnos / Maximo: %d\n", MAX_PERSONAS);
        return;
    }

    struct Persona AlumnoCreado;

    printf("Ingresar nombre del alumno: ");
    scanf(" % 79[^\n]", AlumnoCreado.nombre);

    printf("Ingresar apellido del alumno: ");
    scanf(" %79[^\n]", AlumnoCreado.apellido);

    printf("Ingresar DNI del alumno: ");
    scanf("%d", &AlumnoCreado.DNI);

    printf("Ingresar nota del alumno: ");
    scanf("%d", &AlumnoCreado.nota);

    arr[*n] = AlumnoCreado;
    (*n)++;
    return;
}

void eliminarAlumno(struct Persona arr[], int *n){
    int dni_temp;
    int encontrado = 0;
    int i, j;

    printf("Ingrese el DNI del alumno a eliminar: ");
    scanf("%d", &dni_temp);

    for (i = 0; i < *n; i++){
        if (arr[i].DNI == dni_temp){
            encontrado = 1;
            break;
        }
    }

    if (encontrado == 1){
        for (j = i; j < *n - 1; j++){
            arr[j] = arr[j+1];
        }
        (*n)--;
    }
    else{
        printf("Alumno no encontrado\n");
    }
}