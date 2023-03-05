#ifndef array_H_
#define array_H_
void array_zero_prime(int* arr, int size);
// Return Index MIN and MAX of array Int.
void array_max_min (int *arr, int size, int* pmin, int* pmax);
// Return Max of array Int.
int array_max(int *arr, int size);
// Return Index of Max of array Int.
int array_MaxIndex(int *arr, int size);
// Return Index of Max of array char.
int array_MaxIndexChar(char *arr, int size);
// Return min of array
int array_min(int *arr, int size);
// Return min of array and give index of it.
int array_MinAndIndex(int *arr, int size, int *index);
// Print array of INT
void array_print(int *arr, int size);
// Print array of CHAR
void array_printChar(char *arr, int size);
void array_read (int *arr, int size);
// Return the index of LAST occurrence of a number in a given array.
// If the item is not in the list return -1.
int array_IndexOflastNumber(int *arr, int size, int num);
// Find max. and min. in array and return index.
// results[] array arrangement:  Max. and Min.
// indexs[]  array arrangement: index Max. and index Min.
void array_MaxMin_AndIndex (int *arr, int size, int *results, int *indexs);
// Return 0 if a given number is a power of 3, otherwise return 1.
int isPower3(int value);
// Return 0 if a given number is a power of 3, otherwise return 1.
int IsPowerOfThree(int num);
// Return array contain all numbers between the two given numbers
int* array_betweenTwoNumbersdynamicly (int num1, int num2, int* array_size);
// Return array contain all numbers between the two given numbers
// Function return size of that array
int array_betweenTwoNumbers (int num1, int num2, int *arr, int size);
int array_MostRepeatedPostiveIntegar(int *arr, int size);
// Return most repeated integer.
int array_MostRepeatedIntegar(int *arr, int size);
// Compare function for qsort
int cmp (const void *a, const void *b);
// Return most repeated integer.
int array_MostRepeatedIntegar2(int *arr, int size);
// Reverse its elements of array
void array_Reverse_elements(int *arr, int size);
void array_swap(int *arr1, int size1, int *arr2, int size2);
// Count of the longest consecutive occurrence of a given number in an array.
int array_LongestConsecutiveGiveNumber(int *arr, int size, int num);
// Count of the longest consecutive occurrence of a number in an array.
int array_LongestConsecutiveNumber(int *arr, int size, int *LongestConsecutive);
// Merge two array alternatively and return new array.
int* array_mergeDynamicly(int *arr1, int size1, int *arr2, int size2);
// Merge two array alternatively and Give new array.
// Function return size of two array
int array_mergeStatic(int *arr1, int size1, int *arr2, int size2, int *arr3, int size3);
// Removes the repeated number of an input sorted array and return a new array without the repeated numbers.
int array_removeRepeatedNumber(int *arr, int size, int *arr2);
// function to take an array (with unknown size) contain 2 zeros swap the 3 element after the first zero with the 3 element after the second
void array_12twoZeros(int *arr);
// function to take an array and return the biggest difference between 2 numbers in the array (the smaller number must come first in the array)
int array_biggestDifferenceBetween2Numbers(int *arr, int size);
void Find_MaxAndMin(int *arr, int size, int *P_max, int *P_min);
int array_MostRepeatedFreq (int *arr, int size, int *mostRepeated);
int array_FindNonRepeatedNumber(int *arr, int size);

#endif // array_H_
