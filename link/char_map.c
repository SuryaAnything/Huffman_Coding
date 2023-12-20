//
// Created by surya on 20-12-2023.
//
#include "../include/char_map.h"
#include <stdio.h>

map_char* map_char_init() {
    map_char *map = malloc(128*sizeof(map_char));
    for (int i = 0; i < 128; ++i) {
        (map + i)->value = 0;
        (map + i)->ch = -1;
    }
    return map;
}

void map_char_setValue(map_char *map, char key, int val) {
    (map + key)->ch = key;
    (map + key)->value = val;
}

int map_char_getValue(map_char *map, char key) { return (map + key)->value; }

bool map_char_containsKey(map_char *map, char key) {
    if ((map + key)->value != 0) return true;
    else { return false; }
}

void map_char_free(map_char *map) { free(map); }

void map_char_printMap(map_char *map) {
    printf("char   frequency \n");
    printf("+-----+-----+\n");
    for (int i = 0; i < 128; ++i) {
        if (map_char_containsKey(map, (char)i))
            printf("|  %c  |  %d  \n",(char)i, map_char_getValue(map,(char)i));
    }
    printf("+-----+-----+\n");
}

char* character_toString(char ch) {
    char *str = (char*) malloc(2);
    *(str + 0) = ch;
    *(str + 1) = '\0';
    return str;
}