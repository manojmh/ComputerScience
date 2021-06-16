/**
https://www.geeksforgeeks.org/program-to-find-whether-a-no-is-power-of-two/
Time complexity : O(1)
Space complexity : O(1) 
**/
bool isPowerOfTwo (int x) {
  /* First x in the below expression is for the case when x is 0 */
  return x && (!(x&(x-1)));
}
