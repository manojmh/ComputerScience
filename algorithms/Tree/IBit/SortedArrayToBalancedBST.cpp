/**
https://www.interviewbit.com/old/problems/sorted-array-to-balanced-bst/
Given an array where elements are sorted in ascending order, convert it to a height balanced BST.
Balanced tree : a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1. 
Example :
Given A : [1, 2, 3]
A height balanced BST  : 
    2
  /   \
 1     3
**/
TreeNode *build(const vector<int> &A, int s, int e) {
  if(s>e) return nullptr;
  int mid = s+(e-s)/2;
  TreeNode *root = new TreeNode(A[mid]);
  root->left = build(A, s, mid-1);
  root->right = build(A, mid+1, e);
  return root;
}
TreeNode* Solution::sortedArrayToBST(const vector<int> &A) {
  if(A.size() == 0) return nullptr;
  return build(A, 0, A.size()-1);
}
