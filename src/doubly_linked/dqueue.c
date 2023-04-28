#include <stdlib.h>

#include <libdstruct.h>
#include <report.h>

/*
 * Coloca un nodo al final de la cola.
 */
void
dqueue_enqueue(Node **dqueue, Node *node)
{
    if (*dqueue == NULL) {
        report(__func__, INFO, EMPTY_DATA_STRUCT);
        *dqueue = node;
        return;
    }

    Node *const last_node_in_dqueue = node_jump_to_last(*dqueue);
    node_append(last_node_in_dqueue, node);
}

/*
 * Extrae el primer nodo de la Cola.
 */
Node *
dqueue_dequeue(Node **const dqueue)
{
    if (*dqueue == NULL) {
        report(__func__, ERROR, EMPTY_DATA_STRUCT);
        return NULL;
    }

    Node *const extracted_node = *dqueue;
    Node *const new_first_node = (*dqueue)->next;
    node_unlink(extracted_node);
    if (new_first_node == NULL) {
        report(__func__, INFO, DATA_STRUCT_WILL_BE_EMPTY);
    }
    *dqueue = new_first_node;

    return extracted_node; 
}

/*
 * Imprime todos los nodos relacionados en la cola.
 */
void
dqueue_print(Node *dqueue)
{
    if (dqueue == NULL) {
        report(__func__, ERROR, EMPTY_DATA_STRUCT);
        return;
    }
    node_print_all_linked_nodes(dqueue);
}

