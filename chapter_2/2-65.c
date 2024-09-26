// name   : 2-65.c
// purpose: CS:APP3e homework solution
// author : Nurmareko

// 2.65◆◆◆◆
// Write code to implement the following function:
// /* Return 1 when x contains an odd number of 1s; 0
//    otherwise. Assume w=32 */
// int odd_ones(unsigned x);
//  Your function should follow the bit-level integer
// coding rules (page 164), except that you may assume
// that data type int has w = 32 bits.
//  Your code should contain a total of atmost 12
// arithmetic, bitwise, and logical operations.

#include <stdio.h>

int odd_ones(unsigned x)
{
    // NOTE: since i failed to think up any solution this
    //       solution is studied from several resources in
    //       the internet.
    // https://stackoverflow.com/questions/21617970/how-can-i-check-if-a-value-has-even-parity-of-bits-or-odd
    // https://catonmat.net/low-level-bit-hacks
    // https://graphics.stanford.edu/~seander/bithacks.html#CountBitsSetNaive
    x ^= x >>  1;
    x ^= x >>  2;
    x ^= x >>  4;
    x ^= x >>  8;
    x ^= x >> 16;

    return x & 1;
}

void test_case(unsigned x, int expected)
{
    int actual = odd_ones(x);

    if (actual == expected)
        printf("The test passed!\n");
    else
        printf("Failed! actual [%d], expected [%d]\n", actual, expected);
}

int main(void)
{
    test_case(0x0, 0);
    test_case(0x1, 1);
    test_case(0x3, 0);
    test_case(0xF, 0);
    test_case(0xFFFFFFFF, 0);

    return 0;
}
