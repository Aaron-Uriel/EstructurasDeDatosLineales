#include <stdio.h>
#include <stdlib.h>
#include <libdstruct.h>

#include <report.h>

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
    } else
    {
        node_append(headqueue->last, node);
        headqueue->last = node;
        headqueue->size += 1;
    }
}


void hqueue_print(HQueue *headqueue)
{
    
    if (headqueue == NULL)
    {
        report(__func__, ERROR, NULL_HEAD_DATA_STRUCT);
    } else
    {
    Node *actual = headqueue->first;
    uint32_t i;
    for (i = 0; actual != NULL && i < headqueue->size; i++) {
        printf("%d  -> ", actual->value);
        actual = actual->next;
    }
          }
        printf("NULL.\n");
    }


    Node *hqueue_extract(HQueue *headqueue, int indice)
    {
        Node *actual = headqueue->first;
        Node *nuevo_inicio_final;
        int i;
        if (headqueue != NULL)
        {
            for (i = 0; i < indice && actual != NULL; i++)
            {
                actual = actual->next;        
            }
            
            if (headqueue->first == actual)
            {
                nuevo_inicio_final = actual->next;
                headqueue->first = nuevo_inicio_final;
                nuevo_inicio_final->previous = NULL;
            
            } else if (headqueue->last == actual)
            {
                nuevo_inicio_final = actual->previous;
                headqueue->last = nuevo_inicio_final;
                nuevo_inicio_final->next = NULL;
            }

            actual->previous = NULL;
            actual->next = NULL;
            return actual;
            


        } else 
        {
             report(__func__, ERROR, NULL_HEAD_DATA_STRUCT);
        }
        
    }
    
