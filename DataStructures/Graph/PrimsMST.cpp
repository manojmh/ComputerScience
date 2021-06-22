/**
https://www.geeksforgeeks.org/prims-algorithm-using-priority_queue-stl/
Prim’s algorithm using priority_queue in STL
1) Initialize keys of all vertices as infinite and 
   parent of every vertex as -1.
2) Create an empty priority_queue pq.  Every item
   of pq is a pair (weight, vertex). Weight (or 
   key) is used used as first item  of pair
   as first item is by default used to compare
   two pairs.
3) Initialize all vertices as not part of MST yet.
   We use boolean array inMST[] for this purpose.
   This array is required to make sure that an already
   considered vertex is not included in pq again. This
   is where Ptim's implementation differs from Dijkstra.
   In Dijkstr's algorithm, we didn't need this array as
   distances always increase. We require this array here 
   because key value of a processed vertex may decrease
   if not checked.
4) Insert source vertex into pq and make its key as 0.
5) While either pq doesn't become empty 
    a) Extract minimum key vertex from pq. 
       Let the extracted vertex be u.
    b) Include u in MST using inMST[u] = true.
    c) Loop through all adjacent of u and do 
       following for every vertex v.
           // If weight of edge (u,v) is smaller than
           // key of v and v is not already in MST
           If inMST[v] = false && key[v] > weight(u, v)
               (i) Update key of v, i.e., do
                     key[v] = weight(u, v)
               (ii) Insert v into the pq 
               (iv) parent[v] = u       
6) Print MST edges using parent array.
**/
#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
typedef pair<int,int> iPair;
class Graph {
	int V;
	list<iPair> *adj;
public:
	Graph(int V) {
		this->V = V;
		adj = new list<iPair>[V];
	}
	~Graph() {
		if(adj) delete[] adj;
	}
	void addEdge(int u, int v, int w) {
		adj[u].push_back({v,w});
		adj[v].push_back({u,w});
	}
	void primMST() {
		vector<bool> inMST(V, false);
		vector<int> key(V, INF);
		vector<int> parent(V, -1);
		priority_queue<iPair, vector<iPair>, greater<iPair>> pq;
		pq.push({0, 0});
		key[0] = 0;
		while(!pq.empty()) {
			int u = pq.top().second;
			pq.pop();
			if(inMST[u]) continue;
			inMST[u] = true;	
			for(auto x : adj[u]) {
				int v = x.first;
				int w = x.second;
				if(!inMST[v] && key[v]>w) {
					key[v] = w;
					pq.push({key[v], v});
					parent[v] = u;
				}
			}
		}
		for(int u=1; u<V; u++) {
			printf("%d - %d\n", parent[u], u);
		}
	}
};

int main() {
  int V = 9;
  Graph g(V);
  g.addEdge(0, 1, 4);
  g.addEdge(0, 7, 8);
  g.addEdge(1, 2, 8);
  g.addEdge(1, 7, 11);
  g.addEdge(2, 3, 7);
  g.addEdge(2, 8, 2);
  g.addEdge(2, 5, 4);
  g.addEdge(3, 4, 9);
  g.addEdge(3, 5, 14);
  g.addEdge(4, 5, 10);
  g.addEdge(5, 6, 2);
  g.addEdge(6, 7, 1);
  g.addEdge(6, 8, 6);
  g.addEdge(7, 8, 7);
  g.primMST();
  return 0;
}
