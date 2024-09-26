#include <stdio.h>
#include <assert.h>

unsigned f2u(float x) {
  return *(unsigned*)&x;
}

//int float_le(float x, float y) {
//    unsigned ux = f2u(x);
//    unsigned uy = f2u(y);
//
//    // Get the sign bits
//    unsigned sx = ux >> 31;
//    unsigned sy = uy >> 31;
//
//    // is x and y both zero?
//    int both_zero = ((ux << 1) == 0) && ((uy << 1) == 0);
//
//    int case_1 = (x == y) || both_zero;
//    int case_2 = (sx == 1) && (sy == 0);
//    int case_3 = (sx == sy) && x < y;
//
//    return (case_1 || case_2 || case_3);
//}

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
