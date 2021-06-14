/**
https://www.interviewbit.com/problems/reverse-level-order/
Given a binary tree, return the reverse level order traversal of its nodes values.
(i.e, from left to right and from last level to starting level).
Problem Constraints
1 <= number of nodes <= 5 * 105
1 <= node value <= 105
Input Format: First and only argument is a pointer to the root node of the Binary Tree, A.
Output Format: Return an integer array denoting the reverse level order traversal from left to right.
Example Input
Input 1:
  3
 / \
9  20
  /  \
 15   7
Input 2:
   1
  / \
 6   2
    /
   3
Example Output
Output 1: [15, 7, 9, 20, 3] 
Output 2: [3, 6, 2, 1]
Example Explanation
Explanation 1:
Nodes as level 3 : [15, 7]
Nodes at level 2: [9, 20]
Nodes at level 1: [3]
Reverse level order traversal will be: [15, 7, 9, 20, 3]
Explanation 2:
Nodes as level 3 : [3]
Nodes at level 2: [6, 2]
Nodes at level 1: [1]
Reverse level order traversal will be: [3, 6, 2, 1]
**/
vector<int> Solution::solve(TreeNode* A) {
  int i=0;
  vector<int> res;
  queue<TreeNode *> q;
  map<int, vector<int>> m;
  if(!A) return res;
  q.push(A);
  q.push(nullptr);
  while(!q.empty()) {
    A = q.front();
    q.pop();
    if(!A) {
      i++;
      if(q.empty()) break;
      q.push(nullptr);
      continue;
    }
    m[i].push_back(A->val);
    if(A->left) q.push(A->left);
    if(A->right) q.push(A->right);
  }
  for(auto it=m.rbegin(); it!=m.rend(); ++it) {
    copy((*it).second.begin(), (*it).second.end(), back_inserter(res));
  }
  return res;
}
