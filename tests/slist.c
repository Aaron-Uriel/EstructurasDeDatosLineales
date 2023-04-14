#include <stdio.h>
#include <stdlib.h>

#include <libdstruct.h>

int
main(void)
{
    /* Inicialización de variables. */
    SNode *slist = NULL;
    for(int i = 0; i < 6; i++) {
        slist_push_back(&slist, snode_new(i * 10));
    }
    printf("Nodos insertados: ");

    /* 0 -> 10 -> 20 -> 30 -> 40 -> 50 */
    slist_print(slist);

    /* 0 -> 10 -> 15 -> 20 -> 30 -> 40 -> 50 */
    slist_insert_snode(&slist, snode_new(15), 2);
    slist_print(slist);

    /* 1 -> 10 -> 15 -> 20 -> 30 -> 35*/
    slist_pop_back(&slist);
    slist_pop_back(&slist);
    slist_insert_snode(&slist, snode_new(1), 0);
    slist_push_back(&slist, snode_new(35));
    slist_print(slist);

    return 0;
}
