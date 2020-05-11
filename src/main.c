#include "board.h"
#include "board_print_plain.h"
#include <stdio.h>
#include <stdlib.h>
int  x_1,x_2,y_1,y_2,k;

int getxy(char a[20],char f1, char f2,int mode)
{
    char b;
    
    b = a[k];
    for (int i = 0; i < 3; ++i) {
        if(b <= 'h' && b >= 'a'){
            if(mode == 1) x_1 = (int)(-1 * ('a' - b)) + 1;
            else x_2 = (int)(-1 * ('a' - b)) + 1;
        }        
        if(b <= '8' && b >= '1'){
            if(mode == 1) y_1 = (int)((int)b - 49);
            else y_2 = (int)b - 49;
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
    char mas[10][10];
    board(mas);
   // printf("board\n");
    PrintMas(mas);
   // printf("print\n");
    // string path = "input.txt";
    
    FILE *fin;
    if((fin = fopen("src/input.txt","r")) == NULL){
        printf("Cannot open file\n");
    }
    fseek(fin,0,SEEK_END);
    int size_t = ftell(fin);
    fseek(fin,0,SEEK_SET);
    char str[size_t];
    //printf("fin\n");
    /*if (!fin.is_open()) {
        cout << "файл не найден";
        return 0;
    }*/
    //fread(str,sizeof(char),7,fin);
    //printf("fgets\n");
    int count = 0;
    fread(str,sizeof(char),size_t,fin);
    printf("%s",str);
    k = 0;
    while(k<=size_t){
        printf("\n\n");
        printf("%d",(int)(count / 2) + 1);
        printf(".");
        end = getxy(str, '-', 'x',1);
        end = getxy(str, '#', ' ',2);
        y_1 = (y_1 - 8) * (-1);
        y_2 = (y_2 - 8) * (-1);    
        //mas[y_2][x_2] = mas[y_1][x_1];
        //mas[y_1][x_1] = ' ';
        correct_move(y_1,x_1,y_2,x_2,mas);
        for(int i = k - 6; i < k ; ++i) printf("%c",str[i]);
        printf("\n");
        PrintMas(mas);
        count++;
        if (end == 1)
            return 0;
    }   
    
}