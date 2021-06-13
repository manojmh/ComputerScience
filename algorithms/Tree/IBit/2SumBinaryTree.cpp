/**
https://www.interviewbit.com/problems/2sum-binary-tree/
Given a binary search tree T, where each node contains a positive integer, and an integer K,
you have to find whether or not there exist two different nodes A and B such that A.value + B.value = K.
Return 1 to denote that two such nodes exist. Return 0, otherwise.
Notes
Your solution should run in linear time and not take memory more than O(height of T).
Assume all values in BST are distinct.
Example :
Input 1: 
T :       10
         / \
        9   20

K = 19
Return: 1
Input 2: 
T:        10
         / \
        9   20

K = 40
Return: 0
**/
void inorder(TreeNode* A, int B, unordered_set<int> &s, bool &res) {
  if(!A) return;
  inorder(A->left, B, s, res);
  if(s.find(B - A->val) != s.end()) {
    res = true;
    return;
  }
  s.insert(A->val);
  inorder(A->right, B, s, res);
}
int Solution::t2Sum(TreeNode* A, int B) {
  unordered_set<int> s;
  bool res = false;
  inorder(A,B, s, res);
  return res;
}
