// Name   : 2-62.c
// Purpose: CS:APP3e homework solution
// Author : Nurmareko

// 2.62 ◆◆◆
// Write a function int_shifts_are_arithmetic() that yields 1
// when run on a machine that uses arithmetic right shifts for
// data type int and yields 0 otherwise. Your code should work
// on a machine with any word size. Test your code on several
// machines.

#include <stdio.h>

 int int_shifts_are_arithmetic(void)
{
	 int word_size = sizeof(int)<<3;
	 int max_shift = word_size-1;
	 int x = 1 << max_shift; // binary 10...0

    return ((x >> max_shift) == -1);
}

int main(void)
{
    char *shift_type = int_shifts_are_arithmetic() ? "arithmetic" : "logical";

    printf("this machine use %s shift for type int. \n", shift_type);

    return 0;
}
