#include <stdlib.h>
#include <stdio.h>

#include <libdstruct.h>

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

Node *
node_getnext(Node *const self)
{
    if (self == NULL) { return NULL; }

	return self->next;
}

Node
*node_get_previous(Node *const self)
{
    if (self == NULL) { return NULL; }

    return self->previous;
}

void 
node_append(Node *const self, Node *const adjacent_node)
{
    if (self == NULL) { return; }

	self->next = adjacent_node;
}

void
node_prepend(Node *const self, Node *const adjacent_node)
{
    if (self == NULL) { return; }

    self->previous = adjacent_node;
}

Node
*node_jump_to_last(Node *const self)
{
    if (self == NULL) { return NULL; }

    Node *current_node = self;
    while(current_node->next != NULL) {
         current_node = current_node->next;
    }

    return current_node;
}

Node
*node_jump_to_first(Node *const self)
{
    if (self == NULL) { return NULL; }

    Node *current_node = self;
    while(current_node->previous != NULL) {
         current_node = current_node->previous;
    }
    return current_node;
}

Node
*node_jump_to_n(Node *const self, const uint32_t n)
{
    if (self == NULL) { return NULL; }

    Node *node = self;
    uint32_t i;
    for (i = 0; i < n; i++) {
        if (node->next == NULL) { return NULL; }
        node = node->next;
    }

    return node;     
}

void
node_print_all_linked_nodes(const Node *const self)
{
    const Node *current_node = self;
    while (current_node->next != NULL) {
        printf("%d ", current_node->value);
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
        fprintf(stderr, "\tNode con valor NULL");
    } else {
        fprintf(stderr,
                "\t(Node) { .value = %d; .next = %p; .previous = %p };",
                self->value,
                (void *)self->next,
                (void *)self->previous);
    }
}
