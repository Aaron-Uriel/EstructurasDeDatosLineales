#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>

#include <libdstruct.h>
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
 * Libera la memoria de este nodo y de todos los nodos asociados con el.
 * La idea es que esta función solo sea usada por las estructuras de datos
 * y no directamente a los nodos.
 */
void
pnode_free_group(PNode **self)
{
    /* Esta función puede eliminar mejor los nodos. */
    if (self && *self) {
        PNode *nodo_actual, *nodo_anterior;
        nodo_actual = pnode_jump_to_first(*self);
        while (nodo_actual->next) {
            nodo_anterior = nodo_actual;
            nodo_actual = nodo_actual->next;
            pnode_delete(&nodo_anterior);
        }
        pnode_delete(&nodo_actual);
        *self = NULL;
    }
}

/*
 * Devuelve un apuntador al primer nodo de todos los nodos enlazados.
 */
PNode *
pnode_jump_to_first(PNode *const nodo)
{
    if (nodo) {
        PNode *nodo_actual = nodo;
        while (nodo_actual->previous) {
            nodo_actual = nodo_actual->previous;
        }
        return nodo_actual;
    }
    return NULL;
}
/*
 * Se encarga de hacer una copia del nodo original, sin preservar las
 * conexiones del nodo original.
 */
PNode *
pnode_clone(PNode *nodo)
{
    PNode *nodo_clonado = NULL;
    if (nodo) {
        nodo_clonado = malloc(sizeof(*nodo_clonado));
        if (nodo_clonado) {
            memcpy(nodo_clonado, nodo, sizeof(*nodo_clonado));
            nodo_clonado->next = nodo_clonado->previous = NULL;
        }
    }
    return nodo_clonado;
}

/*
 * Inserta un nodo enfrende del otro.
 * Se toma en cuenta también al nodo que ya está puesto como siguiente
 * para que registre también al nuevo nodo.
 */
void 
pnode_append(PNode *nodo, PNode *nodo_a_insertar)
{
    if (nodo && nodo_a_insertar) {
        if (nodo->next) {
            nodo->next->previous = nodo_a_insertar;
            nodo_a_insertar->next = nodo->next;
        }
        nodo->next = nodo_a_insertar;
        nodo_a_insertar->previous = nodo;
    }
}

/*
 */
void
pnode_prepend(PNode *nodo, PNode *nodo_a_insertar)
{
    if (nodo && nodo_a_insertar) {
        if (nodo->previous) {
            nodo->previous->next = nodo_a_insertar;
            nodo_a_insertar->previous = nodo->previous;
        }
        nodo->previous = nodo_a_insertar;
        nodo_a_insertar->next = nodo;
    }
}

