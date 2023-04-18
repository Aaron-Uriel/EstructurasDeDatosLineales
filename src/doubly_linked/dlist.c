#include <stdlib.h>
#include <stdio.h>

#include <libdstruct.h>

dlist_insert_node(Node **dlist, Node *node, int id){
    dnode = snode_new(id); 
    Node *actual;
    //Node *actualTemp

    if (dnode != NULL)
    {
        if (*dlist == NULL) {
        *dlist = dnode;
        } else {
            actual = *dlist; 
            while (actual->next != NULL) 
            {
                actual = actual->next; 
            }

            dnode->previous = actual;
            actual->next = dnode;
            
        }
    }

}