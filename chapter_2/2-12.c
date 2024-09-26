#include <stdio.h>

int main(void)
{
    int a, b, c;
    int x = 0x87654321;

    printf("x = %x\n", x);
    a = x & 0xff;
    b = x ^ ~0xff;
    c = x | 0xff;
    printf("B. %.8x\n", b);
    printf("A. %.8x\n", a);
    printf("C. %.8x\n", c);

    return 0;
}
