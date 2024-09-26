#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Illustration of code vulnerability similar to that found in
// Sun's XDR library.
void* copy_elements(void *ele_src[], int ele_cnt, size_t ele_size)
{
    // Allocate buffer for ele_cnt objects, each of ele_size bytes
    // and copy from locations designated by ele_src
    if (umult_ok(ele_cnt, ele_size)) {
        void *result = malloc(ele_cnt * ele_size);
        if (result == NULL)
            // malloc failed
            return NULL;
    } else
        return NULL;
    void *next = result;
    int i;
    for (i = 0; i < ele_cnt; i++) {
        // Copy object i to destination
        memcpy(next, ele_src[i], ele_size);
        // Move pointer to next memory region
        next += ele_size;
    }
    return result;
}

// Determine whether arguments can be multiplied without overflow
int umult_ok(unsigned x, unsigned y)
{
    uint64_t product64 = (uint64_t) x * (uint64_t) y;
    unsigned product32 = (unsigned) product64;

    return (product32 == product64);
}

int main(void)
{
    return 0;
}
