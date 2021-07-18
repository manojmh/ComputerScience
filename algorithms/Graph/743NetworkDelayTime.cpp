/**
https://leetcode.com/problems/network-delay-time/
You are given a network of n nodes, labeled from 1 to n. You are also given times, a list of travel times as directed edges times[i] = (ui, vi, wi),
where ui is the source node, vi is the target node, and wi is the time it takes for a signal to travel from source to target.
We will send a signal from a given node k. Return the time it takes for all the n nodes to receive the signal.
If it is impossible for all the n nodes to receive the signal, return -1.
Example 1:
Input: times = [[2,1,1],[2,3,1],[3,4,1]], n = 4, k = 2
Output: 2
Example 2:
Input: times = [[1,2,1]], n = 2, k = 1
Output: 1
Example 3:
Input: times = [[1,2,1]], n = 2, k = 2
Output: -1
Constraints:
1 <= k <= n <= 100
1 <= times.length <= 6000
times[i].length == 3
1 <= ui, vi <= n
ui != vi
0 <= wi <= 100
All the pairs (ui, vi) are unique. (i.e., no multiple edges.)
**/
class Solution {
public:
  int networkDelayTime(vector<vector<int>>& times, int V, int start) {
    vector<int> dist(V+1, INT_MAX);
    dist[start] = 0;
    for(int i=0; i<V-1; i++) {
      for(int j=0; j<times.size(); j++) {
        int u = times[j][0];
        int v = times[j][1];
        int w = times[j][2];
        if(dist[u]!=INT_MAX && dist[v] > dist[u] + w)
          dist[v] = dist[u] + w;
      }
    }
    int mx = INT_MIN;
    for(int i=1; i<dist.size(); i++) {
      if(dist[i] == INT_MAX)
        return -1;
      mx = max(mx, dist[i]);
    }
    return mx;
  }
};
