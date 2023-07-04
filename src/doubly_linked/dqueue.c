#include <stdio.h>
#include <stdlib.h>

#include <libdstruct.h>

/*
 * Coloca un nodo al final de la cola.
 */
void
dqueue_enqueue(Node **cola, Node *nodo)
{
    if (cola && nodo) {
        if (*cola) {
            Node *const nodo_final_cola = node_jump_to_last(*cola);
            node_append(nodo_final_cola, nodo);
        } else {
            *cola = nodo;
        }
    }
}

/*
 * Extrae el primer nodo de la Cola, además, desenlaza al nodo extraido de la
 * cola.
 */
Node *
dqueue_dequeue(Node **const cola)
{
    Node *nodo_extraido = NULL;
    if (cola && *cola) {
        nodo_extraido = *cola;
        *cola = (*cola)->next;
        if (*cola) {
            (*cola)->previous = NULL;
        }
        nodo_extraido->next = nodo_extraido->previous = NULL;
    }
    return nodo_extraido; 
}

void
dqueue_free(Node **cola)
{
    node_free_group(cola);
}

/*
 * Imprime todos los nodos relacionados en la cola.
 */
void
dqueue_print(Node *dqueue)
{
    if (dqueue) {
        node_print_all_linked_nodes(dqueue);
    }
}

