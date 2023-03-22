

// Sheet 3


// 1- Write a C function to return the index of LAST occurrence of a number in a given array.
// Array index start from 0. If the item is not in the list return -1.
int LastOccurrenceOfNum(int *arr, int size, int num)
{
    for (int i = size - 1; i >= 0; i--)
    {
        if (arr[i] == num)
            return i;
    }
    return -1;
}

// 2- Write a C function to return the maximum and minimum number in an array and their indexes.
void MaxMin_NumsAndIndexs(int *arr, int size, int *max, int *min, int *maxIndex, int *minIndex)
{
    *max = arr[0];
    *min = arr[0];
    for (int i = 1; i <= size; i++)
    {
        if (arr[i] > *max)
        {
            *max = arr[i];
            *maxIndex = i;
        }
        if (arr[i] < *min)
        {
            *min = arr[i];
            *minIndex = i;
        }
    }
}

// 4- Write a C function that take two numbers and return array
// contain all numbers between the two given numbers.
// (numbers 2,6->return array contain [3,4,5]).

int* ArrayBetweenTwoNumbersheet3(int n1, int n2, int *size)
{
    int tmp;
    if (n1 > n2)
    {
        tmp = n1;
        n1 = n2;
        n2 = tmp;
    }
    int cnt = 0;
    *size = n2 - n1 - 1;
    int *arr = (int *) malloc(*size * sizeof(int));

    for (int i = n1 + 1; i < n2; i++)
    {
        arr[cnt] = i;
        cnt++;
    }
    return arr;
}


int ArrayBetweenNumbers (int n1, int n2, int *arr, int size)
{
    int cnt = 0;
    int tmp;
    if (n1 > n2)
    {
        tmp = n1;
        n1 = n2;
        n2 = tmp;
    }
    int array_size = n2 - n1 - 1;

    if (array_size > size)
    {
        return -1;
    }

    for (int i = n1 + 1; i < n2; i++)
    {
        arr[cnt] = i;
        cnt++;
    }
    return array_size;
}


// 5- Write c function to find the most repeated number in an array of integers.

int MostRepeatedNum (int *arr, int size, int* num)
{
    int cnt;
    int MaxCnt = 0;
    for (int i = 0; i < size; i++)
    {
        cnt = 0;
        for (int j = i; j < size; j++)
        {
            if (arr[i] == arr[j])
            {
                cnt++;
            }
        }

        if (MaxCnt < cnt)
        {
            MaxCnt = cnt;
            *num = arr[i];
        }
    }

    return MaxCnt;
}


// 6- Write a C function to take an array and reverse its elements.
void ReverseArray (int *arr, int size)
{
    int tmp;
    for (int i = 0; i < size / 2; i++)
    {
        tmp = arr[i];
        arr[i] = arr[size - 1 - i];
        arr[size - 1 - i] = tmp;
    }
}
// 7 - Write a C function to take 2 arrays and swap them
int Swap_arrays (int *arr1, int *arr2, int size1, int size2)
{
    int size = (size1 > size2)? size2:size1;
    int tmp;
    for (int i = 0; i <size; i++)
    {
        tmp = arr1[i];
        arr1[i] = arr2[i];
        arr2[i] = tmp;
    }
}


// 8 - Write a C function that return the count of the longest
// consecutive occurrence of a given number in an array.

int LongestConsecutiveGivenNum(int *arr,int size, int num)
{
    int cnt = 0;
    int max = 0;
    for (int i = 0; i < size; i++)
    {
        if (num == arr[i])
        {
            cnt++;
        }
        else
        {
            cnt = 0;
        }
        if (max < cnt)
            max = cnt;
    }

    return max;
}



// 9- Write a C function that return the count of the
// longest consecutive occurrence of any number ,and return the number
int LongestConsecutive(int *arr,int size, int *num)
{
    int cnt = 1;
    int MaxCnt = 0;
    for (int i = 0; i < size - 1; i++)
    {
        if(arr[i] == arr[i + 1])
        {
            cnt++;
        }
        else
        {
            cnt = 1;
        }
        if (MaxCnt < cnt)
        {
            MaxCnt = cnt;
            *num = arr[i];
        }
    }
    return MaxCnt;
}




int *MergeTwoArrays(int *arr1, int size1, int *arr2, int size2)
{
    int *newArray = (int *) malloc ((size1 + size2) * sizeof(int));
    int cnt1 = 0;
    int cnt2 = 0;
    char flag = 1;
    for(int i = 0; i < size1 + size2; i++)
    {
        if(flag)
        {
            newArray[i] = arr1[cnt1];
            cnt1++;
            if (cnt2 < size2)
                flag = 0;
        }
        else if(flag)
        {
            newArray[i] = arr2[cnt2];
            cnt2++;
            if (cnt1 < size1)
                flag = 1;
        }
    }
    return newArray;
}

// Write a c function that removes the repeated number of an input sorted array
// and return a new array without the repeated numbers.

int RemoveRepeatedUnsorted(int *arr, int size, int *newArr)
{
    int flag = 1;
    int cnt = 0;
    for(int i = 0; i < size; i++)
    {
        flag = 1;
        for(int j = i + 1; j < size; j++)
        {
            if (arr[i] == arr[j])
            {
                flag = 0;
            }
        }

        if (flag)
        {
            newArr[cnt] = arr[i];
            cnt++;
        }
    }
    return cnt;
}


void MAXMIN(int *arr, int size, int *max, int *min)
{
    *max = arr[0];
    *min = arr[0];
    for (int i = 1; i < size; i++)
    {
        if (*max < arr[i])
            *max = arr[i];
        if (*min > arr[i])
            *min = arr[i];
    }
}

int RemoveRepeatedUnsorted2(int *arr, int size, int *newArr)
{
    int max;
    int min;
    int cnt = 0;
    MAXMIN(arr, size, &max, &min);
    int freq_s = max - min + 1;
    //printf("size = %d\n",freq_s);
    int *freq = (int *) calloc(freq_s, sizeof(int));
    freq = freq - min;



    for (int i = 0; i < size; i++)
    {
        if (freq[arr[i]] == 0)
            freq[arr[i]]++;
    }


    for(int i = min; i < max; i++)
    {
        if (freq[i] == 1)
        {
            newArr[cnt] = i;
            cnt++;
        }
    }
    return cnt;
}

int RemoveRepeatedsorted(int *arr, int size, int *newArr)
{
    int cnt = 0;
    for (int i = 0; i < size - 1; i++)
    {
        if (arr[i] != arr[i + 1])
        {
            newArr[cnt] = arr[i];
            cnt++;
        }
    }

    if (arr[size - 1] != arr[size - 2])
    {
        newArr[cnt] = arr[size - 1];
        cnt++;
    }
    return cnt;
}


// (12) Write c function to take an array (with unknown size)
// contain 2 zeros swap the 3 element after the first zero with the 3 element after the second zero
void TwoZeros(int *arr)
{
    int i = 0;
    int firstZero = -1;
    int secondZero = -1;

    while(1)
    {
        if (arr[i] == 0)
        {
            firstZero = secondZero;
            secondZero = i;
        }

        if (firstZero != -1)
            break;

        i++;
    }

    int tmp;
    for (int i = 0; i < 3; i++)
    {
        tmp = arr[firstZero + 1];
        arr[firstZero + 1] = arr[secondZero + 1];
        arr[secondZero + 1] = tmp;
        firstZero++;
        secondZero++;
    }
}


// (13) Write c function to take an array
// and return the biggest difference between 2 numbers in the array


int biggestDifferenceBetween2numbers(int *arr,int size)
{
    int minIndex = 0;
    int max = INT_MIN;

    for(int i = 1; i < size; i++)
    {
        if (arr[minIndex] > arr[i])
        {
            minIndex = i;
        }
    }
    for(int i = minIndex + 1; i < size; i++)
    {
        if (max < arr[i])
            max = arr[i];
    }

    return max - arr[minIndex];
}
// 14
int MostRepeatedMONONum(int *arr, int size)
{
    int freq[10] = {0};
    int max = 0;
    for(int i = 0; i < size; i++)
    {
        freq[arr[i]]++;
    }

    for(int i = 1; i < 10; i++)
    {
        if (freq[i] > freq[max])
        {
            max = i;
        }
    }
    return max;
}


