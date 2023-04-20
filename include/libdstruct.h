#ifndef LIBDSTRUCT
#define LIBDSTRUCT

#ifdef BUILDING_LIBDSTRUCT
    #define PUBLIC __attribute__((visibility ("default")))
#else
    #define PUBLIC
#endif

#include <stdbool.h>
#include <stdint.h>



/* Nodos. */

typedef struct SNode SNode;
struct SNode {
	int32_t  value;
	SNode    *next;
};

PUBLIC SNode    *snode_new(int32_t value);
PUBLIC void     snode_delete(SNode **self);
PUBLIC SNode    *snode_clone(SNode *self);
PUBLIC void     snode_append(SNode *const self, SNode *const snode);
PUBLIC SNode    *snode_jump_to_last(SNode *const self);
PUBLIC SNode    *snode_jump_to_n(SNode *const self, const uint32_t n);
PUBLIC void     snode_print_all_linked_nodes(const SNode *const self);
PUBLIC void     snode_print_debug(const SNode *const self);

typedef struct Node Node;
struct Node {
    int32_t value;
    Node    *previous;
    Node    *next;
};

PUBLIC Node *node_new(int32_t value);
PUBLIC void node_delete(Node **const self);
PUBLIC Node *node_clone(Node *self);
PUBLIC void node_append(Node *const self, Node *const node);
PUBLIC void node_prepend(Node *const self, Node *const node);
PUBLIC Node *node_jump_to_last(Node *const self);
PUBLIC Node *node_jump_to_first(Node *const self);
PUBLIC Node *node_jump_to_n(Node *const self, const uint32_t n);
PUBLIC void node_print_all_linked_nodes(Node *const self);
PUBLIC void node_print_debug(const Node *const self);

/* Fin de nodos. */

/* Listas. */

PUBLIC void     slist_push_back(SNode **slist, SNode *snode);
PUBLIC void     slist_insert_snode(SNode **const slist, SNode *const snode, const uint32_t index);
PUBLIC int32_t  slist_search_snode(SNode **const slist, SNode *const snode);
PUBLIC SNode    *slist_pop_back(SNode **slist);
PUBLIC SNode    *slist_extract_node(SNode **const slist, const uint32_t index);
PUBLIC void     slist_print(SNode *slist);

typedef struct HList HList;


/* Fin de listas. */

/* Colas. */

typedef struct HQueue HQueue;

PUBLIC SNode *squeue_dequeue(SNode **const squeue);
PUBLIC void squeue_enqueue(SNode **squeue, SNode *snode);
PUBLIC void squeue_print(SNode *squeue);

/* Fin de colas. */

/* Pila. */

PUBLIC void sstack_insert_node(SNode **sstack, SNode *snode, int id);
PUBLIC void sstack_delete(SNode **sstack);
PUBLIC void sstack_imprimir(SNode **sstack);

/* Fin de pila. */

/*Lista doblemente ligada*/
PUBLIC void dolist_insert_node(Node **dlist, Node *node, int id);
PUBLIC void dlist_imprimir(Node **list);
PUBLIC void delete_node(Node **dlist, int id);
/*Fin lista*/
#endif
