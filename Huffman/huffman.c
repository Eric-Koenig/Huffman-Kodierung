//
// Created by User on 24.11.2024.
//

#include "huffman.h"
#include <stdio.h>
#include "io.h"
#include "huffman_common.h"
#include "stdbool.h"


/**
* soll die über Parameter in übergebenen Test-Daten in den Eingabepuffer
* des Moduls io bringen, dann in einer Schleife byteweise aus dem
Eingabepuffer lesen und für jedes gelesene Zeichen, dessen ASCII-Wert
kleiner ’a’ ist, ein 1-Bit in den Ausgabepuffer schreiben und für jedes
Zeichen, dessen ASCII-Wert größer oder gleich ’a’ ist, ein 0-Bit in den
Ausgabepuffer schreiben. Abschließend beschafft sich die Funktion über
das Modul io den Inhalt des Ausgabepuffers und stellt diesen über den
Parameter out bereit.

Ablauf meiner Implementierung:
1. init_out(): Logisches Leeren des Ausgabepuffers (Länge und Pointer auf Null setzen)
2. init_in(in): Schreibt das übergebene Array in den Eingabepuffer. Length setzen, Position nach Ablauf wieder zurücksetzen.
3. While Schleife: Bedingung has_next_char prüft ob der Pointer auf den eingabepuffer kleiner ist als dessen Länge
4. read_char
5. write_Bit
 * @param in Übergebenes Array mit den Ursprünglichen Char-Werten
 * @param out Ausgabe mit den Bit Werten
 */
extern void test_rd_chars_wr_bits(char in[], char out[])
{
    printf("test_rd_chars_wr_bits\n");
    init_out();
    init_in(in);
    while(has_next_char())
   {
     unsigned char a = read_char();
     if (a >= 'a')
     {
         write_bit(BIT_0);   //0101010
     } else
     {
          write_bit(BIT_1);
     }
 }
    get_out_buffer(out); // Problem
}

/**
* soll die über Parameter in übergebenen Test-Daten in den Eingabepuffer
des Moduls io bringen, dann in einer Schleife bitweise aus dem Eingabe
puffer lesen und für jedes gelesene 1-Bit das Zeichen ’1’ in den Aus
gabepuffer schreiben und für jedes gelesene 0-Bit das Zeichen ’0’ in den
Ausgabepuffer schreiben. Abschließend beschafft sich die Funktion den
Inhalt des Ausgabepuffers und stellt diesen über den Parameter out bereit
 * @param in Übergebenes Array mit Bits
 * @param out Ausgabe Bits als Chars
 */
extern void test_rd_bits_wr_chars(char in[], char out[])
{
    printf("test_rd_bits_wr_chars\n");
    init_out();
    init_in(in);
    while(has_next_bit())
    {
        BIT bit = read_bit();
        if(bit == BIT_1)
        {
            write_char('1');
        }
        else
        {
            write_char('0');
        }
    }
    get_out_buffer(out);

}