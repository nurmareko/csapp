// name   :
// purpose:
// author : Nurmareko

#include <stdio.h>
#include <assert.h>

int lower_one_mask(int n)
{
    // because bit index count start from 0 we set n-1
    int n_bit_on = 1 << n-1;

    // right propagate the rightmost 1-bit
    return n_bit_on | (n_bit_on-1);
}

int main(void)
{
    assert(lower_one_mask(1) == 0x1);
    assert(lower_one_mask(6) == 0x3F);
    assert(lower_one_mask(17) == 0x1FFFF);
    assert(lower_one_mask(32) == 0xFFFFFFFF);
    printf("test passed!\n");

    return 0;
}
