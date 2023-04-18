#include <stdlib.h>
#include <stdio.h>

#include <libdstruct.h>
/* 
 * Aquí probamos las funciones de la pila y vemos que todo va bien xd.
 * Si algo sale más return 1;, y si todo ta' bien return 0;
 */

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



int
main(void)
{
     Node *list = NULL, *node = NULL; 
    int id;
    printf("Ingrese el numero del nodo: ");
    scanf("%d", &id);
    dlist_insert_node(&list, node, id);
    dlist_imprimir(&list);

    printf("Ingrese el numero del nodo: ");
    scanf("%d", &id);
    dlist_insert_node(&list, node, id);
    dlist_imprimir(&list);

    printf("Ingrese el numero del nodo: ");
    scanf("%d", &id);
    dlist_insert_node(&list, node, id);
    dlist_imprimir(&list);


    return 0;
}
