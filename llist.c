#include "llist.h"
#include <stdlib.h>

node_t *node_create(void* value) {
  node_t* node = (node_t*) malloc(sizeof(node_t));
  node->value = value;
  node->previous = NULL;
  node->next = NULL;

  return node;
}

node_t* node_append(node_t* node, void* value) {
  node_t* next_node = node_create(value);
  next_node->previous = node;
  next_node->next = node->next;

  if (node->next != NULL) 
    node->previous = next_node;

  node->next = next_node;

  return next_node;
}

node_t* node_prepend(node_t* node, void* value) {
  node_t* previous_node = node_create(value);
  previous_node->previous = node->previous;
  previous_node->next = node;

  if (node->previous != NULL)
    node->next = previous_node;

  node->previous = previous_node;

  return previous_node;
}

node_t* node_pushback(node_t* node, void* value) {
  node_t* last_node = node_last(node);
  
  if (last_node == NULL)
    last_node = node;

  node_t* new_node = node_append(last_node, value);
  return new_node;
}

node_t* node_pushfront(node_t* node, void* value) {
  node_t* first_node = node_first(node);
  
  if (first_node == NULL) 
    first_node = node;

  node_t* new_node = node_prepend(first_node, value);
  return new_node;
}

node_t* node_first(const node_t* node) {
  node_t* first = node->previous;

  while (first != NULL && first->previous != NULL)
    first = first->previous;
    
  return first;
};

node_t* node_last(const node_t* node) {
  node_t* last = node->next;

  while (last != NULL && last->next != NULL)
    last = last->next;

  return last;
};
