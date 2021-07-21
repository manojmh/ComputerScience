/**
https://leetcode.com/problems/shortest-path-visiting-all-nodes/
You have an undirected, connected graph of n nodes labeled from 0 to n - 1.
You are given an array graph where graph[i] is a list of all the nodes connected with node i by an edge.
Return the length of the shortest path that visits every node.
You may start and stop at any node, you may revisit nodes multiple times, and you may reuse edges.
Example 1:
Input: graph = [[1,2,3],[0],[0],[0]]
Output: 4
Explanation: One possible path is [1,0,2,0,3]
Example 2:
Input: graph = [[1],[0,2,4],[1,3,4],[2],[1,2]]
Output: 4
Explanation: One possible path is [0,1,4,2,3]
Constraints:
n == graph.length
1 <= n <= 12
0 <= graph[i].length < n
graph[i] does not contain i.
If graph[a] contains b, then graph[b] contains a.
The input graph is always connected.
**/
struct Node{
  int node;
  int mask;
  int step;
};
class Solution {
public:
  int shortestPathLength(vector<vector<int>>& graph) {
    int n = graph.size();
    int allVisited = (1<<n)-1;
    unordered_set<string> visited;
    queue<Node> q;
    for(int i=0; i<n; i++) {
      q.push({i, 1<<i, 0});
      string key = to_string(i) + "_" + to_string(1 << i);
      visited.insert(key);
    }
    while(!q.empty()) {
      auto front = q.front();
      q.pop();

      int u = front.node;
      int mask = front.mask;
      int step = front.step;

      if(mask == allVisited) return step;

      for (auto new_node : graph[u]) {
        int new_mask = mask | (1<<new_node);
        int new_step = step + 1;
        string key = to_string(new_node) + "_" + to_string(new_mask);
        if(visited.find(key) == visited.end()) {
          visited.insert(key);
          q.push({new_node, new_mask, new_step});
        }
      }
    }
    return -1;
  }
};
