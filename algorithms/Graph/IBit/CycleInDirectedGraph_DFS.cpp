/**
https://www.interviewbit.com/old/problems/cycle-in-directed-graph/
Given an directed graph having A nodes. A matrix B of size M x 2 is given which represents the M edges
such that there is a edge directed from node B[i][0] to node B[i][1].
Find whether the graph contains a cycle or not, return 1 if cycle is present else return 0.
NOTE:
The cycle must contain atleast two nodes.
There are no self-loops in the graph.
There are no multiple edges between two nodes.
The graph may or may not be connected.
Nodes are numbered from 1 to A.
Your solution will run on multiple test cases. If you are using global variables make sure to clear them.
Problem Constraints
2 <= A <= 105
1 <= M <= min(200000,A(A-1))
1 <= B[i][0], B[i][1] <= A
Input Format
The first argument given is an integer A representing the number of nodes in the graph.
The second argument given a matrix B of size M x 2 which represents the M edges such that there is a edge directed from node B[i][0] to node B[i][1].
Output Format
Return 1 if cycle is present else return 0.
Example Input
Input 1:
A = 5
B = [[1, 2] 
     [4, 1] 
     [2, 4] 
     [3, 4] 
     [5, 2] 
     [1, 3] ]
Input 2:
A = 5
B = [ [1, 2]
      [2, 3] 
      [3, 4] 
      [4, 5] ]
Example Output
Output 1: 1
Output 2: 0
Example Explanation*
Explanation 1: The given graph contain cycle 1 -> 3 -> 4 -> 1 or the cycle 1 -> 2 -> 4 -> 1
Explanation 2: The given graph doesn't contain any cycle.
**/
#include <bits/stdc++.h>
using namespace std;
list<int> *adj;
vector<bool> visited;
vector<bool> rec;
bool dfs(int u) {
  visited[u] = true;
  rec[u] = true;
  for(auto v=adj[u].begin(); v!=adj[u].end(); ++v) {
    if(!visited[*v] && dfs(*v))
      return true;
    else if(rec[*v])
      return true;
  }
  rec[u] = false;
  return false;
}
int Solution::solve(int A, vector<vector<int> > &B) {
  adj = new list<int>[A+1];
  for(int i=0; i<B.size(); i++) {
    int u = B[i][0];
    int v = B[i][1];
    adj[u].push_back(v);
  }
  visited = vector<bool>(A+1, false);
  rec = vector<bool>(A+1, false);
  for(int i=1; i<=A; i++) {
    if(!visited[i] && dfs(i)) {
      visited.clear();
      rec.clear();
      if(adj) delete[] adj;
      return true;
    }
  }
  visited.clear();
  rec.clear();
  if(adj) delete[] adj;
  return false;
}
