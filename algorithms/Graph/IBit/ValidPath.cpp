/**
There is a rectangle with left bottom as  (0, 0) and right up as (x, y). There are N circles such that their centers are inside the rectangle.
Radius of each circle is R. Now we need to find out if it is possible that we can move from (0, 0) to (x, y) without touching any circle.
Note : We can move from any cell to any of its 8 adjecent neighbours and we cannot move outside the boundary of the rectangle at any point of time.
Input Format
1st argument given is an Integer x.
2nd argument given is an Integer y.
3rd argument given is an Integer N, number of circles.
4th argument given is an Integer R, radius of each circle.
5th argument given is an Array A of size N, where A[i] = x cordinate of ith circle
6th argument given is an Array B of size N, where B[i] = y cordinate of ith circle
Output Format
Return YES or NO depending on weather it is possible to reach cell (x,y) or not starting from (0,0).
Constraints
0 <= x, y, R <= 100
1 <= N <= 1000
Center of each circle would lie within the grid
For Example
Input:
x = 2
y = 3
N = 1
R = 1
A = [2]
B = [3]
Output: NO
Explanation: There is NO valid path in this case
**/
typedef pair<int, int> iPair;
int posX[] = {-1, -1, -1,  0,  0,  1, 1, 1};
int posY[] = {-1,  0,  1, -1,  1, -1, 0, 1};

bool isValid(vector<int> &X, vector<int> &Y, int x, int y, int r, vector<vector<bool>> &visited) {
  if(x>=0 && x<visited.size() && y>=0 && y<visited[0].size()) {
    for(int k=0; k<X.size(); k++) {
      if(((X[k]-x)*(X[k]-x) + (Y[k]-y) * (Y[k]-y)) <= r*r) {
        return false;
      }
    }
    return (!visited[x][y]);
  }
  return false;
}

string Solution::solve(int x, int y, int n, int r, vector<int> &X, vector<int> &Y) {
  queue<iPair> q;
  q.push({0,0});
  vector<vector<bool>> visited(x+1, vector<bool>(y+1, false));
  visited[0][0] = true;
  while(!q.empty()) {
    int ux = q.front().first;
    int uy = q.front().second;
    if(ux == x && uy == y)
      return "YES";
    q.pop();
    for(int i=0; i<8; i++) {
      int newX = ux+posX[i];
      int newY = uy+posY[i];

      if(isValid(X, Y, newX, newY, r, visited)) {
        q.push({newX, newY});
        visited[newX][newY] = true;
      }
    }
  }
  return "NO";
}
