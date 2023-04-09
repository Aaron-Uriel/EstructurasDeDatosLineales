#include <stdlib.h>

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
node_delete(Node *const self)
{
	free(self);
}

Node *
node_getnext(Node *const self)
{
	return self->next;
}

Node
*node_get_previous(Node *const self)
{
    return self->previous;
}

void 
node_append(Node *const self, Node *const adjacent_node)
{
	self->next = adjacent_node;
}

void
node_prepend(Node *const self, Node *const adjacent_node)
{
    self->previous = adjacent_node;
}

Node
*node_go_to_last(Node *const self)
{
    /* El bucle for más ilegible que verás en tu vida XD */
    Node *current_node;
    for (current_node = self; 
         current_node->next != NULL;
         current_node = current_node->next);

    return current_node;
}

Node
*node_go_to_first(Node *const self)
{
    /* El bucle for más ilegible que verás en tu vida XD */
    Node *current_node;
    for (current_node = self; 
         current_node->previous != NULL;
         current_node = current_node->previous);

    return current_node;
}
