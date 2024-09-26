#include <stdio.h>

void f(int maxbytes) {
    if (maxbytes - (signed) sizeof(int) >= 0)
        printf("%d\n", maxbytes - sizeof(int));
}

int main(void)
{
    f(5);
    f(4);
    f(3);
    f(2);
    f(1);
    f(0);
    f(-1);

    return 0;
}
