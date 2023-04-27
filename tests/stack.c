#include <stdlib.h>
#include <stdio.h>
#include <libdstruct.h>


int
main(void)
{
    /*List *headlist = list_new(); 
    Node *hlist = NULL;
    int numero;
    printf("Un número: ");
    scanf("%d", &numero);
    hlist = node_new(numero);
    list_insert_node(headlist, hlist);
    list_print(headlist);
    */

   HQueue *headqueue = hqueue_new();
   Node *queue = NULL; 
   int numero;
   printf("Numero: ");
   scanf("%d", &numero);
   queue = node_new(numero);
   hqueue_insert(headqueue, queue);
   hqueue_print(headqueue);

   printf("Numero: ");
   scanf("%d", &numero);
   queue = node_new(numero);
   hqueue_insert(headqueue, queue);
   hqueue_print(headqueue);

    printf("Numero: ");
   scanf("%d", &numero);
   queue = node_new(numero);
   hqueue_insert(headqueue, queue);
   hqueue_print(headqueue);
    return 0;
}
