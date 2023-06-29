#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include <libdstruct.h>

/*
 * Asigna la dirección de memoria para usar una cola con prioridad.
 * La cola se inicializa vacía por lo que no tiene nodos, estos se pueden
 * agregar después.
 */
PQueue *
pqueue_new(void) {
    PQueue *new_pqueue = malloc(sizeof(*new_pqueue));
    if (new_pqueue == NULL) {
        return NULL;
    }

    new_pqueue->first = NULL;
    new_pqueue->last = NULL;
    new_pqueue->size = 0;

    return new_pqueue;
}

/*
 * Inserta un nodo dentro de la cola.
 * El nodo insertado se coloca en una determinada parte de la cola
 * dependiendo de su valor de prioridad, las prioridades de menor
 * valor se colocan antes, por lo que la mayor prioridad es 0.
 */
void
pqueue_enqueue(PQueue *pqueue, PNode *pnode) {
    if (pnode == NULL) {
        return;
    }
    if (pqueue == NULL) {
        return;
    }

    /* Cuando la cola no tiene ningún elemento todavía. */
    if (pqueue->size == 0) {
        pqueue->first = pnode;
        pqueue->last = pnode;
        pqueue->size = 1;
        return;
    }

    /*
     * Cuando la prioridad del nodo a insertar es mas cercana a 0 que
     * la del primer nodo.
     */
    if (pnode->priority < pqueue->first->priority) {
        pnode_prepend(pqueue->first, pnode);
        pqueue->first = pnode;
        pqueue->size += 1;
        return;
    }

    /*
     * Cuando la prioridad del nodo a insertar es de igual o mayor
     * valor que la del último nodo, lo insertamos al final.
     */
    if (pnode->priority >= pqueue->last->priority) {
        pnode_append(pqueue->last, pnode);
        pqueue->last = pnode;
        pqueue->size += 1;
        return;
    }
    
    /*
     * Cuando no ocurre ningúna caso especial, buscamos la prioridad 
     * correspondiente al nodo.
     * Nos movemos justo al lugar donde aparezca una prioridad de
     * mayor valor e insertamos antes.
     */
    uint32_t i;
    PNode *current_pnode;
    for (current_pnode = pqueue->first, i = 0;
         current_pnode != NULL && i < pqueue->size;
         current_pnode = current_pnode->next, i += 1) {
        /* 
         * Cuando el nodo actual es de una prioridad de mayor valor,
         * insertamos antes de el y después del anterior.
         */
        if (current_pnode->priority > pnode->priority) {
            PNode *prev_pnode = current_pnode->previous;
            pnode_append(prev_pnode, pnode);
            pnode_prepend(current_pnode, pnode);
            pqueue->size += 1;
            return;
        }
    }

    /* Nunca se debería llegar hasta aquí. */
}

/*
 * Devuelve siempre el primer nodo de la cola.
 * La prioridad de los nodos devueltos debería de ser siempre la
 * menor que esté en la cola, pero esta función no lo verifica, la
 * función para insertar se encarga de insertarlos ordenadamete.
 */
PNode *
pqueue_dequeue(PQueue *pqueue) {
    if (pqueue == NULL) {
        return NULL;
    }
    /* Cuando la estructura está vacía, no podemos extraer nada. */
    if (pqueue->size == 0) {
        return NULL;
    }

    /*
     * Cuando solo se tiene un elemento en la cola, vaciamos la
     * cola.
     */
    if (pqueue->size == 1) {
        PNode *const extracted_pnode = pqueue->first;
        pqueue->first = NULL;
        pqueue->last = NULL;
        pqueue->size = 0;
        return extracted_pnode;
    }

    /*
     * Cuando no hay ningún caso especial, escogemos el nodo a
     * extraer, movemos la referencia del primer nodo y desenlazamos
     * el que era el primer nodo.
     */
    PNode *const extracted_pnode = pqueue->first;
    pqueue->first = pqueue->first->next;
    pqueue->size -= 1;

    pnode_unlink(extracted_pnode);
    return extracted_pnode; 
}

void
pqueue_print(PQueue *pqueue) {
    if (pqueue == NULL) {
        return;
    }

    printf("Tamaño: %d.\n", pqueue->size);
    PNode *current_pnode;
    uint32_t i;
    for (current_pnode = pqueue->first, i = 0;
         current_pnode != NULL && i < pqueue->size;
         current_pnode = current_pnode->next, i += 1) {
        printf("(%d, %d) -> ",
               current_pnode->value,
               current_pnode->priority);
    }
    printf("NULL\n");
}
