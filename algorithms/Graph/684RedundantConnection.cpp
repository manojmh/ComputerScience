/**
https://leetcode.com/problems/redundant-connection/
In this problem, a tree is an undirected graph that is connected and has no cycles.
You are given a graph that started as a tree with n nodes labeled from 1 to n, with one additional edge added.
The added edge has two different vertices chosen from 1 to n, and was not an edge that already existed.
The graph is represented as an array edges of length n where edges[i] = [ai, bi] indicates that there is an edge between nodes ai and bi in the graph.
Return an edge that can be removed so that the resulting graph is a tree of n nodes. If there are multiple answers, return the answer that occurs last in the input.
Example 1:
Input: edges = [[1,2],[1,3],[2,3]]
Output: [2,3]
Example 2:
Input: edges = [[1,2],[2,3],[3,4],[1,4],[1,5]]
Output: [1,4]
Constraints:
n == edges.length
3 <= n <= 1000
edges[i].length == 2
1 <= ai < bi <= edges.length
ai != bi
There are no repeated edges.
The given graph is connected.
**/
class Solution {
  vector<int> parent;
  vector<int> rank;
  int find_set(int x) {
    if(x == parent[x])
      return x;
    return parent[x] = find_set(parent[x]);
  }
  void union_set(int x, int y) {
    x = parent[x];
    y = parent[y];
    if(x==y) return;
    if(rank[x] > rank[y])
      parent[y] = x;
    else{
      parent[x] = y;
      if(rank[x] == rank[y])
        rank[x]++;
    }
  }
public:
  vector<int> findRedundantConnection(vector<vector<int>>& edges) {
    int n = edges.size();
    vector<int> res;
    parent.resize(n+1, 0);
    rank.resize(n+1, 0);
    for(int i=0; i<n+1; i++)
      parent[i] = i;
    for(auto i=0; i<edges.size(); i++) {
      int x = find_set(edges[i][0]);
      int y = find_set(edges[i][1]);
      if(x!=y)
        union_set(edges[i][0], edges[i][1]);
      else {
        res.push_back(edges[i][0]);
        res.push_back(edges[i][1]);
      }
    }
    return res;
  }
};
