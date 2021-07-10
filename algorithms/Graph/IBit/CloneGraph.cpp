/**
https://www.interviewbit.com/old/problems/clone-graph/
https://leetcode.com/problems/clone-graph/submissions/
Clone an undirected graph. Each node in the graph contains a label and a list of its neighbors.
**/
class Solution {
public:
  unordered_map<Node*, Node*> table;
  Node* cloneGraph(Node* node) {
    if(!node)
      return nullptr;
    return dfs(node);
  }
  Node* dfs(Node* node){
    if (table.count(node))
      return table[node];
    table[node] = new Node(node->val);
    for(auto it: node->neighbors)
      table[node]->neighbors.push_back(dfs(it));
    return table[node];
  }
};
