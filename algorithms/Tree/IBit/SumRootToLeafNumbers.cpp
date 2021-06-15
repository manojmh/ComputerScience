/**
https://www.interviewbit.com/problems/sum-root-to-leaf-numbers/
Given a binary tree containing digits from 0-9 only, each root-to-leaf path could represent a number.
An example is the root-to-leaf path 1->2->3 which represents the number 123.
Find the total sum of all root-to-leaf numbers % 1003.
Example :
    1
   / \
  2   3
The root-to-leaf path 1->2 represents the number 12.
The root-to-leaf path 1->3 represents the number 13.
Return the sum = (12 + 13) % 1003 = 25 % 1003 = 25.
**/
void dfs(TreeNode *root,int tmp,int &sum) {
  if(!root) return;
  if(!root->left && !root->right) {
    sum+=(10*tmp)%1003+(root->val%1003);
    return;
  }
  dfs(root->left,(10*tmp+root->val)%1003,sum);
  dfs(root->right,(10*tmp+root->val)%1003,sum);
}
int Solution::sumNumbers(TreeNode* A) {
  if(!A) return 0;
  int sum=0;
  dfs(A,0,sum);
  return sum%1003;
}
