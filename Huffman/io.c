//
// Created by User on 24.11.2024.
//
#include "io.h"
#include <stdbool.h>
#include "huffman_common.h"
#define BUF_SIZE 4096
#define GET_BIT(BYTE,POS)((BYTE >> POS) & 1; Return BYTE;)
/**
 * 1. Bitmaske erschaffen wo nur das Bit an POS 1 ist --> invertieren = Nur Bit an
 * POS ist null -> Verundung = Löschen des Bits
 * 2. Bit auf Postion gesetzt -> Veroderung = Update
 * @param BYTE Byte wo geschrieben werden soll
 * @param BIT Wert der eingefügt werden soll
 * @param POS Bit das verändert werden soll.
 */
#define PUT_BIT(BYTE,BIT,POS)(BYTE = BYTE & ~(1 << POS); BYTE = BYTE | (BIT << POS); Return BYTE;)

static unsigned char in_buffer[BUF_SIZE];
static unsigned char out_buffer[BUF_SIZE];

extern void init_in(char text[])
{

}
extern void init_out()
{

}
extern void get_out_buffer(char text[])
{

}
extern bool has_next_char(void)
{

}
extern unsigned char read_char(void)
{

}
extern void write_char(unsigned char c)
{

}
extern bool has_next_bit(void)
{

}
extern BIT read_bit(void)
{

}
extern void write_bit(BIT c)
{

}
