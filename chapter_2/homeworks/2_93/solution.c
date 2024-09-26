#include <stdio.h>
#include <assert.h>
#include <math.h>

// Access bit-level representation floating-point number
typedef unsigned float_bits;

// Compute |f|. If f is NaN, then return f.
float_bits float_absval(float_bits f)
{
    unsigned exp = f >> 23 & 0xFF;
    unsigned frac = f & 0x7FFFFF;

    if ((exp == 0xFF) && (frac != 0)) {
        // f is NaN. return f
        return f;
    } else
        return f & 0x7FFFFFFF;
}

int main(void)
{
    // positve
    assert(float_absval(0x4B000000) == 0x4B000000);
    assert(float_absval(0x4B000001) == 0x4B000001);
    assert(float_absval(0x4B7FFFFD) == 0x4B7FFFFD);
    assert(float_absval(0x4B7FFFFE) == 0x4B7FFFFE);
    assert(float_absval(0x4B7FFFFF) == 0x4B7FFFFF);
    // negative
    assert(float_absval(0xCB000000) == 0x4B000000);
    assert(float_absval(0xCB000001) == 0x4B000001);
    assert(float_absval(0xCB7FFFFD) == 0x4B7FFFFD);
    assert(float_absval(0xCB7FFFFE) == 0x4B7FFFFE);
    assert(float_absval(0xCB7FFFFF) == 0x4B7FFFFF);
    // NaN
    assert(float_absval(0x7F800001) == 0x7F800001);
    assert(float_absval(0xFFFFFFFF) == 0xFFFFFFFF);

    printf("The test passed!\n");

    return 0;
}
