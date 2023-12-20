#include <stdbool.h>

typedef struct node {
    char* str;
    int val;
    struct node *left;
    struct node *right;
}node_t;

bool compareTo(node_t **pNode, node_t **pNode1);