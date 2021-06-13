/**
https://www.interviewbit.com/problems/balanced-binary-tree/
Given a binary tree, determine if it is height-balanced.
Height-balanced binary tree : is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1. 
Return 0 / 1 ( 0 for false, 1 for true ) for this problem
Example :
Input : 
  1
 / \
2   3
Return : True or 1 
Input 2 : 
     3
    /
   2
  /
 1
Return : False or 0 
Because for the root node, left subtree has depth 2 and right subtree has depth 0. 
Difference = 2 > 1. 
**/
bool flag;
int dfs(TreeNode* A) {
  if (!flag) return 0;
  if (A == NULL) return 0;
  int left, right;
  left = dfs(A->left);
  right = dfs(A->right);
  if (abs(left - right) >= 2) {
    flag = false;
    return 0;
  }
  return max(right, left) + 1;
}
int Solution::isBalanced(TreeNode* A) {
  flag = true;
  dfs(A);
  return flag;
}
