/**
https://www.interviewbit.com/problems/right-view-of-binary-tree/
Given a binary tree A of integers. Return an array of integers representing the right view of the Binary tree.
Right view of a Binary Tree: is a set of nodes visible when the tree is visited from Right side.
Problem Constraints
1 <= Number of nodes in binary tree <= 105
0 <= node values <= 109
Input Format
First and only argument is an pointer to the root of binary tree A.
Output Format
Return an integer array denoting the right view of the binary tree A.
Example Input
Input 1:
        1
      /   \
     2    3
    / \  / \
   4   5 6  7
  /
 8 
Input 2:
    1
   /  \
  2    3
   \
    4
     \
      5
Example Output
Output 1: [1, 3, 7, 8]
Output 2: [1, 3, 4, 5]
**/
vector<int> Solution::solve(TreeNode* A) {
  int i=0;
  vector<int> res;
  if(!A) return res;
  map<int, int> m;
  queue<TreeNode *> q;
  q.push(A);
  q.push(nullptr);
  while(!q.empty()) {
    A = q.front();
    q.pop();
    if(!A) {
      if(q.empty()) break;
      i++;
      q.push(nullptr);
      continue;
    }
    if(m.find(i) == m.end())
      m[i] = A->val;
    if(A->right) q.push(A->right);
    if(A->left) q.push(A->left);
  }
  for(auto a:m) {
    res.push_back(a.second);
  }
  return res;
}
