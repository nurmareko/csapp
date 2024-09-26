#include <stdio.h>
#include <assert.h>

// Access bit-level representation flaoting-point number
typedef unsigned float_bits;

// Compute 0.5*f. If f is NaN, then return f.
float_bits float_half(float_bits f)
{
    // Decompose bit representation into parts
    unsigned sign = f >> 31;
    unsigned exp = f >> 23 & 0xFF;
    unsigned frac = f & 0x7FFFFF;
}

// get the floating point value of x
float u2f(unsigned x) {
  return *(float*) &x;
}

int main(void)
{
    return 0;
}
