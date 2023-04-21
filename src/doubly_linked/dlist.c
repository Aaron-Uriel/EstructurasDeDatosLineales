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

void dodelete_node(Node **dlist, int id) //Elimina por medio de id y sólo el primero.
{
    Node *actual = *dlist, *prev = NULL, *next = NULL;
    int deleted, cont = 0;
    if (actual != NULL)
    {
        while (actual->next != NULL)
        {
            if (actual->value == id)
            {
                break;
            } else
            {
                cont ++;
                actual = actual->next;
                
            }
        }
        if (actual->value != id)
        {
            printf("No se encontro el nodo\n");
        } else{
            deleted = actual->value;
            prev = actual->previous;
            next = actual->next;
            if (prev != NULL)
            {
                prev->next = next;
            }
            
            
            if (next != NULL)
            {
                next->previous = prev;
            }
            actual->previous = NULL;
            actual->next = NULL;
            free(actual);
            printf("Se eliminó: %d \n", deleted);
            if (cont == 0)
            {
                *dlist = next;
            }
            

        }
 
    }
}
