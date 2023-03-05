#ifndef sudoku_H_
#define sudoku_H_

#define ARR_ROW (9)
#define ARR_COL (9)
#define FIRSTROW_INDEX       0
#define FIRSTCOL_INDEX       0
#define TOTAL_NIN_LEVEL      3
#define END_SMALLMATRIX      3
#define MAX_NUMOFCHOICE      4
#define MIN_NUMOFCHOICE      1
#define MAX_NUMOFWINNERFLASH 15
#define INPUTNO              2
#define INPUTYES             1
#define MAXNUM_LOADINGFLASH  20


#define CLEAR_LINEON printf("\33[2K\r");
#define CLEAR_LINE_ANDUP printf("\x1b[1F");


#define CLEAR_LINES  printf("\x1b[1F");   \
                     printf("%60c", ' '); \
                     printf("\x1b[1F");   \
                     printf("%60c", ' '); \
                     printf("\x1b[1F");   \



extern int NumOfCellTofill;
extern int check_array[ARR_ROW][ARR_COL];
extern int sudoku[ARR_ROW][ARR_COL];



// Running of Game
void sudoku_start(void);
// choice level player want to play.
void Start_menu();
// Take user answer to play
void Solve_sudoku(void);
// Take user answer And check of it
// check if game is end or not
// Yes return 1, no return 0
int Take_ans(void);
// Check if player finish and win or not
// Yes return 1, no return 0
int sudoku_isfinish(int row,int col);
// Check if player put in cell valid number or not
// Yes return 1, no return 0
int check_cell(int row, int col, int num);
// Print sudoku grid
void sudoku_print(int sudoku[][ARR_COL]);
// check if player win or not
// Yes return 1, no return 0
int sudoku_Winner();
// print loading on screen.
void print_loading();
// Delay some time
void delay(int number_of_seconds);
// print is specific location on console.
void Consol_cord(int x, int y);



#endif // sudoku_H_

