// Modify the code to run properly on any machine for which
// data tykpe int is at least 16 bits.

#include <stdio.h>

int int_size_is_32(void)
{
    // Set most significant bit (msb) of 32-bit machine
    int set_msb = 1 << 15;
    set_msb = set_msb << 15;
    set_msb = set_msb << 1;
    // Shift past msb of 32-bit word
    int beyond_msb = set_msb << 1;

    // set_msb is nonzero when word size >= 32
    // beyond_msb is zero when word size <= 32
    return set_msb && !beyond_msb;
}

int main(void)
{
    if (int_size_is_32())
        printf("int size is 32\n");
    else
        printf("int size is not 32\n");

    return 0;
}
