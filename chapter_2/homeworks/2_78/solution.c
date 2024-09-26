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

int main(void)
{
    assert(divide_power2(1230, 0) == (1230 / (1 << 0)));
    assert(divide_power2(6170, 1) == (6170 / (1 << 1)));
    assert(divide_power2( 771, 4) == ( 771 / (1 << 4)));
    assert(divide_power2(  48, 8) == (  48 / (1 << 8)));

    assert(divide_power2(-123, 0) == (-123 / (1 << 0)));
    assert(divide_power2(-123, 1) == (-123 / (1 << 1)));
    assert(divide_power2(-123, 4) == (-123 / (1 << 4)));
    assert(divide_power2(-123, 8) == (-123 / (1 << 8)));

    printf("test passed!\n");

    return 0;
}
