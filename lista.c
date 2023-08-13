#include "lista.h"
#include <stdlib.h>

/* Recibe el puntero a un nodo e imprime sus datos. */
void imprimirNodo(tNodo* nodo) {
    if (nodo == NULL) {
        printf("El nodo NO EXISTE.\n\n");
        return;
    }

    const char* mensajeNoSiguiente = "No hay nodo siguiente";
    const char* siguiente = (nodo->siguiente == NULL) ? mensajeNoSiguiente : nodo->siguiente->nombre;

    printf("Indice: %d.\n", nodo->indice);
    printf("Nombre: %s.\n", nodo->nombre);
    printf("Precio: %.2f €.\n", nodo->precio);
    printf("Unidades: %d.\n", nodo->unidades);
    printf("Valor total: %.2f €.\n", nodo->valorTotal);
    printf("Nodo siguiente: %s.\n\n", siguiente);
}


/* Recibe un puntero a la cabeza e imprime todos los nodos de la lista. */
void imprimirLista(tNodo* cabeza) {
    tNodo* actual = cabeza;

    if (cabeza == NULL) {
        printf("La lista NO EXISTE.\n\n");
        return;
    }

    while (actual != NULL) {
        imprimirNodo(actual);
        actual = actual->siguiente;
    }
}


/* Recibe un puntero a la cabeza de una lista y cuenta los nodos que hay en ella. */
int numeroNodos(tNodo* cabeza) {
    if (cabeza == NULL) {
        printf("La lista NO EXISTE.\n\n");
        return 0;
    }

    tNodo* actual = cabeza;
    int contador = 0;

    while (actual != NULL) {
        actual = actual->siguiente;
        contador++;
    }

    return contador;
}


/* Devuelve el nodo nulo. */
tNodo* nodoNulo() {
    tNodo* nulo = (tNodo*)malloc(sizeof(tNodo));

    if (nulo == NULL) {
        /* Error de asignacion de memoria. */
        perror("No se ha podido asignar memoria al nodo nulo.\n\n");
        exit(EXIT_FAILURE);
    }

    nulo->indice = -1;
    nulo->nombre = "NODO NULO";
    nulo->precio = 0.0;
    nulo->unidades = 0;
    nulo->valorTotal = 0.0;
    nulo->siguiente = NULL;

    return nulo;
}


/* Localiza y devuelve un puntero al elemento cuyo indice se pasa por parametro. La cabeza de la lista tambien
   se pasa por parametro. */
tNodo* localizaNodo(tNodo* cabeza, int indice) {
    tNodo* actual = cabeza;
    tNodo* nulo = nodoNulo();
    nulo->indice = indice;
    int contador = 0;

    if (cabeza == NULL || indice < 0 || indice >= numeroNodos(actual)) {
        printf("Indice fuera de la lista. El nodo no existe. Indices entre %d y %d.\n\n", 0, numeroNodos(cabeza) - 1);
        return nulo;
    }

    if (indice == 0) {
        return actual;
    } else {
        while (actual->siguiente != NULL && contador < indice) {
            actual = actual->siguiente;
            contador++;
        }
        if (actual == NULL) {
            printf("Indice fuera de la lista. El nodo no existe. Indices entre %d y %d.\n\n", 0, numeroNodos(cabeza) - 1);
            return nulo;
        }
        return actual;
    }
}


/* Devuelve un nodo que se crea introduciendo sus valores. Inicialmente tendra el indice despues del ultimo. */
tNodo* crearNodo(tNodo* cabeza) {
    tNodo* nodoNuevo = (tNodo*)malloc(sizeof(tNodo));

    if (nodoNuevo == NULL) {
        perror("Error al asignar memoria al nodo.\n\n");
        exit(EXIT_FAILURE);
    }

    nodoNuevo->nombre = (char*)malloc(100 * sizeof(char)); // Necesario para que no de error la asignacion.
    
    if (nodoNuevo->nombre == NULL) {
        perror("Error al asignar memoria al nombre del nodo.\n\n");
        exit(EXIT_FAILURE);
    }

    printf("Introduzca el nombre: ");
    fgets(nodoNuevo->nombre, 100, stdin);
    nodoNuevo->nombre[strcspn(nodoNuevo->nombre, "\n")] = '\0'; // Elimina el caracter de nueva linea si esta.
    nodoNuevo->indice = numeroNodos(cabeza);
    printf("Introduzca el precio: ");
    scanf("%f", &nodoNuevo->precio);
    printf("Introduzca cuantas unidades: ");
    scanf("%d", &nodoNuevo->unidades);
    nodoNuevo->valorTotal = nodoNuevo->unidades * nodoNuevo->precio;
    nodoNuevo->siguiente = NULL;
    printf("\n");

    return nodoNuevo;
}


/* Recibe un puntero a la cabeza de la lista y un doble puntero al ultimo nodo. Crea cuatro nodos nuevos y los añade al final. */
void creaNodos(tNodo* cabeza, tNodo**  ultimoNodo) {
    #define NODOS 4

    int ultimoOrden = numeroNodos(cabeza) - 1;
    char num[6];

    for (int i = 0; i < NODOS; i++) {
        tNodo* nuevoNodo = (tNodo*)malloc(sizeof(tNodo));
        
        if (nuevoNodo == NULL) {
            perror("Error al asignar memoria a nuevoNodo.\n\n");
            exit(EXIT_FAILURE);
        }

        char nombre[100];
        snprintf(nombre, sizeof(nombre), "Nodo%d", ++ultimoOrden);

        nuevoNodo->indice = ultimoOrden;
        nuevoNodo->nombre = (char*)malloc(strlen(nombre) + 1); // Asigna memoria suficiente para el nombre.

        if (nuevoNodo->nombre == NULL) {
            perror("Error al asignar memoria para el nombre del nodo.\n\n");
            exit(EXIT_FAILURE);
        }

        strcpy(nuevoNodo->nombre, nombre);

        nuevoNodo->precio = 0.0;
        nuevoNodo->unidades = 0;
        nuevoNodo->valorTotal = nuevoNodo->unidades * nuevoNodo->precio;
        nuevoNodo->siguiente = NULL;

        /* Actualiza el ultimo nodo de la lista. */
        if (*ultimoNodo != NULL) {
            (*ultimoNodo)->siguiente = nuevoNodo;
        }

        *ultimoNodo = nuevoNodo;
    }
}