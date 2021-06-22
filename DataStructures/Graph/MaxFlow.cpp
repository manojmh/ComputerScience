/**
https://www.geeksforgeeks.org/ford-fulkerson-algorithm-for-maximum-flow-problem/
Ford-Fulkerson Algorithm for Maximum Flow Problem
Ford-Fulkerson Algorithm 
The following is simple idea of Ford-Fulkerson algorithm:
1) Start with initial flow as 0.
2) While there is a augmenting path from source to sink. Add this path-flow to flow.
3) Return flow.
Time complexity of the above algorithm is O(max_flow * E).
We run a loop while there is an augmenting path. In worst case, we may add 1 unit flow in every iteration.
Therefore the time complexity becomes O(max_flow * E).
**/
#include <bits/stdc++.h>
using namespace std;
#define V 6
bool bfs(int rg[V][V], int s, int t, vector<int> &parent) {
	vector<bool> visited(V, false);
	queue<int> q;
	q.push(s);
	visited[s] = true;
	while(!q.empty()) {
		int u = q.front();
		q.pop();
		for(int v=0; v<V; v++) {
			if(rg[u][v] && !visited[v]) {
				if(v == t) {
					parent[v] = u;
					return true;
				}
				q.push(v);
				visited[v] = true;
				parent[v] = u;
			}
		}
	}
	return false;
}
int fordFulkerson(int g[V][V], int s, int t) {
	int rg[V][V];
	memset(rg, 0, sizeof(rg));
	for(int u=0; u<V; u++)
		for(int v=0; v<V; v++)
			rg[u][v] = g[u][v];
	vector<int> parent(V, -1);
	int maxPath = 0;
	while(bfs(rg, s, t, parent)) {
		int path = INT_MAX;
		for(int v=t; v!=s; v=parent[v]) {
			int u = parent[v];
			path = min(path, rg[u][v]);
		}
		for(int v=t; v!=s; v=parent[v]) {
			int u = parent[v];
			rg[u][v] -= path;
			rg[v][u] += path;
		}
		maxPath += path;
	}
	return maxPath;
}
int main() {
  // Let us create a graph shown in the above example
  int graph[V][V]
    = { { 0, 16, 13, 0, 0, 0 }, { 0, 0, 10, 12, 0, 0 },
        { 0, 4, 0, 0, 14, 0 },  { 0, 0, 9, 0, 0, 20 },
        { 0, 0, 0, 7, 0, 4 },   { 0, 0, 0, 0, 0, 0 } };

  cout << "The maximum possible flow is "
     << fordFulkerson(graph, 0, 5);

  return 0;
}
