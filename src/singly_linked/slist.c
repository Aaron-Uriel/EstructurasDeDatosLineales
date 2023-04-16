#include <stdlib.h>
#include <stdio.h>

#include <libdstruct.h>
#include <report.h>

/*
 * Añade un nodo al final de la lista.
 */
void
slist_push_back(SNode **slist, SNode *snode)
{
    if (snode == NULL) {
        report(__func__, ERROR, NULL_NODE);
        return;
    }
    if (*slist == NULL) {
        report(__func__, INFO, NULL_DATA_STRUCT);
        *slist = snode;
        return;
    }

    SNode *const last_snode = snode_jump_to_last(*slist);
    last_snode->next = snode;
}

/*
 * Inserta un nodo en una posición arbitraria de la lista.
 * En caso de querer insertar en una posición fuera de los confines la lista,
 * la función no hace nada.
 */
void
slist_insert_snode(SNode **const slist, SNode *const snode, const uint32_t index)
{
    if (snode == NULL) {
        report(__func__, ERROR, NULL_NODE); return;
    }
    if (*slist == NULL) {
        report(__func__, ERROR, NULL_DATA_STRUCT);
        snode_print_debug(snode);
        return;
    }

    /* Revisamos si se quiere insertar justo al principio o no. */
    if (index == 0) {
        SNode *const old_first_snode = *slist;
        SNode *const new_first_snode = snode;

        *slist = new_first_snode;
        new_first_snode->next = old_first_snode;
        return;
    }

    SNode *const snode_before_index = snode_jump_to_n(*slist, index - 1);
    /* Se está intentando insertar algo fuera de los límites. */
    if (snode_before_index == NULL) {
        report(__func__, ERROR, OUT_OF_BOUNDS);
        snode_print_debug(snode);
        return;
    }
    SNode *const snode_at_index = snode_before_index->next;
    if (snode_at_index == NULL) {
        report(__func__, ERROR, OUT_OF_BOUNDS);
        snode_print_debug(snode);
        return;
    }
    /* Ocurre cuando queremos insertar dentro de la lista */
    snode_before_index->next = snode;
    snode->next = snode_at_index;
}

/*
 * Extrae el último nodo de la lista y lo devuelve.
 */
SNode *
slist_pop_back(SNode **slist)
{
    if (*slist == NULL) {
        report(__func__, ERROR, NULL_DATA_STRUCT);
        return NULL;
    }

    /* No puedo usar snode_jump_to_last porque necesito el penultimo también. */
    SNode *second_last_snode = *slist;
    SNode *last_snode = second_last_snode->next;
    if (last_snode == NULL) {
        report(__func__, WARN, DATA_STRUCT_WILL_BE_EMPTY);
        snode_print_debug(second_last_snode);
        slist = NULL;
        return second_last_snode;
    }

    while(last_snode->next != NULL) {
        second_last_snode = last_snode;
        last_snode = last_snode->next;
    }

    second_last_snode->next = NULL;

    return last_snode;
}

/*
 * Extrae un nodo de una posición arbitraria dentro de los confines de la lista.
 * En caso de intentar extraer un nodo fuera de los límites, la función
 * regresa NULL.
 */
SNode *
slist_extract_node(SNode **const slist, const uint32_t index)
{
    if (*slist == NULL) {
        report(__func__, ERROR, NULL_DATA_STRUCT);
        return NULL;
    }

    SNode *extracted_node;
    if (index == 0) {
        SNode *const old_first_node = *slist;
        SNode *const new_first_node = old_first_node->next;
        extracted_node = new_first_node;
    } else {
        SNode *const node_before_index = snode_jump_to_n(*slist, index - 1);
        if (node_before_index == NULL) {
            report(__func__, ERROR, OUT_OF_BOUNDS);
            return NULL;
        }

        SNode *const node_at_index = node_before_index->next;
        if (node_at_index == NULL) {
            report(__func__, ERROR, OUT_OF_BOUNDS);
            return NULL;
        }

        /* Extraemos. */
        node_before_index->next = node_at_index->next;
        extracted_node = node_at_index;
    }
    return extracted_node;
}

/*
 * Imprime la lista.
 */
void
slist_print(SNode *slist)
{
    if (slist == NULL) {
        report(__func__, ERROR, NULL_DATA_STRUCT);
        return;
    }
    snode_print_all_linked_nodes(slist);
}

