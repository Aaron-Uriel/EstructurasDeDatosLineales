#include <stdlib.h>
#include <stdio.h>

#include <libdstruct.h>

int
main(void)
{
    Node *list = NULL, *node = NULL; 
    int id;
    printf("Ingrese el numero del nodo:");
    scanf("%d", &id);
    dlist_insert_node(&sstack, snode, id);
    printf("Ingrese el numero del nodo:");
    scanf("%d", &id);
    dlist_insert_node(&sstack, snode, id);
    printf("Ingrese el numero del nodo:");
    scanf("%d", &id);
    dlist_insert_node(&sstack, snode, id);

}