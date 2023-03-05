#include "sudokuProject.h"

int NumOfCellTofill;
static int curr_NumCellFilled = 0;
int check_array[ARR_ROW][ARR_COL];
int sudoku[ARR_ROW][ARR_COL];

// Running of Game
void sudoku_start(void)
{
    while(1)
    {
        Start_menu();
    }
}



// choice level player want to play.
void Start_menu()
{
    system("cls");
    int choice;

    Consol_cord(100, 8);
    printf(WHTB UBLK BRED "MAIN MENU\n"COLOR_RESET);
    Consol_cord(98, 12);
    printf(BYEL"1- beginner.\n");
    Consol_cord(98, 14);
    printf("2- intermediate.\n");
    Consol_cord(98, 16);
    printf("3- profissional.\n");
    printf("\n\n");
    Consol_cord(98, 18);
    printf("4- test.\n"COLOR_RESET);
    printf("\n\n");


    // if user Enter number not between 1 and 3 ask again
    do
    {
        printf("%20cEnter your choice here: ",' ');
        scanf("%d", &choice);
        CLEAR_LINE_ANDUP
        CLEAR_LINEON
    }
    while (choice < MIN_NUMOFCHOICE || choice > MAX_NUMOFCHOICE);


    // initialize current number of correct choice to zero.
    curr_NumCellFilled = 0;
    // Send choice to take from saved array.
    sudoku_userChoice(choice);



}

// Take user answer to play
void Solve_sudoku(void)
{

    system("cls");
    print_loading();
    sudoku_print(sudoku);

    int solved = 0;

    // Ask user for answer till grid is solved
    while(!solved)
    {
        solved = Take_ans();
    }

    // function when user win.
    sudoku_Winner();
}

// Take user answer And check of it
// check if game is end or not
// Yes return 1, no return 0
int Take_ans(void)
{
    int row;
    int col;
    int num;
    int isFinished;

    printf(GRN"       Please Enter Row: ");
    scanf("%d", &row);
    printf("       Please Enter Col.: ");
    scanf("%d", &col);

    row = row - 1;
    col = col -1;


    // check if user Enter write col And Row
    if(row > ARR_ROW || col > ARR_COL || row < 0 || col < 0)
    {
        CLEAR_LINES
        printf(BRED"%40cError can not place that number!\a"COLOR_RESET,' ');
        sleep(1);
        CLEAR_LINEON
        return 0;
    }

    // Take number player want to put.
    printf("       Please number number: ");
    scanf("%d", &num);
    printf(COLOR_RESET);


    // Check if we can put number in that cell in grid or not
    if (check_array[row][col] != 1)
    {
        if (check_cell(row, col, num))
        {
            sudoku[row][col] = num;
            sudoku_print(sudoku);
            isFinished = sudoku_isfinish(row, col);
            return isFinished;
        }
        else
        {
            CLEAR_LINES
            printf(BRED"%45cWrong number!\a"COLOR_RESET,' ');
            sleep(1);
            CLEAR_LINEON
            return 0;
        }
    }
    else
    {
        CLEAR_LINES
        printf(BRED"%40cError can not place that number!\a"COLOR_RESET,' ');
        sleep(1);
        CLEAR_LINEON
        return 0;
    }

}


// Check if player finish and win or not
// Yes return 1, no return 0
int sudoku_isfinish(int row, int col)
{

    if (check_array[row][col] == 0)
    {
        curr_NumCellFilled++;
        check_array[row][col] = -1;
    }

    if (curr_NumCellFilled == NumOfCellTofill)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}




// Check if player put in cell valid number or not
// Yes return 1, no return 0
int check_cell(int row, int col, int num)
{

    if (num < 0 || num > 9)
    {
        return 0;
    }
    else if (sudoku[row][col] == num)
    {
        return 1;
    }


    for (int i = FIRSTROW_INDEX; i < ARR_ROW; i++)
    {

        // Check if we find the same num in the row return 0.
        if (sudoku[row][i] == num)
        {
            return 0;
        }
        // Check if we find the same num in the col return 0.
        if (sudoku[i][col] == num)
        {
            return 0;
        }
    }

    // Check if 3*3 matrix contain that number;
    int startRow = row - row % 3;
    int startCol = col - col % 3;

    for (int rowIndex = 0; rowIndex < END_SMALLMATRIX; rowIndex++)
    {
        for (int colIndex = 0; colIndex < END_SMALLMATRIX; colIndex++)
        {
            if (sudoku[rowIndex + startRow][colIndex + startCol] == num)
                return 0;
        }
    }
    return 1;

}





// Print sudoku grid
void sudoku_print(int sudoku[][ARR_COL])
{
    if (sudoku == 0)
    {return ;}

    system("cls");
    printf("\n\n\n\n");
    printf("%40c", ' ');
    printf(MAG"    1  2  3   4  5  6   7  8  9\n");
    printf(YEL"%42c-------------------------------\n",' ');
    // Print row of sudoku.
    for(int rowIndex = FIRSTROW_INDEX; rowIndex < ARR_ROW; rowIndex++)
    {
        printf("%40c", ' ');
        printf(MAG"%d "YEL"|", rowIndex + 1);
        // Print col of sudoku.
        for (int colIndex = FIRSTCOL_INDEX; colIndex < ARR_COL; colIndex++)
        {
            if (check_array[rowIndex][colIndex] == 1)
            {
                printf(COLOR_RESET"%2d ", sudoku[rowIndex][colIndex]);
            }
            else
            {
                printf(CYN"%2d "COLOR_RESET, sudoku[rowIndex][colIndex]);
            }


            // Put boarder between numbers
            if ((colIndex + 1) % 3 == 0)
            {
                printf(YEL"|");
            }
        }
        // Add new line after three rows
        if ((rowIndex + 1) % 3 == 0)
        {
            printf("\n%40c", ' ');
            printf(YEL"  -------------------------------\n"COLOR_RESET);
        }
        else
            printf("\n");
    }
    printf("\n\n");

}



// check if player win or not
// Yes return 1, no return 0
int sudoku_Winner()
{
    int ans;
    for(int flashingIndex = 0; flashingIndex <= MAX_NUMOFWINNERFLASH; flashingIndex++)
    {
        if (flashingIndex % 2)
            printf(BGRN"%39c congratulations you are WINNER!"COLOR_RESET,' ');

        delay(30);
        CLEAR_LINEON
    }

    system("cls");
    printf(BHYEL"\n\n\n\n\n%40cYou want to Play New game?!\n"COLOR_RESET, ' ');


    do
    {
        printf(BHRED"%45c 1- Yes   2-No: "COLOR_RESET, ' ');
        scanf("%d", &ans);
        CLEAR_LINE_ANDUP
        CLEAR_LINEON
    }
    while (ans < INPUTYES || ans > INPUTNO);

    // EXIT when player press "No".
    if (ans == INPUTNO)
    {
        system("cls");
        exit(0);
    }
}




// print loading on screen.
void print_loading()
{
    for(int flashingIndex = 0; flashingIndex <= MAXNUM_LOADINGFLASH; flashingIndex++)
    {
        Consol_cord(98, 14);
        printf(YEL"Loading %d%%", flashingIndex);
        delay(3);
        CLEAR_LINEON
    }
}

// Delay some time
void delay(int number_of_seconds)
{
    // Converting time into milli_seconds
    int milli_seconds = 10 * number_of_seconds;

    // Storing start time
    clock_t start_time = clock();

    // looping till required time is not achieved
    while (clock() < start_time + milli_seconds);
}

// print is specific location on console.
void Consol_cord(int x, int y)
{
    COORD coord;
    coord.X = x / 2;
    coord.Y = y / 2;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}



