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
  
  return EXIT_SUCCESS;

  // Llamar a una función que me diga en que líneas existe el patron
  procesar_linea(argv[1], argv[2]);

  return EXIT_SUCCESS;
}

void procesar_linea(char *fichero, char *patron)
{

    // Declaramos numlinea
    int numLinea = 1;

    // Abrir el archivo


    // Hacer un bucle que vaya leyendo linea a linea 


    // Dentro del bucle, con strstr buscar el patron dentro de la linea
    // Si existe, tenemos que imprimir esto:
    printf("[PROCESADOR %d] Patron '%s' encontrado en linea %d\n",getpid(),patron,numLinea);

    // Cerrar el fichero

}


