#include <stdio.h>
#include <assert.h>

int a(int k)
{
    return -1 << k;
}

int b(int k, int j)
{
    return ~(-1 << k) << j;
}

int main(void)
{
    assert(a(0) == 0xFFFFFFFF);
    assert(a(1) == 0xFFFFFFFE);
    assert(a(2) == 0xFFFFFFFC);
    assert(a(7) == 0xFFFFFF80);
    assert(a(8) == 0xFFFFFF00);

    assert(b(0, 0) == 0x00000000);
    assert(b(1, 0) == 0x00000001);
    assert(b(0, 1) == 0x00000000);
    assert(b(1, 1) == 0x00000002);
    assert(b(2, 0) == 0x00000003);
    assert(b(0, 2) == 0x00000000);
    assert(b(2, 2) == 0x0000000C);

    printf("The test passed!\n");

    return 0;
}
