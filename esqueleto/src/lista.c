#include <stdio.h>
#include <stdlib.h>
#include <lista.h>

// Crea una lista con un nodo.
void crear(TLista *pLista, char *valor)
{
  pLista->pPrimero = malloc(sizeof(TNodo)); // memoria del tamaño de una caja (crea un pPrimero a una zona de memoria que tiene este tamaño, pPrimero apunta a ese espacio)
  char *pValor = malloc(strlen(valor) * sizeof(char));
  strcpy(pValor, valor);

  pLista->pPrimero->valor = pValor;
  pLista->pPrimero->pSiguiente = NULL;
}

void destruir(TLista *pLista)
{
  TNodo *pAux1;
  struct Nodo *pAux2;

  for (pAux1 = pLista->pPrimero; pAux1 != NULL;)
  {
    pAux2 = pAux1->pSiguiente;
    free(pAux1);
    pAux1 = pAux2;
  }

  free(pLista);
}

// Inserta al ppio de la lista.
void insertar(TLista *pLista, char *valor)
{
  TNodo *pAux;
  pAux = malloc(sizeof(TNodo));

  char *pValor = malloc(strlen(valor) * sizeof(char));
  strcpy(pValor, valor);

  pAux->valor = pLista->pPrimero->valor;
  pAux->pSiguiente = pLista->pPrimero->pSiguiente;

  pLista->pPrimero->valor = pValor;
  pLista->pPrimero->pSiguiente = pAux;
}

void insertarFinal(TLista *pLista, char *valor)
{
  TNodo *pAux;
  TNodo *pAux1 = NULL;

  char *pValor = malloc(strlen(valor) * sizeof(char));
  strcpy(pValor, valor);

  if (pLista->pPrimero == NULL)
  {
    pLista->pPrimero = malloc(sizeof(TNodo));
    pLista->pPrimero->valor = pValor;
    pLista->pPrimero->pSiguiente = NULL;
  }
  pAux = pLista->pPrimero;

  while (pAux != NULL)
  {
    pAux1 = pAux;
    pAux = pAux->pSiguiente;
  }

  pAux = malloc(sizeof(TNodo));
  pAux->valor = pValor;
  pAux1->pSiguiente = pAux;
}

// Suponemos n = 1, 2, ...
void insertarN(TLista *pLista, int index, char *valor)
{

  char *pValor = malloc(strlen(valor) * sizeof(char));
  strcpy(pValor, valor);

  if (index < 0)
  {
    printf("No existe este índice.\n");
    return;
  }

  TNodo *pAux1;
  pAux1 = malloc(sizeof(TNodo));

  if (pAux1 == NULL)
  {
    printf("Error: No se pudo asignar memoria.\n");
    return;
  }

  pAux1->valor = pValor;

  // Caso especial: si el índice es cero, el nuevo nodo será el nuevo primer nodo
  if (index == 0)
  {
    pAux1->pSiguiente = pLista->pPrimero;
    pLista->pPrimero = pAux1;
    return;
  }

  // Apuntadores auxiliares para recorrer la lista
  TNodo *pAux2 = pLista->pPrimero; // puntero actual
  TNodo *pAux3 = NULL;             // puntero anterior
  int contador = 0;

  // Recorremos la lista hasta el nodo en la posición index o hasta el final si index es mayor al tamaño de la lista
  while (pAux2 != NULL && contador < index)
  {
    pAux3 = pAux2;
    pAux2 = pAux2->pSiguiente;
    contador++;
  }

  // Si index excede el tamaño de la lista, mostramos un mensaje de error
  if (contador < index)
  {
    printf("No existe este índice.\n");
    free(pAux1);
    return;
  }

  // Insertamos el nuevo nodo entre el puntero anterior y el actual
  pAux1->pSiguiente = pAux2;
  pAux3->pSiguiente = pAux1;
}

// Elimina el primer elemento de la lista.
void eliminar(TLista *pLista)
{

  // Creamos un puntero auxiliar
  TNodo *pAux1;

  // Guardamos temporalmente pSiguiente de pPrimero para no perderlo
  pAux1 = malloc(sizeof(TNodo));
  pAux1 = pLista->pPrimero->pSiguiente;

  // Liberamos pPrimero
  free(pLista->pPrimero);

  // Clonamos pAux1 en pPrimero

  pLista->pPrimero = pAux1;
}

void eliminarN(TLista *pLista, int index)
{
  // Apuntamos primer nodo de la lista y recorremos hasta el nodo deseado
  TNodo *pAux = pLista->pPrimero;
  TNodo *pAux1 = NULL;
  int contador = 0;

  if (index < 0)
  {
    printf("No existe este indice\n");
  }
  else
  {

    // Si se quiere eliminar el primer elemento de la lista (Asumimos que la lista empieza desde 1)

    if (index == 0)
    {
      // Llamamos a la funcion eliminar
      eliminar(pLista);
      // Devolvemos llamada
      return;
    }

    // Mientras pAux no sea NULL y el indice sea distinto
    while (index != contador && pAux != NULL)
    {

      // Movemos el puntero pAux hasta el nodo deseado
      pAux1 = pAux;
      pAux = pAux->pSiguiente;
      contador++;
    }

    // Ya tenemos posicionado el nodo a eliminar, pasamos al pSiguiente del

    pAux1->pSiguiente = pAux->pSiguiente;

    // Eliminamos nodo
    free(pAux);
  }
}

char *getElementoN(TLista *pLista, int index)
{

  // Creamos un nodo auxiliar que recorre la lista
  TNodo *pAux;
  int contador = 0;

  pAux = pLista->pPrimero;
  if (index < 0)
  {
    printf("No existe este índice.\n");
    return NULL;
  }

  // Recorremos la lista
  while (pAux != NULL && contador < index)
  {
    pAux = pAux->pSiguiente;

    contador++;
  }

  // Si el índice es mayor que el tamaño de la lista, imprimimos un mensaje de error
  if (contador < index)
  {
    printf("no existe este índice.\n");
    return NULL;
  }

  return pAux->valor;
}

void imprimir(TLista *pLista)
{
  TNodo *pAux = pLista->pPrimero;

  printf("Lista: \n");
  while (pAux != NULL)
  {
    printf("%s \n ", pAux->valor);
    pAux = pAux->pSiguiente;
  }
  printf("\n");
}

int longitud(TLista *pLista)
{
  TNodo *pAux1;
  int contador = 0;

  // Primero apuntamos al primer nodo de la lista

  pAux1 = pLista->pPrimero;

  // Mientras el pSiguiente no sea nulo, que avance al siguiente
  while (pAux1 != NULL)
  {
    contador++;
    pAux1 = pAux1->pSiguiente;
  }

  return contador;
}