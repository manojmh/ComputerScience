/** GOOGLE
Problem Description
Given an array A of size N. You need to find the sum of Maximum and Minimum element in the given array.
NOTE: You should make minimum number of comparisons.
Problem Constraints
1 <= N <= 105
-109 <= A[i] <= 109

Input Format
First and only argument is an integer array A of size N.

Output Format
Return an integer denoting the sum Maximum and Minimum element in the given array.

Example Input
Input 1:
 A = [-2, 1, -4, 5, 3]
Input 2:
 A = [1, 3, 4, 1]
Example Output
Output 1:
 1
Output 2:
 5
Example Explanation
Explanation 1:
 Maximum Element is 5 and Minimum element is -4. (5 + (-4)) = 1. 
Explanation 2:
 Maximum Element is 4 and Minimum element is 1. (4 + 1) = 5.
**/

struct MinMax {
    int mn;
    int mx;
};

MinMax binarySearch(vector<int> &A, int low, int high) {
  //only one element
  if(low == high) {
      MinMax m;
      m.mn = A[low];
      m.mx = A[low];
      return m;
  }
  //2 elements
  if(low + 1 == high) {
      MinMax m;
      if(A[low] < A[high]) {
          m.mn = A[low];
          m.mx = A[high];
      }
      else {
          m.mn = A[high];
          m.mx = A[low];
      }
      return m;
  }
  //more than 2 elements
  MinMax res, left, right;
  int mid = (low+high)/2;
  left = binarySearch(A, low, mid);
  right = binarySearch(A, mid+1, high);
  if(left.mn < right.mn)
      res.mn = left.mn;
  else
      res.mn = right.mn;

  if(left.mx > right.mx)
      res.mx = left.mx;
  else
      res.mx = right.mx;
  return res;
}
int Solution::solve(vector<int> &A) {
  MinMax m = binarySearch(A, 0, A.size()-1);
  return m.mx + m.mn;
}
