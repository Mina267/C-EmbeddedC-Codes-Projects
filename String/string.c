#include "Project.h"


int string_len(char *str)
{
    int i;
    for( i = 0; str[i]; i++);
    return i;
}


int string_compare(char *s1, char *s2)
{
    int i;


    for(i=0; s1[i] || s2[i]; i++)
    {
        if(s1[i] != s2[i])
        {
            return 0;
        }
    }
    return 1;
}

int string_CompareCaseLess(char *s1, char *s2)
{
    int i;

    string_tolower(s1);
    string_tolower(s2);

    for(i=0; s1[i] || s2[i]; i++)
    {
        if(s1[i] != s2[i] )
        {
            return 0;
        }
    }
    return 1;
}


// Function to reverse string
void string_reverse(char *str)
{
    int size = string_len(str);
    for(int i = 0; i < size / 2; i++)
    {
        str[i] = str[i] ^ str[size - 1 - i];
        str[size - 1 - i] = str[i] ^ str[size - 1 - i];
        str[i] = str[i] ^ str[size - 1 - i];
    }
}




void string_tolower(char *str)
{
    char X = 'a' - 'A';

    for(int i = 0; str[i];i++)
    {
        if (str[i] >= 'A'&& str[i] <= 'Z')
        {
            str[i] = str[i] + X;
        }
    }
}

void string_toupper(char *str)
{
    char X = 'a' - 'A';

    for(int i = 0; str[i];i++)
    {
        if (str[i] >= 'a'&& str[i] <= 'z')
        {
            str[i] = str[i] - X;
        }
    }
}


void string_print(char *str)
{
    for(int i = 0; str[i];i++)
    {
        printf("%c",str[i]);
    }
    printf("\n");
}


void string_printIndex(char *str)
{
    for(int i = 0; str[i];i++)
    {
        printf("%2d: ",i);
        printf("%c", str[i]);
        printf("\n");
    }
    printf("\n");
}


void string_scan(char * str, int MaxsSize)
{
    int i = 0;
    fflush(stdin);
    scanf("%c",&str[i]);
    do
    {
        i++;
        scanf("%c",&str[i]);
    }
    while(str[i] != '\n' && i < MaxsSize - 1);

    str[i] = 0;
}

int string_longestWord3(char *sentence)
{
    int curr_word;
    int is_word = 0;
    int longestWord = 0;
    longestWord = string_wordLength(sentence + is_word);

    for (int i = 0; sentence[i] ; i++)
    {
        if (sentence[i] == ' ')
        {
            is_word = i + 1;
            curr_word = string_wordLength(sentence + is_word);
            if (curr_word > longestWord)
                longestWord = curr_word;
        }
    }

    return longestWord;

}

// Determine length of word in string
int string_wordLength(char *str)
{
    int i;
    for( i = 0; str[i]; i++)
    {
        if (str[i] == ' ')
            break;
    }
    return i;
}





// Return 1 if char is space
int string_isSpace(char letter)
{
    int flag;
    return flag = (letter == ' ') ? 1 : 0;
}

// Copy string take start and end
void string_copy(char *str1, char* copyString, int start, int end)
{
    int i, j;
    for(i = start - 1, j = 0; i <= (end - 1) && str1[i] != 0; i++, j++)
    {
        copyString[j] = str1[i];
    }
    copyString[j] = 0;

}

// Copy string take start and end
void string_Scopy(char *str1, char* copyString, int start, int end, int copy_size, int orignal_size)
{
    int i, j;
    if (start > orignal_size)
        return ;


    for(i = start - 1, j = 0; ( i <= (end - 1) && str1[i] != 0 && i < copy_size - 1); i++, j++)
    {
        copyString[j] = str1[i];
    }
    printf("string function:  ");
    string_print(str1);
    copyString[j] = 0;

}

// Returns number of word in string
void string_WordsCount(char *str)
{
    int i, cnt = 0;
    for (i = 0; str[i]; i++)
    {
        if (string_isSpace(str[i]))
            cnt++;
    }
    return cnt + 1;
}

void stringToInt(char*str,int*pnum)
{
    int flag = 0;
    *pnum = 0;

    for(int i = 0; str[i]; i++)
    {
        if (str[i] >= '0' && str[i] <= '9')
        {
            *pnum += str[i] - '0';
            *pnum *= 10;
        }
        if (str[i] == '-')
        {
            flag = 1;
        }
    }

    *pnum /= 10;

    if (flag == 1)
    {
        *pnum *= -1;
    }

}






























