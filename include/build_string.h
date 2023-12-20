/**
 * String Builder Implementation
 * This code implements a simple string builder in C, allowing dynamic string
 * concatenation and resizing.
 *
 * Note:
 * - The string builder dynamically resizes its buffer as needed.
 * - The `string_builder` struct allows for building strings without constant resizing.
 */

#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define DEFAULT_BUILDER_SIZE 10

typedef struct {
    char *string;
    int current_size;
    int size;
}string_builder;

string_builder* build_new_string();

static void stringBuilder_reallocate(string_builder *str);

void append_string(string_builder *str1, const char *str2);

char* stringBuilder_toString(string_builder *str);

void stringBuilder_deallocate(string_builder *stream);