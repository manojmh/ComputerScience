/**
Space and time efficient Binomial Coefficient
Input: n = 4 and k = 2
Output: 6
Explanation: 4 C 2 is 4!/(2!*2!) = 6

Input: n = 5 and k = 2
Output: 10
Explanation: 5 C 2 is 5!/(3!*2!) = 20

C(n, k) 
= n! / (n-k)! * k!
= [n * (n-1) *....* 1]  / [ ( (n-k) * (n-k-1) * .... * 1) * 
                            ( k * (k-1) * .... * 1 ) ]
After simplifying, we get
C(n, k) 
= [n * (n-1) * .... * (n-k+1)] / [k * (k-1) * .... * 1]

Also, C(n, k) = C(n, n-k)  
// r can be changed to n-r if r > n-r 
**/
unsigned long int binomialCoeff(unsigned int n, unsigned int k) {
  unsigned long int res = 1;
  // Since C(n, k) = C(n, n-k)
  if (k > n - k)
    k = n - k;
  // Calculate value of [n*(n-1)*---*(n-k+1)] /
  // [k*(k-1)*---*1]
  for (int i = 0; i < k; ++i) {
    res *= (n - i);
    res /= (i + 1);
  }
  return res;
}
