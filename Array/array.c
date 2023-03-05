#include "Project.h"


void array_zero_prime(int* arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        if (isprime(arr[i]))
        {
            arr[i] = 0;
        }
    }
}


// Return Index MIN and MAX of array Int.
void array_max_min (int *arr, int size, int* pmin, int* pmax)
{
    int min = INT_MAX, max = INT_MIN;
    for(int i = 0; i < size; i++)
    {
        if (arr[i] > max)
            max = arr[i];

        else if (arr [i] < min)
            min = arr[i];
    }

    *pmin = min;
    *pmax = max;

}

// Return Max of array Int.
int array_max(int *arr, int size)
{
    int max = INT_MIN;
    for(int i = 0; i < size; i++)
    {
        if (arr[i] > max)
            max = arr[i];
    }
    return max;
}

// Return Index of Max of array Int.
int array_MaxIndex(int *arr, int size)
{
    int max = INT_MIN;
    int index;
    for(int i = 0; i < size; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
            index = i;
        }
    }
    return index;
}

// Return Index of Max of array char.
int array_MaxIndexChar(char *arr, int size)
{
    int max = INT_MIN;
    int index;
    for(int i = 0; i < size; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
            index = i;
        }
    }
    return index;
}

// Return min of array
int array_min(int *arr, int size)
{
    int min = INT_MAX;
    for(int i = 0; i < size; i++)
    {
        if (arr[i] < min)
            min = arr[i];
    }
    return min;
}

// Return min of array and give index of it.
int array_MinAndIndex(int *arr, int size, int *index)
{
    int min = INT_MAX;
    for(int i = 0; i < size; i++)
    {
        if (arr[i] < min)
        {
            min = arr[i];
            *index = i;
        }
    }
    return min;
}

// Print array of INT
void array_print(int *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%3d ", arr[i]);
    }
    printf("\n==================================================\n");
}

// Print array of CHAR
void array_printChar(char *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}


void array_read (int *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        scanf("%d",&arr[i]);
    }
}




// Return the index of LAST occurrence of a number in a given array.
// If the item is not in the list return -1.
int array_IndexOflastNumber(int *arr, int size, int num)
{
    int index = -1;
    // Loop break if number found.
    for (int i = size - 1; i >= 0; i--)
    {
        if (arr[i] == num)
        {
            index = i;
            break;
        }
    }
    return index;
}

// Find max. and min. in array and return index.
// results[] array arrangement:  Max. and Min.
// indexs[]  array arrangement: index Max. and index Min.
void array_MaxMin_AndIndex (int *arr, int size, int *results, int *indexs)
{
    // initialize Max and Min.
    results[0] = arr[0];
    results[1] = arr[0];

    for (int i = 1; i < size; i++)
    {
        if (arr[i] > results[0])
        {
            results[0] = arr[i];
            indexs[0] = i;
        }
        else if (arr[i] < results[1])
        {
            results[1] = arr[i];
            indexs[1] = i;
        }
    }

}

// Return 0 if a given number is a power of 3, otherwise return 1.
int isPower3(int value)
{
    // 1162261467 is The biggest power of 3 that fits into signed 32 bits = 3^19
    // For unsigned number 3^20 = 3486784401.
    // Any number give reminder to that number equal to zero is power of three.
    return !((value > 0) && (1162261467 % value == 0));
}




// Return 0 if a given number is a power of 3, otherwise return 1.
int IsPowerOfThree(int num)
{
    if (num == 0)
    {
        return 1;
    }
    while(num % 3 == 0)
    {
        num /= 3;
    }
    // If number after while Loop not equal one return 1, else return zero;
    return (num != 1);
}



// Return array contain all numbers between the two given numbers
int* array_betweenTwoNumbersdynamicly (int num1, int num2, int* array_size)
{
    int cnt=0;

    // Check which number is greater.
    if(num1 < num2)
        swap(&num1, &num2);

    // Determine size of the array.
    *array_size = (num1 - num2) - 1;


    int *arr = malloc(sizeof(int) * (*array_size));
    // Check if pointer equal NULL.
    if (arr == 0)
        return ;

    for(int i = num2 + 1; i < num1; i++)
    {
        arr[cnt] = i;
        cnt++;
    }

    return arr;
}


// Return array contain all numbers between the two given numbers
// Function return size of that array
int array_betweenTwoNumbers (int num1, int num2, int *arr, int size)
{
    int cnt=0;
    int array_size;

    // Check if pointer equal NULL.
    if (arr == 0)
        return ;

    // Check which number is greater.
    if(num1 < num2)
        swap(&num1, &num2);

    // Determine size of the array.
    array_size = (num1 - num2) - 1;

    // Check if Given array is large enough.
    array_size = (array_size > size)? size : array_size;



    for(int i = num2 + 1; i < num1; i++)
    {
        arr[cnt] = i;
        cnt++;
    }

    return array_size;
}



// Return most repeated positive integer.


int array_MostRepeatedPostiveIntegar(int *arr, int size)
{
    // Check if pointer equal NULL.
    if (arr == 0)
        return ;

    int result;
    // Use repeats array to count how much each number repeats by using indexes. initialize by zero.
    // Ex. repeats[5] = 3; means number 5 repeats 3 times
    int repeats[repeats_size] = {0};
    for (int i = 0; i < size; i++)
    {
        // increment index number by one.
        repeats[arr[i]]++;
    }
    result = array_MaxIndex(repeats, repeats_size);
    return result;
}



// Return most repeated integer.
int array_MostRepeatedIntegar(int *arr, int size)
{
    // Check if pointer equal NULL.
    if (arr == 0)
        return ;

    int currMax, most_repated;
    int Max = INT_MIN;
    for(int i = 0; i < size; i++)
    {
        currMax = 0;
        for(int j = i + 1; j < size; j++)
        {
            if(arr[i] == arr[j])
            {
                currMax++;
            }
        }
        if (currMax > Max)
        {
            Max = currMax;
            most_repated = arr[i];
        }
    }
    return most_repated;
}



// Compare function for qsort
int cmp (const void *a, const void *b)
{
    return  *(const int*)a - *(const int*)b;
}

// Return most repeated integer.
int array_MostRepeatedIntegar2(int *arr, int size)
{
    // Sort Array for easy count
    qsort(arr, size, sizeof(int), cmp);

    int currMax = 1, most_repated;

    int Max = INT_MIN;

    for (int i = 1; i < size; i++)
    {
        if (arr[i] == arr[i - 1])
            currMax++;
        else
            currMax = 1;

        if (currMax >= Max)
        {
            Max = currMax;
            most_repated = arr[i - 1];
        }
    }
    return most_repated;
}

// Reverse its elements of array
void array_Reverse_elements(int *arr, int size)
{
    // Check if pointer equal NULL.
    if (arr == 0)
        return ;

    for(int i = 0; i < size / 2; i++)
    {
        swap(&arr[i],&arr[size - 1 - i]);
    }
}


void array_swap(int *arr1, int size1, int *arr2, int size2)
{
    // Check if pointer equal NULL.
    if (arr1 == 0)
        return ;
    // Check if pointer equal NULL.
    if (arr2 == 0)
        return ;

    // Work on small size array
    int size;
    size = (size1 > size2)? size2 : size1;

    // swap values of two arrays
    for (int i = 0; i < size; i++)
    {
        swap(&arr1[i], &arr2[i]);
    }

    // Make Garbage excessive value for small array put in largest equal to zero.
    for(int i = size; i < size1 || i < size2; i++)
    {
        if (size1 > size2)
            arr1[i] = 0;
        else
            arr2[i] = 0;
    }
}

// Count of the longest consecutive occurrence of a given number in an array.
int array_LongestConsecutiveGiveNumber(int *arr, int size, int num)
{
    int currMax = 0,  Max = 0;
    for (int i = 0; i < size; i++)
    {
        // If number equal to arr[i] increment if not start count from began
        if (arr[i] == num)
            currMax++;
        else
            currMax = 0;


        if (currMax >= Max)
            Max = currMax;
    }
    return Max;
}


// Count of the longest consecutive occurrence of a number in an array.
int array_LongestConsecutiveNumber(int *arr, int size, int *LongestConsecutive)
{
    int currMax = 1,  Max = 0;
    for (int i = 1; i < size; i++)
    {
        if (arr[i] == arr[i - 1])
            currMax++;
        else
            currMax = 1;


        if (currMax >= Max)
        {
            Max = currMax;
            *LongestConsecutive = arr[i - 1];
        }

    }
    return Max;
}


// Merge two array alternatively and return new array.
int* array_mergeDynamicly(int *arr1, int size1, int *arr2, int size2)
{
    // Check if pointers equal NULL.
    if (arr1 == 0)
        return ;

    if (arr2 == 0)
        return ;

    // If two array not equal quit
    if (size1 != size2)
        return ;

    // Flag to do alternate between two array.
    bool flag = true;
    int cnt = 0;

    int *arr3 = malloc(sizeof(int) * (size1 + size2));
    if( arr3 == NULL)
        return ;


    for(int i = 0, n = size1 + size2; i < n; i++)
    {
        if (flag)
        {
            arr3[i] = arr1[cnt];
            flag = false;
        }
        else
        {
            arr3[i] = arr2[cnt];
            flag = true;
            cnt++;
        }

    }
    return arr3;
}

// Merge two array alternatively and Give new array.
// Function return size of two array
int array_mergeStatic(int *arr1, int size1, int *arr2, int size2, int *arr3, int size3)
{
    // Check if pointers equal NULL.
    if (arr1 == 0)
        return ;

    if (arr2 == 0)
        return ;

    if (arr3 == 0)
        return ;

    // If two array not equal quit
    if (size1 != size2)
        return ;

    int cnt = 0;
    int size = (size3 < size1 + size2) ? size3 : size1 + size2;
    // Flag to do alternate between two array.
    bool flag = true;

    for(int i = 0; i < size; i++)
    {
        if (flag)
        {
            arr3[i] = arr1[cnt];
            flag = false;
        }
        else
        {
            arr3[i] = arr2[cnt];
            //printf("arr3[%d] = arr2[%d] = %d\n", i, cnt, arr2[cnt]);
            flag = true;
            cnt++;
        }
    }
    return size;
}

// Removes the repeated number of an input sorted array and return a new array without the repeated numbers.
int array_removeRepeatedNumber(int *arr, int size, int *arr2)
{
    // Check if pointers equal NULL.
    if (arr == 0)
        return ;

    if (arr2 == 0)
        return ;

    int new_size = 0;
    for (int i = 1; i < size; i++)
    {
        if (arr[i] != arr[i - 1])
        {
            arr2[new_size] = arr[i - 1];
            new_size++;
        }
    }
    // Handle last number in array
    arr2[new_size] = arr[size - 1];
    new_size++;

    return new_size;
}


// function to take an array (with unknown size) contain 2 zeros swap the 3 element after the first zero with the 3 element after the second
void array_12twoZeros(int *arr)
{
    // Check if pointers equal NULL.
    if (arr == 0)
        return ;

    int first_zero = -1;
    int curr_zero;
    // USe count to break out loop When we found Two zeros.
    char cnt = 0;
    for(int i = 0; cnt < 2 ; i++)
    {
        if (arr[i] == 0)
        {
            curr_zero = i;
            cnt++;

            // Save First zero one time
            if (first_zero == -1)
                first_zero = curr_zero;
        }
    }
    swap(&arr[curr_zero + 1], &arr[first_zero + 1]);
    swap(&arr[curr_zero + 2], &arr[first_zero + 2]);
    swap(&arr[curr_zero + 3], &arr[first_zero + 3]);
}

// function to take an array and return the biggest difference between 2 numbers in the array (the smaller number must come first in the array)
int array_biggestDifferenceBetween2Numbers(int *arr, int size)
{
    // Check if pointers equal NULL.
    if (arr == 0)
        return ;

    int min_index;
    // array_MinAndIndex: Return minimum, and give index.
    int Min = array_MinAndIndex(arr, size, &min_index);

    // Add to address the the index of minimum to start find Max
    int Max = array_max(arr + min_index, size - min_index);

    // abs if smallest number is negative
    return (Max - abs(Min));
}



void Find_MaxAndMin(int *arr, int size, int *P_max, int *P_min)
{
    *P_max = arr[0];
    *P_min = arr[0];
    for(int i = 1; i < size; i++)
    {
        if (*P_max < arr[i])
            *P_max = arr[i];

        if (*P_min > arr[i])
            *P_min = arr[i];
    }
}

int array_MostRepeatedFreq (int *arr, int size, int *mostRepeated)
{
    int max;
    int min;
    int maxRepeats = 0;
    Find_MaxAndMin(arr, size, &max, &min);

    int F_size = max - min + 1;

    int *freq = (int *) calloc(F_size, sizeof(int));

    for (int i = 0; i < size ; i++)
    {
        freq[arr[i] - min]++;
    }

    array_print(freq,F_size);

    for (int i = 0; i < F_size; i++)
    {
        if (maxRepeats < freq[i])
        {
            maxRepeats = freq[i];
            *mostRepeated = i + min;
        }
    }

    return maxRepeats;
}



int array_FindNonRepeatedNumber(int *arr, int size)
{
    int max;
    int min;
    int maxRepeats = 0;
    Find_MaxAndMin(arr, size, &max, &min);

    int F_size = max - min + 1;

    int *freq = (int *) calloc(F_size, sizeof(int));

    for (int i = 0; i < size ; i++)
    {
        freq[arr[i] - min]++;
    }
}
