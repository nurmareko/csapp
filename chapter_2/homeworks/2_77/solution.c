#include <stdio.h>
#include <assert.h>

// A. K = 17
int a(int x)
{
    return (x << 4) + x;
}

// B. K = -7
int b(int x)
{
    // -a + b = b - a
    // return -(x << 3) + x;
    return x - (x << 3);
}

// C. K = 60
int c(int x)
{
    // x * K
    return (x << 6) - (x << 2);
}

// D. K = -112
int d(int x)
{
    // -a + b = b - a
    // return -(x << 7) + (x << 4);
    return (x << 4) - (x << 7);
}

int main(void)
{
    assert(a(-3) == -51);
    assert(a(-2) == -34);
    assert(a(-1) == -17);
    assert(a( 0) ==   0);
    assert(a( 1) ==  17);
    assert(a( 2) ==  34);
    assert(a( 3) ==  51);

    assert(b(-3) ==  21);
    assert(b(-2) ==  14);
    assert(b(-1) ==   7);
    assert(b( 0) ==   0);
    assert(b( 1) ==  -7);
    assert(b( 2) == -14);
    assert(b( 3) == -21);

    assert(c(-3) == -180);
    assert(c(-2) == -120);
    assert(c(-1) ==  -60);
    assert(c( 0) ==    0);
    assert(c( 1) ==   60);
    assert(c( 2) ==  120);
    assert(c( 3) ==  180);

    assert(d(-3) ==  336);
    assert(d(-2) ==  224);
    assert(d(-1) ==  112);
    assert(d( 0) ==    0);
    assert(d( 1) == -112);
    assert(d( 2) == -224);
    assert(d( 3) == -336);

    printf("The test passed!\n");

    return 0;
}
