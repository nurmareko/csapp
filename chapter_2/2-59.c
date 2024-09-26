#include <stdio.h>

int main(void)
{
    int x = 0x89ABCDEF;
    int y = 0x76543210;
    int mask = 0xff; // lower byte mask
    int result = (x & mask) + (y & ~mask);

    printf("%x\n", result);

    return 0;
}
