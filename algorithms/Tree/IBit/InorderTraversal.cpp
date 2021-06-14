/**
https://www.interviewbit.com/problems/inorder-traversal/
Given a binary tree, return the inorder traversal of its nodes’ values.
Example :
Given binary tree
 1
  \
   2
  /
 3
return [1,3,2].
Using recursion is not allowed.
**/
vector<int> Solution::inorderTraversal(TreeNode* A) {
  if(!A) return vector<int>();
  vector<int> res;
  stack<TreeNode *> s;
  TreeNode *cur = A;
  while(cur || !s.empty()) {
    while(cur) {
      s.push(cur);
      cur = cur->left;
    }
    cur = s.top();
    s.pop();
    res.push_back(cur->val);
    cur = cur->right;
  }
  return res;
}
