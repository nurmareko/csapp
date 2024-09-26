#include <stdio.h>
#include <assert.h>

unsigned f2u(float x) {
  return *(unsigned*)&x;
}

int float_le(float x, float y) {
    unsigned ux = f2u(x);
    unsigned uy = f2u(y);

    // Get the sign bits
    unsigned sx = ux >> 31;
    unsigned sy = uy >> 31;

    return x == y || !ux << 1 && !uy << 1 || sx && !sy || x < y;
}

int main(void)
{
    assert(float_le(+0.0, +0.0) == 1);
    assert(float_le(-0.0, -0.0) == 1);
    assert(float_le(+0.0, -0.0) == 1);
    assert(float_le(-0.0, +0.0) == 1);

    assert(float_le(1.0, 1.0) == 1);
    assert(float_le(-1.0, -1.0) == 1);
    assert(float_le(0.013672, 240.0) == 1);

    assert(float_le(1.0, -0.0) == 0);
    assert(float_le(2.0, 1.0) == 0);

    printf("the test passed!\n");

    return 0;
}
