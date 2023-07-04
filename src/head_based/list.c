#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <libdstruct.h>

/* 
 * Crea una nueva lista con cabecera.
 * La lista no contiene ningún nodo al crearse, se crea completamente 
 * vacía.
 */
List *
list_new(void) {
    List *nueva_lista = calloc(1, sizeof(*nueva_lista));
    return nueva_lista;
}

/*
 * Inserta un nodo en la lista con cabecera.
 * El nodo se inserta de forma ordenada, por lo que los nodos quedan
 * organizados de forma ascendente.
 */
void
list_insert_node(List *const lista, Node *const nodo)
{
    if (lista && nodo) {
        /* Cuando la lista no está vacía. */
        if (lista->first && lista->last && lista->size) {
            /* 
             * Manejamos respectivamente los casos:
             * - Menor que el menor de la lista.
             * - Mayor o igual que el mayor de la lista.
             * - Ninguno de los anteriores (buscamos su lugar).
             */
            if (nodo->value < lista->first->value) {
                node_prepend(lista->first, nodo);
                lista->first = nodo;
            }
            else if (nodo->value >= lista->last->value) {
                node_append(lista->last, nodo);
                lista->last = nodo;
            }
            else {
                uint32_t nodos_analizados = 0;
                Node *nodo_actual = lista->first;
                while (nodos_analizados < lista->size  &&
                       nodo_actual->value <= nodo->value)
                {
                    nodo_actual = nodo_actual->next;
                }
                node_prepend(nodo_actual, nodo);
            }
            lista->size += 1;
        } else {
            lista->first = lista->last = nodo;
            lista->size = 1;
        }
    }
}

/*
 * Extrae un nodo de una lista doblemente enlazada.
 * Realiza una busqueda lineal para encontrar un nodo, lo desenlaza y
 * regresa su dirección en memoria.
 */
Node *
list_extract_node(List *const lista, int32_t id)
{
    /* ¿Debería de cambiarlo para aprovechar la cabecera? */
    Node *nodo_extraido = NULL;
    if (lista && lista->size) {
        Node *nodo_actual = lista->first;
        while (nodo_actual->next && nodo_actual->value != id) {
            nodo_actual = nodo_actual->next;
        }
        if (nodo_actual->value == id) {
            lista->size -= 1;
            if (nodo_actual->previous) {
                nodo_actual->previous->next = nodo_actual->next;
            } else {
                lista->first = lista->first->next;
            }
            if (nodo_actual->next) {
                nodo_actual->next->previous = nodo_actual->previous;
            } else {
                lista->last = lista->last->previous;
            }
            nodo_actual->previous = nodo_actual->next = NULL;
            nodo_extraido = nodo_actual;
        }
    }
    return nodo_extraido;
}

/*
 * Libera la memoria relacionada a la lista con cabecera, incluyendo a 
 * la cabecera.
 */
void
list_free(List **lista)
{
    if (lista && *lista) {
        node_free_group(&(*lista)->first);
        free(*lista);
        *lista = NULL;
    }
}

/*
 * Busca un nodo en la lista, en caso de existir se regresa la dirección
 * en memoria del nodo.
 */
Node *
list_search_node(List *const lista, int32_t id)
{
    if (lista && lista->size) {
        /* Por ver: ¿Vale la pensa cambiarlo para que aproveche la cabecera? */
        uint32_t conteo = 0;
        Node *nodo_actual = lista->first;
        while (conteo < lista->size && nodo_actual->value != id) {
            nodo_actual = nodo_actual->next;
            conteo++;
        }
        if (conteo < lista->size) {
            return nodo_actual;
        }
    }
    return NULL;
}


/*
 * Imprime todos los nodos que conforman a la lista con cabecera.
 */
void
list_print(List *const lista)
{
    if (lista && lista->size) {
        printf("Tamaño: %d.\n", lista->size);
        node_print_all_linked_nodes(lista->first);
    }
}

