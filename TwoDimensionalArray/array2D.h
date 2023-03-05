#ifndef array2D_H_
#define array2D_H_
int twoDimensionalArray_print(int *arr, int row, int col);
int str_cmp2(char *str1, char* str2);
// Swap data of arrays.
void twoDimensionalArray_swapData(char *s1, char* s2);
// Sorting two dimensional array of strings alphabetical order
void twoDimensionalArray_BubbleSortingstr(char *ar, int row, int col);
int twoDimensionalArray_printstrings(char *ar, int row, int col);
void print_book(char book[][5][50], int size);
void print_pages(char str[][50], int size);
int twoDimensionalArray_EqualDiagonals(int arr[][4], int row, int col);
int twoDimensionalArray_Zigzag(int arr[][4], int row, int col);
int twoDimensionalArray_print2(int *arr, int row, int col);

#endif // array2D_H_
