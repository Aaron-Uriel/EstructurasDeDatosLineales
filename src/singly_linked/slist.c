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
    /* 
     * Probablemente se puede mejorar, lo estoy haciendo basado en la 
     * lista doblemente ligada. 
     */
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
            }
            else {
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
        nodo_actual = nodo_anterior = *lista;
        while (nodo_actual->next && nodo_actual->value != id) {
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
 * Comprueba si existe un nodo con el id pasado como argumento
 * dentro de la lista.
 * Regresa verdadero si existe hay al menos un nodo con el mismo id.
 */
bool
slist_search_snode(SNode **const lista, int32_t id) {
    if (lista && *lista) {
        /* ¿Se puede mejorar la búsqueda? */
        SNode *nodo_actual = *lista;
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
 * Imprime la lista.
 */
void
slist_print(SNode *lista)
{
    if (lista) {
        snode_print_all_linked_nodes(lista);
    }
}

