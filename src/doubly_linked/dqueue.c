#include <stdlib.h>

#include <libdstruct.h>

/*
 * Coloca un nodo al final de la cola.
 */
void
dqueue_enqueue(Node **dqueue, Node *node)
{
    if (*dqueue == NULL) {
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
        return NULL;
    }

    Node *const extracted_node = *dqueue;
    Node *const new_first_node = (*dqueue)->next;
    node_unlink(extracted_node);
    if (new_first_node == NULL) {
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
        return;
    }
    node_print_all_linked_nodes(dqueue);
}

