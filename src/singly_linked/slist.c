#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include <libdstruct.h>

/*
 * Inserta un nodo de forma ordenada en la lista. Los nodos se acomodan de
 * forma ascendente.
 */
void
slist_insert_snode(SNode **slist, SNode *snode)
{
    if (snode == NULL ) {
        return;
    }
    /* Cuando la lista está vacía, ponemos el nodo como el primer elemento de la lista. */
    if (*slist == NULL) {
        *slist = snode;
        return;
    }

    /*
     * Cuando el elemento que vamos a ingresar ya es menor que el menor
     * (el primer elemento), nos ahorramos toda la lógica que está en el
     * resto del programa.
     */
    if (snode->value < (*slist)->value) {
        snode_append(snode, *slist);
        *slist = snode;
        return;
    }

    /* 
     * Nos movemos con dos apuntadores, uno considerado el actual y el otro
     * considerado como el anterior al actual.
     */
    SNode *prev_snode = *slist, *current_snode = prev_snode->next;
    /* Caso: la lista es de solo un elemento. */
    if (current_snode == NULL) {
        bool snode_is_lesser = snode->value < (*slist)->value;
        if (snode_is_lesser) {
            snode->next = *slist;
            *slist = snode;
        } else {
            (*slist)->next = snode;
        }

        return;
    }

    while (current_snode != NULL) {
        /* 
         * Caso: encontramos un nodo que tiene un valor mayor al que queremos
         * insertar; se insertará al interior de la Lista.
         */
        if (current_snode->value > snode->value) {
            snode_append(prev_snode, snode);
            snode_append(snode, current_snode);
            //prev_snode->next = snode;
            //snode->next = current_snode;
            return;
        }
        prev_snode = current_snode;
        current_snode = current_snode->next;
    }
    /* 
     * Se sale del while solo si llegamos al final sin encontrar un nodo de mayor
     * valor, por lo que este se va a poner al final.
     */
    prev_snode->next = snode;
}

/*
 * Busca si existe el nodo recibido dentro de la lista, si este existe se regresa
 * el índice de ese nodo.
 * La función regresa -1 cuando ocurre algún error relacionado a las variables
 * pasadas a la funciín, se regresa -2 si no se encontró el nodo en la lista.
 * Para saber si el nodo es el mismo, se compara únicamente el valor dentro de
 * los nodos, no se hace ninguna comparación profunda.
 */
int32_t
slist_search_snode(SNode **const slist, SNode *const snode) {
    if (snode == NULL) {
        return -1;
    }
    if (*slist == NULL) {
        return -1;
    }

    SNode *current_snode;
    int32_t i;
    for (current_snode = *slist, i = 0;
         current_snode != NULL;
         current_snode = current_snode->next, i++) {
        if (current_snode->value == snode->value) {
            return i;
        }
    }
    
    return -2;
}

/**
 * Extrae un nodo de una posición arbitraria dentro de los confines de la lista.
 * En caso de intentar extraer un nodo fuera de los límites, la función
 * regresa NULL.
 */
SNode *
slist_extract_node(SNode **const slist, const uint32_t index)
{
    if (*slist == NULL) {
        return NULL;
    }

    SNode *extracted_node;
    /* Caso: se quiere extraer el primer nodo. */
    if (index == 0) {
        extracted_node = *slist;
        *slist = (*slist)->next;
        return extracted_node;
    }
    
    SNode *const node_before_index = snode_jump_to_n(*slist, index - 1);
    if (node_before_index == NULL) {
        return NULL;
    }

    SNode *const node_at_index = node_before_index->next;
    if (node_at_index == NULL) {
        return NULL;
    }

    /* Extraemos. */
    node_before_index->next = node_at_index->next;
    extracted_node = node_at_index;
    return extracted_node;
}

/*
 * Imprime la lista.
 */
void
slist_print(SNode *slist)
{
    if (slist == NULL) {
        return;
    }
    snode_print_all_linked_nodes(slist);
}

