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
