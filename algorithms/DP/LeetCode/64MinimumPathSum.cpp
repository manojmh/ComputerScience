/**
https://leetcode.com/problems/minimum-path-sum/
Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right,
which minimizes the sum of all numbers along its path.
Note: You can only move either down or right at any point in time.
Example 1:
Input: grid = [[1,3,1],[1,5,1],[4,2,1]]
Output: 7
Explanation: Because the path 1 → 3 → 1 → 1 → 1 minimizes the sum.
Example 2:
Input: grid = [[1,2,3],[4,5,6]]
Output: 12
Constraints:
m == grid.length
n == grid[i].length
1 <= m, n <= 200
0 <= grid[i][j] <= 100
Intution: https://www.youtube.com/watch?v=BzTIOsC0xWM&list=PL-Jc9J83PIiG8fE6rj9F5a6uyQ5WPdqKy&index=7
**/
class Solution {
public:
  int minPathSum(vector<vector<int>>& grid) {
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> t(n, vector<int>(m, INT_MAX));
    for(int i=n-1; i>=0; i--) {
      for(int j=m-1; j>=0; j--) {
        if(i==n-1 && j==m-1) t[i][j] = grid[i][j];
        else if(i==n-1) t[i][j] = t[i][j+1] + grid[i][j];
        else if(j==m-1) t[i][j] = t[i+1][j] + grid[i][j];
        else t[i][j] = grid[i][j] + min(t[i][j+1], t[i+1][j]);
      }
    }
    return t[0][0];
  }
};
