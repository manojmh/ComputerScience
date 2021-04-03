/**
Given an integar A.
Compute and return the square root of A.
If A is not a perfect square, return floor(sqrt(A)).
DO NOT USE SQRT FUNCTION FROM STANDARD LIBRARY
Input Format
The first and only argument given is the integer A.
Output Format
Return floor(sqrt(A))
Constraints
1 <= A <= 10^9
For Example
Input 1: A = 11
Output 1: 3
Input 2: A = 9
Output 2: 3
**/
int sqrtHelp(long long low, long long high, long long A) {
  if(high >= low) {
    long long mid = low + (high-low)/2;
    long long mul = mid*mid;
    if(mul == A)
      return mid;
    if(mul > A)
      return sqrtHelp(low, mid-1, A);
    return sqrtHelp(mid+1, high, A);
  }
  return (int)(low*low == A)?low:low-1;
}
int Solution::sqrt(int A) {
  if(A==0) return 0;
  if(A==1 || A==2) return 1;
  return sqrtHelp(2, A, A);
}
//Editorial recursive Solution
int sqrt(int x) {
  if (x == 0) return 0;
  int start = 1, end = x, ans;
  while (start <= end) {
    int mid = (start + end) / 2;
    if (mid <= x / mid) {
      start = mid + 1;
      ans = mid;
    } else {
      end = mid - 1;
    }
  }
  return ans;
}
//Editorial Better Solution:
double ans(double A, double n) {
  return abs(A - n) < 0.001;
}
double better(double A, double n) {
  return (n + A / n) / 2;
}
double sol(double A, double n) {
  if (ans(A/n, n)) return n;
  return sol(A, better(A, n));
}
int Solution::sqrt(int A) {
  return (int)sol(A, 1); 
}
