#include <stdio.h>
#include <stdlib.h>
#include <libdstruct.h>

void sstack_insert_node(SNode **sstack, SNode *snode)
{
    SNode *actual;

    if (snode != NULL)
    {
        if (*sstack == NULL) {
        *sstack = snode;
        } else {
            actual = *sstack; 
            while (actual->next != NULL) 
            {
                actual = actual->next; 
            }

            actual->next = snode;

        }
    }

    
}

SNode *sstack_delete(SNode **sstack)
{
    SNode *second_last_snode = *sstack, *deleted = NULL;
    SNode *last_snode = second_last_snode->next;

    if (*sstack == NULL)
    {
        return deleted;
    }
    
    if (last_snode == NULL) {
        sstack = NULL;
    }

    while(last_snode->next != NULL) {
        second_last_snode = last_snode;
        last_snode = last_snode->next;
    }

    deleted = last_snode;
    last_snode = NULL;
    second_last_snode->next = NULL;
    return deleted;
}


void sstack_imprimir(SNode **sstack)
{
    snode_print_all_linked_nodes(*sstack);
}

