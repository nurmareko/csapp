#include <stdio.h>
#include <stdbool.h>

// return 1 if Any bit in the least significant byte of x equals 1
int expression_c(int x)
{
    return ((x & 0xff) && x);
}

void test_case(int x, int expected)
{
    int actual = expression_c(x);

    if (actual == expected)
        printf("The test passed!\n");
    else
        printf("The actual value [%d] differs from [%d], the expected value.\n", actual, expected);
}

int main(void)
{
    test_case(0x0, false);   // 0...0 00000000
    test_case(0x100, false); // 0...0 00000001 00000000
    test_case(0x101, true);  // 0...0 00000001 00000001
    test_case(0x80, true);   // 0...0 00000000 10000000
    test_case(0x55, true);   // 0...0 00000000 01010101
    test_case(0xFF, true);   // 0...0 00000000 11111111

    return 0;
}
