#include <limits.h>
#include <stdio.h>
#include <stdbool.h>

// Determine whether armugents can be added without overflow
int tadd_ok(int x, int y)
{
    int sum = x + y;

    if (x > 0 && y > 0 && sum <= 0) { // positive overflow
        return false;
    } else if (x < 0 && y < 0 && sum >= 0) { // negative overflow
        return false;
    } else
        return true;
}

// test case for tadd_ok
int test_case(int x, int y, int expected)
{
    int actual = tadd_ok(x, y);

    if (actual == expected) {
        printf("The test passed!\n");
    } else
        printf("Actual value [%d] differs from [%d], the expected value\n", actual, expected);
}

int main(void)
{
    // negative overflow
    test_case(INT_MIN, -1, false);
    // no overflow
    test_case(INT_MIN, 0, true);
    test_case(INT_MAX, 0, true);
    test_case(420, 420, true);
    test_case(-69, -69, true);
    // positive overflow
    test_case(INT_MAX, 1, false);
}
