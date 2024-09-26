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
    int x_msb = x >> 31;
    int y_msb = y >> 31;

    printf("DEBUG: x_msb = %d\n", x_msb);
    printf("DEBUG: y_msb = %d\n", y_msb);
    putchar('\n');

    if (x == 0 || y == 0)
        return 0;
    else if ((x_msb == 0 && y_msb == 0) || x == y)
        return signed_high_prod(x, y);
    else if (x_msb != y_msb)
        return ...;
}


int main(void)
{
    //assert(unsigned_high_prod(0, 0) == 0x0);
    //assert(unsigned_high_prod(0, 1) == 0x0);
    //assert(unsigned_high_prod(0, INT_MAX) == 0x0);
    //assert(unsigned_high_prod(0, INT_MIN) == 0x0);
    //assert(unsigned_high_prod(0, ~0) == 0x0);
    //assert(unsigned_high_prod(1, 1) == 0x0);
    //assert(unsigned_high_prod(1, INT_MAX) == 0x0);
    assert(unsigned_high_prod(1, INT_MIN) == 0x0);
    //assert(unsigned_high_prod(1, ~0) == 0x0);
    //assert(unsigned_high_prod(INT_MAX, INT_MAX) == 0x3FFFFFFF);
    //assert(unsigned_high_prod(INT_MAX, INT_MIN) == 0x3FFFFFFF);
    //assert(unsigned_high_prod(INT_MAX, ~0) == 0x7FFFFFFE);
    //assert(unsigned_high_prod(INT_MIN, INT_MIN) == 0x40000000);
    //assert(unsigned_high_prod(INT_MIN, ~0) == 0x7FFFFFFF);

    printf("The test passed!\n");

    return 0;
}
