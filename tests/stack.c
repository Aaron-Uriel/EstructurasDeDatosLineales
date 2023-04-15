#include <stdlib.h>
#include <stdio.h>

#include <libdstruct.h>
/* 
 * Aquí probamos las funciones de la pila y vemos que todo va bien xd.
 * Si algo sale más return 1;, y si todo ta' bien return 0;
 */

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
