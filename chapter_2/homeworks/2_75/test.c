#include <stdio.h>
#include <stdint.h>
#include <limits.h>

int main(void)
{
    int64_t x = (int64_t)  INT_MIN * INT_MIN;

    printf("%.16x\n", x);

    return 0;
}
