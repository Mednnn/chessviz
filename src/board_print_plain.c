#include "board_print_plain.h"

void PrintMas(char mas[10][10])
{
    int i, j;
    for (i = 0; i < 10; ++i) {
        for (j = 0; j < 10; ++j) {
            printf("%c", mas[i][j]);
        }
        printf("\n");
    }
}