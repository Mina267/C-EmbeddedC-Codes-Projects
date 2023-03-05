#ifndef math1_H_
# math1_H_
// Swap two numbers
void swap(int *num1, int *num2);
void swap_char(char *num1, char *num2);
// Multiplication two number
int multi(int num1, int num2);
// Give reminder
int reminder(int numerator, int denominator);
// Division
int div_numbers(int numerator, int denominator);
// Power of number
int power(int num1, int num2);
// Power of float number
float pow_f(float num1, float num2);
// subtract two numbers, and return result.
int subtraction (int num1, int num2);
// Give factorial.
unsigned int fact(int num);
// Square root of float number
float sqrt_f(float num);
// Square root of int number
int sqrt_i(int num);
// log base 2
unsigned int log2n(unsigned int num);
// log base 10
unsigned int log10n(unsigned int num);
// Reverse decimal number
int reverse_decimal(int num);
// Program to give sum from 1 --> n
int sum_numberRange (int n);
// Pass number and give prime numbers
void print_primes(unsigned int steps);
// Check if number is prime return (1) or not return (1).
bool isprime(int num);
// Base of two return (1) Not return(0)
bool isbase2(unsigned int num);
// Even return (1) odd return(0)
bool is_even(int num);
// function to get the nth term of Fibonacci series, and use it to print the first 20 element.
int Fibonacci_series(int num);
// Use it to print the first 20 element.
void print_first20Fibonacci();
int Fibonacci_seriesEquation(int num);
// Write a C function to take 10 mono numbers (from 0to 9) from user and return the most repeated one, if user enter number bigger than 9 return -1(don’t use arrays).
char mono_repeat(void);
// Function count occurrences of digit.
int Occurrences_count(long long nums, int num);
unsigned char add2(unsigned char num1, unsigned char num2);
unsigned int add_i2(unsigned int num1, unsigned int num2);
// Add two unsigned char;
// return 1 if function operate correctly otherwise return 0;
unsigned char add_unsignedChar(unsigned char num1, unsigned char num2, unsigned char *result);
// Add two unsigned int;
// return 1 if function operate correctly otherwise return 0;
unsigned int add_unsignedInt(unsigned int num1, unsigned int num2, unsigned int *result);
// Return Max. number is input from start of running time.
int Max_num(int num);
// return smaller positive integer number.
int smallerPositiveNumber2(int num1, int num2, int num3);
// return smaller positive integer number.
int smallerPositiveNumber(int num1, int num2, int num3);
// return smaller integer number.
int smallerNumber(int num1, int num2, int num3);

#endif // math1_H_

