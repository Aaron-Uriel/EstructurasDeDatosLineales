#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>

#include <libdstruct.h>
#include <report.h>
#include <string.h>

/*
 * Devuelve un apuntador que contiene la dirección de un nodo con
 * prioridad recién creado, con el valor ingresado.
 */
PNode *
pnode_new(int32_t value, uint8_t priority)
{
	PNode *const new_pnode = malloc(sizeof(*new_pnode));
	if (new_pnode == NULL) {
        report(__func__, ERROR, OUT_OF_MEMORY);
    }

    new_pnode->value    = value;
    new_pnode->priority = priority;
    new_pnode->next     = NULL;
    new_pnode->previous = NULL;

	return new_pnode;
}

/*
 * Crea un nuevo nodo con prioridad con el valor de un nodo
 * doblemente enlazado.
 * Solo copia el valor del nodo original.
 */
PNode *
pnode_new_from_node(Node *node, uint8_t priority)
{
	PNode *const new_pnode = malloc(sizeof(*new_pnode));
	if (new_pnode == NULL) {
        report(__func__, ERROR, OUT_OF_MEMORY);
    }

    new_pnode->value    = node->value;
    new_pnode->priority = priority;
    new_pnode->next     = NULL;
    new_pnode->previous = NULL;

	return new_pnode;
}
/*
 * Libera el espacio en memoria ocupado por el nodo, adicionalmente como medida 
 * de seguridad, hace que el apuntador a nodo que recibe apunte a NULL después 
 * de ser liberado.
 */
void
pnode_delete(PNode **self)
{
	free(*self);
    *self = NULL;
}

/*
 * Se encarga de hacer una copia exacta del nodo original.
 */
PNode *
pnode_clone(PNode *self)
{
    if (self == NULL) {
        report(__func__, ERROR, NULL_NODE);
        return NULL;
    }

    /* 
     * Reservamos el espacio en memoria que ocupará el nodo
     * clonado.
     */
    PNode *cloned_pnode = malloc(sizeof(*cloned_pnode));
    if (cloned_pnode == NULL) {
        report(__func__, ERROR, OUT_OF_MEMORY);
        return NULL;
    }
    memcpy(cloned_pnode, self, sizeof(*cloned_pnode));

    return cloned_pnode;
}

/*
 * Crea una relación entre los dos nodos:
 * - El primer nodo (self) ahora dirá que su siguiente nodo 
 *   es el segundo nodo (node).
 * - El segundo nodo (node) ahora dirá que su nodo anterior
 *   es el primer nodo (self).
 */
void 
pnode_append(PNode *self, PNode *pnode)
{
    if (self == NULL || pnode == NULL) {
        report(__func__, ERROR, NULL_NODE);
        return;
    }

	self->next = pnode;
    pnode->previous = self;
}

/*
 * Crea una relación entre los dos nodos:
 * - El primer nodo (self) ahora dirá que su nodo anterior
 *   es el segundo nodo (node).
 * - El segundo nodo (node) ahora dirá que su siguiente nodo
 *   es el primer nodo (self).
 */
void
pnode_prepend(PNode *self, PNode *pnode)
{
    if (self == NULL || pnode == NULL) {
        report(__func__, ERROR, NULL_NODE);
        return;
    }

    self->previous = pnode;
    pnode->next = self;
}

/*
 * Desprende al nodo de los nodos relacionados con el y viceversa.
 * Si existen dos nodos conectados a este, estos se van a relacionar entre
 * si, ya sin involucrar al nodo pasado a esta función.
 */
void
pnode_unlink(PNode *const self) {
    if (self == NULL) {
        report(__func__, ERROR, NULL_NODE);
    }

    PNode *const previous_pnode = self->previous;
    PNode *const next_pnode = self->next;
    if (previous_pnode != NULL && next_pnode != NULL) {
        pnode_append(previous_pnode, next_pnode);
        self->previous = NULL;
        self->next = NULL;
    }
    else if (previous_pnode != NULL) {
        previous_pnode->next = NULL;
        self->previous = NULL;
    }
    else if (next_pnode != NULL) {
        next_pnode->previous = NULL;
        self->next = NULL;
    }
}
