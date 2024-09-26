// name   :
// purpose:
// author : Nurmareko

#include <stdio.h>
#include <assert.h>

int fits_bits(int x, int n)
{
    // perform logical left shift on x by n, the shift need
    // to be in two step in case when n is equal word size of
    // int
    int result = (unsigned) x >> n-1 >> 1;

    // if result == 0 that mean all set bit of x fit within
    // n-bit space
    return (result == 0);
}

int main(void)
{
    assert(fits_bits(0x0, 1) == 1);
    assert(fits_bits(0x1, 1) == 1);
    assert(fits_bits(0x2, 1) == 0);
    assert(fits_bits(0x0,8) == 1);
    assert(fits_bits(0xFF,8) == 1);
    assert(fits_bits(0x100,8) == 0);
    assert(fits_bits(0x0, 32) == 1);
    assert(fits_bits(0xFFFFFFFF, 32) == 1);

    printf("test passed!\n");

    return 0;
}
