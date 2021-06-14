/**
https://www.interviewbit.com/problems/zigzag-level-order-traversal-bt/
Given a binary tree, return the zigzag level order traversal of its nodes’ values.
(ie, from left to right, then right to left for the next level and alternate between).
Example :
Given binary tree
  3
 / \
9  20
  /  \
 15   7
return
[
 [3],
 [20, 9],
 [15, 7]
]
**/
vector<vector<int>> Solution::zigzagLevelOrder(TreeNode* A) {
  vector<vector<int>> res;
  if(!A) return res;
  stack<TreeNode *> s1, s2;
  s1.push(A);
  vector<int> temp;
  while(1) {
    //Following condition cannot be checked instead of while(1)
    if(s1.empty() && s2.empty())
      break;
    while(!s1.empty()) {
      A = s1.top();
      s1.pop();
      temp.push_back(A->val);
      if(A->left) s2.push(A->left);
      if(A->right) s2.push(A->right);
    }
    if(temp.size()>=1)
    res.push_back(temp);
    temp.clear();
    while(!s2.empty()) {
      A = s2.top();
      s2.pop();
      temp.push_back(A->val);
      if(A->right) s1.push(A->right);
      if(A->left) s1.push(A->left);
    }
    if(temp.size()>=1)
    res.push_back(temp);
    temp.clear();
  }
  return res;
}
