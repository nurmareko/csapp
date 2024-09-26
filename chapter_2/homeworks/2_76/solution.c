#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void *calloc(size_t nmemb, size_t size)
{
    size_t total_size = nmemb * size;

    if ((total_size == 0) || (total_size < nmemb))
        return NULL;
    else
        return memset(malloc(total_size), 0, total_size);
}

int main(void)
{
    return 0;
}
