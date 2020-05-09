#include <iostream>
using namespace std;


void PrintMas(char **mas)
{
    int i, j;
    for (i = 0; i < 10; ++i) {
        for (j = 0; j < 10; ++j) {
            cout << mas[i][j];
        }
        cout << endl;
    }
}