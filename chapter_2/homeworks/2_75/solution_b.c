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
    unsigned p = (unsigned) signed_high_prod((int) x, (int) y);
    if((int) x < 0){
        p += y;
    }
    if((int) y < 0){
        p += x;
    }
    return p;
}


int main(void)
{
    assert(signed_high_prod(..., ...) == 0x);
    assert(signed_high_prod(..., ...) == 0x);
    assert(signed_high_prod(..., ...) == 0x);
    assert(signed_high_prod(..., ...) == 0x);
    assert(signed_high_prod(..., ...) == 0x);

    printf("The test passed!\n");

    return 0;
}
