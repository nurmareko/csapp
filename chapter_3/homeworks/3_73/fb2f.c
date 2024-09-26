#include <stdio.h>

typedef unsigned float_bits;

float fb2f(float_bits x) {
	union {
		float_bits b;
		float f;
	} converter;
	converter.b = x;
	return converter.f;
}


int main(void) {
	printf("%G\n", fb2f(0xFF7FFFFF));
	printf("%G\n", fb2f(0x80000001));
	printf("%G\n", fb2f(0x00000000));
	printf("%G\n", fb2f(0x80000000));
	printf("%G\n", fb2f(0x00000001));
	printf("%G\n", fb2f(0x7F7FFFFF));
	printf("%G\n", fb2f(0x7F800000));
	printf("%G\n", fb2f(0xFF800000));
	printf("%G\n", fb2f(0x7F800001));
	printf("%G\n", fb2f(0xFF800001));

	return 0;
}