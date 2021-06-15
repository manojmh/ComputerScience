/**
https://www.interviewbit.com/problems/construct-binary-tree-from-inorder-and-preorder/
Given preorder and inorder traversal of a tree, construct the binary tree.
Note: You may assume that duplicates do not exist in the tree. 
Example :
Input :
Preorder : [1, 2, 3]
Inorder  : [2, 1, 3]
Return :
  1
 / \
2   3
**/
int search(vector<int> &in, int start, int end, int val) {
  for(int i=start; i<=end; i++)
    if(in[i] == val)
      return i;
}
TreeNode *build(vector<int> &in, vector<int> &pre, int start, int end, int &preIdx) {
  if(start > end) return nullptr;
  TreeNode *node = new TreeNode(pre[preIdx++]);
  if(start == end) return node;

  int inIdx = search(in, start, end, node->val);
  node->left = build(in, pre, start, inIdx-1, preIdx);
  node->right = build(in, pre, inIdx+1, end, preIdx);
  return node;
}
TreeNode* Solution::buildTree(vector<int> &pre, vector<int> &in) {
  int preIdx = 0;
  return build(pre, in, 0, pre.size()-1, preIdx);
}
