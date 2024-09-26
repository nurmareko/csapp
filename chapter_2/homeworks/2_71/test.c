#include <stdio.h>
#include <assert.h>

typedef unsigned packed_t;

int xbyte(packed_t word, int bytenum)
{
    return (word >> (bytenum << 3)) & 0xFF;
}

int main(void)
{
    packed_t word = 0x800001FF;

    //assert(xbyte(word, 0) == 0xFFFFFFFF);
    //assert(xbyte(word, 1) == 0x1);
    //assert(xbyte(word, 2) == 0x0);
    //assert(xbyte(word, 3) == 0x80000000);
    //printf("the test passed!\n");

    printf("%x\n", xbyte(word, 3));

    return 0;
}
