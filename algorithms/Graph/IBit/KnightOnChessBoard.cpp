/**
https://www.interviewbit.com/old/problems/knight-on-chess-board/
Given any source point, (C, D) and destination point, (E, F) on a chess board,
we need to find whether Knight can move to the destination or not.
The above figure details the movements for a knight ( 8 possibilities ).
If yes, then what would be the minimum number of steps for the knight to move to the said point.
If knight can not move from the source point to the destination point, then return -1.
Note: A knight cannot go out of the board.
Input Format:
The first argument of input contains an integer A.
The second argument of input contains an integer B.
=> The chessboard is of size A x B.
The third argument of input contains an integer C.
The fourth argument of input contains an integer D.
=> The Knight is initially at position (C, D).
The fifth argument of input contains an integer E.
The sixth argument of input contains an integer F.
=> The Knight wants to reach position (E, F).
Output Format:
If it is possible to reach the destination point, return the minimum number of moves.
Else return -1.
Constraints:
1 <= A, B <= 500
Example
Input 1:
A = 8
B = 8
C = 1
D = 1
E = 8
F = 8
Output 1: 6
Explanation 1:
The size of the chessboard is 8x8, the knight is initially at (1, 1) and the knight wants to reach position (8, 8).
The minimum number of moves required for this is 6.
**/
typedef pair<int,int> iPair;
int posX[] = {-2,-2,2,2,-1,-1,1,1};
int posY[] = {-1,1,-1,1,-2,2,-2,2};
int Solution::knight(int A, int B, int C, int D, int E, int F) {
  C--,D--,E--,F--;
  if(C==E && D==F) return 0;
  vector<vector<bool>> visited(A, vector<bool>(B, false));
  queue<pair<iPair, int>> q;
  q.push({{C,D}, 0});
  visited[C][D] = true;
  while(!q.empty()) {
    C = q.front().first.first;
    D = q.front().first.second;
    int count = q.front().second;
    q.pop();
    if(C==E && D==F)
      return count;
    for(int x=0; x<8; x++) {
      int ni = C + posX[x];
      int nj = D + posY[x];
      if(ni>=0 && ni<A && nj>=0 && nj<B && !visited[ni][nj]) {
        q.push({{ni,nj}, count+1});
        visited[ni][nj] = true; 
      }
    }
  }
  return -1;
}
