/**
Given a binary tree and a sum, find all root-to-leaf paths where each path’s sum equals the given sum.
For example: Given the below binary tree and sum = 22,
      5
     / \
    4   8
   /   / \
  11  13  4
 /  \    / \
7    2  5   1
return
[
 [5,4,11,2],
 [5,8,4,5]
]
**/
void sum(TreeNode *A, int curSum, int B, vector<int> temp, vector<vector<int>> &res) {
  if(!A) return;

  curSum += A->val;
  temp.push_back(A->val);

  if(!A->left && !A->right && curSum==B) {
    res.push_back(temp);
    return;
  }
  sum(A->left, curSum, B, temp, res);
  sum(A->right, curSum, B, temp, res);
}

vector<vector<int> > Solution::pathSum(TreeNode* A, int B) {
  vector<int> temp;
  vector<vector<int>> res;
  sum(A, 0, B, temp, res);
  return res;
}
