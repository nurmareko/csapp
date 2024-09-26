#include <stdio.h>
#include <limits.h>
#include <assert.h>

int main(void)
{
    //printf("0     = %d\n", 0);
    //printf("1     = %d\n", 1);
    //printf("min   = %d\n", INT_MIN);
    //printf("max   = %d\n", INT_MAX);
    //printf("-1    = %d\n", -1);
    //putchar('\n');
    //printf("-0    = %d\n", -0);
    //printf("-1    = %d\n", -1);
    //printf("-min  = %d\n", -INT_MIN);
    //printf("-max  = %d\n", -INT_MAX);
    //printf("-(-1) = %d\n", -(-1));

    //assert(INT_MIN == INT_MIN);

    printf("%d\n", (-1 > -INT_MIN));

    //printf("the test passed!\n");

    return 0;
}
