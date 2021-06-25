/**
https://www.interviewbit.com/old/problems/min-sum-path-in-matrix/
Given a 2D integer array A of size M x N, you need to find a path from top left to bottom right which minimizes the sum of all numbers along its path.
NOTE: You can only move either down or right at any point in time.
Input Format
First and only argument is an 2D integer array A of size M x N.
Output Format
Return a single integer denoting the minimum sum of a path from cell (1, 1) to cell (M, N).
Example Input
Input 1:
A = [[1, 3, 2]
     [4, 3, 1]
     [5, 6, 1]
    ]
Example Output
Output 1: 9
Example Explanation
Explanation 1:
The path is 1 -> 3 -> 2 -> 1 -> 1
So ( 1 + 3 + 2 + 1 + 1) = 8
**/
int Solution::minPathSum(vector<vector<int> > &A) {
  int m=A.size();
  int n=A[0].size();
  vector<vector<int>> res(m, vector<int>(n, 0));
  for(int i=m-1; i>=0; i--) {
    for(int j=n-1; j>=0; j--) {
      if(i==m-1 && j==n-1)
        res[i][j] = A[i][j];
      else if(i==m-1)
        res[i][j] = A[i][j] + res[i][j+1];
      else if(j==n-1)
        res[i][j] = A[i][j] + res[i+1][j];
      else
        res[i][j] = A[i][j] + min(res[i][j+1], res[i+1][j]);
    }
  }
  return res[0][0];
}
