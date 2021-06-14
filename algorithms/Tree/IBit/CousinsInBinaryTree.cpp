/**
https://www.interviewbit.com/problems/cousins-in-binary-tree/
Given a Binary Tree A consisting of N nodes.
You need to find all the cousins of node B.
NOTE:
Siblings should not be considered as cousins.
Try to do it in single traversal.
You can assume that Node B is there in the tree A.
Order doesn't matter in the output.
Problem Constraints
1 <= N <= 105
1 <= B <= N
Input Format: First Argument represents the root of binary tree A.
Second Argument is an integer B denoting the node number.
Output Format
Return an integer array denoting the cousins of node B.
NOTE: Order doesn't matter.
Example Input
Input 1:
A =
     1
   /   \
  2     3
 / \   / \
4   5 6   7 
B = 5
Input 2:
A = 
      1
    /   \
   2     3
  / \ .   \
 4   5 .   6
B = 1
Example Output
Output 1: [6, 7]
Output 2: []
Example Explanation
Explanation 1: Cousins of Node 5 are Node 6 and 7 so we will return [6, 7]
Remember Node 4 is sibling of Node 5 and do not need to return this.
Explanation 2: Since Node 1 is the root so it doesn't have any cousin so we will return an empty array.
**/
vector<int> Solution::solve(TreeNode* A, int B) {
  if(!A) return vector<int>();
  //map<level, multimap<curNode, parentNode>>
  map<int, multimap<int, int>> m;
  queue<pair<TreeNode*,TreeNode*>> q;
  q.push({A, nullptr});
  q.push({nullptr, nullptr});
  int i = 0, parent = 0;
  while(!q.empty()) {
    pair<TreeNode *,TreeNode *> p = q.front();
    A = p.first;
    q.pop();
    if(!A) {
      i++;
      if(q.empty()) break;
      q.push({nullptr, nullptr});
      continue;
    }
    if(A->val == B) parent = p.second?p.second->val:0;
    m[i].insert({A->val, p.second?p.second->val:0});
    if(A->left) q.push({A->left, A});
    if(A->right) q.push({A->right, A});
  }
  for(auto a:m) {
    if(a.second.find(B) != a.second.end()) {
      vector<int> res;
      for(auto t:a.second) {
        if(t.second != parent)
          res.push_back(t.first);
      }
      return res;
    }
  }
  return vector<int>();
}
