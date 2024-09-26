#include <stdio.h>
#include <stdbool.h>

// D. Any bit in the most significant byte of x equals 0.
int expression_d(int x)
{
    int byte = 8;
    int shift_value = (sizeof(int)-1) * byte;
    int x_higher = x & (0xFF << shift_value);
    return !(x_higher && x_higher);
}

void test_case(int x, int expected)
{
    int actual = expression_d(x);

    if (actual == expected)
        printf("The test passed!\n");
    else
        printf("The actual value [%d] differs from [%d], the expected value.\n", actual, expected);
}

int main(void)
{
    test_case(0x0, true);         // 00000000 0...0
    test_case(0xAAAAAA, true);    // 00000000 10101010...10101010
    test_case(0xFEFFFFFF, true);  // 11111110 11111111...11111111
    test_case(0xFF000000, false); // 11111111 00000000...00000000
    test_case(0xFFFFFFFF, false); // 11111111 11111111...11111111

    return 0;
}
