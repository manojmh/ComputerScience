/** Google Microsoft Amazon Adobe
A robot is located at the top-left corner of an A x B grid (marked ‘Start’ in the diagram below).
Path Sum: Example 1
The robot can only move either down or right at any point in time.
The robot is trying to reach the bottom-right corner of the grid (marked ‘Finish’ in the diagram below).
Diagram: https://www.interviewbit.com/problems/grid-unique-paths/
How many possible unique paths are there?
Note: A and B will be such that the resulting answer fits in a 32 bit signed integer.
Example : Input : A = 2, B = 2
Output : 2
2 possible routes : (0, 0) -> (0, 1) -> (1, 1) 
              OR  : (0, 0) -> (1, 0) -> (1, 1)

//Solution is based on Pascals triangle
1 
1 1 
1 2 1 
1 3 3 1 
1 4 6 4 1 
1 5 10 10 5 1 
1 6 15 20 15 6 1 
**/
int Solution::uniquePaths(int A, int B) {
  if(A == 0 || B == 0) return 0;
  if(A == 1 || B == 1) return 1;
  vector<vector<int>> dp(A, vector<int>(B, 0));
  for(int i=0; i<A; i++)
    dp[i][0] = 1;
  for(int j=0;j<B; j++)
    dp[0][j] = 1;
  for(int i=1; i<A; i++) {
    for(int j=1; j<B; j++) {
      dp[i][j] = dp[i-1][j] + dp[i][j-1];
    }
  }
  return dp[A-1][B-1];
}
