#include <stdlib.h>

#include <libdstruct.h>

SNode *
snode_new(int32_t value)
{
	SNode *const new_snode = malloc(sizeof(SNode));
	if (new_snode != NULL) {
		new_snode->value     = value;
		new_snode->_next     = NULL;
	}

	return new_snode;
}

void
snode_delete(SNode *const self)
{
	free(self);
}

SNode *
snode_get_next(SNode *const self)
{
	return self->_next;
}

void 
snode_append(SNode *const self, SNode *const adjacent_snode)
{
	self->_next = adjacent_snode;
}

