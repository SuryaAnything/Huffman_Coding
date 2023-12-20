#include <stdlib.h>
#include "comparable.h"
#include "build_string.h"


node_t* creat_new_node(int val, char* str);

node_t* join_node(node_t *nptr1, node_t *nptr2);


void get_binary_equivalent(node_t *nptr, char ch, string_builder *str);