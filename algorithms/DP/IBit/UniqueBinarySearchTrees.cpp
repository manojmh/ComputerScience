/**
Given A, generate all structurally unique BST’s (binary search trees) that store values 1…A.
Input Format:
The first and the only argument of input contains the integer, A.
Output Format:
Return a list of tree nodes representing the generated BST's.
Constraints:
1 <= A <= 15
Example:
Input 1: A = 3
Output 1:
 1         3     3      2      1
  \       /     /      / \      \
   3     2     1      1   3      2
  /     /       \                 \
 2     1         2                 3
**/
vector<TreeNode*> insert(int start, int end) {
  vector<TreeNode*> res;
  if(start>end) {
    res.push_back(nullptr);
    return res;
  }
  if(start==end) {
    res.push_back(new TreeNode(start));
    return res;
  }
  for(int i=start; i<=end; i++) {
    TreeNode *root = new TreeNode(start);
    vector<TreeNode*> left = insert(start, i-1);
    vector<TreeNode*> right = insert(i+1, end);
    for(auto lt:left) {
      for(auto rt:right) {
        TreeNode *root = new TreeNode(i);
        root->left = lt;
        root->right = rt;
        res.push_back(root);
      }
    }
  }
  return res;
}
vector<TreeNode*> Solution::generateTrees(int A) {
  return insert(1, A);
}
