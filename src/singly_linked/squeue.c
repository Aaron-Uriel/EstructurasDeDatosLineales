#include <stdlib.h>
#include <stdio.h>

#include <libdstruct.h>

/*
 * Extrae el primer nodo de la Cola.
 */
SNode *
squeue_dequeue(SNode **const squeue)
{
    if (*squeue == NULL) {
        return NULL;
    }

    SNode *const extracted_node = *squeue;
    SNode *const new_first_node = (*squeue)->next;
    extracted_node->next = NULL;
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
        *squeue = snode;
        return;
    }

    SNode *const last_node_in_squeue = snode_jump_to_last(*squeue);
    snode_append(last_node_in_squeue, snode);
}

/*
 * Imprime todos los nodos relacionados en la cola.
 */
void
squeue_print(SNode *squeue)
{
    if (squeue == NULL) {
        return;
    }
    snode_print_all_linked_nodes(squeue);
}

