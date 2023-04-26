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
    slist_insert_snode(&listita, snode_new(numerito));
    printf("Escribe el númerito: ");
    scanf("%d", &numerito);
    slist_insert_snode(&listita, snode_new(numerito));
    printf("Escribe el númerito: ");
    scanf("%d", &numerito);
    slist_insert_snode(&listita, snode_new(numerito));
    printf("Escribe el númerito: ");
    scanf("%d", &numerito);
    slist_insert_snode(&listita, snode_new(numerito));
    printf("Escribe el númerito: ");
    scanf("%d", &numerito);
    slist_insert_snode(&listita, snode_new(numerito));
    slist_print(listita);
    printf("Escribe el numerito a copiaarrrrr: ");
    scanf("%d", &numerito);
    copia = snode_clone(snode_jump_to_n(listita, numerito));
    slist_insert_snode(&listita, snode_new(copia->value));
    slist_print(listita);

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
