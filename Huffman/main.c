#include <stdio.h>
#include <string.h>
#include "huffman.h"
#include "io.h"
#include "huffman_common.h"

int main(void)
{
   printf("Huffman Huffman Code Code Example\n");
   char in[] = "aAbBcCdDeEfFgGhHiIjJkKlLmMnNoOpPqQrRsStTuUvVwWxX";
   char out[50] = {0};
   test_rd_chars_wr_bits(in, out);
   strcmp(out, "UUUUUU");
}
