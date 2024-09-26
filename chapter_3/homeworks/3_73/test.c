#include <stdio.h>
#include <stdint.h>

int main(void) {
	uint32 x;
	for (x = 0x0; x <= 0xFFFFFFFF; x++) {
		printf("%X\n", x);
		if (x == 0xFFFFFFFF)
			break;
	}
	return 0;
}