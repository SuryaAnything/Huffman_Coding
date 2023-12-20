//
// Created by surya on 20-12-2023.
//
#include "../include/binary_tree.h"
node_t* creat_new_node(int val, char* str) {
    node_t *nptr = (node_t*) malloc(sizeof(node_t));
    nptr->str = (char*) calloc(128, sizeof(char));
    strcpy(nptr->str,str);
    free(str);
    nptr->val = val;
    nptr->right = NULL;
    nptr->left = NULL;
    return nptr;
}

node_t* join_node(node_t *nptr1, node_t *nptr2) {
    int new_value = nptr1->val + nptr2->val;
    char *new_str = (char*) malloc(128);
    strcpy(new_str,nptr1->str);
    strcat(new_str,nptr2->str);
    node_t *joined = creat_new_node(new_value, new_str);
    joined->left = (node_t*) malloc(sizeof(node_t));
    joined->right = (node_t*) malloc(sizeof(node_t));
    if (compareTo(&nptr1,&nptr2)){
        memcpy(joined->left,nptr1, sizeof(node_t));
        memcpy(joined->right,nptr2, sizeof(node_t));
    }
    else {
        memcpy(joined->left,nptr2, sizeof(node_t));
        memcpy(joined->right,nptr1, sizeof(node_t));
    }
    return joined;
}


void get_binary_equivalent(node_t *nptr, char ch, string_builder *str) {
    if (strlen(nptr->str)==1)
        return;

    bool direction = false;

    for (int i = 0; nptr->left->str[i]!='\0' ; ++i) {

        if (ch==nptr->left->str[i]) {
            direction = true;
            break;
        }
    }

    if (direction) {
        append_string(str,"0");
        return get_binary_equivalent(nptr->left, ch, str);
    }
    else {
        append_string(str,"1");
        return get_binary_equivalent(nptr->right,ch,str);
    }

}