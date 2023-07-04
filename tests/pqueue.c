/*#include <stdio.h>
#include <assert.h>

#include <libdstruct.h>

int main(void) {
    PQueue *my_pqueue = pqueue_new();
    Node *test_node = node_new(55);
    pqueue_enqueue(my_pqueue, pnode_new_from_node(test_node, 10));
    pqueue_enqueue(my_pqueue, pnode_new(99, 0));
    pqueue_enqueue(my_pqueue, pnode_new(-10, 5));
    pqueue_enqueue(my_pqueue, pnode_new(10, 5));
    pqueue_enqueue(my_pqueue, pnode_new(90, 5));
    pqueue_print(my_pqueue);

    PNode *test_pnode = pqueue_dequeue(my_pqueue);
    assert(test_pnode->value == 99);
    pqueue_print(my_pqueue);

    pqueue_dequeue(my_pqueue);
    pqueue_print(my_pqueue);

    pqueue_enqueue(my_pqueue, pnode_new(90, 10));
    pqueue_print(my_pqueue);
    pqueue_enqueue(my_pqueue, pnode_new(0, 11));
    pqueue_print(my_pqueue);
    return 0;
}
*/