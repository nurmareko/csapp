#include <stdio.h>

unsigned replace_byte(unsigned val, char n, unsigned char byte_sub)
{
    size_t upper_limit = sizeof(unsigned) - 1;
    char byte = 8;

    if (n < 0 || n > upper_limit)
        return val;
    else
        return (val & ~(0xff << (n * byte))) + (((unsigned) byte_sub) << (n * byte));
}

void test_case(unsigned val, char n, char byte_sub, unsigned expected)
{
    unsigned actual = replace_byte(val, n, byte_sub);

    if (actual == expected)
        printf("The test passed!\n");
    else
        printf("The actual value [%X] differs from [%X], the expected value.\n", actual, expected);
}

int main(void)
{
    test_case(0x12345678, -1, 0xAB, 0x12345678);
    test_case(0x12345678, 4, 0xAB, 0x12345678);
    test_case(0x12345678, 2, 0xAB, 0x12AB5678);
    test_case(0x12345678, 0, 0xAB, 0x123456AB);

    return 0;
}
