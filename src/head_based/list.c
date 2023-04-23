#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <libdstruct.h>
#include <report.h>

/* 
 * Crea una nueva lista con cabecera.
 * La lista no contiene ningún nodo al crearse, se crea completamente vacía.
 */
List *
list_new(void) {
    /* Inicializa con ceros el espacio de memoria que utilizará la lista. */
    List *new_list = calloc(1, sizeof(*new_list));
    return new_list;
}

int32_t
list_search_node(List *const list, Node *const node) {
    if (node == NULL) {
        report(__func__, ERROR, NULL_NODE);
        return -1;
    }
    if (list == NULL) {
        report(__func__, ERROR, NULL_HEAD_DATA_STRUCT);
        return -1;
    }

    Node *current_node;
    int32_t i;
    for (current_node = list->first, i = 0;
         current_node->next != NULL;
         current_node = current_node->next, i++) {
        bool deep_cmp = memcmp((void *)current_node, 
                               (void *)node,
                               sizeof(*current_node));
        if (deep_cmp == 0) {
            return i;
        }
    }
    
    return -2;
}
/*
 * Inserta un nodo en la lista con cabecera.
 * El nodo se inserta de forma ordenada, por lo que los nodos quedan
 * organizados de forma ascendente.
 */
void
list_insert_node(List *const list, Node *const node)
{
    if (node == NULL) {
        report(__func__, ERROR, NULL_NODE);
        return;
    }
    if (list == NULL) {
        report(__func__, ERROR, NULL_HEAD_DATA_STRUCT);
        return;
    }

    /* Cuando la lista está vacía. */
    if (list->size == 0) {
        report(__func__, INFO, EMPTY_DATA_STRUCT);
        list->first = node;
        list->last = node;
        list->size = 1;
        return;
    }

    /* 
     * Cuando el nodo a insertar ya es menor que el menor 
     * (el primero).
     */
    if (node->value < list->first->value) {
        node_prepend(list->first, node);
        list->first = node;
        list->size += 1;
        return;
    }

    /*
     * Cuando el nodo es mayor que el mayor (el último).
     */
    if (node->value > list->last->value) {
        node_append(list->last, node);
        list->last = node;
        list->size += 1;
        return;
    }

    /*
     * Cuando no se cumple ningún caso espacial, buscamos el lugar
     * donde insertar el nodo dentro de la lista.
     */
    int32_t i;
    Node *current_node;
    for (current_node = list->first, i = 0;
         current_node != NULL && i < list->size;
         current_node = current_node->next, i += 1) {
        printf("Entró\n");
        /* 
         * Cuando encontramos el lugar donde insertar el nodo dentro 
         * de la lista.
         */
        if (node->value < current_node->value) {
            node_prepend(current_node, node);
            list->size += 1;

            return;
        }
    }

    /* Nunca se debería llegar hasta aquí. */
    report(__func__, ERROR, OUT_OF_BOUNDS);
}

/*
 * Extrae el n-ésimo nodo de la lista, si no se encuentra se devuelve NULL.
 * El rango de valores para n siempre es desde 0 hasta *tamaño de lista* - 1.
 */
Node *
list_extract_node(List *const list, const uint32_t n)
{
    if (list == NULL) {
        report(__func__, ERROR, NULL_HEAD_DATA_STRUCT);
        return NULL;
    }

    /* 
     * Cuando el n-ésimo nodo que se quiere extraer no existe; n está más allá
     * de los nodos de la lista. 
     */
    if (n > list->size - 1) {
        report(__func__, ERROR, OUT_OF_BOUNDS);
        return NULL;
    }

    /* Buscamos el nodo a extraer y  lo extraemos. */
    Node *extracted_node;
    if (n == 0) {
        extracted_node = list->first;
        list->first = list->first->next;
        list->first->previous = NULL;
    }
    else if (n == list->size - 1) {
        extracted_node = list->last;
        list->last = list->last->previous;
        list->last->next = NULL;
    }
    else {
        extracted_node = node_jump_to_n(list->first, n);
        node_unlink(extracted_node);
    }
    
    list->size -= 1;
    return extracted_node;
}

/*
 * Imprime todos los nodos que conforman a la lista con cabecera.
 */
void
list_print(List *const list)
{
    if (list == NULL) {
        report(__func__, ERROR, NULL_HEAD_DATA_STRUCT);
        return;
    }

    printf("Tamaño: %d.\n", list->size);
    Node *current_node;
    int32_t i;
    for (current_node = list->first, i = 0;
         current_node != NULL && i < list->size;
         current_node = current_node->next, i += 1) {
        printf("%d -> ", current_node->value);
    }
    printf("NULL\n");
}

