#include <stdlib.h>
#include <stdio.h>

#include <libdstruct.h>

void
slist_insert_node(SNode **const slist, SNode *const node, const uint32_t index)
{
    /* Revisamos si se quiere insertar justo al principio o no. */
    if (index == 0) {
        SNode *const old_first_node = *slist;
        SNode *const new_first_node = node;

        *slist = new_first_node;
        new_first_node->next = old_first_node;
    } else {
        SNode *const node_before_index = snode_jump_to_n(*slist, index - 1);
        /* Se está intentando insertar algo fuera de los límites. */
        if (node_before_index == NULL) {
            return;
        }

        SNode *const node_at_index = node_before_index->next;
        /* Se está intentando insertar justo al final de la slista */
        if (node_at_index == NULL) {
            node_before_index->next = node;
        }
        /* Ocurre cuando queremos insertar dentro de la slista */
        else {
            node_before_index->next = node;
            node->next = node_at_index;
        }
    }
}

SNode *
slist_extract_node(SNode **const slist, const uint32_t index)
{
    SNode *extracted_node;
    if (index == 0) {
        SNode *const old_first_node = *slist;
        SNode *const new_first_node = old_first_node->next;
        extracted_node = new_first_node;
    } else {
        SNode *const node_before_index = snode_jump_to_n(*slist, index - 1);
        /* Se está intentando extraer algo fuera de los límites. */
        if (node_before_index == NULL) {
            return NULL;
        }

        SNode *const node_at_index = node_before_index->next;
        /* Se está intentando extraer algo fuera d elos límites. */
        if (node_at_index == NULL) {
            return NULL;
        }

        /* Extraemos. */
        node_before_index->next = node_at_index->next;
        extracted_node = node_at_index;
    }
    return extracted_node;
}

void
slist_print(SNode **slist)
{
    snode_print_all_linked_nodes(*slist);
}
