/**
https://www.interviewbit.com/old/problems/possibility-of-finishing-all-courses-given-prerequisites/
There are a total of A courses you have to take, labeled from 1 to A.
Some courses may have prerequisites, for example to take course 2 you have to first take course 1, which is expressed as a pair: [1,2].
Given the total number of courses and a list of prerequisite pairs, is it possible for you to finish all courses?
Return 1 if it is possible to finish all the courses, or 0 if it is not possible to finish all the courses.
Input Format:
The first argument of input contains an integer A, representing the number of courses.
The second argument of input contains an integer array, B.
The third argument of input contains an integer array, C.
Output Format:
Return a boolean value:
  1 : If it is possible to complete all the courses.
  0 : If it is not possible to complete all the courses.
Constraints:
1 <= A <= 6e4
1 <= length(B) = length(C) <= 1e5
1 <= B[i], C[i] <= A
Example:
Input 1:
  A = 3
  B = [1, 2]
  C = [2, 3]
Output 1: 1
Explanation 1:
    It is possible to complete the courses in the following order:
        1 -> 2 -> 3
Input 2:
  A = 2
  B = [1, 2]
  C = [2, 1]
Output 2: 0
Explanation 2:
    It is not possible to complete all the courses.
**/
#include <list>
class Graph {
  int V;
  list<int> *adj;
public:
    Graph(int V) {
      this->V = V;
      adj = new list<int>[V];
    }
    ~Graph() {
      if(adj)
        delete[] adj;
    }
    void addEdge(int u, int v) {
      adj[u].push_back(v);
    }
    bool dfsUtils(int u, vector<bool> &visited, vector<bool> &rec) {
      if(visited[u] == false) {
        visited[u] = true;
        rec[u] = true;
        for(auto it=adj[u].begin(); it!=adj[u].end(); ++it) {
          if(!visited[*it] && dfsUtils(*it, visited, rec))
            return true;
          else if(rec[*it]) {
            return true;
          }
        }
      }
      rec[u] = false;
      return false;
    }
    int dfs() {
      stack<int> s;
      vector<bool> visited(V, false);
      vector<bool> rec(V, false);
      for(auto i=0; i<V; i++) {
        if(dfsUtils(i, visited, rec))
          return false;
      }
      return true;
    }
};
int Solution::solve(int A, vector<int> &B, vector<int> &C) {
  Graph g(A);
  for(int i=0; i<B.size(); i++) {
    g.addEdge(B[i]-1, C[i]-1);
  }
  return g.dfs();
}
