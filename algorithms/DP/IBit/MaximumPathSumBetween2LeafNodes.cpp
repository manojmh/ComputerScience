/**
https://practice.geeksforgeeks.org/problems/maximum-path-sum/1#
Maximum Path Sum between 2 Leaf Nodes 
Hard Accuracy: 49.92% Submissions: 79508 Points: 8
Given a binary tree in which each node element contains a number.
Find the maximum possible sum from one leaf node to another leaf node.
NOTE: Here Leaf node is a node which is connected to exactly one different node.
Example 1:
Input :      
       3                               
     /    \                          
   4       5                     
  /  \      
-10   4                          
Output: 16
Explanation :
Maximum Sum lies between leaf node 4 and 5.
4 + 4 + 3 + 5 = 16.
Example 2:
Input :    
          -15                               
       /      \                          
      5         6                      
    /  \       / \
  -8    1     3   9
 /  \              \
2   -3              0
                   / \
                  4  -1
                     /
                   10  
Output :  27
Explanation:
The maximum possible sum from one leaf node 
to another is (3 + 6 + 9 + 0 + -1 + 10 = 27)
Your Task:  
You dont need to read input or print anything.
Complete the function maxPathSum() which takes root node as input parameter and returns the maximum sum between 2 leaf nodes.
Expected Time Complexity: O(N)
Expected Auxiliary Space: O(Height of Tree)
**/
class Solution {
  public:
  int maxPathSumUtil(Node *root, int &res) {
    if(!root)
      return 0;
    
    if(!root->left && !root->right)
      return root->data;
    
    int l = maxPathSumUtil(root->left, res);
    int r = maxPathSumUtil(root->right, res);
    
    if (root->left && root->right) {
      int temp = max(l, r) + root->data; 
      res = max(res, l+r+root->data);
      return temp;
    }
    return (!root->left)? r + root->data: l + root->data;
  }
  int maxPathSum(Node* root) {
    int res = INT_MIN;
    int val = maxPathSumUtil(root, res);
    //--- for test case ---
    //   7
    //  /  \
    //Null -3
    //(case - 1)
    //value of res will be INT_MIN but the answer is 4 , which is returned by the
    //function maxPathSumUtil().
    if(res == INT_MIN)
      return val;
    return res;
  }
};
