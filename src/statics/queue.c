#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include <libdstruct.h>


StaticQueue *
static_queue_new(int size)
{
    StaticQueue *queue = malloc(sizeof(StaticQueue));
    queue->array = malloc(size * sizeof(int)); 
    queue->first = 0;
    queue->last = 0;
    queue->size = size;
    queue->is_full = false;

    return queue;
}


void
static_queue_insert(StaticQueue *self, int value)
{
    if (self->is_full) {
        printf("La cola está llena.\n");
        return;
    }
    self->array[self->last] = value;
    self->last = (self->last + 1) % self->size;

    if (self->first == self->last) 
    {
        self->is_full = true;

    }
}


int static_queue_extract(StaticQueue *self)
{
    int extraer;
    if (self->last == self->first && self->is_full == false)
    {
        return -1;
    }
    
    extraer = self->array[self->first];
    self->first = (self->first + 1) % self->size;
    if (self->is_full)
    {
        self->is_full = false;
    }
    
    return extraer;
}

void
static_queue_print(StaticQueue *self)
{

    if (self->is_full)
    {
        int condic_paro = (self->size - 1 + self->first) % self->size, i;
        for (i = self->first;
            i != condic_paro;
            i = (i + 1) % self->size) {
            printf("%d ", self->array[i]);
        }
        printf("%d \n", self->array[i]);

        return;
    }
    
    for (int i = self->first;
         i != self->last;
         i = (i + 1) % self->size) {
        printf("%d ", self->array[i]);
    }

    printf("\n");
}

