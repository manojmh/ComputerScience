/**
A mother vertex in a graph G = (V,E) is a vertex v such that all other vertices in G can be reached by a path from v.
Case 1:- Undirected Connected Graph : In this case, all the vertices are mother vertices as we can reach to all the other nodes in the graph.
Case 2:- Undirected/Directed Disconnected Graph : In this case, there is no mother vertices as we cannot reach to all the other nodes in the graph.
Case 3:- Directed Connected Graph : In this case, we have to find a vertex -v in the graph such that we can reach to all the other nodes in the graph through a directed path.

The idea is based on Kosaraju’s Strongly Connected Component Algorithm.
In a graph of strongly connected components, mother vertices are always vertices of source component in component graph. The idea is based on below fact.
If there exist mother vertex (or vertices), then one of the mother vertices is the last finished vertex in DFS.
(Or a mother vertex has the maximum finish time in DFS traversal).
A vertex is said to be finished in DFS if a recursive call for its DFS is over, i.e., all descendants of the vertex have been visited. 

How does the above idea work? 
Let the last finished vertex be v.
Basically, we need to prove that there cannot be an edge from another vertex u to v if u is not another mother vertex 
(Or there cannot exist a non-mother vertex u such that u-→v is an edge). There can be two possibilities.

Recursive DFS call is made for u before v.
If an edge u-→v exists, then v must have finished before u because v is reachable through u and a vertex finishes after all its descendants.
Recursive DFS call is made for v before u. In this case also, if an edge u-→v exists, then either v must finish before u
(which contradicts our assumption that v is finished at the end) OR u should be reachable from v (which means u is another mother vertex).

Algorithm : 
Do DFS traversal of the given graph. While doing traversal keep track of last finished vertex ‘v’. This step takes O(V+E) time.
If there exist mother vertex (or vertices), then v must be one (or one of them). Check if v is a mother vertex by doing DFS/BFS from v. This step also takes O(V+E) time.
**/

#include <bits/stdc++.h>
using namespace std;

int  V = 0;
int  g[10][10];
bool visited[10];

void addEdge(int s, int d, int w=1) {
  g[s][d] = w;
}

void BFS(int u) {
  queue<int> q;
  q.push(u);
  visited[u] = true;

  while(!q.empty()) {
    u = q.front();
    q.pop();
    for(int v = 0; v < V; ++v) {
      if(g[u][v] && !visited[v]) {
        q.push(v);
        visited[v] = true;
      }
    }
  }
}

void MotherVertex() {
  int lastVisited = -1;
  for(int u = 0; u < V; ++u) {
    if(!visited[u]) {
      BFS(u);
      lastVisited = u;
    }
  }

  for(int u = 0; u < V; ++u)
    visited[u] = false;

  BFS(lastVisited);

  for(int u = 0; u < V; ++u) {
    if(!visited[u]) {
      cout << "No MotherVertex found !!!\n";
      return;
    }
  }
  cout << lastVisited << endl;
}

int main()
{
  // Create a graph given in the above diagram
  V = 7;
  addEdge(0, 1);
  addEdge(0, 2);
  addEdge(1, 3);
  addEdge(4, 1);
  addEdge(6, 4);
  addEdge(5, 6);
  addEdge(5, 2);
  addEdge(6, 0);

  cout << "A mother vertex is : ";
  MotherVertex();

  return 0;
}
