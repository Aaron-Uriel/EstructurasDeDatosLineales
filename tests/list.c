#include <stdint.h>
#include <stdio.h>
#include <assert.h>

#include <libdstruct.h>

int main(void) {
    List *mylist = list_new();

    /*
     * Los ingresamos de forma descendente, deben de guardarse
     * ascendentemente por que list los organiza.
     */
    int32_t i;
    for (i = 9; i >= 0; i -= 1) {
        list_insert_node(mylist, node_new(i));
    }
    list_print(mylist);
    assert(mylist->size == 10);

    Node *extracted_node = list_extract_node(mylist, 3);
    assert(extracted_node->value == 3);
    list_print(mylist);

    extracted_node = list_extract_node(mylist, 0);
    assert(extracted_node->value == 0);
    list_print(mylist);

    list_insert_node(mylist, node_new(-15));
    assert(mylist->first->value == -15);
    list_print(mylist);

    list_insert_node(mylist, node_new(5));
    list_insert_node(mylist, node_new(5));
    list_print(mylist);

    return 0;
}
