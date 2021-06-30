/**
https://www.interviewbit.com/old/problems/min-cost-path/
You are given a AB character matrix named C. Every cell in C has a character U,R,L or D indicating up,right,left and down.
Your target is to go from top left corner to the bottom right corner of the matrix.
But there are some restrictions while moving along the matrix:
If you follow what is written in the cell then you can move freely.
But if you don't follow what is written in the cell then you have to pay 1 unit of cost.
Like: If a cell contains character U and you go right instead of Up you have to pay 1 unit of cost.
So your task is to find the minimum cost to go from top-left corner to the bottom-right corner.
Problem Constraints
1 <= A,B <= 103
C[i][j] can be either U,R,L or D.
Input Format
First Argument represents a integer A (number of rows).
Second Argument represents a integer B (number of columns).
Third Argument represents a string array C which contains A strings each of length B.
Output Format
Return an integer denoting the minimum cost to travel from top-left corner to bottom-right corner.
Example Input
Input:1
A = 3
B = 3
C = ["RRR","DDD","UUU"]
Input:2
A = 1
B = 4
C = ["LLLL"]
Example Output
Output-1 :1
Output-2 :3
Example Explanation*
Explanation for Input-1:
Matrix looks like:
RRR
DDD
UUU
We go right two times and down two times.
So from top-right cell we are going down though right is given so this incurs a cost of 1.
Explanation for Input-2:
Matrix looks like: LLLL
We go right three times.
**/
int xstep[4]={1,-1,0,0};
int ystep[4]={0,0,-1,1};
char dir[4]={'D', 'U', 'L', 'R'};
bool isvalid(int m, int n , int x , int y) {
  if(x>=0 && x<m && y>=0 && y<n)
    return true;
  return false;
}
int Solution::solve(int m, int n, vector<string> &C) {
  vector<vector<int>>d(m,vector<int>(n,INT_MAX));
  set<pair<int,pair<int,int>>>s;
  s.insert({0,{0,0}});
  d[0][0]=0;
  while(s.size()) {
    auto temp = *s.begin();
    int x=temp.second.first;
    int y=temp.second.second;
    if(x==m && y==n)
      return temp.first;
    s.erase(s.begin());
    for(int i=0;i<4;i++) {
      int u=x+xstep[i];
      int v=y+ystep[i];
      if(!isvalid(m,n,u,v))
        continue;
      int w=(C[x][y]==dir[i]?0:1);
      if(d[u][v]>d[x][y]+w) {
        s.erase({d[u][v],{u,v}});
        d[u][v]=d[x][y]+w;
        s.insert({d[u][v],{u,v}});
      }
    }
  }
  return d[m-1][n-1];
}
