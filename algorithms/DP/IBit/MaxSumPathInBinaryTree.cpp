/**
https://www.interviewbit.com/old/problems/max-sum-path-in-binary-tree/
Given a binary tree T, find the maximum path sum.
The path may start and end at any node in the tree.
Input Format:
The first and the only argument contains a pointer to the root of T, A.
Output Format:
Return an integer representing the maximum sum path.
Constraints:
1 <= Number of Nodes <= 7e4
-1000 <= Value of Node in T <= 1000
Example :
Input 1:
   1
  / \
 2   3
Output 1: 6
Explanation 1: The path with maximum sum is: 2 -> 1 -> 3
Input 2:
  -10
  /  \
-20  -30
Output 2: -10
Explanation 2 : The path with maximum sum is: -10
**/
int sum(TreeNode *root, int &res) {
  if(!root) return 0;

  int l = sum(root->left, res);
  int r = sum(root->right, res);

  int temp = max(max(l, r) + root->val, root->val); 
  int ans = max(temp, l+r+root->val);
  res = max(res, ans);
  return temp;
}
int Solution::maxPathSum(TreeNode* A) {
  int res = INT_MIN;
  sum(A, res);
  return res;
}
