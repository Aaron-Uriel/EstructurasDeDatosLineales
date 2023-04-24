#include <stdlib.h>
#include <stdio.h>
#include <libdstruct.h>








int
main(void)
{
    SNode *listita = NULL, *copia = NULL;
    int numerito, busquita;
    printf("Escribe el númerito: ");
    scanf("%d", &numerito);
    sstack_insert_node(&listita, snode_new(numerito));
    printf("Escribe el númerito: ");
    scanf("%d", &numerito);
    sstack_insert_node(&listita, snode_new(numerito));
    printf("Escribe el númerito: ");
    scanf("%d", &numerito);
    sstack_insert_node(&listita, snode_new(numerito));
    printf("Escribe el númerito: ");
    scanf("%d", &numerito);
    sstack_insert_node(&listita, snode_new(numerito));
    printf("Escribe el númerito: ");
    scanf("%d", &numerito);
    sstack_insert_node(&listita, snode_new(numerito));
    sstack_imprimir(&listita);
    printf("Escribe el numerito a copiaarrrrr: ");
    scanf("%d", &numerito);
    copia = snode_jump_to_n(listita, numerito);
    sstack_insert_node(&listita, snode_clone(copia));
    sstack_imprimir(&listita);
    /* busquita = slist_search_snode(&listita,snode_new(numerito));
    if (busquita == -1)
    {
        printf("Está vacío :(, se regresa %d \n", busquita);
    } else if (busquita == -2)
    {
        printf("No se encotró :(, se regresa %d\n", busquita);
    } else if (busquita >= 0)
    {
        printf("Sí está, yeiiiii :D, se regresa %d \n", busquita);
    }
    */


    return 0;
}
