/**
Given a binary tree, flatten it to a linked list in-place.
Example :
Given
   1
  / \
 2   5
/ \   \
3   4   6
The flattened tree should look like:
 1
  \
   2
    \
     3
      \
       4
        \
         5
          \
           6
Note that the left child of all nodes should be NULL.
**/
TreeNode* Solution::flatten(TreeNode* A) {
  if(!A || (!A->left && !A->right)) return A;
  if(A->left) {
    flatten(A->left);
    TreeNode* temp = A->right;
    A->right = A->left;
    A->left = NULL;
    TreeNode* t = A->right;
    while(t->right)
        t = t->right;
    t->right = temp;
  }
  flatten(A->right);
  return A;
}
