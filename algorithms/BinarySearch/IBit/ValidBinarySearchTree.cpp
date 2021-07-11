/**
https://www.interviewbit.com/old/problems/valid-binary-search-tree/
Given a binary tree, determine if it is a valid binary search tree (BST).
Assume a BST is defined as follows:
The left subtree of a node contains only nodes with keys less than the node’s key.
The right subtree of a node contains only nodes with keys greater than the node’s key.
Both the left and right subtrees must also be binary search trees.
Example :
Input : 
 1
/  \
2    3
Output : 0 or False
Input : 
  2
 / \
1   3
Output : 1 or True 
Return 0 / 1 ( 0 for false, 1 for true ) for this problem
**/
int validate(TreeNode *A, int left, int right) {
  if(!A) return true;
  return (A->val > left && A->val<right) && validate(A->left, left, A->val) && validate(A->right, A->val, right);
}
int Solution::isValidBST(TreeNode* A) {
  return validate(A, INT_MIN, INT_MAX);
}
