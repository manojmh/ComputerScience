/**
https://www.interviewbit.com/problems/min-depth-of-binary-tree/
Given a binary tree, find its minimum depth.
The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.
NOTE : The path has to end on a leaf node. 
Example :
   1
  /
 2
min depth = 2.
**/
void minD(TreeNode *A, int &mn, int i) {
  if(!A) return;
  if(A->left == nullptr && A->right == nullptr) {
    mn = min(mn, i+1);
  }
  minD(A->left, mn, i+1);
  minD(A->right, mn, i+1);
}
int Solution::minDepth(TreeNode* A) {
  int mn = INT_MAX;
  minD(A, mn, 0);
  return mn;
}
//Editorial:
class Solution {
public:
  int minDepth(TreeNode *root) {
    if (root == NULL) return 0;
    if (root->left == NULL && root->right == NULL) return 1;

    if (!root->left) return minDepth(root->right) + 1;
    if (!root->right) return minDepth(root->left) + 1;

    return min(minDepth(root->left), minDepth(root->right)) + 1; 
  }
};
