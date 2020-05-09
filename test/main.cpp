#define CTEST_MAIN
#define CTEST_SEGFAULT
#include <ctest.h>
#include "board.h"

char** mas;
    


CTEST(coords, correct_paws) 
{
    ASSERT_TRUE(correct_move(2,4,2,4,mas));
}

CTEST(coords, incorrect_paws) 
{
    ASSERT_FALSE(correct_move(2,4,5,4,mas));
}

CTEST(coords, incorrect_rook) 
{
    ASSERT_FALSE(correct_move(8, 1, 8, 2,mas));
}

CTEST(coords, correct_knight) 
{
    ASSERT_TRUE(correct_move(8, 2, 6, 3,mas));
}

CTEST(coords, incorrect_knight) 
{
    ASSERT_FALSE(correct_move(8, 2, 7, 2,mas));
}

int main(int argc, const char** argv)
{
    mas = new char*[10];
    for (int i = 0; i < 10; i++)
        mas[i] = new char[10];
    board(mas);
    int result = ctest_main(argc, argv);
    return result;
}
