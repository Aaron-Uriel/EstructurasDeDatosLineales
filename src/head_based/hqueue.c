#include <stdio.h>
#include <stdlib.h>
#include <libdstruct.h>



HQueue *
hqueue_new(void) {
    HQueue *new_hqueue = malloc(sizeof(*new_hqueue));
    if (new_hqueue == NULL) {
        return NULL;
    }

    new_hqueue->first = NULL;
    new_hqueue->last = NULL;
    new_hqueue->size = 0;

    return new_hqueue;
}

void hqueue_insert(HQueue *headqueue, Node *queue)
{
    if (headqueue->size == 0) {
        headqueue->first = queue;
        headqueue->last = queue;
        headqueue->size = 1;
    } else
    {
        headqueue->last = queue;
        node_append(headqueue->last, queue);
        headqueue->size += 1;
    }
}


void hqueue_print(HQueue *headqueue)
{
    
    if (headqueue == NULL)
    {
        printf("\t| + Esta vacia. +\n");
    } else
    {
    Node *actual = headqueue->first;
    uint32_t i;
    for (i = 0; actual != NULL && i <= headqueue->size; i++) {
        printf(" tamanio: %d, %d  -> ", headqueue->size, actual->value);
        actual = actual->next;
    }
          }
        printf("NULL.\n");
    }
    
