#include <stdio.h>

float u2f(unsigned x)
{
    return *(float*)&x;
}

int main(void)
{
    unsigned x = 127 >> 23;
    printf("%d\n", x);

    return 0;
}
