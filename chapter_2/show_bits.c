#include <stdio.h>

void printBits(unsigned int num) {
    // Assuming 32-bit integer
    int bits = sizeof(num) * 8;

    for (int i = bits - 1; i >= 0; i--) {
        // Bitwise AND with a mask to check each bit
        int bit = (num >> i) & 1;
        printf("%d", bit);

        // Optionally, add space or other formatting for readability
        if (i % 4 == 0)
            printf(" ");
    }
    printf("\n");
}

int main() {
    unsigned int number = 123; // Change this number to the one you want to visualize

    printf("Bit representation of %u: \n", number);
    printBits(number);

    return 0;
}
