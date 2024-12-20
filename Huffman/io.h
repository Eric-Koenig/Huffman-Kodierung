//
// Created by User on 24.11.2024.
//

#ifndef IO_H
#define IO_H
#include <stdbool.h>
#include "huffman_common.h"
extern void init_in(char text[]);
extern void init_out();
extern void get_out_buffer(char text[]);
extern bool has_next_char(void);
extern unsigned char read_char(void);
extern void write_char(unsigned char c);
extern bool has_next_bit(void);
extern BIT read_bit(void);
extern void write_bit(BIT bit);
#endif //IO_H
