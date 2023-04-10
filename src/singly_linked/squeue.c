#include <stdlib.h>
#include <stdio.h>

#include <libdstruct.h>

SNode *
squeue_extract_node(SNode **const squeue)
{
    /* squeue solo  es NULL si la cola está vacía */
    if (squeue == NULL) {
        return NULL;
    } else {
        SNode *const extracted_node = *squeue;
        *squeue = (*squeue)->next;
        return extracted_node; 
    }
}

void
squeue_insert_node(SNode **squeue, SNode *snode)
{
    /* squeue solo es NULL cuando la cola está vacía. */
    if (squeue == NULL) {
        squeue = &snode;
    } else {
        SNode *const last_node_in_squeue = snode_jump_to_last(*squeue);
        last_node_in_squeue->next = snode;
    }
}

void
squeue_imprimir(const SNode *const *const squeue)
{
    snode_print_all_linked_nodes(*squeue);
}

