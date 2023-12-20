//
// Created by surya on 20-12-2023.
//
#include "../include/dynamic_heap.h"
heap* heap_initializer() {
    heap *hptr = (heap*) malloc(sizeof(heap));
    hptr->value = (node_t**) malloc(DEFAULT_HEAP_SIZE*sizeof(node_t*));
    hptr->size = DEFAULT_HEAP_SIZE;
    hptr->current_size = 0;
    return hptr;
}

// Reallocation

void heap_reallocate(heap *hptr) {
    node_t **newPtr = (node_t**)realloc(hptr->value, hptr->size*2* sizeof(node_t*));
    if (newPtr!=NULL) {
        hptr->value = newPtr;
    }
    hptr->size *= 2;
}

static bool heap_isFull(heap *hptr) {
    return hptr->current_size==hptr->size;
}


// Insertion

void insert_heap(heap *hptr, node_t *nptr) {
    if (heap_isFull(hptr)) {
        heap_reallocate(hptr);
    }
    int index = hptr->current_size++;
    *(hptr->value + index) = (node_t*) malloc(sizeof(node_t));
    memcpy(*(hptr->value + index),nptr, sizeof(node_t));
    // check with its parent index and get right placed
    int parent_ind = (index - 1) / 2;
    while (index > 0) {
        if (compareTo((hptr->value + index), (hptr->value + parent_ind))) {
            swap_elements(hptr->value, index, parent_ind);
            index = parent_ind;
            parent_ind = (index - 1) / 2;
        }
        else break;
    }
}


// Removal

node_t* remove_heap(heap *hptr) {
    int index = --hptr->current_size;
    node_t *removable = *(hptr->value + 0);

    swap_elements(hptr->value, 0, index);
    *(hptr->value + index) = NULL;

    index = 0; //
    // check with its child index and get right placed
    int c_idx1 = 2 * index + 1;
    int c_idx2 = 2 * index + 2;

    while (c_idx2 < hptr->current_size) {
        if (compareTo(hptr->value + c_idx1, hptr->value + index) ||
            compareTo(hptr->value + c_idx2, hptr->value + index)) {
            int swap_index = get_min_index(hptr->value, c_idx1, c_idx2);
            swap_elements(hptr->value, swap_index, index);
            index = swap_index;
            c_idx1 = 2 * index + 1;
            c_idx2 = 2 * index + 2;
        }
        else break;
    }
    if (c_idx1 < hptr->current_size) {
        if (compareTo(hptr->value + c_idx1, hptr->value + index)){
            int swap_index = c_idx1;
            swap_elements(hptr->value, swap_index, index);
        }
    }

    return removable;
}

static int get_min_index(node_t **pNode, int idx1, int idx2) {
    if ((*(pNode + idx1))->val < (*(pNode + idx2))->val){
        return idx1;
    }
    else
        return idx2;
}

static void swap_elements(node_t **pNode, int index, int ind) {
    node_t *temp = *(pNode + ind);
    *(pNode + ind) = *(pNode + index);
    *(pNode + index) = temp;
}

void heap_deallocate(heap *hptr) {
    free(hptr->value);
    free(hptr);
}