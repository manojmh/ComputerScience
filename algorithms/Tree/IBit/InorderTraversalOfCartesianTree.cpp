/**
https://www.interviewbit.com/problems/inorder-traversal-of-cartesian-tree/
Given an inorder traversal of a cartesian tree, construct the tree.
Cartesian tree : is a heap ordered binary tree, where the root is greater than all the elements in the subtree. 
Note: You may assume that duplicates do not exist in the tree. 
Example :
Input : [1 2 3]
Return :   
    3
   /
  2
 /
1
**/
TreeNode *treeBuilder(vector<int> &A, int low, int high) {
  if(low>high) return nullptr;
  int idx = 0;
  int mx = INT_MIN;
  for(int i=low; i<=high; i++) {
    if(mx<A[i]) {
      mx = A[i];
      idx = i;
    }
  }
  TreeNode *root = new TreeNode(mx);
  root->left = treeBuilder(A, low, idx-1);
  root->right = treeBuilder(A, idx+1, high);
  return root;
}
TreeNode* Solution::buildTree(vector<int> &A) {
  return treeBuilder(A, 0, A.size()-1);
}
