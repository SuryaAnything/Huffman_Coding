/**
 * Dynamic Heap Implementation Using Binary Trees
 *
 * This code implements a heap data structure using binary tree nodes.
 * It includes functions for heap creation, insertion, and removal of elements.
 *
 *
 * Note:
 * - Insertion maintains a copy of the node to avoid modifications to the original.
 * - Removal returns the original node address; memory cleanup is the user's responsibility.
 * - Assumes a min-heap structure.
 */




#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "binary_tree.h"
#define DEFAULT_HEAP_SIZE 20


typedef struct {
    node_t **value;
    int size;
    int current_size;
}heap;

static void swap_elements(node_t **pNode, int index, int ind);

static int get_min_index(node_t **pNode, int idx1, int idx2);

heap* heap_initializer();

// Reallocation

void heap_reallocate(heap *hptr);

static bool heap_isFull(heap *hptr);

// Insertion

void insert_heap(heap *hptr, node_t *nptr);

// Removal

node_t* remove_heap(heap *hptr);

void heap_deallocate(heap *hptr);