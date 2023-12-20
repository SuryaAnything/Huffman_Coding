//
// Created by surya on 20-12-2023.
//
#include "../include/bit_stream.h"
bit_stream* create_bitStream() {
    bit_stream *stream = malloc(sizeof(bit_stream));
    stream->byte = 0;
    stream->size = 0;
    return stream;
}

bool bitStream_isFull(bit_stream *stream) {
    return stream->size == 8;
}

void push_bit_right(bit_stream *stream, char bit) {
    char *stringBit = character_toString(bit);
    char x = (char)(atoi(stringBit));
    stream->byte = stream->byte << 1;
    stream->byte |= x;
    stream->size++;
    free(stringBit);
}

void clear_bitStream(bit_stream *stream) {
    stream->byte = 0;
    stream->size = 0;
}

void free_bitStream(bit_stream *stream) {
    free(stream);
}

unsigned char bitStream_getBit(bit_stream *stream) {
    return stream->byte;
}