/**
https://www.interviewbit.com/old/problems/binary-tree-from-inorder-and-postorder/
Given inorder and postorder traversal of a tree, construct the binary tree.
Note: You may assume that duplicates do not exist in the tree. 
Example :
Input : 
Inorder : [2, 1, 3]
Postorder : [2, 3, 1]
Return : 
  1
 / \
2   3
**/
TreeNode *helper(vector<int> &in, int s1, int e1, vector<int> &po, int s2, int e2) {
  if(s1 >= e1||s2 >= e2)
    return nullptr;

  TreeNode *root = new TreeNode(po[e2-1]);

  auto in_idx = find(in.begin()+s1, in.begin()+e1, po[e2-1]);
  int d = in_idx - (in.begin()+s1);

  root->left = helper(in, s1, s1+d, po, s2, s2+d);
  root->right = helper(in, s1+d+1, e1, po, s2+d, e2-1);

  return root;
}
TreeNode* Solution::buildTree(vector<int> &A, vector<int> &B) {
  int n = A.size();
  if(n == 0) return nullptr;
  return helper(A, 0, n, B, 0, n);
}
