#include "lista.h"

int main() {
    printf("\n");
    printf("====================================================================================================\n");
    printf("====================================================================================================\n");
    printf("========================================= LISTA DEFINITIVA =========================================\n");
    printf("====================================================================================================\n");
    printf("====================================================================================================\n\n");

    printf("En primer lugar, creamos un puntero a un tipo de datos para guardar un orden, un nombre de producto,\n"
           "un precio, una catidad de unidades, el valor de todas las unidades juntas y un puntero al siguiente\n"
           "elemento.\n\n");

    printf("Luego creamos el puntero al primer nodo al que llamaremos \"cabeza\", le asignaremos memoria y le\n"
           "asgnaremos unos datos. Su indice sera \"0\".\n\n");

    tNodo* cabeza = (tNodo*)malloc(sizeof(tNodo));
    cabeza->indice = 0;
    cabeza->nombre = "cabeza";
    cabeza->precio = 0.0;
    cabeza->unidades = 0;
    cabeza->valorTotal = 0.0;
    cabeza->siguiente = NULL;

    printf("====================================================================================================\n");
    printf("    ===================================== imprimirNodo =========================================\n");
    printf("====================================================================================================\n\n");


    printf("Ahora creamos la funcion \"imprimirNodo\" que recibira un puntero a un nodo e imprimira sus datos.\n\n");
    imprimirNodo(cabeza);

    printf("====================================================================================================\n");
    printf("     ==================================== numeroNodos =========================================\n");
    printf("====================================================================================================\n\n");


    printf("Probamos la funcion \"numeroNodos\" que crearemos en el siguiente paso para ver si tambien funciona con\n"
           "un solo nodo.\n\n");
           printf("Ahora mismo la lista solo tiene %d nodo.\n\n", numeroNodos(cabeza));

    printf("Creamos un segundo nodo, lo enlazamos a \"cabeza\" y le damos valores para ver si la funcion \n"
           "\"imprimirNodo\" funciona bien.\n\n");

    tNodo* segundo = (tNodo*)malloc(sizeof(tNodo));
    cabeza->siguiente = segundo;
    segundo->indice = 1;
    segundo->nombre = "Datiles";
    segundo->precio = 2.61;
    segundo->unidades = 4;
    segundo->valorTotal = segundo->unidades * segundo->precio;
    segundo->siguiente = NULL;

    printf("====================================================================================================\n");
    printf("    ===================================== imprimirNodo =========================================\n");
    printf("====================================================================================================\n\n");

    imprimirNodo(cabeza);
    imprimirNodo(segundo);

    printf("====================================================================================================\n");
    printf("     ==================================== numeroNodos =========================================\n");
    printf("====================================================================================================\n\n");

    printf("La funcion \"numeroNodos\" cuenta los nodos que hay en una lista recibiendo la cabeza de la lista.\n\n");

    printf("En la lista hay %d nodos.\n\n", numeroNodos(cabeza));

    printf("====================================================================================================\n");
    printf("    ==================================== imprimirLista =========================================\n");
    printf("====================================================================================================\n\n");

    printf("La funcion \"imprimirLista\" imprime todos los nodos de la lista. El puntero a la cabeza se pasa como\n"
           "parametro.\n\n");
    imprimirLista(cabeza);

    printf("====================================================================================================\n");
    printf("    ===================================== localizaNodo =========================================\n");
    printf("====================================================================================================\n\n");

    printf("Probamos la funcion \"localizaNodo\". Primero introducimos un indice menor que 0 y luego uno mayor que el\n"
           "numero de nodos que hay en la lista.\n\n");

    printf("Probamos con indice \"-1\":\n");
    imprimirNodo(localizaNodo(cabeza, -1));
    printf("Probamos con indice \"72\" (fuera de la lista):\n");
    imprimirNodo(localizaNodo(cabeza, 72));
    printf("Probamos con indice \"0\":\n");
    imprimirNodo(localizaNodo(cabeza, 0));
    printf("Probamos con el ultimo indice dentro de la lista \"1\":\n");
    imprimirNodo(localizaNodo(cabeza, 1));
    printf("Probamos con el primer indice fuera de la lista \"2\":\n");
    imprimirNodo(localizaNodo(cabeza, 2));

    printf("====================================================================================================\n");
    printf("        ================================== crearNodo =========================================\n");
    printf("====================================================================================================\n\n");

    printf("La funcion \"crearNodo\" devuelve un nodo cuyos valores se introducen por teclado.\n\n");
    imprimirNodo(crearNodo(cabeza));

    printf("====================================================================================================\n");
    printf("       ================================== crearNodos =========================================\n");
    printf("====================================================================================================\n\n");

    tNodo* ultimoNodo = localizaNodo(cabeza, (numeroNodos(cabeza) - 1));
    creaNodos(cabeza, &ultimoNodo);
    imprimirLista(cabeza);
    printf("La lista contiene ahora %d nodos.\n\n", numeroNodos(cabeza));
    ultimoNodo = localizaNodo(cabeza, (numeroNodos(cabeza) - 1));
    creaNodos(cabeza, &ultimoNodo);
    imprimirLista(cabeza);
    printf("La lista contiene ahora %d nodos.\n\n", numeroNodos(cabeza));
    ultimoNodo = localizaNodo(cabeza, (numeroNodos(cabeza) - 1));
    creaNodos(cabeza, &ultimoNodo);
    imprimirLista(cabeza);
    printf("La lista contiene ahora %d nodos.\n\n", numeroNodos(cabeza));

    return 0;
}