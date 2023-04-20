#include <stdlib.h>
#include <stdio.h>

#include <libdstruct.h>

void dolist_insert_node(Node **dlist, Node *node, int id)
{
    int listo = 0, cont = 0;
    node = node_new(id); 
    Node *actual = *dlist;
    Node *prev, *temporal = node; 

    if (node != NULL)
    {
        if (*dlist == NULL) {
        *dlist = node;

        } else {
            actual = *dlist; 
            while (actual->next != NULL && listo == 0) 
            {
                if (node->value > actual->value)
                {
                    cont ++;
                    prev = actual;
                    actual = actual->next;
                    actual->previous = prev;

                    if (actual->next == NULL && node->value <= actual->value)
                    {
                        temporal = actual;
                        node->previous = prev;
                        actual->previous = node;
                        node->next = temporal;
                        prev->next = node;
                        listo = 1;
                    }
                    
                } else if (node->value <= actual->value)
                {
                    
                    if (cont == 0)
                    {
                        temporal = actual;
                        node->previous = NULL;
                        actual->previous = node;
                        node->next = temporal;
                        *dlist = node;

                    } else {
                        temporal = actual;
                        node->previous = prev;
                        actual->previous = node;
                        node->next = temporal;
                        prev->next = node;
                    }
                
                    listo = 1;

                }
                
            }

            if (listo < 1)
            {
            actual->next = node;
            node->previous = actual;
            node->next = NULL;
            }
 
        }
        
    }

}


void dlist_imprimir(Node **list)
{
    node_print_all_linked_nodes(*list);
}
