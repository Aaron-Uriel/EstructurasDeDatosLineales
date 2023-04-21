#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include <libdstruct.h>
#include <report.h>

/*
 * Devuelve un apuntador que contiene la dirección de un nodo recién creado,
 * con el valor ingresado.
 */
SNode *
snode_new(int32_t value)
{
	SNode *const new_snode = malloc(sizeof(SNode));
    if (new_snode == NULL) {
        report(__func__, ERROR, OUT_OF_MEMORY);
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
snode_delete(SNode **self)
{
	free(*self);
    *self = NULL; 
}

/*
 * Se encarga de hacer una copia exacta del nodo original.
 */
SNode *
snode_clone(SNode *self)
{
    if (self == NULL) {
        report(__func__, ERROR, NULL_NODE);
        return NULL;
    }

    /* Reservamos el espacio en memoria que ocupará el nodo clonado */
    SNode *cloned_node = malloc(sizeof(*cloned_node));
    if (cloned_node == NULL) {
        report(__func__, ERROR, OUT_OF_MEMORY);
        return NULL;
    }
    memcpy(cloned_node, self, sizeof(*cloned_node));

    return cloned_node;
}

/*
 * Crea una relación unidireccional entre los dos nodos:
 * - El primer nodo (self) ahora dirá que su siguiente nodo es
 *   el segundo nodo (snode).
 */
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
 * Devuelve un apuntador al último nodo de todos los nodos enlazados.
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

/*
 * Te devuelve un apuntador al n-ésimo nodo hacia adelante, respecto al nodo ingresado.
 * Si el valor n está más allá de la cadena de nodos se devuelve NULL.
 */
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
            "\t(SNode) { .value = %d; .next = %p };\n",
            self->value,
            (void *)self->next);
}
