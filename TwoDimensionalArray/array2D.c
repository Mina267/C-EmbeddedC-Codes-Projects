#include "Project.h"


int twoDimensionalArray_print(int *arr, int row, int col)
{
    int (*p)[col] = arr;

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            printf("%3d ",p[i][j]);
        }
        printf("\n");
    }
}


int str_cmp2(char *str1, char* str2)
{
    if (str1 == 0) {return ;}
    if (str2 == 0) {return ;}

    for(int i = 0;str1[i] || str2[i]; i++)
    {
        if(str1[i] > str2[i])
        {
            return 1;
        }
        else if (str1[i] < str2[2])
        {
            return -1;
        }

    }
    return 0;
}

// Swap data of arrays.
void twoDimensionalArray_swapData(char *s1, char* s2)
{
    if (s1 == 0) {return ;}
    if (s2 == 0) {return ;}

    for (int i = 0; s1[i] || s2[i]; i++)
    {
        swap_char(&s1[i], &s2[i]);
    }
}

// Sorting two dimensional array of strings alphabetical order
void twoDimensionalArray_BubbleSortingstr(char *ar, int row, int col)
{
    if (ar == 0) {return ;}

    char (*arr)[col] = ar;
    char flag;
    // Loop break if there is no swap.
    for(int i = 0; i < row; i++)
    {
        flag = 1;
        for (int j = 0; j < row - i - 1; j++)
        {
            // First string Larger than first swap.
            if (str_cmpLarger(arr[j], arr[j + 1]) == 1)
            {
                twoDimensionalArray_swapData(&arr[j], &arr[j + 1]);
                flag = 0;
            }
        }
        // If there is no swap break.
        if(flag)
            break;
    }
}

int twoDimensionalArray_printstrings(char *ar, int row, int col)
{
    char (*arr)[col] = ar;
    for (int i = 0; i < row; i++)
    {
        string_print(arr[i]);
    }
}


void print_pages(char str[][50], int size)
{
    for(int i = 0; i < size; i++)
    {
        string_print(str[i]);
    }
    printf("=============================\n");
}

void print_book(char book[][5][50], int size)
{
    for (int i = 0; i < size; i++)
    {
        print_pages(book[i], 3);
    }

}


int twoDimensionalArray_EqualDiagonals(int arr[][4], int row, int col)
{
    if (arr == 0)
        {return ;}

    if (row != col)
        {return -1;}

    int D1 = 0;
    int D2 = 0;
    for (int i = 0; i < row; i++)
    {
        D1 += arr[i][i];
        D2 += arr[i][col - 1 - i];
    }

    if (D1 == D2)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int twoDimensionalArray_Zigzag(int arr[][4], int row, int col)
{
    int c = 0;
    for (int i = 0; i < row; i++)
    {
        if (c > 0)
            c = col - 1;
        else
            c = 0;

        for (int j = 0; j < col; j++)
        {
            printf("%3d ", arr[i][c]);

            if ((i + 1) % 2)
                c++;
            else
                c--;
        }
        printf("\n");
    }
}


int twoDimensionalArray_print2(int *arr, int row, int col)
{


    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            printf("%3d ",arr[i * col + j]);
        }
        printf("\n");
    }
}
void star_set(char arr[][20], int row, int col)
{
    int x;
    int y;
    printf("Enter row and col to set to '*':\n");
    scanf("%d",&x);
    scanf("%d",&y);
    if (x > row || y > col)
    {
        printf("Error!\n");
        return ;
    }
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (j == y && i < x)
            {
                arr[i][j] = 'v';
            }
            else if (j == y && i > x)
            {
                arr[i][j] = '^';
            }
            else if (i == x && j < y)
            {
                arr[i][j] = '>';
            }
            else if (i == x && j > y)
            {
                arr[i][j] = '<';
            }
            else if (i < x && j < y)
            {
                arr[i][j] = '\\';
            }
            else if (i < x && j > y)
            {
                arr[i][j] = '/';
            }
            else if (i > x && j < y)
            {
                arr[i][j] = ',';
            }
            else if (i > x && j > y)
            {
                arr[i][j] = '`';
            }
            else
                arr[i][j] = '-';
        }
    }
    arr[x][y] = '*';
}

void star_print(char arr[][20], int row, int col)
{

    printf("   ");
    for (int i = 0; i < col; i++)
    {
        printf(" %d",i);
    }
    printf("\n");

    for (int i = 0; i < row; i++)
    {
        printf("%2d:  ",i);
        for (int j = 0; j < col; j++)
        {
            printf("%c ", arr[i][j]);
        }
        printf("\n");
    }
    printf("\n========================\n");
}

int star_binary(char arr[][20], int row, int col)
{
    int row_m;
    int col_m;
    int row_f = 0;
    int row_l = row - 1;
    int col_f = 0;
    int col_l = col - 1;


    while (row_f <= row_l && row_f <= row_l)
    {

        row_m = (row_f + row_l) / 2;
        col_m = (col_f + col_l) / 2;

        if (arr[row_m][col_m] == '*')
        {
            printf("* in row %d and col. %d\n", row_m, col_m);
            return 1;
        }
        else if (arr[row_m][col_m] == '\\')
        {
            row_f = row_m + 1;
            col_f = col_m + 1;
        }
        else if (arr[row_m][col_m] == '/')
        {
            row_f = row_m + 1;
            col_l = col_m - 1;
        }
        else if (arr[row_m][col_m] == '`')
        {
            row_l = row_m - 1;
            col_l = col_m - 1;
        }
        else if (arr[row_m][col_m] == ',')
        {
            row_l = row_m - 1;
            col_f = col_m + 1;
        }
        else if (arr[row_m][col_m] == '<')
        {
            row_l = row_m;
            row_f = row_m;
            col_l = col_m - 1;
        }
        else if (arr[row_m][col_m] == '>')
        {
            row_l = row_m;
            row_f = row_m;
            col_f = col_m + 1;;
        }
        else if (arr[row_m][col_m] == 'v')
        {
            col_f = col_m;
            col_l = col_m;
            row_f = row_m + 1;
        }
        else if (arr[row_m][col_m] == '^')
        {
            col_f = col_m;
            col_m = col_m;
            row_l = row_l - 1;
        }
    }

    return 0;
}

