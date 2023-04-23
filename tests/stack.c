#include <stdlib.h>
#include <stdio.h>
#include <libdstruct.h>








int
main(void)
{
    Node *listita = NULL;
    int numerito, busquita;
    printf("Escribe el númerito: ");
    scanf("%d", &numerito);
    dolist_insert_node(&listita, node_new(numerito));
    printf("Escribe el númerito: ");
    scanf("%d", &numerito);
    dolist_insert_node(&listita, node_new(numerito));
    printf("Escribe el númerito: ");
    scanf("%d", &numerito);
    dolist_insert_node(&listita, node_new(numerito));
    printf("Escribe el númerito: ");
    scanf("%d", &numerito);
    dolist_insert_node(&listita, node_new(numerito));
    printf("Escribe el númerito: ");
    scanf("%d", &numerito);
    dolist_insert_node(&listita, node_new(numerito));
    dlist_imprimir(&listita);
    printf("Escribe el numerito a buscarrrrr: ");
    scanf("%d", &numerito);
    busquita = dlist_search_node(&listita, node_new(numerito));
    if (busquita < 0)
    {
        printf("Está vacío :(\n");
    } else if (busquita == 0)
    {
        printf("No se encotró :(\n");
    } else if (busquita >= 1)
    {
        printf("Sí está, yeiiiii :D\n");
    }
    
    
    

    return 0;
}
