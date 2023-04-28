#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include <libdstruct.h>
#include <report.h>

/*
 * Reserva el espacio de memoria para el uso de una pila estática.
 */
StaticStack *
static_stack_new(int size)
{
	StaticStack *stack = malloc(sizeof(StaticStack));
	stack->array = malloc(size * sizeof(int)); 
	stack->first = 0;
	stack->last = 0;
	stack->size = size;
    stack->is_full = false;
	return stack;
}

/*
 * Inserta un valor en la pila.
 */
void
static_stack_insert(StaticStack *self, int value)
{
    if (self->is_full) {
        printf("La Pila está llena.\n");
        return;
    }
    
    self->array[self->last] = value;
    self->last += 1;
    /*
     * Marcamos a la pila como llena cuando el índice del siguiente
     * nodo es igual (excede) al tamaño de la pila.
     */
    if (self->last == self->size) {
        self->last = (self->last - 1);
        self->is_full = true;
        return;
    }
}

/*
 * Extrae el último elemento de la pila.
 * Regresa -1 si la pila apunta a NULL o está vacía.
 */
int
static_stack_extract(StaticStack *self)
{
    if (self == NULL) {
        report(__func__, ERROR, NULL_HEAD_DATA_STRUCT);
        return -1;
    }
    if (self->size == 0) {
        report(__func__, ERROR, EMPTY_DATA_STRUCT);
        return -1;
    }

    /* Cuando la pila es de tamaño 1, va a estar vacía después. */
    if (self->size == 1) {
        report(__func__, INFO, DATA_STRUCT_WILL_BE_EMPTY);
    }

    int extract = self->array[self->last];
    self->last -= 1;
    return extract;
}

/*
 * Imprime los elementos insertados en la pila.
 */
void
static_stack_print(StaticStack *self)
{
    printf("Tamaño máximo: %d\n", self->size);
    /* first y last conforman un rango inclusivo. */
    for (int i = self->first; i <= self->last; i++) {
        printf("%d ", self->array[i]);
    }
    printf("\n");
}

