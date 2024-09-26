// The following code does not run properly on some machines
int bad_int_size_is_32() {
    // Set most significant bit (msb) of 32-bit machine
    int set_msb = 1 << 31;
    // Shift past msb of 32-bit word
    int beyond_msb = 1 << 32;

    // set_msb is nonzero when word size >= 32
    // beyond_msb is zero when word size <= 32
    return set_msb && !beyond_msb;
}

// name   :
// purpose:
// author : Nurmareko

//=============================================================
// A. In what way does our code fail to comply with the c
//    standard?
// let w be the size of int, The shift amount should be a value
// between 0 and w-1, for some machine that use w < 33 the code
// on line 4 and 6 will raise a warning.
//=============================================================
// B. Modify the code to run properly on any machine for which
// data tykpe int is at least 32 bits.
int int_size_is_32_b(void)
{
    // Set most significant bit (msb) of 32-bit machine
    int set_msb = 1 << 31;
    // Shift past msb of 32-bit word
    int beyond_msb = set_msb << 1;

    // set_msb is nonzero when word size >= 32
    // beyond_msb is zero when word size <= 32
    return set_msb && !beyond_msb;
}
//=============================================================
// C. Modify the code to run properly on any machine for which
// data tykpe int is at least 16 bits.
int int_size_is_32_c(void)
{
    // Set most significant bit (msb) of 32-bit machine
    int set_msb = 1 << 15;
    set_msb = set_msb << 15;
    set_msb = set_msb << 1;
    // Shift past msb of 32-bit word
    int beyond_msb = set_msb << 1;

    // set_msb is nonzero when word size >= 32
    // beyond_msb is zero when word size <= 32
    return set_msb && !beyond_msb;
}
