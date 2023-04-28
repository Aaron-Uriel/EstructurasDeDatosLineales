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
   StaticStack *queue = static_stack_new(15);
   int numero;

   printf("Ingrese un numero: ");
   scanf("%d", &numero);
   static_stack_insert(queue, numero);
   static_stack_print(queue);

   printf("Ingrese un numero: ");
   scanf("%d", &numero);
   static_stack_insert(queue, numero);
   static_stack_print(queue);

   printf("Ingrese un numero: ");
   scanf("%d", &numero);
   static_stack_insert(queue, numero);
   static_stack_print(queue);

   static_stack_extract(queue);
   static_stack_print(queue);

   printf("Ingrese un numero: ");
   scanf("%d", &numero);
   static_stack_insert(queue, numero);
   static_stack_print(queue);
   
   printf("Ingrese un numero: ");
   scanf("%d", &numero);
   static_stack_insert(queue, numero);
   static_stack_print(queue);

   static_stack_extract(queue);
   static_stack_print(queue);
    return 0;
}
