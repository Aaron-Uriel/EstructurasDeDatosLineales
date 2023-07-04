#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include <libdstruct.h>

/*
 * Devuelve un apuntador que contiene la dirección de un nodo recién creado,
 * con el valor ingresado.
 */
SNode *
snode_new(int32_t value)
{
	SNode *const new_snode = malloc(sizeof(SNode));
    if (new_snode == NULL) {
        return NULL;
    }

    new_snode->value = value;
    new_snode->next = NULL;

	return new_snode;
}

/*
 * Libera el espacio en memoria ocupado por el nodo, adicionalmente como medida 
 * de seguridad, hace que el apuntador a nodo que recibe apunte a NULL después 
 * de ser liberado.
 */
void
snode_free(SNode **self)
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
snode_free_group(SNode **self)
{
    if (self && *self) {
        SNode *nodo_actual, *nodo_anterior;
        nodo_actual = *self;
        while (nodo_actual->next) {
            nodo_anterior = nodo_actual;
            nodo_actual = nodo_actual->next;
            snode_free(&nodo_anterior);
        }
        snode_free(&nodo_actual);
        *self = NULL;
    }
}

/*
 * Crea una copia de un nodo, sin preservar las conexiones del nodo original.
 */
SNode *
snode_clone(SNode *nodo)
{
    SNode *nodo_clonado = NULL;
    if (nodo) {
        nodo_clonado = malloc(sizeof(*nodo_clonado));
        if (nodo_clonado) {
            memcpy(nodo_clonado, nodo, sizeof(*nodo_clonado));
            nodo_clonado->next = NULL;
        }
    }
    return nodo_clonado;
}

/*
 * Devuelve un apuntador al último nodo de todos los nodos enlazados.
 */
SNode *
snode_jump_to_last(SNode *const self)
{
    if (self == NULL) {
        return NULL;
    }

    SNode *current_node = self;
    while(current_node->next != NULL) {
        current_node = current_node->next;
    }

    return current_node;
}

/*
 * Imprime los valores de todos los nodos relacionados, debido a que es una
 * relación de una sola dirección solo se desde el nodo pasado hasta el último,
 * el nodo recibido por la función no será necesariamente el primero en 
 * toda la relación.
 */
void
snode_print_all_linked_nodes(const SNode *const self)
{
    if (self == NULL) {
        return;
    }

    const SNode *current_node = self;
    while (current_node != NULL) {
        printf("%d -> ", current_node->value);
        current_node = current_node->next;
    }
    printf("NULL\n");
}

