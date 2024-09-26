#include <limits.h>
#include <stdbool.h>
#include <stdio.h>

// Determine whether arguments can be multiplied without overflow
int tmult_ok(int x, int y)
{
    int p = x * y;
    // Either x is zero, or dividing p by x gives y
    return !x || p/x == y;
}

// test case for tmult_ok
int test_case(int x, int y, int expected)
{
    int actual = tmult_ok(x, y);

    if (actual == expected) {
        printf("The test passed!\n");
    } else
        printf("Actual value [%d] differs from [%d], the expected value\n", actual, expected);
}

int main(void)
{
    // no overflow
    test_case(0, 0, true);
    test_case(INT_MIN, 0, true);
    test_case(INT_MAX, 0, true);
    test_case(INT_MIN, 1, true);
    test_case(INT_MAX, 1, true);
    // overflow
    test_case(INT_MIN, 2, false);
    test_case(INT_MAX, 2, false);
    test_case(INT_MIN, INT_MIN, false);
    test_case(INT_MAX, INT_MAX, false);
    test_case(INT_MIN, INT_MAX, false);

    return 0;
}
