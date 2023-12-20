#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    char ch;
    int value;
}map_char;

map_char* map_char_init();

void map_char_setValue(map_char *map, char key, int val);

int map_char_getValue(map_char *map, char key);

bool map_char_containsKey(map_char *map, char key);

void map_char_free(map_char *map);

void map_char_printMap(map_char *map);

char* character_toString(char ch);