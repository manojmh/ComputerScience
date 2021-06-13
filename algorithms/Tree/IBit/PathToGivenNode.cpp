/**
https://www.interviewbit.com/problems/path-to-given-node/
Given a Binary Tree A containing N nodes.
You need to find the path from Root to a given node B.
NOTE:
No two nodes in the tree have same data values.
You can assume that B is present in the tree A and a path always exists.
Problem Constraints
1 <= N <= 105
1 <= Data Values of Each Node <= N
1 <= B <= N
Input Format
First Argument represents pointer to the root of binary tree A.
Second Argument is an integer B denoting the node number.
Output Format
Return an one-dimensional array denoting the path from Root to the node B in order.
Example Input
Input 1:
A =
     1
   /   \
  2     3
 / \   / \
4   5 6   7 
B = 5
Input 2:
A = 
      1
    /   \
   2     3
  / \ .   \
 4   5 .   6
B = 1
Example Output
Output 1: [1, 2, 5]
Output 2: [1]
Example Explanation
Explanation 1:
We need to find the path from root node to node with data value 5.
So the path is 1 -> 2 -> 5 so we will return [1, 2, 5]
Explanation 2:
We need to find the path from root node to node with data value 1.
As node with data value 1 is the root so there is only one node in the path.
So we will return [1]
**/
bool findPath(TreeNode *A, int B, vector<int> &path) {
  if(!A) return false;
  if(findPath(A->left, B, path)) { 
    path.push_back(A->val);
    return true;
  }
  if(A->val == B) {
    path.push_back(A->val);
    return true;
  }
  if(findPath(A->right, B, path)) { 
    path.push_back(A->val);
    return true;
  }
  return false;
}
vector<int> Solution::solve(TreeNode* A, int B) {
  if(!A) return vector<int>();
  vector<int> path;
  findPath(A, B, path);
  reverse(path.begin(), path.end());
  return path;
}
//Editorial:
vector<int> ans;
int val;
bool dfs(TreeNode* cur){
  if(cur == nullptr) return false;
  if(dfs(cur->left) || dfs(cur->right) || cur->val == val){
    ans.push_back(cur->val);
    return true;
  }
  return false;
}
vector<int> Solution::solve(TreeNode* A, int B) {
  ans.clear();
  val = B;
  dfs(A);
  reverse(ans.begin(), ans.end());
  return ans;
}
