//
// Created by User on 24.11.2024.
//
#include "io.h"
#include <stdbool.h>
#include <stdio.h>

#include "huffman_common.h"
#define BUF_SIZE 4096
#define GET_BIT(BYTE,POS)((BYTE >> POS) & 1);

/**
 * 1. Bitmaske erschaffen wo nur das Bit an POS 1 ist --> invertieren = Nur Bit an
 * POS ist null -> Verundung = Löschen des Bits
 * 2. Bit auf Postion gesetzt -> Veroderung = Update
 *
 *   BYTE = 1010 1010
 *   1 = 0000 0001
 *   1 << 5 = 0010 0000
 *   ~ = 1101 1111
 *
 *   1010 1010
 *  &1101 1111
 *   1000 1010
 *
 * @param BYTE Byte wo geschrieben werden soll
 * @param BIT Wert der eingefügt werden soll
 * @param POS Bit das verändert werden soll.
 */
#define PUT_BIT(BYTE,BIT,POS)(BYTE = ((BYTE & ~(1 << (POS))) | ((BIT & 1) << (POS))));

static unsigned char in_buffer[BUF_SIZE];
static unsigned char out_buffer[BUF_SIZE];
// Lese/Schreibposition
static unsigned int out_pos = 0;
static unsigned int in_pos = 0;
// Füllstand
static unsigned int out_len = 0;
static unsigned int in_len = 0;
//Bitweises lesen
static unsigned int bit_in = 7;
static unsigned int bit_out = 7;

static unsigned int in_BitAnzahl;

/**
* Übergebendes Array in den Eingabepuffer schreiben Schleife
* Position auf Null setzen
*Bit-Anzahl als Variabel speichern.
* @param text = Übergebener Inhalt der in den Eingabepuffer geschrieben wird.
*/
extern void init_in(char text[])
{
    in_len = 0;
    in_pos = 0;
    while (text[in_pos] != '\0')
    {
        in_buffer[in_pos] = text[in_pos];
        in_len++;
        in_pos++;
    }
    in_pos = 0;
    in_BitAnzahl = in_len * 8;
}

/**
 * Logisches leeren = Zurücksätzen Länge und Positions-Pointer
 */
extern void init_out()
{
    out_pos = 0;
    out_len = 0;
}

/**
 * Einfache Schleife über den Ausgabepuffer
 * @param text = Array in as der Ausgabepuffer geschriben wird
 */
extern void get_out_buffer(char text[])
{
    int i;
    out_pos = 0;
    for (i = out_pos; i < out_len; i++)
    {
        text[out_pos] = out_buffer[out_pos];
        out_pos++;
    }
}

/**
 * Prüft ob bis ans Ende des Array itteriert wurde
 * @return in_pos < in_len
 */
extern bool has_next_char(void)
{
    return in_pos < in_len;
}

/**
 * Char lesen und Position erhöhen
 * @return Char
 */
extern unsigned char read_char(void)
{
    unsigned char c = in_buffer[in_pos];
    in_pos++;
    return c;
}

/**
 * C in den Ausgabepuffer schreiben und Position und Länge um eins erhöhen.
 * @param c
 */
extern void write_char(unsigned char c)
{
    out_buffer[out_pos] = c;
    out_pos++;
    out_len++;
}

/**
 * Next bit wird einfach über eine Counter bestimmt
 * @return ob der Counter null noch nicht erreicht hat
 */
extern bool has_next_bit(void)
{
    return in_BitAnzahl > 0; ///???
}

/**
 * Liest ein Bit und zählt bis 8 um ins nächste Byte (Char) zu wechseln
 * @return ein Bit
 */
extern BIT read_bit(void)
{
    BIT bit = GET_BIT(in_buffer[in_pos], bit_in)

    in_BitAnzahl--;
    bit_in--;
    if (bit_in == -1)
    {
        in_pos++;
        bit_in = 7;
    }
    return bit;
}

/**
 * Bit schreiben. Anzahl mitzählen um Byte (Position) zu wechseln
 * @param c Bit das in den Ausgabepuffer geschrieben wird.
 */
extern void write_bit(BIT c)
{
    PUT_BIT(out_buffer[out_pos], c, bit_out)
    bit_out--;
    if (bit_out == -1)
    {
        out_pos++;
        out_len++;
        bit_out = 7;
    }
}
