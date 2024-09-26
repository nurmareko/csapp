// name   : 2-67.c
// purpose: CS:APP3e homework solution
// author : Nurmareko

int bad_int_size_is_32(void) {
 	// Set most significant bit (msb) of 32-bit machine
 	int set_msb = 1 << 31;
 	// Shift past msb of 32-bit word
 	int beyond_msb = 1 << 32;

 	// set_msb is nonzero when word size >=  32
 	// beyond_msb is zero when word size <= 32
 	return set_msb && !beyond_msb;
 }

// A. In what way does our code fail to comply with the C standard?
// for a machine that have int size (w <= 32) the code on line 6
// (line 9 on this code) will cause a warning because the shift amount
// should be a value between 0 and w-1.

// B. Modify the code to run properly on any machine for which data type int is
//    at least 32 bits.
int int_size_is_32_b(void)
{

}

// C. Modify the code to run properly on any machine for which data type int is
//    at least 16 bits.
int int_size_is_32_c(void)
{

}
