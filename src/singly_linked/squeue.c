#include <stdlib.h>
#include <stdio.h>

#include <libdstruct.h>

/*
 * Coloca un nodo al final de la cola.
 */
void
squeue_enqueue(SNode **cola, SNode *nodo)
{
    if (cola && nodo) {
        if (*cola) {
            SNode *const nodo_final_cola = snode_jump_to_last(*cola);
            nodo_final_cola->next = nodo;
        } else {
            *cola = nodo;
        }
    }
}

/*
 * Extrae el primer nodo de la Cola.
 */
SNode *
squeue_dequeue(SNode **const cola)
{
    SNode *nodo_extraido = NULL;
    if (cola && *cola) {
        nodo_extraido = *cola;
        *cola = (*cola)->next;
        nodo_extraido->next = NULL;
    }
    return nodo_extraido; 
}

/*
 * Libera toda la memoria asignada por la cola y hace que la cola apunte a
 * NULL dejandola vacía.
 */
void
squeue_free(SNode **cola)
{
    snode_free_group(cola);
}

/*
 * Imprime todos los nodos relacionados en la cola.
 */
void
squeue_print(SNode *cola)
{
    if (cola) {
        snode_print_all_linked_nodes(cola);
    }
}

