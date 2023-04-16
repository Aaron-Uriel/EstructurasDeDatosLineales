#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <assert.h>

#include <libdstruct.h>

int
main(void)
{
    /* Inicialización de variables. */
    SNode *slist = NULL;
    for(int i = 0; i < 6; i++) {
        slist_push_back(&slist, snode_new(i * 10));
    }
    
    SNode *test_node = snode_new(55);
    const int32_t test_index = 3;
    slist_insert_snode(&slist, test_node, test_index);

    int32_t index = slist_search_snode(&slist, test_node);

    assert(test_index == index);

    printf("%d %d\n", test_index, index);

    
//    /* 0 -> 10 -> 20 -> 30 -> 40 -> 50 */
//    slist_print(slist);
//
//    /* 0 -> 10 -> 15 -> 20 -> 30 -> 40 -> 50 */
//    slist_insert_snode(&slist, snode_new(15), 2);
//    slist_print(slist);
//
//    /* 1 -> 10 -> 15 -> 20 -> 30 -> 35*/
//    slist_pop_back(&slist);
//    slist_pop_back(&slist);
//    slist_insert_snode(&slist, snode_new(1), 0);
//    slist_push_back(&slist, snode_new(35));
//    slist_print(slist);

    return 0;
}
