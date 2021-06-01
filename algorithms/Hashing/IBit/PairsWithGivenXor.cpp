/**
https://www.interviewbit.com/problems/pairs-with-given-xor/
Given an 1D integer array A containing N distinct integers.
Find the number of unique pairs of integers in the array whose XOR is equal to B.
NOTE:
Pair (a, b) and (b, a) is considered to be same and should be counted once.
Problem Constraints
1 <= N <= 105
1 <= A[i], B <= 107
Input Format
First argument is an 1D integer array A.
Second argument is an integer B.
Output Format
Return a single integer denoting the number of unique pairs of integers in the array A whose XOR is equal to B.
Example Input
Input 1:
A = [5, 4, 10, 15, 7, 6]
B = 5
Input 2:
A = [3, 6, 8, 10, 15, 50]
B = 5
Example Output
Output 1:1
Output 2:2
Example Explanation
Explanation 1: (10 ^ 15) = 5
Explanation 2: (3 ^ 6) = 5 and (10 ^ 15) = 5
Hint:
if A^B = C then A^C = B and B^C=A. This is mathematical nature of xor.
Now the problem is similar to finding pair with given sum. Just do xor instead of sum.
Hash[B^A[i]] and in another loop find A[i] if indeices of these two numbers are different, add it to your set.
return set.size();
**/
int Solution::solve(vector<int> &A, int B) {
  map<int, int> m;
  set<int> s;
  for(int i=0; i<A.size(); i++) {
    m[A[i]^B] = i;
  }
  for(int i=0; i<A.size(); i++) {
    if(m.find(A[i]) != m.end())
      if(m[A[i]] != i)
        s.insert(i);
  }
  return s.size()/2;
}
