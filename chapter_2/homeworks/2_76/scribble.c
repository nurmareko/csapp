#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

/* rename to avoid conflict */
void* another_calloc(size_t nmemb, size_t size) {
    size_t total_size = nmemb * size;

    if ((total_size == 0) || (total_size < nmemb))
        return NULL;
    else
        return memset(malloc(total_size), 0, total_size);
}

int main(int argc, char* argv[]) {
  void* p;
  p = another_calloc(0x1234, 1);
  assert(p != NULL);
  free(p);

  p = another_calloc(SIZE_MAX, 2);
  assert(p == NULL);
  free(p);
  return 0;
}
