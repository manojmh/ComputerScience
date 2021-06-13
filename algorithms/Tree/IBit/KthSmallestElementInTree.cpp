/**
https://www.interviewbit.com/problems/kth-smallest-element-in-tree/
Given a binary search tree, write a function to find the kth smallest element in the tree.
Example :
Input : 
  2
 / \
1   3
and k = 2
Return : 2
As 2 is the second smallest element in the tree.
NOTE : You may assume 1 <= k <= Total number of nodes in BST 
**/
void inorder(TreeNode* A, int &B, int &res) {
  if(!A || B==0) return;
  inorder(A->left, B, res);
  B--;
  if(B==0) {
    res = A->val;
    return;
  }
  inorder(A->right, B, res);
}
int Solution::kthsmallest(TreeNode* A, int B) { 
  int res = 0;
  inorder(A,B,res);
  return res;
}
