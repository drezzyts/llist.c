# 🪢 llist.c

Llist.c is a simple library that provides a linked list structure and methods to manipulate it.

> **License:** MIT

## Summary

* [Creating a linked list](#creating-a-linked-list)
* [Inserting values into a linked list](#inserting-values-into-a-linked-list)
* [Removing values of a linked list](#removing-values-of-a-linked-list)
* [Getting values of a linked list](#getting-values-of-a-linked-list)
* [Deleting specific values](#deleting-specific-values)

## Usage

To use `llist.c`, simply include the header file in your project:

```c
#include "llist.h"
```

## Methods

### Creating a linked list

To create a list in `llist.c` you can use `node_create` function. See the examples below:

**Prototypes:**

```c
node_t* node_create(void*);
```

**Examples:**

```c
// creating nodes
node_t* int_node = node_create(&(int){15});
node_t* float_node = node_create(&(float){12.5f});
node_t* char_node = node_create(&(char){'C'});
```

### Inserting values into a linked list

To insert values into a `llist.c` linked list, you can use `node_append`, `node_prepend`, `node_pushback` or `node_pushfront` functions. See the examples bellow:

**Prototypes:**

```c
node_t* node_append(node_t*, void*);
node_t* node_prepend(node_t*, void*);
node_t* node_pushback(node_t*, void*);
node_t* node_pushfront(node_t*, void*);
```

**Examples:**

```c
// ... pushing a value to the end of a linked list
node_pushback(node, &(int){35});

// ... pushing a value to the start of a linked list
node_pushfront(node, &(int){35});

// ... pushing a value in front of a node
node_append(node, &(int){35});

// ... pushing a value in back of a node
node_prepend(node, &(int){35});
```

### Removing values of a linked list

To remove a value of a `llist.c` linked list, you can use `node_pop` or `node_shift` functions. See the examples bellow:

**Prototypes:**

```c
void node_pop(node_t*);
void node_shift(node_t*);
```

**Examples:**

```c
// ... removing the first element of a linked list
node_shift(node);

// ... removing the last element of a linked list
node_pop(node);
```

### Getting values of a linked list

To get a value of a `llist.c` linked list, you can use `node_first`, `node_last`, `node_next`, `node_previous`, `node_at` or `node_find` functions. See the examples below:

**Prototypes:**

```c
node_t* node_first(const node_t*);
node_t* node_last(const node_t*);
node_t* node_next(const node_t*, size_t);
node_t* node_previous(const node_t*, size_t);
node_t* node_at(const node_t*, int);
node_t* node_find(const node_t*, const void* expected,
  bool (*compare_function)(const void* expected, const void* current));
```

**Examples:**

```c
// ... getting a node by value
node_t* finded_node = node_find(node, &(int){5}, VECTOR_INT_COMPARE);

// ... getting the first element of a linked list
node_t* f1 = node_first(node);
node_t* f2 = node_at(node, 0);

// ... getting the last element of a linked list
node_t* l1 = node_last(node);
node_t* l2 = node_at(node, -1);

// ... getting adjacent node of a specific node
node_t* next = node_next(node);
node_t* prev = node_previous(node);

// ... getting a node at specific index of a linked list
node_t* v1 = node_at(node, 2);
node_t* v2 = node_at(node, -3);
```

### Deleting specific values

To remove a value into a `llist.c` linked list, you can use `node_remove` or `node_delete` functions. See the examples below:

**Prototypes:**

```c
void node_delete(node_t*);
void node_remove(node_t*, const void* expected, 
  bool (*compare_function)(const void* expected, const void* current));
```

**Examples:**

```c
// ... deleting a node
node_delete(node);

// ... removing a node by value comparison
node_remove(node, &(int){2}, NODE_INT_COMPARE);
node_remove(node, &(float){3.5}, NODE_FLOAT_COMPARE);
node_remove(node, &(char){'H'}, NODE_CHAR_COMPARE);
node_remove(node, &(char*){"Hello, World!"}, NODE_STRING_COMPARE);
```
