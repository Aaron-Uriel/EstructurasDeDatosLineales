#include <stdlib.h>
#include <stdio.h>

#include <libdstruct.h>
#include <report.h>

/*
 * Extrae el primer nodo de la Cola.
 */
SNode *
squeue_dequeue(SNode **const squeue)
{
    if (*squeue == NULL) {
        report(__func__, ERROR, EMPTY_DATA_STRUCT);
        return NULL;
    }

    SNode *const extracted_node = *squeue;
    SNode *const new_first_node = (*squeue)->next;
    if (new_first_node == NULL) {
        report(__func__, INFO, DATA_STRUCT_WILL_BE_EMPTY);
    }
    *squeue = new_first_node;

    return extracted_node; 
}

/*
 * Coloca un nodo al final de la cola.
 */
void
squeue_enqueue(SNode **squeue, SNode *snode)
{
    if (*squeue == NULL) {
        report(__func__, INFO, EMPTY_DATA_STRUCT);
        *squeue = snode;
        return;
    }

    SNode *const last_node_in_squeue = snode_jump_to_last(*squeue);
    last_node_in_squeue->next = snode;
}

/*
 * Imprime todos los nodos relacionados en la cola.
 */
void
squeue_print(SNode *squeue)
{
    if (squeue == NULL) {
        report(__func__, ERROR, EMPTY_DATA_STRUCT);
        return;
    }
    snode_print_all_linked_nodes(squeue);
}

