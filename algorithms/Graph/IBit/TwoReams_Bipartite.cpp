/**
There are A people numbered 1 to A in a football academy.
The coach of the academy wants to make two teams (not necessary of equal size) but unfortunately,
not all people get along, and several refuse to be put on the same team as that of their enemies.
Given a 2-D array B of size M x 2 denoting the enemies i.e B[i][0] and B[i][1] both are enemies of each other.
Return 1 if it possible to make exactly two teams else return 0.
Problem Constraints
2 <= A <= 105
1 <= M <= 105
1 <= B[i][0], B[i][1] <= A
B[i][0] != B[i][1]
Input Format
First argument is an integer A denoting number of peoples.
Second argument is a 2-D array B of size M x 2 denoting enemies.
Output Format: Return 1 if it possible to make exactly two teams else return 0.
Example Input
Input 1:
A = 5
B = [ [1, 2],
      [2, 3],
      [1, 5],
      [2, 4] ] 
Input 2:
A = 4
B = [ [1, 4],
      [3, 1],
      [4, 3],
      [2, 1] ]
Example Output
Output 1: 1 
Output 2: 0 
Example Explanation
Explanation 1: We can make two teams [1, 3, 4] and [2, 5].
Explanation 2: No possible way to create two teams. So, we need to return 0.
**/
int dfs(int node, int c, int col[], vector<vector<int>> &adj){
  col[node]=c;
  for(int child:adj[node]){
    if(col[child]==c) return 0;
    if(col[child]==-1 && !dfs(child, (c^1), col, adj))
      return 0;
  }
  return 1;
}
int Solution::solve(int A, vector<vector<int> > &B) {
  vector<vector<int>> adj(A+1);
  for(auto v:B){
    adj[v[0]].push_back(v[1]);
    adj[v[1]].push_back(v[0]);
  }
  int col[A+1];
  memset(col, -1, sizeof(col));
  for(int i=1; i<=A; i++){
    if(col[i]==-1 && !dfs(i, 0, col, adj))
      return 0;
  }
  return 1;
}
