#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
  // Comprobar que argc vale 3
    if (argc != 3)
  {
    fprintf(stderr, "Uso: %s linea numero_linea\n", argv[0]);
    exit(EXIT_FAILURE);
  }
  

  // Llamar a una función que me diga en que líneas existe el patron
  procesar_linea(argv[1], argv[2]);

  return EXIT_SUCCESS;
}

void procesar_linea(char *fichero, char *patron)
{
    char linea[256];
    int ch;
    // Declaramos numlinea
    int numLinea = 1;

    // Abrir el archivo
    FILE *archivo = fopen(*fichero, "r");

    if (archivo == NULL)
    {
      fprintf(stderr, "Error al abrir el fichero. \n", *fichero);
      exit(EXIT_FAILURE);
    }
    

    // Hacer un bucle que vaya leyendo linea a linea 
    while (fgets(linea, sizeof(linea), archivo) != NULL)
    {
      //Busca la palabra en la linea
      if (strstr(linea, ))
      {
        /* code */
      }
      
    }
    
    // Dentro del bucle, con strstr buscar el patron dentro de la linea
    // Si existe, tenemos que imprimir esto:
    printf("[PROCESADOR %d] Patron '%s' encontrado en linea %d\n",getpid(),patron,numLinea);

    // Cerrar el fichero

}


