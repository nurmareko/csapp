#include <stdio.h>

typedef unsigned char *byte_pointer;

void show_bytes(byte_pointer start, size_t len) {
	int i;
	for (i = 0; i < len; i++)
		printf(" %.2x", start[i]);
	printf("\n");
}

void show_int(int x) {
	show_bytes((byte_pointer) &x, sizeof(int));
}

void show_float(float x) {
	show_bytes((byte_pointer) &x, sizeof(float));
}

void show_pointer(void *x) {
	show_bytes((byte_pointer) &x, sizeof(void *));
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

void test_show_bytes(int val) {
	int ival = val;
	float fval = (float) val;
	int *pval = &val;
	short sval = (short) val;
	long lval = (long) val;
	double dval = (double) val;

	printf("short   ");
	show_short(sval);
	printf("int     ");
	show_int(ival);
	printf("long    ");
	show_long(lval);
	printf("float   ");
	show_float(fval);
	printf("double  ");
	show_double(dval);
	printf("pointer ");
	show_pointer(pval);
}

int main() {
	test_show_bytes(1);
}
