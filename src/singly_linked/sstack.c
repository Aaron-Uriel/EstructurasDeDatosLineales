#include <stdio.h>
#include <stdlib.h>
#include <libdstruct.h>

void sstack_insert_node(SNode **sstack, SNode *snode)
{
    if (sstack == NULL) {
        sstack = &snode;
    } else {
        SNode *const last_node_in_sstack = snode_jump_to_last(*sstack);
        last_node_in_sstack->next = snode;
    }
}

void sstack_imprimir(const SNode *const *const sstack)
{
    snode_print_all_linked_nodes(*sstack);
}
