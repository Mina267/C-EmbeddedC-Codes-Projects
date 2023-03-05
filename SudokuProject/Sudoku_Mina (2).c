#include "sudokuProject.h"


static int TestArray[1][ARR_ROW][ARR_COL] =
{
{

{3, 1, 6, 5, 7, 8, 4, 9, 2},
{5, 2, 9, 1, 3, 4, 7, 8, 9},
{4, 8, 7, 6, 2, 9, 5, 3, 1},
{2, 6, 3, 4, 1, 5, 9, 8, 7},
{9, 7, 4, 8, 6, 3, 1, 2, 5},
{8, 5, 1, 7, 9, 2, 6, 4, 3},
{1, 3, 8, 9, 4, 7, 2, 5, 6},
{6, 9, 2, 3, 5, 1, 8, 7, 4},
{0, 4, 5, 2, 8, 6, 3, 1, 9}
}
};

static int LevelOneArrays[TOTAL_NIN_LEVEL][ARR_ROW][ARR_COL] =
{
    {   {8,2,6,4,0,9,5,0,0}
        ,{9,0,5,2,6,7,8,4,3}
        ,{4,3,7,1,5,0,0,6,2}
        ,{6,0,1,9,4,2,7,0,8}
        ,{7,9,2,5,0,3,6,1,4}
        ,{3,4,0,0,7,1,2,5,9}
        ,{1,6,4,8,9,5,3,2,7}
        ,{5,8,3,7,2,4,1,9,6}
        ,{2,7,0,3,1,6,4,8,5}
    }
    ,{   {6,0,0,0,0,0,0,0,5}
        ,{0,2,3,0,0,7,0,0,0}
        ,{0,7,5,0,1,0,3,2,8}
        ,{7,9,6,0,4,0,0,5,3}
        ,{0,8,0,0,3,0,1,4,0}
        ,{0,0,4,0,7,0,0,6,9}
        ,{1,5,0,0,9,0,0,0,0}
        ,{0,0,8,1,0,5,0,9,4}
        ,{4,6,0,0,2,3,5,0,1}
    }
    ,{   {5,0,0,1,0,0,0,0,6}
        ,{0,1,0,0,0,7,0,0,0}
        ,{0,0,8,9,0,2,0,5,0}
        ,{3,0,0,0,0,0,0,0,0}
        ,{0,0,2,0,8,1,6,0,0}
        ,{4,8,1,3,5,0,2,9,7}
        ,{1,9,0,0,0,0,4,6,2}
        ,{0,4,3,2,1,5,8,7,9}
        ,{8,0,0,0,9,0,3,0,5}
    }


}
;
static int LevelTwoArrays[TOTAL_NIN_LEVEL][ARR_ROW][ARR_COL] =
{
    {   {9,3,0,2,0,0,6,7,8}
        ,{0,0,0,4,7,0,0,0,2}
        ,{5,0,0,6,0,0,0,0,0}
        ,{0,0,8,0,0,0,2,0,0}
        ,{3,7,0,9,0,2,8,4,0}
        ,{0,5,2,0,4,0,0,1,0}
        ,{0,0,0,1,0,0,0,0,0}
        ,{0,8,5,7,0,9,0,0,0}
        ,{0,0,3,5,0,6,1,0,9}
    }
    ,{   {7,0,0,0,0,5,0,6,0}
        ,{6,8,0,2,0,0,0,9,0}
        ,{0,2,0,0,8,0,0,0,5}
        ,{0,0,9,7,0,0,0,8,0}
        ,{0,0,0,0,0,0,0,0,0}
        ,{2,6,0,1,0,8,3,0,0}
        ,{8,0,0,5,0,4,6,2,0}
        ,{4,0,0,9,7,0,0,0,8}
        ,{5,0,0,8,2,0,9,3,0}
    }
    ,{   {0,0,0,0,3,0,0,0,0}
        ,{0,1,3,4,0,8,9,0,0}
        ,{0,9,0,5,0,0,0,8,0}
        ,{4,0,0,0,9,0,2,0,5}
        ,{0,5,2,0,0,1,0,0,7}
        ,{6,0,0,2,0,5,4,0,0}
        ,{3,0,0,6,0,4,5,0,0}
        ,{0,2,7,0,0,0,6,0,9}
        ,{0,4,6,0,0,9,0,0,0}
    }
}
;

static int LevelThreeArrays[TOTAL_NIN_LEVEL][ARR_ROW][ARR_COL] =
{
    {   {1,0,0,4,0,0,0,9,0}
        ,{0,0,0,0,0,0,8,0,0}
        ,{0,8,0,9,0,4,5,0,0}
        ,{0,8,0,9,0,4,5,0,0}
        ,{0,1,4,8,0,0,2,0,0}
        ,{0,0,0,2,0,7,0,0,0}
        ,{0,2,0,0,6,0,0,0,9}
        ,{6,0,3,0,0,2,0,0,8}
        ,{0,7,0,0,0,0,0,0,3}
    }
    ,{   {0,0,4,1,0,0,3,9,0}
        ,{6,0,0,7,3,0,0,0,0}
        ,{0,0,0,0,0,0,0,4,7}
        ,{0,0,7,0,0,0,9,0,0}
        ,{2,0,0,0,0,5,0,1,0}
        ,{9,4,0,0,1,0,5,3,0}
        ,{7,0,0,0,0,0,4,2,0}
        ,{0,0,0,0,4,3,0,0,9}
        ,{0,0,3,9,0,8,0,0,0}
    }
    ,{   {0,3,0,2,6,0,8,0,0}
        ,{8,5,0,0,3,0,2,0,4}
        ,{0,0,2,0,4,0,0,7,0}
        ,{0,0,1,0,0,0,0,0,0}
        ,{0,0,0,9,0,1,0,8,0}
        ,{4,8,0,3,0,0,0,0,7}
        ,{3,0,7,0,0,2,0,0,0}
        ,{0,9,0,6,0,0,0,0,0}
        ,{2,0,0,0,0,5,1,0,0}
    }


}
;


// Select array as user choice to copy
void sudoku_userChoice(choice)
{

    // Make random number. So, every time new grid appear
    srand(time(NULL));
    int random_number = (rand() % (TOTAL_NIN_LEVEL - 1 + 1)) + 1;

    switch(choice)
    {
    case 1:
        sudoku_chosen(LevelOneArrays, random_number - 1);
        Solve_sudoku();
        break;
    case 2:
        sudoku_chosen(LevelTwoArrays, random_number - 1);
        Solve_sudoku();
        break;
    case 3:
        sudoku_chosen(LevelThreeArrays, random_number - 1);
        Solve_sudoku();
        break;
    case 4:
        sudoku_chosen(TestArray, 0);
        Solve_sudoku();
        break;
    }
}


// Copy sudoku selected by player.
void sudoku_chosen(int sudoku_data[][ARR_ROW][ARR_COL], int Array_num)
{

    if(sudoku_data == 0)
    {return ;}

    NumOfCellTofill = 0;
    for(int rowIndex = FIRSTROW_INDEX; rowIndex < ARR_ROW; rowIndex++)
    {

        for (int colIndex = FIRSTCOL_INDEX; colIndex < ARR_COL; colIndex++)
        {

            // Mark original place of number in sudoku grid
            if (sudoku_data[Array_num][rowIndex][colIndex] != 0)
            {
                check_array[rowIndex][colIndex] = 1;
            }
            else
            {
                check_array[rowIndex][colIndex] = 0;
                NumOfCellTofill++;
            }

            sudoku[rowIndex][colIndex] = sudoku_data[Array_num][rowIndex][colIndex];
        }
    }

}


