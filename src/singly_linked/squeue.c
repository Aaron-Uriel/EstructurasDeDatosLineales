#include <stdlib.h>
#include <stdio.h>

#include <libdstruct.h>
#include <report.h>

SNode *
squeue_dequeue(SNode **const squeue)
{
    if (*squeue == NULL) {
        report(__func__, ERROR, NULL_DATA_STRUCT);
        return NULL;
    }
    SNode *const extracted_node = *squeue;
    *squeue = (*squeue)->next;

    return extracted_node; 
}

void
squeue_enqueue(SNode **squeue, SNode *snode)
{
    if (*squeue == NULL) {
        report(__func__, INFO, NULL_DATA_STRUCT);
        *squeue = snode;
        return;
    }
    SNode *const last_node_in_squeue = snode_jump_to_last(*squeue);
    last_node_in_squeue->next = snode;
}

void
squeue_print(SNode *squeue)
{
    if (squeue == NULL) {
        report(__func__, ERROR, NULL_DATA_STRUCT);
        return;
    }
    snode_print_all_linked_nodes(squeue);
}

