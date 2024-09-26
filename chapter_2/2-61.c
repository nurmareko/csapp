// Name   : 2-61.c
// Purpose: CS:APP3e homework solution
// Author : Nurmareko

// 2.61 ◆◆
// Write C expressions that evaluate to 1 when the following
// conditions are true and to 0 when they are false. Assume x
// is of type int.
//
//  A. Any bit of x equals 1.
//  B. Any bit of x equals 0.
//  C. Any bit in the least significant byte of x equals 1.
//  D. Any bit in the most significant byte of x equals 0.
//
// Your code should follow the bit-level integer coding rules
// (page 164), with the additional restriction that you may
// not use equality (==) or inequality (!=) tests.

#include <stdio.h>

int a(int x)
{
    return !!x;
}

int b(int x)
{
    return ~x || ~x;
}

int c(int x)
{
    // mask off rest of bytes while keeping the lower byte
    // unchanged
	int lower_byte = x & 0xff;

    return a(lower_byte);
}

int d(int x)
{
    int one_byte = 8;
	int word_size = sizeof(int)<<3;
	int mask = ~(0xFF << (word_size - one_byte));
    // mask on rest of bytes while keeping the higher byte
    // unchanged
	int higher_byte = x | mask;

    return b(higher_byte);
}

void test_case(int (*function)(int), int x, int expected)
{
    int actual = function(x);

    if (actual == expected)
        printf("The test passed!\n");
    else
        printf("Actual value [%d] differs from [%d], the expected value.\n", actual, expected);
}

int main(void)
{
    //  A. Any bit of x equals 1.
    test_case(a, 0x0, 0);           // 00...00
    test_case(a, 0xAAAAAAAA, 1);    // 01...01
    test_case(a, 0x55, 1);          // 10...10
    test_case(a, 0xFFFFFFFF, 1);    // 11...11
    //  B. Any bit of x equals 0.
    test_case(b, 0x0, 1);           // 00...00
    test_case(b, 0xAAAAAAAA, 1);    // 01...01
    test_case(b, 0x55, 1);          // 10...10
    test_case(b, 0xFFFFFFFF, 0);    // 11...11
    //  C. Any bit in the least significant byte of x equals 1.
    test_case(c, 0x0, 0);           // 0.....0 00000000
    test_case(c, 0xAA, 1);          // 0.....0 10101010
    test_case(c, 0xFF, 1);          // 0.....0 11111111
    test_case(c, 0xAAAAAA00, 0);    // 10...10 00000000
    test_case(c, 0xAAAAAAAA, 1);    // 10...10 10101010
    test_case(c, 0xAAAAAAFF, 1);    // 10...10 11111111
    test_case(c, 0xFFFFFF00, 0);    // 1.....1 00000000
    test_case(c, 0xFFFFFFAA, 1);    // 1.....1 10101010
    test_case(c, 0xFFFFFFFF, 1);    // 1.....1 11111111
    //  D. Any bit in the most significant byte of x equals 0.
    test_case(d, 0x0, 1);           // 00000000 0.....0
    test_case(d, 0xAA000000, 1);    // 10101010 0.....0
    test_case(d, 0xFF000000, 0);    // 11111111 0.....0
    test_case(d, 0xAAAAAA, 1);      // 00000000 10...10
    test_case(d, 0xAAAAAAAA, 1);    // 10101010 10...10
    test_case(d, 0xFFAAAAAA, 0);    // 11111111 10...10
    test_case(d, 0xFFFFFF, 1);      // 00000000 1.....1
    test_case(d, 0xAAFFFFFF, 1);    // 10101010 1.....1
    test_case(d, 0xFFFFFFFF, 0);    // 11111111 1.....1

    return 0;
}
