#include <stdio.h>

// Get most significant byte from x
int get_msb(int x)
{
    // Shift by w-8
    int shift_val = (sizeof(int)-1)<<3;
    // Arithmetic shift
    int xright = x >> shift_val;
    // Zero all but LSB
    return xright & 0xFF;
}

int main(void)
{
    int result = get_msb(0xABCDEF12);

    printf("%X\n", result);

    return 0;
}
