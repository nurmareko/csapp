// get the bit-level representation of x
unsigned f2u(float x) {
  return *(unsigned*) &x;
}