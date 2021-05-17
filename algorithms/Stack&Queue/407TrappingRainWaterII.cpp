/**
https://leetcode.com/problems/trapping-rain-water-ii/
Given an m x n integer matrix heightMap representing the height of each unit cell in a 2D elevation map,
return the volume of water it can trap after raining.
Example 1:
Input: heightMap = [[1,4,3,1,3,2],[3,2,1,3,2,4],[2,3,3,2,3,1]]
Output: 4
Explanation: After the rain, water is trapped between the blocks.
We have two small pounds 1 and 3 units trapped.
The total volume of water trapped is 4.
Example 2:
Input: heightMap = [[3,3,3,3,3],[3,2,2,2,3],[3,2,1,2,3],[3,2,2,2,3],[3,3,3,3,3]]
Output: 10
Constraints:
m == heightMap.length
n == heightMap[i].length
1 <= m, n <= 200
0 <= heightMap[i][j] <= 2 * 104
**/
class Solution {
public:
  int trapRainWater(vector<vector<int>>& heightMap) {
    if ( heightMap.empty() ) { return 0; }
    int m = heightMap.size();
    int n = heightMap[0].size();
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    vector<vector<int>> visited (m, vector<int> (n, 0));
    vector<vector<int>> dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    int level = 0;
    for ( int i = 0; i < m; ++i ) {
      for ( int j = 0; j < n; ++j ) {
        if ( i == 0 or i == m-1 or j == 0 or j == n-1 ) {
          pq.push(make_pair(heightMap[i][j], i*n+j));
          visited[i][j] = 1;
        }
      }
    }
    int rtn = 0;
    while ( !pq.empty() ) {
      auto curr = pq.top();
      pq.pop();
      int h = curr.first;
      int r = curr.second / n;
      int c = curr.second % n;
      level = max(level, h);    
      for ( int d = 0; d < 4; ++d ) {
        int x = r + dir[d][0];
        int y = c + dir[d][1];
        if ( x < 0 or x >= m or y < 0 or y >= n or visited[x][y] ) { continue; }
        if ( heightMap[x][y] < level) { rtn += level - heightMap[x][y]; }
        pq.push(make_pair(heightMap[x][y], x*n+y));
        visited[x][y] = 1;
      }
    }
    return rtn;
  }
};
