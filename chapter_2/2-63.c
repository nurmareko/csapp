// Name   : 2-63.c
// Purpose: CS:APP3e homework solution
// Author : Nurmareko

// NOTE: This problems does not conform the rules on page 164.
// 2.63 ◆◆◆
// Fill in code for the following C functions. Function srl
// performs a logical right shift using an arithmetic right
// shift (given by value xsra), followed by other operations
// not including right shifts or division. Function sra
// performs an arithmetic right shift using a logical right
// shift (given by value xsrl), followed by other operations
// not including right shifts or division. You may use the
// computation 8*sizeof(int) to determine w, the number of
// bits in data type int. The shift amount k can range from 0
// to w −1.

#include <stdio.h>

// srl: Shift Right Logically
unsigned srl(unsigned x, int k)
{
    // Perform shift arithmetically
    unsigned xsra = (int) x >> k;
    int word_size = sizeof(unsigned)*8;
    // mask off higher k bit
    unsigned bitmask = ~((unsigned) ~0 << word_size-k);

    return xsra & bitmask;
}

// sra: Shift Right Arithmetically
int sra(int x, int k)
{
    int word_size = 8*sizeof(int);
    int max_shift = word_size-1;
    // Perform shift logically
    int xsrl = (unsigned) x >> k;
    // determine the value of most significant bit of x
    int msb = (x & (~0 << max_shift)) ? 1 : 0;
    // determine the proper higher k-bit
    if (msb == 0)
        // return xsrl unchanged
        return xsrl;
    else
        // mask on xsrl higher k-bit
        return xsrl | (~0 << word_size-k);
}

void test_case_srl(unsigned x, int k, unsigned expected)
{
    unsigned actual = srl(x, k);

    if (actual == expected)
        printf("The test passed!\n");
    else
        printf("Failed! actual [%.8X], expected [%.8X]\n", actual, expected);
}

void test_case_sra(int x, int k, int expected)
{
    int actual = sra(x, k);

    if (actual == expected)
        printf("The test passed!\n");
    else
        printf("Failed! actual [%.8X], expected [%.8X]\n", actual, expected);
}

int main(void)
{
    test_case_srl(0x00000000, 8, 0x00000000); // 0...0
    test_case_srl(0x55555555, 8, 0x00555555); // 01...01
    test_case_srl(0xAAAAAAAA, 8, 0x00AAAAAA); // 10...10
    test_case_srl(0xFFFFFFFF, 8, 0x00FFFFFF); // 1...1

    test_case_sra(0x00000000, 8, 0x00000000); // 0...0
    test_case_sra(0x55555555, 8, 0x00555555); // 01...01
    test_case_sra(0xAAAAAAAA, 8, 0xFFAAAAAA); // 10...10
    test_case_sra(0xFFFFFFFF, 8, 0xFFFFFFFF); // 1...1

    return 0;
}
