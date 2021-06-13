/**
IMP
https://www.interviewbit.com/problems/recover-binary-search-tree/
Two elements of a binary search tree (BST) are swapped by mistake.
Tell us the 2 values swapping which the tree will be restored.
Note:
A solution using O(n) space is pretty straight forward. Could you devise a constant space solution? 
Example :
Input : 
         1
        / \
       2   3

Output : 
       [1, 2]
Explanation : Swapping 1 and 2 will change the BST to be 
         2
        / \
       1   3
which is a valid BST
**/
void validate(TreeNode *A, vector<int> &res, int mn, int mx) {
  if(!A) return;
  validate(A->left, res, mn, A->val);
  validate(A->right, res, A->val, mx);
  if(mn > A->val) {
    res.push_back(A->val);
    res.push_back(mn);
  }
  if(mx < A->val) {
    res.push_back(mx);
    res.push_back(A->val);
  }
  sort(res.begin(), res.end());
}
vector<int> Solution::recoverTree(TreeNode* A) {
  vector<int> res;
  validate(A, res, INT_MIN, INT_MAX);
  return vector<int>({res.front(), res.back()});
}
