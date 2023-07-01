#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <libdstruct.h>

/*
 * Inserta un nodo en orden en la lista que se le pasa, no hace nada en caso
 * de recibir argumentos nulos.
 */
void
dlist_insert_node(Node **lista, Node *nodo)
{
    if (nodo && lista) {
        if (*lista) {
            uint32_t conteo = 0;
            Node *nodo_actual = *lista; 
            while (nodo_actual->next &&
                   nodo_actual->value <= nodo->value)
            {
                nodo_actual = nodo_actual->next;
                conteo++;
            }

            /* Cuando es mayor que todos. */
            if (nodo_actual->value <= nodo->value) {
                node_append(nodo_actual, nodo);
            } else {
                node_prepend(nodo_actual, nodo);
                /* Cuando es menor que todos. */
                if (conteo == 0) { *lista = nodo; }
            }
        } else {
            *lista = nodo;
        }
    }
}

/*
 * Extrae un nodo de una lista doblemente enlazada.
 * Realiza una busqueda lineal para encontrar un nodo, lo desenlaza y
 * regresa su dirección en memoria.
 */
Node *
dlist_extract_node(Node **lista, int32_t id)
{
    Node *nodo_extraido = NULL;
    if (lista && *lista) {
        Node *nodo_actual = *lista;
        while (nodo_actual->next && nodo_actual->value != id) {
            nodo_actual = nodo_actual->next;
        }

        if (nodo_actual->value == id) {
            if (nodo_actual->previous) {
                nodo_actual->previous->next = nodo_actual->next;
            } else {
                *lista = nodo_actual->next;
            }
            if (nodo_actual->next) {
                nodo_actual->next->previous = nodo_actual->previous;
            }
            nodo_actual->previous = nodo_actual->next = NULL;
            nodo_extraido = nodo_actual;
        }
    }
    return nodo_extraido;
}

/*
 * Comprueba si existe un nodo dentro de una lista doblemente enlazada.
 * En caso de encontrarlo regresa verdadero, caso contrario regresa falso.
 */
bool
dlist_search_node(Node **lista, int32_t id)
{
    if (lista && *lista) {
        Node *nodo_actual = *lista;
        while (nodo_actual->next && nodo_actual->value != id) {
            nodo_actual = nodo_actual->next;
        }
        if (nodo_actual->value == id) {
            return true;
        }
    }
    return false;
}

/*
 * Imprime todos los elementos de la lista.
 */
void
dlist_imprimir(Node **lista)
{
    if (lista && *lista) {
        node_print_all_linked_nodes(*lista);
    }
}
