#include <stdint.h>
#include <stdio.h>
#include <assert.h>

#include <libdstruct.h>

int
main(void) 
{
    Node *dqueue = NULL, *node = NULL;
    int32_t i;
    for (i = 0; i < 10; i++) {
        dqueue_enqueue(&dqueue, node_new(i));
    }
    node = dqueue_dequeue(&dqueue);
    assert(node->value == 0);
    dqueue_print(dqueue);

    /* No podemos insertar el mismo nodo dos veces. */
    dqueue_enqueue(&dqueue, node);
    dqueue_enqueue(&dqueue, node_new(0));
    dqueue_print(dqueue);
    return 0;
}
