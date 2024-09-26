#include <assert.h>
#include <limits.h>
#include <stdio.h>

// this solution is incorrect but somehow work on my machine.
// see problem 2.32 (page 130)

// Deetermine whether arguments can be subtracted without
// overflow
int tsub_ok(int x, int y)
{
    // we can see subtraction as x + (-y)
    int sum = x + -y;
    // isolate and get the msb value
    int x_msb = !!(x & INT_MIN);
    int y_msb = !!(-y & INT_MIN);
    int sum_msb = !!(sum & INT_MIN);

    // overflow cannot occur when x and y have different sign
    // or when x, y, and sum have same sign
    return (x_msb != y_msb) || (x_msb == sum_msb);
}

int main(void)
{
    assert(tsub_ok(INT_MAX, -1) == 0);
    assert(tsub_ok(INT_MAX, INT_MIN) == 0);
    assert(tsub_ok(INT_MIN, 1) == 0);
    assert(tsub_ok(INT_MIN, INT_MAX) == 0);
    assert(tsub_ok(INT_MAX, 0) == 1);
    assert(tsub_ok(INT_MAX, INT_MAX) == 1);
    assert(tsub_ok(INT_MIN, 0) == 1);
    assert(tsub_ok(INT_MIN, INT_MIN) == 1);
    assert(tsub_ok(2, 3) == 1);

    printf("The test passed!\n");

    return 0;
}
