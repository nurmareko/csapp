#include <stdio.h>
#include <assert.h>

unsigned f2u(float x) {
  return *(unsigned*)&x;
}

// is x less than y?
int float_le(float x, float y) {
    unsigned ux = f2u(x);
    unsigned uy = f2u(y);

    // Get the sign bits
    unsigned sx = ux >> 31;
    unsigned sy = uy >> 31;
    // Get the exp field
    unsigned ex = ux & 0x7F800000;
    unsigned ey = uy & 0x7F800000;
    // Get the fraction field
    unsigned fx = ux & 0x7FFFFF;
    unsigned fy = uy & 0x7FFFFF;

    // is x and y both zero?
    int both_zero = ((ux << 1) == 0) && ((uy << 1) == 0);
    // is denormalize?
    int x_denormalize = ex == 0;
    int y_denormalize = ey == 0;
    // is normalize?
    int x_normalize = !x_denormalize;
    int y_normalize = !y_denormalize;

    int case_1 = (x == y) || both_zero;
    int case_2 = (sx == 1) && (sy == 0);
    int case_3 = (sx == sy) && x_normalize && y_denormalize;
    int case_4 = fx < fy;

    return (case_1 || case_2 || case_3 || case_4);
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
