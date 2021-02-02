/**
0-->2-->1-->0-->3-->4
We can find all strongly connected components in O(V+E) time using Kosaraju’s algorithm. Following is detailed Kosaraju’s algorithm.
1) Create an empty stack ‘S’ and do DFS traversal of a graph. In DFS traversal, after calling recursive DFS for adjacent vertices of a vertex, push the vertex to stack.
   In the above graph, if we start DFS from vertex 0, we get vertices in stack as 1, 2, 4, 3, 0.
2) Reverse directions of all arcs to obtain the transpose graph.
3) One by one pop a vertex from S while S is not empty. Let the popped vertex be ‘v’. Take v as source and do DFS (call DFSUtil(v)).
   The DFS starting from v prints strongly connected component of v. In the above example, we process vertices in order 0, 3, 4, 2, 1 (One by one popped from stack).

Time Complexity: The above algorithm calls DFS, finds reverse of the graph and again calls DFS. DFS takes O(V+E) for a graph represented using adjacency list.
Reversing a graph also takes O(V+E) time. For reversing the graph, we simple traverse all adjacency lists.
**/

#include <bits/stdc++.h>
using namespace std;

int  V = 0;
int  g[10][10];
int  gr[10][10];
bool visited[10];
stack<int> st;

void addEdge(int s, int d, int w=1) {
  g[s][d] = w;
}

void transpose() {
  int i, j; 
  for (i = 0; i < V; i++) 
      for (j = 0; j < V; j++) 
          gr[i][j] = g[j][i];
}

void DFS(int u) {
  visited[u] = true;
  for(int v = 0; v < V; ++v)
    if(g[u][v] && !visited[v])
      DFS(v);
  st.push(u);
}

void DFSForTranspose(int u) {
  visited[u] = true;
  cout << u << " ";

  for(int v = 0; v < V; ++v)
    if(gr[u][v] && !visited[v])
      DFSForTranspose(v);
}

/**************************************************/
void StronglyConnectedComponents() {
  for(int u = 0; u < V; ++u)
    if(!visited[u])
      DFS(u);

  transpose();

  for(int v = 0; v < V; ++v)
    visited[v] = false;

  while(!st.empty()) {
    int u = st.top();
    st.pop();

    if(!visited[u]) {
      DFSForTranspose(u);
      cout << endl;
    }
  }
}
/**************************************************/

int main() { 
  // Create a graph given in the above diagram 
  V = 5; 
  addEdge(1, 0); 
  addEdge(0, 2); 
  addEdge(2, 1); 
  addEdge(0, 3); 
  addEdge(3, 4); 

  cout << "Following are strongly connected components in "
          "given graph \n"; 
  StronglyConnectedComponents(); 
  return 0; 
}
