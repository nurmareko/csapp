// name   : 2-66.c
// purpose: CS:APP3e homework solution
// author : Nurmareko

// 2.66◆◆◆
// Write code to implement the following function:
// /*
//  * Generate mask indicating leftmost 1 in x. Assume w=32.
//  * For example, 0xFF00 -> 0x8000, and 0x6600 --> 0x4000.
//  * If x = 0,then return 0.
//  */
// int leftmost_one(unsigned x);
//
//   Your function should follow the bit-level integer coding rules (page164),
// except that you may assume that data type int has w = 32 bits.
//   Your code should contain a total of atmost 15 arithmetic, bitwise, and
// logical operations.
//   Hint:First transform x into a bit vector of the form [0...011...1].

#include <stdio.h>

// Generate mask indicating leftmost 1 in x. Assume w=32.
// For example, 0xFF00 -> 0x8000, and 0x6600 --> 0x4000.
// If x = 0,then return 0.
int leftmost_one(unsigned x)
{
    // solution from
    // https://dreamanddead.github.io/CSAPP-3e-Solutions/chapter2/2.66/

    // mask on bits to the right of leftmost 1-bit
    x |= x >> 1;
    x |= x >> 2;
    x |= x >> 4;
    x |= x >> 8;
    x |= x >> 16;

    return (x >> 1) + (x && 1);
}

int test_case(unsigned x, int expected)
{
    int actual = leftmost_one(x);

    if (actual == expected)
        printf("The test passed!\n");
    else
        printf("Failed! actual [%.8X], expected [%.8X]\n", actual, expected);
}

int main(void)
{
    test_case(0x0, 0x0);
    test_case(0x1, 0x1);
    test_case(0xFF00, 0x8000);
    test_case(0x6600, 0x4000);
    test_case(0xFFFFFFFF, 0x80000000);

    return 0;
}
