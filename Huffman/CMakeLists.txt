cmake_minimum_required(VERSION 3.29)
project(PPR_A4 C)

set(CMAKE_C_STANDARD 11)

add_executable(PPR_A4 main.c
        huffman_common.c
        huffman_common.h
        io.c
        io.h
        huffman.c
        huffman.h)
