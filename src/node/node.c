#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>

#include <libdstruct.h>
#include <string.h>

/*
 * Devuelve un apuntador que contiene la dirección de un nodo recién creado,
 * con el valor ingresado.
 */
Node *
node_new(int32_t value)
{
	Node *const new_node = malloc(sizeof(Node));

    new_node->value     = value;
    new_node->next      = NULL;
    new_node->previous  = NULL;

	return new_node;
}

/*
 * Libera el espacio en memoria ocupado por el nodo, adicionalmente como medida 
 * de seguridad, hace que el apuntador a nodo que recibe apunte a NULL después 
 * de ser liberado.
 */
void
node_delete(Node **self)
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
node_free_group(Node **self)
{
    /* Esta función puede eliminar mejor los nodos. */
    if (self && *self) {
        Node *nodo_actual, *nodo_anterior;
        nodo_actual = node_jump_to_first(*self);
        while (nodo_actual->next) {
            nodo_anterior = nodo_actual;
            nodo_actual = nodo_actual->next;
            node_delete(&nodo_anterior);
        }
        node_delete(&nodo_actual);
        *self = NULL;
    }
}

/*
 * Se encarga de hacer una copia del nodo original, sin preservar las
 * conexiones del nodo original.
 */
Node *
node_clone(Node *nodo)
{
    Node *nodo_clonado = NULL;
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
node_append(Node *const nodo, Node *const nodo_a_insertar)
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
 * Inserta un nodo atrás respecto a otro.
 * Se toma en cuenta al nodo anterior al nodo que se le antepondrá 
 * otro nodo, en dicho caso se inserta entre ellos dos.
 */
void
node_prepend(Node *const nodo, Node *const nodo_a_insertar)
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

/*
 * Devuelve un apuntador al último nodo de todos los nodos enlazados.
 */
Node *
node_jump_to_last(Node *const self)
{
    Node *nodo_final = NULL;
    if (self) {
        Node *nodo_actual = self;
        while(nodo_actual->next) {
            nodo_actual = nodo_actual->next;
        }
        nodo_final = nodo_actual;
    }
    return nodo_final;
}

/*
 * Devuelve un apuntador al primer nodo de todos los nodos enlazados.
 */
Node
*node_jump_to_first(Node *const self)
{
    if (self) {
        Node *nodo_actual = self;
        while (nodo_actual->previous) {
            nodo_actual = nodo_actual->previous;
        }
        return nodo_actual;
    }
    return NULL;
}

/*
 * Imprime los valores de todos los nodos relacionados, de principio a fin.
 */
void
node_print_all_linked_nodes(Node *const self)
{
    if (self) {
        const Node *current_node = node_jump_to_first(self);
        while (current_node != NULL) {
            printf("%d -> ", current_node->value);
            current_node = current_node->next;
        }
        printf("NULL\n");
    }
}

