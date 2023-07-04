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
    PQueue *new_pqueue = calloc(1, sizeof(*new_pqueue));
    return new_pqueue;
}

/*
 * Inserta un nodo dentro de la cola, basado en su prioridad.
 * El nodo insertado se coloca en una determinada parte de la cola
 * dependiendo de su valor de prioridad, las prioridades de menor
 * valor se colocan antes, por lo que la mayor prioridad es 0.
 */
void
pqueue_enqueue(PQueue *cola, PNode *nodo) {
    if (cola && nodo) {
        if (cola->size) {
            /* 
             * Manejamos los siguientes casos:
             * - Prioridad de menor valor que la del nodo de menor prioridad.
             * - Prioridad igual o mayor que la del nodo de mayor prioridad.
             * - Ningún caso especial (buscamos su lugar).
             */
            if (nodo->priority < cola->first->priority) {
                pnode_prepend(cola->first, nodo);
                cola->first = nodo;
            }
            else if (nodo->priority >= cola->last->priority) {
                pnode_append(cola->last, nodo);
                cola->last = nodo;
            }
            else {
                uint32_t nodos_analizados = 0;
                PNode *nodo_actual = cola->first;
                while (nodos_analizados < cola->size  &&
                       nodo_actual->priority <= nodo->priority)
                {
                    nodo_actual = nodo_actual->next;
                }
                pnode_prepend(nodo_actual, nodo);
            }
        } else {
            cola->first = cola->last = nodo;
        }
        cola->size += 1;
    }
}

/*
 * Devuelve siempre el primer nodo de la cola, siendo este el de prioridad
 * de menor valor.
 */
PNode *
pqueue_dequeue(PQueue *cola) {
    PNode *nodo_extraido = NULL;
    if (cola && cola->size) {
        nodo_extraido = cola->first;
        cola->first = cola->first->next;
        if (cola->first) {
            cola->first->previous = NULL;
        }
        cola->size -= 1;
        nodo_extraido-> next = nodo_extraido->previous = NULL;
    }
    return nodo_extraido;
}

/*
 * Libera toda la memoria relacionada con la cola de prioridad, incluyendo
 * a la cabecera.
 */
void
pqueue_free(PQueue **cola)
{
    if (cola && *cola) {
        pnode_free_group(&(*cola)->first);
        free(*cola);
        *cola = NULL;
    }
}

/*
 * Imprime todos los nodos dentro de la cola con prioridad, incluyendo sus
 * prioridades asociadas.
 */
void
pqueue_print(PQueue *cola) {
    if (cola && cola->size) {
        printf("Tamaño: %d.\n", cola->size);
        PNode *nodo_actual;
        uint32_t i;
        for (nodo_actual = cola->first, i = 0;
             nodo_actual != NULL && i < cola->size;
             nodo_actual = nodo_actual->next, i += 1) {
            printf("(%d, %d) -> ",
                   nodo_actual->value,
                   nodo_actual->priority);
        }
        printf("NULL\n");
    }
}
