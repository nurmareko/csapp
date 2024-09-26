#include <stdio.h>
#include <assert.h>

// Access bit-level representation floating-point number
typedef unsigned float_bits;

// get the floating point value of x
float u2f(float_bits x) {
  return *(float*) &x;
}

// get the bit-level representation of x
unsigned f2u(float x) {
  return *(float_bits*) &x;
}

int main(void)
{
    //assert(u2f(0x4F800000) == 4294967296.0);
    //assert(f2u(4294967296.0) == 0x4F800000);

    //printf("The test passed!\n");

    return 0;
}
