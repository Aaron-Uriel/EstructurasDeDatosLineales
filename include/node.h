#ifndef NODE_H
#define NODE_H

#include <stdint.h>

typedef struct SNode SNode;

SNode   *snode_new(int32_t);
void    snode_delete(SNode *);
SNode   *snode_get_next(SNode *);
void    snode_append(SNode *const, SNode *const);

typedef struct Node Node;

Node *node_new(int32_t);
void node_delete(Node *);
Node *node_get_next(Node *);
Node *node_get_previous(Node *);
void node_append(Node *self, Node *adjacent_node);
void node_prepend(Node *self, Node *adjacent_node);

#endif
