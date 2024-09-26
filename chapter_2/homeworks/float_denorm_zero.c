#include <stdio.h>
#include <assert.h>

// Access bit-level representation floating-point number
typedef unsigned float_bits;

// If f is denorm, return 0. Otherwise, return f
float_bits float_denorm_zero(float_bits f)
{
    // Decompose bit representation into parts
    unsigned sign = f >> 31;
    unsigned exp = f >> 23 & 0xFF;
    unsigned frac = f & 0x7FFFFF;

    if (exp == 0) {
        // Denormalized. Set fraction to 0
        frac = 0;
    }
    // Reassemble bits
    return (sign << 31) | (exp << 23) | frac;;
}

int main(void)
{
    assert(float_denorm_zero(0) == 0);
    assert(float_denorm_zero(0x807FFFFF) == 0x80000000);
    assert(float_denorm_zero(0x800000) == 0x800000);
    assert(float_denorm_zero(0xFF800000) == 0xFF800000);

    printf("The test passed!\n");

    return 0;
}
