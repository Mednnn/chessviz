#include "board.h"
void board(char** mas)
{
    for (int i = 0; i <= 9; i++) {
        for (int j = 0; j <= 9; j++)
            mas[i][j] = ' ';
    }

    mas[0][1] = 'a';
    mas[0][2] = 'b';
    mas[0][3] = 'c';
    mas[0][4] = 'd';
    mas[0][5] = 'e';
    mas[0][6] = 'f';
    mas[0][7] = 'g';
    mas[0][8] = 'h';

    mas[9][1] = 'a';
    mas[9][2] = 'b';
    mas[9][3] = 'c';
    mas[9][4] = 'd';
    mas[9][5] = 'e';
    mas[9][6] = 'f';
    mas[9][7] = 'g';
    mas[9][8] = 'h';

    mas[1][0] = '8';
    mas[2][0] = '7';
    mas[3][0] = '6';
    mas[4][0] = '5';
    mas[5][0] = '4';
    mas[6][0] = '3';
    mas[7][0] = '2';
    mas[8][0] = '1';

    mas[1][9] = '8';
    mas[2][9] = '7';
    mas[3][9] = '6';
    mas[4][9] = '5';
    mas[5][9] = '4';
    mas[6][9] = '3';
    mas[7][9] = '2';
    mas[8][9] = '1';

    mas[1][1] = 'r';
    mas[1][2] = 'n';
    mas[1][3] = 'b';
    mas[1][4] = 'q';
    mas[1][5] = 'k';
    mas[1][6] = 'b';
    mas[1][7] = 'n';
    mas[1][8] = 'r';

    mas[8][1] = 'R';
    mas[8][2] = 'N';
    mas[8][3] = 'B';
    mas[8][4] = 'Q';
    mas[8][5] = 'K';
    mas[8][6] = 'B';
    mas[8][7] = 'N';
    mas[8][8] = 'R';

    mas[2][1] = 'p';
    mas[2][2] = 'p';
    mas[2][3] = 'p';
    mas[2][4] = 'p';
    mas[2][5] = 'p';
    mas[2][6] = 'p';
    mas[2][7] = 'p';
    mas[2][8] = 'p';

    mas[7][1] = 'P';
    mas[7][2] = 'P';
    mas[7][3] = 'P';
    mas[7][4] = 'P';
    mas[7][5] = 'P';
    mas[7][6] = 'P';
    mas[7][7] = 'P';
    mas[7][8] = 'P';
}

bool correct_move(int y1, int x1, int y2, int x2, char** mas)
{
    if (mas[y1][x1] == 'p') {
        if (mas[y2][x2] == ' ' && x1 == x2 && abs(y2 - y1) <= 2) {
            mas[y2][x2] = mas[y1][x1];
            mas[y1][x1] = ' ';
            return 1;
        }
        if (mas[y2][x2] != ' ' && mas[y2][x2] >= 65 && mas[y2][x2] <= 90
            && ((y1 - 1 == y2 && x1 - 1 == x2)
                || (y1 - 1 == y2 && x1 + 1 == x2))) {
            mas[y2][x2] = mas[y1][x1];
            mas[y1][x1] = ' ';
            return 1;
        }
        return 0;
    }
    if (mas[y1][x1] == 'P') {
        if (mas[y2][x2] == ' ' && x1 == x2 && abs(y2 - y1) <= 2) {
            mas[y2][x2] = mas[y1][x1];
            mas[y1][x1] = ' ';
            return 1;
        }
        if (mas[y2][x2] != ' ' && mas[y2][x2] >= 97 && mas[y2][x2] <= 122
            && ((y1 + 1 == y2 && x1 - 1 == x2)
                || (y1 + 1 == y2 && x1 + 1 == x2))) {
            mas[y2][x2] = mas[y1][x1];
            mas[y1][x1] = ' ';
            return 1;
        }
        return 0;
    }
    if (mas[y1][x1] == 'r') {
        if (mas[y2][x2] == ' ' && (x1 == x2 || y1 == y2)) {
            mas[y2][x2] = mas[y1][x1];
            mas[y1][x1] = ' ';
            return 1;
        }
        if (mas[y2][x2] != ' ' && mas[y2][x2] >= 65 && mas[y2][x2] <= 90
            && (x1 == x2 || y1 == y2)) {
            mas[y2][x2] = mas[y1][x1];
            mas[y1][x1] = ' ';
            return 1;
        }
        return 0;
    }
    if (mas[y1][x1] == 'R') {
        if (mas[y2][x2] == ' ' && (x1 == x2 || y1 == y2)) {
            mas[y2][x2] = mas[y1][x1];
            mas[y1][x1] = ' ';
            return 1;
        }
        if (mas[y2][x2] != ' ' && mas[y2][x2] >= 97 && mas[y2][x2] <= 122
            && (x1 == x2 || y1 == y2)) {
            mas[y2][x2] = mas[y1][x1];
            mas[y1][x1] = ' ';
            return 1;
        }
        return 0;
    }
    if (mas[y1][x1] == 'n') {
        if (mas[y2][x2] == ' ' && (pow(x2 - x1, 2) + pow(y2 - y1, 2)) == 5) {
            mas[y2][x2] = mas[y1][x1];
            mas[y1][x1] = ' ';

            return 1;
        }
        if (mas[y2][x2] != ' ' && mas[y2][x2] >= 65 && mas[y2][x2] <= 90
            && (pow(x2 - x1, 2) + pow(y2 - y1, 2)) == 5) {
            mas[y2][x2] = mas[y1][x1];
            mas[y1][x1] = ' ';

            return 1;
        }
        return 0;
    }
    if (mas[y1][x1] == 'N') {
        if (mas[y2][x2] == ' ' && (pow(x2 - x1, 2) + pow(y2 - y1, 2)) == 5) {
            mas[y2][x2] = mas[y1][x1];
            mas[y1][x1] = ' ';

            return 1;
        }
        if (mas[y2][x2] != ' ' && mas[y2][x2] >= 97 && mas[y2][x2] <= 122
            && (pow(x2 - x1, 2) + pow(y2 - y1, 2)) == 5) {
            mas[y2][x2] = mas[y1][x1];
            mas[y1][x1] = ' ';
            return 1;
        }
        return 0;
    }
    if (mas[y1][x1] == 'b') {
        if (mas[y2][x2] == ' ' && abs(y2 - y1) == abs(x2 - x1)) {
            mas[y2][x2] = mas[y1][x1];
            mas[y1][x1] = ' ';
            return 1;
        }
        if (mas[y2][x2] != ' ' && mas[y2][x2] >= 65 && mas[y2][x2] <= 90
            && abs(y2 - y1) == abs(x2 - x1)) {
            mas[y2][x2] = mas[y1][x1];
            mas[y1][x1] = ' ';
            return 1;
        }
        return 0;
    }
    if (mas[y1][x1] == 'B') {
        if (mas[y2][x2] == ' ' && abs(y2 - y1) == abs(x2 - x1)) {
            mas[y2][x2] = mas[y1][x1];
            mas[y1][x1] = ' ';
            return 1;
        }
        if (mas[y2][x2] != ' ' && mas[y2][x2] >= 97 && mas[y2][x2] <= 122
            && abs(y2 - y1) == abs(x2 - x1)) {
            mas[y2][x2] = mas[y1][x1];
            mas[y1][x1] = ' ';
            return 1;
        }
        return 0;
    }
    if (mas[y1][x1] == 'q') {
        if (mas[y2][x2] == ' '
            && (x1 == x2 || y1 == y2 || (abs(y2 - y1) == abs(x2 - x1)))) {
            mas[y2][x2] = mas[y1][x1];
            mas[y1][x1] = ' ';
            return 1;
        }
        if (mas[y2][x2] != ' '
            && (x1 == x2 || y1 == y2 || (abs(y2 - y1) == abs(x2 - x1)))
            && mas[y2][x2] >= 65 && mas[y2][x2] <= 90) {
            mas[y2][x2] = mas[y1][x1];
            mas[y1][x1] = ' ';
            return 1;
        }
        return 0;
    }
    if (mas[y1][x1] == 'Q') {
        if (mas[y2][x2] == ' '
            && (x1 == x2 || y1 == y2 || (abs(y2 - y1) == abs(x2 - x1)))) {
            mas[y2][x2] = mas[y1][x1];
            mas[y1][x1] = ' ';
            return 1;
        }
        if (mas[y2][x2] != ' '
            && (x1 == x2 || y1 == y2 || (abs(y2 - y1) == abs(x2 - x1)))
            && mas[y2][x2] >= 97 && mas[y2][x2] <= 122) {
            mas[y2][x2] = mas[y1][x1];
            mas[y1][x1] = ' ';
            return 1;
        }
        return 0;
    }
    if (mas[y1][x1] == 'k') {
        if (mas[y2][x2] == ' ' && (abs(y2 - y1) == 1 || abs(x2 - x1) == 1)) {
            mas[y2][x2] = mas[y1][x1];
            mas[y1][x1] = ' ';
            return 1;
        }
        if (mas[y2][x2] != ' ' && (abs(y2 - y1) == 1 || abs(x2 - x1) == 1)
            && mas[y2][x2] >= 65 && mas[y2][x2] <= 90) {
            mas[y2][x2] = mas[y1][x1];
            mas[y1][x1] = ' ';
            return 1;
        }
        return 0;
    }
    if (mas[y1][x1] == 'K') {
        if (mas[y2][x2] == ' ' && (abs(y2 - y1) == 1 || abs(x2 - x1) == 1)) {
            mas[y2][x2] = mas[y1][x1];
            mas[y1][x1] = ' ';
            return 1;
        }
        if (mas[y2][x2] != ' ' && (abs(y2 - y1) == 1 || abs(x2 - x1) == 1)
            && mas[y2][x2] >= 97 && mas[y2][x2] <= 122) {
            mas[y2][x2] = mas[y1][x1];
            mas[y1][x1] = ' ';
            return 1;
        }
        return 0;
    }
    return 0;
}