#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <libdstruct.h>

StaticStack *static_stack_new(int size) {
	StaticStack *stack    = malloc(sizeof(StaticStack));
	stack->array = malloc(size * sizeof(int)); 
	stack->first = 0;
	stack->last = 0;
	stack->size = size;
    bool is_full = false;
	return stack;
}


void static_stack_insert(StaticStack *self, int value) {

  if (self->is_full) {
    printf("La Pila está llena.\n");
    return;
  } else
  {
	self->array[self->last] = value;
	self->last = (self->last + 1);

	if (self->first == self->last) 
    {
         self->is_full = true;
    }
  }
}

void static_stack_extract(StaticStack *self) {
        StaticStack *temp = NULL; 
        int extract;
	    for (int i = self->first; i < self->last; i++) {
            extract = i;
    	}
        temp = self;
        temp->last = (extract) % self->size;

	printf("\n");
    
}

void static_stack_print(StaticStack *self) {

	    for (int i = self->first; i < self->last; i++) {
		    printf("%d ", self->array[i]);
    	}
	printf("\n");
    
}