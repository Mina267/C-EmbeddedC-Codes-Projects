#ifndef binary_H_
#define binary_H_

// Count number of 1's
char ones_cnt(unsigned int num);
void print_binary(unsigned int num);
void print_binary_z(unsigned int num);
// Reverse binary number
unsigned char reverse_8bits(unsigned char num);
unsigned int reverse_32bits(unsigned int num);
unsigned int toggle_bit(unsigned int num, unsigned char bit);
unsigned int set_bit(unsigned int num, unsigned char bit);
unsigned int clear_bit(unsigned int num, unsigned char bit);
unsigned char read(unsigned int num, unsigned char bit);
void print_binaryLLU_z(unsigned long long num);
// Swap 4 bytes
void swap4Bytes (int *num);
// Swap 4 bytes
void swap_4bytes (int *num);

#endif // binary_H_
