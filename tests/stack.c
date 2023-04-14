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
    SNode *sstack_delete;
    

    if (sstack == NULL) {
        printf("No hay elementos a eliminar");
    } else
        {
            sstack_delete = snode_jump_to_last(*sstack);
            printf("Se eliminó %d\n", sstack_delete -> value);
            free(sstack_delete);

    
        }   
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
    
     printf("Numero del nodo: ");
    scanf("%d", &id );
    sstack_insert_node(&sstack, snode, id);
    sstack_imprimir(&sstack);



    return 0;
}
