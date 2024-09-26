#include <stdio.h>
#include <stdbool.h>

// return 1 if any bit of x equals 0;
int expression_b(int x)
{
    return !(x && x);
}

void test_case(int x, int expected)
{
    int actual = expression_b(x);

    if (actual == expected)
        printf("The test passed!\n");
    else
        printf("The actual value [%d] differs from [%d], the expected value.\n", actual, expected);
}

int main(void)
{
    test_case(0x0, true);         // 0...0
    test_case(0x1, false);         // 0...01
    test_case(0x80000000, false);  // 10...0
    test_case(0x55555555, false);  // [01]...01
    test_case(0xFFFFFFFF, false);  // 1...1

    return 0;
}
