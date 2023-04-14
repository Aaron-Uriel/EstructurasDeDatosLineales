#include <libdstruct.h>
#include <stdlib.h>
#include<stdio.h>

/* 
 * Aquí probamos las funciones de la pila y vemos que todo va bien xd.
 * Si algo sale más return 1;, y si todo ta' bien return 0;
 */

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
            while (actual -> next != NULL) 
            {
                actual = actual -> next; 
            }

            actual->next = snode;
        }
    }

    
}


void sstack_imprimir(SNode **sstack)
{
    snode_print_all_linked_nodes(*sstack);
}


void sstack_delete(SNode **sstack)
{
    
    SNode *second_last_snode = *sstack;
    SNode *last_snode = second_last_snode->next;
    if (last_snode == NULL) {
        sstack = NULL;
    }

    while(last_snode->next != NULL) {
        second_last_snode = last_snode;
        last_snode = last_snode->next;
    }
    printf("Se eliminó %d\n",last_snode->value);
    last_snode = NULL;
    second_last_snode->next = NULL;
}


int
main(void)
{
    SNode *sstack = NULL, *snode = NULL;
    int id;
    printf("Numero del nodo: ");
    scanf("%d", &id );
    sstack_insert_node(&sstack, snode, id);
    sstack_imprimir(&sstack);

    printf("Numero del nodo: ");
    scanf("%d", &id );
    sstack_insert_node(&sstack, snode, id);
    sstack_imprimir(&sstack);

    printf("Numero del nodo: ");
    scanf("%d", &id );
    sstack_insert_node(&sstack, snode, id);
    sstack_imprimir(&sstack);
    sstack_delete(&sstack);
    sstack_imprimir(&sstack);

    printf("Numero del nodo: ");
    scanf("%d", &id );
    sstack_insert_node(&sstack, snode, id);
    sstack_imprimir(&sstack);
    sstack_delete(&sstack);
    sstack_imprimir(&sstack);

    return 0;
}
