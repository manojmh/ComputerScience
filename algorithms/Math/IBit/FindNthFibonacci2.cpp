/** Facebook
Given an integer A you need to find the Ath fibonacci number modulo 109 + 7.
The first fibonacci number F1 = 1
The first fibonacci number F2 = 1
The nth fibonacci number Fn = Fn-1 + Fn-2 (n > 2)
Problem Constraints
1 <= A <= 109.
Input Format
First argument is an integer A.
Output Format
Return a single integer denoting Ath fibonacci number modulo 109 + 7.
Example Input
Input 1:A = 4
Input 2:A = 3
Example Output
Output 1:3
Output 2:2
Example Explanation
Explanation 1: 
F3 = F2 + F1 = 1 + 1 = 2
F4 = F3 + F2 = 2 + 1 = 3
Explanation 2:
F3 = F2 + F1 = 1 + 1 = 2
**/
const int MODVAL = 1000000007;
vector<long> vec_one{1,1,1,0};

vector<long> operator*(vector<long > a, vector<long> b) {
  return {
    ( long( a[0] * b[0] )%MODVAL + long( a[1] * b[2] )%MODVAL)%MODVAL,
    ( long( a[0] * b[1] )%MODVAL + long( a[1] * b[3] )%MODVAL)%MODVAL,
    ( long( a[2] * b[0] )%MODVAL + long( a[3] * b[2] )%MODVAL)%MODVAL,
    ( long( a[2] * b[1] )%MODVAL + long( a[3] * b[3] )%MODVAL)%MODVAL
  };
}

vector<long> power(int n) {
  if(n == 1)
    return vec_one;
  vector<long> nby2 = power(n/2);
  return n%2 ? (nby2 * nby2 * vec_one) : (nby2 * nby2);
}

int Solution::solve(int A) {
  return power(A-1)[0];
}
