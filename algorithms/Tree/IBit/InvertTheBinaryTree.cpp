/**
https://www.interviewbit.com/problems/invert-the-binary-tree/
Given a binary tree, invert the binary tree and return it.
Look at the example for more details.
Example :
Given binary tree
     1
   /   \
  2     3
 / \   / \
4   5 6   7
invert and return
     1
   /   \
  3     2
 / \   / \
7   6 5   4
**/
TreeNode* Solution::invertTree(TreeNode* A) {
  if(!A) return A;
  if(A->left);
    invertTree(A->left);
  if(A->right)
    invertTree(A->right);
  swap(A->left, A->right);
  return A;
}
