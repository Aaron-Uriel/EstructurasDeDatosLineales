#ifndef LIBDSTRUCT
#define LIBDSTRUCT

#include <stdbool.h>

#if defined _WIN32 || defined __CYGWIN__
  #ifdef BUILDING_LIBDSTRUCT
    #define LIBDSTRUCT_PUBLIC __declspec(dllexport)
  #else
    #define LIBDSTRUCT_PUBLIC __declspec(dllimport)
  #endif
#else
  #ifdef BUILDING_LIBDSTRUCT
      #define PUBLIC __attribute__((visibility ("default")))
  #else
      #define PUBLIC
  #endif
#endif

#include <stdint.h>

typedef struct List List;
typedef struct HList HList;
typedef struct SList SList;

typedef struct Queue Queue;
typedef struct HQueue HQueue;
typedef struct SQueue SQueue;

typedef struct SNode SNode;
struct SNode {
	int32_t  value;
	SNode    *_next;
};

SNode   *snode_new(int32_t value);
void    snode_delete(SNode *const self);
SNode   *snode_get_next(SNode *const self);
void    snode_append(SNode *const self, SNode *const adjacent_node);

typedef struct Node Node;
struct Node {
    int32_t value;
    Node    *previous;
    Node    *next;
};

Node *node_new(int32_t value);
void node_delete(Node *const self);
Node *node_get_next(Node *const self);
Node *node_get_previous(Node *const self);
void node_append(Node *const self, Node *const adjacent_node);
void node_prepend(Node *const self, Node *const adjacent_node);

#endif
