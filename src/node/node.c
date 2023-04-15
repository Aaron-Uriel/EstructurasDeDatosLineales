#include <stdlib.h>
#include <stdio.h>

#include <libdstruct.h>
#include <report.h>

Node *
node_new(int32_t value)
{
	Node *const new_node = malloc(sizeof(Node));
	if (new_node != NULL) {
		new_node->value     = value;
		new_node->next     = NULL;
        new_node->previous = NULL;
	}

	return new_node;
}

void
node_delete(Node **self)
{
	free(*self);
    *self = NULL;
}

void 
node_append(Node *const self, Node *const adjacent_node)
{
    if (self == NULL) {
        report(__func__, ERROR, NULL_NODE);
        return;
    }

	self->next = adjacent_node;
}

void
node_prepend(Node *const self, Node *const adjacent_node)
{
    if (self == NULL) {
        report(__func__, ERROR, NULL_NODE);
        return;
    }

    self->previous = adjacent_node;
}

Node
*node_jump_to_last(Node *const self)
{
    if (self == NULL) {
        report(__func__, ERROR, NULL_NODE);
        return NULL;
    }

    Node *current_node = self;
    while(current_node->next != NULL) {
         current_node = current_node->next;
    }

    return current_node;
}

Node
*node_jump_to_first(Node *const self)
{
    if (self == NULL) {
        report(__func__, ERROR, NULL_NODE);
        return NULL;
    }

    Node *current_node = self;
    while(current_node->previous != NULL) {
         current_node = current_node->previous;
    }
    return current_node;
}

Node
*node_jump_to_n(Node *const self, const uint32_t n)
{
    if (self == NULL) {
        report(__func__, ERROR, NULL_NODE);
        return NULL;
    }

    Node *node = self;
    uint32_t i;
    for (i = 0; i < n; i++) {
        if (node->next == NULL) {
            report(__func__, ERROR, OUT_OF_BOUNDS);
            return NULL;
        }
        node = node->next;
    }

    return node; 
}

void
node_print_all_linked_nodes(Node *const self)
{
    if (self == NULL) {
        report(__func__, ERROR, NULL_NODE);
        return;
    }
    const Node *current_node = node_jump_to_first(self);
    while (current_node != NULL) {
        printf("%d ", current_node->value);
        current_node = current_node->next;
    }
    printf("NULL\n");
}

/*
 * La función imprime una representación textual del nodo, útil para depuración.
 */
void
node_print_debug(const Node *const self)
{
    if (self == NULL) {
        report(__func__, ERROR, NULL_NODE);
        return;
    }

    fprintf(stderr,
            "\t(Node) { .value = %d; .next = %p; .previous = %p };",
            self->value,
            (void *)self->next,
            (void *)self->previous);
}
