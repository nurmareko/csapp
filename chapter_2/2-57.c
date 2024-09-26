#include <stdio.h>

typedef unsigned char *byte_pointer;

void show_bytes(byte_pointer start, size_t len) {
	int i;
	for (i = 0; i < len; i++)
		printf(" %.2x", start[i]);
	printf("\n");
}

void show_short(short x)
{
    show_bytes((byte_pointer) &x, sizeof(short));
}

void show_long(long x)
{
    show_bytes((byte_pointer) &x, sizeof(long));
}

void show_double(double x)
{
    show_bytes((byte_pointer) &x, sizeof(double));
}

void test_showbytes(int val)
{
	short sval = val;
	long lval = val;
	double dval = val;

	show_short(sval);
	show_long(lval);
	show_double(dval);
}

int main(void)
{
    test_showbytes(1234);
	
    return 0;
}
