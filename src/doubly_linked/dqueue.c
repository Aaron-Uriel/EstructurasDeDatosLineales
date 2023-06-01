#include <stdlib.h>
#include <libdstruct.h>
#include <report.h>

Node *dqueue_dequeue(Node **const dqueue){

}

void dqueue_enqueue(Node **dqueue, Node *node){

}

void
dqueue_print(Node *dqueue)
{
    if (dqueue == NULL) {
        report(__func__, ERROR, NULL_DATA_STRUCT);
        return;
    }
    Node_print_all_linked_nodes(dqueue);
}