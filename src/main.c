#include "board.h"
#include "board_print_plain.h"

int main()
{
    char mas[10][10];
    board(mas);
    PrintMas(mas);
    chess_logic(mas);  
}