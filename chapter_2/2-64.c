// name   : 2-64.c
// purpose: CS:APP3e homework solution
// author : Nurmareko

// Write code to implement the following function:
// /* Return 1 when any odd bit of x equals 1; 0 otherwise.
//    Assume w=32 */
// int any_odd_one(unsigned x);
// Your function should follow the bit-level integer coding
// rules (page 164), except that you may assume that data
// type int has w = 32 bits.

#include <stdio.h>

// return 1 when any odd bit of x equals 1; 0 otherwise.
// assume w=32
int any_odd_one(unsigned x)
{
    // mask off even bits
    int mask = 0xAAAAAAAA;
    int result = x & mask;

    return result != 0;
}

void test_case(unsigned x, int expected)
{
    int actual = any_odd_one(x);

    if (actual == expected)
        printf("The test passed!\n");
    else
        printf("Failed! actual [%d], expected [%d]\n", actual, expected);
}

int main(void)
{
    test_case(0x00000000, 0); // 0...0
    test_case(0x00000001, 0); // 0...01
    test_case(0x00000002, 1); // 0...010
    test_case(0x55555555, 0); // 01...01
    test_case(0xAAAAAAAA, 1); // 10...10
    test_case(0xFFFFFFFF, 1); // 1...1

    return 0;
}
