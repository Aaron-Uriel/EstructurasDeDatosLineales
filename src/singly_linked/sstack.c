#include <stdio.h>
#include <stdlib.h>
#include <libdstruct.h>

 void add_node (SNode *pila, SNode node)
 {  
    int id;
    system("clear");
    printf("\t_______________________________\n");
     printf("\t Ingrese el ID del nodo: ");
    scanf("%d", &id);

    node = snode_new(id);
    if (nodo != NULL)
    {
        snode_append(*pila, node);
    }
    
 }