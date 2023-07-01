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
 * Se encarga de hacer una copia exacta del nodo original.
 */
Node *
node_clone(Node *self)
{
    if (self == NULL) {
        return NULL;
    }

    /* Reservamos el espacio en memoria que ocupará el nodo clonado */
    Node *cloned_node = malloc(sizeof(*cloned_node));
    if (cloned_node == NULL) {
        return NULL;
    }
    memcpy(cloned_node, self, sizeof(*cloned_node));

    return cloned_node;
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
 * Desprende al nodo de los nodos relacionados con el y viceversa.
 * Si existen dos nodos conectados a este, estos se van a relacionar entre si,
 * ya sin involucrar al nodo pasado a esta función.
 */
void
node_unlink(Node *const self) {
    if (self == NULL) {
    }

    Node *const previous_node = self->previous;
    Node *const next_node = self->next;
    if (previous_node != NULL && next_node != NULL) {
        node_append(previous_node, next_node);
        self->previous = NULL;
        self->next = NULL;
    }
    else if (previous_node != NULL) {
        previous_node->next = NULL;
        self->previous = NULL;
    }
    else if (next_node != NULL) {
        next_node->previous = NULL;
        self->next = NULL;
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
    if (self == NULL) {
        return NULL;
    }

    Node *current_node = self;
    while(current_node->previous != NULL) {
         current_node = current_node->previous;
    }
    return current_node;
}

/*
 * Te devuelve un apuntador al n-ésimo nodo hacia adelante, respecto al nodo ingresado.
 * Si el valor n está más allá de la cadena de nodos se devuelve NULL.
 */
Node
*node_jump_to_n(Node *const self, const uint32_t n)
{
    if (self == NULL) {
        return NULL;
    }

    Node *node = self;
    uint32_t i;
    for (i = 0; i < n; i++) {
        if (node->next == NULL) {
            return NULL;
        }
        node = node->next;
    }

    return node; 
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

/*
 * La función imprime una representación textual del nodo, útil para depuración.
 */
void
node_print_debug(const Node *const self)
{
    if (self == NULL) {
        return;
    }

    fprintf(stderr,
            "\t(Node) { .value = %d; .next = %p; .previous = %p };\n",
            self->value,
            (void *)self->next,
            (void *)self->previous);
}
