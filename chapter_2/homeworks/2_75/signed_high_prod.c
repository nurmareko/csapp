#include <assert.h>
#include <limits.h>
#include <stdint.h>
#include <stdio.h>

int signed_high_prod(int x, int y)
{
    // compute x * y in 2w-bit, assume w = 32
    int64_t product = (int64_t) x * y;
    // the size of int data type in bits
    int int_size = sizeof(int) << 3;
    // shift high-order bits in place of low-order bits
    int high_bits = product >> int_size;

    return high_bits;
}

int main(void)
{
    assert(signed_high_prod(0, 0) == 0x0);
    assert(signed_high_prod(0, 1) == 0x0);
    assert(signed_high_prod(0, INT_MAX) == 0x0);
    assert(signed_high_prod(0, INT_MIN) == 0x0);
    assert(signed_high_prod(0, ~0) == 0x0);
    assert(signed_high_prod(1, 1) == 0x0);
    assert(signed_high_prod(1, INT_MAX) == 0x0);
    assert(signed_high_prod(1, INT_MIN) == 0xFFFFFFFF);
    assert(signed_high_prod(1, ~0) == 0xFFFFFFFF);
    assert(signed_high_prod(INT_MAX, INT_MAX) == 0x3FFFFFFF);
    assert(signed_high_prod(INT_MAX, INT_MIN) == 0xC0000000);
    assert(signed_high_prod(INT_MAX, ~0) == 0xFFFFFFFF);
    assert(signed_high_prod(INT_MIN, INT_MIN) == 0x40000000);
    assert(signed_high_prod(INT_MIN, ~0) == 0x0);

    printf("The test passed!\n");

    return 0;
}
