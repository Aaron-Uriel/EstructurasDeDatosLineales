#include <libdstruct.h>
#include<stdio.h>

/* 
 * Aquí probamos las funciones de la pila y vemos que todo va bien xd.
 * Si algo sale más return 1;, y si todo ta' bien return 0;
 */

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


int
main(void)
{
    SNode *sstack = NULL, *snode = NULL;
    int id;
    printf("Numero del nodo: ");
    scanf("%d", &id );
    snode = snode_new(id); 
    sstack_insert_node(&sstack, snode);
    sstack_imprimir(sstack);

    return 0;
}
