#include <stdio.h>

int main()
{
  int matriz1[3][3] = {
      {1, 2, 3},
      {4, 5, 1},
      {4, 3, 6}};

  int matriz2[3][3] = {
      {1, 4, 6},
      {2, 5, 7},
      {3, 6, 8}};
    
      //Cargar matriz 1
    printf ("Escriba los valores de la primera matriz\n");
    for (int x = 0 ;x < 3; x++){
        for (int y = 0; y < 3; y++){
            printf("Matriz[%d][%d]: ",x,y);
            scanf("%d", &matriz1[x][y]);
        }
    }
    
    //Cargar matriz 2
     printf ("\nEscriba los valores de la segunda matriz\n");
    for (int x = 0 ;x < 3; x++){
        for (int y = 0; y < 3; y++){
            printf("Matriz2[%d][%d]: ",x,y);
            scanf("%d", &matriz2[x][y]);
        }
    }

  // Recorrer la matriz y la va a sumar
  for (int x = 0; x < 3; x++)
  {
    for (int y = 0; y < 3; y++)
    {
      printf("\t %d ", matriz1[x][y] + matriz2[x][y]);
    }
    printf("\n");
  }

  return 0;
}