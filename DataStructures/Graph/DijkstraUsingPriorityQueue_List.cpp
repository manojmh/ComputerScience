/**
1) Initialize distances of all vertices as infinite.
2) Create an empty priority_queue pq.  Every item
   of pq is a pair (weight, vertex). Weight (or 
   distance) is used used as first item  of pair
   as first item is by default used to compare
   two pairs
3) Insert source vertex into pq and make its
   distance as 0.
4) While either pq doesn't become empty
    a) Extract minimum distance vertex from pq. 
       Let the extracted vertex be u.
    b) Loop through all adjacent of u and do 
       following for every vertex v.
           // If there is a shorter path to v
           // through u. 
           If dist[v] > dist[u] + weight(u, v)
               (i) Update distance of v, i.e., do
                     dist[v] = dist[u] + weight(u, v)
               (ii) Insert v into the pq (Even if v is
                    already there)        
5) Print distance array dist[] to print all shortest
   paths.
Output:
Vertex   Distance from Source
0          0
1          4
2          12
3          19
4          21
5          11
6          9
7          8
8          14
**/
#include<bits/stdc++.h>
using namespace std;
# define INF 0x3f3f3f3f
typedef pair<int, int> iPair;
class Graph {
    int V;
    list< pair<int, int> > *adj;
public:
    Graph(int V);
    void addEdge(int u, int v, int w);
    void shortestPath(int s);
};
Graph::Graph(int V) {
    this->V = V;
    adj = new list<iPair> [V];
}
void Graph::addEdge(int u, int v, int w) {
    adj[u].push_back(make_pair(v, w));
    adj[v].push_back(make_pair(u, w));
}
void Graph::shortestPath(int src) {
  priority_queue< iPair, vector <iPair> , greater<iPair> > pq;
  vector<int> dist(V, INF);
  pq.push(make_pair(0, src));
  dist[src] = 0;
  while (!pq.empty()) {
    int u = pq.top().second;
    pq.pop();
    for (auto x : adj[u]) {
      int v = x.first;
      int weight = x.second;
      if (dist[v] > dist[u] + weight) {
        dist[v] = dist[u] + weight;
        pq.push(make_pair(dist[v], v));
      }
    }
  }
  printf("Vertex Distance from Source\n");
  for (int i = 0; i < V; ++i)
    printf("%d \t\t %d\n", i, dist[i]);
}
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
  g.shortestPath(0); 
  return 0;
}
