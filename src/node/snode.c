#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include <libdstruct.h>
#include <report.h>

SNode *
snode_new(int32_t value)
{
	SNode *const new_snode = malloc(sizeof(SNode));
	if (new_snode != NULL) {
		new_snode->value = value;
		new_snode->next = NULL;
	}

	return new_snode;
}

void
snode_delete(SNode **self)
{
	free(*self);
    *self = NULL; 
}

void 
snode_append(SNode *const self, SNode *const snode)
{
    if (self == NULL || snode == NULL) {
        report(__func__, ERROR, NULL_NODE);
        return;
    }

	self->next = snode;
}

/*
 * Descripción de la función.
 * Esta función sirve para llegar al final de una serie de nodos enlazados.
 * Es útil cuando quieres insertar nodos al final por ejemplo.
 */
SNode
*snode_jump_to_last(SNode *const self)
{
    if (self == NULL) {
        report(__func__, ERROR, NULL_NODE);
        return NULL;
    }

    SNode *current_node = self;
    while(current_node->next != NULL) {
        current_node = current_node->next;
    }

    return current_node;
}

SNode
*snode_jump_to_n(SNode *const self, const uint32_t n)
{
    if (self == NULL) {
        report(__func__, ERROR, NULL_NODE);
        return NULL;
    }

    SNode *node = self;
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
snode_print_all_linked_nodes(const SNode *const self)
{
    if (self == NULL) {
        report(__func__, ERROR, NULL_NODE);
        return;
    }

    const SNode *current_node = self;
    while (current_node != NULL) {
        printf("%d -> ", current_node->value);
        current_node = current_node->next;
    }
    printf("NULL\n");
}

/*
 * La función imprime una representación textual del nodo, útil para depuración.
 */
void
snode_print_debug(const SNode *const self)
{
    if (self == NULL) {
        report(__func__, ERROR, NULL_NODE);
        return;
    }

    fprintf(stderr,
            "\t(SNode) { .value = %d; .next = %p };",
            self->value,
            (void *)self->next);
}
