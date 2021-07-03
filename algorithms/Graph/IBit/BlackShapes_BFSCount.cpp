/**
https://www.interviewbit.com/old/problems/black-shapes/
Given N x M character matrix A of O's and X's, where O = white, X = black.
Return the number of black shapes. A black shape consists of one or more adjacent X's (diagonals not included)
Input Format: The First and only argument is a N x M character matrix.
Output Format: Return a single integer denoting number of black shapes.
Constraints:
1 <= N,M <= 1000
A[i][j] = 'X' or 'O'
Example:
Input 1:
A = [ OOOXOOO
      OOXXOXO
      OXOOOXO  ]
Output 1: 3
Explanation:
3 shapes are  :
(i)    X
     X X
(ii)
      X
(iii)
      X
      X
Note: we are looking for connected shapes here.
XXX
XXX
XXX
is just one single connected black shape.
**/
typedef pair<int, int> iPair;
int posX[] = {-1,0,1,0};
int posY[] = {0,-1,0,1};
int bfs(int i, int j, vector<string> &A, vector<vector<bool>> &visited) {
  queue<iPair> q;
  q.push({i,j});
  visited[i][j] = true;
  while(!q.empty()) {
    i = q.front().first;
    j = q.front().second;
    q.pop();
    for(int x=0; x<4; x++) {
      int ni = i + posX[x];
      int nj = j + posY[x];
      if(ni>=0 && ni<A.size() && 
         nj>=0 && nj<A[0].size() &&
         A[ni][nj] == 'X' && !visited[ni][nj])
      {
        q.push({ni, nj});
        visited[ni][nj] = true;
      }
    }
  }
  return 1;
}
int Solution::black(vector<string> &A) {
  int ans = 0;
  vector<vector<bool>> visited(A.size(), vector<bool>(A[0].size(), false));
  for(int i=0; i<A.size(); i++) {
    for(int j=0; j<A[0].size(); j++) {
      if(!visited[i][j] && A[i][j] == 'X')
        ans += bfs(i,j,A,visited);
    }
  }
  return ans;
}
