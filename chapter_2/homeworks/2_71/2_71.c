// A. What is wrong with this code?
// when the value of the designated byte is negative, the
// function fail to sign extend it.

// B Give a correct implementation of the function that uses
// only left and right shifts, along with one subtraction.
#include <stdio.h>
#include <assert.h>

typedef unsigned packed_t;

int xbyte(packed_t word, int bytenum)
{
    return (int) (word << (24 - (bytenum << 3))) >> 24;
}

int main(void)
{
    packed_t word = 0x800001FF;

    assert(xbyte(word, 0) == 0xFFFFFFFF);
    assert(xbyte(word, 1) == 0x1);
    assert(xbyte(word, 2) == 0x0);
    assert(xbyte(word, 3) == 0xFFFFFF80);
    printf("the test passed!\n");

    //printf("%d\n", xbyte(word, 3));
    //printf("%d", (char) 0x80);

    return 0;
}
