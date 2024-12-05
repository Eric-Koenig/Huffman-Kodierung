#include <stdio.h>
#include <string.h>
#include "huffman.h"
#include "io.h"
#include "huffman_common.h"

void IO_tests(void);

int main(void)
{
    IO_tests();

}

/**
 *
 * Tests für die Aufgaben zur Abgabe 1
 */
void IO_tests(void)
{
    printf("Huffman Huffman Code Code Example\n");
    char in[] = "aAbBcCdDeEfFgGhHiIjJkKlLmMnNoOpPqQrRsStTuUvVwWxX";
    char out[50] = {0};
    test_rd_chars_wr_bits(in, out);
    printf("%s\n", out);
    char out2[50] = {0};
    char in2[] = "abCdefGHijKlmnOPqrStuvWXyzAbcdEF";
    test_rd_chars_wr_bits(in2, out2);
    printf("%s\n", out2);
    char in3[] = "1234567890";
    char out3[90] = {0};
    test_rd_bits_wr_chars(in3, out3);
    printf("%s\n", out3);
    char in4[] = "0192837465";
    char out4[90] = {0};
    test_rd_bits_wr_chars(in4, out4);
    printf("%s\n", out4);
}
