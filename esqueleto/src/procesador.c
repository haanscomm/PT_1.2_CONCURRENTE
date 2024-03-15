#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

#define PATH_MAX 4096

// Declaración de la función procesar_linea
void procesar_linea(char *fichero, char *patron);

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
    // Declaramos numlinea
    int numLinea = 1;

    // Abrir el archivo
    FILE *fp;
    char linea[PATH_MAX];

    if ((fp = fopen(fichero, "r")) == NULL)
  {
    fprintf(stderr, "Error al abrir el fichero %s\n", fichero);
    exit(EXIT_FAILURE);
  }

    // Hacer un bucle que vaya leyendo linea a linea 
  while (fgets(linea, sizeof(linea), fp) != NULL)
  {
    //Busca la palabra en la linea
    // Dentro del bucle, con strstr buscar el patron dentro de la linea
    if (strstr(linea, patron) != NULL)
    {
    // Si existe, tenemos que imprimir esto:
    printf("[PROCESADOR %d] Patron '%s' encontrado en linea %d\n",getpid(),patron,numLinea);
      
    }
    numLinea++;
     
  }
    

    // Cerrar el fichero
    fclose(fp);

}


