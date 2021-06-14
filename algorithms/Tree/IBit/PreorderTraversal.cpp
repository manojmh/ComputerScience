/**
https://www.interviewbit.com/problems/preorder-traversal/
Given a binary tree, return the preorder traversal of its nodes’ values.
Example :
Given binary tree
 1
  \
   2
  /
 3
return [1,2,3].
Using recursion is not allowed.
**/
vector<int> Solution::preorderTraversal(TreeNode* A) {
  vector<int> res;
  if(!A) return res;
  stack<TreeNode *> s;
  s.push(A);
  while(!s.empty()) {
    A = s.top();
    s.pop();
    res.push_back(A->val);
    if(A->right) s.push(A->right);
    if(A->left) s.push(A->left);
  }
  return res;
}
