#include "Project.h"


// Swap two numbers
void swap(int *num1, int *num2)
{
    *num1 = *num1 ^ *num2;
    *num2 = *num1 ^ *num2;
    *num1 = *num1 ^ *num2;
}

void swap_char(char *num1, char *num2)
{
    *num1 = *num1 ^ *num2;
    *num2 = *num1 ^ *num2;
    *num1 = *num1 ^ *num2;
}

// Multiplication two number
int multi(int num1, int num2)
{
    int multi = 0;
    int steps = num2;
    if (steps < 0)
        steps = -steps;

    for(int i = 0; i < steps; i++)
    {
        multi += num1;
    }

    if (num2 < 0)
        multi = -multi;

    return multi;
}

// Give reminder
int reminder(int numerator, int denominator)
{
    while (numerator >= denominator)
    {
        numerator -= denominator;
    }
    return numerator;
}

// Division
int div_numbers(int numerator, int denominator)
{
    int cnt = 0;
    char sign = 0;
    if (numerator < 0)
    {
        numerator = -numerator;
        sign++;
    }
    if (denominator < 0)
    {
        denominator = -denominator;
        sign++;
    }


    while (numerator >= denominator)
    {
        numerator -= denominator;
        cnt++;
    }
    if(sign == 2 || sign == 0)
        return cnt;
    else
        return -cnt;
}

// Power of number
int power(int num1, int num2)
{
    int result = 1;

    for(int i = 0; i < num2; i++)
    {
        result *= num1;
    }
    if (num2 < 0)
        result = 0;

    return result;
}

// Power of float number
float pow_f(float num1, float num2)
{
    float result = 1;

    float steps = num2;
    if (steps < 0)
        steps = -steps;

    for (int i = 0; i < steps; i++)
    {
        result *= num1;
    }

    if (num2 < 0)
        result = 1 / result;

    return result;
}

// subtract two numbers, and return result.
int subtraction (int num1, int num2)
{
    int borrow;
    while (num2)
    {
        borrow = (~num1) & num2;
        num1 = num1 ^ num2;
        num2 = borrow << 1;
    }
    return num1;
}

// Give factorial.
unsigned int fact(int num)
{
    if (num == 1)
        return 1;
    else
        return num * fact(num - 1);
}

// Square root of float number
float sqrt_f(float num)
{
    float temp, sqrt;

    sqrt = num / 2;
    temp = 0;

    while(sqrt != temp)
    {
        temp = sqrt;
        sqrt = ((num / temp) + temp) / 2;
    }

    return sqrt;
}

// Square root of int number
int sqrt_i(int num)
{
    int sqrt = 0, i;


    for(i = 1; num >= i*i; i++)
    {
        if(num == i*i)
        {
            sqrt = i;
            break;
        }
    }
    if(sqrt == 0)
        sqrt = i - 1;

    return sqrt;
}

// log base 2
unsigned int log2n(unsigned int num)
{
    return (num > 1) ? 1 + log2n(num / 2) : 0;
}

// log base 10
unsigned int log10n(unsigned int num)
{
    return (num > 1) ? 1 + log10n(num / 10) : 0;
}

// Reverse decimal number
int reverse_decimal(int num)
{
    int  r_num = 0, c_num, placeholder = 1;
    c_num = num;

    while(c_num)
    {
        c_num /= 10;
        placeholder *= 10;
    }
    while(num)
    {
        placeholder /= 10;
        r_num += (num % 10) * placeholder;
        num /= 10;
    }
    return r_num;
}

// Program to give sum from 1 --> n
int sum_numberRange (int n)
{
    n = (n * (n + 1)) / 2;
    return n;
}

// Pass number and give prime numbers
void print_primes(unsigned int steps)
{
    int curr_num = 1;
    bool flag;

    while(steps)
    {
        flag = true;
        for(int i = 2; i <= curr_num / 2; i++)
        {
            if(curr_num % i == 0)
            {
                flag = false;
                break;
            }
        }
        // Handel number two special case
        if (curr_num == 1)
        {
            printf("%d\n",curr_num + 1);
            steps--;
        }

        if (flag && curr_num != 1)
        {
            printf("%d\n", curr_num);
            steps--;
        }
        // Use odd number only
        curr_num += 2;
    }
}

// Check if number is prime return (1) or not return (1).
bool isprime(int num)
{
    bool flag = true;
    if(num == 0 || num == 1 || (num % 2 == 0 && num != 2))
        return false;

    for (int i = 2; i <= num / 2; i++)
    {
        if (num % i == 0)
        {
            flag = false;
            break;
        }
    }

    return flag;

}

// Base of two return (1) Not return(0)
bool isbase2(unsigned int num)
{
    // Ex number: 8 , 8-1 = 7 --->  1000 & 0111 = 0000
    if ((num & (num - 1)) == 0 && num != 0)
        return true;
    else
        return false;
}

// Even return (1) odd return(0)
bool is_even(int num)
{
    if (num & 1)
        return false;
    else
        return true;
}



// function to get the nth term of Fibonacci series, and use it to print the first 20 element.
int Fibonacci_series(int num)
{
    // Get the nth term of Fibonacci series.
    // initialize first and second terms
    int f1 = 0,f2 = 1;
    int next_term;

    if (num == 0)
        return f1;

    for(int i = 1; i < num; i++)
    {
        next_term = f1 + f2;
        f1 = f2;
        f2 = next_term;
    }

    return f2;
}

// Use it to print the first 20 element.
void print_first20Fibonacci()
{
    for (int i = 0; i < 20; i++)
        printf("%d ", Fibonacci_series(i));

    printf("\n");
}



int Fibonacci_seriesEquation(int num)
{
    float result = (pow_f((1 + sqrt_f(5)),(float)num) - pow_f((1 - sqrt_f(5)),(float)num)) / (pow_f(2,(float)num) *  sqrt_f(5));
    return ((int)result);
}


// Write a C function to take 10 mono numbers (from 0to 9) from user and return the most repeated one, if user enter number bigger than 9 return -1(don’t use arrays).
char mono_repeat(void)
{
    long long num, nums = 0;
    long long placeholder = 1;
    int result = 0;
    int max_count = 1;

    printf("Enter numbers: \n");
    for(int i = 0; i < 10 ; i++)
    {
        scanf("%d", &num);
        if (num > 9 && num < 0)
        {
            return -1;
        }
        nums = nums + (num * placeholder);
        placeholder *= 10;
    }

    // Handle negative number
    if (nums < 0)
        nums = -nums;



    // Check occurrences of each number from zero to 10
    for (int i = 0; i <= 9; i++)
    {
        int count = Occurrences_count(nums, i);

        // Update Max count.
        if (count >= max_count)
        {
            max_count = count;
            result = i;
        }
    }
    return result;
}





// Function count occurrences of digit.
int Occurrences_count(long long nums, int num)
{
    int count = 0;
    while (nums)
    {
        // Increment count if current digit is same as number.
        if (nums % 10 == num)
            count++;
        nums = nums / 10;
    }
    return count;
}




unsigned char add2(unsigned char num1, unsigned char num2)
{
    unsigned int result = (num1 + num2) > 255 ? 255 : num1 + num2;
    return (unsigned char)result;
}

unsigned int add_i2(unsigned int num1, unsigned int num2)
{
    long int result = (num1 + num2) > 0xffff ? 0xffff : num1 + num2;
    return (unsigned int)result;
}



// Add two unsigned char;
// return 1 if function operate correctly otherwise return 0;
unsigned char add_unsignedChar(unsigned char num1, unsigned char num2, unsigned char *result)
{

    // Find the most significant bit bit in each char.
    // If most significant bit in first number and second are one, you will get overflow.
    // Ex. [1]010 0000 + [1]011 0100 --> overflow
    // If they are the different, check that a if one of them most significant bit is one.
    // And if most significant bit in result is zero, then there was overflow.
    // [1]011 0101 + [0]111 0101 = 1 [0]010 1010 ---> overflow
    unsigned char ans = num1 + num2;
    unsigned char a = num1 >> char_size - 1;
    unsigned char b = num2 >> char_size - 1;
    unsigned char c = ans >> char_size - 1;

    if ((!(a&b))&(c|!(a^b)))
    {
        *result = ans;
        return 1;
    }
    else
    {
        return 0;
    }
}




// Add two unsigned int;
// return 1 if function operate correctly otherwise return 0;
unsigned int add_unsignedInt(unsigned int num1, unsigned int num2, unsigned int *result)
{

    // Find the most significant bit bit in each int.
    // If most significant bit in first number and second are one, you will get overflow.
    // Ex. [1]010 0000 + [1]011 0100 --> overflow
    // If they are the different, check that a if one of them most significant bit is one.
    // And if most significant bit in result is zero, then there was overflow.
    // [1]011 0101 + [0]111 0101 = 1 [0]010 1010 ---> overflow
    unsigned int ans = num1 + num2;
    unsigned int a = num1 >> int_size - 1;
    unsigned int b = num2 >> int_size - 1;
    unsigned int c = ans >> int_size - 1;

    // (a ^ b) to check that a if one of them most significant bit is one.
    // 0^0 --> 1, 0^1 --> 0, 1^0 --> 0. then !(a ^ b) change 0 to 1 and 1 to 0
    // if  most significant is 1 and is !(a ^ b) = 0 or 1 give 1
    // if equal 0 and is !(a ^ b) = 0 give 0 if  !(a ^ b) = 1  give 1.
    if ((!(a & b)) & (c | !(a ^ b)))
    {
        *result = ans;
        return 1;
    }
    else
    {
        return 0;
    }
}



// Return Max. number is input from start of running time.
int Max_num(int num)
{
    static int Max = INT_MIN;
    if (num > Max)
    {
        Max = num;
    }
    return Max;
}






// return smaller positive integer number.
int smallerPositiveNumber2(int num1, int num2, int num3)
{
    if (!num1 || !num2 || !num3)
        return 0;
    else if (!(num1 / num2) && !(num1 / num3))
        return num1;
    else if (!(num2 / num1) && !(num2 / num3))
        return num2;
    else if (!(num3 / num1) && !(num3 / num2))
        return num3;
}

// return smaller positive integer number.
int smallerPositiveNumber(int num1, int num2, int num3)
{
    int cnt = 0;
    while (num1 && num2 && num3)
    {
        num1--;
        num2--;
        num3--;
        cnt++;
    }
    return cnt;
}

// return smaller integer number.
int smallerNumber(int num1, int num2, int num3)
{
    int cnt = 0;
    int i = -1;
    if ((num1 >> 31) & 1 || (num2 >> 31) & 1 || (num3 >> 31) & 1)
    {
        i = 1;
        if (!((num1 >> 31) & 1))
            num1 = 0;
        if (!((num2 >> 31) & 1))
            num2 = 0;
        if (!((num3 >> 31) & 1))
            num3 = 0;


        while (num1 || num2 || num3)
        {
            if (num1)
                num1 = num1 + i;
            if (num2)
                num2 = num2 + i;
            if (num3)
                num3 = num3 + i;
            cnt++;
        }
        cnt = -cnt ;
    }
    else
    {
        while (num1 && num2 && num3)
        {
            num1 = num1 + i;
            num2 = num2 + i;
            num3 = num3 + i;
            cnt++;
        }
    }

    return cnt;
}





int AddWithoutPostiveSign(int num1, int num2)
{
    // num1 = 8, num2 = 7;
    // add = num1 – ~num2 – 1;
    // add = 8 – (-8) – 1;
    // add = 8 + 8 – 1;
    // add = 8 + 7;
    // add = 15;

    return num1 - (~num2) - 1;
}


/*    n1 = 1 , n2 = 3.
    * first iteration.
    *  0001 (a)
    * &0011 (b)
    * ------
    *  0001 --> position of carry (b)
    * then do addition
    *  0001 (a)
    * ^0011 (b)
    * ------
    *  0010 --> equal a
    *
    * b << 1 --> 0010
    *
    * second iteration.
    *  0010 (a)
    * &0010 (b)
    * ------
    *  0010 --> position of carry (b)
    *
    * then do addition
    *  0001 (a)
    * ^0011 (b)
    * ------
    *  0000 --> equal a
    *
    *  b << 1 --> 0100
    *
    * third iteration.
    *  0000 (a)
    * &0100 (b)
    * ------
    *  0000 --> position of carry (b)
    *
    * then do addition
    *  0000 (a)
    * ^0100 (b)
    * ------
    *  0100 --> equal a
    *
    *
    *
*/
int AddWithoutPostiveSign2(int n1, int n2)
{
    while(n2)
    {
        unsigned carry = n1 & n2;
        n1 = n1 ^ n2;
        n2 = carry << 1;
    }

    return n1;
}

int AddWithPostIncrement(int num1, int num2)
{
    // for loop will start from 1 and move till the value of
    // second number , first number(a) is incremented in for loop
    for (int i = 1; i <= num2; i++)
        num1++;

    return num1;

}


// subtract two numbers, and return result.
int subtractionWithoutNegativeSign (int num1, int num2)
{
    int borrow;
    while (num2)
    {
        borrow = (~num1) & num2;
        num1 = num1 ^ num2;
        num2 = borrow << 1;
    }
    return num1;
}



