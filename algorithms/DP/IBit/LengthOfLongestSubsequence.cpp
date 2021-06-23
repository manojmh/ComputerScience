/**
Given an 1D integer array A of length N, find the length of longest subsequence which is first increasing then decreasing.
Problem Constraints
0 <= N <= 3000
-107 <= A[i] <= 107
Input Format
The first and the only argument contains an integer array A.
Output Format
Return an integer representing the answer as described in the problem statement.
Example Input
Input 1: A = [1, 2, 1]
Input 2: A = [1, 11, 2, 10, 4, 5, 2, 1]
Example Output
Output 1:3
Output 2: 6
Example Explanation
Explanation 1: [1, 2, 1] is the longest subsequence.
Explanation 2: [1 2 10 4 2 1] is the longest subsequence.
**/
int Solution::longestSubsequenceLength(const vector<int> &A) {
  int n = A.size();
  int LIS[n], LDS[n];
  LIS[0] = 0;
  LDS[n-1] = 0;
  for(int i=0; i<n; i++) {
    int mx = 0;
    for(int j=0; j<i; j++) {
      if(A[j]<A[i])
        if(LIS[j] > mx)
          mx = LIS[j];
    }
    LIS[i] = mx+1;
  }
  for(int i=n-1; i>=0; i--) {
    int mx = 0;
    for(int j=n-1; j>i; j--) {
      if(A[j]<A[i]) {
        if(LDS[j] > mx)
          mx = LDS[j];
        }
    }
    LDS[i] = mx+1;
  }
  int mx = 0;
  for(int i=0; i<n; i++)
    mx = max(mx, (LIS[i]+LDS[i]-1));
  return mx;
}
