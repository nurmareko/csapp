#include <limits.h>
#include <stdbool.h>
#include <stdio.h>

// Determine whether arguments can be added without overflow
int uadd_ok(unsigned x, unsigned y)
{
    unsigned sum = x + y;

    if (sum < x) {
        return false;
    } else
        return true;
}

// test case for uadd_ok
void test_case(unsigned x, unsigned y, int expected)
{
    int actual = uadd_ok(x, y);

    if (actual == expected) {
        printf("The test passed!\n");
    } else
        printf("Actual value [%d] differs from [%d], the expected value\n", actual, expected);
}

int main(void)
{
    // no overflow
    test_case(UINT_MAX, 0, true);
    // overflow
    test_case(UINT_MAX, 1, false);
    test_case(UINT_MAX, 2, false);
    test_case(UINT_MAX, 3, false);

    return 0;
}
