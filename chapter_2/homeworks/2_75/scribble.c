#include <stdio.h>
#include <stdint.h>
#include <limits.h>

int main(void)
{
    uint64_t x = (uint64_t) 0x80000000 * (uint64_t) 0xFFFFFFFF;

    printf("%llu\n", x);

    return 0;
}
