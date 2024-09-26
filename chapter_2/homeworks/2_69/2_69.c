// name   :
// purpose:
// author : Nurmareko

#include <stdio.h>
#include <assert.h>

unsigned rotate_left(unsigned x, int n)
{
    int wordsize = sizeof(int) << 3;
    int max_shift = wordsize-1;

    // left shift the lower wordsize-n bits of x
    unsigned lower_rest = x << n;

    // get the n higher bits of x
    unsigned upper_n = x >> max_shift-n >> 1;

    return lower_rest + upper_n;
}

int main(void)
{
    assert(rotate_left(0x12345678, 0) == 0x12345678);
    assert(rotate_left(0x12345678, 4) == 0x23456781);
    assert(rotate_left(0x12345678, 20) == 0x67812345);
    assert(rotate_left(0x12345678, 31) == 0x91A2B3C);
    printf("the test passed!\n");

    return 0;
}
