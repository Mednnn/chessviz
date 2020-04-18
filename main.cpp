#include <fstream>
#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;

void PrintMas()
{
    cout << endl;
    int i, j;
    for (i = 0; i < 8; ++i) {
        cout << i + 1 << "|";
        for (j = 0; j < 8; ++j) {
            cout << mas[i][j] << " ";
        }

        cout << endl;
    }
    cout << " |_______________" << endl;
    cout << "  a b c d e f g h";
    cout << endl;
}

void getxy(string a, int& x, int& y, int& k, char f1, char f2)
{
    char b = a[k];
    while (b != f1 && b != f2) {
        switch (b <= 'h' && b >= 'a') {
        case true:
            x = (int)('h' - b + 1);
            break;
        default:
            break;
        }
        switch (b <= '8' && b >= '1') {
        case true:
            y = int(b) - 49;
            break;
        default:
            break;
        }
        k++;
        if (k < a.length)
            b = a[k];
    }
}

int main()
{
    PrintMas();
    int x1, x2, y1, y2;
    int k;
    string path = "input.txt";
    string str;
    ifstream fin;
    fin.open(path);
    int count = 0;
    while (!fin.eof()) {
        fin >> str;
        k = 0;
        getxy(str, x1, y1, k, '-', 'x');
        getxy(str, x2, y2, k, '#', ' ');
        y1 = (y1 - 7) * (-1);
        y2 = (y2 - 7) * (-1);
        mas[y2][x2] = mas[y1][x1];
        mas[y1][x1] = ' ';
        cout << endl << endl;
        cout << count / 2 + 1 << "." << str << endl;
        PrintMas();
        count++;
    }
    string b;
}
