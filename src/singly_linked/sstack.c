#include <stdio.h>
#include <stdlib.h>
#include <libdstruct.h>


/*
 * Inserta un nodo en la pila en el primer lugar (el tope de la pila).
 */
void
sstack_insert_node(SNode **pila, SNode *nodo)
{
    if (pila) {
        if (*pila) {
            nodo->next = *pila;
        }
        *pila = nodo;
    }
}

/*
 * Extrae el primer nodo de la pila (el de más arriba) y también lo desenlaza.
 */
SNode *
sstack_delete(SNode **pila)
{
    SNode *nodo_extraido = NULL;
    if (pila && *pila) {
        nodo_extraido = *pila;
        *pila = (*pila)->next;
    }
    return nodo_extraido;
}

void
sstack_free(SNode **pila)
{
    snode_free_group(pila);
}

/*
 * Imprime todos los nodos dentro de la pila.
 */
void
sstack_imprimir(SNode **pila)
{
    snode_print_all_linked_nodes(*pila);
}

