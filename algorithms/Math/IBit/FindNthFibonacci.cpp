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
#define mod 1000000007

void multiply(long F[2][2], long M[2][2]) {
  long x = ((((F[0][0]%mod) * (M[0][0]%mod))%mod) + (((F[0][1]%mod) * (M[1][0]%mod))%mod))%mod;
  long y = ((((F[0][0]%mod) * (M[0][1]%mod))%mod) + (((F[0][1]%mod) * (M[1][1]%mod))%mod))%mod;
  long z = ((((F[1][0]%mod) * (M[0][0]%mod))%mod) + (((F[1][1]%mod) * (M[1][0]%mod))%mod))%mod;
  long w = ((((F[1][0]%mod) * (M[0][1]%mod))%mod) + (((F[1][1]%mod) * (M[1][1]%mod))%mod))%mod;
  F[0][0] = x;
  F[0][1] = y;
  F[1][0] = z;
  F[1][1] = w;
}

void power(long F[2][2], int n) {
  if(n == 0 || n == 1)
   return;
  long M[2][2] = {{1, 1}, {1, 0}};

  power(F, n / 2);
  multiply(F, F);

  if (n % 2 != 0)
    multiply(F, M);
}

int Solution::solve(int n) {
  long F[2][2] = {{1, 1}, {1, 0}};
  if (n == 0)
      return 0;
  power(F, n - 1);
  return (int)F[0][0];
}
