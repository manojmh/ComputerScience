/**
You are given a preorder traversal A, of a Binary Search Tree.
Find if it is a valid preorder traversal of a BST.
Problem Constraints
1 <= A[i] <= 106
1 <= |A| <= 105
Input Format
First and only argument is an integer array A denoting the pre-order traversal.
Output Format
Return an integer:
0 : Impossible preorder traversal of a BST
1 : Possible preorder traversal of a BST
Example Input
Input 1: A = [7, 7, 10, 10, 9, 5, 2, 8]
Example Output
Output 1: 1
**/
int Solution::solve(vector<int> &A) {
  stack<int> s;
  int root = INT_MIN;
  for(int i=0; i<A.size(); i++) {
    if(A[i] < root)
      return false;
    while(!s.empty() && s.top() < A[i]) {
      root = s.top();
      s.pop();
    }
    s.push(A[i]);
  }
  return true;
}
