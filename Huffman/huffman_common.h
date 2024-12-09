//
// Created by User on 24.11.2024.
//
#ifndef HUFFMAN_COMMON_H
#define HUFFMAN_COMMON_H

typedef enum
{
    BIT_0 = 0,
    BIT_1 = 1
} BIT;
typedef enum
{
    Erfolgreiche_Ausführung = 0,
    Unbekannter_Fehler = 1,
    Fehler_in_den_Kommandozeilenargumenten = 2,
    Datei_bzw_IO_Fehler = 3,
    Fehler_beim_Komprimieren_oder_Dekomprimieren = 4
}Exit_Code;
#endif //HUFFMAN_COMMON_H
