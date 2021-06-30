/**
https://www.interviewbit.com/old/problems/level-order/
Given a binary tree, return the level order traversal of its nodes’ values. (ie, from left to right, level by level).
Example :
Given binary tree
  3
 / \
9  20
  /  \
 15   7
return its level order traversal as:
[
  [3],
  [9,20],
  [15,7]
]
Also think about a version of the question where you are asked to do a level order traversal
of the tree when depth of the tree is much greater than number of nodes on a level.
**/
vector<vector<int> > Solution::levelOrder(TreeNode* root) {
  vector<vector<int>> res;
  vector<int> temp;
  queue<TreeNode *> q;
  q.push(root);
  q.push(nullptr);
  while(!q.empty()) {
    root = q.front();
    q.pop();
    if(!root) {
      res.push_back(temp);
      temp.clear();
      if(q.empty())
        break;
      q.push(nullptr);
      continue;
    }
    temp.push_back(root->val);
    if(root->left) q.push(root->left);
    if(root->right) q.push(root->right);
  }
  return res;
}
