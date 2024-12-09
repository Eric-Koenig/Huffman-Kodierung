#include <stdio.h>
#include <string.h>
#include "huffman.h"
#include "io.h"
#include "huffman_common.h"

void IO_tests(void);
void printHelp(void);

Exit_Code main(int argc, char *argv[]) {
    Exit_Code Exit = Erfolgreiche_Ausführung;
    printf("Huffman-Kodierung\n");
    printHelp();
    if(argc == 1)
    {
        printf("Keine Argumente bereitgestellt\n");
        Exit = Fehler_in_den_Kommandozeilenargumenten;
    }


    return Exit;
}

/**
 * Methode um die Anwedungsbeschreibung ins Terminal auszugeben
 */
void printHelp()
{
    printf("Anwendung:\n");
    printf("huffman <options> <filename>\n");
    printf("Options:\n");
    printf("-c           Die Eingabedatei wird komprimiert.\n");
    printf("-d           Die Eingabedatei wird dekomprimiert.\n");
    printf("-l<level>    Legt den Level der Komprimierung fest. \n");
    printf("-v           Gibt Informationen über die Komprimierung bzw. Dekomprimierung aus\n");
    printf("-o <outfile> Name der Ausgabedatei.\n");
    printf("-h           Zeigt Diese Hilfe an. \n");
    printf("<filename>   Name der Eingabedatei\n");
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
