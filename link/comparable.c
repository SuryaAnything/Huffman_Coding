//
// Created by surya on 20-12-2023.
//
#include "../include/comparable.h"
bool compareTo(node_t **pNode, node_t **pNode1) {
    if ((*pNode)->val < (*pNode1)->val)
        return true;
    else
        return false;
}