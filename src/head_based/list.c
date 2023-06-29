#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <libdstruct.h>

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

/*
 * Busca el nodo dentro de la lista.
 * Se regresa un valor positivo indicando el índice del nodo, si se regresa
 * un valor menor que 0 quiere decir que ocurrió un error.
 * Para saber si el nodo que se busca en la lista se encontró, comparamos el
 * valor dentro de los nodos. No se realiza ninguna comparación profunda.
 */
int32_t
list_search_node(List *const list, Node *const node) {
    if (node == NULL) {
        return -1;
    }
    if (list == NULL) {
        return -1;
    }

    Node *current_node;
    int32_t i;
    for (current_node = list->first, i = 0;
         current_node != NULL;
         current_node = current_node->next, i++) {
        if (current_node->value == node->value) {
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
        return;
    }
    if (list == NULL) {
        return;
    }

    /* Cuando la lista está vacía. */
    if (list->size == 0) {
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
     * Cuando el nodo es mayor o igual que el mayor (el último).
     */
    if (node->value >= list->last->value) {
        node_append(list->last, node);
        list->last = node;
        list->size += 1;
        return;
    }

    /*
     * Cuando no se cumple ningún caso espacial, buscamos el lugar
     * donde insertar el nodo dentro de la lista.
     */
    uint32_t i;
    Node *current_node;
    for (current_node = list->first, i = 0;
         current_node != NULL && i < list->size;
         current_node = current_node->next, i += 1) {
        /* 
         * Cuando encontramos el lugar donde insertar el nodo dentro 
         * de la lista, colocamos el nodo antes del actual y después
         * del anterior.
         */
        if (node->value < current_node->value) {
            Node *prev_node = current_node->previous;
            node_append(prev_node, node);
            node_prepend(current_node, node);
            list->size += 1;

            return;
        }
    }

    /* Nunca se debería llegar hasta aquí. */
}

/*
 * Extrae el n-ésimo nodo de la lista, si no se encuentra se devuelve NULL.
 * El rango de valores para n siempre es desde 0 hasta *tamaño de lista* - 1.
 */
Node *
list_extract_node(List *const list, const uint32_t n)
{
    if (list == NULL) {
        return NULL;
    }

    /* 
     * Cuando el n-ésimo nodo que se quiere extraer no existe; n está más allá
     * de los nodos de la lista. 
     */
    if (n > list->size - 1) {
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
        return;
    }

    printf("Tamaño: %d.\n", list->size);
    Node *current_node;
    uint32_t i;
    for (current_node = list->first, i = 0;
         current_node != NULL && i < list->size;
         current_node = current_node->next, i += 1) {
        printf("%d -> ", current_node->value);
    }
    printf("NULL\n");
}

