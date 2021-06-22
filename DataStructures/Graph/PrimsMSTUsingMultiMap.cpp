#include <bits/stdc++.h>
using namespace std;
#define V 5
typedef pair<int, int> iPair;
//weight and edge
multimap<int, iPair> m;

void addEdge(int u, int v, int w=1) {
	iPair p = {u,v};
	m.insert(w, p);
}

void prims() {
  //tracks visited vertex
	set<int> s;
	s.insert(m.begin()->second.first);
  //tracks wthether all vertexes are visited
	while(s.size() != V) {
		for(auto it = m.begin(); it != m.end(); ++it) {
			if(s.find(it->second.second) == s.end()) {
				s.insert(it->second.second);
				cout << it->second.first << " " << it->second.second << endl;
			}
		}
	}
}

int main() {
	int graph[5][5] = { { 0, 2, 0, 6, 0 },  
                      { 2, 0, 3, 8, 5 },  
                      { 0, 3, 0, 0, 7 },  
                      { 6, 8, 0, 0, 9 },  
                      { 0, 5, 7, 9, 0 } };
	for(int i=0; i<5; ++i) {
		for(int j=0; j<5; ++j)
			addEdge(i, j, graph[i][j]);
	}
	prims();
	return 0;
}
