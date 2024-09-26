#include <stdio.h>
#include <assert.h>
#include <math.h>

float u2f(unsigned x) {
  return *(float*) &x;
}

float fpwr2(int x)
{
    int bias = 127;
    int k = 23;
    // Result exponent and fraction
    unsigned exp, frac;
    unsigned u;

    if (x < -bias-k) {
        // Too small. Return 0.0
        exp = 0;
        frac = 0;
    } else if (x < -bias-1) {
        // Denormalized result
        exp = 0;
        frac = 0x400000 >> -bias-x;
    } else if (x < bias+1) {
        // Normalized result.
        exp = x + bias;
        frac = 0;
    } else {
        // Too big. Return +oo
        exp = 0xFF;
        frac = 0;
    }

    // Pack exp and frac into 32 bits
    u = exp << 23 | frac;
    // Return as float
    return u2f(u);
}


int main(void)
{
    // denormalized range
    //assert(fpwr2(-149) == 1); // min
    //assert(fpwr2(-127) == 0x400000); // max
    // normalized range
    //assert(fpwr2(-126) == 0x1000000); // min
    //assert(fpwr2(127) == 0x7F000000); // max
    // out of range
    //assert(fpwr2(-150) == 0); // too small
    //assert(fpwr2(128) == 0x7F800000); // too big

    assert(fpwr2(0) == powf(2,0));
    assert(fpwr2(100) == powf(2,100));
    assert(fpwr2(-100) == powf(2,-100));
    assert(fpwr2(10000) == powf(2,10000));
    assert(fpwr2(-10000) == powf(2,-10000));

    printf("The test passed!");

    return 0;
}
