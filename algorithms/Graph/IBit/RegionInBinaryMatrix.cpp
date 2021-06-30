/**
https://www.interviewbit.com/old/problems/region-in-binarymatrix/
Given a binary matrix A of size N x M.
Cells which contain 1 are called filled cell and cell that contain 0 are called empty cell.
Two cells are said to be connected if they are adjacent to each other horizontally, vertically, or diagonally.
If one or more filled cells are also connected, they form a region. Find the length of the largest region.
Problem Constraints
1 <= N, M <= 102
A[i][j]=0 or A[i][j]=1
Input Format
First argument is a 2D binary matrix Aof size  N x M.
Output Format
Return a single interger denoting the length of largest region.
Example Input
Input 1:
A = [  [0, 0, 1, 1, 0]
       [1, 0, 1, 1, 0]
       [0, 1, 0, 0, 0]
       [0, 0, 0, 0, 1]
   ]
Input 2:
A = [  [1, 1, 1]
       [0, 0, 1]
   ]
Example Output
Output 1: 6
Output 2: 4
Example Explanation
Explanation 1: The largest region is denoted by red color in the matrix:
00110
10110
01000
00001
Explanation 2:The largest region is:
111
001
**/
typedef pair<int,int> iPair;
int posX[] = {-1, -1, -1,  0, 0,  1, 1, 1};
int posY[] = {-1,  0,  1, -1, 1, -1, 0, 1};

int Solution::solve(vector<vector<int> > &A) {
  int maxCount = INT_MIN;;
  for(int i=0; i<A.size(); i++) {
    for(int j=0; j<A[0].size(); j++) {
      if(A[i][j]) {
        int count = 0;
        queue<iPair> q;
        q.push({i,j});
        while(!q.empty()) {
          iPair curPos = q.front();
          q.pop();
          maxCount = max(maxCount, count);
          for(int i=0; i<8; i++) {
            int newX = curPos.first + posX[i];
            int newY = curPos.second + posY[i];
            if(newX>=0 && newX<A.size() &&
              newY>=0 && newY<A[0].size() &&
              A[newX][newY])
            {
              q.push({newX, newY});
              A[newX][newY] = 0;
              count++;
            }
          }
        }
      }
    }
  }
  return maxCount;
}
