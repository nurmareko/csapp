#include <stdio.h>

// generate x * 3/4 from x = a up to x = b
void generate_threefourths(int a, int b) {
    float x;
    for (x = a; x <= b; x++)
        printf("%d * 3/4 = %.2f\n",(int) x, (x * 3/4));
}

void int_to_bin(int num) {
  char str[9] = {0};
  int i;
  for (i=7; i>=0; i--) {
    str[i] = (num&1)?'1':'0';
    num >>= 1;
  }
  printf("%s\n", str);
}

void generate_binary(int a, int b) {
    for (; a <= b; a++) {
        printf("%d ", a);
        int_to_bin(a);
    }
}

int generate_unadjusted(int a, int b)
{
    int x;
    for (x = a; x <= b; x++)
        printf("(%d / 4) * 3 = %d\n", x, ((x / 4) * 3));
}

int main(void)
{
    generate_threefourths(-20, 20);
    //generate_binary(-20, 20);
    //generate_unadjusted(-20, 20);

    return 0;
}
