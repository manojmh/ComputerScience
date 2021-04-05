/**
https://www.interviewbit.com/problems/implement-power-function/
Implement pow(x, n) % d.
In other words, given x, n and d,
find (xn % d)
Note that remainders on division cannot be negative.
In other words, make sure the answer you return is non negative.
Input : x = 2, n = 3, d = 3
Output : 2
2^3 % 3 = 8 % 3 = 2.
**/
int Solution::pow(int x, int n, int d) {
  if(x < 0) x = (x % d + d) % d;
  if(x == 0) return 0;
  if(n == 0) return 1;
  if(n == 1) return x%d;

  long long temp = pow(x, n/2, d);
  temp = (temp * temp) % d;
  if(n%2 == 1)
    return (x * temp) % d;
  return temp;
}
//Editorial Better Solution:
int Solution::pow(int x, int n, int p) {
  if (n == 0) 
    return 1 % p;

  long long ans = 1, base = x;
  while (n > 0) {
    if (n % 2 == 1) {
      ans = (ans * base) % p;
      n--;
    } 
    else {
      base = (base * base) % p;
      n /= 2;
    }
  }
  if (ans < 0) 
    ans = (ans + p) % p;
  return ans;
}
