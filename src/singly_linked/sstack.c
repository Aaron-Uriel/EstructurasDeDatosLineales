#include <stdio.h>
#include <stdlib.h>
#include <libdstruct.h>


/*
Función que no regresa nada, recibe la dirección de
memoria de un SNode * y un puntero de tipo SNode.
Si el SNode no es NULL: Si la pila == NULL, el SNode se 
pone como primero, sino, se va hasta el último y lo inserta.
*/
void sstack_insert_node(SNode **sstack, SNode *snode)
{
    SNode *actual;

    if (snode != NULL)
    {
        if (*sstack == NULL) {
        *sstack = snode;
        } else {
            actual = *sstack; 
            while (actual->next != NULL) 
            {
                actual = actual->next; 
            }

            actual->next = snode;

        }
    }
}

/*
Regresa un SNode * y recibe la dirección de memoria de un SNode *
Crea dos SNode *, uno para el último y otro para el penúltimo
Si la lista está vacía regresa un SNode * == NULL 
Mientras el siguiente del último sea distinto de NULL:
El penúltimo será el último y último será el SNdode * siguiente.
Cuando se encuetre, sólo el penúltimo deja de apuntar al último 
y regresa el nodo extraido.
*/
SNode *sstack_delete(SNode **sstack)
{
    SNode *second_last_snode = *sstack, *deleted = NULL;
    SNode *last_snode = second_last_snode->next;

    if (*sstack == NULL)
    {
        return deleted;
    }
    
    if (last_snode == NULL) {
        sstack = NULL;
    }

    while(last_snode->next != NULL) {
        second_last_snode = last_snode;
        last_snode = last_snode->next;
    }

    deleted = last_snode;
    last_snode = NULL;
    second_last_snode->next = NULL;
    return deleted;
}

//Imprime la pila.
void sstack_imprimir(SNode **sstack)
{
    snode_print_all_linked_nodes(*sstack);
}

