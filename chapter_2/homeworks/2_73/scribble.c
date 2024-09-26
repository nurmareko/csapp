#include <stdio.h>
#include <limits.h>

int main(void)
{
    printf("%X\n", ~(~0U >> 1));

    return 0;
}
