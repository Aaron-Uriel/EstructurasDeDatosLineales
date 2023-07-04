#include <stdio.h>
#include <stdlib.h>
#include <libdstruct.h>

/*
 * Asigna el espacio en memoria para una cola con cabecera, la cola está
 * inicialmente vacía.
 */
HQueue *
hqueue_new(void) {
    HQueue *nueva_cola = calloc(1, sizeof(*nueva_cola));
    return nueva_cola;
}

/*
 * Inserta un nodo al final de la cola.
 */
void
hqueue_insert(HQueue *cola, Node *nodo)
{
    if (cola && nodo) {
        if (cola->size) {
            node_append(cola->last, nodo);
        } else {
            cola->first = nodo;
        }
        cola->last = nodo;
        cola->size += 1;
    }
}

/*
 * Extrae un nodo del principio de la cola.
 */
Node *
hqueue_extract(HQueue *cola)
{
    Node *nodo_extraido = NULL;
    if (cola && cola->size) {
        nodo_extraido = cola->first;
        cola->first = cola->first->next;
        if (cola->first) {
            cola->first->previous = NULL;
        } else {
            cola->last = NULL;
        }
        cola->size -= 1;
        nodo_extraido->next = nodo_extraido->previous = NULL;
    }
    return nodo_extraido;
}

/*
 * Libera toda la memoria relacionada con la cola con cabecera, incluyendo
 * a los miembros de la estructura y a toda la estructura.
 */
void
hqueue_free(HQueue **cola)
{
    if (cola && *cola) {
        node_free_group(&(*cola)->first);
        free(*cola);
        *cola = NULL;
    }
}

/*
 * Imprime todos los nodos dentro de la cola.
 */
void
hqueue_print(HQueue *cola)
{
    if (cola && cola->size) {
        printf("Tamaño: %d.\n", cola->size);
        node_print_all_linked_nodes(cola->first);
    }
}

