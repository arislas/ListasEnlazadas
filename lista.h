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

/* Ordena los indices de la lista cuando se inserta o elimina un nodo. */
void ordenarIndices(tNodo* cabeza);

/* Crea un nodo a partir de los valores introducidos. No se introduce en la lista. */
tNodo* crearNodoAislado(char* nombre, float precio, int unidades);

/* Inserta un nodo al principio. Recibe un puntero doble a la cabeza de la lista y un puntero
   al nodo nuevo que se quiere insertar al principio. */
void insertarAlPrincipio(tNodo** cabeza, tNodo* nodoNuevo);

/* Inserta un nodo al principio de la lista y reordena los indices a partir del nodo nuevo. */
void push(tNodo** cabeza, char* nombre, float precio, int unidades);