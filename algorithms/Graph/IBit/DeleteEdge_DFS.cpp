/**
https://www.interviewbit.com/old/problems/delete-edge/
Given a undirected tree with N nodes labeled from 1 to N.
Each node has a certain weight assigned to it given by an integer array A of size N.
You need to delete an edge in such a way that Product between sum of weight of nodes in one subtree with sum of weight of nodes in other subtree is maximized.
Return this maximum possible product modulo 109 + 7.
NOTE:
The tree is rooted at node labeled with 1.
Problem Constraints
2 <= N <= 105
1 <= A[i] <= 103
Input Format
First argument is an integer array A of size N denoting the weight of each node.
Second argument is a 2-D array B of size (N-1) x 2 denoting the edge of the tree.
Output Format
Return a single integer denoting the maximum product prossible of sum of weights of nodes in the two subtrees formed by deleting an edge with modulo 109 + 7.
Example Input
Input 1:
A = [10, 5, 12, 6]
B =[
    [1, 2]
    [1, 4]
    [4, 3]
   ]
Input 2:
A = [11, 12]
B = [
     [1, 2]
    ]
Example Output
Output 1: 270
Output 2: 132
Example Explanation
Explanation 1: Removing edge (1, 4) created two subtrees.
Subtree-1 contains nodes (1, 2) and Subtree-2 contains nodes (3, 4)
So product will be = (A[1] + A[2]) * (A[3] + A[4]) = 15 * 18 = 270
Explanation 2:
Removing edge (1, 2) created two subtrees.
Subtree-1 contains node (1) and Subtree-2 contains node (3)
So product will be = (A[1]) * (A[2]) = 11 * 12 = 132
**/
#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
long long ans = 0;
long long sum = 0;
vector<int> sumA;
list<int> *adj = nullptr;
long long dfs(int cur, int parent) {
  if(adj[cur].size() == 1) return sumA[cur-1];
  long long s=0;
  for(auto x:adj[cur]) {
    if(x==parent) continue;
    long long tp = dfs(x, cur);
    s += tp;
    long long temp = (((tp)%mod)*((sum-tp)%mod))%mod;
    ans = max(ans, temp);
  }
  return s+sumA[cur-1];
}
int Solution::deleteEdge(vector<int> &A, vector<vector<int> > &B) {
  sumA.clear();
  sumA = A;
  ans = 0;
  sum = 0;
  for(int i=0; i<A.size(); i++) sum += A[i];
  adj = new list<int>[A.size()+1];
  for(int i=0; i<B.size(); i++) {
    int u = B[i][0];
    int v = B[i][1];
    adj[u].push_back(v); 
    adj[v].push_back(u); 
  }
  dfs(1, -1);
  return (int)ans;
}
