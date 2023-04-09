#include <stdlib.h>

#include <libdstruct.h>

struct Node {
    int32_t value;
    Node    *_previous;
    Node    *_next;
};

Node *
node_new(int32_t value)
{
	Node *const new_node = malloc(sizeof(Node));
	if (new_node != NULL) {
		new_node->value     = value;
		new_node->_next     = NULL;
        new_node->_previous = NULL;
	}

	return new_node;
}

void
node_delete(Node *const self)
{
	free(self);
}

Node *
node_get_next(Node *const self)
{
	return self->_next;
}

Node
*node_get_previous(Node *const self)
{
    return self->_previous;
}

void 
node_append(Node *const self, Node *const adjacent_node)
{
	self->_next = adjacent_node;
}

void
node_prepend(Node *const self, Node *const adjacent_node)
{
    self->_previous = adjacent_node;
}
