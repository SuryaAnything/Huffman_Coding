cmake_minimum_required(VERSION 3.10)
project(StringCompression C)

set(CMAKE_C_STANDARD 11)

set(SOURCES src/main.c
        link/binary_tree.c
        link/bit_stream.c
        link/build_string.c
        link/char_map.c
        link/comparable.c
        link/dynamic_heap.c)

add_executable(target ${SOURCES})