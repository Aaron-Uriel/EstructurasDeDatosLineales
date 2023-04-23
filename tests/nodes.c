#include <stdint.h>
#include <stdio.h>
#include <assert.h>

#include <libdstruct.h>
#include <string.h>

void node_test(void) {
    /* Inicializamos y vemos que se inicializó como esperamos. */
    Node *mynode = node_new(45);
    assert(mynode->value == 45);
    
    /* Creamos arreglo de nodos */
    Node *node_array[10];
    int32_t i;
    for (i = 0; i < 10; i++) {
        node_array[i] = node_new(i);
        assert(node_array[i]->next == NULL && node_array[i]->previous == NULL);
    }

    /* Probamos dos de las funciones para crear enlaces. */
    node_prepend(mynode, node_array[7]);
    assert(mynode->previous->value == 7);
    node_append(mynode, node_array[3]);
    assert(mynode->next->value == 3);

    /* Probamos función de clonar nodo. */
    Node *myclone = node_clone(mynode);
    assert(memcmp((void *)mynode, (void *)myclone, sizeof(*myclone)) == 0);

    /* Probamos la función para quitar enlaces. */
    node_unlink(mynode);
    assert(mynode->previous == NULL && mynode->next == NULL);
    assert(node_array[7]->next == NULL && node_array[3]->previous == NULL);

    assert(memcmp((void *)mynode, (void *)myclone, sizeof(*mynode)) == 0);
}

int
main(void) {

    return 0;
}
