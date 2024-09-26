#include <assert.h>
#include <limits.h>
#include <stdint.h>
#include <stdio.h>

int signed_high_prod(int x, int y)
{
    // compute x * y in 2w-bit
    int64_t product = (int64_t) x * y;
    // the size of int data type in bits
    int int_size = sizeof(int) << 3;
    // shift high-order bits in place of low-order bits
    int high_bits = product >> int_size;

    return high_bits;
}

unsigned unsigned_high_prod(unsigned x, unsigned y)
{
    int signed_product = signed_high_prod(x, y);
    int x_msb = (unsigned) x >> 31;
    int y_msb = (unsigned) y >> 31;

    return signed_product + (x_msb * y) + (y_msb * x);
}

int main(void)
{
    assert(unsigned_high_prod(0, 0) == 0x0);
    assert(unsigned_high_prod(0, 1) == 0x0);
    assert(unsigned_high_prod(0, INT_MAX) == 0x0);
    assert(unsigned_high_prod(0, INT_MIN) == 0x0);
    assert(unsigned_high_prod(0, ~0) == 0x0);
    assert(unsigned_high_prod(1, 1) == 0x0);
    assert(unsigned_high_prod(1, INT_MAX) == 0x0);
    assert(unsigned_high_prod(1, INT_MIN) == 0x0);
    assert(unsigned_high_prod(1, ~0) == 0x0);
    assert(unsigned_high_prod(INT_MAX, INT_MAX) == 0x3FFFFFFF);
    assert(unsigned_high_prod(INT_MAX, INT_MIN) == 0x3FFFFFFF);
    assert(unsigned_high_prod(INT_MAX, ~0) == 0x7FFFFFFE);
    assert(unsigned_high_prod(INT_MIN, INT_MIN) == 0x40000000);
    assert(unsigned_high_prod(INT_MIN, ~0) == 0x7FFFFFFF);

    printf("The test passed!\n");

    return 0;
}
