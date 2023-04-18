#include <stdlib.h>
#include <stdio.h>

#include <libdstruct.h>

void dlist_insert_node(Node **dlist, Node *node, int id){
    node = node_new(id); 
    Node *actual = *dlist;
    Node *prev; 


    if (node != NULL)
    {
        if (*dlist == NULL) {
        *dlist = node;

        } else {
            actual = *dlist; 
            while (actual->next != NULL) 
            {;
                prev = actual;
                actual = actual->next;
                actual->previous = prev;

            }

            actual->next = node;
            node->previous = actual;

            
        }
    }

}


void dlist_imprimir(Node **list)
{
    node_print_all_linked_nodes(*list);
}
