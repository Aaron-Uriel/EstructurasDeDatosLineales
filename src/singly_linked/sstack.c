#include <stdio.h>
#include <stdlib.h>
#include <libdstruct.h>

void
sstack_insert_node(SNode **sstack, SNode *snode, int id)
{
    snode = snode_new(id); 
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


void sstack_imprimir(SNode **sstack)
{
    snode_print_all_linked_nodes(*sstack);
}