/**
https://www.interviewbit.com/old/problems/water-flow/
Given an N x M matrix A of non-negative integers representing the height of each unit cell in a continent,
the "Blue lake" touches the left and top edges of the matrix and the "Red lake" touches the right and bottom edges.
Water can only flow in four directions (up, down, left, or right) from a cell to another one with height equal or lower.
Find the number of cells from where water can flow to both the Blue and Red lake.
Problem Constraints
1 <= M, N <= 1000
1 <= A[i][j] <= 109
Input Format
First and only argument is a 2D matrix A.
Output Format
Return an integer denoting the number of cells from where water can flow to both the Blue and Red lake.
Example Input
Input 1:
A = [
     [1, 2, 2, 3, 5]
     [3, 2, 3, 4, 4]
     [2, 4, 5, 3, 1]
     [6, 7, 1, 4, 5]
     [5, 1, 1, 2, 4]
   ]
Input 2:
A = [
     [2, 2]
     [2, 2]
   ]
Example Output
Output 1:7
Output 2:4
Example Explanation
Explanation 1:
Blue Lake ~   ~   ~   ~   ~ 
      ~  1   2   2   3  (5) *
      ~  3   2   3  (4) (4) *
      ~  2   4  (5)  3   1  *
      ~ (6) (7)  1   4   5  *
      ~ (5)  1   1   2   4  *
         *   *   *   *   * Red Lake
Water can flow to both lakes from the cells denoted in parentheses.
Explanation 2: Water can flow from all cells.
**/
int posX[] = {-1,0,0,1};
int posY[] = {0,-1,1,0};
typedef pair<int, int> iPair;
void bfs(int i, int j, vector<vector<int> > &A, vector<vector<bool> > &visited) {
  queue<iPair> q;
  q.push({i,j});
  visited[i][j] = true;
  while(!q.empty()) {
    i = q.front().first;
    j = q.front().second;
    q.pop();
    for(int p=0; p<4; p++) {
    int ni = i + posX[p];
    int nj = j + posY[p];
    if(ni>=0 && ni<A.size() && nj>=0 && nj<A[0].size() &&
       !visited[ni][nj] && A[i][j] <= A[ni][nj]){
      visited[ni][nj] = true;
      q.push({ni, nj});
    }
    }
  }
}
int Solution::solve(vector<vector<int> > &A) {
  vector<vector<bool>> visitedB(A.size(), vector<bool>(A[0].size(), false));
  vector<vector<bool>> visitedR(A.size(), vector<bool>(A[0].size(), false));
  for(int i=0; i<A.size(); i++)
    bfs(i, 0, A, visitedB);

  for(int j=0; j<A[0].size(); j++)
    bfs(0, j, A, visitedB);

  for(int i=A.size()-1; i>=0; i--)
    bfs(i, A[0].size()-1, A, visitedR);

  for(int j=A[0].size()-1; j>=0; j--)
    bfs(A.size()-1, j, A, visitedR);
  int count  = 0;
  for(int i=0; i<A.size(); i++) {
    for(int j=0; j<A[i].size(); j++) {
      if(visitedB[i][j] == true && visitedR[i][j] == true) {
        //cout << i << " " << j << " " << A[i][j] << endl;
        count++;
      }
    }
  }
  return count;
}
