#include <stdio.h>
#include <assert.h>

// Access bit-level representation floating-point number
typedef unsigned float_bits;

// Compute 2*f. If f is NaN, then return f.
float_bits float_twice(float_bits f)
{
    // Decompose bit representation
    unsigned sign = f >> 31;
    unsigned exp = f >> 23 & 0xFF;
    unsigned frac = f & 0x7FFFFF;

    if (exp == 0xFF) {
        // f is NaN
        return f;
    } else if (exp == 0) {
        // f is denormalized
        return (sign << 31) ^ f<<1;
    } else {
        // f is normalized
        exp++;
        if (exp == 0xFF)
            frac = 0;
        return (sign << 31) | (exp << 23) | frac;
    }
}

// get the floating point value of x
float u2f(float_bits x) {
  return *(float*) &x;
}

// compare float_twice(x) == (2.0 * u2f(x)) for all 2^32 value
// of x
void test_case(void)
{
    float_bits template = 0x4F800000;
    float_bits x;
    unsigned frac = 0;

    for (x = template; frac <= 0x7FFFFF; ++frac, x = (template | frac)) {
        printf("frac = %u\t%f\n\n", frac, (2.0 * u2f(x)));
        assert(u2f(float_twice(x)) == (2.0 * u2f(x)));
    }
    printf("The test passed!\n");
}

int main(void)
{

    // Zero
    assert(u2f(float_twice(0)) == (2 * u2f(0)));
    assert(u2f(float_twice(0x80000000)) == (2 * u2f(0x80000000)));
    // Denormalized
    assert(u2f(float_twice(0x7FFFFF)) == (2 * u2f(0x7FFFFF)));
    assert(u2f(float_twice(0x807FFFFF)) == (2 * u2f(0x807FFFFF)));
    assert(u2f(float_twice(0x400000)) == (2 * u2f(0x400000)));
    assert(u2f(float_twice(0x80400000)) == (2 * u2f(0x80400000)));
    assert(u2f(float_twice(1)) == (2 * u2f(1)));
    assert(u2f(float_twice(0x80000001)) == (2 * u2f(0x80000001)));
    // Normalized
    assert(u2f(float_twice(0x800000)) == (2 * u2f(0x800000)));
    assert(u2f(float_twice(0x80800000)) == (2 * u2f(0x80800000)));
    assert(u2f(float_twice(0x4F800000)) == (2 * u2f(0x4F800000)));
    assert(u2f(float_twice(0x4FFFFFFF)) == (2 * u2f(0x4FFFFFFF)));
    assert(u2f(float_twice(0x7F7FFFFF)) == (2 * u2f(0x7F7FFFFF)));
    assert(u2f(float_twice(0xFF7FFFFF)) == (2 * u2f(0xFF7FFFFF)));
    // NaN
    assert(u2f(float_twice(0x7F800001)));
    assert(u2f(float_twice(0xFF800001)));

    printf("The test passed!\n");

    return 0;
}
