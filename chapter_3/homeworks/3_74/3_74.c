#include <stdio.h>
#include <assert.h>

typedef enum {NEG, ZERO, POS, OTHER} range_t;
typedef unsigned float_bits;

range_t find_range(float x) {
	asm(
        "movq $0, %rax\n\t"
        "movq $1, %rsi\n\t"
        "movq $2, %rdx\n\t"
        "movq $3, %rcx\n\t"
        "vxorps %xmm1, %xmm1, %xmm1\n\t"
        "vucomiss %xmm1, %xmm0\n\t"
        "cmoveq %rsi, %rax\n\t"
        "cmovaq %rdx, %rax\n\t"
        "cmovpq %rcx, %rax\n\t"
	);
}

// Convert bit representation of float to float
float fb2f(float_bits x) {
	union {
		float_bits b;
		float f;
	} converter;
	converter.b = x;
	return converter.f;
}

int main(void)
{
	assert(find_range(fb2f(0xFF7FFFFF)) == NEG);   // smallest negative
	assert(find_range(fb2f(0x80000001)) == NEG);   // largest negative
	assert(find_range(fb2f(0x00000000)) == ZERO);  // zero
	assert(find_range(fb2f(0x80000000)) == ZERO);  // negative zero
	assert(find_range(fb2f(0x00000001)) == POS);   // smallest positive
	assert(find_range(fb2f(0x7F7FFFFF)) == POS);   // largest positive
	assert(find_range(fb2f(0x7F800000)) == POS);   // positive infinity
	assert(find_range(fb2f(0xFF800000)) == NEG);   // negative infinity
	assert(find_range(fb2f(0x7F800001)) == OTHER); // NaN
	assert(find_range(fb2f(0xFF800001)) == OTHER); // NaN

	printf("The test passed!\n");

	return 0;
}
