#include "includes.h"

typedef struct nodo {
    int indice;
    char* nombre;
    float precio;
    int unidades;
    float valorTotal;
    struct nodo* siguiente;
} tNodo;

/* Recibe el puntero a un nodo e imprime sus datos. */
void imprimirNodo(tNodo* nodo);

/* Recibe un puntero a la cabeza e imprime todos los nodos de la lista. */
void imprimirLista(tNodo* cabeza);

/* Recibe un puntero a la cabeza de una lista y cuenta los nodos que hay en ella. */
int numeroNodos(tNodo* cabeza);

/* Devuelve el nodo nulo. */
tNodo* nodoNulo();

/* Localiza y devuelve un puntero al elemento cuyo indice se pasa por parametro. La cabeza de la lista tambien
   se pasa por parametro. */
tNodo* localizaNodo(tNodo* cabeza, int indice);

/* Devuelve un nodo que se crea introduciendo sus valores. Inicialmente tendra el indice despues del ultimo. */
tNodo* crearNodo(tNodo* cabeza);

/* Recibe un puntero a la cabeza de la lista y un doble puntero al ultimo nodo. Crea cuatro nodos nuevos y los añade al final. */
void creaNodos(tNodo* cabeza, tNodo**  ultimoNodo);