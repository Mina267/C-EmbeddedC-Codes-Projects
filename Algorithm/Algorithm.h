#ifndef Algorithm_H_
#define Algorithm_H_

void mergeSortedArrays(int *arr, int l, int m, int r);
void MergeSorting(int *arr, int l, int r);
void array_MergeSorting(int *arr, int size);
void CountMaxMin(int *arr, int size, int *max, int *min);
void array_CountSorting(int *arr, int size);
int SelectionMax(int *arr, int last);
void array_SelectionSorting(int *arr, int size);
void array_BubleSorting(int *arr, int size);
void swapTwo(int *num1, int *num2);
int array_binarySearch(int *arr, int size, int num, int *index);
int array_LinearSearch(int *arr, int size, int NumberToFind, int *index);
int str_cmp(char *str1, char* str2);
int arrayToPointer_printstrings(int **arr, int size);
void Swap_pointers(char **pp1, char **pp2);
void array_HeapSorting(int *arr, int size);

#endif // Algorithm_H_
