//
// Created by surya on 13-12-2023.
//
#include <windows.h>
#include <stdio.h>
#include "../include/dynamic_heap.h"
#include "../include/bit_stream.h"

int main() {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    FILE *fptr1 = fopen("../temp/input/string.txt","r");
    if (fptr1==NULL) {
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
        printf("Error: File could not be opened");
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE); // Reset color

        return 1;
    }

    string_builder *text_stream= build_new_string();
    char character;
    while ((character = (char)fgetc(fptr1)) != EOF) {
        char *s = character_toString(character);
        append_string(text_stream, s);
        free(s);
    }

    char *text = stringBuilder_toString(text_stream);
    stringBuilder_deallocate(text_stream);
    FILE *fptr2 = fopen("../temp/output/output.txt","w+");
    if (fptr2==NULL) {
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
        printf("Error: File could not be opened");
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE); // Reset color

        return 1;
    }
    map_char *map = map_char_init();
    for (int i = 0; text[i]!='\0' ; ++i) {
        if (map_char_containsKey(map, text[i])) {
            map_char_setValue(map,text[i], map_char_getValue(map,text[i])+1);
        }
        else {
            map_char_setValue(map, text[i], 1);
        }
    }
    printf("\nText taken: -\n\n");
    map_char_printMap(map);
    heap *hptr = heap_initializer();
    for (int i = 0; i < 128; ++i) {
        if (map_char_containsKey(map,(char)i)) {
            node_t *nptr = creat_new_node(map_char_getValue(map,(char)i), character_toString((char)i));
            insert_heap(hptr, nptr);
            free(nptr);
        }
    }

    printf("\n\n\nCreating Tree.....\n\n\n");

    while (hptr->current_size>1) {
        node_t *first = remove_heap(hptr);
        node_t *second = remove_heap(hptr);
        node_t *joined = join_node(first, second);
        insert_heap(hptr,joined);
        free(first);
        free(second);
        free(joined);
    }
    node_t *root = remove_heap(hptr);
    heap_deallocate(hptr);
    int max_size = 0;
    for (int i = 0; i < 128; ++i) {
        if (map_char_containsKey(map,(char)i)) {
            string_builder *temp = build_new_string();
            get_binary_equivalent(root,(char)i,temp);
            if (max_size<temp->current_size)
                max_size = temp->current_size;
            char *s_temp = stringBuilder_toString(temp);
            map_char_setValue(map,(char)i, atoi(s_temp));
            free(s_temp);
        }
    }
    unsigned long long  total_size = max_size* strlen(text);
    map_char_printMap(map);
    printf("\nGenerating...");

    char *string = (char*)calloc(total_size, sizeof(char));
    string[0] = '\0';
    for (int i = 0; text[i]!='\0' ; ++i) {
        if (i%10000==0)
            printf(".");
        int bin = map_char_getValue(map,text[i]);
        snprintf(string,total_size,"%s%d",string,bin);
    }

    printf("\n<Done>\n");

    //printf("String : %s",string);//"0010010101001"
    bit_stream *stream = create_bitStream();
    printf("\n\nBit stream Created:-");
    for (int i = 0; string[i]!='\0' ; ++i) {
        char ch = string[i];
        if (bitStream_isFull(stream)){
            fprintf(fptr2,"%c", bitStream_getBit(stream));
            clear_bitStream(stream);
            push_bit_right(stream, ch);
        }
        else {
            push_bit_right(stream, ch);
        }
    }
    fprintf(fptr2,"%c  ", bitStream_getBit(stream));

    clear_bitStream(stream);
    free_bitStream(stream);
    printf("\n\n\nFinal Flag : Success\n\n\n");

}