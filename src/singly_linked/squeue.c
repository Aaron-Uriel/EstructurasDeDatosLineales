#include <stdlib.h>
#include <stdio.h>

#include <libdstruct.h>
#include <error.h>

SNode *
squeue_enqueue(SNode **const squeue)
{
    if (squeue == NULL) {
        //error(__func__, ERR_NULL_DATA_STRUCT);
        return NULL;
    }

    SNode *const extracted_node = *squeue;
    *squeue = (*squeue)->next;

    return extracted_node; 
}

void
squeue_insert_node(SNode **squeue, SNode *snode)
{
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

