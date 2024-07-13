#ifndef LLIST_H
#define LLIST_H

typedef struct Node {
  struct Node* next;
  struct Node* previous;
  void* value;
} node_t;

node_t* node_create(void*);
node_t* node_append(node_t*, void*);
node_t* node_prepend(node_t*, void*);
node_t* node_pushback(node_t*, void*);
node_t* node_pushfront(node_t*, void*);
node_t* node_first(const node_t*);
node_t* node_last(const node_t*);

#endif