#include <stdio.h>
#include <assert.h>
#include <limits.h>

int threefourths(int x)
{
    int lower2 = x & 3; // isolate lower two digits of x
    int is_negative = x & INT_MIN;

    // perform division by 4
    is_negative && (x += (1 << 2) - 1);
    int div4 = x >> 2;

    // perform multiplication by 3
    int result = (div4 << 1) + div4;

    // adjust result
    // is x negative and x lower 2 digits is 00?
    int adjust_1 = is_negative  && (lower2 == 1);
    // is x positive and x lower 2 digits is 11?
    int adjust_2 = !is_negative && (lower2 == 3);
    // is x negative and x lower 2 digits is 10?
    int adjust_3 = is_negative  && (lower2 == 2);
    // is x positive and x lower 2 digits is 10?
    int adjust_4 = !is_negative && (lower2 == 2);

    // adjust value by -2
    adjust_1 && (result -= 2) ||
    // adjust value by +2
    adjust_2 && (result += 2) ||
    // adjust value by -1
    adjust_3 && (result -= 1) ||
    // adjust value by +1
    adjust_4 && (result += 1);

    return result;
}

int main(void)
{
    assert(threefourths(-20) == -15);
    assert(threefourths(-19) == -14);
    assert(threefourths(-18) == -13);
    assert(threefourths(-17) == -12);
    assert(threefourths(-16) == -12);
    assert(threefourths(-15) == -11);
    assert(threefourths(-14) == -10);
    assert(threefourths(-13) == -9);
    assert(threefourths(-12) == -9);
    assert(threefourths(-11) == -8);
    assert(threefourths(-10) == -7);
    assert(threefourths(-9) == -6);
    assert(threefourths(-8) == -6);
    assert(threefourths(-7) == -5);
    assert(threefourths(-6) == -4);
    assert(threefourths(-5) == -3);
    assert(threefourths(-4) == -3);
    assert(threefourths(-3) == -2);
    assert(threefourths(-2) == -1);
    assert(threefourths(-1) == 0);
    assert(threefourths(0) == 0);
    assert(threefourths(1) == 0);
    assert(threefourths(2) == 1);
    assert(threefourths(3) == 2);
    assert(threefourths(4) == 3);
    assert(threefourths(5) == 3);
    assert(threefourths(6) == 4);
    assert(threefourths(7) == 5);
    assert(threefourths(8) == 6);
    assert(threefourths(9) == 6);
    assert(threefourths(10) == 7);
    assert(threefourths(11) == 8);
    assert(threefourths(12) == 9);
    assert(threefourths(13) == 9);
    assert(threefourths(14) == 10);
    assert(threefourths(15) == 11);
    assert(threefourths(16) == 12);
    assert(threefourths(17) == 12);
    assert(threefourths(18) == 13);
    assert(threefourths(19) == 14);
    assert(threefourths(20) == 15);

    assert(threefourths(INT_MAX) == 1610612735);
    assert(threefourths(INT_MIN) == -1610612736);

    printf("the test passed!\n");

    return 0;
}
