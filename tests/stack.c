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
   StaticQueue *queue = static_queue_new(15);
   int numero;

   printf("Ingrese un numero: ");
   scanf("%d", &numero);
   static_queue_insert(queue, numero);
   static_queue_print(queue);

   printf("Ingrese un numero: ");
   scanf("%d", &numero);
   static_queue_insert(queue, numero);
   static_queue_print(queue);

   printf("Ingrese un numero: ");
   scanf("%d", &numero);
   static_queue_insert(queue, numero);
   static_queue_print(queue);

   static_queue_extract(queue);
   static_queue_print(queue);

   printf("Ingrese un numero: ");
   scanf("%d", &numero);
   static_queue_insert(queue, numero);
   static_queue_print(queue);
   
   printf("Ingrese un numero: ");
   scanf("%d", &numero);
   static_queue_insert(queue, numero);
   static_queue_print(queue);

   static_queue_extract(queue);
   static_queue_print(queue);
    return 0;
}
