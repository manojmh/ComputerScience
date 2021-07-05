/**
https://www.interviewbit.com/old/problems/useful-extra-edges/
Given a graph of A nodes. Also given the weighted edges in the form of array B.
You are also given starting point C and destination point D.
Also given are some extra edges in the form of vector E.
You need to find the length of the shortest path from C to D if you can use maximum one road from the given roads in E.
All roads are one way ie they go from B[i][0] to B[i][1].
Problem Constraints
1 <= A <= 100000
1 <= |B| <= 100000
1 <= C, D <= A
1 <= |E| <= 300
All lengths of the roads lie between 1 and 1000.
Input Format
First argument is the integer A.
Second argument is the vector of vectors B.
Third argument is the integer C.
Fourth argument is the integer D.
Fifth argument is the vector of vectors E.
Output Format
Return -1 if C is not reachable from D. Else return the shortest distance between them.
Example Input
Input 1:
A = 3
B = [[1, 2, 1] [2, 3, 2]]
C = 1
D = 3
E = [[1, 3, 2]]
Input 2:
A = 4
B = [[1, 2, 1][2, 3, 2][3, 1, 4]]
C = 1
D = 4
E = [[1, 3, 2]]
Example Output
Output 1:2
Output 2:-1
Example Explanation
Explanation 1:Use the direct edge from 1 to 3. It has shortest path from 1 to 3.
Explanation 2: 4 cannot be reached from 1.
**/
#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> iPair;
#define INF 0x3f3f3f3f
int V;
list<iPair> *adj = nullptr;
int djikstras(int src, int dst) {
  vector<int> dist(V+1, INF);
  priority_queue<iPair, vector<iPair>, greater<iPair>> pq;
  pq.push({0,src});
  dist[src] = 0;
  while(!pq.empty()) {
    int u = pq.top().second;
    pq.pop();
    for(auto it:adj[u]) {
      int v = it.first;
      int w = it.second;
      if(dist[v] > dist[u] + w) {
        dist[v] = dist[u] + w;
        pq.push({dist[v], v});
      }
    }
  }
  return dist[dst];
}
int Solution::solve(int A, vector<vector<int> > &B, int C, int D, vector<vector<int> > &E) {
  V = A;
  adj =new list<iPair>[V+1];
  for(int i=0; i<B.size(); i++) {
    int u = B[i][0];
    int v = B[i][1];
    int w = B[i][2];
    if(u>A || v>A) continue;
    adj[u].push_back({v,w});
  }
  int ans=INF;
  for(int i=0; i<E.size(); i++) {
    int u = E[i][0];
    int v = E[i][1];
    int w = E[i][2];
    if(u>A || v>A) continue;
    adj[u].push_back({v,w});
    adj[v].push_back({u,w});
    ans = min(ans, djikstras(C,D));
    adj[u].pop_back();
    adj[v].pop_back();
  }
  if(adj) delete[] adj;
  return (ans==INF) ? -1 : ans;
}
