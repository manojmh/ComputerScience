/**
https://www.geeksforgeeks.org/minimum-cut-in-a-directed-graph/
Find minimum s-t cut in a flow network
For example, in the following flow network, example s-t cuts are {{0 ,1}, {0, 2}}, {{0, 2}, {1, 2}, {1, 3}}, etc.
The minimum s-t cut is {{1, 3}, {4, 3}, {4 5}} which has capacity as 12+7+4 = 23.
Following are steps to print all edges of the minimum cut.
1) Run Ford-Fulkerson algorithm and consider the final residual graph.
2) Find the set of vertices that are reachable from the source in the residual graph.
3) All edges which are from a reachable vertex to non-reachable vertex are minimum cut edges. Print all such edges.
Output:
1 - 3
4 - 3
4 - 5
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
				q.push(v);
				visited[v] = true;
				parent[v] = u;
			}
		}
	}
	return visited[t];
}
void dfs(int rg[V][V], int u, vector<bool> &visited) {
	visited[u] = true;
	for(int v=0; v<V; v++) {
		if(rg[u][v] && !visited[v]) {
			dfs(rg, v, visited);
		}
	}
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
	vector<bool> visited(V, false);
	dfs(rg, s, visited);
	cout << "Min Cuts are as follows : \n";
	for(int u=0; u<V; u++)
		for(int v=0; v<V; v++)
			if(visited[u] && !visited[v] && g[u][v])
				cout << u << "->" << v << endl;
	return maxPath;
}
int main() {
  // Let us create a graph shown in the above example
  int graph[V][V]
    = { { 0, 16, 13, 0, 0, 0 }, { 0, 0, 10, 12, 0, 0 },
        { 0, 4, 0, 0, 14, 0 },  { 0, 0, 9, 0, 0, 20 },
        { 0, 0, 0, 7, 0, 4 },   { 0, 0, 0, 0, 0, 0 } };
  cout << "The maximum possible flow is "
     << fordFulkerson(graph, 0, 5) << endl;
  return 0;
}
