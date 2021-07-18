/**
https://leetcode.com/problems/number-of-provinces/
There are n cities. Some of them are connected, while some are not.
If city a is connected directly with city b, and city b is connected directly with city c, then city a is connected indirectly with city c.
A province is a group of directly or indirectly connected cities and no other cities outside of the group.
You are given an n x n matrix isConnected where isConnected[i][j] = 1 if the ith city and the jth city are directly connected, and isConnected[i][j] = 0 otherwise.
Return the total number of provinces.
Example 1:
Input: isConnected = [[1,1,0],[1,1,0],[0,0,1]]
Output: 2
Example 2:
Input: isConnected = [[1,0,0],[0,1,0],[0,0,1]]
Output: 3
Constraints:
1 <= n <= 200
n == isConnected.length
n == isConnected[i].length
isConnected[i][j] is 1 or 0.
isConnected[i][i] == 1
isConnected[i][j] == isConnected[j][i]
**/
class Solution {
public:
  vector<int> parent, rank;
  int n;
  int find_set(int v) {
    if(v == parent[v]) return v;
    return parent[v] = find_set(parent[v]);
  } 
  void union_set(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if(a == b) return;
    if(rank[a] < rank[b]) {
      parent[a] = b;
    }
    else {
      parent[b] = a;
      if(rank[a] == rank[b]) {
        rank[b]++;
      }
    }
    n--;   
  }
  int findCircleNum(vector<vector<int>>& isConnected) {
    parent = vector<int>(isConnected.size());
    rank = vector<int>(parent.size(), 0);
    n = isConnected.size();
    for(int i = 0 ; i < parent.size() ; i++) {
      parent[i] = i;
    }
    for(int i = 0 ; i < isConnected.size() ; i++) {
      for(int j = 0 ; j < isConnected.size() ; j++) {
        if(isConnected[i][j]) {
          union_set(i, j);
        }
      }
    }
    return n;
  }
};
