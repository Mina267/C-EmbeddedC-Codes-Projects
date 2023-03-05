#ifndef string_H_
#define string_H_
int string_len(char *str);
int string_compare(char *s1, char *s2);
int string_CompareCaseLess(char *s1, char *s2);
// Function to reverse string
void string_reverse(char *str);
void string_tolower(char *str);
void string_toupper(char *str);
void string_print(char *str);
void string_printIndex(char *str);
void string_scan(char * str, int MaxsSize);
int string_longestWord3(char *sentence);
// Determine length of word in string
int string_wordLength(char *str);
// Return 1 if char is space
int string_isSpace(char letter);
// Copy string take start and end
void string_copy(char *str1, char* copyString, int start, int end);
// Copy string take start and end
void string_Scopy(char *str1, char* copyString, int start, int end, int copy_size, int orignal_size);
// Returns number of word in string
void string_WordsCount(char *str);
void stringToInt(char*str,int*pnum);

#endif // string_H_
