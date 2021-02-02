/**
Breadth First Search(Level Order Travesal)
Time Complexity: O(V+E) where V is number of vertices in the graph and E is number of edges in the graph.
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

    cout << u << " ";

    for(int v = 0; v < V; ++v) {
      if(g[u][v] && !visited[v]) {
        q.push(v);
        visited[v] = true;
      }
    }
  }
}

int main() 
{
  // Create a graph given in the above diagram
  V = 4;
  addEdge(0, 1);
  addEdge(0, 2);
  addEdge(1, 2);
  addEdge(2, 0);
  addEdge(2, 3);
  addEdge(3, 3);

  cout << "Following is Depth First Traversal"
          " (starting from vertex 2) \n";
  BFS(2);
  return 0; 
}
