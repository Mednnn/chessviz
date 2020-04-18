#include "board.h"
#include "board_print_plain.h"
#include <fstream>
#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;

int getxy(string a, int& x, int& y, int& k, char f1, char f2)
{
    char b;
    b = a[k];
    for (int i = 0; i < 3; ++i) {
        switch (b <= 'h' && b >= 'a') {
        case true:
            x = (int)(-1 * ('a' - b)) + 1;
            cout << x << " ";
            break;
        }
        switch (b <= '8' && b >= '1') {
        case true:
            y = int(b) - 49;
            cout << y << endl;
            break;
        }
        k++;
        b = a[k];
        if (b == '#')
            return 1;
    }

    return 0;
}

int main()
{
    int end = 0;
    char** mas;
    mas = new char*[10];
    for (int i = 0; i < 10; i++)
        mas[i] = new char[10];
    board(mas);
    PrintMas(mas);
    int x1, x2, y1, y2;
    int k;
    string path = "../input.txt";
    string str;
    ifstream fin;
    fin.open(path);
    int count = 0;
    while (!fin.eof()) {
        fin >> str;
        k = 0;
        end = getxy(str, x1, y1, k, '-', 'x');
        end = getxy(str, x2, y2, k, '#', ' ');
        y1 = (y1 - 8) * (-1);
        y2 = (y2 - 8) * (-1);

        mas[y2][x2] = mas[y1][x1];
        mas[y1][x1] = ' ';
        cout << endl << endl;
        cout << count / 2 + 1 << "." << str << endl;
        PrintMas(mas);
        count++;
        if (end == 1)
            break;
    }
    string b;
}