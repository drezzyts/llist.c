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
}

node_t* node_at(const node_t* node, int index) {
  node_t* current = index < 0 ? node_last(node) : node_first(node);

  if (current == NULL) return NULL;

  if (index > 0)
    return node_next(current, index);
  else if (index < 0)
    return node_previous(current, abs(index + 1));
  else
    return current;
}

node_t *node_find(const node_t* node, const void *expected, 
  bool (*compare_function)(const void *expected, const void *current))
{
  node_t* current = node_first(node);
  
  while(current != NULL) {
    bool is_equal = compare_function(expected, current->value);
    if (is_equal) return current;
    current = current->next;
  }

  return NULL;
};

node_t* node_next(const node_t* node, size_t offset) {
  node_t* current = node->next;

  for (int i = 0; i < offset - 1; i++) {
    if (current == NULL || current->next == NULL) 
      return NULL;

    current = current->next; 
  };

  return current;
};

node_t* node_previous(const node_t* node, size_t offset) {
  node_t* current = node->previous;

  for (int i = 0; i < offset - 1; i++) {
    if (current == NULL || current->next == NULL) 
      return NULL;

    current = current->previous; 
  };

  return current;
};

size_t node_size(const node_t* node) {
  node_t* current = node_first(node);
  size_t size = 0;

  while (current != NULL) {
    current = current->next;
    size++;
  }

  return size;
};

bool node_empty(const node_t* node) {
  return node->next == NULL && node->previous == NULL ? true : false;
};

void node_delete(node_t* node) {
  node_t* next_node = node->next;
  node_t* prev_node = node->previous;

  if (next_node)
    next_node->previous = prev_node;
  
  if (prev_node)
    prev_node->next = next_node;

  free(node);
}

void node_remove(node_t* node, const void *expected, 
  bool (*compare_function)(const void *expected, const void *current)) 
{
  node_t* current = node_first(node);

  while(current != NULL) {
    bool is_equal = compare_function(expected, current->value);
    if (is_equal) return node_delete(current);
    current = current->next;
  }
};

void node_pop(node_t* node) {
  node_t* last = node_last(node);
  if (last == NULL) return;

  node_delete(last);
};

void node_shift(node_t* node) {
  node_t* first = node_first(node);
  if (first == NULL) return;

  node_delete(first); 
};