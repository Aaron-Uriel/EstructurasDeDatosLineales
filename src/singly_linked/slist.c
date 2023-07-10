#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include <libdstruct.h>

/*
 * Inserta un nodo de forma ordenada en la lista. Los nodos se acomodan de
 * forma ascendente.
 */
void
slist_insert_snode(SNode **lista, SNode *nodo)
{
    if (lista && nodo) {
        if (*lista) {
            uint32_t conteo = 0;
            SNode *nodo_actual, *nodo_anterior;
            nodo_actual = nodo_anterior = *lista;
            while (nodo_actual->next &&
                   nodo_actual->value <= nodo->value)
            {
                nodo_anterior = nodo_actual;
                nodo_actual = nodo_actual->next;
                conteo++;
            }

            /* Es mayor que todos. */
            if (nodo_actual->value <= nodo->value) {
                nodo_actual->next = nodo;
            } else {
                nodo->next = nodo_actual;
                /* Cuando es el menor de todos. */
                if (conteo == 0) {
                    *lista = nodo;
                } else {
                    nodo_anterior->next = nodo;
                }
            }
        } else {
            *lista = nodo;
        }
    }
}

/*
 * Extrae un nodo de una posición arbitraria dentro de los confines de la lista.
 * En caso de intentar extraer un nodo fuera de los límites, la función
 * regresa NULL.
 */
SNode *
slist_extract_node(SNode **const lista, int32_t id)
{
    SNode *nodo_extraido = NULL;
    if (lista && *lista) {
        uint32_t conteo = 0;
        SNode *nodo_actual, *nodo_anterior;
        nodo_actual = *lista;
        while (nodo_actual->next && nodo_actual->value != id) {
            nodo_anterior = nodo_actual;
            nodo_actual = nodo_actual->next;
            conteo++;
        }

        if (nodo_actual->value == id) {
            if (conteo) {
                nodo_anterior->next = nodo_actual->next;
            } else {
                *lista = nodo_actual->next;
            }
            nodo_actual->next = NULL;
            nodo_extraido = nodo_actual;
        }
    }
    return nodo_extraido;
}

/*
 * Busca un nodo en la lista, en caso de existir se regresa la dirección
 * en memoria del nodo.
 */
SNode *
slist_search_snode(SNode **const lista, int32_t id) {
    if (lista && *lista) {
        SNode *nodo_actual = *lista;
        while (nodo_actual->next && nodo_actual->value != id) {
            nodo_actual = nodo_actual->next;
        }
        if (nodo_actual->value == id) {
            return nodo_actual;
        }
    }
    return NULL;
}

/*
 * Libera la memoria asignada por la lista.
 */
void
slist_free(SNode **lista)
{
    snode_free_group(lista);
}

/*
 * Imprime la lista.
 */
void
slist_print(SNode *lista)
{
    if (lista) {
        snode_print_all_linked_nodes(lista);
    }
}

