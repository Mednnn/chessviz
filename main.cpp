#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main() {
  int i, j;
  ifstream tf;
  string  a;
  tf.open("input.txt");
  char mas[8][8] = {{'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'},
                    {'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
                    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                    {'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
                    {'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'}};
  for (i = 0; i < 8; ++i) {
    for (j = 0; j < 8; ++j) {
      cout << mas[i][j];
    }
    cout << endl;
  }
  getline(tf,a);
  //cout << a;
  int x1,x2,y1,y2;
  bool oper;
  char b;
  int k = 0;
  while(b!='-' && b!='x'){
    b = a[k];
    switch(b <= 'h' && b >= 'a'){
    case true:
      x1 = (int)('h' - b + 1);
      cout << x1;
      break;
    }
    switch(b <='8' && b >= '1'){
    case true:y1 = int(b) - 48;cout << "-" << y1; break;
    }
	   
    k++;
  }
  cout << endl;
}

