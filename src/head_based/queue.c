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

void hqueue_insert(HQueue *headqueue, Node *node)
{
    if (headqueue->size == 0) {
        headqueue->first = node;
        headqueue->last = node;
        headqueue->size = 1;
    } else {
        node_append(headqueue->last, node);
        headqueue->last = node;
        headqueue->size += 1;
    }
}


void hqueue_print(HQueue *headqueue)
{
    if (headqueue) {
        Node *actual = headqueue->first;
        uint32_t i;
        for (i = 0; actual != NULL && i < headqueue->size; i++) {
            printf("%d  -> ", actual->value);
            actual = actual->next;
        }
    }
    printf("NULL.\n");
}


Node *hqueue_extract(HQueue *headqueue)
{
    Node *actual = headqueue->first;
    Node *nuevo_inicio_final;
    int i;
    if (headqueue != NULL) {
        nuevo_inicio_final = actual->next;
        headqueue->first = nuevo_inicio_final;

        actual->previous = NULL;
        actual->next = NULL;
        return actual;
    }
}
