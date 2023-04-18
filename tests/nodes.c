#include <stdio.h>
#include <assert.h>

#include <libdstruct.h>

int
main(void) {
    SNode *snode = snode_new(40), *snode2;
    Node *node = node_new(25), *node2;
    snode2 = snode_clone(snode);
    node2 = node_clone(node);
    node->value;
     Node *node3 = node_new (30);
     node->next = node3;
     node3->previous = node;
     printf ("%d\n", node->next->value);

    assert(snode != snode2 && node != node2);

    printf("SNodes: %p -> %d; %p -> %d\n"
           "Nodes: %p -> %d; %p -> %d\n",
           (void *)snode, snode->value, (void *)snode2, snode2->value,
           (void *)node, node->value, (void *)node2, node2->value);
    return 0;
}
