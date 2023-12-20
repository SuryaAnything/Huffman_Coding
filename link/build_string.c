//
// Created by surya on 20-12-2023.
//

#include "../include/build_string.h"
string_builder* build_new_string() {
    string_builder *str = malloc(sizeof(string_builder));
    str->string = (char*) calloc(DEFAULT_BUILDER_SIZE,sizeof(char));
    str->size = DEFAULT_BUILDER_SIZE;
    str->current_size = 0;
    return str;
}

static void stringBuilder_reallocate(string_builder *str) {
    char *ptr = realloc(str->string,str->size*2);
    if(ptr!=NULL)
        str->string = ptr;
    str->size *= 2;
}

void append_string(string_builder *str1, const char *str2) {
    while (strlen(str2)>=(str1->size-str1->current_size)) {
        stringBuilder_reallocate(str1);
    }
    str1->current_size++;
    strcat(str1->string,str2);
}

char* stringBuilder_toString(string_builder *str) {
    char *string = (char*) malloc(sizeof(char)*str->current_size);
    strcpy(string,str->string);
    return string;
}

void stringBuilder_deallocate(string_builder *stream) {
    free(stream->string);
    free(stream);
}