/**
Depth-first search is an algorithm for traversing or searching tree or graph data structures.
The algorithm starts at the root node (selecting some arbitrary node as the root node in the case of a graph) and explores as far as possible along each branch before backtracking. So the basic idea is to start from the root or any arbitrary node and mark the node and move to the adjacent unmarked node and continue this loop until there is no unmarked adjacent node. Then backtrack and check for other unmarked nodes and traverse them. Finally print the nodes in the path.

Complexity Analysis: 

Time Complexity: O(V+E). 
The above algorithm is simply DFS with an extra stack. So time complexity is the same as DFS which is.
Auxiliary space: O(V). 
The extra space is needed for the stack.
**/

#include <bits/stdc++.h>
using namespace std;

int  V = 0;
int  g[10][10];
bool visited[10];

void addEdge(int s, int d, int w=1) {
  g[s][d] = w;
}

void DFSUtil(int u) {
  visited[u] = true;
  cout << u << " ";

  for(int v = 0; v < V; ++v)
    if(g[u][v] && !visited[v])
      DFSUtil(v);
}

void DFS(int u) {
  if(!visited[u])
    DFSUtil(u);
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
  DFS(2);
  return 0; 
}
