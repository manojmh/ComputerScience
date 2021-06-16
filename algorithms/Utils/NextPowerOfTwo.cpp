/**
https://stackoverflow.com/questions/466204/rounding-up-to-next-power-of-2
**/
int nextPowerOfTwo(int x) {
  return pow( 2, ceil( log(x)/log(2) ) );
}
