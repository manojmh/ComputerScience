/**
https://www.interviewbit.com/problems/max-depth-of-binary-tree/
Given a binary tree, find its maximum depth.
The maximum depth of a binary tree is the number of nodes along the longest path from the root node down to the farthest leaf node.
NOTE : The path has to end on a leaf node. 
Example :
         1
        /
       2
max depth = 2.
**/
//Editorial:
int Solution::maxDepth(TreeNode* A) {
  if (A == 0) return 0;
  return 1 + max(maxDepth(A->left), maxDepth(A->right));
}
//my Solution
void depth(TreeNode *A, int i, int &res) {
  if(!A) return;
  depth(A->left, i+1, res);
  depth(A->right, i+1, res);
  res = max(i, res);
}
int Solution::maxDepth(TreeNode* A) {
  if(!A) return 0;
  int res = INT_MIN;
  depth(A, 1, res);
  return res;
}
