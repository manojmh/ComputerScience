/**
https://www.interviewbit.com/problems/least-common-ancestor/
Find the lowest common ancestor in an unordered binary tree given two values in the tree.
Lowest common ancestor : the lowest common ancestor (LCA) of two nodes v and w in a tree or
directed acyclic graph (DAG) is the lowest (i.e. deepest) node that has both v and w as descendants. 
Example :
        _______3______
       /              \
    ___5__          ___1__
   /      \        /      \
   6      _2_     0        8
         /   \
         7    4
For the above tree, the LCA of nodes 5 and 1 is 3.
LCA = Lowest common ancestor 
Please note that LCA for nodes 5 and 4 is 5.
You are given 2 values. Find the lowest common ancestor of the two nodes represented by val1 and val2
No guarantee that val1 and val2 exist in the tree. If one value doesn’t exist in the tree then return -1.
There are no duplicate values.
You can use extra memory, helper functions, and can modify the node struct but, you can’t add a parent pointer.
**/
int LCA(TreeNode *root, int v1, int v2) {
  if (root == NULL)
    return -1;
  if (root->val == v1 or root->val == v2)
    return root->val;
  int left = LCA(root->left, v1, v2);
  int right = LCA(root->right, v1, v2);

  if (left != -1 and right != -1) {
    return root->val;
  }
  return (left != -1) ? left : right;
}

bool search(TreeNode *root, int item) {
  if (root == NULL)
    return false;
  if (root->val == item)
    return true;
  return (search(root->left, item) || search(root->right, item));
}

int Solution::lca(TreeNode *A, int B, int C) {
  return (search(A, B) && search(A, C)) ? LCA(A, B, C) : -1;
}
