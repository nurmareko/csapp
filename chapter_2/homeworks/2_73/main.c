#include <stdio.h>
#include <assert.h>
#include <limits.h>

//int saturating_add(int x, int y)
//{
//    int result = x + y;
//
//    if (x > 0 && y > 0 && result <= 0)
//        return INT_MAX;
//    else if (x < 0 && y < 0 && result >= 0)
//        return INT_MIN;
//    else
//        return result;
//}

int saturating_add(int x, int y)
{
    int sum = x + y;
    // bit mask to keep only most significant bit
    int msb_mask = INT_MIN;
    // get msb value
    int x_msb = !!(x & msb_mask);
    int y_msb = !!(y & msb_mask);
    int sum_msb = !!(sum & msb_mask);

    // if x and y msb is 0 but sum msb is 1 positive overflow
    // has occur
    int p_overflow = (x_msb == 0) && (y_msb == 0) && (sum_msb == 1);

    // if x and y msb is 1 but sum msb is 0 negative overflow
    // has occur
    int n_overflow = (x_msb == 1) && (y_msb == 1) && (sum_msb == 0);

    // set sum to saturation value if overflow has occur
    (p_overflow && (sum = INT_MAX)) || (n_overflow && (sum = INT_MIN));

    return sum;
}

int main(void)
{
    assert(saturating_add(INT_MIN, 0) == INT_MIN);
    assert(saturating_add(INT_MIN, -1) == INT_MIN);
    assert(saturating_add(INT_MIN, -20) == INT_MIN);
    assert(saturating_add(INT_MIN, INT_MIN) == INT_MIN);

    assert(saturating_add(0, 0) == 0);
    assert(saturating_add(0, 1) == 1);
    assert(saturating_add(101, 220) == 321);
    assert(saturating_add(INT_MIN, INT_MAX) == -1);

    assert(saturating_add(INT_MAX, 0) == INT_MAX);
    assert(saturating_add(INT_MAX, 1) == INT_MAX);
    assert(saturating_add(INT_MAX, 20) == INT_MAX);
    assert(saturating_add(INT_MAX, INT_MAX) == INT_MAX);

    printf("The test passed!\n");

    return 0;
}
