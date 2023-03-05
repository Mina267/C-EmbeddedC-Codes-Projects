#include "Project.h"




// Count number of 1's
char ones_cnt(unsigned int num)
{
    char cnt = 0;
    while (num)
    {
        if (num & 1)
        {
            cnt++;
        }
        num = num >> 1;
    }

    return cnt;
}

void print_binary(unsigned int num)
{
    unsigned int bit_len = 1 << (int_size - 1) ;
    bool flag = false;
    while (bit_len)
    {
        if (num & bit_len)
        {
            printf("1");
            flag = true;
        }
        else if (flag)
        {
            printf("0");
        }
        bit_len = bit_len >> 1;
    }
    printf("\n");
}

void print_binary_z(unsigned int num)
{
    unsigned int bit_len = 1 << (SIZEOF_INT - 1) ;
    int cnt = 0;
    while (bit_len)
    {
        cnt++;
        if (num & bit_len)
            printf("1");

        else
            printf("0");

        if (cnt % 4 == 0)
        {
            printf(" ");
        }

        bit_len = bit_len >> 1;
    }
    printf("\n");
}

void print_binaryLLU_z(unsigned long long num)
{
    unsigned long long bit_len = 1 << (LONGLONG_SIZE - 1) ;
    while (bit_len)
    {
        if (num & bit_len)
            printf("1");

        else
            printf("0");

        bit_len = bit_len >> 1;
    }
    printf("\n===========================\n");
}

// Reverse binary number
unsigned char reverse_8bits(unsigned char num)
{
    num = (num & 0xF0) >> 4 | (num & 0x0F) << 4;
    num = (num & 0xCC) >> 2 | (num & 0x33) << 2;
    num = (num & 0xAA) >> 1 | (num & 0x55) << 1;
    return num;
}

unsigned int reverse_32bits(unsigned int num)
{
        unsigned int r, len;
        r = 0;
        len = int_size;

        // r = 0000 0000 | 0000 0001  --> 0000 0001
        // r = 0000 0010 | 0000 0000  --> 0000 0010
        // r = 0000 0100 | 0000 0001  --> 0000 0101
        // r = 0000 1010 | 0000 0000  --> 0000 1010
        // And so on
        while (len--) {
            r = (r << 1) | (num & 1);
            num >>= 1;
        }
    return r;
}

unsigned int toggle_bit(unsigned int num, unsigned char bit)
{
    num = num ^ (1 << bit);
    return num;
}
unsigned int set_bit(unsigned int num, unsigned char bit)
{
    num = num | (1 << bit);
    return num;
}
unsigned int clear_bit(unsigned int num, unsigned char bit)
{
    num = num & (~(1 << bit));
    return num;
}

unsigned char read(unsigned int num, unsigned char bit)
{
    num = num & (1 << bit);
    return num;
}




// Swap 4 bytes
void swap4Bytes (int *num)
{

    int sizeInt = 31;
    int s_bit = 7;

    for(int i = 0; i < 16; i++)
    {
        // IF two bits different toggle bits.
        if ((*num >> (sizeInt - i) & 1) != ((*num >> s_bit) & 1))
        {
            *num = *num ^ (1 << (sizeInt - i));
            *num = *num ^ (1 << s_bit);
        }

        s_bit--;

        // Start to Swap Second byte when first done.
        if (s_bit == -1)
        {
            s_bit = 15;
        }
    }
}


// Swap 4 bytes
void swap_4bytes (int *num)
{
    // move byte 4 to byte 1
    // move byte 3 to byte 2
    // move byte 2 to byte 3
    // move byte 1 to byte 4 then remove unwanted bits by using '&' operator.
    // combine all bytes by using '|' operator.
    *num = ((*num >> 24) & 0xff) |
           ((*num >> 8) & 0xff00) |
           ((*num << 8) & 0x00ff0000) |
           ((* num << 24) & 0xff000000);
}
