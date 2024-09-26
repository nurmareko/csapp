#include <stdio.h>

typedef unsigned char *byte_pointer;

int is_little_endian(void)
{
    const short x = 1;
    short least_significant_byte = 0x01;
    byte_pointer x_bytes = (byte_pointer) &x;
    short smallest_address_value = x_bytes[0];

    return (least_significant_byte == smallest_address_value);
}

int main(void)
{
    printf(is_little_endian() ? "little endian" : "big endian" "\n");

    return 0;
}
