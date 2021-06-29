/**
Given an array A, of N integers A.
Return the highest product possible by multiplying 3 numbers from the array.
NOTE: Solution will fit in a 32-bit signed integer.
Input Format:
The first and the only argument is an integer array A.
Output Format:
Return the highest possible product.
Constraints:
1 <= N <= 5e5
Example:
Input 1: A = [1, 2, 3, 4]
Output 1: 24
Explanation 1: 2 * 3 * 4 = 24
Input 2: A = [0, -1, 3, 100, 70, 50]
Output 2: 350000
Explanation 2:
70 * 50 * 100 = 350000

Intution:
Do we need to consider all the elements from the array ?
Is it enough to consider just the 3 maximum numbers from the array ? Obviously No.
Product of 2 negative numbers is positive. So, Negative numbers with higher absolute value might also be of interest.
How about maximum 3 elements, and 2 negative elements with the highest absolute value ?
**/
int Solution::maxp3(vector<int> &A) {
  sort(A.begin(), A.end(), greater<int>());
  int mul1 = A[0] * A[1] * A[2];
  int mul2 = A[0] * A[A.size()-1] * A[A.size()-2];
  return max(mul1, mul2);
}
