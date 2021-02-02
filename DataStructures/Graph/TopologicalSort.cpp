/**
Topological sorting for Directed Acyclic Graph (DAG) is a linear ordering of vertices such that for every directed edge u v, vertex u comes before v in the ordering.
Topological Sorting for a graph is not possible if the graph is not a DAG.

For example, a topological sorting of the following graph is “5 4 2 3 1 0”. There can be more than one topological sorting for a graph.
For example, another topological sorting of the following graph is “4 5 2 3 1 0”.
The first vertex in topological sorting is always a vertex with in-degree as 0 (a vertex with no incoming edges).

Complexity Analysis: 

Time Complexity: O(V+E). 
The above algorithm is simply DFS with an extra stack. So time complexity is the same as DFS which is.
Auxiliary space: O(V). 
The extra space is needed for the stack.
Note: Here, we can also use vector instead of the stack.
If the vector is used then print the elements in reverse order to get the topological sorting.
**/

#include <bits/stdc++.h>
using namespace std;

int V = 0;
int g[100][100];

void addEdge(int s, int d, int w=1) {
	g[s][d] = w;
}

void topologicalSortUtil(int u, vector<bool> &visited, stack<int> &st) {
  visited[u] = true;
  for(int v = 0; v < V; ++v)
    if(g[u][v] && !visited[v])
      topologicalSortUtil(v, visited, st);
  st.push(u);
}

void topologicalSort() {
  stack<int> st;
  vector<bool> visited(V, false);
  for(int u = 0; u < V; ++u)
    if(!visited[u])
      topologicalSortUtil(u, visited, st);

  while(!st.empty()) {
    cout << st.top() << " ";
    st.pop();
  }
  cout << endl;
}

int main() 
{
  V = 6;
  addEdge(5, 2); 
  addEdge(5, 0); 
  addEdge(4, 0); 
  addEdge(4, 1); 
  addEdge(2, 3); 
  addEdge(3, 1); 

  cout << "Following is a Topological Sort of the given graph \n"; 

  // Function Call 
  topologicalSort();
  return 0; 
}
