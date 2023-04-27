#include <stdio.h>
#include <stdlib.h>
#include <libdstruct.h>


void hqueue_insert(List *headqueue, Node *queue)
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


void hqueue_print(List *headqueue)
{
    Node *actual = headqueue->first;
    int32_t i;
    if (headqueue == NULL)
    {
        printf("\t| + Esta vacia. +\n");
    } else
    {
        for (actual = headqueue->first, i = 0;
         actual != NULL && i < headqueue->size;
         actual = actual->next, i += 1) {
        printf("%d -> Tamanio %d ", actual->value, headqueue->size);
          }
        printf("NULL.\n");
    }
    
}