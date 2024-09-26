#include <stdio.h>
#include <assert.h>

// Access bit-level representation floating-point number
typedef unsigned float_bits;

// Compute -f. If f is NaN, then return f.
float_bits float_negate(float_bits f)
{
    // Decompose bit representation into parts
    unsigned exp = f >> 23 & 0xFF;
    unsigned frac = f & 0x7FFFFF;

    if ((exp == 0xFF) && (frac != 0)) {
        // f is NaN. return f
        return f;
    } else
        return f ^ 0x80000000;
}

int main(void)
{
    // denormalized
    assert(float_negate(0) == 0x80000000);
    assert(float_negate(0x7FFFFF) == 0x807FFFFF);
    assert(float_negate(0x80000000) == 0);
    assert(float_negate(0x807FFFFF) == 0x7FFFFF);
    // normalized
    assert(float_negate(0x800000) == 0x80800000);
    assert(float_negate(0x7F7FFFFF) == 0xFF7FFFFF);
    assert(float_negate(0x80800000) == 0x800000);
    assert(float_negate(0xFF7FFFFF) == 0x7F7FFFFF);
    // infinity
    assert(float_negate(0x7F800000) == 0xFF800000);
    assert(float_negate(0xFF800000) == 0x7F800000);
    // NaN
    assert(float_negate(0x7F800001) == 0x7F800001);
    assert(float_negate(0xFFFFFFFF) == 0xFFFFFFFF);

    printf("The test passed!\n");

    return 0;
}
