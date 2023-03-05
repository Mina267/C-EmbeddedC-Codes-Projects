#include "Project.h"


// Search for number and Give index in pointer
// If Number found return 1, not found return 0;
// complexity O(n).
int array_LinearSearch(int *arr, int size, int NumberToFind, int *index)
{
    for( int i = 0; i < size; i++)
    {
        if(arr[i] == NumberToFind)
        {
            *index = i;
            return 1;
        }
    }
    return 0;
}

// Search for number and Give index in pointer
// If Number found return 1, not found return 0;
// Input array must be sorted
// complexity O(log n).
int array_binarySearch(int *arr, int size, int num, int *index)
{
    // 0 1 2 3 4 5 6 7 8
    int m;
    int l = 0;
    int r = size - 1;


    while (l <= r)
    {
        m = (l + r) / 2;

        if (arr[m] == num)
        {
            *index = m;
            return 1;
        }
        else if (arr[m] > num)
        {
            r = m - 1;
        }
        else
        {
            l = m + 1;
        }
    }

    return 0;

}


// Sort array from smaller to larger
// complexity O(n^2), space O(1).
void array_BubleSorting(int *arr, int size)
{
    char flag = 0;
    for (int j = 0; j < size; j++)
    {
        flag = 0;
        for (int i = 0; i < size - j - 1; i++)
        {
            if (arr[i] > arr[i + 1])
            {
                swapTwo(&arr[i], &arr[i + 1]);
                flag = 1;
            }
        }
        if (!flag)
            break;
    }

}
// Swap two numbers
void swapTwo(int *num1, int *num2)
{
    *num1 = *num1 ^ *num2;
    *num2 = *num1 ^ *num2;
    *num1 = *num1 ^ *num2;
}


// Sort array from smaller to larger
// complexity O(n^2), space O(1). But with fewer swap than bubble.
void array_SelectionSorting(int *arr, int size)
{
    int MaxIndex;
    int last = size - 1;
    for (int i = 0; i < size; i++)
    {
        MaxIndex = SelectionMax(arr, last);
        if (last != MaxIndex)
            swapTwo(&arr[MaxIndex], &arr[last]);
        last--;
    }
}

int SelectionMax(int *arr, int last)
{
    int MaxIndex = 0;
    for(int i = 0; i <= last; i++)
    {
        if (arr[MaxIndex] < arr[i])
            MaxIndex = i;
    }
    return MaxIndex;
}



// Sort array from smaller to larger
// complexity O(n + k), space O(k).
void array_CountSorting(int *arr, int size)
{
    int max;
    int min;
    int index = 0;
    int F_size;
    CountMaxMin(arr, size, &max, &min);
    F_size = max - min + 1;

    int *cnt = (int *)calloc(F_size, sizeof(int));

    cnt = cnt - min;

    for(int i = 0; i < size; i++)
    {
        cnt[arr[i]]++;
    }

    for (int i = min; i <= max; i++)
    {
        while(cnt[i])
        {
            arr[index] = i;
            cnt[i]--;
            index++;
        }
    }
}

void CountMaxMin(int *arr, int size, int *max, int *min)
{
    *max = arr[0];
    *min = arr[0];
    for(int i = 1; i < size; i++)
    {
        if (*max < arr[i])
            *max = arr[i];
        else if (*min > arr[i])
            *min = arr[i];
    }
}



void array_MergeSorting(int *arr, int size)
{
    //array_print(arr,size);
    // Use to call merge function to do not disturb user to input right left index.
    MergeSorting(arr, 0, size - 1);
}

void MergeSorting(int *arr, int l, int r)
{

    // Casting to prevent overflow
   // unsigned int m = (unsigned int)(((long long)l + (long long)r) / (long long)2);

    // condition is bass case of recursion function.
    if (l < r)
    {
        int m = l + (r - l) / 2;
        // Sort left half numbers of array
        MergeSorting(arr, l, m);
        // Sort right half numbers of array
        MergeSorting(arr, m + 1, r);
        // Merge Two Sorted half of array
        mergeSortedArrays(arr, l,m,r);
    }
}

void mergeSortedArrays(int *arr, int l, int m, int r)
{
    int i, j, k;
    int length_l = m - l + 1;
    int length_r = r - m;

    int left[length_l];
    int right[length_r];

    // copy the left half into the temp_l array
    for (int x = 0; x < length_l; x++)
    {
        left[x] = arr[l + x];
    }

    // copy the right half into the temp_r array
    for (int x = 0; x < length_r; x++)
    {
        right[x] = arr[m + 1 + x];
    }

    i = 0;
    j = 0;
    k = l;
    // merge two array
    while(i < length_l && j < length_r)
    {
        if (left[i] <= right[j])
        {
            arr[k] = left[i];
            i++;
        }
        else
        {
            arr[k] = right[j];
            j++;
        }
        k++;
    }

    // Copy remaining elements
    while (i < length_l)
    {
        arr[k] = left[i];
        i++;
        k++;
    }
    // Copy remaining elements
    while (j < length_r)
    {
        arr[k] = right[j];
        j++;
        k++;
    }
}



void array_HeapSorting(int *arr, int size)
{

}
