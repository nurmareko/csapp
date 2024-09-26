// A. Explain why the conditional test in the code always
// succeeds. Hint: The sizeof operator returns a value of
// type size_t

// When an operation is performed where one operand is signed
// and the other is unsigned, C implicitly casts the signed
// argument to unsigned and performs the operations assuming
// the numbers are nonnegative.
// size_t is defined as an unsigned integer, when the value
// of maxbytes is less than sizeof(val) the expression
// maxbytes-sizeof(val) will overflow to positive number

// B. Show how you can rewrite the conditional test to make it
//    work properly.
void copy_int(int val, void *buf, int maxbytes) {
    if (maxbytes-(signed)sizeof(val) >= 0)
        memcpy(buf, (void *) &val, sizeof(val));
}
