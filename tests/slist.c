#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <assert.h>

#include <libdstruct.h>

int
main(void)
{
//    Inicialización de variables. 
    SNode *slist = NULL, *tmp_node;
    for(int i = 0; i < 6; i++) {
        tmp_node = snode_new(i * 10);
        slist_insert_snode(&slist, tmp_node);
    }
    
  //   0 -> 10 -> 20 -> 30 -> 40 -> 50 
    slist_print(slist);

    // 0 -> 10 -> 15 -> 20 -> 30 -> 40 -> 50 
    slist_insert_snode(&slist, snode_new(15));
    slist_print(slist);

     //1 -> 10 -> 15 -> 20 -> 30 -> 35
    slist_insert_snode(&slist, snode_new(1));
    slist_extract_node(&slist, 0);
    slist_print(slist);

    assert(slist_extract_node(&slist, 3)->value == 20);
    return 0;
}
