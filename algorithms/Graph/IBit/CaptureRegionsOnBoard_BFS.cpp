/**
Given a 2D character matrix A of size N x M, containing 'X' and 'O', capture all regions surrounded by 'X'.
A region is captured by flipping all 'O's into 'X's in that surrounded region.
Problem Constraints
1 <= N, M <= 103
Input Format
First and only argument 2D character matrix A of size N X M.
Output Format
Make changes to the the input only as matrix is passed by reference.
Example Input
Input 1:
A = [  [X, X, X, X],
      [X, O, O, X],
      [X, X, O, X],
      [X, O, X, X]
   ]
Example Output
Output 1:
A = [  [X, X, X, X],
      [X, X, X, X],
      [X, X, X, X],
      [X, O, X, X]
   ]
Example Explanation
Explanation 1: 'O' in (4,2) is not surrounded by X from below.
**/
typedef pair<int,int> iPair;
int posX[] = {-1,0,0,1};
int posY[] = {0,-1,1,0};
void bfs(set<iPair> &starter, vector<vector<char> > &A, vector<vector<bool>> & visited) {
  for(auto n: starter) {
    int i = n.first;
    int j = n.second;
    queue<iPair> q;
    while(!q.empty()) q.pop();
    q.push({i,j});
    visited[i][j] = true;
    while(!q.empty()) {
      i = q.front().first;
      j = q.front().second;
      q.pop();
      for(int x=0; x<4; x++) {
        int ni = i + posX[x];
        int nj = j + posY[x];
        if(ni>=0 && ni<A.size() && nj>=0 && nj<A[0].size() && 
           !visited[ni][nj] && A[ni][nj] == 'O') {
          q.push({ni, nj});
          visited[ni][nj] = true;
        }
      }
    }
  }
}
void Solution::solve(vector<vector<char> > &A) {
  set<iPair> s;
  vector<vector<bool>> visited(A.size(), vector<bool>(A[0].size(), false));
  for(int i=0; i<A.size(); i++) {
    for(int j=0; j<A[0].size(); j++) {
      if(A[i][j] == 'O') {
        if(i==0 || i==A.size()-1 || j==0 || j==A[0].size()-1) {
          s.insert({i,j});
        }
      }
    }
  }
  bfs(s, A, visited);
  for(int i=0; i<A.size(); i++)
    for(int j=0; j<A[i].size(); j++)
      if(visited[i][j])
        A[i][j] == 'O';
      else
        A[i][j] = 'X';
}
