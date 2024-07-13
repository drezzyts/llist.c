#ifndef LLIST_H
#define LLIST_H

#ifndef NODE_INT_COMPARE
#define NODE_INT_COMPARE __node_int_cmp
#endif

#ifndef NODE_FLOAT_COMPARE
#define NODE_FLOAT_COMPARE __node_float_cmp
#endif

#ifndef NODE_STRING_COMPARE
#define NODE_STRING_COMPARE __node_string_cmp
#endif

#ifndef NODE_CHAR_COMPARE
#define NODE_CHAR_COMPARE __node_char_cmp
#endif

#ifndef __NODE_EPSILON
#define __NODE_EPSILON 1e-5
#endif

#include <stddef.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

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
node_t* node_next(const node_t*, size_t);
node_t* node_previous(const node_t*, size_t);
node_t* node_at(const node_t*, int);
node_t* node_find(const node_t*, const void* expected,
  bool (*compare_function)(const void* expected, const void* current));

void node_delete(node_t*);
void node_remove(node_t*, const void* expected, 
  bool (*compare_function)(const void* expected, const void* current));
void node_pop(node_t*);
void node_shift(node_t*);

size_t node_size(const node_t*);
bool node_empty(const node_t*);

bool __node_int_cmp(const void* expected, const void* current) {
  if (expected == NULL || current == NULL) return false;
  return (*(int*) expected) == (*(int*) current) ? true : false;
}

bool __node_float_cmp(const void* expected, const void* current) {
  if (expected == NULL || current == NULL) return false;
  return fabs(*(float*) expected - *(float*) current) < __NODE_EPSILON;
}

bool __node_string_cmp(const void* expected, const void* current) {
  if (expected == NULL || current == NULL) return false;
  return strcmp(*(char**) expected, *(char**) current) == 0 ? true : false;
}

bool __node_char_cmp(const void* expected, const void* current) {
  if (expected == NULL || current == NULL) return false;
  return (*(char*) expected) == (*(char*) current) ? true : false;
}

#endif