#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
using namespace std;

char mas[8][8] = {{'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'},
                  {'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
                  {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                  {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                  {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                  {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                  {'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
                  {'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'}};

void PrintMas()
{
    cout << endl;
    int i, j;
    for (i = 0; i < 8; ++i) {
        for (j = 0; j < 8; ++j) {
            cout << mas[i][j];
        }

        cout << endl;
    }
    cout << endl;
}

void getxy(string a, int& x, int& y, int& k, char f1, char f2)
{
    char b;
    while (b != f1 && b != f2) {
        b = a[k];
        switch (b <= 'h' && b >= 'a') {
        case true:
            x = (int)('h' - b + 1);
            break;
        }
        switch (b <= '8' && b >= '1') {
        case true:
            y = int(b) - 49;
            break;
        }

        k++;
    }
}

int main()
{
    int i, j;
    bool end = false;
    PrintMas();
    int x1, x2, y1, y2;
    bool oper;
    int k;
    string path = "input.txt";
    string str;
    ifstream fin;
    fin.open(path);
    while (!fin.eof()) {
        fin >> str;
        k = 0;
        getxy(str, x1, y1, k, '-', 'x');
        getxy(str, x2, y2, k, '#', ' ');
        y1 = (y1 - 7) * (-1);
        y2 = (y2 - 7) * (-1);
        mas[y2][x2] = mas[y1][x1];
        mas[y1][x1] = ' ';
        PrintMas();
    }
}
