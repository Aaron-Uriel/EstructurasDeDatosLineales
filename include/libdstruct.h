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

/* Nodo simplemente enlazado. */
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

/* Nodo doblemente enlazado. */
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
PUBLIC void node_unlink(Node *const self);
PUBLIC Node *node_jump_to_last(Node *const self);
PUBLIC Node *node_jump_to_first(Node *const self);
PUBLIC Node *node_jump_to_n(Node *const self, const uint32_t n);
PUBLIC void node_print_all_linked_nodes(Node *const self);
PUBLIC void node_print_debug(const Node *const self);

/* Nodo doblemente enlazado y con prioridad. */
typedef struct PNode PNode;
struct PNode {
    int32_t value;
    uint8_t priority;
    PNode *previous;
    PNode *next;
};
PUBLIC PNode   *pnode_new(int32_t value, uint8_t priority);
PUBLIC PNode   *pnode_new_from_node(Node *node, uint8_t priority);
PUBLIC void    pnode_delete(PNode **self);
PUBLIC PNode   *pnode_clone(PNode *self);
PUBLIC void    pnode_append(PNode *self, PNode *pnode);
PUBLIC void    pnode_prepend(PNode *self, PNode *pnode);
PUBLIC void    pnode_unlink(PNode *self);


/* Fin de nodos. */

/* Colas. */

/* Cola simplemente enlazada. */
PUBLIC SNode *squeue_dequeue(SNode **const squeue);
PUBLIC void squeue_enqueue(SNode **squeue, SNode *snode);
PUBLIC void squeue_print(SNode *squeue);

/* Cola doblemente enlazada. */
PUBLIC void dqueue_enqueue(Node **dqueue, Node *node);
PUBLIC Node *dqueue_dequeue(Node **const dqueue);
PUBLIC void dqueue_print(Node *dqueue);

/* Cola con cabecera. */
typedef struct HQueue HQueue;
struct HQueue {
    Node *first;
    Node *last;
    uint32_t size;
};
PUBLIC HQueue *hqueue_new(void);
PUBLIC void hqueue_insert(HQueue *headqueue, Node *queue);
PUBLIC void hqueue_print(HQueue *headqueue);

/* Cola con prioridad. */
typedef struct PQueue PQueue;
struct PQueue {
    PNode *first;
    PNode *last;
    uint32_t size;
};
PUBLIC PQueue   *pqueue_new(void);
PUBLIC void     pqueue_enqueue(PQueue *pqueue, PNode *pnode);
PUBLIC PNode    *pqueue_dequeue(PQueue *pqueue);
PUBLIC void     pqueue_print(PQueue *pequeue);

/* Fin de colas. */

/* Listas. */

/* Lista simplemente ligada. */
PUBLIC void     slist_insert_snode(SNode **const slist, SNode *const snode);
PUBLIC int32_t  slist_search_snode(SNode **const slist, SNode *const snode);
PUBLIC SNode    *slist_extract_node(SNode **const slist, const uint32_t index);
PUBLIC void     slist_print(SNode *slist);

/* Lista doblemente ligada. */
PUBLIC void dlist_insert_node(Node **dlist, Node *node);
PUBLIC void dlist_imprimir(Node **list);
PUBLIC Node *dlist_delete_node(Node **dlist, int id);
PUBLIC int  dlist_search_node(Node **dlist, Node* node);

/* Lista con cabecera. */
typedef struct List List;
struct List {
    Node *first;
    Node *last;
    uint32_t size;
};
PUBLIC List     *list_new(void);
PUBLIC void     list_insert_node(List *const list, Node *const node);
PUBLIC int32_t  list_search_node(List *const list, Node *const node);
PUBLIC Node     *list_extract_node(List *const list, const uint32_t n);
PUBLIC void     list_print(List *const list);


/* Fin de listas. */

/* Pila. */

/* Pila simplemente enlazada. */
PUBLIC void sstack_insert_node(SNode **sstack, SNode *snode);
PUBLIC SNode *sstack_delete(SNode **sstack);
PUBLIC void sstack_imprimir(SNode **sstack);

/* Fin de pila. */

#endif
