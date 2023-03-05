#include "Project.h"

void Swap_pointers(char **pp1, char **pp2)
{
    char *tmp;
    tmp = *pp1;
    *pp1 = *pp2;
    *pp2 = tmp;
}

int arrayToPointer_printstrings(int **arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        string_print(arr[i]);
    }
}

int str_cmp(char *str1, char* str2)
{

    for(int i = 0;str1[i] || str2[i];i++)
    {
        if(str1[i] != str2[i])
        {
            return 0;
        }
    }
    return 1;
}

int arrayToPointer_LinearSearch(char **arr, int size, char* str)
{
    for (int i = 0; i < size; i++)
    {
        if (str_cmp(arr[i], str))
        {
            return i;
        }
    }
    return -1;
}



int str_cmpLarger(char *str1, char* str2)
{
    for(int i = 0;str1[i] || str2[i];i++)
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


void arrayToPointer_BubbleSortingstr(char **arr, int size)
{
    int flag;

    for(int i = 0; i < size; i++)
    {
        flag = 1;
        for (int j = 0; j < size - i - 1; j++)
        {
            if (str_cmpLarger(arr[j], arr[j + 1]) == 1)
            {
                Swap_pointers(&arr[j], &arr[j + 1]);
                flag = 0;
            }
        }

        if(flag)
            break;
    }
}



int arrayToPointer_LinearSearchchar(char **arr, int size, char ch, int *line)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; arr[i][j]; j++)
        {
            if (arr[i][j] == ch)
            {
                *line = i;
                return j;
            }
        }
    }
    return -1;
}



int str_cmpTheSame(char *str1, char* str2)
{
    if (str1 == 0) {return ;}
    if (str2 == 0) {return ;}

    for(int i = 0;str1[i] || str2[i];i++)
    {
        if(str1[i] > str2[i])
        {
            return 1;
        }
        else if (str1[i] < str2[i])
        {
            return -1;
        }

    }
    return 0;
}

// Searching two dimensional array of strings alphabetical order
int arrayToPointer_binarySearchstr(char **arr, int size, char *s)
{
    if (arr == 0) {return ;}

    int m;
    int f;
    int l;
    f = 0;
    l = size - 1;

    while (f <= l)
    {
        m = (f + l) / 2;

        if (!str_cmpTheSame(arr[m], s))
        {
            return (m + 1);
        }
        else if (str_cmpTheSame(arr[m], s) == 1)
        {
            l = m - 1;
        }
        else
        {
            f = m + 1;
        }
    }
    return -1;
}

