#include <stdio.h>
#include <assert.h>
#include <limits.h>

// Divide by power of 2. Assume 0 <= k < w-1
int divide_power2(int x, int k)
{
    // if x & INT_MIN is not zero then x is negative
    int is_negative = x & INT_MIN;

    // add bias if x is negative integer
    is_negative && (x += (1 << k) - 1);

    return x >> k;
}

int mul3div4(int x)
{
    // x * 3
    int product = (x << 1) + x;
    // x / 4
    int quotient = divide_power2(product, 2);

    return quotient;
}

int main(void)
{
    assert(mul3div4(0) == (0 * 3 / 4));
    assert(mul3div4(1) == (1 * 3 / 4));
    assert(mul3div4(2) == (2 * 3 / 4));

    assert(mul3div4(INT_MIN) == (INT_MIN * 3 / 4));
    assert(mul3div4(INT_MAX) == (INT_MAX * 3 / 4));
    assert(mul3div4(-1) == (-1 * 3 / 4));

    printf("The test passed!\n");

    return 0;
}
